#pragma once

#include <algorithm>
#include <cassert>
#include <functional>
#include <map>
#include <utility>
#include <vector>
using namespace std;

#include "../graph/graph-template.hpp"
#include "static-top-tree-vertex-based.hpp"

namespace DynamicDiameterImpl {

template <typename T>
struct HalfPath {
  T d;
  int u;
  friend HalfPath max(const HalfPath& lhs, const HalfPath& rhs) {
    if (lhs.d != rhs.d) return lhs.d > rhs.d ? lhs : rhs;
    return lhs.u > rhs.u ? lhs : rhs;
  }
};
template <typename T>
struct Path {
  T d;
  int u, v;
  friend Path max(const Path& lhs, const Path& rhs) {
    if (lhs.d != rhs.d) return lhs.d > rhs.d ? lhs : rhs;
    if (lhs.u != rhs.u) return lhs.u > rhs.u ? lhs : rhs;
    return lhs.v > rhs.v ? lhs : rhs;
  }
};
template <typename T>
struct L {
  Path<T> dia;
  HalfPath<T> d1, d2;
};
template <typename T>
struct H {
  Path<T> dia;
  HalfPath<T> pd, cd;
  T p_to_c;
  int p, c;
};

template <typename T>
H<T> vertex(T x, int i) {
  H<T> r;
  r.dia = {x, i, i};
  r.pd = r.cd = {x, i};
  r.p_to_c = x;
  r.p = r.c = i;
  return r;
}

template <typename T>
H<T> compress(const H<T>& p, const H<T>& c) {
  H<T> r;
  r.dia = max(max(p.dia, c.dia), {p.cd.d + c.pd.d, p.cd.u, c.pd.u});
  r.pd = max(p.pd, {p.p_to_c + c.pd.d, c.pd.u});
  r.cd = max(c.cd, {c.p_to_c + p.cd.d, p.cd.u});
  r.p_to_c = p.p_to_c + c.p_to_c;
  r.p = p.p, r.c = c.c;
  return r;
}

template <typename T>
L<T> rake(const L<T>& a, const L<T>& b) {
  L<T> r;
  r.dia = max(a.dia, b.dia);
  if (a.d1.d > b.d1.d) {
    r.d1 = a.d1;
    r.d2 = max(a.d2, b.d1);
  } else {
    r.d1 = b.d1;
    r.d2 = max(b.d2, a.d1);
  }
  return r;
}

template <typename T>
L<T> add_edge(const H<T>& a) {
  L<T> r;
  r.dia = a.dia;
  r.d1 = a.pd;
  r.d2 = {0, -1};
  return r;
}

template <typename T>
H<T> add_vertex(const L<T>& a, T x, int i) {
  H<T> r;
  r.dia = max(a.dia, {a.d1.d + x + a.d2.d, a.d1.u, a.d2.u});
  r.pd = r.cd = {a.d1.d + x, a.d1.u};
  r.p_to_c = x;
  r.p = r.c = i;
  return r;
}

template <typename T>
struct Aux_Tree {
  int N, _buf;
  const WeightedGraph<T>& g;
  vector<vector<int>> aux;
  vector<T> w;
  map<pair<int, int>, int> e_to_id;

  Aux_Tree(const WeightedGraph<T>& _g) : g(_g) {
    N = g.size();
    aux.resize(2 * N - 1);
    w.resize(2 * N - 1);
    _buf = N;
    dfs(0, -1);
    assert(_buf == 2 * N - 1);
  }

  void dfs(int c, int p) {
    for (auto& d : g[c]) {
      if (d == p) continue;
      int id = _buf++;
      aux[id].push_back(c), aux[c].push_back(id);
      aux[id].push_back(d), aux[d].push_back(id);
      w[id] = d.cost;
      e_to_id[minmax<int>(c, d)] = id;
      dfs(d, c);
    }
  }
};

template <typename T>
struct DynamicDiameter {
  const WeightedGraph<T>& g;
  int n;
  Aux_Tree<T> aux;
  HeavyLightDecomposition<vector<vector<int>>> hld;
  DPonStaticTopTreeVertexBased<
      vector<vector<int>>, H<T>, L<T>, function<H<T>(int)>,
      function<H<T>(const H<T>&, const H<T>&)>,
      function<L<T>(const L<T>&, const L<T>&)>, function<L<T>(const H<T>&)>,
      function<H<T>(const L<T>&, int)>>
      dp;

  DynamicDiameter(const WeightedGraph<T>& _g)
      : g(_g),
        n(g.size()),
        aux(g),
        hld(aux.aux),
        dp(
            hld, [&](int i) { return vertex(aux.w[i], i < n ? i : -1); },
            [&](const H<T>& p, const H<T>& c) { return compress(p, c); },
            [&](const L<T>& a, const L<T>& b) { return rake(a, b); },
            [&](const H<T>& a) { return add_edge(a); },
            [&](const L<T>& a, int i) {
              return add_vertex(a, aux.w[i], i < n ? i : -1);
            }) {}

  pair<T, pair<int, int>> get() {
    auto [d, u, v] = dp.get().dia;
    return make_pair(d, make_pair(u, v));
  }

  void update(int u, int v, T x) {
    assert(aux.e_to_id.count(minmax(u, v)));
    int i = aux.e_to_id[minmax(u, v)];
    aux.w[i] = x;
    dp.update(i);
  }
};
}  // namespace DynamicDiameterImpl

using DynamicDiameterImpl::DynamicDiameter;

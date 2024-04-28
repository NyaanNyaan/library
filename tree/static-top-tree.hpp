#pragma once

#include <cassert>
#include <utility>
#include <vector>
using namespace std;

#include "convert-tree.hpp"
#include "heavy-light-decomposition.hpp"

namespace StaticTopTreeImpl {

enum Type { Edge, Compress, Rake };

template <typename G>
struct StaticTopTree {
  const HeavyLightDecomposition<G>& hld;
  vector<vector<int>> g;
  int root;     // 元の木の root
  int tt_root;  // top tree の root
  vector<int> P, L, R;
  vector<Type> T;

  StaticTopTree(const HeavyLightDecomposition<G>& _hld) : hld(_hld) {
    root = hld.root;
    g = rooted_tree(hld.g, root);
    int n = g.size();
    P.resize(n, -1), L.resize(n, -1), R.resize(n, -1);
    T.resize(n, Type::Edge);
    build();
  }

 private:
  int add(int l, int r, Type t) {
    if (t == Type::Compress or t == Type::Rake) {
      assert(l != -1 and r != -1);
    }
    assert(t != Type::Edge);
    int k = P.size();
    P.push_back(-1), L.push_back(l), R.push_back(r), T.push_back(t);
    if (l != -1) P[l] = k;
    if (r != -1) P[r] = k;
    return k;
  }
  pair<int, int> merge(const vector<pair<int, int>>& a, Type t) {
    assert(!a.empty());
    if (a.size() == 1) return a[0];
    int sum_s = 0;
    for (auto& [_, s] : a) sum_s += s;
    vector<pair<int, int>> b, c;
    for (auto& [i, s] : a) {
      (sum_s > s ? b : c).emplace_back(i, s);
      sum_s -= s * 2;
    }
    auto [i, si] = merge(b, t);
    auto [j, sj] = merge(c, t);
    return {add(i, j, t), si + sj};
  }
  pair<int, int> compress(int i) {
    vector<pair<int, int>> chs{{i, 1}};
    while (!g[i].empty()) {
      chs.push_back(rake(i));
      i = g[i][0];
    }
    return merge(chs, Type::Compress);
  }
  pair<int, int> rake(int i) {
    vector<pair<int, int>> chs{{g[i][0], 1}};
    for (int j = 1; j < (int)g[i].size(); j++) chs.push_back(compress(g[i][j]));
    return merge(chs, Type::Rake);
  }
  void build() {
    auto [i, n] = compress(root);
    assert((int)g.size() == n);
    assert((int)P.size() == n * 2 - 1);
    tt_root = i;
  }
};

template <typename G, typename Data, typename Edge, typename Compress,
          typename Rake>
struct DPonStaticTopTree {
  const StaticTopTree<G> tt;
  vector<Data> dat;
  const Edge edge;
  const Compress compress;
  const Rake rake;

  DPonStaticTopTree(const HeavyLightDecomposition<G>& hld, const Edge& _edge,
                    const Compress& _compress, const Rake& _rake)
      : tt(hld), edge(_edge), compress(_compress), rake(_rake) {
    int n = tt.P.size();
    dat.resize(n);
    dfs(tt.tt_root);
  }

  Data get() { return dat[tt.tt_root]; }
  void update(int k) {
    while (k != -1) _update(k), k = tt.P[k];
  }

 private:
  void _update(int k) {
    if (tt.T[k] == Type::Edge) {
      dat[k] = edge(k);
    } else if (tt.T[k] == Type::Compress) {
      dat[k] = compress(dat[tt.L[k]], dat[tt.R[k]]);
    } else if (tt.T[k] == Type::Rake) {
      dat[k] = rake(dat[tt.L[k]], dat[tt.R[k]]);
    }
  }

  void dfs(int k) {
    if (tt.L[k] != -1) dfs(tt.L[k]);
    if (tt.R[k] != -1) dfs(tt.R[k]);
    _update(k);
  }
};

}  // namespace StaticTopTreeImpl

using StaticTopTreeImpl::DPonStaticTopTree;
using StaticTopTreeImpl::StaticTopTree;

/*
  // template
  using Data = ;
  auto edge = [&](int i) -> Data {

  };
  auto compress = [&](const Data& p, const Data& c) -> Data {

  };
  auto rake = [&](const Data& p, const Data& c) -> Data {

  };
  HeavyLightDecomposition hld{g};
  DPonStaticTopTree<vector<vector<int>>, Data, decltype(edge),
                    decltype(compress), decltype(rake)>
      dp(hld, edge, compress, rake);
*/

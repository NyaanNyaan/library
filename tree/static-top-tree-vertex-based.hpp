#pragma once

#include <cassert>
#include <utility>
#include <vector>
using namespace std;

#include "convert-tree.hpp"
#include "heavy-light-decomposition.hpp"

namespace StaticTopTreeVertexBasedImpl {

enum Type { Vertex, Compress, Rake, Add_Edge, Add_Vertex };

template <typename G>
struct StaticTopTreeVertexBased {
  const HeavyLightDecomposition<G>& hld;
  vector<vector<int>> g;
  int root;     // 元の木の root
  int tt_root;  // top tree の root
  vector<int> P, L, R;
  vector<Type> T;

  StaticTopTreeVertexBased(const HeavyLightDecomposition<G>& _hld) : hld(_hld) {
    root = hld.root;
    g = rooted_tree(hld.g, root);
    int n = g.size();
    P.resize(n, -1), L.resize(n, -1), R.resize(n, -1);
    T.resize(n, Type::Vertex);
    build();
  }

 private:
  int add(int l, int r, Type t) {
    if (t == Type::Compress or t == Type::Rake) {
      assert(l != -1 and r != -1);
    }
    if (t == Type::Add_Edge) {
      assert(l != -1 and r == -1);
    }
    assert(t != Type::Vertex and t != Type::Add_Vertex);
    int k = P.size();
    P.push_back(-1), L.push_back(l), R.push_back(r), T.push_back(t);
    if (l != -1) P[l] = k;
    if (r != -1) P[r] = k;
    return k;
  }
  int add2(int k, int l, int r, Type t) {
    assert(k < (int)g.size());
    assert(t == Type::Vertex or t == Type::Add_Vertex);
    if (t == Type::Vertex) {
      assert(l == -1 and r == -1);
    } else {
      assert(l != -1 and r == -1);
    }
    P[k] = -1, L[k] = l, R[k] = r, T[k] = t;
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
    vector<pair<int, int>> chs;
    while (true) {
      chs.push_back(add_vertex(i));
      if (g[i].empty()) break;
      i = g[i][0];
    }
    return merge(chs, Type::Compress);
  }
  pair<int, int> rake(int i) {
    vector<pair<int, int>> chs;
    for (int j = 1; j < (int)g[i].size(); j++) chs.push_back(add_edge(g[i][j]));
    if (chs.empty()) return {-1, 0};
    return merge(chs, Type::Rake);
  }
  pair<int, int> add_edge(int i) {
    auto [j, sj] = compress(i);
    return {add(j, -1, Type::Add_Edge), sj};
  }
  pair<int, int> add_vertex(int i) {
    auto [j, sj] = rake(i);
    return {add2(i, j, -1, j == -1 ? Type::Vertex : Type::Add_Vertex), sj + 1};
  }
  void build() {
    auto [i, n] = compress(root);
    assert((int)g.size() == n);
    tt_root = i;
  }
};

template <typename G, typename Path, typename Point, typename Vertex,
          typename Compress, typename Rake, typename Add_edge,
          typename Add_vertex>
struct DPonStaticTopTreeVertexBased {
  const StaticTopTreeVertexBased<G> tt;
  vector<Path> path;
  vector<Point> point;
  const Vertex vertex;
  const Compress compress;
  const Rake rake;
  const Add_edge add_edge;
  const Add_vertex add_vertex;

  DPonStaticTopTreeVertexBased(const HeavyLightDecomposition<G>& hld,
                               const Vertex& _vertex, const Compress& _compress,
                               const Rake& _rake, const Add_edge& _add_edge,
                               const Add_vertex& _add_vertex)
      : tt(hld),
        vertex(_vertex),
        compress(_compress),
        rake(_rake),
        add_edge(_add_edge),
        add_vertex(_add_vertex) {
    int n = tt.P.size();
    path.resize(n), point.resize(n);
    dfs(tt.tt_root);
  }

  Path get() { return path[tt.tt_root]; }
  void update(int k) {
    while (k != -1) _update(k), k = tt.P[k];
  }

 private:
  void _update(int k) {
    if (tt.T[k] == Type::Vertex) {
      path[k] = vertex(k);
    } else if (tt.T[k] == Type::Compress) {
      path[k] = compress(path[tt.L[k]], path[tt.R[k]]);
    } else if (tt.T[k] == Type::Rake) {
      point[k] = rake(point[tt.L[k]], point[tt.R[k]]);
    } else if (tt.T[k] == Type::Add_Edge) {
      point[k] = add_edge(path[tt.L[k]]);
    } else {
      path[k] = add_vertex(point[tt.L[k]], k);
    }
  }

  void dfs(int k) {
    if (tt.L[k] != -1) dfs(tt.L[k]);
    if (tt.R[k] != -1) dfs(tt.R[k]);
    _update(k);
  }
};

}  // namespace StaticTopTreeVertexBasedImpl

using StaticTopTreeVertexBasedImpl::DPonStaticTopTreeVertexBased;
using StaticTopTreeVertexBasedImpl::StaticTopTreeVertexBased;

/*

  // template
  using Path = ;
  using Point = ;
  auto vertex = [&](int i) -> Path {

  };
  auto compress = [&](const Path& p, const Path& c) -> Path {

  };
  auto rake = [&](const Point& a, const Point& b) -> Point {

  };
  auto add_edge = [&](const Path& a) -> Point {

  };
  auto add_vertex = [&](const Point& a, int i) -> Path {

  };
  HeavyLightDecomposition hld{g};
  DPonStaticTopTreeVertexBased<vector<vector<int>>, Path, Point,
  decltype(vertex), decltype(compress), decltype(rake), decltype(add_edge),
                    decltype(add_vertex)>
      dp(hld, vertex, compress, rake, add_edge, add_vertex);
*/

/**
 * @brief Static Top Tree
 */

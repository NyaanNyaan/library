#pragma once

#include "../graph/graph-template.hpp"

template <typename G>
struct HeavyLightDecomposition {
 private:
  void dfs_sz(int cur) {
    size[cur] = 1;
    for (auto& dst : g[cur]) {
      if (dst == par[cur]) {
        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))
          swap(g[cur][0], g[cur][1]);
        else
          continue;
      }
      depth[dst] = depth[cur] + 1;
      par[dst] = cur;
      dfs_sz(dst);
      size[cur] += size[dst];
      if (size[dst] > size[g[cur][0]]) {
        swap(dst, g[cur][0]);
      }
    }
  }

  void dfs_hld(int cur) {
    down[cur] = id++;
    for (auto dst : g[cur]) {
      if (dst == par[cur]) continue;
      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));
      dfs_hld(dst);
    }
    up[cur] = id;
  }

  // [u, v)
  vector<pair<int, int>> ascend(int u, int v) const {
    vector<pair<int, int>> res;
    while (nxt[u] != nxt[v]) {
      res.emplace_back(down[u], down[nxt[u]]);
      u = par[nxt[u]];
    }
    if (u != v) res.emplace_back(down[u], down[v] + 1);
    return res;
  }

  // (u, v]
  vector<pair<int, int>> descend(int u, int v) const {
    if (u == v) return {};
    if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};
    auto res = descend(u, par[nxt[v]]);
    res.emplace_back(down[nxt[v]], down[v]);
    return res;
  }

 public:
  G& g;
  int root, id;
  vector<int> size, depth, down, up, nxt, par;
  HeavyLightDecomposition(G& _g, int _root = 0)
      : g(_g),
        root(_root),
        id(0),
        size(g.size(), 0),
        depth(g.size(), 0),
        down(g.size(), -1),
        up(g.size(), -1),
        nxt(g.size(), root),
        par(g.size(), root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  pair<int, int> idx(int i) const { return make_pair(down[i], up[i]); }

  template <typename F>
  void path_query(int u, int v, bool vertex, const F& f) {
    int l = lca(u, v);
    for (auto&& [a, b] : ascend(u, l)) {
      int s = a + 1, t = b;
      s > t ? f(t, s) : f(s, t);
    }
    if (vertex) f(down[l], down[l] + 1);
    for (auto&& [a, b] : descend(l, v)) {
      int s = a, t = b + 1;
      s > t ? f(t, s) : f(s, t);
    }
  }

  template <typename F>
  void path_noncommutative_query(int u, int v, bool vertex, const F& f) {
    int l = lca(u, v);
    for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);
    if (vertex) f(down[l], down[l] + 1);
    for (auto&& [a, b] : descend(l, v)) f(a, b + 1);
  }

  template <typename F>
  void subtree_query(int u, bool vertex, const F& f) {
    f(down[u] + int(!vertex), up[u]);
  }

  int lca(int a, int b) {
    while (nxt[a] != nxt[b]) {
      if (down[a] < down[b]) swap(a, b);
      a = par[nxt[a]];
    }
    return depth[a] < depth[b] ? a : b;
  }

  int dist(int a, int b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }
};

/**
 * @brief Heavy Light Decomposition(重軽分解)
 * @docs docs/tree/heavy-light-decomposition.md
 */

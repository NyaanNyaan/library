#pragma once



#include "../graph/graph-template.hpp"

template <typename G>
struct DSUonTree {
 private:
  G &g;
  int N;
  vector<int> sub_sz, euler, down, up;
  int idx_;
  int root;

  int dfs1(int cur, int par = -1) {
    sub_sz[cur] = 1;
    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {
      swap(g[cur][0], g[cur][1]);
    }
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      sub_sz[cur] += dfs1(dst, cur);
      if (sub_sz[dst] > sub_sz[g[cur][0]]) swap(dst, g[cur][0]);
    }
    return sub_sz[cur];
  }

  void dfs2(int cur, int par = -1) {
    euler[idx_] = cur;
    down[cur] = idx_++;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs2(dst, cur);
    }
    up[cur] = idx_;
  }

 public:
  DSUonTree(G &_g,int _root = 0)
      : g(_g),
        N(_g.size()),
        sub_sz(_g.size()),
        euler(_g.size()),
        down(_g.size()),
        up(_g.size()),
        idx_(0),
        root(_root) {
    dfs1(root);
    dfs2(root);
  }

  int idx(int u) const { return down[u]; }

  template <typename UPDATE, typename QUERY, typename CLEAR, typename RESET>
  void run(UPDATE &update, QUERY &query, CLEAR &clear, RESET &reset) {
    auto dsu = [&](auto rc, int cur, int par = -1, bool keep = false) -> void {
      for (int i = 1; i < (int)g[cur].size(); i++)
        if (g[cur][i] != par) rc(rc, g[cur][i], cur, false);
      if (sub_sz[cur] != 1) rc(rc, g[cur][0], cur, true);
      if (sub_sz[cur] != 1)
        for (int i = up[g[cur][0]]; i < up[cur]; i++) update(euler[i]);
      update(cur);
      query(cur);
      if (!keep) {
        for (int i = down[cur]; i < up[cur]; i++) clear(euler[i]);
        reset();
      }
      return;
    };
    dsu(dsu, root);
  }
};

/**
 * @brief DSU on Tree(Guni)
 * @docs docs/tree/dsu-on-tree.md
 */

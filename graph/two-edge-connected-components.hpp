#pragma once

#include "./graph-template.hpp"
#include "./lowlink.hpp"

template <typename G>
struct TwoEdgeConnectedComponents {
  const G &g;
  LowLink<G> low;
  vector<int> comp;
  int k;
  vector<vector<int>> groups, tree;
  TwoEdgeConnectedComponents(const G &g_)
      : g(g_), low(g_), comp(g_.size(), -1), k(0) {
    for (int i = 0; i < (int)g.size(); i++) {
      if (comp[i] == -1) dfs(i, -1);
    }
    groups.resize(k);
    tree.resize(k);
    for (int i = 0; i < (int)g.size(); i++) {
      groups[comp[i]].push_back(i);
    }
    for (auto &e : low.bridge) {
      int u = comp[e.first], v = comp[e.second];
      tree[u].push_back(v);
    }
  };

  int operator[](const int &k) const { return comp[k]; }

  void dfs(int i, int p) {
    if (p >= 0 && low.ord[p] >= low.low[i])
      comp[i] = comp[p];
    else
      comp[i] = k++;
    for (auto &d : g[i]) {
      if (comp[d] == -1) dfs(d, i);
    }
  }
};

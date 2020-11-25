#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/graph-template.hpp"

template <typename G>
struct Tree {
 private:
  G& g;
  int root;
  vector<vector<int>> bl;
  vector<int> dp;
  void build() {
    bl.resize(g.size());
    dp.resize(g.size());
    dfs(root, -1, 0);
  }

  void dfs(int c, int p, int _dp) {
    dp[c] = _dp;
    for (int i = p, x = -1; i != -1;) {
      bl[c].push_back(i);
      i = ++x < (int)bl[i].size() ? bl[i][x] : -1;
    }
    for (auto& d : g[c]) {
      if (d == p) continue;
      dfs(d, c, _dp + 1);
    }
  }

 public:
  Tree(G& _g, int _r = 0) : g(_g), root(_r) { build(); }

  int depth(int u) const { return dp[u]; }

  int par(int u) const { return u == root ? -1 : bl[u][0]; }

  int kth_ancestor(int u, int k) const {
    for (int i = k ? __lg(k) : -1; i >= 0; --i) {
      if ((k >> i) & 1) {
        if (i >= (int)bl[u].size()) return -1;
        u = bl[u][i];
      }
    }
    return u;
  }

  int nxt(int s, int t) const {
    if (dp[s] >= dp[t]) return par(s);
    int u = kth_ancestor(t, dp[t] - dp[s] - 1);
    return bl[u][0] == s ? u : bl[s][0];
  }

  vector<int> path(int s, int t) const {
    vector<int> pre, suf;
    while (dp[s] > dp[t]) {
      pre.push_back(s);
      s = bl[s][0];
    }
    while (dp[s] < dp[t]) {
      suf.push_back(t);
      t = bl[t][0];
    }
    while (s != t) {
      pre.push_back(s);
      suf.push_back(t);
      s = bl[s][0];
      t = bl[t][0];
    }
    pre.push_back(s);
    reverse(begin(suf), end(suf));
    copy(begin(suf), end(suf), back_inserter(pre));
    return pre;
  }

  int lca(int u, int v) {
    if (dp[u] != dp[v]) {
      if (dp[u] > dp[v]) swap(u, v);
      v = kth_ancestor(v, dp[v] - dp[u]);
    }
    if (u == v) return u;
    for (int i = __lg(dp[u]); i >= 0; --i) {
      if (dp[u] < (1 << i)) continue;
      if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];
    }
    return bl[u][0];
  }
};

/**
 * @brief 木に対する一般的なクエリ
 */

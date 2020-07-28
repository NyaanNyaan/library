#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/graph-template.hpp"

// Rerooting
// f1(c1, c2) ... merge value of child node
// f2(memo[i], chd, par) ... return value from child node to parent node
// memo[i] ... result of subtree rooted i
// dp[i] ... result of tree rooted i
template <typename T, typename G, typename F1, typename F2>
struct Rerooting {
  const G &g;
  const F1 f1;
  const F2 f2;
  vector<T> memo, dp;
  T I;

  Rerooting(const G &g, const F1 f1, const F2 f2, const T &I)
      : g(g), f1(f1), f2(f2), memo(g.size(), I), dp(g.size(), I), I(I) {
    dfs(0, -1);
    efs(0, -1, I);
  }

  const T &operator[](int i) const { return dp[i]; }

  void dfs(int cur, int par) {
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs(dst, cur);
      memo[cur] = f1(memo[cur], f2(memo[dst], dst, cur));
    }
  }

  void efs(int cur, int par, const T &pval) {
    // get cumulative sum
    vector<T> buf;
    for (auto dst : g[cur]) {
      if (dst == par) continue;
      buf.push_back(f2(memo[dst], dst, cur));
    }
    vector<T> head(buf.size() + 1), tail(buf.size() + 1);
    head[0] = tail[buf.size()] = I;
    for (int i = 0; i < (int)buf.size(); i++) head[i + 1] = f1(head[i], buf[i]);
    for (int i = (int)buf.size() - 1; i >= 0; i--)
      tail[i] = f1(tail[i + 1], buf[i]);

    // update
    dp[cur] = par == -1 ? head.back() : f1(pval, head.back());

    // propagate
    int idx = 0;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      efs(dst, cur, f2(f1(pval, f1(head[idx], tail[idx + 1])), cur, dst));
      idx++;
    }
  }
};

/*

using T = ;
// identify element of f1, and answer of leaf
T I = ;
// merge value of child node
auto f1 = [&](T x, T y) -> T {

};
// return value from child node to parent node
auto f2 = [&](T x, int chd, int par) -> T {

};
Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);

*/
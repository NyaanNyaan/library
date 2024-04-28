#pragma once

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
  T leaf;

  Rerooting(const G &_g, const F1 _f1, const F2 _f2, const T &_leaf)
      : g(_g), f1(_f1), f2(_f2), memo(g.size()), dp(g.size()), leaf(_leaf) {
    dfs(0, -1);
    dfs2(0, -1, T{});
  }

  const T &operator[](int i) const { return dp[i]; }

  void dfs(int cur, int par) {
    vector<T> chds;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs(dst, cur);
      chds.push_back(f2(memo[dst], dst, cur));
    }
    if (chds.empty()) {
      memo[cur] = leaf;
    } else {
      memo[cur] = chds[0];
      for (int i = 1; i < (int)chds.size(); i++) {
        memo[cur] = f1(memo[cur], chds[i]);
      }
    }
  }

  void dfs2(int cur, int par, const T &pval) {
    // get cumulative sum
    vector<T> buf;
    if (cur != 0) buf.push_back(pval);
    for (auto dst : g[cur]) {
      if (dst == par) continue;
      buf.push_back(f2(memo[dst], dst, cur));
    }
    vector<T> head(buf.size()), tail(buf.size());
    if (!buf.empty()) {
      head[0] = buf[0];
      for (int i = 1; i < (int)buf.size(); i++) {
        head[i] = f1(head[i - 1], buf[i]);
      }
      tail.back() = buf.back();
      for (int i = (int)buf.size() - 2; i >= 0; i--) {
        tail[i] = f1(tail[i + 1], buf[i]);
      }
    }
    dp[cur] = head.empty() ? leaf : head.back();
    int idx = cur == 0 ? 0 : 1;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      T val;
      bool first = idx == 0;
      bool last = idx + 1 == (int)head.size();
      if (first and last) {
        val = leaf;
      } else if (first) {
        val = tail[idx + 1];
      } else if (last) {
        val = head[idx - 1];
      } else {
        val = f1(head[idx - 1], tail[idx + 1]);
      }
      dfs2(dst, cur, f2(val, cur, dst));
      idx++;
    }
  }
};

/**
 * @brief Rerooting(全方位木DP)
 * @docs docs/tree/rerooting.md
 */

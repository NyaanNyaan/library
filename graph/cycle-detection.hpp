#pragma once

#include <utility>
#include <vector>
using namespace std;

#include "./graph-template.hpp"

template <typename G>
vector<pair<int, int>> CycleDetection(const G& g, bool directed = true) {
  for (int i = 0; i < (int)g.size(); i++) {
    for (auto j : g[i]) {
      if (i == j) {
        vector<pair<int, int>> res;
        res.emplace_back(i, i);
        return res;
      }
    }
  }

  vector<int> pidx(g.size(), -1), vis(g.size(), 0);

  vector<pair<int, int>> cycle;
  int finish = 0;
  auto dfs = [&](auto rec, int cur, int pval, int par) -> int {
    pidx[cur] = pval;
    vis[cur] = 1;
    for (auto& dst : g[cur]) {
      if (finish) return -1;
      if (!directed && dst == par) continue;
      if (pidx[dst] == pidx[cur]) {
        cycle.emplace_back(cur, dst);
        return dst;
      }
      if (vis[dst]) continue;
      int nx = rec(rec, dst, pval, cur);
      if (nx != -1) {
        cycle.emplace_back(cur, dst);
        if (cur == nx) {
          finish = 1;
          return -1;
        }
        return nx;
      }
    }
    pidx[cur] = -1;
    return -1;
  };

  for (int i = 0; i < (int)g.size(); i++) {
    if (vis[i]) continue;
    dfs(dfs, i, i, -1);

    if (finish) {
      reverse(begin(cycle), end(cycle));
      return cycle;
    }
  }
  return vector<pair<int, int>>{};
}

/**
 * @brief 閉路の検出
 */

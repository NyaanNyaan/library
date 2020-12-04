#pragma once



#include "../graph/topological-sort.hpp"

vector<int> GrundyNumber(vector<vector<int>> &g) {
  vector<int> topo = TopologicalSort(g);
  if ((int)topo.size() == 0) return vector<int>();
  vector<int> grundy(g.size(), 0);
  vector<int> memo(g.size() + 1, 0);
  for (int _ = (int)g.size() - 1; _ >= 0; _--) {
    int i = topo[_];
    if (g[i].size() == 0) continue;
    for (auto &x : g[i]) {
      memo[grundy[x]]++;
    }
    while (memo[grundy[i]] > 0) grundy[i]++;
    for (auto &x : g[i]) {
      memo[grundy[x]]--;
    }
  }
  return grundy;
};

/**
 * @brief Grundy Number
 */

#pragma once

#include "../graph/graph-template.hpp"

// unreachable -> -1
template <typename T>
vector<T> dijkstra(WeightedGraph<T> &g, int start = 0) {
  using P = pair<T, int>;
  int N = (int)g.size();
  vector<T> d(N, T(-1));
  priority_queue<P, vector<P>, greater<P> > Q;
  d[start] = 0;
  Q.emplace(0, start);
  while (!Q.empty()) {
    P p = Q.top();
    Q.pop();
    int cur = p.second;
    if (d[cur] < p.first) continue;
    for (auto dst : g[cur]) {
      if (d[dst] == T(-1) || d[cur] + dst.cost < d[dst]) {
        d[dst] = d[cur] + dst.cost;
        Q.emplace(d[dst], dst);
      }
    }
  }
  return d;
}

/**
 * @brief ダイクストラ法
 * @docs docs/shortest-path/dijkstra.md
 */

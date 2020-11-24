#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/graph-template.hpp"

// unreachable -> -1
template <typename T>
vector<T> bfs01(WeightedGraph<T>& g, int start = 0) {
  int N = (int)g.size();
  vector<T> d(N, -1);
  deque<int> Q;
  d[start] = 0;
  Q.push_back(start);
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop_front();
    for (auto& dst : g[cur]) {
      if (d[dst] != -1) continue;
      d[dst] = d[cur] + dst.cost;
      if (dst.cost == 0)
        Q.push_front(dst);
      else
        Q.push_back(dst);
    }
  }
  return d;
}
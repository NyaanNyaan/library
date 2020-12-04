#pragma once



#include "../graph/graph-template.hpp"
#include "../data-structure/radix-heap.hpp"

// unreachable -> -1
template <typename T>
vector<T> dijkstra_radix_heap(WeightedGraph<T> &g, int start = 0) {
  int N = (int)g.size();
  vector<T> d(N, T(-1));
  RadixHeap<T, int> Q;
  d[start] = 0;
  Q.push(0, start);
  while (!Q.empty()) {
    auto p = Q.pop();
    int cur = p.second;
    if (d[cur] < T(p.first)) continue;
    for (auto dst : g[cur]) {
      if (d[dst] == T(-1) || d[cur] + dst.cost < d[dst]) {
        d[dst] = d[cur] + dst.cost;
        Q.push(d[dst], dst);
      }
    }
  }
  return d;
}

/*
 * @brief ダイクストラ法(Radix Heap)
 * @docs docs/shortest-path/dijkstra-radix-heap.md
**/

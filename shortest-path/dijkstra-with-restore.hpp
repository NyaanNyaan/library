#pragma once



#include "../data-structure/radix-heap.hpp"
#include "../graph/graph-template.hpp"

// unreachable -> {-1, -1}
template <typename T>
vector<pair<T, int>> dijkstra_restore(WeightedGraph<T> &g, int start = 0) {
  int N = (int)g.size();
  using P = pair<T, int>;
  vector<P> d(N, P{-1, -1});
  RadixHeap<T, int> Q;
  d[start].first = 0;
  Q.push(0, start);
  while (!Q.empty()) {
    auto p = Q.pop();
    int cur = p.second;
    T dc = d[cur].first;
    if (dc < T(p.first)) continue;
    for (auto dst : g[cur]) {
      if (d[dst].first == T(-1) || dc + dst.cost < d[dst].first) {
        d[dst] = P{dc + dst.cost, cur};
        Q.push(dc + dst.cost, dst);
      }
    }
  }
  return d;
}

/*
 * @brief ダイクストラ法(復元付き)
 **/

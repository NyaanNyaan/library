#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../data-structure/radix-heap.hpp"
#include "../graph/static-graph.hpp"

template <typename T>
struct DijkstraGraph {
  StaticGraph<T> g;

  DijkstraGraph(int _n, int _m) : g(_n, _m) {}

  void add_edge(int u, int v, T c) { g.add_edge(u, v, c); }

  vector<T> dijkstra(int start = 0) {
    vector<T> d(g.size(), T(-1));
    RadixHeap<T, int> Q;
    d[start] = 0;
    Q.push(0, start);
    while (!Q.empty()) {
      auto p = Q.pop();
      int u = p.second;
      if (d[u] < T(p.first)) continue;
      T du = d[u];
      for (auto&& [v, c] : g[u]) {
        if (d[v] == T(-1) || du + c < d[v]) {
          d[v] = du + c;
          Q.push(d[v], v);
        }
      }
    }
    return d;
  }
};

/*
 * @brief ダイクストラ法(定数倍高速化)
 * @docs docs/shortest-path/dijkstra-fast.md
 **/

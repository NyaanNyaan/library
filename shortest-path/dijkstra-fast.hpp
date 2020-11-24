#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../data-structure/radix-heap.hpp"

template <typename T, int N, int M>
struct DijkstraGraph {
  array<int, N> first;
  array<int, M + 1> succ, V;
  array<T, M + 1> C;
  int ec;

  constexpr DijkstraGraph() : ec(0) { fill(begin(first), end(first), 0); }

  void add_edge(int u, int v, T c) {
    ++ec;
    succ[ec] = first[u];
    first[u] = ec;
    V[ec] = v;
    C[ec] = c;
  }

  vector<T> dijkstra(int start = 0) {
    vector<T> d(N, T(-1));
    RadixHeap<T, int> Q;
    d[start] = 0;
    Q.push(0, start);
    while (!Q.empty()) {
      auto p = Q.pop();
      int u = p.second;
      if (d[u] < T(p.first)) continue;
      T du = d[u];
      for (int id = first[u]; id; id = succ[id]) {
        int v = V[id];
        T c = C[id];
        if (d[v] == T(-1) or du + c < d[v]) {
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

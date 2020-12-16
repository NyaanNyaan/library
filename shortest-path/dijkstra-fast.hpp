#pragma once

#include "../data-structure/radix-heap.hpp"
#include "../graph/static-graph.hpp"

template <typename T>
vector<T> dijkstra(StaticGraph<T>& g, int start = 0) {
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

template <typename T>
T dijkstra_point(StaticGraph<T>& g, int start, int goal) {
  vector<T> d(g.size(), T(-1));
  RadixHeap<T, int> Q;
  d[start] = 0;
  Q.push(0, start);
  while (!Q.empty()) {
    auto p = Q.pop();
    int u = p.second;
    if(u == goal) return d[u];
    if (d[u] < T(p.first)) continue;
    T du = d[u];
    for (auto&& [v, c] : g[u]) {
      if (d[v] == T(-1) || du + c < d[v]) {
        d[v] = du + c;
        Q.push(d[v], v);
      }
    }
  }
  return -1;
}

template <typename T>
vector<pair<T, int>> dijkstra_restore(StaticGraph<T>& g, int start = 0) {
  vector<pair<T, int>> d(g.size(), {T(-1), -1});
  RadixHeap<T, int> Q;
  d[start] = {0, -1};
  Q.push(0, start);
  while (!Q.empty()) {
    auto p = Q.pop();
    int u = p.second;
    if (d[u].first < T(p.first)) continue;
    T du = d[u].first;
    for (auto&& [v, c] : g[u]) {
      if (d[v].first == T(-1) || du + c < d[v].first) {
        d[v] = {du + c, u};
        Q.push(du + c, v);
      }
    }
  }
  return d;
}

/*
 * @brief ダイクストラ法(定数倍高速化)
 * @docs docs/shortest-path/dijkstra-fast.md
 **/

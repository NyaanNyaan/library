#pragma once

#include "../graph/graph-template.hpp"

template <typename T>
struct Dual_of_Shortest_Path {
  int N;
  vector<vector<edge<T>>> g;
  T INF;
  vector<T> d;

  Dual_of_Shortest_Path(int _n)
      : N(_n), g(N), INF(numeric_limits<T>::max() / 2.1), d(N, INF) {}

  // add constraint f(j) <= f(i) + w
  void add_edge(int i, int j, T c) { g[i].emplace_back(i, j, c); }

  // solve max{f(t) - f(s)} for each t
  // if unsatisfiable, return empty vector
  vector<T> solve(int start = 0) {
    d[start] = 0;
    for (int loop = 0; loop < N; ++loop) {
      int upd = 0;
      for (int i = 0; i < N; ++i) {
        for (auto& e : g[i]) {
          if (d[i] + e.cost < d[e.to]) {
            d[e.to] = d[i] + e.cost;
            upd = 1;
          }
        }
      }
      if (!upd) break;
      if (loop == N - 1) return {};
    }
    return d;
  }
};

/**
 * @brief 牛ゲー(最短路問題の双対)
 */

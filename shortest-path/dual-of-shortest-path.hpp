#pragma once

#include "../graph/graph-template.hpp"

template <typename T>
struct Dual_of_Shortest_Path {
  int N;
  vector<edge<T>> es;

  Dual_of_Shortest_Path(int _n) : N(_n) {}

  // add constraint f(j) <= f(i) + w
  void add_edge(int i, int j, T c) { es.emplace_back(i, j, c); }

  // if s != -1, solve max{f(t) - f(s)} for each t
  // if unsatisfiable, return empty vector
  vector<T> solve(int start = -1) {
    T INF = numeric_limits<T>::max() / 2.1;
    vector<T> d(N, INF);
    if (start == -1) fill(begin(d), end(d), T{0});
    if (start != -1) d[start] = 0;
    for (int loop = 0; loop < N; loop++) {
      int upd = 0;
      for (auto e : es) {
        if (d[e.src] + e.cost < d[e.to]) {
          d[e.to] = d[e.src] + e.cost;
          upd = 1;
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

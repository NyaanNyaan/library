#pragma once

#include "./graph-template.hpp"

// if the graph is not DAG, return empty vector
template <typename T>
vector<int> TopologicalSort(T &g) {
  int N = g.size();
  vector<int> marked(N, 0), temp(N, 0), v;
  auto visit = [&](auto f, int i) -> bool {
    if (temp[i] == 1) return false;
    if (marked[i] == 0) {
      temp[i] = 1;
      for (auto &e : g[i]) {
        if (f(f, e) == false) return false;
      }
      marked[i] = 1;
      v.push_back(i);
      temp[i] = 0;
    }
    return true;
  };

  for (int i = 0; i < N; i++) {
    if (marked[i] == 0) {
      if (visit(visit, i) == false) return vector<int>();
    }
  }
  reverse(v.begin(), v.end());
  return v;
}
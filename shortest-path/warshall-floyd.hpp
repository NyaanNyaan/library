#pragma once



#include "../graph/graph-template.hpp"

// i : d[i][i] < 0 exists -> negative cycle
template <typename T>
void warshall_floyd(T& d) {
  if((int)d.size() == 0) return;
  int N = d[0].size();
  for (int i = 0; i < N; i++) d[i][i] = 0;
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
#pragma once

#include "gauss-elimination.hpp"

template <typename mint>
vector<vector<mint>> inverse_matrix(const vector<vector<mint>>& a) {
  int N = a.size();
  assert(N > 0);
  assert(N == (int)a[0].size());

  vector<vector<mint>> m(N, vector<mint>(2 * N));
  for (int i = 0; i < N; i++) {
    copy(begin(a[i]), end(a[i]), begin(m[i]));
    m[i][N + i] = 1;
  }

  auto [rank, det] = GaussElimination(m, N, true);
  if (rank != N) return {};

  vector<vector<mint>> b(N);
  for (int i = 0; i < N; i++) {
    copy(begin(m[i]) + N, end(m[i]), back_inserter(b[i]));
  }
  return b;
}

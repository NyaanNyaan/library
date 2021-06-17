#pragma once

#include "matrix.hpp"

template <typename mint>
std::pair<int, mint> GaussElimination(vector<vector<mint>> &a,
                                      int pivot_max = -1,
                                      bool diagonalize = false) {
  int H = a.size(), W = a[0].size();
  int rank = 0, je = pivot_max;
  if (pivot_max == -1) pivot_max = W - 1;
  mint det = 1;
  for (int j = 0; j < je; j++) {
    int idx = -1;
    for (int i = rank; i < H; i++) {
      if (a[i][j] != mint(0)) {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      det = 0;
      continue;
    }
    if (rank != idx) {
      det = -det;
      swap(a[rank], a[idx]);
    }
    det *= a[rank][j];
    if (LE && a[rank][j] != mint(1)) {
      mint coeff = a[rank][j].inverse();
      for (int k = j; k < W; k++) a[rank][k] *= coeff;
    }
    int is = diagonalize ? 0 : rank + 1;
    for (int i = is; i < H; i++) {
      if (i == rank) continue;
      if (a[i][j] != mint(0)) {
        mint coeff = a[i][j] / a[rank][j];
        for (int k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;
      }
    }
    rank++;
  }
  return make_pair(rank, det);
}

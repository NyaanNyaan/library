#pragma once

#include "gauss-elimination.hpp"


template <typename mint>
vector<vector<mint>> LinearEquation(vector<vector<mint>> a, vector<mint> b) {
  int H = a.size(), W = a[0].size();
  for (int i = 0; i < H; i++) a[i].push_back(b[i]);
  auto p = GaussElimination(a, W - 1, true);
  int rank = p.first;

  for (int i = rank; i < H; ++i) {
    if (a[i][W] != 0) return vector<vector<mint>>{};
  }

  vector<vector<mint>> res(1, vector<mint>(W));
  vector<int> pivot(W, -1);
  for (int i = 0, j = 0; i < rank; ++i) {
    while (a[i][j] == 0) ++j;
    res[0][j] = a[i][W], pivot[j] = i;
  }
  for (int j = 0; j < W; ++j) {
    if (pivot[j] == -1) {
      vector<mint> x(W);
      x[j] = 1;
      for (int k = 0; k < j; ++k) {
        if (pivot[k] != -1) x[k] = -a[pivot[k]][j];
      }
      res.push_back(x);
    }
  }
  return res;
}

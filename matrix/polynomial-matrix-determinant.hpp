#pragma once



#include "../fps/formal-power-series.hpp"
#include "../fps/polynomial-interpolation.hpp"
#include "matrix.hpp"

template <typename mint>
FormalPowerSeries<mint> PolynomialMatrixDeterminant(
    const Matrix<FormalPowerSeries<mint>> &m) {
  int N = m.size();
  int deg = 0;
  for (int i = 0; i < N; ++i) deg += max<int>(1, m[i][i].size()) - 1;
  vector<mint> xs(deg + 1);
  vector<mint> ys(deg + 1);
  Matrix<mint> M(N);
  for (int x = 0; x <= deg; x++) {
    xs[x] = x;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) M[i][j] = m[i][j].eval(x);
    ys[x] = M.determinant();
  }
  return PolynomialInterpolation<mint>(xs, ys);
}

/**
 * @brief 多項式行列の行列式
 * @docs docs/matrix/polynomial-matrix-determinant.md
 */

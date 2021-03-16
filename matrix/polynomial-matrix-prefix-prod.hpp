#pragma once

#include "../fps/formal-power-series.hpp"
#include "../fps/sample-point-shift.hpp"
#include "matrix.hpp"

// return m(k-1) * m(k-2) * ... * m(1) * m(0)
template <typename mint>
Matrix<mint> polynomial_matrix_prod(Matrix<FormalPowerSeries<mint>> &m,
                                    long long k) {
  using Mat = Matrix<mint>;
  using fps = FormalPowerSeries<mint>;

  auto shift = [](vector<Mat> &G, mint x) -> vector<Mat> {
    int d = G.size(), n = G[0].size();
    vector<Mat> H(d, Mat(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        fps g(d);
        for (int l = 0; l < d; l++) g[l] = G[l][i][j];
        fps h = SamplePointShift(g, x);
        for (int l = 0; l < d; l++) H[l][i][j] = h[l];
      }
    }
    return H;
  };

  int n = m.size();
  int deg = 1;
  for (auto &_ : m.A) {
    for (auto &x : _) deg = max<int>(deg, (int)x.size() - 1);
  }
  while (deg & (deg - 1)) deg++;

  vector<Mat> G(deg + 1);
  long long v = 1;
  while (deg * v * v < k) v *= 2;
  mint iv = mint(v).inverse();

  for (int i = 0; i < (int)G.size(); i++) {
    mint x = mint(v) * i;
    Mat mt(n);
    for (int j = 0; j < n; j++)
      for (int l = 0; l < n; l++) mt[j][l] = m[j][l].eval(x);
    G[i] = mt;
  }

  for (long long w = 1; w != v; w <<= 1) {
    mint W = w;
    auto G1 = shift(G, W * iv);
    auto G2 = shift(G, (W * deg * v + v) * iv);
    auto G3 = shift(G, (W * deg * v + v + W) * iv);
    for (int i = 0; i <= w * deg; i++)
      G[i] = G1[i] * G[i], G2[i] = G3[i] * G2[i];
    copy(begin(G2), end(G2) - 1, back_inserter(G));
  }

  Mat res = Mat::I(n);
  long long i = 0;
  while (i + v <= k) res = G[i / v] * res, i += v;
  while (i < k) {
    Mat mt(n);
    for (int j = 0; j < n; j++)
      for (int l = 0; l < n; l++) mt[j][l] = m[j][l].eval(i);
    res = mt * res;
    i++;
  }
  return res;
}

/**
 * @brief 多項式行列のprefix product
 */

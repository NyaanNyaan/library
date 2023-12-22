#pragma once

#include "../modulo/binomial.hpp"
#include "composite-exp.hpp"
#include "formal-power-series.hpp"
#include "multipoint-evaluation.hpp"
#include "pascal-matrix.hpp"
#include "polynomial-interpolation.hpp"

// S_{i, j} = stirling{i, j} を満たす行列 S を縦ベクトルに作用
template <typename mint>
FormalPowerSeries<mint> stirling_matrix(FormalPowerSeries<mint> a,
                                        int rev = false) {
  using fps = FormalPowerSeries<mint>;
  if (a.empty()) return {};

  int N = a.size();
  Binomial<mint> binom(N + 10);
  if (rev == false) {
    for (int i = 0; i < N; i++) a[i] *= binom.finv(i);
    fps f = pascal_matrix_trans(a, true);
    fps b = composite_exp<mint>(f, 1, N);
    for (int i = 0; i < N; i++) b[i] *= binom.fac(i);
    return b;
  } else {
    for (int i = 0; i < N; i++) a[i] *= binom.finv(i);
    fps f = inverse_of_composite_exp<mint>(a, 1);
    fps b = pascal_matrix_trans(f, false);
    for (int i = 0; i < N; i++) b[i] *= binom.fac(i);
    return b;
  }
}

// S_{i, j} = stirling{j, i} を満たす行列 S を縦ベクトルに作用
template <typename mint>
FormalPowerSeries<mint> stirling_matrix_trans(FormalPowerSeries<mint> a,
                                              int rev = false) {
  using fps = FormalPowerSeries<mint>;
  if (a.empty()) return {};

  int N = a.size();
  Binomial<mint> binom(N + 10);
  vector<mint> xs(N);
  for (int i = 0; i < N; i++) xs[i] = i;

  if (rev == false) {
    auto _f = MultipointEvaluation(a, xs);
    fps f{begin(_f), end(_f)};
    fps g = pascal_matrix(f, true);
    for (int i = 0; i < N; i++) g[i] *= binom.finv(i);
    return g;
  } else {
    for (int i = 0; i < N; i++) a[i] *= binom.fac(i);
    auto g = pascal_matrix(a, false);
    return PolynomialInterpolation(xs, g);
  }
}

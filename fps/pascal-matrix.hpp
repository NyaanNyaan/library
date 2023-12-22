#pragma once

#include "../modulo/binomial.hpp"
#include "formal-power-series.hpp"

// P_{i, j} = binom(i, j) を満たす行列 P を縦ベクトルに作用
template <typename mint>
FormalPowerSeries<mint> pascal_matrix(FormalPowerSeries<mint> a,
                                      int rev = false) {
  using fps = FormalPowerSeries<mint>;
  if (a.empty()) return {};

  int N = a.size();
  Binomial<mint> binom(N + 10);
  if (rev == false) {
    fps e(N);
    for (int i = 0; i < N; i++) {
      a[i] *= binom.finv(i);
      e[i] = binom.finv(i);
    }
    fps b = (a * e).pre(N);
    for (int i = 0; i < N; i++) b[i] *= binom.fac(i);
    return b;
  } else {
    fps ie(N);
    for (int i = 0; i < N; i++) {
      a[i] *= binom.finv(i);
      ie[i] = binom.finv(i) * (i % 2 ? -1 : 1);
    }
    fps b = (a * ie).pre(N);
    for (int i = 0; i < N; i++) b[i] *= binom.fac(i);
    return b;
  }
}

// P_{i, j} = binom(j, i) を満たす行列 P を縦ベクトルに作用
template <typename mint>
FormalPowerSeries<mint> pascal_matrix_trans(FormalPowerSeries<mint> a,
                                            int rev = false) {
  using fps = FormalPowerSeries<mint>;
  if (a.empty()) return {};

  int N = a.size();
  Binomial<mint> binom(N + 10);
  if (rev == false) {
    fps e(N);
    for (int i = 0; i < N; i++) {
      a[i] *= binom.fac(i);
      e[i] = binom.finv(i);
    }
    fps b = (a.rev() * e).pre(N).rev();
    for (int i = 0; i < N; i++) b[i] *= binom.finv(i);
    return b;
  } else {
    fps ie(N);
    for (int i = 0; i < N; i++) {
      a[i] *= binom.fac(i);
      ie[i] = binom.finv(i) * (i % 2 ? -1 : 1);
    }
    fps b = (a.rev() * ie).pre(N).rev();
    for (int i = 0; i < N; i++) b[i] *= binom.finv(i);
    return b;
  }
}

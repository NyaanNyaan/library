#pragma once

#include "../modulo/binomial.hpp"
#include "formal-power-series.hpp"
#include "fps-famous-series.hpp"

// 数列 a_0, a_1, ... の一般項 a_n が多項式 f(n) で表せるとする
// このとき b_i = sum_{0<=j<=i} a_i の一般項を表す多項式を求める
template <typename mint>
FormalPowerSeries<mint> fualhuber(const FormalPowerSeries<mint>& f,
                                  Binomial<mint>& C) {
  using fps = FormalPowerSeries<mint>;
  int N = f.size();
  auto B = BernoulliEGF(N + 3, C);
  B[1] = -B[1];
  fps s(N), t(N);
  for (int i = 0; i < N; i++) s[i] = f[i] * C.fac(i), t[i] = B[i];
  fps u = s * t.rev();
  fps g(N + 1);
  g[0] = f[0];
  for (int i = 0; i < N; i++) g[i + 1] = u[i + N - 1] * C.finv(i + 1);
  return g;
}

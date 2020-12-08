#pragma once
#include "./formal-power-series.hpp"
#include "../modulo/binomial.hpp"

// calculate F(x + a)
template <typename mint>
FormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint> f, mint a,
                                    Binomial<mint>& C) {
  using fps = FormalPowerSeries<mint>;
  int N = f.size();
  for (int i = 0; i < N; i++) f[i] *= C.fac(i);
  reverse(begin(f), end(f));
  fps g(N, mint(1));
  for (int i = 1; i < N; i++) g[i] = g[i - 1] * a * C.inv(i);
  f = (f * g).pre(N);
  reverse(begin(f), end(f));
  for (int i = 0; i < N; i++) f[i] *= C.finv(i);
  return f;
}

/**
 * @brief 平行移動
 * @docs docs/fps/fps-taylor-shift.md
 */

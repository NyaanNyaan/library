#pragma once
#include "formal-power-series.hpp"

// find f, saitsfying equation f' = g(f) mod x ^ deg
template <typename mint>
FormalPowerSeries<mint> DifferentialEquation(
    function<FormalPowerSeries<mint>(FormalPowerSeries<mint>, int)> g,
    function<FormalPowerSeries<mint>(FormalPowerSeries<mint>, int)> gprime,
    mint f0, int deg) {
  using fps = FormalPowerSeries<mint>;
  fps f{f0};
  for (int i = 1; i < deg; i <<= 1) {
    fps r = (-gprime(f, i << 1)).integral().exp(i << 1);
    fps h = ((g(f, i << 1) - gprime(f, i << 1) * f) * r).pre(i << 1).integral();
    f = ((h + f0) * r.inv(i << 1)).pre(i << 1);
  }
  return f.pre(deg);
}

/**
 * @brief 常微分方程式
 * @docs docs/fps/differential-equation.md
 */

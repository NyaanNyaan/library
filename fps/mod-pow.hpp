#pragma once

#include "formal-power-series.hpp"

template <typename mint>
FormalPowerSeries<mint> mod_pow(int64_t k, const FormalPowerSeries<mint>& base,
                                const FormalPowerSeries<mint>& d) {
  using fps = FormalPowerSeries<mint>;
  assert(!d.empty());
  auto inv = d.rev().inv();
  auto quo = [&](const fps& poly) {
    if (poly.size() < d.size()) return fps{};
    int n = poly.size() - d.size() + 1;
    return (poly.rev().pre(n) * inv.pre(n)).pre(n).rev();
  };
  fps res{1}, b(base);
  while (k) {
    if (k & 1) {
      res *= b;
      res -= quo(res) * d;
      res.shrink();
    }
    b *= b;
    b -= quo(b) * d;
    b.shrink();
    k >>= 1;
    assert(b.size() + 1 <= d.size());
    assert(res.size() + 1 <= d.size());
  }
  return res;
}

/**
 * @brief Mod-Pow ($f(x)^k \mod g(x)$)
 */

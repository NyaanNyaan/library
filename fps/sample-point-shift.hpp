#pragma once

#include "../modulo/binomial.hpp"
#include "formal-power-series.hpp"

// input  : h(0), h(1), ..., h(d - 1)
// output : h(m), h(m + 1), ..., h(m + d - 1)
template <typename mint>
FormalPowerSeries<mint> SamplePointShift(FormalPowerSeries<mint>& ys, mint m) {
  static Binomial<mint> C;
  int d = ys.size() - 1;
  FormalPowerSeries<mint> f(d + 1), g(d * 2 + 1);
  for (int i = 0; i <= d; i++) {
    f[i] = ys[i] * C.finv(i) * C.finv(d - i);
    if ((d - i) & 1) f[i] = -f[i];
  }
  for (int i = 0; i <= 2 * d; i++) {
    assert(m - d + i != mint(0));
    g[i] = (m - d + i).inverse();
  }
  auto h = f * g;
  mint coeff = 1;
  for (int i = 0; i <= d; i++) coeff *= (m - d + i);
  for (int i = 0; i <= d; i++) {
    h[i + d] *= coeff;
    coeff *= (m + i + 1) * g[i];
  }
  return FormalPowerSeries<mint>{begin(h) + d, begin(h) + 2 * d + 1};
}

#pragma once

#include "formal-power-series.hpp"

// b[i] = sum_k c[k] * a[k - i] となる b を計算
template <typename mint>
FormalPowerSeries<mint> middle_product(FormalPowerSeries<mint> a,
                                       FormalPowerSeries<mint> c) {
  int s = a.size(), t = c.size();
  assert(0 < s and s <= t);
  int B = 1;
  while (B < t) B *= 2;
  a = a.rev();
  a.resize(B), c.resize(B);
  a.ntt(), c.ntt();
  for (int i = 0; i < B; i++) a[i] *= c[i];
  a.intt();
  return {begin(a) + s - 1, begin(a) + t};
}

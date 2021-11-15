#pragma once

#include "../modulo/binomial.hpp"
#include "formal-power-series.hpp"

// input : y(0), y(1), ..., y(n - 1)
// output : y(t), y(t + 1), ..., y(t + m - 1)
// (if m is default, m = n)
template <typename mint>
FormalPowerSeries<mint> SamplePointShift(FormalPowerSeries<mint>& y, mint t,
                                         int m = -1) {
  if (m == -1) m = y.size();
  long long T = t.get();
  int k = (int)y.size() - 1;
  T %= mint::get_mod();
  if (T <= k) {
    FormalPowerSeries<mint> ret(m);
    int ptr = 0;
    for (int64_t i = T; i <= k and ptr < m; i++) {
      ret[ptr++] = y[i];
    }
    if (k + 1 < T + m) {
      auto suf = SamplePointShift<mint>(y, k + 1, m - ptr);
      for (int i = k + 1; i < T + m; i++) {
        ret[ptr++] = suf[i - (k + 1)];
      }
    }
    return ret;
  }
  if (T + m > mint::get_mod()) {
    auto pref = SamplePointShift<mint>(y, T, mint::get_mod() - T);
    auto suf = SamplePointShift<mint>(y, 0, m - pref.size());
    copy(begin(suf), end(suf), back_inserter(pref));
    return pref;
  }

  FormalPowerSeries<mint> finv(k + 1, 1), d(k + 1);
  for (int i = 2; i <= k; i++) finv[k] *= i;
  finv[k] = mint(1) / finv[k];
  for (int i = k; i >= 1; i--) finv[i - 1] = finv[i] * i;
  for (int i = 0; i <= k; i++) {
    d[i] = finv[i] * finv[k - i] * y[i];
    if ((k - i) & 1) d[i] = -d[i];
  }

  FormalPowerSeries<mint> h(m + k);
  for (int i = 0; i < m + k; i++) {
    h[i] = mint(1) / (T - k + i);
  }

  auto dh = d * h;

  FormalPowerSeries<mint> ret(m);
  mint cur = T;
  for (int i = 1; i <= k; i++) cur *= T - i;
  for (int i = 0; i < m; i++) {
    ret[i] = cur * dh[k + i];
    cur *= T + i + 1;
    cur *= h[i];
  }
  return ret;
}

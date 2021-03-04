#pragma once

#include "formal-power-series.hpp"

template <typename mint>
FormalPowerSeries<mint> n2_inv(const FormalPowerSeries<mint>& f) {
  assert(f.empty() == false && f[0] != mint(0));
  int n = f.size();
  mint if0 = f[0].inverse();
  FormalPowerSeries<mint> g(n);
  g[0] = if0;
  for (int k = 1; k < n; k++) {
    for (int i = 0; i < k; i++) g[k] += g[i] * f[k - i];
    g[k] *= -if0;
  }
  return g;
}

template <typename mint>
FormalPowerSeries<mint> n2_log(const FormalPowerSeries<mint>& f) {
  assert(f.empty() == false && f[0] == 1);
  int n = f.size(), mod = mint::get_mod();

  static vector<mint> invs{mint(1), mint(1)};
  while ((int)invs.size() <= n) {
    int i = invs.size();
    invs.push_back((-invs[mod % i]) * (mod / i));
  }

  FormalPowerSeries<mint> g(n);
  for (int k = 0; k < n - 1; k++) {
    for (int i = 0; i < k; i++) g[k + 1] -= g[i + 1] * f[k - i] * (i + 1);
    g[k + 1] *= invs[k + 1];
    g[k + 1] += f[k + 1];
  }
  return g;
}

template <typename mint>
FormalPowerSeries<mint> n2_exp(const FormalPowerSeries<mint>& f) {
  assert(f.empty() == false && f[0] == 0);
  int n = f.size(), mod = mint::get_mod();

  static vector<mint> invs{mint(1), mint(1)};
  while ((int)invs.size() <= n) {
    int i = invs.size();
    invs.push_back((-invs[mod % i]) * (mod / i));
  }

  FormalPowerSeries<mint> g(n);
  g[0] = 1;
  for (int k = 0; k < n - 1; k++) {
    for (int i = 0; i <= k; i++) g[k + 1] += f[i + 1] * g[k - i] * (i + 1);
    g[k + 1] *= invs[k + 1];
  }
  return g;
}

template <typename mint>
FormalPowerSeries<mint> n2_sqrt(const FormalPowerSeries<mint>& f) {
  assert(f.empty() == false && f[0] == 1);
  int n = f.size();
  static mint inv2 = mint(2).inverse();
  FormalPowerSeries<mint> g(n);
  g[0] = 1;
  for (int k = 1; k < n; k++) {
    g[k] = f[k];
    for (int i = 1; i <= k - 1; i++) g[k] -= g[i] * g[k - i];
    g[k] *= inv2;
  }
  return g;
}

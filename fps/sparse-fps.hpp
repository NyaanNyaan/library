#pragma once

#include <utility>
#include <vector>
using namespace std;

#include "formal-power-series.hpp"

// g が sparse を仮定, f * g.inv() を計算
template <typename mint>
FormalPowerSeries<mint> sparse_div(const FormalPowerSeries<mint>& f,
                                   const FormalPowerSeries<mint>& g,
                                   int deg = -1) {
  assert(g.empty() == false && g[0] != mint(0));
  if (deg == -1) deg = f.size();
  mint ig0 = g[0].inverse();
  FormalPowerSeries<mint> s = f * ig0;
  s.resize(deg);
  vector<pair<int, mint>> gs;
  for (int i = 1; i < (int)g.size(); i++) {
    if (g[i] != 0) gs.emplace_back(i, g[i] * ig0);
  }
  for (int i = 0; i < deg; i++) {
    for (auto& [j, g_j] : gs) {
      if (i + j >= deg) break;
      s[i + j] -= s[i] * g_j;
    }
  }
  return s;
}

template <typename mint>
FormalPowerSeries<mint> sparse_inv(const FormalPowerSeries<mint>& f,
                                   int deg = -1) {
  assert(f.empty() == false && f[0] != mint(0));
  if (deg == -1) deg = f.size();
  vector<pair<int, mint>> fs;
  for (int i = 1; i < (int)f.size(); i++) {
    if (f[i] != 0) fs.emplace_back(i, f[i]);
  }
  FormalPowerSeries<mint> g(deg);
  mint if0 = f[0].inverse();
  if (0 < deg) g[0] = if0;
  for (int k = 1; k < deg; k++) {
    for (auto& [j, fj] : fs) {
      if (k < j) break;
      g[k] += g[k - j] * fj;
    }
    g[k] *= -if0;
  }
  return g;
}

template <typename mint>
FormalPowerSeries<mint> sparse_log(const FormalPowerSeries<mint>& f,
                                   int deg = -1) {
  assert(f.empty() == false && f[0] == 1);
  if (deg == -1) deg = f.size();
  vector<pair<int, mint>> fs;
  for (int i = 1; i < (int)f.size(); i++) {
    if (f[i] != 0) fs.emplace_back(i, f[i]);
  }

  int mod = mint::get_mod();
  static vector<mint> invs{1, 1};
  while ((int)invs.size() <= deg) {
    int i = invs.size();
    invs.push_back((-invs[mod % i]) * (mod / i));
  }

  FormalPowerSeries<mint> g(deg);
  for (int k = 0; k < deg - 1; k++) {
    for (auto& [j, fj] : fs) {
      if (k < j) break;
      int i = k - j;
      g[k + 1] -= g[i + 1] * fj * (i + 1);
    }
    g[k + 1] *= invs[k + 1];
    if (k + 1 < (int)f.size()) g[k + 1] += f[k + 1];
  }
  return g;
}

template <typename mint>
FormalPowerSeries<mint> sparse_exp(const FormalPowerSeries<mint>& f,
                                   int deg = -1) {
  assert(f.empty() or f[0] == 0);
  if (deg == -1) deg = f.size();
  vector<pair<int, mint>> fs;
  for (int i = 1; i < (int)f.size(); i++) {
    if (f[i] != 0) fs.emplace_back(i, f[i]);
  }

  int mod = mint::get_mod();
  static vector<mint> invs{1, 1};
  while ((int)invs.size() <= deg) {
    int i = invs.size();
    invs.push_back((-invs[mod % i]) * (mod / i));
  }

  FormalPowerSeries<mint> g(deg);
  if (deg) g[0] = 1;
  for (int k = 0; k < deg - 1; k++) {
    for (auto& [ip1, fip1] : fs) {
      int i = ip1 - 1;
      if (k < i) break;
      g[k + 1] += fip1 * g[k - i] * (i + 1);
    }
    g[k + 1] *= invs[k + 1];
  }
  return g;
}

template <typename mint>
FormalPowerSeries<mint> sparse_pow(const FormalPowerSeries<mint>& f,
                                   long long k, int deg = -1) {
  if (deg == -1) deg = f.size();
  if (k == 0) {
    FormalPowerSeries<mint> g(deg);
    if (deg) g[0] = 1;
    return g;
  }
  int zero = 0;
  while (zero != (int)f.size() and f[zero] == 0) zero++;
  if (zero == (int)f.size() or __int128_t(zero) * k >= deg) {
    return FormalPowerSeries<mint>(deg, 0);
  }
  if (zero != 0) {
    FormalPowerSeries<mint> suf{begin(f) + zero, end(f)};
    auto g = sparse_pow(suf, k, deg - zero * k);
    FormalPowerSeries<mint> h(zero * k, 0);
    copy(begin(g), end(g), back_inserter(h));
    return h;
  }

  int mod = mint::get_mod();
  static vector<mint> invs{1, 1};
  while ((int)invs.size() <= deg) {
    int i = invs.size();
    invs.push_back((-invs[mod % i]) * (mod / i));
  }

  vector<pair<int, mint>> fs;
  for (int i = 1; i < (int)f.size(); i++) {
    if (f[i] != 0) fs.emplace_back(i, f[i]);
  }

  FormalPowerSeries<mint> g(deg);
  g[0] = f[0].pow(k);
  mint denom = f[0].inverse();
  k %= mint::get_mod();
  for (int a = 1; a < deg; a++) {
    for (auto& [i, f_i] : fs) {
      if (a < i) break;
      g[a] += f_i * g[a - i] * ((k + 1) * i - a);
    }
    g[a] *= denom * invs[a];
  }
  return g;
}

/**
 * @brief sparse な形式的冪級数の演算
 */

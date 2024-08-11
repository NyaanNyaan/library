#pragma once

#include "../modulo/binomial.hpp"
#include "formal-power-series.hpp"
#include "taylor-shift.hpp"

template <typename mint>
FormalPowerSeries<mint> Stirling1st(int N, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  if (N <= 0) return fps{1};
  int lg = 31 - __builtin_clz(N);
  fps f = {0, 1};
  for (int i = lg - 1; i >= 0; i--) {
    int n = N >> i;
    f *= TaylorShift(f, mint(n >> 1), C);
    if (n & 1) f = (f << 1) + f * (n - 1);
  }
  return f;
}

// S(0, K), S(1, K), ..., S(upper, K) を列挙
template <typename mint>
FormalPowerSeries<mint> Stirling1stRow(int K, int upper, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  if (upper < K) return {};
  fps f(upper + 1);
  for (int i = 1; i < (int)f.size(); i++) f[i] = C.inv(i);
  f = f.pow(K) * C.finv(K);
  for (int n = K; n <= upper; n++) f[n] *= C.fac(n);
  return f;
}

template <typename mint>
FormalPowerSeries<mint> Stirling2nd(int N, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  fps f(N + 1), g(N + 1);
  for (int i = 0; i <= N; i++) {
    f[i] = mint(i).pow(N) * C.finv(i);
    g[i] = (i & 1) ? -C.finv(i) : C.finv(i);
  }
  return (f * g).pre(N + 1);
}

template <typename mint>
FormalPowerSeries<mint> Stirling2ndRow(int K, int upper, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  if (upper < K) return {};
  fps f(upper + 1);
  for (int i = 1; i <= upper; i++) f[i] = C.finv(i);
  f = f.pow(K) * C.finv(K);
  for (int i = K; i <= upper; i++) f[i] *= C.fac(i);
  return f;
}

template <typename mint>
FormalPowerSeries<mint> BernoulliEGF(int N, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  fps f(N + 1);
  for (int i = 0; i <= N; i++) f[i] = C.finv(i + 1);
  return f.inv(N + 1);
}

template <typename mint>
FormalPowerSeries<mint> Partition(int N, Binomial<mint> &) {
  using fps = FormalPowerSeries<mint>;
  fps f(N + 1);
  f[0] = 1;
  for (int k = 1; k <= N; k++) {
    long long k1 = 1LL * k * (3 * k + 1) / 2;
    long long k2 = 1LL * k * (3 * k - 1) / 2;
    if (k2 > N) break;
    if (k1 <= N) f[k1] += ((k & 1) ? -1 : 1);
    if (k2 <= N) f[k2] += ((k & 1) ? -1 : 1);
  }
  return f.inv();
}

template <typename mint>
vector<mint> Montmort(int N) {
  if (N <= 1) return {0};
  if (N == 2) return {0, 1};
  vector<mint> f(N);
  f[0] = 0, f[1] = 1;
  mint coeff = 2, one = 1;
  for (int i = 2; i < N; i++) {
    f[i] = (f[i - 1] + f[i - 2]) * coeff;
    coeff += one;
  }
  return f;
};

/**
 * @brief 有名な数列
 */

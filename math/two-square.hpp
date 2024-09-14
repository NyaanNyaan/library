#pragma once

#include "../internal/internal-math.hpp"
#include "../prime/fast-factorize.hpp"
#include "gaussian-integer.hpp"

// 解が存在しない場合 (-1, -1) を返す
Gaussian_Integer<__int128_t> solve_norm_equation_prime(long long p) {
  if (p % 4 == 3) return {-1, -1};
  if (p == 2) return {1, 1};
  long long x = 1;
  while (true) {
    x++;
    long long z = internal::modpow<long long, __int128_t>(x, (p - 1) / 4, p);
    if (__int128_t(z) * z % p == p - 1) {
      x = z;
      break;
    }
  }
  long long y = 1, k = (__int128_t(x) * x + 1) / p;
  while (k > 1) {
    long long B = x % k, D = y % k;
    if (B < 0) B += k;
    if (D < 0) D += k;
    if (B * 2 > k) B -= k;
    if (D * 2 > k) D -= k;
    long long nx = (__int128_t(x) * B + __int128_t(y) * D) / k;
    long long ny = (__int128_t(x) * D - __int128_t(y) * B) / k;
    x = nx, y = ny;
    k = (__int128_t(x) * x + __int128_t(y) * y) / p;
  }
  return {x, y};
}

// p^e が long long に収まる
vector<Gaussian_Integer<__int128_t>> solve_norm_equation_prime_power(
    long long p, long long e) {
  using G = Gaussian_Integer<__int128_t>;
  if (p % 4 == 3) {
    if (e % 2 == 1) return {};
    long long x = 1;
    for (int i = 0; i < e / 2; i++) x *= p;
    return {G{x}};
  }
  if (p == 2) return {G{1, 1}.pow(e)};
  G pi = solve_norm_equation_prime(p);
  vector<G> pows(e + 1);
  pows[0] = 1;
  for (int i = 1; i <= e; i++) pows[i] = pows[i - 1] * pi;
  vector<G> res(e + 1);
  for (int i = 0; i <= e; i++) res[i] = pows[i] * (pows[e - i].conj());
  return res;
}

// 0 <= arg < 90 の範囲の解のみ返す
vector<Gaussian_Integer<__int128_t>> solve_norm_equation(long long N) {
  using G = Gaussian_Integer<__int128_t>;
  if (N < 0) return {};
  if (N == 0) return {G{0}};
  auto pes = factor_count(N);
  for (auto& [p, e] : pes) {
    if (p % 4 == 3 && e % 2 == 1) return {};
  }
  vector<G> res{G{1}};
  for (auto& [p, e] : pes) {
    vector<G> cur = solve_norm_equation_prime_power(p, e);
    vector<G> nxt;
    for (auto& g1 : res) {
      for (auto& g2 : cur) nxt.push_back(g1 * g2);
    }
    res = nxt;
  }

  for (auto& g : res) {
    while (g.x <= 0 || g.y < 0) g = G{-g.y, g.x};
  }
  return res;
}

// x,y 両方非負のみ, 辞書順で返す
vector<pair<long long, long long>> two_square(long long N) {
  if (N < 0) return {};
  if (N == 0) return {{0, 0}};
  vector<pair<long long, long long>> ans;
  for (auto& g : solve_norm_equation(N)) {
    ans.emplace_back(g.x, g.y);
    if (g.y == 0) ans.emplace_back(g.y, g.x);
  }
  sort(begin(ans), end(ans));
  return ans;
}

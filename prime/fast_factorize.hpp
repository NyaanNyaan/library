#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../inner/inner_math.hpp"
#include "../misc/rng.hpp"
#include "../modint/arbitrary-prime-modint.hpp"
#include "../modint/modint-montgomery64.hpp"

namespace fast_factorize {
using u64 = uint64_t;

template <typename mint>
bool miller_rabin(u64 n, vector<u64> as) {
  if (mint::get_mod() != n) mint::set_mod(n);
  u64 d = n - 1;
  while (~d & 1) d >>= 1;
  mint e{1}, rev{int64_t(n - 1)};
  for (u64 a : as) {
    if (n <= a) break;
    u64 t = d;
    mint y = mint(a).pow(t);
    while (t != n - 1 && y != e && y != rev) {
      y *= y;
      t *= 2;
    }
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool is_prime(u64 n) {
  if (~n & 1) return n == 2;
  if (n <= 1) return false;
  if (n < (1LL << 30))
    return miller_rabin<ArbitraryLazyMontgomeryModInt>(n, {2, 7, 61});
  else
    return miller_rabin<montgomery64>(
        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

template <typename mint, typename T>
T pollard_rho(T n) {
  if (~n & 1) return 2;
  if (is_prime(n)) return n;
  if (mint::get_mod() != n) mint::set_mod(n);
  mint R, one = 1;
  auto f = [&](mint x) { return x * x + R; };
  auto rnd = [&]() { return rng() % (n - 2) + 2; };
  while (1) {
    mint x, y, ys, q = one;
    R = rnd(), y = rnd();
    T g = 1;
    constexpr int m = 128;
    for (int r = 1; g == 1; r <<= 1) {
      x = y;
      for (int i = 0; i < r; ++i) y = f(y);
      for (int k = 0; g == 1 && k < r; k += m) {
        ys = y;
        for (int i = 0; i < m && i < r - k; ++i) q *= x - (y = f(y));
        g = inner::gcd<T>(q.get(), n);
      }
    }
    if (g == n) do
        g = inner::gcd<T>((x - (ys = f(ys))).get(), n);
      while (g == 1);
    if (g != n) return g;
  }
  exit(1);
}

vector<u64> inner_factorize(u64 n) {
  if (n <= 1) return {};
  u64 p;
  if (n <= (1LL << 30))
    p = pollard_rho<ArbitraryLazyMontgomeryModInt, uint32_t>(n);
  else
    p = pollard_rho<montgomery64, uint64_t>(n);
  if (p == n) return {p};
  auto l = inner_factorize(p);
  auto r = inner_factorize(n / p);
  copy(begin(r), end(r), back_inserter(l));
  return l;
}

vector<u64> factorize(u64 n) {
  auto ret = inner_factorize(n);
  sort(begin(ret), end(ret));
  return ret;
}

}  // namespace fast_factorize
using fast_factorize::factorize;
using fast_factorize::is_prime;

/**
 * @brief 高速素因数分解(Miller Rabin/Pollard's Rho)
 * @docs docs/math/prime-factorization.md
 */
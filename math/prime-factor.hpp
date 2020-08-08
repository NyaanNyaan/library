#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../modint/arbitrary-prime-modint.hpp"
#include "../modint/modint-montgomery64.hpp"

template <typename mint>
bool miller_rabin(uint64_t n, vector<uint64_t> as) {
  mint::set_mod(n);
  uint64_t d = n - 1;
  while (d % 2 == 0) d /= 2;
  mint e{1}, rev{int64_t(n - 1)};
  for (uint64_t a : as) {
    if (n <= a) break;
    uint64_t t = d;
    mint y = mint(a).pow(t);
    while (t != n - 1 && y != e && y != rev) {
      y *= y;
      t *= 2;
    }
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool is_prime(uint64_t n) {
  if (n == 2) return true;
  if (n <= 1 || n % 2 == 0) return false;
  if (n < (1LL << 30))
    return miller_rabin<ArbitraryLazyMontgomeryModInt>(n, {2, 7, 61});
  else
    return miller_rabin<montgomery64>(
        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

template <typename mint>
uint64_t pollard_rho(uint64_t n) {
  if (is_prime(n)) return n;
  if (n % 2 == 0) return 2;
  mint::set_mod(n);
  uint64_t d;
  mint one{1}, c{1};
  auto f = [&](mint x) { return x * x + c; };
  for (;; c += one) {
    mint x{2}, y{2};
    do {
      x = f(x), y = f(f(y));
      d = __gcd<uint64_t>((x - y).get(), n);
    } while (d == 1);
    if (d < n) return d;
  }
  assert(0);
}

vector<uint64_t> prime_factor(uint64_t n) {
  if (n <= 1) return {};
  uint64_t p;
  if (n <= (1LL << 30))
    p = pollard_rho<ArbitraryLazyMontgomeryModInt>(n);
  else
    p = pollard_rho<montgomery64>(n);
  if (p == n) return {p};
  auto l = prime_factor(p);
  auto r = prime_factor(n / p);
  copy(begin(r), end(r), back_inserter(l));
  return l;
}

/**
 * @brief 高速素因数分解(Miller Rabin/Pollard's Rho)
 * @docs docs/prime-factorization.md
 */

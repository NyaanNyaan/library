#pragma once

#include <vector>
using namespace std;

#include "../internal/internal-math.hpp"
#include "../modint/arbitrary-montgomery-modint.hpp"

namespace fast_factorize {

template <typename T, typename U>
bool miller_rabin(const T& n, vector<T> ws) {
  if (n <= 2) return n == 2;
  if (n % 2 == 0) return false;

  T d = n - 1;
  while (d % 2 == 0) d /= 2;
  U e = 1, rev = n - 1;
  for (T w : ws) {
    if (w % n == 0) continue;
    T t = d;
    U y = internal::modpow<T, U>(w, t, n);
    while (t != n - 1 && y != e && y != rev) y = y * y % n, t *= 2;
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool miller_rabin_u64(unsigned long long n) {
  return miller_rabin<unsigned long long, __uint128_t>(
      n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

template <typename mint>
bool miller_rabin(unsigned long long n, vector<unsigned long long> ws) {
  if (n <= 2) return n == 2;
  if (n % 2 == 0) return false;

  if (mint::get_mod() != n) mint::set_mod(n);
  unsigned long long d = n - 1;
  while (~d & 1) d >>= 1;
  mint e = 1, rev = n - 1;
  for (unsigned long long w : ws) {
    if (w % n == 0) continue;
    unsigned long long t = d;
    mint y = mint(w).pow(t);
    while (t != n - 1 && y != e && y != rev) y *= y, t *= 2;
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool is_prime(unsigned long long n) {
  using mint32 = ArbitraryLazyMontgomeryModInt<96229631>;
  using mint64 = ArbitraryLazyMontgomeryModInt64bit<622196072>;

  if (n <= 2) return n == 2;
  if (n % 2 == 0) return false;
  if (n < (1uLL << 30)) {
    return miller_rabin<mint32>(n, {2, 7, 61});
  } else if (n < (1uLL << 62)) {
    return miller_rabin<mint64>(
        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
  } else {
    return miller_rabin_u64(n);
  }
}

}  // namespace fast_factorize

using fast_factorize::is_prime;

/**
 * @brief Miller-Rabin primality test
 */

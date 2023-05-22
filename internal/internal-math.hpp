#pragma once

#include "internal-type-traits.hpp"

namespace internal {

#include <cassert>
using namespace std;

// a^{-1} mod p を計算。gcd(a, p) != 1 が必要
template <typename T>
T inv(T a, T p) {
  a = a % p;
  if constexpr (is_broadly_signed_v<T>) {
    if (a < 0) a += p;
  }
  T b = p, x = 1, y = 0;
  while (a) {
    T q = b / a;
    swap(a, b %= a);
    swap(x, y -= q * x);
  }
  assert(b == 1);
  return y < 0 ? y + p : y;
}

// T : 値の型
// U : T*T がオーバーフローしない型
template <typename T, typename U>
T modpow(T a, __int128_t n, T p) {
  T ret = 1 % p;
  while (n) {
    if (n & 1) ret = U(ret) * a % p;
    a = U(a) * a % p;
    n >>= 1;
  }
  return ret;
}

}  // namespace internal

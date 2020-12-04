#pragma once

namespace inner {

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

template <typename T>
T gcd(T a, T b) {
  while (b) swap(a %= b, b);
  return a;
}

template <typename T>
T inv(T a, T p) {
  T b = p, x = 1, y = 0;
  while (a) {
    T q = b / a;
    swap(a, b %= a);
    swap(x, y -= q * x);
  }
  assert(b == 1);
  return y < 0 ? y + p : y;
}

template <typename T, typename U>
T modpow(T a, U n, T p) {
  T ret = 1 % p;
  for (; n; n >>= 1, a = U(a) * a % p)
    if (n & 1) ret = U(ret) * a % p;
  return ret;
}

}  // namespace inner

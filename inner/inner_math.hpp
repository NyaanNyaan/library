#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace inner {

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

template <typename T = i32>
T gcd(T a, T b) {
  while (b) swap(a %= b, b);
  return a;
}

__attribute__((target("avx2"), optimize("O3"))) u64 gcd_fast(u64 x, u64 y) {
  if (x == 0 || y == 0) return x + y;
  u32 bx = __builtin_ctz(x);
  u32 by = __builtin_ctz(y);
  u32 k = min(bx, by);
  x >>= bx, y >>= by;
  while (x != 0 && y != 0)
    if (x == y)
      return x << k;
    else if (x > y)
      x = (x - y) >> __builtin_ctz(x - y);
    else
      y = (y - x) >> __builtin_ctz(y - x);
  return (x + y) << k;
}

template <typename T = int32_t>
T inv(T a, T p) {
  T b = p, x = 1, y = 0;
  while (a) {
    T q = b % a;
    swap(a, b /= a);
    swap(x, y -= q * x);
  }
  assert(b == 1);
  return y < 0 ? y + p : y;
}

template <typename T = int32_t, typename U = int64_t>
T modpow(T a, U n, T p) {
  T ret = 1;
  for (; n; n >>= 1, a = U(a) * a % p)
    if (n & 1) ret = U(ret) * a % p;
  return ret;
}

}  // namespace inner

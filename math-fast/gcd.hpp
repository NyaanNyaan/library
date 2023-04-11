#pragma once

#include <algorithm>
using namespace std;

namespace BinaryGCDImpl {
using u64 = unsigned long long;
using i8 = char;

u64 binary_gcd(u64 a, u64 b) {
  if (a == 0 || b == 0) return a + b;
  i8 n = __builtin_ctzll(a);
  i8 m = __builtin_ctzll(b);
  a >>= n;
  b >>= m;
  n = min(n, m);
  while (a != b) {
    u64 d = a - b;
    i8 s = __builtin_ctzll(d);
    bool f = a > b;
    b = f ? b : a;
    a = (f ? d : -d) >> s;
  }
  return a << n;
}

using u128 = __uint128_t;
// a > 0
int ctz128(u128 a) {
  u64 lo = a & u64(-1);
  return lo ? __builtin_ctzll(lo) : 64 + __builtin_ctzll(a >> 64);
}
u128 binary_gcd128(u128 a, u128 b) {
  if (a == 0 || b == 0) return a + b;
  i8 n = ctz128(a);
  i8 m = ctz128(b);
  a >>= n;
  b >>= m;
  n = min(n, m);
  while (a != b) {
    u128 d = a - b;
    i8 s = ctz128(d);
    bool f = a > b;
    b = f ? b : a;
    a = (f ? d : -d) >> s;
  }
  return a << n;
}

}  // namespace BinaryGCDImpl

long long binary_gcd(long long a, long long b) {
  return BinaryGCDImpl::binary_gcd(abs(a), abs(b));
}
__int128_t binary_gcd128(__int128_t a, __int128_t b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  return BinaryGCDImpl::binary_gcd128(a, b);
}

/**
 * @brief binary GCD
 */

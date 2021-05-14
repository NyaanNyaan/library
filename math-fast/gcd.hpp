#pragma once

#include <algorithm>
using namespace std;

namespace BinaryGCDImpl {
using u64 = unsigned long long;
using i8 = char;

inline u64 binary_gcd(u64 a, u64 b) {
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
}  // namespace BinaryGCDImpl

long long gcd(long long a, long long b) {
  return BinaryGCDImpl::binary_gcd(abs(a), abs(b));
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

/**
 * @brief binary GCD
 */

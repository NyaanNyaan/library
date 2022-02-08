#pragma once

#include <utility>
using namespace std;

struct Barrett {
  using u32 = unsigned int;
  using i64 = long long;
  using u64 = unsigned long long;
  u32 m;
  u64 im;
  Barrett() : m(), im() {}
  Barrett(int n) : m(n), im(u64(-1) / m + 1) {}
  constexpr inline i64 quo(u64 n) {
    u64 x = u64((__uint128_t(n) * im) >> 64);
    u32 r = n - x * m;
    return m <= r ? x - 1 : x;
  }
  constexpr inline i64 rem(u64 n) {
    u64 x = u64((__uint128_t(n) * im) >> 64);
    u32 r = n - x * m;
    return m <= r ? r + m : r;
  }
  constexpr inline pair<i64, int> quorem(u64 n) {
    u64 x = u64((__uint128_t(n) * im) >> 64);
    u32 r = n - x * m;
    if (m <= r) return {x - 1, r + m};
    return {x, r};
  }
  constexpr inline i64 pow(u64 n, i64 p) {
    u32 a = rem(n), r = m == 1 ? 0 : 1;
    while (p) {
      if (p & 1) r = rem(u64(r) * a);
      a = rem(u64(a) * a);
      p >>= 1;
    }
    return r;
  }
};
#pragma once

#include "internal-type-traits.hpp"

namespace internal {

#include <cassert>
#include <utility>
#include <vector>
using namespace std;

// a mod p
template <typename T>
T safe_mod(T a, T p) {
  a %= p;
  if constexpr (is_broadly_signed_v<T>) {
    if (a < 0) a += p;
  }
  return a;
}

// 返り値：pair(g, x)
// s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
template <typename T>
pair<T, T> inv_gcd(T a, T p) {
  static_assert(is_broadly_signed_v<T>);
  a = safe_mod(a, p);
  if (a == 0) return {p, 0};
  T b = p, x = 1, y = 0;
  while (a != 0) {
    T q = b / a;
    swap(a, b %= a);
    swap(x, y -= q * x);
  }
  if (y < 0) y += p / b;
  return {b, y};
}

// 返り値 : a^{-1} mod p
// gcd(a, p) != 1 が必要
template <typename T>
T inv(T a, T p) {
  static_assert(is_broadly_signed_v<T>);
  a = safe_mod(a, p);
  T b = p, x = 1, y = 0;
  while (a != 0) {
    T q = b / a;
    swap(a, b %= a);
    swap(x, y -= q * x);
  }
  assert(b == 1);
  return y < 0 ? y + p : y;
}

// T : 底の型
// U : T*T がオーバーフローしない かつ 指数の型
template <typename T, typename U>
T modpow(T a, U n, T p) {
  a = safe_mod(a, p);
  T ret = 1 % p;
  while (n != 0) {
    if (n % 2 == 1) ret = U(ret) * a % p;
    a = U(a) * a % p;
    n /= 2;
  }
  return ret;
}

// 返り値 : pair(rem, mod)
// 解なしのときは {0, 0} を返す
template <typename T>
pair<T, T> crt(const vector<T>& r, const vector<T>& m) {
  static_assert(is_broadly_signed_v<T>);
  assert(r.size() == m.size());
  int n = int(r.size());
  T r0 = 0, m0 = 1;
  for (int i = 0; i < n; i++) {
    assert(1 <= m[i]);
    T r1 = safe_mod(r[i], m[i]), m1 = m[i];
    if (m0 < m1) swap(r0, r1), swap(m0, m1);
    if (m0 % m1 == 0) {
      if (r0 % m1 != r1) return {0, 0};
      continue;
    }
    auto [g, im] = inv_gcd(m0, m1);
    T u1 = m1 / g;
    if ((r1 - r0) % g) return {0, 0};
    T x = (r1 - r0) / g % u1 * im % u1;
    r0 += x * m0;
    m0 *= u1;
    if (r0 < 0) r0 += m0;
  }
  return {r0, m0};
}

}  // namespace internal

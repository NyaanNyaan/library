#pragma once

#include <algorithm>
#include <cassert>
#include <tuple>
#include <utility>
#include <vector>

namespace atcoder {

// @param m `1 <= m`
// @return x mod m
template <typename T>
constexpr T safe_mod(T x, T m) {
  x %= m;
  if (x < 0) x += m;
  return x;
}

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
template <typename T>
constexpr std::pair<T, T> inv_gcd(T a, T b) {
  a = safe_mod(a, b);
  if (a == 0) return {b, 0};

  // Contracts:
  // [1] s - m0 * a = 0 (mod b)
  // [2] t - m1 * a = 0 (mod b)
  // [3] s * |m1| + t * |m0| <= b
  T s = b, t = a;
  T m0 = 0, m1 = 1;

  while (t) {
    T u = s / t;
    s -= t * u;
    m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

    // [3]:
    // (s - t * u) * |m1| + t * |m0 - m1 * u|
    // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
    // = s * |m1| + t * |m0| <= b

    auto tmp = s;
    s = t;
    t = tmp;
    tmp = m0;
    m0 = m1;
    m1 = tmp;
  }
  // by [3]: |m0| <= b/g
  // by g != b: |m0| < b/g
  if (m0 < 0) m0 += b / s;
  return {s, m0};
}

template <typename T>
T inv_mod(T x, T m) {
  assert(1 <= m);
  auto z = inv_gcd(x, m);
  assert(z.first == 1);
  return z.second;
}

// (rem, mod)
template <typename T>
std::pair<T, T> crt(const std::vector<T>& r, const std::vector<T>& m) {
  assert(r.size() == m.size());
  int n = int(r.size());
  // Contracts: 0 <= r0 < m0
  T r0 = 0, m0 = 1;
  for (int i = 0; i < n; i++) {
    assert(1 <= m[i]);
    T r1 = safe_mod(r[i], m[i]), m1 = m[i];
    if (m0 < m1) {
      std::swap(r0, r1);
      std::swap(m0, m1);
    }
    if (m0 % m1 == 0) {
      if (r0 % m1 != r1) return {0, 0};
      continue;
    }
    // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)

    // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));
    // r2 % m0 = r0
    // r2 % m1 = r1
    // -> (r0 + x*m0) % m1 = r1
    // -> x*u0*g % (u1*g) = (r1 - r0) (u0*g = m0, u1*g = m1)
    // -> x = (r1 - r0) / g * inv(u0) (mod u1)

    // im = inv(u0) (mod u1) (0 <= im < u1)
    T g, im;
    std::tie(g, im) = inv_gcd(m0, m1);

    T u1 = (m1 / g);
    // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)
    if ((r1 - r0) % g) return {0, 0};

    // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)
    T x = (r1 - r0) / g % u1 * im % u1;

    // |r0| + |m0 * x|
    // < m0 + m0 * (u1 - 1)
    // = m0 + m0 * m1 / g - m0
    // = lcm(m0, m1)
    r0 += x * m0;
    m0 *= u1;  // -> lcm(m0, m1)
    if (r0 < 0) r0 += m0;
  }
  return {r0, m0};
}
}  // namespace atcoder

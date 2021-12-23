#pragma once

// input  : a, M (0 < a < M)
// output : pair(g, x) s.t. g = gcd(a, M), xa = g (mod M), 0 <= x < b/g
template <typename uint>
pair<uint, uint> gcd_inv(uint a, uint M) {
  assert(M != 0 && 0 < a);
  a %= M;
  uint b = M, s = 1, t = 0;
  while (true) {
    if (a == 0) return {b, t + M};
    t -= b / a * s;
    b %= a;
    if (b == 0) return {a, s};
    s -= a / b * t;
    a %= b;
  }
}

// 入力 : 0 <= rem[i] < mod[i], 1 <= mod[i]
// 存在するとき   : return {rem, mod}
// 存在しないとき : return {0, 0}
template <typename T, typename U>
pair<unsigned long long, unsigned long long> garner(const vector<T>& rem,
                                                    const vector<U>& mod) {
  assert(rem.size() == mod.size());
  using u64 = unsigned long long;
  u64 r0 = 0, m0 = 1;
  for (int i = 0; i < (int)rem.size(); i++) {
    assert(1 <= mod[i]);
    assert(0 <= rem[i] && rem[i] < mod[i]);
    u64 m1 = mod[i], r1 = rem[i] % m1;
    if (m0 < m1) swap(r0, r1), swap(m0, m1);
    if (m0 % m1 == 0) {
      if (r0 % m1 != r1) return {0, 0};
      continue;
    }
    u64 g, im;
    tie(g, im) = gcd_inv(m0, m1);
    u64 y = r0 < r1 ? r1 - r0 : r0 - r1;
    if (y % g != 0) return {0, 0};
    u64 u1 = m1 / g;
    y = y / g % u1;
    if (r0 > r1 && y != 0) y = u1 - y;
    u64 x = y * im % u1;
    r0 += x * m0;
    m0 *= u1;
  }
  return {r0, m0};
}

/**
 * @brief Garner's algorithm
 */

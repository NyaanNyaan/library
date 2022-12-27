#pragma once

#include "../modint/montgomery-modint.hpp"
#include "./ntt.hpp"

namespace ArbitraryNTT {
using i64 = int64_t;
using u128 = __uint128_t;
constexpr int32_t m0 = 167772161;
constexpr int32_t m1 = 469762049;
constexpr int32_t m2 = 754974721;
using mint0 = LazyMontgomeryModInt<m0>;
using mint1 = LazyMontgomeryModInt<m1>;
using mint2 = LazyMontgomeryModInt<m2>;
constexpr int r01 = mint1(m0).inverse().get();
constexpr int r02 = mint2(m0).inverse().get();
constexpr int r12 = mint2(m1).inverse().get();
constexpr int r02r12 = i64(r02) * r12 % m2;
constexpr i64 w1 = m0;
constexpr i64 w2 = i64(m0) * m1;

template <typename T, typename submint>
vector<submint> mul(const vector<T> &a, const vector<T> &b) {
  static NTT<submint> ntt;
  vector<submint> s(a.size()), t(b.size());
  for (int i = 0; i < (int)a.size(); ++i) s[i] = i64(a[i] % submint::get_mod());
  for (int i = 0; i < (int)b.size(); ++i) t[i] = i64(b[i] % submint::get_mod());
  return ntt.multiply(s, t);
}

template <typename T>
vector<int> multiply(const vector<T> &s, const vector<T> &t, int mod) {
  auto d0 = mul<T, mint0>(s, t);
  auto d1 = mul<T, mint1>(s, t);
  auto d2 = mul<T, mint2>(s, t);
  int n = d0.size();
  vector<int> ret(n);
  const int W1 = w1 % mod;
  const int W2 = w2 % mod;
  for (int i = 0; i < n; i++) {
    int n1 = d1[i].get(), n2 = d2[i].get(), a = d0[i].get();
    int b = i64(n1 + m1 - a) * r01 % m1;
    int c = (i64(n2 + m2 - a) * r02r12 + i64(m2 - b) * r12) % m2;
    ret[i] = (i64(a) + i64(b) * W1 + i64(c) * W2) % mod;
  }
  return ret;
}

template <typename mint>
vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
  if (a.size() == 0 && b.size() == 0) return {};
  if (min<int>(a.size(), b.size()) < 128) {
    vector<mint> ret(a.size() + b.size() - 1);
    for (int i = 0; i < (int)a.size(); ++i)
      for (int j = 0; j < (int)b.size(); ++j) ret[i + j] += a[i] * b[j];
    return ret;
  }
  vector<int> s(a.size()), t(b.size());
  for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i].get();
  for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i].get();
  vector<int> u = multiply<int>(s, t, mint::get_mod());
  vector<mint> ret(u.size());
  for (int i = 0; i < (int)u.size(); ++i) ret[i] = mint(u[i]);
  return ret;
}

template <typename T>
vector<u128> multiply_u128(const vector<T> &s, const vector<T> &t) {
  if (s.size() == 0 && t.size() == 0) return {};
  if (min<int>(s.size(), t.size()) < 128) {
    vector<u128> ret(s.size() + t.size() - 1);
    for (int i = 0; i < (int)s.size(); ++i)
      for (int j = 0; j < (int)t.size(); ++j) ret[i + j] += i64(s[i]) * t[j];
    return ret;
  }
  auto d0 = mul<T, mint0>(s, t);
  auto d1 = mul<T, mint1>(s, t);
  auto d2 = mul<T, mint2>(s, t);
  int n = d0.size();
  vector<u128> ret(n);
  for (int i = 0; i < n; i++) {
    i64 n1 = d1[i].get(), n2 = d2[i].get();
    i64 a = d0[i].get();
    i64 b = (n1 + m1 - a) * r01 % m1;
    i64 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
    ret[i] = a + b * w1 + u128(c) * w2;
  }
  return ret;
}
}  // namespace ArbitraryNTT

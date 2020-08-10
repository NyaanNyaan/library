#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../modint/montgomery-modint.hpp"
#include "./ntt-avx2.hpp"

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
  NTT<submint> ntt;
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
  for (int i = 0; i < n; i++) {
    i64 n1 = d1[i].get(), n2 = d2[i].get();
    i64 a = d0[i].get();
    i64 b = (n1 + m1 - a) * r01 % m1;
    i64 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
    ret[i] = (a + b * w1 + c * w2) % mod;
  }
  return ret;
}

template <typename mint>
vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
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
  auto d0 = mul<T, mint0>(s, t);
  auto d1 = mul<T, mint1>(s, t);
  auto d2 = mul<T, mint2>(s, t);
  int n = d0.size();
  vector<u128> ret(n);
  for (int i = 0; i < n; i++) {
    i64 n1 = d1[i].get(), n2 = d2[i].get();
    i64 a = d0[i].get();
    u128 b = (n1 + m1 - a) * r01 % m1;
    u128 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
    ret[i] = a + b * w1 + c * w2;
  }
  return ret;
}

/*
template <int mod>
vector<int> multiply(const vector<int> &s, const vector<int> &t) {
  auto d0 = mul<m0>(s, t);
  auto d1 = mul<m1>(s, t);
  auto d2 = mul<m2>(s, t);
  int n = d0.size();
  vector<int> res(n);
  using i64 = int64_t;
  static const int r01 = mint1(m0).inverse().get();
  static const int r02 = mint2(m0).inverse().get();
  static const int r12 = mint2(m1).inverse().get();
  static const int r02r12 = i64(r02) * r12 % m2;
  static const int w1 = m0 % mod;
  static const int w2 = i64(w1) * m1 % mod;
  for (int i = 0; i < n; i++) {
    i64 n1 = d1[i].get(), n2 = d2[i].get();
    i64 a = d0[i].get();
    i64 b = (n1 + m1 - a) * r01 % m1;
    i64 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
    res[i] = (a + b * w1 + c * w2) % mod;
  }
  return std::move(res);
}

template <int mod>
vector<LazyMontgomeryModInt<mod>> multiply(
    const vector<LazyMontgomeryModInt<mod>> &a,
    const vector<LazyMontgomeryModInt<mod>> &b) {
  using mint = LazyMontgomeryModInt<mod>;
  vector<int> s(a.size()), t(b.size());
  for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i].get();
  for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i].get();
  vector<int> u = multiply<mod>(s, t);
  vector<mint> ret(u.size());
  for (int i = 0; i < (int)u.size(); ++i)
    ret[i].a = mint::reduce(uint64_t(u[i]) * mint::n2);
  return std::move(ret);
}
*/
}  // namespace ArbitraryNTT
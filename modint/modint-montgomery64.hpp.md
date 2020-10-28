---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: modulo/mod-kth-root.hpp
    title: kth root(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-factorization.test.cpp
    title: verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/modint-montgomery64.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct montgomery64 {\n  using mint = montgomery64;\n\
    \  using i64 = int64_t;\n  using u64 = uint64_t;\n  using u128 = __uint128_t;\n\
    \n  static u64 mod;\n  static u64 r;\n  static u64 n2;\n\n  static u64 get_r()\
    \ {\n    u64 ret = mod;\n    for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;\n\
    \    return ret;\n  }\n\n  static void set_mod(u64 m) {\n    assert(m < (1LL <<\
    \ 62));\n    assert((m & 1) == 1);\n    mod = m;\n    n2 = -u128(m) % m;\n   \
    \ r = get_r();\n    assert(r * mod == 1);\n  }\n\n  u64 a;\n\n  montgomery64()\
    \ : a(0) {}\n  montgomery64(const int64_t &b) : a(reduce((u128(b) + mod) * n2)){};\n\
    \n  static u64 reduce(const u128 &b) {\n    return (b + u128(u64(b) * u64(-r))\
    \ * mod) >> 64;\n  }\n\n  mint &operator+=(const mint &b) {\n    if (i64(a +=\
    \ b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint &operator-=(const\
    \ mint &b) {\n    if (i64(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\
    \n  mint &operator*=(const mint &b) {\n    a = reduce(u128(a) * b.a);\n    return\
    \ *this;\n  }\n\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n\
    \    return *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this)\
    \ += b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n\
    \  mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n  bool operator==(const mint &b)\
    \ const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n\
    \  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod ? a - mod\
    \ : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const { return\
    \ mint() - mint(*this); }\n\n  mint pow(u128 n) const {\n    mint ret(1), mul(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = montgomery64(t);\n  \
    \  return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n  u64\
    \ get() const {\n    u64 ret = reduce(a);\n    return ret >= mod ? ret - mod :\
    \ ret;\n  }\n\n  static u64 get_mod() { return mod; }\n};\ntypename montgomery64::u64\
    \ montgomery64::mod, montgomery64::r, montgomery64::n2;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct montgomery64\
    \ {\n  using mint = montgomery64;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\
    \  using u128 = __uint128_t;\n\n  static u64 mod;\n  static u64 r;\n  static u64\
    \ n2;\n\n  static u64 get_r() {\n    u64 ret = mod;\n    for (i64 i = 0; i < 5;\
    \ ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static void set_mod(u64\
    \ m) {\n    assert(m < (1LL << 62));\n    assert((m & 1) == 1);\n    mod = m;\n\
    \    n2 = -u128(m) % m;\n    r = get_r();\n    assert(r * mod == 1);\n  }\n\n\
    \  u64 a;\n\n  montgomery64() : a(0) {}\n  montgomery64(const int64_t &b) : a(reduce((u128(b)\
    \ + mod) * n2)){};\n\n  static u64 reduce(const u128 &b) {\n    return (b + u128(u64(b)\
    \ * u64(-r)) * mod) >> 64;\n  }\n\n  mint &operator+=(const mint &b) {\n    if\
    \ (i64(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint\
    \ &operator-=(const mint &b) {\n    if (i64(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  mint &operator*=(const mint &b) {\n    a = reduce(u128(a)\
    \ * b.a);\n    return *this;\n  }\n\n  mint &operator/=(const mint &b) {\n   \
    \ *this *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const mint\
    \ &b) const { return mint(*this) += b; }\n  mint operator-(const mint &b) const\
    \ { return mint(*this) -= b; }\n  mint operator*(const mint &b) const { return\
    \ mint(*this) *= b; }\n  mint operator/(const mint &b) const { return mint(*this)\
    \ /= b; }\n  bool operator==(const mint &b) const {\n    return (a >= mod ? a\
    \ - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  mint operator-() const { return mint() - mint(*this); }\n\
    \n  mint pow(u128 n) const {\n    mint ret(1), mul(*this);\n    while (n > 0)\
    \ {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n\
    \    return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint\
    \ &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = montgomery64(t);\n  \
    \  return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n  u64\
    \ get() const {\n    u64 ret = reduce(a);\n    return ret >= mod ? ret - mod :\
    \ ret;\n  }\n\n  static u64 get_mod() { return mod; }\n};\ntypename montgomery64::u64\
    \ montgomery64::mod, montgomery64::r, montgomery64::n2;\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/modint-montgomery64.hpp
  requiredBy:
  - prime/fast-factorize.hpp
  - modulo/mod-kth-root.hpp
  timestamp: '2020-08-09 01:48:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - verify/verify-unit-test/osak.test.cpp
documentation_of: modint/modint-montgomery64.hpp
layout: document
redirect_from:
- /library/modint/modint-montgomery64.hpp
- /library/modint/modint-montgomery64.hpp.html
title: modint/modint-montgomery64.hpp
---

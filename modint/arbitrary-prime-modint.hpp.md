---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps-sqrt.hpp
    title: "\u5E73\u65B9\u6839"
  - icon: ':heavy_check_mark:'
    path: modulo/mod-kth-root.hpp
    title: kth root(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: modulo/mod-sqrt.hpp
    title: mod sqrt(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-factorization.test.cpp
    title: verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/arbitrary-prime-modint.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct ArbitraryLazyMontgomeryModInt {\n  using mint =\
    \ ArbitraryLazyMontgomeryModInt;\n  using i32 = int32_t;\n  using u32 = uint32_t;\n\
    \  using u64 = uint64_t;\n\n  static u32 mod;\n  static u32 r;\n  static u32 n2;\n\
    \n  static u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i)\
    \ ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static void set_mod(u32 m)\
    \ {\n    assert(m < (1 << 30));\n    assert((m & 1) == 1);\n    mod = m;\n   \
    \ n2 = -u64(m) % m;\n    r = get_r();\n    assert(r * mod == 1);\n  }\n\n  u32\
    \ a;\n\n  ArbitraryLazyMontgomeryModInt() : a(0) {}\n  ArbitraryLazyMontgomeryModInt(const\
    \ int64_t &b)\n      : a(reduce(u64(b % mod + mod) * n2)){};\n\n  static u32 reduce(const\
    \ u64 &b) {\n    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  mint\
    \ &operator+=(const mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 *\
    \ mod;\n    return *this;\n  }\n\n  mint &operator-=(const mint &b) {\n    if\
    \ (i32(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint\
    \ &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  mint operator+(const mint &b) const { return mint(*this) += b; }\n \
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  mint operator*(const\
    \ mint &b) const { return mint(*this) *= b; }\n  mint operator/(const mint &b)\
    \ const { return mint(*this) /= b; }\n  bool operator==(const mint &b) const {\n\
    \    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n\
    \  bool operator!=(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const { return mint()\
    \ - mint(*this); }\n\n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModInt(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n\
    \  u32 get() const {\n    u32 ret = reduce(a);\n    return ret >= mod ? ret -\
    \ mod : ret;\n  }\n\n  static u32 get_mod() { return mod; }\n};\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::mod;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::r;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::n2;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct ArbitraryLazyMontgomeryModInt\
    \ {\n  using mint = ArbitraryLazyMontgomeryModInt;\n  using i32 = int32_t;\n \
    \ using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static u32 mod;\n  static\
    \ u32 r;\n  static u32 n2;\n\n  static u32 get_r() {\n    u32 ret = mod;\n   \
    \ for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n\
    \  static void set_mod(u32 m) {\n    assert(m < (1 << 30));\n    assert((m & 1)\
    \ == 1);\n    mod = m;\n    n2 = -u64(m) % m;\n    r = get_r();\n    assert(r\
    \ * mod == 1);\n  }\n\n  u32 a;\n\n  ArbitraryLazyMontgomeryModInt() : a(0) {}\n\
    \  ArbitraryLazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod\
    \ + mod) * n2)){};\n\n  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b)\
    \ * u32(-r)) * mod) >> 32;\n  }\n\n  mint &operator+=(const mint &b) {\n    if\
    \ (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  mint &operator*=(const mint &b) {\n    a = reduce(u64(a)\
    \ * b.a);\n    return *this;\n  }\n\n  mint &operator/=(const mint &b) {\n   \
    \ *this *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const mint\
    \ &b) const { return mint(*this) += b; }\n  mint operator-(const mint &b) const\
    \ { return mint(*this) -= b; }\n  mint operator*(const mint &b) const { return\
    \ mint(*this) *= b; }\n  mint operator/(const mint &b) const { return mint(*this)\
    \ /= b; }\n  bool operator==(const mint &b) const {\n    return (a >= mod ? a\
    \ - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  mint operator-() const { return mint() - mint(*this); }\n\
    \n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n\
    \      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b) {\n  \
    \  return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is, mint\
    \ &b) {\n    int64_t t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModInt(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n\
    \  u32 get() const {\n    u32 ret = reduce(a);\n    return ret >= mod ? ret -\
    \ mod : ret;\n  }\n\n  static u32 get_mod() { return mod; }\n};\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::mod;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::r;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::n2;\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/arbitrary-prime-modint.hpp
  requiredBy:
  - prime/fast-factorize.hpp
  - modulo/mod-sqrt.hpp
  - modulo/mod-kth-root.hpp
  - fps/fps-sqrt.hpp
  timestamp: '2020-07-28 19:14:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp
  - verify/verify-unit-test/osak.test.cpp
  - verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
  - verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
documentation_of: modint/arbitrary-prime-modint.hpp
layout: document
redirect_from:
- /library/modint/arbitrary-prime-modint.hpp
- /library/modint/arbitrary-prime-modint.hpp.html
title: modint/arbitrary-prime-modint.hpp
---

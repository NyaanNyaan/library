---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/barrett-reduction.hpp
    title: modint/barrett-reduction.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ntt/multivariate-circular-convolution.hpp
    title: "\u591A\u5909\u6570\u5DE1\u56DE\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/arbitrary-modint.test.cpp
    title: verify/verify-unit-test/arbitrary-modint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/barrett-reduction.test.cpp
    title: verify/verify-unit-test/barrett-reduction.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/garner-bigint.test.cpp
    title: verify/verify-unit-test/garner-bigint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-binomial-coefficient-prime-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-binomial-coefficient-prime-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "modint (2^{30} \u672A\u6E80\u306E\u4EFB\u610F mod \u7528)"
    links: []
  bundledCode: "#line 2 \"modint/arbitrary-modint.hpp\"\n\n#line 2 \"modint/barrett-reduction.hpp\"\
    \n\n#include <utility>\nusing namespace std;\n\nstruct Barrett {\n  using u32\
    \ = unsigned int;\n  using i64 = long long;\n  using u64 = unsigned long long;\n\
    \  u32 m;\n  u64 im;\n  Barrett() : m(), im() {}\n  Barrett(int n) : m(n), im(u64(-1)\
    \ / m + 1) {}\n  constexpr inline i64 quo(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    return m <= r ? x - 1 : x;\n  }\n\
    \  constexpr inline i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >>\
    \ 64);\n    u32 r = n - x * m;\n    return m <= r ? r + m : r;\n  }\n  constexpr\
    \ inline pair<i64, int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n) * im)\
    \ >> 64);\n    u32 r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n  \
    \  return {x, r};\n  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32 a\
    \ = rem(n), r = m == 1 ? 0 : 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r)\
    \ * a);\n      a = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n\
    };\n#line 4 \"modint/arbitrary-modint.hpp\"\n\ntemplate <int id>\nstruct ArbitraryModIntBase\
    \ {\n  int x;\n\n  ArbitraryModIntBase() : x(0) {}\n\n  ArbitraryModIntBase(int64_t\
    \ y) {\n    int z = y % get_mod();\n    if (z < 0) z += get_mod();\n    x = z;\n\
    \  }\n\n  ArbitraryModIntBase &operator+=(const ArbitraryModIntBase &p) {\n  \
    \  if ((x += p.x) >= get_mod()) x -= get_mod();\n    return *this;\n  }\n\n  ArbitraryModIntBase\
    \ &operator-=(const ArbitraryModIntBase &p) {\n    if ((x += get_mod() - p.x)\
    \ >= get_mod()) x -= get_mod();\n    return *this;\n  }\n\n  ArbitraryModIntBase\
    \ &operator*=(const ArbitraryModIntBase &p) {\n    x = rem((unsigned long long)x\
    \ * p.x);\n    return *this;\n  }\n\n  ArbitraryModIntBase &operator/=(const ArbitraryModIntBase\
    \ &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n\n  ArbitraryModIntBase\
    \ operator-() const { return ArbitraryModIntBase(-x); }\n  ArbitraryModIntBase\
    \ operator+() const { return *this; }\n\n  ArbitraryModIntBase operator+(const\
    \ ArbitraryModIntBase &p) const {\n    return ArbitraryModIntBase(*this) += p;\n\
    \  }\n\n  ArbitraryModIntBase operator-(const ArbitraryModIntBase &p) const {\n\
    \    return ArbitraryModIntBase(*this) -= p;\n  }\n\n  ArbitraryModIntBase operator*(const\
    \ ArbitraryModIntBase &p) const {\n    return ArbitraryModIntBase(*this) *= p;\n\
    \  }\n\n  ArbitraryModIntBase operator/(const ArbitraryModIntBase &p) const {\n\
    \    return ArbitraryModIntBase(*this) /= p;\n  }\n\n  bool operator==(const ArbitraryModIntBase\
    \ &p) const { return x == p.x; }\n\n  bool operator!=(const ArbitraryModIntBase\
    \ &p) const { return x != p.x; }\n\n  ArbitraryModIntBase inverse() const {\n\
    \    int a = x, b = get_mod(), u = 1, v = 0, t;\n    while (b > 0) {\n      t\
    \ = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t * v, v);\n    }\n  \
    \  return ArbitraryModIntBase(u);\n  }\n\n  ArbitraryModIntBase pow(int64_t n)\
    \ const {\n    ArbitraryModIntBase ret(1), mul(x);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const ArbitraryModIntBase\
    \ &p) {\n    return os << p.x;\n  }\n\n  friend istream &operator>>(istream &is,\
    \ ArbitraryModIntBase &a) {\n    int64_t t;\n    is >> t;\n    a = ArbitraryModIntBase(t);\n\
    \    return (is);\n  }\n\n  int get() const { return x; }\n\n  inline unsigned\
    \ int rem(unsigned long long p) { return barrett().rem(p); }\n\n  static inline\
    \ Barrett &barrett() {\n    static Barrett b;\n    return b;\n  }\n\n  static\
    \ inline int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\n \
    \ static void set_mod(int md) {\n    assert(0 < md && md <= (1LL << 30) - 1);\n\
    \    get_mod() = md;\n    barrett() = Barrett(md);\n  }\n};\n\nusing ArbitraryModInt\
    \ = ArbitraryModIntBase<-1>;\n\n/**\n * @brief modint (2^{30} \u672A\u6E80\u306E\
    \u4EFB\u610F mod \u7528)\n */\n"
  code: "#pragma once\n\n#include \"barrett-reduction.hpp\"\n\ntemplate <int id>\n\
    struct ArbitraryModIntBase {\n  int x;\n\n  ArbitraryModIntBase() : x(0) {}\n\n\
    \  ArbitraryModIntBase(int64_t y) {\n    int z = y % get_mod();\n    if (z < 0)\
    \ z += get_mod();\n    x = z;\n  }\n\n  ArbitraryModIntBase &operator+=(const\
    \ ArbitraryModIntBase &p) {\n    if ((x += p.x) >= get_mod()) x -= get_mod();\n\
    \    return *this;\n  }\n\n  ArbitraryModIntBase &operator-=(const ArbitraryModIntBase\
    \ &p) {\n    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n    return\
    \ *this;\n  }\n\n  ArbitraryModIntBase &operator*=(const ArbitraryModIntBase &p)\
    \ {\n    x = rem((unsigned long long)x * p.x);\n    return *this;\n  }\n\n  ArbitraryModIntBase\
    \ &operator/=(const ArbitraryModIntBase &p) {\n    *this *= p.inverse();\n   \
    \ return *this;\n  }\n\n  ArbitraryModIntBase operator-() const { return ArbitraryModIntBase(-x);\
    \ }\n  ArbitraryModIntBase operator+() const { return *this; }\n\n  ArbitraryModIntBase\
    \ operator+(const ArbitraryModIntBase &p) const {\n    return ArbitraryModIntBase(*this)\
    \ += p;\n  }\n\n  ArbitraryModIntBase operator-(const ArbitraryModIntBase &p)\
    \ const {\n    return ArbitraryModIntBase(*this) -= p;\n  }\n\n  ArbitraryModIntBase\
    \ operator*(const ArbitraryModIntBase &p) const {\n    return ArbitraryModIntBase(*this)\
    \ *= p;\n  }\n\n  ArbitraryModIntBase operator/(const ArbitraryModIntBase &p)\
    \ const {\n    return ArbitraryModIntBase(*this) /= p;\n  }\n\n  bool operator==(const\
    \ ArbitraryModIntBase &p) const { return x == p.x; }\n\n  bool operator!=(const\
    \ ArbitraryModIntBase &p) const { return x != p.x; }\n\n  ArbitraryModIntBase\
    \ inverse() const {\n    int a = x, b = get_mod(), u = 1, v = 0, t;\n    while\
    \ (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t *\
    \ v, v);\n    }\n    return ArbitraryModIntBase(u);\n  }\n\n  ArbitraryModIntBase\
    \ pow(int64_t n) const {\n    ArbitraryModIntBase ret(1), mul(x);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const\
    \ ArbitraryModIntBase &p) {\n    return os << p.x;\n  }\n\n  friend istream &operator>>(istream\
    \ &is, ArbitraryModIntBase &a) {\n    int64_t t;\n    is >> t;\n    a = ArbitraryModIntBase(t);\n\
    \    return (is);\n  }\n\n  int get() const { return x; }\n\n  inline unsigned\
    \ int rem(unsigned long long p) { return barrett().rem(p); }\n\n  static inline\
    \ Barrett &barrett() {\n    static Barrett b;\n    return b;\n  }\n\n  static\
    \ inline int &get_mod() {\n    static int mod = 0;\n    return mod;\n  }\n\n \
    \ static void set_mod(int md) {\n    assert(0 < md && md <= (1LL << 30) - 1);\n\
    \    get_mod() = md;\n    barrett() = Barrett(md);\n  }\n};\n\nusing ArbitraryModInt\
    \ = ArbitraryModIntBase<-1>;\n\n/**\n * @brief modint (2^{30} \u672A\u6E80\u306E\
    \u4EFB\u610F mod \u7528)\n */\n"
  dependsOn:
  - modint/barrett-reduction.hpp
  isVerificationFile: false
  path: modint/arbitrary-modint.hpp
  requiredBy:
  - ntt/multivariate-circular-convolution.hpp
  timestamp: '2023-05-29 20:16:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp
  - verify/verify-unit-test/arbitrary-modint.test.cpp
  - verify/verify-unit-test/garner-bigint.test.cpp
  - verify/verify-unit-test/barrett-reduction.test.cpp
  - verify/verify-yosupo-math/yosupo-binomial-coefficient-prime-mod.test.cpp
documentation_of: modint/arbitrary-modint.hpp
layout: document
redirect_from:
- /library/modint/arbitrary-modint.hpp
- /library/modint/arbitrary-modint.hpp.html
title: "modint (2^{30} \u672A\u6E80\u306E\u4EFB\u610F mod \u7528)"
---

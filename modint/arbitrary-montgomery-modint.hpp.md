---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps-sqrt.hpp
    title: "\u5E73\u65B9\u6839"
  - icon: ':heavy_check_mark:'
    path: math/primitive-root-ll.hpp
    title: math/primitive-root-ll.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/mod-kth-root.hpp
    title: kth root(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: modulo/mod-sqrt.hpp
    title: mod sqrt(Tonelli-Shanks algorithm)
  - icon: ':warning:'
    path: modulo/quadratic-equation.hpp
    title: modulo/quadratic-equation.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/multivariate-circular-convolution.hpp
    title: "\u591A\u5909\u6570\u5DE1\u56DE\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  - icon: ':heavy_check_mark:'
    path: prime/miller-rabin.hpp
    title: Miller-Rabin primality test
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/arbitrary-modint.test.cpp
    title: verify/verify-unit-test/arbitrary-modint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/factorize.test.cpp
    title: verify/verify-unit-test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/garner-bigint.test.cpp
    title: verify/verify-unit-test/garner-bigint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/primality-test.test.cpp
    title: verify/verify-unit-test/primality-test.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/primitive-root.test.cpp
    title: verify/verify-unit-test/primitive-root.test.cpp
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
    path: verify/verify-yosupo-math/yosupo-primality-test-u64.test.cpp
    title: verify/verify-yosupo-math/yosupo-primality-test-u64.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-primality-test.test.cpp
    title: verify/verify-yosupo-math/yosupo-primality-test.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-primitive-root.test.cpp
    title: verify/verify-yosupo-math/yosupo-primitive-root.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0002.test.cpp
    title: verify/verify-yuki/yuki-0002.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0103.test.cpp
    title: verify/verify-yuki/yuki-0103.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/arbitrary-montgomery-modint.hpp\"\n\n#include <iostream>\n\
    using namespace std;\n\ntemplate <typename Int, typename UInt, typename Long,\
    \ typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase {\n  using\
    \ mint = ArbitraryLazyMontgomeryModIntBase;\n\n  inline static UInt mod;\n  inline\
    \ static UInt r;\n  inline static UInt n2;\n  static constexpr int bit_length\
    \ = sizeof(UInt) * 8;\n\n  static UInt get_r() {\n    UInt ret = mod;\n    while\
    \ (mod * ret != 1) ret *= UInt(2) - mod * ret;\n    return ret;\n  }\n  static\
    \ void set_mod(UInt m) {\n    assert(m < (UInt(1u) << (bit_length - 2)));\n  \
    \  assert((m & 1) == 1);\n    mod = m, n2 = -ULong(m) % m, r = get_r();\n  }\n\
    \  UInt a;\n\n  ArbitraryLazyMontgomeryModIntBase() : a(0) {}\n  ArbitraryLazyMontgomeryModIntBase(const\
    \ Long &b)\n      : a(reduce(ULong(b % mod + mod) * n2)){};\n\n  static UInt reduce(const\
    \ ULong &b) {\n    return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \  }\n\n  mint &operator+=(const mint &b) {\n    if (Int(a += b.a - 2 * mod) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n  mint &operator-=(const mint &b)\
    \ {\n    if (Int(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n  mint\
    \ &operator*=(const mint &b) {\n    a = reduce(ULong(a) * b.a);\n    return *this;\n\
    \  }\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return\
    \ *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n \
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n\n  bool operator==(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const\
    \ { return mint(0) - mint(*this); }\n  mint operator+() const { return mint(*this);\
    \ }\n\n  mint pow(ULong n) const {\n    mint ret(1), mul(*this);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n  \
    \  return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    Long t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModIntBase(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const {\n    Int x = get(), y = get_mod(),\
    \ u = 1, v = 0;\n    while (y > 0) {\n      Int t = x / y;\n      swap(x -= t\
    \ * y, y);\n      swap(u -= t * v, v);\n    }\n    return mint{u};\n  }\n\n  UInt\
    \ get() const {\n    UInt ret = reduce(a);\n    return ret >= mod ? ret - mod\
    \ : ret;\n  }\n\n  static UInt get_mod() { return mod; }\n};\n\n// id \u306B\u9069\
    \u5F53\u306A\u4E71\u6570\u3092\u5272\u308A\u5F53\u3066\u3066\u4F7F\u3046\ntemplate\
    \ <int id>\nusing ArbitraryLazyMontgomeryModInt =\n    ArbitraryLazyMontgomeryModIntBase<int,\
    \ unsigned int, long long,\n                                      unsigned long\
    \ long, id>;\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit =\n\
    \    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\n\
    \                                      __uint128_t, id>;\n"
  code: "#pragma once\n\n#include <iostream>\nusing namespace std;\n\ntemplate <typename\
    \ Int, typename UInt, typename Long, typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase\
    \ {\n  using mint = ArbitraryLazyMontgomeryModIntBase;\n\n  inline static UInt\
    \ mod;\n  inline static UInt r;\n  inline static UInt n2;\n  static constexpr\
    \ int bit_length = sizeof(UInt) * 8;\n\n  static UInt get_r() {\n    UInt ret\
    \ = mod;\n    while (mod * ret != 1) ret *= UInt(2) - mod * ret;\n    return ret;\n\
    \  }\n  static void set_mod(UInt m) {\n    assert(m < (UInt(1u) << (bit_length\
    \ - 2)));\n    assert((m & 1) == 1);\n    mod = m, n2 = -ULong(m) % m, r = get_r();\n\
    \  }\n  UInt a;\n\n  ArbitraryLazyMontgomeryModIntBase() : a(0) {}\n  ArbitraryLazyMontgomeryModIntBase(const\
    \ Long &b)\n      : a(reduce(ULong(b % mod + mod) * n2)){};\n\n  static UInt reduce(const\
    \ ULong &b) {\n    return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \  }\n\n  mint &operator+=(const mint &b) {\n    if (Int(a += b.a - 2 * mod) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n  mint &operator-=(const mint &b)\
    \ {\n    if (Int(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n  mint\
    \ &operator*=(const mint &b) {\n    a = reduce(ULong(a) * b.a);\n    return *this;\n\
    \  }\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return\
    \ *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n \
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n\n  bool operator==(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const\
    \ { return mint(0) - mint(*this); }\n  mint operator+() const { return mint(*this);\
    \ }\n\n  mint pow(ULong n) const {\n    mint ret(1), mul(*this);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n  \
    \  return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    Long t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModIntBase(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const {\n    Int x = get(), y = get_mod(),\
    \ u = 1, v = 0;\n    while (y > 0) {\n      Int t = x / y;\n      swap(x -= t\
    \ * y, y);\n      swap(u -= t * v, v);\n    }\n    return mint{u};\n  }\n\n  UInt\
    \ get() const {\n    UInt ret = reduce(a);\n    return ret >= mod ? ret - mod\
    \ : ret;\n  }\n\n  static UInt get_mod() { return mod; }\n};\n\n// id \u306B\u9069\
    \u5F53\u306A\u4E71\u6570\u3092\u5272\u308A\u5F53\u3066\u3066\u4F7F\u3046\ntemplate\
    \ <int id>\nusing ArbitraryLazyMontgomeryModInt =\n    ArbitraryLazyMontgomeryModIntBase<int,\
    \ unsigned int, long long,\n                                      unsigned long\
    \ long, id>;\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit =\n\
    \    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\n\
    \                                      __uint128_t, id>;\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/arbitrary-montgomery-modint.hpp
  requiredBy:
  - prime/miller-rabin.hpp
  - prime/fast-factorize.hpp
  - math/primitive-root-ll.hpp
  - ntt/multivariate-circular-convolution.hpp
  - fps/fps-sqrt.hpp
  - modulo/mod-sqrt.hpp
  - modulo/mod-kth-root.hpp
  - modulo/quadratic-equation.hpp
  timestamp: '2023-05-29 20:16:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - verify/verify-yosupo-math/yosupo-primitive-root.test.cpp
  - verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
  - verify/verify-yosupo-math/yosupo-primality-test.test.cpp
  - verify/verify-yosupo-math/yosupo-primality-test-u64.test.cpp
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp
  - verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
  - verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
  - verify/verify-yuki/yuki-0103.test.cpp
  - verify/verify-yuki/yuki-0002.test.cpp
  - verify/verify-unit-test/factorize.test.cpp
  - verify/verify-unit-test/primitive-root.test.cpp
  - verify/verify-unit-test/primality-test.test.cpp
  - verify/verify-unit-test/garner-bigint.test.cpp
  - verify/verify-unit-test/arbitrary-modint.test.cpp
  - verify/verify-unit-test/osak.test.cpp
documentation_of: modint/arbitrary-montgomery-modint.hpp
layout: document
redirect_from:
- /library/modint/arbitrary-montgomery-modint.hpp
- /library/modint/arbitrary-montgomery-modint.hpp.html
title: modint/arbitrary-montgomery-modint.hpp
---

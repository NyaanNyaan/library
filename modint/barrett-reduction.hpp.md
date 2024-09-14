---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-modint.hpp
    title: "modint (2^{30} \u672A\u6E80\u306E\u4EFB\u610F mod \u7528)"
  - icon: ':heavy_check_mark:'
    path: modulo/arbitrary-mod-binomial.hpp
    title: "\u4EFB\u610Fmod\u4E8C\u9805\u4FC2\u6570"
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
    path: verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp
    title: verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-binomial-coefficient-prime-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-binomial-coefficient-prime-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-binomial-coefficient.test.cpp
    title: verify/verify-yosupo-math/yosupo-binomial-coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-arbitrary-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-arbitrary-mod.test.cpp
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
    links: []
  bundledCode: "#line 2 \"modint/barrett-reduction.hpp\"\n\n#include <utility>\nusing\
    \ namespace std;\n\nstruct Barrett {\n  using u32 = unsigned int;\n  using i64\
    \ = long long;\n  using u64 = unsigned long long;\n  u32 m;\n  u64 im;\n  Barrett()\
    \ : m(), im() {}\n  Barrett(int n) : m(n), im(u64(-1) / m + 1) {}\n  constexpr\
    \ inline i64 quo(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n   \
    \ u32 r = n - x * m;\n    return m <= r ? x - 1 : x;\n  }\n  constexpr inline\
    \ i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n    u32 r =\
    \ n - x * m;\n    return m <= r ? r + m : r;\n  }\n  constexpr inline pair<i64,\
    \ int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n    u32\
    \ r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n    return {x, r};\n\
    \  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32 a = rem(n), r = m ==\
    \ 1 ? 0 : 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r) * a);\n      a\
    \ = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n};\n"
  code: "#pragma once\n\n#include <utility>\nusing namespace std;\n\nstruct Barrett\
    \ {\n  using u32 = unsigned int;\n  using i64 = long long;\n  using u64 = unsigned\
    \ long long;\n  u32 m;\n  u64 im;\n  Barrett() : m(), im() {}\n  Barrett(int n)\
    \ : m(n), im(u64(-1) / m + 1) {}\n  constexpr inline i64 quo(u64 n) {\n    u64\
    \ x = u64((__uint128_t(n) * im) >> 64);\n    u32 r = n - x * m;\n    return m\
    \ <= r ? x - 1 : x;\n  }\n  constexpr inline i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    return m <= r ? r + m : r;\n  }\n\
    \  constexpr inline pair<i64, int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n\
    \    return {x, r};\n  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32\
    \ a = rem(n), r = m == 1 ? 0 : 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r)\
    \ * a);\n      a = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: modint/barrett-reduction.hpp
  requiredBy:
  - ntt/multivariate-circular-convolution.hpp
  - modint/arbitrary-modint.hpp
  - modulo/arbitrary-mod-binomial.hpp
  timestamp: '2022-02-08 14:09:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/garner-bigint.test.cpp
  - verify/verify-unit-test/barrett-reduction.test.cpp
  - verify/verify-unit-test/arbitrary-modint.test.cpp
  - verify/verify-yosupo-math/yosupo-binomial-coefficient.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant-arbitrary-mod.test.cpp
  - verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp
  - verify/verify-yosupo-math/yosupo-binomial-coefficient-prime-mod.test.cpp
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp
  - verify/verify-yosupo-ntt/yosupo-multivariate-circular-convolution.test.cpp
documentation_of: modint/barrett-reduction.hpp
layout: document
redirect_from:
- /library/modint/barrett-reduction.hpp
- /library/modint/barrett-reduction.hpp.html
title: modint/barrett-reduction.hpp
---

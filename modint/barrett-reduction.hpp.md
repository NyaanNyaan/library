---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: modulo/arbitrary-mod-binomial-large.hpp
    title: modulo/arbitrary-mod-binomial-large.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/arbitrary-mod-binomial.hpp
    title: "\u4EFB\u610Fmod\u4E8C\u9805\u4FC2\u6570"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp
    title: verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-binomial-coefficient.test.cpp
    title: verify/verify-yosupo-math/yosupo-binomial-coefficient.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/barrett-reduction.hpp\"\n\n#include <cassert>\n#include\
    \ <utility>\nusing namespace std;\n\nstruct Barrett {\n  using u32 = unsigned\
    \ int;\n  using i64 = long long;\n  using u64 = unsigned long long;\n  u32 m;\n\
    \  u64 im;\n  Barrett() : m(), im() {}\n  Barrett(int n) : m(n), im(u64(-1) /\
    \ m + 1) { assert(1 < n); }\n  constexpr inline i64 quo(u64 n) {\n    u64 x =\
    \ u64((__uint128_t(n) * im) >> 64);\n    u32 r = n - x * m;\n    return m <= r\
    \ ? x - 1 : x;\n  }\n  constexpr inline i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    return m <= r ? r + m : r;\n  }\n\
    \  constexpr inline pair<i64, int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n)\
    \ * im) >> 64);\n    u32 r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n\
    \    return {x, r};\n  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32\
    \ a = rem(n), r = 1;\n    while (p) {\n      if (p & 1) r = rem(u64(r) * a);\n\
    \      a = rem(u64(a) * a);\n      p >>= 1;\n    }\n    return r;\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\nusing namespace std;\n\
    \nstruct Barrett {\n  using u32 = unsigned int;\n  using i64 = long long;\n  using\
    \ u64 = unsigned long long;\n  u32 m;\n  u64 im;\n  Barrett() : m(), im() {}\n\
    \  Barrett(int n) : m(n), im(u64(-1) / m + 1) { assert(1 < n); }\n  constexpr\
    \ inline i64 quo(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n   \
    \ u32 r = n - x * m;\n    return m <= r ? x - 1 : x;\n  }\n  constexpr inline\
    \ i64 rem(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n    u32 r =\
    \ n - x * m;\n    return m <= r ? r + m : r;\n  }\n  constexpr inline pair<i64,\
    \ int> quorem(u64 n) {\n    u64 x = u64((__uint128_t(n) * im) >> 64);\n    u32\
    \ r = n - x * m;\n    if (m <= r) return {x - 1, r + m};\n    return {x, r};\n\
    \  }\n  constexpr inline i64 pow(u64 n, i64 p) {\n    u32 a = rem(n), r = 1;\n\
    \    while (p) {\n      if (p & 1) r = rem(u64(r) * a);\n      a = rem(u64(a)\
    \ * a);\n      p >>= 1;\n    }\n    return r;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: modint/barrett-reduction.hpp
  requiredBy:
  - modulo/arbitrary-mod-binomial-large.hpp
  - modulo/arbitrary-mod-binomial.hpp
  timestamp: '2021-04-29 14:58:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-binomial-coefficient-large.test.cpp
  - verify/verify-yosupo-math/yosupo-binomial-coefficient.test.cpp
documentation_of: modint/barrett-reduction.hpp
layout: document
redirect_from:
- /library/modint/barrett-reduction.hpp
- /library/modint/barrett-reduction.hpp.html
title: modint/barrett-reduction.hpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp
    title: verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/kth-root-integral.md
    document_title: $\mathrm{floor}(a^{\frac{1}{k}})$
    links: []
  bundledCode: "#line 2 \"math/kth-root-integral.hpp\"\n\n\n\nuint64_t kth_root_integral(uint64_t\
    \ a, uint64_t k) {\n  if (a <= 1 || k == 1) return a;\n  if (64 <= k) return 1;\n\
    \  auto check = [&](__uint128_t n) {\n    __uint128_t x = 1, m = n;\n    for (int\
    \ p = k; p; p >>= 1, m *= m)\n      if (p & 1) x *= m;\n    return x <= a;\n \
    \ };\n  uint64_t n = powl(a, (long double)(1.0) / k);\n  while (!check(n)) --n;\n\
    \  while (check(n + 1)) ++n;\n  return n;\n}\n\n/**\n * @brief $\\mathrm{floor}(a^{\\\
    frac{1}{k}})$\n * @docs docs/math/kth-root-integral.md\n */\n"
  code: "#pragma once\n\n\n\nuint64_t kth_root_integral(uint64_t a, uint64_t k) {\n\
    \  if (a <= 1 || k == 1) return a;\n  if (64 <= k) return 1;\n  auto check = [&](__uint128_t\
    \ n) {\n    __uint128_t x = 1, m = n;\n    for (int p = k; p; p >>= 1, m *= m)\n\
    \      if (p & 1) x *= m;\n    return x <= a;\n  };\n  uint64_t n = powl(a, (long\
    \ double)(1.0) / k);\n  while (!check(n)) --n;\n  while (check(n + 1)) ++n;\n\
    \  return n;\n}\n\n/**\n * @brief $\\mathrm{floor}(a^{\\frac{1}{k}})$\n * @docs\
    \ docs/math/kth-root-integral.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/kth-root-integral.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp
documentation_of: math/kth-root-integral.hpp
layout: document
redirect_from:
- /library/math/kth-root-integral.hpp
- /library/math/kth-root-integral.hpp.html
title: $\mathrm{floor}(a^{\frac{1}{k}})$
---
## $\mathrm{floor}(a^{\frac{1}{k}})$

#### 概要

整数$a$の$k$乗根(切り捨て)を求めるライブラリ。

$a,k$の値によって`powl`関数が上下両方に誤差を発生しうることに注意して実装する。

#### 使い方

- `kth_root_integral(a, k)`　:　$a$の$k$乗根を求める。

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: fps/famous-series.hpp
    title: fps/famous-series.hpp
  - icon: ':heavy_check_mark:'
    path: fps/utility.hpp
    title: fps/utility.hpp
  - icon: ':heavy_check_mark:'
    path: fps/taylor-shift.hpp
    title: "\u5E73\u884C\u79FB\u52D5"
  - icon: ':heavy_check_mark:'
    path: fps/fps-composition.hpp
    title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}\\left((N \\log N)^{\\frac{3}{2}}\\\
      right)$ )"
  - icon: ':heavy_check_mark:'
    path: fps/sum-of-exponential-times-poly.hpp
    title: $\sum_{i}a^i f(i)$
  - icon: ':heavy_check_mark:'
    path: fps/lagrange-interpolation-point.hpp
    title: fps/lagrange-interpolation-point.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1145.test.cpp
    title: verify/verify-yuki/yuki-1145.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0963-circular.test.cpp
    title: verify/verify-yuki/yuki-0963-circular.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1080.test.cpp
    title: verify/verify-yuki/yuki-1080.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
    title: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-composition.test.cpp
    title: verify/verify-yosupo-fps/yosupo-composition.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"modulo/binomial.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <typename T>\nstruct Binomial {\n  vector<T> fac_, finv_, inv_;\n\
    \  Binomial(int MAX) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {\n   \
    \ MAX += 9;\n    fac_[0] = finv_[0] = inv_[0] = 1;\n    for (int i = 1; i <= MAX;\
    \ i++) fac_[i] = fac_[i - 1] * i;\n    finv_[MAX] = fac_[MAX].inverse();\n   \
    \ for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);\n    for\
    \ (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];\n  }\n\n  inline\
    \ T fac(int i) const { return fac_[i]; }\n  inline T finv(int i) const { return\
    \ finv_[i]; }\n  inline T inv(int i) const { return inv_[i]; }\n\n  T C(int n,\
    \ int r) const {\n    if (n < r || r < 0) return T(0);\n    return fac_[n] * finv_[n\
    \ - r] * finv_[r];\n  }\n\n  T C_naive(int n, int r) const {\n    if (n < r ||\
    \ r < 0) return T(0);\n    T ret = 1;\n    for (T i = 1; i <= r; i += T(1)) {\n\
    \      ret *= n--;\n      ret *= i.inverse();\n    }\n    return ret;\n  }\n\n\
    \  T P(int n, int r) const {\n    if (n < r || r < 0) return T(0);\n    return\
    \ fac_[n] * finv_[n - r];\n  }\n\n  T H(int n, int r) const {\n    if (n < 0 ||\
    \ r < 0) return (0);\n    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T>\nstruct Binomial {\n  vector<T> fac_, finv_, inv_;\n  Binomial(int\
    \ MAX) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {\n    MAX += 9;\n  \
    \  fac_[0] = finv_[0] = inv_[0] = 1;\n    for (int i = 1; i <= MAX; i++) fac_[i]\
    \ = fac_[i - 1] * i;\n    finv_[MAX] = fac_[MAX].inverse();\n    for (int i =\
    \ MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);\n    for (int i = 1;\
    \ i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];\n  }\n\n  inline T fac(int\
    \ i) const { return fac_[i]; }\n  inline T finv(int i) const { return finv_[i];\
    \ }\n  inline T inv(int i) const { return inv_[i]; }\n\n  T C(int n, int r) const\
    \ {\n    if (n < r || r < 0) return T(0);\n    return fac_[n] * finv_[n - r] *\
    \ finv_[r];\n  }\n\n  T C_naive(int n, int r) const {\n    if (n < r || r < 0)\
    \ return T(0);\n    T ret = 1;\n    for (T i = 1; i <= r; i += T(1)) {\n     \
    \ ret *= n--;\n      ret *= i.inverse();\n    }\n    return ret;\n  }\n\n  T P(int\
    \ n, int r) const {\n    if (n < r || r < 0) return T(0);\n    return fac_[n]\
    \ * finv_[n - r];\n  }\n\n  T H(int n, int r) const {\n    if (n < 0 || r < 0)\
    \ return (0);\n    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: modulo/binomial.hpp
  requiredBy:
  - fps/famous-series.hpp
  - fps/utility.hpp
  - fps/taylor-shift.hpp
  - fps/fps-composition.hpp
  - fps/sum-of-exponential-times-poly.hpp
  - fps/lagrange-interpolation-point.hpp
  timestamp: '2020-07-31 19:33:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1145.test.cpp
  - verify/verify-yuki/yuki-0963-circular.test.cpp
  - verify/verify-yuki/yuki-1080.test.cpp
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  - verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - verify/verify-yosupo-fps/yosupo-composition.test.cpp
documentation_of: modulo/binomial.hpp
layout: document
redirect_from:
- /library/modulo/binomial.hpp
- /library/modulo/binomial.hpp.html
title: modulo/binomial.hpp
---

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps-composition.hpp
    title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}\\left((N \\log N)^{\\frac{3}{2}}\\\
      right)$ )"
  - icon: ':heavy_check_mark:'
    path: fps/fps-famous-series.hpp
    title: "\u6709\u540D\u306A\u6570\u5217"
  - icon: ':heavy_check_mark:'
    path: fps/lagrange-interpolation-point.hpp
    title: fps/lagrange-interpolation-point.hpp
  - icon: ':heavy_check_mark:'
    path: fps/sum-of-exponential-times-poly.hpp
    title: $\sum_{i}a^i f(i)$
  - icon: ':heavy_check_mark:'
    path: fps/taylor-shift.hpp
    title: "\u5E73\u884C\u79FB\u52D5"
  - icon: ':heavy_check_mark:'
    path: fps/utility.hpp
    title: fps/utility.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-composition.test.cpp
    title: verify/verify-yosupo-fps/yosupo-composition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
    title: verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
    title: verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
    title: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0117.test.cpp
    title: verify/verify-yuki/yuki-0117.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0125.test.cpp
    title: verify/verify-yuki/yuki-0125.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0720.test.cpp
    title: verify/verify-yuki/yuki-0720.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0890.test.cpp
    title: verify/verify-yuki/yuki-0890.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0963-circular.test.cpp
    title: verify/verify-yuki/yuki-0963-circular.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1080.test.cpp
    title: verify/verify-yuki/yuki-1080.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1112-sparse.test.cpp
    title: verify/verify-yuki/yuki-1112-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1112.test.cpp
    title: verify/verify-yuki/yuki-1112.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1145.test.cpp
    title: verify/verify-yuki/yuki-1145.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1303.test.cpp
    title: verify/verify-yuki/yuki-1303.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulo/binomial.hpp\"\n\n\n\ntemplate <typename T>\nstruct\
    \ Binomial {\n  vector<T> fac_, finv_, inv_;\n  Binomial(int MAX = 0) : fac_(MAX\
    \ + 10), finv_(MAX + 10), inv_(MAX + 10) {\n    assert(T::get_mod() != 0);\n \
    \   MAX += 9;\n    fac_[0] = finv_[0] = inv_[0] = 1;\n    for (int i = 1; i <=\
    \ MAX; i++) fac_[i] = fac_[i - 1] * i;\n    finv_[MAX] = fac_[MAX].inverse();\n\
    \    for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);\n  \
    \  for (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];\n  }\n\n \
    \ void extend() {\n    int n = fac_.size();\n    T fac = fac_.back() * n;\n  \
    \  T inv = (-inv_[T::get_mod() % n]) * (T::get_mod() / n);\n    T finv = finv_.back()\
    \ * inv;\n    fac_.push_back(fac);\n    finv_.push_back(finv);\n    inv_.push_back(inv);\n\
    \  }\n\n  T fac(int i) {\n    while (i >= (int)fac_.size()) extend();\n    return\
    \ fac_[i];\n  }\n\n  T finv(int i) {\n    while (i >= (int)finv_.size()) extend();\n\
    \    return finv_[i];\n  }\n\n  T inv(int i) {\n    while (i >= (int)inv_.size())\
    \ extend();\n    return inv_[i];\n  }\n\n  T C(int n, int r) {\n    if (n < r\
    \ || r < 0) return T(0);\n    return fac(n) * finv(n - r) * finv(r);\n  }\n\n\
    \  T C_naive(int n, int r) {\n    if (n < r || r < 0) return T(0);\n    T ret\
    \ = T(1);\n    r = min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i)\
    \ * (n--);\n    return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < r || r\
    \ < 0) return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  T H(int n, int\
    \ r) {\n    if (n < 0 || r < 0) return T(0);\n    return r == 0 ? 1 : C(n + r\
    \ - 1, r);\n  }\n};\n"
  code: "#pragma once\n\n\n\ntemplate <typename T>\nstruct Binomial {\n  vector<T>\
    \ fac_, finv_, inv_;\n  Binomial(int MAX = 0) : fac_(MAX + 10), finv_(MAX + 10),\
    \ inv_(MAX + 10) {\n    assert(T::get_mod() != 0);\n    MAX += 9;\n    fac_[0]\
    \ = finv_[0] = inv_[0] = 1;\n    for (int i = 1; i <= MAX; i++) fac_[i] = fac_[i\
    \ - 1] * i;\n    finv_[MAX] = fac_[MAX].inverse();\n    for (int i = MAX - 1;\
    \ i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);\n    for (int i = 1; i <= MAX;\
    \ i++) inv_[i] = finv_[i] * fac_[i - 1];\n  }\n\n  void extend() {\n    int n\
    \ = fac_.size();\n    T fac = fac_.back() * n;\n    T inv = (-inv_[T::get_mod()\
    \ % n]) * (T::get_mod() / n);\n    T finv = finv_.back() * inv;\n    fac_.push_back(fac);\n\
    \    finv_.push_back(finv);\n    inv_.push_back(inv);\n  }\n\n  T fac(int i) {\n\
    \    while (i >= (int)fac_.size()) extend();\n    return fac_[i];\n  }\n\n  T\
    \ finv(int i) {\n    while (i >= (int)finv_.size()) extend();\n    return finv_[i];\n\
    \  }\n\n  T inv(int i) {\n    while (i >= (int)inv_.size()) extend();\n    return\
    \ inv_[i];\n  }\n\n  T C(int n, int r) {\n    if (n < r || r < 0) return T(0);\n\
    \    return fac(n) * finv(n - r) * finv(r);\n  }\n\n  T C_naive(int n, int r)\
    \ {\n    if (n < r || r < 0) return T(0);\n    T ret = T(1);\n    r = min(r, n\
    \ - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n    return ret;\n\
    \  }\n\n  T P(int n, int r) {\n    if (n < r || r < 0) return T(0);\n    return\
    \ fac(n) * finv(n - r);\n  }\n\n  T H(int n, int r) {\n    if (n < 0 || r < 0)\
    \ return T(0);\n    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: modulo/binomial.hpp
  requiredBy:
  - fps/fps-composition.hpp
  - fps/lagrange-interpolation-point.hpp
  - fps/sum-of-exponential-times-poly.hpp
  - fps/fps-famous-series.hpp
  - fps/utility.hpp
  - fps/taylor-shift.hpp
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  - verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
  - verify/verify-yosupo-fps/yosupo-composition.test.cpp
  - verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
  - verify/verify-yuki/yuki-1112-sparse.test.cpp
  - verify/verify-yuki/yuki-0720.test.cpp
  - verify/verify-yuki/yuki-1303.test.cpp
  - verify/verify-yuki/yuki-0125.test.cpp
  - verify/verify-yuki/yuki-0963-circular.test.cpp
  - verify/verify-yuki/yuki-0890.test.cpp
  - verify/verify-yuki/yuki-1112.test.cpp
  - verify/verify-yuki/yuki-1080.test.cpp
  - verify/verify-yuki/yuki-0117.test.cpp
  - verify/verify-yuki/yuki-1145.test.cpp
documentation_of: modulo/binomial.hpp
layout: document
redirect_from:
- /library/modulo/binomial.hpp
- /library/modulo/binomial.hpp.html
title: modulo/binomial.hpp
---

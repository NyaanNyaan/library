---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/lagrange-interpolation-point.hpp\"\n\n#line 2 \"modulo/binomial.hpp\"\
    \n\ntemplate <typename T>\nstruct Binomial {\n  vector<T> fac_, finv_, inv_;\n\
    \  Binomial(int MAX = 0) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {\n\
    \    assert(T::get_mod() != 0);\n    MAX += 9;\n    fac_[0] = finv_[0] = inv_[0]\
    \ = 1;\n    for (int i = 1; i <= MAX; i++) fac_[i] = fac_[i - 1] * i;\n    finv_[MAX]\
    \ = fac_[MAX].inverse();\n    for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i\
    \ + 1] * (i + 1);\n    for (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i\
    \ - 1];\n  }\n\n  void extend() {\n    int n = fac_.size();\n    T fac = fac_.back()\
    \ * n;\n    T inv = (-inv_[T::get_mod() % n]) * (T::get_mod() / n);\n    T finv\
    \ = finv_.back() * inv;\n    fac_.push_back(fac);\n    finv_.push_back(finv);\n\
    \    inv_.push_back(inv);\n  }\n\n  T fac(int i) {\n    if(i < 0) return T(0);\n\
    \    while (i >= (int)fac_.size()) extend();\n    return fac_[i];\n  }\n\n  T\
    \ finv(int i) {\n    if(i < 0) return T(0);\n    while (i >= (int)finv_.size())\
    \ extend();\n    return finv_[i];\n  }\n\n  T inv(int i) {\n    if(i < 0) return\
    \ T(0);\n    while (i >= (int)inv_.size()) extend();\n    return inv_[i];\n  }\n\
    \n  T C(int n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    return\
    \ fac(n) * finv(n - r) * finv(r);\n  }\n\n  T C_naive(int n, int r) {\n    if\
    \ (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n    r = min(r, n\
    \ - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n    return ret;\n\
    \  }\n\n  T P(int n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n\
    \    return fac(n) * finv(n - r);\n  }\n\n  T H(int n, int r) {\n    if (n < 0\
    \ || r < 0) return T(0);\n    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n\
    #line 4 \"fps/lagrange-interpolation-point.hpp\"\n\n// given  : y(x=0) , y(x=1)\
    \ , ... , y(k)\n// return : y(x)\ntemplate <typename mint>\nmint lagrange_interpolation(const\
    \ vector<mint>& y, long long x,\n                            Binomial<mint>& C)\
    \ {\n  int N = (int)y.size() - 1;\n  if (x <= N) return y[x];\n  mint ret = 0;\n\
    \  vector<mint> dp(N + 1, 1), pd(N + 1, 1);\n  mint a = x, one = 1;\n  for (int\
    \ i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;\n  for (int i = N; i > 0;\
    \ i--) pd[i - 1] = pd[i] * a, a += one;\n  for (int i = 0; i <= N; i++) {\n  \
    \  mint tmp = y[i] * dp[i] * pd[i] * C.finv(i) * C.finv(N - i);\n    ret += ((N\
    \ - i) & 1) ? -tmp : tmp;\n  }\n  return ret;\n}\n"
  code: "#pragma once\n\n#include \"../modulo/binomial.hpp\"\n\n// given  : y(x=0)\
    \ , y(x=1) , ... , y(k)\n// return : y(x)\ntemplate <typename mint>\nmint lagrange_interpolation(const\
    \ vector<mint>& y, long long x,\n                            Binomial<mint>& C)\
    \ {\n  int N = (int)y.size() - 1;\n  if (x <= N) return y[x];\n  mint ret = 0;\n\
    \  vector<mint> dp(N + 1, 1), pd(N + 1, 1);\n  mint a = x, one = 1;\n  for (int\
    \ i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;\n  for (int i = N; i > 0;\
    \ i--) pd[i - 1] = pd[i] * a, a += one;\n  for (int i = 0; i <= N; i++) {\n  \
    \  mint tmp = y[i] * dp[i] * pd[i] * C.finv(i) * C.finv(N - i);\n    ret += ((N\
    \ - i) & 1) ? -tmp : tmp;\n  }\n  return ret;\n}"
  dependsOn:
  - modulo/binomial.hpp
  isVerificationFile: false
  path: fps/lagrange-interpolation-point.hpp
  requiredBy: []
  timestamp: '2021-02-01 19:31:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
documentation_of: fps/lagrange-interpolation-point.hpp
layout: document
redirect_from:
- /library/fps/lagrange-interpolation-point.hpp
- /library/fps/lagrange-interpolation-point.hpp.html
title: fps/lagrange-interpolation-point.hpp
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"fps/lagrange-interpolation-point.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"modulo/binomial.hpp\"\nusing namespace std;\n\
    \ntemplate <typename T>\nstruct Binomial {\n  vector<T> fac_, finv_, inv_;\n \
    \ Binomial(int MAX) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {\n    MAX\
    \ += 9;\n    fac_[0] = finv_[0] = inv_[0] = 1;\n    for (int i = 1; i <= MAX;\
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
    \ r < 0) return (0);\n    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line\
    \ 6 \"fps/lagrange-interpolation-point.hpp\"\n\n// given  : y(x=0) , y(x=1) ,\
    \ ... , y(k)\n// return : y(x)\ntemplate <typename mint>\nmint lagrange_interpolation(const\
    \ vector<mint>& y, long long x,\n                            const Binomial<mint>&\
    \ C) {\n  int N = (int)y.size() - 1;\n  if (x <= N) return y[x];\n  mint ret =\
    \ 0;\n  vector<mint> dp(N + 1, 1), pd(N + 1, 1);\n  mint a = x, one = 1;\n  for\
    \ (int i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;\n  for (int i = N;\
    \ i > 0; i--) pd[i - 1] = pd[i] * a, a += one;\n  for (int i = 0; i <= N; i++)\
    \ {\n    mint tmp = y[i] * dp[i] * pd[i] * C.finv(i) * C.finv(N - i);\n    ret\
    \ += ((N - i) & 1) ? -tmp : tmp;\n  }\n  return ret;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../modulo/binomial.hpp\"\n\n// given  : y(x=0) , y(x=1) , ... , y(k)\n// return\
    \ : y(x)\ntemplate <typename mint>\nmint lagrange_interpolation(const vector<mint>&\
    \ y, long long x,\n                            const Binomial<mint>& C) {\n  int\
    \ N = (int)y.size() - 1;\n  if (x <= N) return y[x];\n  mint ret = 0;\n  vector<mint>\
    \ dp(N + 1, 1), pd(N + 1, 1);\n  mint a = x, one = 1;\n  for (int i = 0; i < N;\
    \ i++) dp[i + 1] = dp[i] * a, a -= one;\n  for (int i = N; i > 0; i--) pd[i -\
    \ 1] = pd[i] * a, a += one;\n  for (int i = 0; i <= N; i++) {\n    mint tmp =\
    \ y[i] * dp[i] * pd[i] * C.finv(i) * C.finv(N - i);\n    ret += ((N - i) & 1)\
    \ ? -tmp : tmp;\n  }\n  return ret;\n}"
  dependsOn:
  - modulo/binomial.hpp
  isVerificationFile: false
  path: fps/lagrange-interpolation-point.hpp
  requiredBy: []
  timestamp: '2020-08-31 22:48:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  - verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
documentation_of: fps/lagrange-interpolation-point.hpp
layout: document
redirect_from:
- /library/fps/lagrange-interpolation-point.hpp
- /library/fps/lagrange-interpolation-point.hpp.html
title: fps/lagrange-interpolation-point.hpp
---

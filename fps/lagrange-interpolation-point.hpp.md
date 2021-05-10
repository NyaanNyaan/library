---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/lagrange-interpolation-point.hpp\"\n\n#line 2 \"modulo/binomial.hpp\"\
    \n\ntemplate <typename T>\nstruct Binomial {\n  vector<T> f, g, h;\n  Binomial(int\
    \ MAX = 0) : f(1, T(1)), g(1, T(1)), h(1, T(1)) {\n    while (MAX >= (int)f.size())\
    \ extend();\n  }\n\n  void extend() {\n    int n = f.size();\n    int m = n *\
    \ 2;\n    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n    for (int i = n;\
    \ i < m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m - 1].inverse();\n  \
    \  h[m - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2; i >= n; i--) {\n \
    \     g[i] = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i - 1];\n    }\n  }\n\
    \n  T fac(int i) {\n    if (i < 0) return T(0);\n    while (i >= (int)f.size())\
    \ extend();\n    return f[i];\n  }\n\n  T finv(int i) {\n    if (i < 0) return\
    \ T(0);\n    while (i >= (int)g.size()) extend();\n    return g[i];\n  }\n\n \
    \ T inv(int i) {\n    if (i < 0) return -inv(-i);\n    while (i >= (int)h.size())\
    \ extend();\n    return h[i];\n  }\n\n  T C(int n, int r) {\n    if (n < 0 ||\
    \ n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r) * finv(r);\n \
    \ }\n\n  inline T operator()(int n, int r) { return C(n, r); }\n\n  T C_naive(int\
    \ n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n\
    \    r = min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n\
    \    return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n < r || r <\
    \ 0) return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  T H(int n, int r)\
    \ {\n    if (n < 0 || r < 0) return T(0);\n    return r == 0 ? 1 : C(n + r - 1,\
    \ r);\n  }\n};\n#line 4 \"fps/lagrange-interpolation-point.hpp\"\n\n// given \
    \ : y(x=0) , y(x=1) , ... , y(k)\n// return : y(x)\ntemplate <typename mint>\n\
    mint lagrange_interpolation(const vector<mint>& y, long long x,\n            \
    \                Binomial<mint>& C) {\n  int N = (int)y.size() - 1;\n  if (x <=\
    \ N) return y[x];\n  mint ret = 0;\n  vector<mint> dp(N + 1, 1), pd(N + 1, 1);\n\
    \  mint a = x, one = 1;\n  for (int i = 0; i < N; i++) dp[i + 1] = dp[i] * a,\
    \ a -= one;\n  for (int i = N; i > 0; i--) pd[i - 1] = pd[i] * a, a += one;\n\
    \  for (int i = 0; i <= N; i++) {\n    mint tmp = y[i] * dp[i] * pd[i] * C.finv(i)\
    \ * C.finv(N - i);\n    ret += ((N - i) & 1) ? -tmp : tmp;\n  }\n  return ret;\n\
    }\n"
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
  timestamp: '2021-05-10 21:37:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
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

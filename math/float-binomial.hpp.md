---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1220.test.cpp
    title: verify/verify-yuki/yuki-1220.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/float-binomial.hpp\"\n\n\n\nstruct FloatBinomial {\n\
    \  vector<long double> f;\n  static constexpr long double LOGZERO = -1e10;\n\n\
    \  FloatBinomial(int MAX) {\n    f.resize(MAX + 1, 0.0);\n    f[0] = 0.0;\n  \
    \  for (int i = 1; i <= MAX; i++) {\n      f[i] = f[i - 1] + logl(i);\n    }\n\
    \  }\n\n  long double logfac(int n) const { return f[n]; }\n\n  long double logfinv(int\
    \ n) const { return -f[n]; }\n\n  long double logC(int n, int k) const {\n   \
    \ if (n < k || k < 0 || n < 0) return LOGZERO;\n    return f[n] - f[n - k] - f[k];\n\
    \  }\n\n  long double logP(int n, int k) const {\n    if (n < k || k < 0 || n\
    \ < 0) return LOGZERO;\n    return f[n] - f[n - k];\n  }\n};\n"
  code: "#pragma once\n\n\n\nstruct FloatBinomial {\n  vector<long double> f;\n  static\
    \ constexpr long double LOGZERO = -1e10;\n\n  FloatBinomial(int MAX) {\n    f.resize(MAX\
    \ + 1, 0.0);\n    f[0] = 0.0;\n    for (int i = 1; i <= MAX; i++) {\n      f[i]\
    \ = f[i - 1] + logl(i);\n    }\n  }\n\n  long double logfac(int n) const { return\
    \ f[n]; }\n\n  long double logfinv(int n) const { return -f[n]; }\n\n  long double\
    \ logC(int n, int k) const {\n    if (n < k || k < 0 || n < 0) return LOGZERO;\n\
    \    return f[n] - f[n - k] - f[k];\n  }\n\n  long double logP(int n, int k) const\
    \ {\n    if (n < k || k < 0 || n < 0) return LOGZERO;\n    return f[n] - f[n -\
    \ k];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/float-binomial.hpp
  requiredBy: []
  timestamp: '2021-05-10 21:26:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1220.test.cpp
documentation_of: math/float-binomial.hpp
layout: document
redirect_from:
- /library/math/float-binomial.hpp
- /library/math/float-binomial.hpp.html
title: math/float-binomial.hpp
---

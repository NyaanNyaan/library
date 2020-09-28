---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1220.test.cpp
    title: verify/verify-yuki/yuki-1220.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/float-binomial.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct FloatBinomial {\n  vector<long double> fac_;\n  static\
    \ constexpr long double LOGZERO = -1e10;\n\n  FloatBinomial(int MAX) {\n    fac_.resize(MAX\
    \ + 1, 0.0);\n    fac_[0] = 0.0;\n    for (int i = 1; i <= MAX; i++) {\n     \
    \ fac_[i] = fac_[i - 1] + logl(i);\n    }\n  }\n\n  long double logfac(int n)\
    \ const { return fac_[n]; }\n\n  long double logfinv(int n) const { return -fac_[n];\
    \ }\n\n  long double logC(int n, int k) const {\n    if (n < k || k < 0 || n <\
    \ 0) return LOGZERO;\n    return fac_[n] - fac_[n - k] - fac_[k];\n  }\n\n  long\
    \ double logP(int n, int k) const {\n    if (n < k || k < 0 || n < 0) return LOGZERO;\n\
    \    return fac_[n] - fac_[n - k];\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct FloatBinomial\
    \ {\n  vector<long double> fac_;\n  static constexpr long double LOGZERO = -1e10;\n\
    \n  FloatBinomial(int MAX) {\n    fac_.resize(MAX + 1, 0.0);\n    fac_[0] = 0.0;\n\
    \    for (int i = 1; i <= MAX; i++) {\n      fac_[i] = fac_[i - 1] + logl(i);\n\
    \    }\n  }\n\n  long double logfac(int n) const { return fac_[n]; }\n\n  long\
    \ double logfinv(int n) const { return -fac_[n]; }\n\n  long double logC(int n,\
    \ int k) const {\n    if (n < k || k < 0 || n < 0) return LOGZERO;\n    return\
    \ fac_[n] - fac_[n - k] - fac_[k];\n  }\n\n  long double logP(int n, int k) const\
    \ {\n    if (n < k || k < 0 || n < 0) return LOGZERO;\n    return fac_[n] - fac_[n\
    \ - k];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/float-binomial.hpp
  requiredBy: []
  timestamp: '2020-09-04 23:57:13+09:00'
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

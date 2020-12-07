---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: marathon/simulated-annealing.hpp
    title: Simulated Annealing
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-unit-test/simulated-annealing.test.cpp
    title: verify/verify-unit-test/simulated-annealing.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"marathon/log_table.hpp\"\n\nstruct log_table {\n  double\
    \ l[65536];\n  constexpr log_table() : l() {\n    unsigned long long x = 88172645463325252ULL;\n\
    \    double log_u64max = log(2) * 64;\n    for (int i = 0; i < 65536; i++) {\n\
    \      x = x ^ (x << 7);\n      x = x ^ (x >> 9);\n      l[i] = log(double(x))\
    \ - log_u64max;\n    }\n  }\n};\n"
  code: "#pragma once\n\nstruct log_table {\n  double l[65536];\n  constexpr log_table()\
    \ : l() {\n    unsigned long long x = 88172645463325252ULL;\n    double log_u64max\
    \ = log(2) * 64;\n    for (int i = 0; i < 65536; i++) {\n      x = x ^ (x << 7);\n\
    \      x = x ^ (x >> 9);\n      l[i] = log(double(x)) - log_u64max;\n    }\n \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/log_table.hpp
  requiredBy:
  - marathon/simulated-annealing.hpp
  timestamp: '2020-12-08 00:23:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-unit-test/simulated-annealing.test.cpp
documentation_of: marathon/log_table.hpp
layout: document
redirect_from:
- /library/marathon/log_table.hpp
- /library/marathon/log_table.hpp.html
title: marathon/log_table.hpp
---

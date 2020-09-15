---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: misc/simulated-annealing.hpp
    title: misc/simulated-annealing.hpp
  - icon: ':heavy_check_mark:'
    path: math/prime-factor.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-factrization.test.cpp
    title: verify/verify-yosupo-math/yosupo-factrization.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"misc/rng.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nunsigned long long rng() {\n  static unsigned long long x_ = 88172645463325252ULL;\n\
    \  x_ = x_ ^ (x_ << 7);\n  return x_ = x_ ^ (x_ >> 9);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nunsigned\
    \ long long rng() {\n  static unsigned long long x_ = 88172645463325252ULL;\n\
    \  x_ = x_ ^ (x_ << 7);\n  return x_ = x_ ^ (x_ >> 9);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/rng.hpp
  requiredBy:
  - misc/simulated-annealing.hpp
  - math/prime-factor.hpp
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-factrization.test.cpp
documentation_of: misc/rng.hpp
layout: document
redirect_from:
- /library/misc/rng.hpp
- /library/misc/rng.hpp.html
title: misc/rng.hpp
---

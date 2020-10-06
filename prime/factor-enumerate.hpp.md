---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: prime/osak.hpp
    title: prime/osak.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"prime/factor-enumerate.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nvector<int> factor_enumerate(int N) {\n  vector<int> lp(N\
    \ + 1, 0);\n  if (N < 2) return lp;\n  vector<int> pr{2, 3};\n  for (int i = 2;\
    \ i <= N; i += 2) lp[i] = 2;\n  for (int i = 3; i <= N; i += 6) lp[i] = 3;\n \
    \ for (int i = 5, d = 4; i <= N; i += d = 6 - d) {\n    if (lp[i] == 0) {\n  \
    \    lp[i] = i;\n      pr.push_back(i);\n    }\n    for (int j = 2; j < (int)pr.size()\
    \ && i * pr[j] <= N; ++j) {\n      lp[i * pr[j]] = pr[j];\n      if (pr[j] ==\
    \ lp[i]) break;\n    }\n  }\n  return lp;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int>\
    \ factor_enumerate(int N) {\n  vector<int> lp(N + 1, 0);\n  if (N < 2) return\
    \ lp;\n  vector<int> pr{2, 3};\n  for (int i = 2; i <= N; i += 2) lp[i] = 2;\n\
    \  for (int i = 3; i <= N; i += 6) lp[i] = 3;\n  for (int i = 5, d = 4; i <= N;\
    \ i += d = 6 - d) {\n    if (lp[i] == 0) {\n      lp[i] = i;\n      pr.push_back(i);\n\
    \    }\n    for (int j = 2; j < (int)pr.size() && i * pr[j] <= N; ++j) {\n   \
    \   lp[i * pr[j]] = pr[j];\n      if (pr[j] == lp[i]) break;\n    }\n  }\n  return\
    \ lp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: prime/factor-enumerate.hpp
  requiredBy:
  - prime/osak.hpp
  timestamp: '2020-09-18 02:00:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/osak.test.cpp
documentation_of: prime/factor-enumerate.hpp
layout: document
redirect_from:
- /library/prime/factor-enumerate.hpp
- /library/prime/factor-enumerate.hpp.html
title: prime/factor-enumerate.hpp
---

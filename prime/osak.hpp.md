---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: prime/factor-enumerate.hpp
    title: prime/factor-enumerate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/factorize.test.cpp
    title: verify/verify-unit-test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"prime/osak.hpp\"\n\n#line 2 \"prime/factor-enumerate.hpp\"\
    \n\nvector<int> factor_enumerate(int N) {\n  vector<int> lp(N + 1, 0);\n  if (N\
    \ < 2) return lp;\n  vector<int> pr{2, 3};\n  for (int i = 2; i <= N; i += 2)\
    \ lp[i] = 2;\n  for (int i = 3; i <= N; i += 6) lp[i] = 3;\n  for (int i = 5,\
    \ d = 4; i <= N; i += d = 6 - d) {\n    if (lp[i] == 0) {\n      lp[i] = i;\n\
    \      pr.push_back(i);\n    }\n    for (int j = 2; j < (int)pr.size() && i *\
    \ pr[j] <= N; ++j) {\n      lp[i * pr[j]] = pr[j];\n      if (pr[j] == lp[i])\
    \ break;\n    }\n  }\n  return lp;\n}\n#line 4 \"prime/osak.hpp\"\n\ntemplate<int\
    \ MAX>\nvector<int> osak(int n){\n  static vector<int> f = factor_enumerate(MAX);\n\
    \  vector<int> ret;\n  while(f[n]) ret.push_back(f[n]), n /= f[n];\n  return ret;\n\
    }\n"
  code: "#pragma once\n\n#include \"factor-enumerate.hpp\"\n\ntemplate<int MAX>\n\
    vector<int> osak(int n){\n  static vector<int> f = factor_enumerate(MAX);\n  vector<int>\
    \ ret;\n  while(f[n]) ret.push_back(f[n]), n /= f[n];\n  return ret;\n}"
  dependsOn:
  - prime/factor-enumerate.hpp
  isVerificationFile: false
  path: prime/osak.hpp
  requiredBy: []
  timestamp: '2020-12-05 08:35:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/factorize.test.cpp
  - verify/verify-unit-test/osak.test.cpp
documentation_of: prime/osak.hpp
layout: document
redirect_from:
- /library/prime/osak.hpp
- /library/prime/osak.hpp.html
title: prime/osak.hpp
---

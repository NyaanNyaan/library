---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/binomial-table.test.cpp
    title: verify/verify-unit-test/binomial-table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulo/binomial-table.hpp\"\n\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate <typename mint>\nvector<vector<mint>> binomial_table(int\
    \ n) {\n  n += 10;\n  vector dp(n, vector(n, mint{0}));\n  dp[0][0] = 1;\n  for\
    \ (int i = 0; i + 1 < n; i++) {\n    for (int j = 0; j <= i; j++) {\n      dp[i\
    \ + 1][j + 0] += dp[i][j];\n      dp[i + 1][j + 1] += dp[i][j];\n    }\n  }\n\
    \  return dp;\n}\n"
  code: "#pragma once\n\n#include <vector>\nusing namespace std;\n\ntemplate <typename\
    \ mint>\nvector<vector<mint>> binomial_table(int n) {\n  n += 10;\n  vector dp(n,\
    \ vector(n, mint{0}));\n  dp[0][0] = 1;\n  for (int i = 0; i + 1 < n; i++) {\n\
    \    for (int j = 0; j <= i; j++) {\n      dp[i + 1][j + 0] += dp[i][j];\n   \
    \   dp[i + 1][j + 1] += dp[i][j];\n    }\n  }\n  return dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: modulo/binomial-table.hpp
  requiredBy: []
  timestamp: '2024-05-04 15:53:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/binomial-table.test.cpp
documentation_of: modulo/binomial-table.hpp
layout: document
redirect_from:
- /library/modulo/binomial-table.hpp
- /library/modulo/binomial-table.hpp.html
title: modulo/binomial-table.hpp
---

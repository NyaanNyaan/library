---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u90E8\u5206\u5217DP"
    links: []
  bundledCode: "#line 2 \"string/subsequence-dp.hpp\"\n\nvector<vector<int>> CalcNext(const\
    \ string &S, char offset = 'a', int w = 26) {\n  int n = (int)S.size();\n  vector<vector<int>>\
    \ res(n + 1, vector<int>(w, n));\n  for (int i = n - 1; i >= 0; --i) {\n    for\
    \ (int j = 0; j < w; ++j) res[i][j] = res[i + 1][j];\n    res[i][S[i] - offset]\
    \ = i;\n  }\n  return res;\n};\n\ntemplate <typename T>\nvector<T> SubSequenceDP(const\
    \ string &S, char offset = 'a', int w = 26) {\n  auto nxt = CalcNext(S, offset,\
    \ w);\n  int n = S.size();\n  vector<T> dp(n + 1);\n  dp[0] = 1;\n  for (int i\
    \ = 0; i < n; i++) {\n    for (int j = 0; j < w; j++) {\n      if (nxt[i][j] >=\
    \ n) continue;\n      dp[nxt[i][j] + 1] += dp[i];\n    }\n  }\n  dp.erase(begin(dp));\n\
    \  return dp;\n}\n\n/**\n * @brief \u90E8\u5206\u5217DP\n */\n"
  code: "#pragma once\n\nvector<vector<int>> CalcNext(const string &S, char offset\
    \ = 'a', int w = 26) {\n  int n = (int)S.size();\n  vector<vector<int>> res(n\
    \ + 1, vector<int>(w, n));\n  for (int i = n - 1; i >= 0; --i) {\n    for (int\
    \ j = 0; j < w; ++j) res[i][j] = res[i + 1][j];\n    res[i][S[i] - offset] = i;\n\
    \  }\n  return res;\n};\n\ntemplate <typename T>\nvector<T> SubSequenceDP(const\
    \ string &S, char offset = 'a', int w = 26) {\n  auto nxt = CalcNext(S, offset,\
    \ w);\n  int n = S.size();\n  vector<T> dp(n + 1);\n  dp[0] = 1;\n  for (int i\
    \ = 0; i < n; i++) {\n    for (int j = 0; j < w; j++) {\n      if (nxt[i][j] >=\
    \ n) continue;\n      dp[nxt[i][j] + 1] += dp[i];\n    }\n  }\n  dp.erase(begin(dp));\n\
    \  return dp;\n}\n\n/**\n * @brief \u90E8\u5206\u5217DP\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: string/subsequence-dp.hpp
  requiredBy: []
  timestamp: '2020-12-10 19:54:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/subsequence-dp.hpp
layout: document
redirect_from:
- /library/string/subsequence-dp.hpp
- /library/string/subsequence-dp.hpp.html
title: "\u90E8\u5206\u5217DP"
---

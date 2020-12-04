---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Pruefer Code
    links: []
  bundledCode: "#line 2 \"tree/pruefer-code.hpp\"\n\n\n\n// input: [c \\in [0, n)]\
    \ * (n-2), n>=3\nvector<vector<int>> pruefer_code(const vector<int>& code) {\n\
    \  int n = code.size() + 2;\n  assert(n > 2);\n  vector<vector<int>> g(n);\n \
    \ vector<int> deg(n, 1);\n  for (auto& x : code) deg[x]++;\n  for (auto& i : code)\
    \ {\n    for (int j = 0; j < n; j++) {\n      if (deg[j] == 1) {\n        g[i].push_back(j);\n\
    \        g[j].push_back(i);\n        deg[i]--, deg[j]--;\n      }\n    }\n  }\n\
    \  int u = -1, v = -1;\n  for (int i = 0; i < n; i++) {\n    if (deg[i] == 1)\
    \ (u == -1 ? u : v) = i;\n  }\n  g[u].push_back(v);\n  g[v].push_back(u);\n  return\
    \ g;\n}\n\n/**\n * @brief Pruefer Code\n */\n"
  code: "#pragma once\n\n\n\n// input: [c \\in [0, n)] * (n-2), n>=3\nvector<vector<int>>\
    \ pruefer_code(const vector<int>& code) {\n  int n = code.size() + 2;\n  assert(n\
    \ > 2);\n  vector<vector<int>> g(n);\n  vector<int> deg(n, 1);\n  for (auto& x\
    \ : code) deg[x]++;\n  for (auto& i : code) {\n    for (int j = 0; j < n; j++)\
    \ {\n      if (deg[j] == 1) {\n        g[i].push_back(j);\n        g[j].push_back(i);\n\
    \        deg[i]--, deg[j]--;\n      }\n    }\n  }\n  int u = -1, v = -1;\n  for\
    \ (int i = 0; i < n; i++) {\n    if (deg[i] == 1) (u == -1 ? u : v) = i;\n  }\n\
    \  g[u].push_back(v);\n  g[v].push_back(u);\n  return g;\n}\n\n/**\n * @brief\
    \ Pruefer Code\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/pruefer-code.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/pruefer-code.hpp
layout: document
redirect_from:
- /library/tree/pruefer-code.hpp
- /library/tree/pruefer-code.hpp.html
title: Pruefer Code
---

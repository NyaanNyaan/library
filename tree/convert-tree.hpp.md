---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/tree-path.test.cpp
    title: verify/verify-unit-test/tree-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6839\u4ED8\u304D\u6728\u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\
      \u6728\u3078\u306E\u5909\u63DB"
    links: []
  bundledCode: "#line 2 \"tree/convert-tree.hpp\"\n\nvector<vector<int>> inverse_tree(const\
    \ vector<vector<int>>& g, int root = 0) {\n  int N = (int)g.size();\n  vector<vector<int>>\
    \ rg(N);\n  vector<char> v(N);\n  for (int i = 0; i < N; i++)\n    for (auto&\
    \ j : g[i]) {\n      rg[j].push_back(i);\n    }\n  return rg;\n}\n\nvector<vector<int>>\
    \ rooted_tree(const vector<vector<int>>& g, int root = 0) {\n  int N = (int)g.size();\n\
    \  vector<vector<int>> rg(N);\n  vector<bool> v(N, false);\n  v[root] = 1;\n \
    \ queue<int> que;\n  que.emplace(root);\n  while (!que.empty()) {\n    auto p\
    \ = que.front();\n    que.pop();\n    for (auto& e : g[p]) {\n      if (v[e] ==\
    \ false) {\n        v[e] = true;\n        que.push(e);\n        rg[p].push_back(e);\n\
    \      }\n    }\n  }\n  return rg;\n}\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\
    \u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\u3078\u306E\u5909\u63DB\n */\n"
  code: "#pragma once\n\nvector<vector<int>> inverse_tree(const vector<vector<int>>&\
    \ g, int root = 0) {\n  int N = (int)g.size();\n  vector<vector<int>> rg(N);\n\
    \  vector<char> v(N);\n  for (int i = 0; i < N; i++)\n    for (auto& j : g[i])\
    \ {\n      rg[j].push_back(i);\n    }\n  return rg;\n}\n\nvector<vector<int>>\
    \ rooted_tree(const vector<vector<int>>& g, int root = 0) {\n  int N = (int)g.size();\n\
    \  vector<vector<int>> rg(N);\n  vector<bool> v(N, false);\n  v[root] = 1;\n \
    \ queue<int> que;\n  que.emplace(root);\n  while (!que.empty()) {\n    auto p\
    \ = que.front();\n    que.pop();\n    for (auto& e : g[p]) {\n      if (v[e] ==\
    \ false) {\n        v[e] = true;\n        que.push(e);\n        rg[p].push_back(e);\n\
    \      }\n    }\n  }\n  return rg;\n}\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\
    \u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\u3078\u306E\u5909\u63DB\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/convert-tree.hpp
  requiredBy: []
  timestamp: '2020-12-05 20:52:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/tree-path.test.cpp
documentation_of: tree/convert-tree.hpp
layout: document
redirect_from:
- /library/tree/convert-tree.hpp
- /library/tree/convert-tree.hpp.html
title: "\u6839\u4ED8\u304D\u6728\u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\u3078\
  \u306E\u5909\u63DB"
---

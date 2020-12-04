---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/convert-rooted-tree.hpp\"\n\n\n\ntemplate <typename\
    \ G>\nG convert_rooted_tree(const G& g, int root = 0, bool inverse = false) {\n\
    \  int N = (int)g.size();\n  G rg(N);\n  vector<char> v(N);\n  v[root] = 1;\n\
    \  queue<int> que;\n  que.emplace(root);\n  while (!que.empty()) {\n    auto p\
    \ = que.front();\n    que.pop();\n    for (auto& to : g[p]) {\n      if (v[to]\
    \ == 0) {\n        v[to] = 1;\n        que.emplace(to);\n        if (inverse)\n\
    \          rg[to].emplace_back(p);\n        else\n          rg[p].emplace_back(to);\n\
    \      }\n    }\n  }\n  return rg;\n}\n"
  code: "#pragma once\n\n\n\ntemplate <typename G>\nG convert_rooted_tree(const G&\
    \ g, int root = 0, bool inverse = false) {\n  int N = (int)g.size();\n  G rg(N);\n\
    \  vector<char> v(N);\n  v[root] = 1;\n  queue<int> que;\n  que.emplace(root);\n\
    \  while (!que.empty()) {\n    auto p = que.front();\n    que.pop();\n    for\
    \ (auto& to : g[p]) {\n      if (v[to] == 0) {\n        v[to] = 1;\n        que.emplace(to);\n\
    \        if (inverse)\n          rg[to].emplace_back(p);\n        else\n     \
    \     rg[p].emplace_back(to);\n      }\n    }\n  }\n  return rg;\n}"
  dependsOn: []
  isVerificationFile: false
  path: tree/convert-rooted-tree.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/convert-rooted-tree.hpp
layout: document
redirect_from:
- /library/tree/convert-rooted-tree.hpp
- /library/tree/convert-rooted-tree.hpp.html
title: tree/convert-rooted-tree.hpp
---

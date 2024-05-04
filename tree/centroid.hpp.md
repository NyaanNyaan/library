---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/tree-hash.hpp
    title: tree/tree-hash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2821.test.cpp
    title: verify/verify-aoj-other/aoj-2821.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/centroid.hpp\"\n\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\ntemplate <typename G>\nvector<int> centroid(const G &g)\
    \ {\n  const int N = (int)g.size();\n\n  vector<pair<int, int> > st;\n  st.emplace_back(0,\
    \ -1);\n  vector<int> sz(N), par(N);\n  while (!st.empty()) {\n    auto p = st.back();\n\
    \    if (sz[p.first] == 0) {\n      sz[p.first] = 1;\n      for (auto &to : g[p.first])\n\
    \        if (to != p.second) st.emplace_back(to, p.first);\n    } else {\n   \
    \   for (auto &to : g[p.first])\n        if (to != p.second) sz[p.first] += sz[to];\n\
    \      par[p.first] = p.second;\n      st.pop_back();\n    }\n  }\n\n  vector<int>\
    \ ret;\n  int size = N;\n  for (int i = 0; i < N; i++) {\n    int val = N - sz[i];\n\
    \    for (auto &to : g[i])\n      if (to != par[i]) val = max(val, sz[to]);\n\
    \    if (val < size) size = val, ret.clear();\n    if (val == size) ret.emplace_back(i);\n\
    \  }\n\n  return ret;\n}\n"
  code: "#pragma once\n\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \ntemplate <typename G>\nvector<int> centroid(const G &g) {\n  const int N = (int)g.size();\n\
    \n  vector<pair<int, int> > st;\n  st.emplace_back(0, -1);\n  vector<int> sz(N),\
    \ par(N);\n  while (!st.empty()) {\n    auto p = st.back();\n    if (sz[p.first]\
    \ == 0) {\n      sz[p.first] = 1;\n      for (auto &to : g[p.first])\n       \
    \ if (to != p.second) st.emplace_back(to, p.first);\n    } else {\n      for (auto\
    \ &to : g[p.first])\n        if (to != p.second) sz[p.first] += sz[to];\n    \
    \  par[p.first] = p.second;\n      st.pop_back();\n    }\n  }\n\n  vector<int>\
    \ ret;\n  int size = N;\n  for (int i = 0; i < N; i++) {\n    int val = N - sz[i];\n\
    \    for (auto &to : g[i])\n      if (to != par[i]) val = max(val, sz[to]);\n\
    \    if (val < size) size = val, ret.clear();\n    if (val == size) ret.emplace_back(i);\n\
    \  }\n\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid.hpp
  requiredBy:
  - tree/tree-hash.hpp
  timestamp: '2024-05-04 15:53:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-2821.test.cpp
documentation_of: tree/centroid.hpp
layout: document
redirect_from:
- /library/tree/centroid.hpp
- /library/tree/centroid.hpp.html
title: tree/centroid.hpp
---

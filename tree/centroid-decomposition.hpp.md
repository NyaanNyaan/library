---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/frequency-table-of-tree-distance.hpp
    title: "\u9802\u70B9\u9593\u306E\u8DDD\u96E2\u306E\u5EA6\u6570\u5206\u5E03"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
    title: verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/centroid-decomposition.md
    document_title: Centroid Decomposition
    links: []
  bundledCode: "#line 2 \"tree/centroid-decomposition.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <typename G>\nstruct CentroidDecomposition {\n\
    \  const G &g;\n  vector<int> sub;\n  vector<bool> v;\n  vector<vector<int>> tree;\n\
    \  int root;\n\n  CentroidDecomposition(const G &g_, int isbuild = true) : g(g_)\
    \ {\n    sub.resize(g.size(), 0);\n    v.resize(g.size(), false);\n    if (isbuild)\
    \ build();\n  }\n\n  void build() {\n    tree.resize(g.size());\n    root = build_dfs(0);\n\
    \  }\n\n  int get_size(int cur, int par) {\n    sub[cur] = 1;\n    for (auto &dst\
    \ : g[cur]) {\n      if (dst == par || v[dst]) continue;\n      sub[cur] += get_size(dst,\
    \ cur);\n    }\n    return sub[cur];\n  }\n\n  int get_centroid(int cur, int par,\
    \ int mid) {\n    for (auto &dst : g[cur]) {\n      if (dst == par || v[dst])\
    \ continue;\n      if (sub[dst] > mid) return get_centroid(dst, cur, mid);\n \
    \   }\n    return cur;\n  }\n\n  int build_dfs(int cur) {\n    int centroid =\
    \ get_centroid(cur, -1, get_size(cur, -1) / 2);\n    v[centroid] = true;\n   \
    \ for (auto &dst : g[centroid]) {\n      if (!v[dst]) {\n        int nxt = build_dfs(dst);\n\
    \        if (centroid != nxt) tree[centroid].emplace_back(nxt);\n      }\n   \
    \ }\n    v[centroid] = false;\n    return centroid;\n  }\n};\n\n/**\n * @brief\
    \ Centroid Decomposition\n * @docs docs/tree/centroid-decomposition.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename G>\nstruct CentroidDecomposition {\n  const G &g;\n  vector<int> sub;\n\
    \  vector<bool> v;\n  vector<vector<int>> tree;\n  int root;\n\n  CentroidDecomposition(const\
    \ G &g_, int isbuild = true) : g(g_) {\n    sub.resize(g.size(), 0);\n    v.resize(g.size(),\
    \ false);\n    if (isbuild) build();\n  }\n\n  void build() {\n    tree.resize(g.size());\n\
    \    root = build_dfs(0);\n  }\n\n  int get_size(int cur, int par) {\n    sub[cur]\
    \ = 1;\n    for (auto &dst : g[cur]) {\n      if (dst == par || v[dst]) continue;\n\
    \      sub[cur] += get_size(dst, cur);\n    }\n    return sub[cur];\n  }\n\n \
    \ int get_centroid(int cur, int par, int mid) {\n    for (auto &dst : g[cur])\
    \ {\n      if (dst == par || v[dst]) continue;\n      if (sub[dst] > mid) return\
    \ get_centroid(dst, cur, mid);\n    }\n    return cur;\n  }\n\n  int build_dfs(int\
    \ cur) {\n    int centroid = get_centroid(cur, -1, get_size(cur, -1) / 2);\n \
    \   v[centroid] = true;\n    for (auto &dst : g[centroid]) {\n      if (!v[dst])\
    \ {\n        int nxt = build_dfs(dst);\n        if (centroid != nxt) tree[centroid].emplace_back(nxt);\n\
    \      }\n    }\n    v[centroid] = false;\n    return centroid;\n  }\n};\n\n/**\n\
    \ * @brief Centroid Decomposition\n * @docs docs/tree/centroid-decomposition.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid-decomposition.hpp
  requiredBy:
  - tree/frequency-table-of-tree-distance.hpp
  timestamp: '2020-12-02 03:43:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
documentation_of: tree/centroid-decomposition.hpp
layout: document
redirect_from:
- /library/tree/centroid-decomposition.hpp
- /library/tree/centroid-decomposition.hpp.html
title: Centroid Decomposition
---
## 重心分解

#### 概要

TODO

#### 使い方


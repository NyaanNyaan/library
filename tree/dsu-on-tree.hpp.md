---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/dsu-on-tree.md
    document_title: DSU on Tree(Guni)
    links: []
  bundledCode: "#line 2 \"tree/dsu-on-tree.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 3 \"graph/graph-template.hpp\"\nusing namespace std;\n\
    \ntemplate <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int\
    \ _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int _src, int _to,\
    \ T _cost) : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const int\
    \ &x) {\n    to = x;\n    return *this;\n  }\n\n  operator int() const { return\
    \ to; }\n};\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\ntemplate <typename\
    \ T>\nusing WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph = vector<vector<int>>;\n\
    \n// Input of (Unweighted) Graph\nUnweightedGraph graph(int N, int M = -1, bool\
    \ is_directed = false,\n                      bool is_1origin = true) {\n  UnweightedGraph\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n\
    \    if (!is_directed) g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of\
    \ Weighted Graph\ntemplate <typename T>\nWeightedGraph<T> wgraph(int N, int M\
    \ = -1, bool is_directed = false,\n                        bool is_1origin = true)\
    \ {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _\
    \ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n  \
    \  if (is_1origin) x--, y--;\n    g[x].eb(x, y, c);\n    if (!is_directed) g[y].eb(y,\
    \ x, c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate <typename T>\nEdges<T>\
    \ esgraph(int N, int M, int is_weighted = true, bool is_1origin = true) {\n  Edges<T>\
    \ es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n  \
    \  T c;\n    if (is_weighted)\n      cin >> c;\n    else\n      c = 1;\n    if\
    \ (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n  }\n  return es;\n}\n\
    \n// Input of Adjacency Matrix\ntemplate <typename T>\nvector<vector<T>> adjgraph(int\
    \ N, int M, T INF, int is_weighted = true,\n                           bool is_directed\
    \ = false, bool is_1origin = true) {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n\
    \  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n\
    \    if (is_weighted)\n      cin >> c;\n    else\n      c = 1;\n    if (is_1origin)\
    \ x--, y--;\n    d[x][y] = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return\
    \ d;\n}\n#line 6 \"tree/dsu-on-tree.hpp\"\n\ntemplate <typename G>\nstruct DSUonTree\
    \ {\n private:\n  G &g;\n  int N;\n  vector<int> sub_sz, euler, down, up;\n  int\
    \ idx_;\n  int root;\n\n  int dfs1(int cur, int par = -1) {\n    sub_sz[cur] =\
    \ 1;\n    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {\n      swap(g[cur][0],\
    \ g[cur][1]);\n    }\n    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n\
    \      sub_sz[cur] += dfs1(dst, cur);\n      if (sub_sz[dst] > sub_sz[g[cur][0]])\
    \ swap(dst, g[cur][0]);\n    }\n    return sub_sz[cur];\n  }\n\n  void dfs2(int\
    \ cur, int par = -1) {\n    euler[idx_] = cur;\n    down[cur] = idx_++;\n    for\
    \ (auto &dst : g[cur]) {\n      if (dst == par) continue;\n      dfs2(dst, cur);\n\
    \    }\n    up[cur] = idx_;\n  }\n\n public:\n  DSUonTree(G &_g,int _root = 0)\n\
    \      : g(_g),\n        N(_g.size()),\n        sub_sz(_g.size()),\n        euler(_g.size()),\n\
    \        down(_g.size()),\n        up(_g.size()),\n        idx_(0),\n        root(_root)\
    \ {\n    dfs1(root);\n    dfs2(root);\n  }\n\n  int idx(int u) const { return\
    \ down[u]; }\n\n  template <typename UPDATE, typename QUERY, typename CLEAR, typename\
    \ RESET>\n  void run(UPDATE &update, QUERY &query, CLEAR &clear, RESET &reset)\
    \ {\n    auto dsu = [&](auto rc, int cur, int par = -1, bool keep = true) -> void\
    \ {\n      // light edge -> run dfs and clear data\n      for (int i = 1; i <\
    \ (int)g[cur].size(); i++)\n        if (g[cur][i] != par) rc(rc, g[cur][i], cur,\
    \ false);\n\n      // heavy edge -> run dfs and reserve data\n      if (sub_sz[cur]\
    \ != 1) rc(rc, g[cur][0], cur, true);\n\n      // light edge -> reserve data\n\
    \      if (sub_sz[cur] != 1)\n        for (int i = up[g[cur][0]]; i < up[cur];\
    \ i++) update(euler[i]);\n\n      // current node -> reserve data\n      update(cur);\n\
    \n      // answer queries related to subtree of current node\n      query(cur);\n\
    \n      // if keep is false, clear all data\n      if (!keep) {\n        for (int\
    \ i = down[cur]; i < up[cur]; i++) clear(euler[i]);\n        reset();\n      }\n\
    \      return;\n    };\n    dsu(dsu, root);\n  }\n};\n\n/**\n * @brief DSU on\
    \ Tree(Guni)\n * @docs docs/tree/dsu-on-tree.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../graph/graph-template.hpp\"\n\ntemplate <typename G>\nstruct DSUonTree {\n\
    \ private:\n  G &g;\n  int N;\n  vector<int> sub_sz, euler, down, up;\n  int idx_;\n\
    \  int root;\n\n  int dfs1(int cur, int par = -1) {\n    sub_sz[cur] = 1;\n  \
    \  if ((int)g[cur].size() >= 2 and g[cur][0] == par) {\n      swap(g[cur][0],\
    \ g[cur][1]);\n    }\n    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n\
    \      sub_sz[cur] += dfs1(dst, cur);\n      if (sub_sz[dst] > sub_sz[g[cur][0]])\
    \ swap(dst, g[cur][0]);\n    }\n    return sub_sz[cur];\n  }\n\n  void dfs2(int\
    \ cur, int par = -1) {\n    euler[idx_] = cur;\n    down[cur] = idx_++;\n    for\
    \ (auto &dst : g[cur]) {\n      if (dst == par) continue;\n      dfs2(dst, cur);\n\
    \    }\n    up[cur] = idx_;\n  }\n\n public:\n  DSUonTree(G &_g,int _root = 0)\n\
    \      : g(_g),\n        N(_g.size()),\n        sub_sz(_g.size()),\n        euler(_g.size()),\n\
    \        down(_g.size()),\n        up(_g.size()),\n        idx_(0),\n        root(_root)\
    \ {\n    dfs1(root);\n    dfs2(root);\n  }\n\n  int idx(int u) const { return\
    \ down[u]; }\n\n  template <typename UPDATE, typename QUERY, typename CLEAR, typename\
    \ RESET>\n  void run(UPDATE &update, QUERY &query, CLEAR &clear, RESET &reset)\
    \ {\n    auto dsu = [&](auto rc, int cur, int par = -1, bool keep = true) -> void\
    \ {\n      // light edge -> run dfs and clear data\n      for (int i = 1; i <\
    \ (int)g[cur].size(); i++)\n        if (g[cur][i] != par) rc(rc, g[cur][i], cur,\
    \ false);\n\n      // heavy edge -> run dfs and reserve data\n      if (sub_sz[cur]\
    \ != 1) rc(rc, g[cur][0], cur, true);\n\n      // light edge -> reserve data\n\
    \      if (sub_sz[cur] != 1)\n        for (int i = up[g[cur][0]]; i < up[cur];\
    \ i++) update(euler[i]);\n\n      // current node -> reserve data\n      update(cur);\n\
    \n      // answer queries related to subtree of current node\n      query(cur);\n\
    \n      // if keep is false, clear all data\n      if (!keep) {\n        for (int\
    \ i = down[cur]; i < up[cur]; i++) clear(euler[i]);\n        reset();\n      }\n\
    \      return;\n    };\n    dsu(dsu, root);\n  }\n};\n\n/**\n * @brief DSU on\
    \ Tree(Guni)\n * @docs docs/tree/dsu-on-tree.md\n */\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/dsu-on-tree.hpp
  requiredBy: []
  timestamp: '2020-11-26 23:21:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
documentation_of: tree/dsu-on-tree.hpp
layout: document
redirect_from:
- /library/tree/dsu-on-tree.hpp
- /library/tree/dsu-on-tree.hpp.html
title: DSU on Tree(Guni)
---
## DSU on Tree

#### テンプレート

```
// reflect data of node i
  auto update = [&](int i) {

  };
  // answer queries of subtree i
  auto query = [&](int i) {

  };
  // below two function are called if all data must be deleted
  // delete data of node i (if necesarry)
  auto clear = [&](int i) {

  };
  // delete data related to all (if necesarry)
  auto reset = [&]() {

  };
  DSUonTree<decltype(g)> dsu(g, 0);
  dsu.run(update, query, clear, reset);
```

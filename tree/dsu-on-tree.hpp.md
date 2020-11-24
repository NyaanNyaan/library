---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
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
    \ d;\n}\n#line 6 \"tree/dsu-on-tree.hpp\"\n\ntemplate <typename G, typename UPDATE,\
    \ typename QUERY, typename CLEAR,\n          typename RESET>\nstruct DSUonTree\
    \ {\n  G &g;\n  int N;\n  vector<int> sub_sz, euler, li, ri;\n  int idx;\n  UPDATE\
    \ &update;\n  QUERY &query;\n  CLEAR &clear;\n  RESET &reset;\n\n  DSUonTree(G\
    \ &_g, UPDATE &_update, QUERY &_query, CLEAR &_clear, RESET &_reset)\n      :\
    \ g(_g),\n        N(_g.size()),\n        sub_sz(_g.size()),\n        euler(_g.size()),\n\
    \        li(_g.size()),\n        ri(_g.size()),\n        idx(0),\n        update(_update),\n\
    \        query(_query),\n        clear(_clear),\n        reset(_reset) {\n   \
    \ dfs1();\n    dfs2();\n  }\n\n  int dfs1(int cur = 0, int par = -1) {\n    sub_sz[cur]\
    \ = 1;\n    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {\n      swap(g[cur][0],\
    \ g[cur][1]);\n    }\n    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n\
    \      sub_sz[cur] += dfs1(dst, cur);\n      if (sub_sz[dst] > sub_sz[g[cur][0]])\
    \ swap(dst, g[cur][0]);\n    }\n    return sub_sz[cur];\n  }\n\n  void dfs2(int\
    \ cur = 0, int par = -1) {\n    euler[idx] = cur;\n    li[cur] = idx++;\n    for\
    \ (auto &dst : g[cur]) {\n      if (dst == par) continue;\n      dfs2(dst, cur);\n\
    \    }\n    ri[cur] = idx;\n  }\n\n  void dsu(int cur = 0, int par = -1, int keep\
    \ = 1) {\n    // light edge -> run dfs and clear data\n    for (int i = 1; i <\
    \ (int)g[cur].size(); i++)\n      if (g[cur][i] != par) dsu(g[cur][i], cur, false);\n\
    \n    // heavy edge -> run dfs and reserve data\n    if (sub_sz[cur] != 1) dsu(g[cur][0],\
    \ cur, true);\n\n    // light edge -> reserve data\n    if (sub_sz[cur] != 1)\n\
    \      for (int i = ri[g[cur][0]]; i < ri[cur]; i++) update(euler[i]);\n\n   \
    \ // current node -> reserve data\n    update(cur);\n\n    // answer queries related\
    \ to subtree of current node\n    query(cur);\n\n    // if keep is false, clear\
    \ all data\n    if (!keep) {\n      for (int i = li[cur]; i < ri[cur]; i++) clear(euler[i]);\n\
    \      reset();\n    }\n    return;\n  }\n\n  void run() { dsu(); }\n};\n\n/*\n\
    \  // reflect data of node i\n  auto update = [&](int i) {\n\n  };\n  // answer\
    \ queries of subtree i\n  auto query = [&](int i) {\n\n  };\n  // below two function\
    \ are called if all data must be deleted\n  // delete data of node i (if necesarry)\n\
    \  auto clear = [&](int i) {\n\n  };\n  // delete data related to all (if necesarry)\n\
    \  auto reset = [&]() {\n\n  };\n  DSUonTree<decltype(g), decltype(update), decltype(query),\
    \ decltype(clear),\n            decltype(reset)>\n      dsu(g, update, query,\
    \ clear, reset);\n  dsu.run();\n*/\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../graph/graph-template.hpp\"\n\ntemplate <typename G, typename UPDATE, typename\
    \ QUERY, typename CLEAR,\n          typename RESET>\nstruct DSUonTree {\n  G &g;\n\
    \  int N;\n  vector<int> sub_sz, euler, li, ri;\n  int idx;\n  UPDATE &update;\n\
    \  QUERY &query;\n  CLEAR &clear;\n  RESET &reset;\n\n  DSUonTree(G &_g, UPDATE\
    \ &_update, QUERY &_query, CLEAR &_clear, RESET &_reset)\n      : g(_g),\n   \
    \     N(_g.size()),\n        sub_sz(_g.size()),\n        euler(_g.size()),\n \
    \       li(_g.size()),\n        ri(_g.size()),\n        idx(0),\n        update(_update),\n\
    \        query(_query),\n        clear(_clear),\n        reset(_reset) {\n   \
    \ dfs1();\n    dfs2();\n  }\n\n  int dfs1(int cur = 0, int par = -1) {\n    sub_sz[cur]\
    \ = 1;\n    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {\n      swap(g[cur][0],\
    \ g[cur][1]);\n    }\n    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n\
    \      sub_sz[cur] += dfs1(dst, cur);\n      if (sub_sz[dst] > sub_sz[g[cur][0]])\
    \ swap(dst, g[cur][0]);\n    }\n    return sub_sz[cur];\n  }\n\n  void dfs2(int\
    \ cur = 0, int par = -1) {\n    euler[idx] = cur;\n    li[cur] = idx++;\n    for\
    \ (auto &dst : g[cur]) {\n      if (dst == par) continue;\n      dfs2(dst, cur);\n\
    \    }\n    ri[cur] = idx;\n  }\n\n  void dsu(int cur = 0, int par = -1, int keep\
    \ = 1) {\n    // light edge -> run dfs and clear data\n    for (int i = 1; i <\
    \ (int)g[cur].size(); i++)\n      if (g[cur][i] != par) dsu(g[cur][i], cur, false);\n\
    \n    // heavy edge -> run dfs and reserve data\n    if (sub_sz[cur] != 1) dsu(g[cur][0],\
    \ cur, true);\n\n    // light edge -> reserve data\n    if (sub_sz[cur] != 1)\n\
    \      for (int i = ri[g[cur][0]]; i < ri[cur]; i++) update(euler[i]);\n\n   \
    \ // current node -> reserve data\n    update(cur);\n\n    // answer queries related\
    \ to subtree of current node\n    query(cur);\n\n    // if keep is false, clear\
    \ all data\n    if (!keep) {\n      for (int i = li[cur]; i < ri[cur]; i++) clear(euler[i]);\n\
    \      reset();\n    }\n    return;\n  }\n\n  void run() { dsu(); }\n};\n\n/*\n\
    \  // reflect data of node i\n  auto update = [&](int i) {\n\n  };\n  // answer\
    \ queries of subtree i\n  auto query = [&](int i) {\n\n  };\n  // below two function\
    \ are called if all data must be deleted\n  // delete data of node i (if necesarry)\n\
    \  auto clear = [&](int i) {\n\n  };\n  // delete data related to all (if necesarry)\n\
    \  auto reset = [&]() {\n\n  };\n  DSUonTree<decltype(g), decltype(update), decltype(query),\
    \ decltype(clear),\n            decltype(reset)>\n      dsu(g, update, query,\
    \ clear, reset);\n  dsu.run();\n*/"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/dsu-on-tree.hpp
  requiredBy: []
  timestamp: '2020-11-24 16:37:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/dsu-on-tree.hpp
layout: document
redirect_from:
- /library/tree/dsu-on-tree.hpp
- /library/tree/dsu-on-tree.hpp.html
title: tree/dsu-on-tree.hpp
---

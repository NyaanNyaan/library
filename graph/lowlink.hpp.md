---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/two-edge-connected-components.hpp
    title: graph/two-edge-connected-components.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-3-a.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-3-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-3-b.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-3-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-two-edge-cc.test.cpp
    title: verify/verify-yosupo-graph/yosupo-two-edge-cc.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/lowlink.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 3 \"graph/graph-template.hpp\"\nusing namespace std;\n\ntemplate\
    \ <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int _to, T\
    \ _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int _src, int _to, T _cost)\
    \ : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const int &x) {\n\
    \    to = x;\n    return *this;\n  }\n\n  operator int() const { return to; }\n\
    };\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\ntemplate <typename\
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
    \ d;\n}\n#line 6 \"graph/lowlink.hpp\"\n\n// LowLink ... enumerate bridge and\
    \ articulation point\n// bridge ... \u6A4B articulation point ... \u95A2\u7BC0\
    \u70B9\ntemplate <typename G>\nstruct LowLink {\n  int N;\n  const G &g;\n  vector<int>\
    \ ord, low, articulation;\n  vector<pair<int, int> > bridge;\n\n  LowLink(const\
    \ G &g) : g(g) {\n    N = g.size();\n    ord.resize(N, -1);\n    low.resize(N,\
    \ -1);\n    int k = 0;\n    for (int i = 0; i < N; i++)\n      if (!(~ord[i]))\
    \ k = dfs(i, k, -1);\n  }\n\n  int dfs(int idx, int k, int par) {\n    low[idx]\
    \ = (ord[idx] = k++);\n    int cnt = 0;\n    bool is_arti = false, flg = false;\n\
    \    for (auto &to : g[idx]) {\n      if (ord[to] == -1) {\n        cnt++;\n \
    \       k = dfs(to, k, idx);\n        low[idx] = min(low[idx], low[to]);\n   \
    \     is_arti |= (par != -1) && (low[to] >= ord[idx]);\n        if (ord[idx] <\
    \ low[to]) {\n          bridge.emplace_back(minmax(idx, (int)to));\n        }\n\
    \      } else if (to != par || exchange(flg, true)) {\n        low[idx] = min(low[idx],\
    \ ord[to]);\n      }\n    }\n    is_arti |= par == -1 && cnt > 1;\n    if (is_arti)\
    \ articulation.push_back(idx);\n    return k;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"./graph-template.hpp\"\n\n// LowLink ... enumerate bridge and articulation\
    \ point\n// bridge ... \u6A4B articulation point ... \u95A2\u7BC0\u70B9\ntemplate\
    \ <typename G>\nstruct LowLink {\n  int N;\n  const G &g;\n  vector<int> ord,\
    \ low, articulation;\n  vector<pair<int, int> > bridge;\n\n  LowLink(const G &g)\
    \ : g(g) {\n    N = g.size();\n    ord.resize(N, -1);\n    low.resize(N, -1);\n\
    \    int k = 0;\n    for (int i = 0; i < N; i++)\n      if (!(~ord[i])) k = dfs(i,\
    \ k, -1);\n  }\n\n  int dfs(int idx, int k, int par) {\n    low[idx] = (ord[idx]\
    \ = k++);\n    int cnt = 0;\n    bool is_arti = false, flg = false;\n    for (auto\
    \ &to : g[idx]) {\n      if (ord[to] == -1) {\n        cnt++;\n        k = dfs(to,\
    \ k, idx);\n        low[idx] = min(low[idx], low[to]);\n        is_arti |= (par\
    \ != -1) && (low[to] >= ord[idx]);\n        if (ord[idx] < low[to]) {\n      \
    \    bridge.emplace_back(minmax(idx, (int)to));\n        }\n      } else if (to\
    \ != par || exchange(flg, true)) {\n        low[idx] = min(low[idx], ord[to]);\n\
    \      }\n    }\n    is_arti |= par == -1 && cnt > 1;\n    if (is_arti) articulation.push_back(idx);\n\
    \    return k;\n  }\n};"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy:
  - graph/two-edge-connected-components.hpp
  timestamp: '2020-11-24 16:37:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-two-edge-cc.test.cpp
  - verify/verify-aoj-grl/aoj-grl-3-a.test.cpp
  - verify/verify-aoj-grl/aoj-grl-3-b.test.cpp
documentation_of: graph/lowlink.hpp
layout: document
redirect_from:
- /library/graph/lowlink.hpp
- /library/graph/lowlink.hpp.html
title: graph/lowlink.hpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-1-c.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-1-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/semiring.test.cpp
    title: verify/verify-unit-test/semiring.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"shortest-path/warshall-floyd.hpp\"\n\n\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\ntemplate <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int\
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
    \  if (is_1origin) x--, y--;\n    g[x].emplace_back(x, y, c);\n    if (!is_directed)\
    \ g[y].emplace_back(y, x, c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate\
    \ <typename T>\nEdges<T> esgraph(int N, int M, int is_weighted = true, bool is_1origin\
    \ = true) {\n  Edges<T> es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n\
    \    cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin >> c;\n    else\n\
    \      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n\
    \  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename T>\n\
    vector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n    \
    \                       bool is_directed = false, bool is_1origin = true) {\n\
    \  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++) {\n\
    \    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin\
    \ >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y] =\
    \ c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n#line 6 \"shortest-path/warshall-floyd.hpp\"\
    \n\n// i : d[i][i] < 0 exists -> negative cycle\ntemplate <typename T>\nvoid warshall_floyd(T&\
    \ d) {\n  int N = d[0].size();\n  for (int i = 0; i < N; i++) d[i][i] = 0;\n \
    \ for (int k = 0; k < N; k++)\n    for (int i = 0; i < N; i++)\n      for (int\
    \ j = 0; j < N; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n}\n"
  code: "#pragma once\n\n\n\n#include \"../graph/graph-template.hpp\"\n\n// i : d[i][i]\
    \ < 0 exists -> negative cycle\ntemplate <typename T>\nvoid warshall_floyd(T&\
    \ d) {\n  int N = d[0].size();\n  for (int i = 0; i < N; i++) d[i][i] = 0;\n \
    \ for (int k = 0; k < N; k++)\n    for (int i = 0; i < N; i++)\n      for (int\
    \ j = 0; j < N; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n}"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: shortest-path/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2020-12-05 08:35:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-1-c.test.cpp
  - verify/verify-unit-test/semiring.test.cpp
documentation_of: shortest-path/warshall-floyd.hpp
layout: document
redirect_from:
- /library/shortest-path/warshall-floyd.hpp
- /library/shortest-path/warshall-floyd.hpp.html
title: shortest-path/warshall-floyd.hpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-1-b.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-1-b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"shortest-path/bellman-ford.hpp\"\n\n\n\n#line 2 \"graph/graph-template.hpp\"\
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
    \ <typename T>\nEdges<T> esgraph([[maybe_unused]] int N, int M, int is_weighted\
    \ = true,\n                 bool is_1origin = true) {\n  Edges<T> es;\n  for (int\
    \ _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n\
    \      cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x,\
    \ y, c);\n  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename\
    \ T>\nvector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n\
    \                           bool is_directed = false, bool is_1origin = true)\
    \ {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y]\
    \ = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 6 \"shortest-path/bellman-ford.hpp\"\n\n// bellman-ford\u6CD5\n//\
    \ goal\u304C\u5B58\u5728\u3057\u306A\u3044\u3068\u304D-> \u8CA0\u9589\u8DEF\u304C\
    \u5B58\u5728\u3059\u308B\u3068\u304D\u306F\u7A7A\u5217\u3092\u8FD4\u3059\n// goal\u304C\
    \u5B58\u5728\u3059\u308B\u3068\u304D  -> start\u3068goal\u306E\u9593\u306B\u8CA0\
    \u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u6642\u306B\u8CA0\u9589\u8DEF\u3092\
    \u8FD4\u3059\ntemplate <typename T>\nvector<T> bellman_ford(int N, Edges<T> &es,\
    \ int start = 0, int goal = -1) {\n  T INF = numeric_limits<T>::max() / 2;\n \
    \ vector<T> d(N, INF);\n  d[start] = 0;\n  for (int i = 0; i < N; i++) {\n   \
    \ bool update = false;\n    for (auto &e : es) {\n      if (d[e.src] == INF) continue;\n\
    \      if (d[e.to] > d[e.src] + e.cost) {\n        update = true, d[e.to] = d[e.src]\
    \ + e.cost;\n      }\n    }\n    if (!update) return d;\n  }\n\n  if (goal ==\
    \ -1) return vector<T>();\n  vector<bool> negative(N, false);\n  for (int i =\
    \ 0; i < N; i++) {\n    for (auto &e : es) {\n      if (d[e.src] == INF) continue;\n\
    \      if (d[e.to] > d[e.src] + e.cost)\n        negative[e.to] = true, d[e.to]\
    \ = d[e.src] + e.cost;\n      if (negative[e.src] == true) negative[e.to] = true;\n\
    \    }\n  }\n\n  if (negative[goal] == true)\n    return vector<T>();\n  else\n\
    \    return d;\n}\n"
  code: "#pragma once\n\n\n\n#include \"../graph/graph-template.hpp\"\n\n// bellman-ford\u6CD5\
    \n// goal\u304C\u5B58\u5728\u3057\u306A\u3044\u3068\u304D-> \u8CA0\u9589\u8DEF\
    \u304C\u5B58\u5728\u3059\u308B\u3068\u304D\u306F\u7A7A\u5217\u3092\u8FD4\u3059\
    \n// goal\u304C\u5B58\u5728\u3059\u308B\u3068\u304D  -> start\u3068goal\u306E\u9593\
    \u306B\u8CA0\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u6642\u306B\u8CA0\u9589\
    \u8DEF\u3092\u8FD4\u3059\ntemplate <typename T>\nvector<T> bellman_ford(int N,\
    \ Edges<T> &es, int start = 0, int goal = -1) {\n  T INF = numeric_limits<T>::max()\
    \ / 2;\n  vector<T> d(N, INF);\n  d[start] = 0;\n  for (int i = 0; i < N; i++)\
    \ {\n    bool update = false;\n    for (auto &e : es) {\n      if (d[e.src] ==\
    \ INF) continue;\n      if (d[e.to] > d[e.src] + e.cost) {\n        update = true,\
    \ d[e.to] = d[e.src] + e.cost;\n      }\n    }\n    if (!update) return d;\n \
    \ }\n\n  if (goal == -1) return vector<T>();\n  vector<bool> negative(N, false);\n\
    \  for (int i = 0; i < N; i++) {\n    for (auto &e : es) {\n      if (d[e.src]\
    \ == INF) continue;\n      if (d[e.to] > d[e.src] + e.cost)\n        negative[e.to]\
    \ = true, d[e.to] = d[e.src] + e.cost;\n      if (negative[e.src] == true) negative[e.to]\
    \ = true;\n    }\n  }\n\n  if (negative[goal] == true)\n    return vector<T>();\n\
    \  else\n    return d;\n}"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: shortest-path/bellman-ford.hpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-1-b.test.cpp
documentation_of: shortest-path/bellman-ford.hpp
layout: document
redirect_from:
- /library/shortest-path/bellman-ford.hpp
- /library/shortest-path/bellman-ford.hpp.html
title: shortest-path/bellman-ford.hpp
---

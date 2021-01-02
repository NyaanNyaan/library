---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-0304.test.cpp
    title: verify/verify-aoj-other/aoj-0304.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u725B\u30B2\u30FC(\u6700\u77ED\u8DEF\u554F\u984C\u306E\u53CC\
      \u5BFE)"
    links: []
  bundledCode: "#line 2 \"shortest-path/dual-of-shortest-path.hpp\"\n\n#line 2 \"\
    graph/graph-template.hpp\"\n\ntemplate <typename T>\nstruct edge {\n  int src,\
    \ to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n\
    \  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}\n\n \
    \ edge &operator=(const int &x) {\n    to = x;\n    return *this;\n  }\n\n  operator\
    \ int() const { return to; }\n};\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\n\
    template <typename T>\nusing WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph\
    \ = vector<vector<int>>;\n\n// Input of (Unweighted) Graph\nUnweightedGraph graph(int\
    \ N, int M = -1, bool is_directed = false,\n                      bool is_1origin\
    \ = true) {\n  UnweightedGraph g(N);\n  if (M == -1) M = N - 1;\n  for (int _\
    \ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    if (is_1origin) x--,\
    \ y--;\n    g[x].push_back(y);\n    if (!is_directed) g[y].push_back(x);\n  }\n\
    \  return g;\n}\n\n// Input of Weighted Graph\ntemplate <typename T>\nWeightedGraph<T>\
    \ wgraph(int N, int M = -1, bool is_directed = false,\n                      \
    \  bool is_1origin = true) {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N -\
    \ 1;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n   \
    \ T c;\n    cin >> c;\n    if (is_1origin) x--, y--;\n    g[x].emplace_back(x,\
    \ y, c);\n    if (!is_directed) g[y].emplace_back(y, x, c);\n  }\n  return g;\n\
    }\n\n// Input of Edges\ntemplate <typename T>\nEdges<T> esgraph(int N, int M,\
    \ int is_weighted = true, bool is_1origin = true) {\n  Edges<T> es;\n  for (int\
    \ _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n\
    \      cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x,\
    \ y, c);\n  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename\
    \ T>\nvector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n\
    \                           bool is_directed = false, bool is_1origin = true)\
    \ {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y]\
    \ = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n#line 4 \"shortest-path/dual-of-shortest-path.hpp\"\
    \n\ntemplate <typename T>\nstruct Dual_of_Shortest_Path {\n  int N;\n  vector<vector<edge<T>>>\
    \ g;\n  T INF;\n  vector<T> d;\n\n  Dual_of_Shortest_Path(int _n)\n      : N(_n),\
    \ g(N), INF(numeric_limits<T>::max() / 2.1), d(N, INF) {}\n\n  // add constraint\
    \ f(j) <= f(i) + w\n  void add_edge(int i, int j, T c) { g[i].emplace_back(i,\
    \ j, c); }\n\n  // solve max{f(t) - f(s)} for each t\n  // if unsatisfiable, return\
    \ empty vector\n  vector<T> solve(int start = 0) {\n    d[start] = 0;\n    for\
    \ (int loop = 0; loop < N; ++loop) {\n      int upd = 0;\n      for (int i = 0;\
    \ i < N; ++i) {\n        for (auto& e : g[i]) {\n          if (d[i] + e.cost <\
    \ d[e.to]) {\n            d[e.to] = d[i] + e.cost;\n            upd = 1;\n   \
    \       }\n        }\n      }\n      if (!upd) break;\n      if (loop == N - 1)\
    \ return {};\n    }\n    return d;\n  }\n};\n\n/**\n * @brief \u725B\u30B2\u30FC\
    (\u6700\u77ED\u8DEF\u554F\u984C\u306E\u53CC\u5BFE)\n */\n"
  code: "#pragma once\n\n#include \"../graph/graph-template.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Dual_of_Shortest_Path {\n  int N;\n  vector<vector<edge<T>>> g;\n\
    \  T INF;\n  vector<T> d;\n\n  Dual_of_Shortest_Path(int _n)\n      : N(_n), g(N),\
    \ INF(numeric_limits<T>::max() / 2.1), d(N, INF) {}\n\n  // add constraint f(j)\
    \ <= f(i) + w\n  void add_edge(int i, int j, T c) { g[i].emplace_back(i, j, c);\
    \ }\n\n  // solve max{f(t) - f(s)} for each t\n  // if unsatisfiable, return empty\
    \ vector\n  vector<T> solve(int start = 0) {\n    d[start] = 0;\n    for (int\
    \ loop = 0; loop < N; ++loop) {\n      int upd = 0;\n      for (int i = 0; i <\
    \ N; ++i) {\n        for (auto& e : g[i]) {\n          if (d[i] + e.cost < d[e.to])\
    \ {\n            d[e.to] = d[i] + e.cost;\n            upd = 1;\n          }\n\
    \        }\n      }\n      if (!upd) break;\n      if (loop == N - 1) return {};\n\
    \    }\n    return d;\n  }\n};\n\n/**\n * @brief \u725B\u30B2\u30FC(\u6700\u77ED\
    \u8DEF\u554F\u984C\u306E\u53CC\u5BFE)\n */\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: shortest-path/dual-of-shortest-path.hpp
  requiredBy: []
  timestamp: '2021-01-02 17:08:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-0304.test.cpp
documentation_of: shortest-path/dual-of-shortest-path.hpp
layout: document
redirect_from:
- /library/shortest-path/dual-of-shortest-path.hpp
- /library/shortest-path/dual-of-shortest-path.hpp.html
title: "\u725B\u30B2\u30FC(\u6700\u77ED\u8DEF\u554F\u984C\u306E\u53CC\u5BFE)"
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-1-a.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/dijkstra.test.cpp
    title: verify/verify-unit-test/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/shortest-path/dijkstra.md
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
    links: []
  bundledCode: "#line 2 \"shortest-path/dijkstra.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"graph/graph-template.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n\
    \  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int _src,\
    \ int _to, T _cost) : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const\
    \ int &x) {\n    to = x;\n    return *this;\n  }\n\n  operator int() const { return\
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
    \ d;\n}\n#line 6 \"shortest-path/dijkstra.hpp\"\n\n// unreachable -> -1\ntemplate\
    \ <typename T>\nvector<T> dijkstra(WeightedGraph<T> &g, int start = 0) {\n  using\
    \ P = pair<T, int>;\n  int N = (int)g.size();\n  vector<T> d(N, T(-1));\n  priority_queue<P,\
    \ vector<P>, greater<P> > Q;\n  d[start] = 0;\n  Q.emplace(0, start);\n  while\
    \ (!Q.empty()) {\n    P p = Q.top();\n    Q.pop();\n    int cur = p.second;\n\
    \    if (d[cur] < p.first) continue;\n    for (auto dst : g[cur]) {\n      if\
    \ (d[dst] == T(-1) || d[cur] + dst.cost < d[dst]) {\n        d[dst] = d[cur] +\
    \ dst.cost;\n        Q.emplace(d[dst], dst);\n      }\n    }\n  }\n  return d;\n\
    }\n\n/*\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @docs docs/shortest-path/dijkstra.md\n\
    **/\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../graph/graph-template.hpp\"\n\n// unreachable -> -1\ntemplate <typename\
    \ T>\nvector<T> dijkstra(WeightedGraph<T> &g, int start = 0) {\n  using P = pair<T,\
    \ int>;\n  int N = (int)g.size();\n  vector<T> d(N, T(-1));\n  priority_queue<P,\
    \ vector<P>, greater<P> > Q;\n  d[start] = 0;\n  Q.emplace(0, start);\n  while\
    \ (!Q.empty()) {\n    P p = Q.top();\n    Q.pop();\n    int cur = p.second;\n\
    \    if (d[cur] < p.first) continue;\n    for (auto dst : g[cur]) {\n      if\
    \ (d[dst] == T(-1) || d[cur] + dst.cost < d[dst]) {\n        d[dst] = d[cur] +\
    \ dst.cost;\n        Q.emplace(d[dst], dst);\n      }\n    }\n  }\n  return d;\n\
    }\n\n/*\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @docs docs/shortest-path/dijkstra.md\n\
    **/\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: shortest-path/dijkstra.hpp
  requiredBy: []
  timestamp: '2020-11-26 01:55:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp
  - verify/verify-unit-test/dijkstra.test.cpp
  - verify/verify-aoj-grl/aoj-grl-1-a.test.cpp
documentation_of: shortest-path/dijkstra.hpp
layout: document
redirect_from:
- /library/shortest-path/dijkstra.hpp
- /library/shortest-path/dijkstra.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---
## ダイクストラ法

ダイクストラ法を$\mathrm{O}(E \log V)$で行うライブラリ。

#### 概要

ダイクストラ法とは負辺の無い有向グラフでの単一始点最短経路を$\mathrm{O}(E \log V)$で計算するアルゴリズムである。[基数ヒープ](https://nyaannyaan.github.io/library/shortest-path/dijkstra-radix-heap.hpp)やフィボナッチヒープを用いた高速化も知られている。

#### 使い方

- `dijkstra(g, start = 0)`: sを始点としたダイクストラ法を行い、sからの距離(到達できない場合`-1`)が格納された配列を返す。

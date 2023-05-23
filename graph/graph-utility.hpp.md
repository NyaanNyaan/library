---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: shortest-path/restore-shortest-path.hpp
    title: shortest-path/restore-shortest-path.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-a.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-diameter.test.cpp
    title: verify/verify-yosupo-graph/yosupo-diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp
    title: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-strongly-connected-components.test.cpp
    title: verify/verify-yosupo-graph/yosupo-strongly-connected-components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/graph-utility.md
    document_title: "\u30B0\u30E9\u30D5\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\u30A3"
    links: []
  bundledCode: "#line 2 \"graph/graph-utility.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
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
    \ c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 4 \"graph/graph-utility.hpp\"\n\n// \u4E00\u822C\u306E\u30B0\u30E9\
    \u30D5\u306Est\u304B\u3089\u306E\u8DDD\u96E2\uFF01\uFF01\uFF01\uFF01\n// unvisited\
    \ nodes : d = -1\nvector<int> Depth(const UnweightedGraph &g, int start = 0) {\n\
    \  int n = g.size();\n  vector<int> ds(n, -1);\n  ds[start] = 0;\n  queue<int>\
    \ q;\n  q.push(start);\n  while (!q.empty()) {\n    int c = q.front();\n    q.pop();\n\
    \    int dc = ds[c];\n    for (auto &d : g[c]) {\n      if (ds[d] == -1) {\n \
    \       ds[d] = dc + 1;\n        q.push(d);\n      }\n    }\n  }\n  return ds;\n\
    }\n\n// Depth of Rooted Weighted Tree\n// unvisited nodes : d = -1\ntemplate <typename\
    \ T>\nvector<T> Depth(const WeightedGraph<T> &g, int start = 0) {\n  vector<T>\
    \ d(g.size(), -1);\n  auto dfs = [&](auto rec, int cur, T val, int par = -1) ->\
    \ void {\n    d[cur] = val;\n    for (auto &dst : g[cur]) {\n      if (dst ==\
    \ par) continue;\n      rec(rec, dst, val + dst.cost, cur);\n    }\n  };\n  dfs(dfs,\
    \ start, 0);\n  return d;\n}\n\n// Diameter of Tree\n// return value : { {u, v},\
    \ length }\npair<pair<int, int>, int> Diameter(const UnweightedGraph &g) {\n \
    \ auto d = Depth(g, 0);\n  int u = max_element(begin(d), end(d)) - begin(d);\n\
    \  d = Depth(g, u);\n  int v = max_element(begin(d), end(d)) - begin(d);\n  return\
    \ make_pair(make_pair(u, v), d[v]);\n}\n\n// Diameter of Weighted Tree\n// return\
    \ value : { {u, v}, length }\ntemplate <typename T>\npair<pair<int, int>, T> Diameter(const\
    \ WeightedGraph<T> &g) {\n  auto d = Depth(g, 0);\n  int u = max_element(begin(d),\
    \ end(d)) - begin(d);\n  d = Depth(g, u);\n  int v = max_element(begin(d), end(d))\
    \ - begin(d);\n  return make_pair(make_pair(u, v), d[v]);\n}\n\n// nodes on the\
    \ path u-v ( O(N) )\ntemplate <typename G>\nvector<int> Path(G &g, int u, int\
    \ v) {\n  vector<int> ret;\n  int end = 0;\n  auto dfs = [&](auto rec, int cur,\
    \ int par = -1) -> void {\n    ret.push_back(cur);\n    if (cur == v) {\n    \
    \  end = 1;\n      return;\n    }\n    for (int dst : g[cur]) {\n      if (dst\
    \ == par) continue;\n      rec(rec, dst, cur);\n      if (end) return;\n    }\n\
    \    if (end) return;\n    ret.pop_back();\n  };\n  dfs(dfs, u);\n  return ret;\n\
    }\n\n/**\n * @brief \u30B0\u30E9\u30D5\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\u30A3\
    \n * @docs docs/graph/graph-utility.md\n */\n"
  code: "#pragma once\n\n#include \"./graph-template.hpp\"\n\n// \u4E00\u822C\u306E\
    \u30B0\u30E9\u30D5\u306Est\u304B\u3089\u306E\u8DDD\u96E2\uFF01\uFF01\uFF01\uFF01\
    \n// unvisited nodes : d = -1\nvector<int> Depth(const UnweightedGraph &g, int\
    \ start = 0) {\n  int n = g.size();\n  vector<int> ds(n, -1);\n  ds[start] = 0;\n\
    \  queue<int> q;\n  q.push(start);\n  while (!q.empty()) {\n    int c = q.front();\n\
    \    q.pop();\n    int dc = ds[c];\n    for (auto &d : g[c]) {\n      if (ds[d]\
    \ == -1) {\n        ds[d] = dc + 1;\n        q.push(d);\n      }\n    }\n  }\n\
    \  return ds;\n}\n\n// Depth of Rooted Weighted Tree\n// unvisited nodes : d =\
    \ -1\ntemplate <typename T>\nvector<T> Depth(const WeightedGraph<T> &g, int start\
    \ = 0) {\n  vector<T> d(g.size(), -1);\n  auto dfs = [&](auto rec, int cur, T\
    \ val, int par = -1) -> void {\n    d[cur] = val;\n    for (auto &dst : g[cur])\
    \ {\n      if (dst == par) continue;\n      rec(rec, dst, val + dst.cost, cur);\n\
    \    }\n  };\n  dfs(dfs, start, 0);\n  return d;\n}\n\n// Diameter of Tree\n//\
    \ return value : { {u, v}, length }\npair<pair<int, int>, int> Diameter(const\
    \ UnweightedGraph &g) {\n  auto d = Depth(g, 0);\n  int u = max_element(begin(d),\
    \ end(d)) - begin(d);\n  d = Depth(g, u);\n  int v = max_element(begin(d), end(d))\
    \ - begin(d);\n  return make_pair(make_pair(u, v), d[v]);\n}\n\n// Diameter of\
    \ Weighted Tree\n// return value : { {u, v}, length }\ntemplate <typename T>\n\
    pair<pair<int, int>, T> Diameter(const WeightedGraph<T> &g) {\n  auto d = Depth(g,\
    \ 0);\n  int u = max_element(begin(d), end(d)) - begin(d);\n  d = Depth(g, u);\n\
    \  int v = max_element(begin(d), end(d)) - begin(d);\n  return make_pair(make_pair(u,\
    \ v), d[v]);\n}\n\n// nodes on the path u-v ( O(N) )\ntemplate <typename G>\n\
    vector<int> Path(G &g, int u, int v) {\n  vector<int> ret;\n  int end = 0;\n \
    \ auto dfs = [&](auto rec, int cur, int par = -1) -> void {\n    ret.push_back(cur);\n\
    \    if (cur == v) {\n      end = 1;\n      return;\n    }\n    for (int dst :\
    \ g[cur]) {\n      if (dst == par) continue;\n      rec(rec, dst, cur);\n    \
    \  if (end) return;\n    }\n    if (end) return;\n    ret.pop_back();\n  };\n\
    \  dfs(dfs, u);\n  return ret;\n}\n\n/**\n * @brief \u30B0\u30E9\u30D5\u30E6\u30FC\
    \u30C6\u30A3\u30EA\u30C6\u30A3\n * @docs docs/graph/graph-utility.md\n */\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/graph-utility.hpp
  requiredBy:
  - shortest-path/restore-shortest-path.hpp
  timestamp: '2021-11-23 10:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-shortest-path-dijkstra-abstruct.test.cpp
  - verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp
  - verify/verify-yosupo-graph/yosupo-diameter.test.cpp
  - verify/verify-yosupo-graph/yosupo-strongly-connected-components.test.cpp
  - verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-a.test.cpp
documentation_of: graph/graph-utility.hpp
layout: document
redirect_from:
- /library/graph/graph-utility.hpp
- /library/graph/graph-utility.hpp.html
title: "\u30B0\u30E9\u30D5\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\u30A3"
---
## グラフユーティリティ

### 概要

与えられたグラフgに関して計算を行う。グラフの頂点数を$N$とする。

グラフのデータ型はグラフテンプレート(graph-template.hpp)で定義されている。

### 使い方

- `vector<int> Depth(const UnweightedGraph &g, int start = 0)`:

  返り値の$i$番の要素は、頂点$\mathrm{start}$から頂点$i$までの最短パスの長さ。最短パスがない場合は$-1$とする。計算量$\mathrm{O}(N)$

- `vector<T> Depth<T>(WeightedGraph<T> g, int start = 0)`:

  グラフ$g$は根付き木でなくてはならない。
  
  返り値の$i$番の要素は、頂点startから頂点$i$までの最短パスの長さ。パスがない場合は$-1$を返す。計算量$\mathrm{O}(N)$

- `pair<pair<int, int>, int> Diameter(const UnweightedGraph &g)` , `pair<pair<int, int>, T> Diameter<T>(const WeightedGraph<T> &g)`

  グラフ$g$は木でなくてはならない。

  木の直径の長さを$d$、両端の頂点を$u,v$として$((u,v),d)$を返す。計算量$\mathrm{O}(N)$

- `vector<int> Path<G>(G &g, int u, int v)`:

  型`G`は`UnweightedGraph`または`WeightedGraph<T>`で、グラフは木でなくてはならない。
  
  頂点$u$から$v$に至るパスが通る頂点($u$,$v$を含む)の列を返す。計算量$\mathrm{O}(N)$

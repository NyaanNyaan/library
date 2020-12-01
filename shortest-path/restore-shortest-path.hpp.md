---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graph-utility.hpp
    title: graph/graph-utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"shortest-path/restore-shortest-path.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"graph/graph-utility.hpp\"\nusing namespace std;\n\
    \n#line 3 \"graph/graph-template.hpp\"\nusing namespace std;\n\ntemplate <typename\
    \ T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1),\
    \ to(_to), cost(_cost) {}\n  edge(int _src, int _to, T _cost) : src(_src), to(_to),\
    \ cost(_cost) {}\n\n  edge &operator=(const int &x) {\n    to = x;\n    return\
    \ *this;\n  }\n\n  operator int() const { return to; }\n};\ntemplate <typename\
    \ T>\nusing Edges = vector<edge<T>>;\ntemplate <typename T>\nusing WeightedGraph\
    \ = vector<Edges<T>>;\nusing UnweightedGraph = vector<vector<int>>;\n\n// Input\
    \ of (Unweighted) Graph\nUnweightedGraph graph(int N, int M = -1, bool is_directed\
    \ = false,\n                      bool is_1origin = true) {\n  UnweightedGraph\
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
    \ d;\n}\n#line 6 \"graph/graph-utility.hpp\"\n\n// Depth of Rooted Tree\n// unvisited\
    \ nodes : d = -1\nvector<int> Depth(const UnweightedGraph &g, int start = 0) {\n\
    \  vector<int> d(g.size(), -1);\n  auto dfs = [&](auto rec, int cur, int par =\
    \ -1) -> void {\n    d[cur] = par == -1 ? 0 : d[par] + 1;\n    for (auto &dst\
    \ : g[cur]) {\n      if (dst == par) continue;\n      rec(rec, dst, cur);\n  \
    \  }\n  };\n  dfs(dfs, start);\n  return d;\n}\n\n// Depth of Rooted Weighted\
    \ Tree\n// unvisited nodes : d = -1\ntemplate <typename T>\nvector<T> Depth(const\
    \ WeightedGraph<T> &g, int start = 0) {\n  vector<T> d(g.size(), -1);\n  auto\
    \ dfs = [&](auto rec, int cur, T val, int par = -1) -> void {\n    d[cur] = val;\n\
    \    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n      rec(rec,\
    \ dst, val + dst.cost, cur);\n    }\n  };\n  dfs(dfs, start, 0);\n  return d;\n\
    }\n\n// Diameter of Tree\n// return value : { {u, v}, length }\npair<pair<int,\
    \ int>, int> Diameter(const UnweightedGraph &g) {\n  auto d = Depth(g, 0);\n \
    \ int u = max_element(begin(d), end(d)) - begin(d);\n  d = Depth(g, u);\n  int\
    \ v = max_element(begin(d), end(d)) - begin(d);\n  return make_pair(make_pair(u,\
    \ v), d[v]);\n}\n\n// Diameter of Weighted Tree\n// return value : { {u, v}, length\
    \ }\ntemplate <typename T>\npair<pair<int, int>, T> Diameter(const WeightedGraph<T>\
    \ &g) {\n  auto d = Depth(g, 0);\n  int u = max_element(begin(d), end(d)) - begin(d);\n\
    \  d = Depth(g, u);\n  int v = max_element(begin(d), end(d)) - begin(d);\n  return\
    \ make_pair(make_pair(u, v), d[v]);\n}\n\n// nodes on the path u-v ( O(N) )\n\
    template <typename G>\nvector<int> Path(G &g, int u, int v) {\n  vi ret;\n  int\
    \ end = 0;\n  auto dfs = [&](auto rec, int cur, int par = -1) -> void {\n    ret.push_back(cur);\n\
    \    if (cur == v) {\n      end = 1;\n      return;\n    }\n    for (int dst :\
    \ g[cur]) {\n      if (dst == par) continue;\n      rec(rec, dst, cur);\n    \
    \  if (end) return;\n    }\n    if (end) return;\n    ret.pop_back();\n  };\n\
    \  dfs(dfs, u);\n  return ret;\n}\n#line 6 \"shortest-path/restore-shortest-path.hpp\"\
    \n\n// restore shortest path from S to G\ntemplate <typename T>\nvector<int> restore_shortest_path(WeightedGraph<T>\
    \ &g, vector<T> &d, int S,\n                                  int G) {\n  int\
    \ N = g.size();\n  WeightedGraph<T> rev(g.size());\n  for (int i = 0; i < N; i++)\n\
    \    for (auto &e : g[i]) rev[e.to].emplace_back(e.to, i, e.cost);\n  vector<int>\
    \ ret;\n  ret.push_back(G);\n  int p = G;\n  T dist = d[G];\n  vector<int> vis(N,\
    \ 0);\n  vis[G] = 1;\n  do {\n    int nxt = -1;\n    T nval = numeric_limits<T>::max()\
    \ / 2;\n    for (auto &e : rev[p]) {\n      if (vis[e.to] || d[e.to] + e.cost\
    \ != dist) continue;\n      if (d[e.to] < nval) nval = d[e.to], nxt = e.to;\n\
    \    }\n    ret.push_back((vis[nxt] = 1, dist = nval, p = nxt));\n  } while (p\
    \ != S);\n  reverse(begin(ret), end(ret));\n  return ret;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../graph/graph-utility.hpp\"\n\n// restore shortest path from S to G\ntemplate\
    \ <typename T>\nvector<int> restore_shortest_path(WeightedGraph<T> &g, vector<T>\
    \ &d, int S,\n                                  int G) {\n  int N = g.size();\n\
    \  WeightedGraph<T> rev(g.size());\n  for (int i = 0; i < N; i++)\n    for (auto\
    \ &e : g[i]) rev[e.to].emplace_back(e.to, i, e.cost);\n  vector<int> ret;\n  ret.push_back(G);\n\
    \  int p = G;\n  T dist = d[G];\n  vector<int> vis(N, 0);\n  vis[G] = 1;\n  do\
    \ {\n    int nxt = -1;\n    T nval = numeric_limits<T>::max() / 2;\n    for (auto\
    \ &e : rev[p]) {\n      if (vis[e.to] || d[e.to] + e.cost != dist) continue;\n\
    \      if (d[e.to] < nval) nval = d[e.to], nxt = e.to;\n    }\n    ret.push_back((vis[nxt]\
    \ = 1, dist = nval, p = nxt));\n  } while (p != S);\n  reverse(begin(ret), end(ret));\n\
    \  return ret;\n}"
  dependsOn:
  - graph/graph-utility.hpp
  - graph/graph-template.hpp
  isVerificationFile: false
  path: shortest-path/restore-shortest-path.hpp
  requiredBy: []
  timestamp: '2020-11-24 16:37:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp
documentation_of: shortest-path/restore-shortest-path.hpp
layout: document
redirect_from:
- /library/shortest-path/restore-shortest-path.hpp
- /library/shortest-path/restore-shortest-path.hpp.html
title: shortest-path/restore-shortest-path.hpp
---

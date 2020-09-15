---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"graph/dimension-expanded-graph.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"graph/graph-template.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n\
    \  edge(int to, T cost) : src(-1), to(to), cost(cost) {}\n  edge(int src, int\
    \ to, T cost) : src(src), to(to), cost(cost) {}\n\n  edge &operator=(const int\
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
    \ d;\n}\n#line 6 \"graph/dimension-expanded-graph.hpp\"\n\ntemplate <int DIM>\n\
    struct DimensionExpandedGraph {\n  using i64 = long long;\n  using A = array<int,\
    \ DIM>;\n\n  int N;\n  A g_size, coeff;\n\n  template <typename... T>\n  DimensionExpandedGraph(const\
    \ T &... t) : N(1), g_size({t...}) {\n    set_coeff();\n  }\n\n  void set_coeff()\
    \ {\n    coeff.fill(1);\n    for (int i = 0; i < DIM; i++) {\n      for (int j\
    \ = 0; j < i; j++) coeff[j] *= g_size[i];\n      N *= g_size[i];\n    }\n  }\n\
    \n  int id(const A &a) {\n    int ret = 0;\n    for (int i = 0; i < DIM; i++)\
    \ ret += a[i] * coeff[i];\n    return ret;\n  }\n\n  int id_(int, int n) { return\
    \ n; }\n  template <typename T, typename... U>\n  int id_(int idx, int n, T &&t,\
    \ U &&... u) {\n    n += coeff[idx++] * t;\n    return id_(idx, n, forward<U>(u)...);\n\
    \  }\n  template <typename... T>\n  int id(const T &... t) {\n    return id_(0,\
    \ 0, t...);\n  }\n\n  int ok(const A &a) {\n    for (int i = 0; i < DIM; i++)\n\
    \      if (a[i] < 0 or g_size[i] <= a[i]) return 0;\n    return 1;\n  }\n\n  int\
    \ ok_(int) { return 1; }\n  template <typename T, typename... U>\n  int ok_(int\
    \ idx, T &&t, U &&... u) {\n    if (t < 0 or g_size[idx++] <= t) return 0;\n \
    \   return ok_(idx, forward<U>(u)...);\n  }\n  template <typename... T>\n  int\
    \ ok(const T &... t) {\n    return ok_(0, t...);\n  }\n\n  template <typename\
    \ F>\n  vector<i64> bfs(F f, A s = {}) {\n    vector<i64> dist(N, -1);\n    queue<A>\
    \ Q;\n    dist[id(s)] = 0;\n    Q.push(s);\n    while (!Q.empty()) {\n      A\
    \ c = Q.front();\n      Q.pop();\n      f(c, [&](A d) {\n        if (dist[id(d)]\
    \ == -1) {\n          dist[id(d)] = dist[id(c)] + 1;\n          Q.push(d);\n \
    \       }\n      });\n    }\n    return dist;\n  }\n\n  template <typename F>\n\
    \  vector<i64> bfs01(F f, A s = {}) {\n    vector<i64> dist(N, -1);\n    deque<A>\
    \ Q;\n    dist[id(s)] = 0;\n    Q.push_back(s);\n    while (!Q.empty()) {\n  \
    \    A c = Q.front();\n      Q.pop_front();\n      f(c, [&](A d, i64 w) {\n  \
    \      if (dist[id(d)] == -1) {\n          dist[id(d)] = dist[id(c)] + w;\n  \
    \        if (w == 0)\n            Q.push_front(d);\n          else\n         \
    \   Q.push_back(d);\n        }\n      });\n    }\n    return dist;\n  }\n\n  template\
    \ <typename F>\n  vector<i64> dijkstra(F f, A s = {}) {\n    vector<i64> dist(N,\
    \ -1);\n    using P = pair<i64, A>;\n    priority_queue<P, vector<P>, greater<P>>\
    \ Q;\n    Q.emplace(dist[id(s)] = 0, s);\n    while (!Q.empty()) {\n      i64\
    \ d;\n      A c;\n      tie(d, c) = Q.top();\n      Q.pop();\n      if (dist[id(c)]\
    \ < d) continue;\n      f(c, [&](A d, i64 w) {\n        if (dist[id(d)] == -1\
    \ or dist[id(d)] > dist[id(c)] + w) {\n          Q.emplace(dist[id(d)] = dist[id(c)]\
    \ + w, d);\n        }\n      });\n    }\n    return dist;\n  }\n};\n\nstruct GridGraph\
    \ : DimensionExpandedGraph<2> {\n  vector<string> str;\n  char ng;\n  int is_8_direction;\n\
    \n  template <typename... T>\n  GridGraph(const T &... t) : ng('#'), is_8_direction(false)\
    \ {\n    N = 1;\n    g_size = A({t...});\n    set_coeff();\n  }\n\n  operator\
    \ vector<string> &() { return str; }\n\n  template <typename F>\n  void adjacent(pair<int,int>\
    \ c, F f) {\n    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};\n    int dy[] = {0, 1,\
    \ 0, -1, 1, -1, 1, -1};\n    int i, j;\n    tie(i, j) = c;\n    for (int k = 0;\
    \ k < is_8_direction ? 8 : 4; k++) {\n      int di = i + dx[k], dj = dy[k];\n\
    \      if (ok(di, dj) and str[di][dj] != ng) f(di, dj);\n    }\n  }\n\n  template\
    \ <typename F>\n  vector<i64> bfs(F f, A s = {}){\n    vector<i64> dist(N, -1);\n\
    \    queue<A> Q;\n    dist[id(s)] = 0;\n    Q.push(s);\n    while (!Q.empty())\
    \ {\n      A c = Q.front();\n      Q.pop();\n      adjacent(c, [&](A d) {\n  \
    \      if (dist[id(d)] == -1) {\n          dist[id(d)] = dist[id(c)] + 1;\n  \
    \        Q.push(d);\n        }\n      });\n    }\n    return dist;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"./graph-template.hpp\"\n\ntemplate <int DIM>\nstruct DimensionExpandedGraph\
    \ {\n  using i64 = long long;\n  using A = array<int, DIM>;\n\n  int N;\n  A g_size,\
    \ coeff;\n\n  template <typename... T>\n  DimensionExpandedGraph(const T &...\
    \ t) : N(1), g_size({t...}) {\n    set_coeff();\n  }\n\n  void set_coeff() {\n\
    \    coeff.fill(1);\n    for (int i = 0; i < DIM; i++) {\n      for (int j = 0;\
    \ j < i; j++) coeff[j] *= g_size[i];\n      N *= g_size[i];\n    }\n  }\n\n  int\
    \ id(const A &a) {\n    int ret = 0;\n    for (int i = 0; i < DIM; i++) ret +=\
    \ a[i] * coeff[i];\n    return ret;\n  }\n\n  int id_(int, int n) { return n;\
    \ }\n  template <typename T, typename... U>\n  int id_(int idx, int n, T &&t,\
    \ U &&... u) {\n    n += coeff[idx++] * t;\n    return id_(idx, n, forward<U>(u)...);\n\
    \  }\n  template <typename... T>\n  int id(const T &... t) {\n    return id_(0,\
    \ 0, t...);\n  }\n\n  int ok(const A &a) {\n    for (int i = 0; i < DIM; i++)\n\
    \      if (a[i] < 0 or g_size[i] <= a[i]) return 0;\n    return 1;\n  }\n\n  int\
    \ ok_(int) { return 1; }\n  template <typename T, typename... U>\n  int ok_(int\
    \ idx, T &&t, U &&... u) {\n    if (t < 0 or g_size[idx++] <= t) return 0;\n \
    \   return ok_(idx, forward<U>(u)...);\n  }\n  template <typename... T>\n  int\
    \ ok(const T &... t) {\n    return ok_(0, t...);\n  }\n\n  template <typename\
    \ F>\n  vector<i64> bfs(F f, A s = {}) {\n    vector<i64> dist(N, -1);\n    queue<A>\
    \ Q;\n    dist[id(s)] = 0;\n    Q.push(s);\n    while (!Q.empty()) {\n      A\
    \ c = Q.front();\n      Q.pop();\n      f(c, [&](A d) {\n        if (dist[id(d)]\
    \ == -1) {\n          dist[id(d)] = dist[id(c)] + 1;\n          Q.push(d);\n \
    \       }\n      });\n    }\n    return dist;\n  }\n\n  template <typename F>\n\
    \  vector<i64> bfs01(F f, A s = {}) {\n    vector<i64> dist(N, -1);\n    deque<A>\
    \ Q;\n    dist[id(s)] = 0;\n    Q.push_back(s);\n    while (!Q.empty()) {\n  \
    \    A c = Q.front();\n      Q.pop_front();\n      f(c, [&](A d, i64 w) {\n  \
    \      if (dist[id(d)] == -1) {\n          dist[id(d)] = dist[id(c)] + w;\n  \
    \        if (w == 0)\n            Q.push_front(d);\n          else\n         \
    \   Q.push_back(d);\n        }\n      });\n    }\n    return dist;\n  }\n\n  template\
    \ <typename F>\n  vector<i64> dijkstra(F f, A s = {}) {\n    vector<i64> dist(N,\
    \ -1);\n    using P = pair<i64, A>;\n    priority_queue<P, vector<P>, greater<P>>\
    \ Q;\n    Q.emplace(dist[id(s)] = 0, s);\n    while (!Q.empty()) {\n      i64\
    \ d;\n      A c;\n      tie(d, c) = Q.top();\n      Q.pop();\n      if (dist[id(c)]\
    \ < d) continue;\n      f(c, [&](A d, i64 w) {\n        if (dist[id(d)] == -1\
    \ or dist[id(d)] > dist[id(c)] + w) {\n          Q.emplace(dist[id(d)] = dist[id(c)]\
    \ + w, d);\n        }\n      });\n    }\n    return dist;\n  }\n};\n\nstruct GridGraph\
    \ : DimensionExpandedGraph<2> {\n  vector<string> str;\n  char ng;\n  int is_8_direction;\n\
    \n  template <typename... T>\n  GridGraph(const T &... t) : ng('#'), is_8_direction(false)\
    \ {\n    N = 1;\n    g_size = A({t...});\n    set_coeff();\n  }\n\n  operator\
    \ vector<string> &() { return str; }\n\n  template <typename F>\n  void adjacent(pair<int,int>\
    \ c, F f) {\n    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};\n    int dy[] = {0, 1,\
    \ 0, -1, 1, -1, 1, -1};\n    int i, j;\n    tie(i, j) = c;\n    for (int k = 0;\
    \ k < is_8_direction ? 8 : 4; k++) {\n      int di = i + dx[k], dj = dy[k];\n\
    \      if (ok(di, dj) and str[di][dj] != ng) f(di, dj);\n    }\n  }\n\n  template\
    \ <typename F>\n  vector<i64> bfs(F f, A s = {}){\n    vector<i64> dist(N, -1);\n\
    \    queue<A> Q;\n    dist[id(s)] = 0;\n    Q.push(s);\n    while (!Q.empty())\
    \ {\n      A c = Q.front();\n      Q.pop();\n      adjacent(c, [&](A d) {\n  \
    \      if (dist[id(d)] == -1) {\n          dist[id(d)] = dist[id(c)] + 1;\n  \
    \        Q.push(d);\n        }\n      });\n    }\n    return dist;\n  }\n};"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/dimension-expanded-graph.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dimension-expanded-graph.hpp
layout: document
redirect_from:
- /library/graph/dimension-expanded-graph.hpp
- /library/graph/dimension-expanded-graph.hpp.html
title: graph/dimension-expanded-graph.hpp
---

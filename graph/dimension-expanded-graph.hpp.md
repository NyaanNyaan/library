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
    \ d;\n}\n#line 6 \"graph/dimension-expanded-graph.hpp\"\n\ntemplate <int64_t DIM>\n\
    struct DimensionExpandedGraph {\n  using i64 = long long;\n  using A = array<i64,\
    \ DIM>;\n\n  i64 N;\n  A g_size, coeff;\n\n  template <typename... T>\n  DimensionExpandedGraph(const\
    \ T &... t) : N(1), g_size({t...}) {\n    set_coeff();\n  }\n\n  void set_coeff()\
    \ {\n    coeff.fill(1);\n    for (i64 i = 0; i < DIM; i++) {\n      assert(g_size[i]\
    \ != 0);\n      for (i64 j = 0; j < i; j++) coeff[j] *= g_size[i];\n      N *=\
    \ g_size[i];\n    }\n  }\n\n  i64 operator()(const A &a) {\n    i64 ret = 0;\n\
    \    for (i64 i = 0; i < DIM; i++) {\n      if (a[i] < 0 or g_size[i] <= a[i])\
    \ return -1;\n      ret += a[i] * coeff[i];\n    }\n    return ret;\n  }\n\n \
    \ A inv(i64 n) {\n    A ret{};\n    for (i64 i = 0; i < DIM; i++) {\n      ret[i]\
    \ = n / coeff[i];\n      n %= coeff[i];\n    }\n    return ret;\n  }\n\n  i64\
    \ inner_id(i64, i64 n) { return n; }\n  template <typename T, typename... U>\n\
    \  i64 inner_id(i64 i, i64 n, T &&t, U &&... u) {\n    if (t < 0 or g_size[i]\
    \ <= t) return -1;\n    n += coeff[i++] * t;\n    return inner_id(i, n, forward<U>(u)...);\n\
    \  }\n  template <typename... T>\n  i64 operator()(const T &... t) {\n    return\
    \ inner_id(0, 0, t...);\n  }\n\n  i64 ok(const A &a) {\n    for (i64 i = 0; i\
    \ < DIM; i++)\n      if (a[i] < 0 or g_size[i] <= a[i]) return 0;\n    return\
    \ 1;\n  }\n\n  i64 inner_ok(i64) { return 1; }\n  template <typename T, typename...\
    \ U>\n  i64 inner_ok(i64 idx, T &&t, U &&... u) {\n    if (t < 0 or g_size[idx++]\
    \ <= t) return 0;\n    return inner_ok(idx, forward<U>(u)...);\n  }\n  template\
    \ <typename... T>\n  i64 ok(const T &... t) {\n    return inner_ok(0, t...);\n\
    \  }\n\n  template <typename F>\n  vector<i64> bfs(F f, A s = {}) {\n    vector<i64>\
    \ dist(N, -1);\n    queue<A> Q;\n    assert((*this)(s) != -1);\n    dist[(*this)(s)]\
    \ = 0;\n    Q.push(s);\n    while (!Q.empty()) {\n      A c = Q.front();\n   \
    \   Q.pop();\n      i64 idc = (*this)(c);\n      f(c, [&](A d) {\n        i64\
    \ idd = (*this)(d);\n        if (idd == -1) return;\n        if (dist[idd] ==\
    \ -1) {\n          dist[idd] = dist[idc] + 1;\n          Q.push(d);\n        }\n\
    \      });\n    }\n    return dist;\n  }\n\n  template <typename F>\n  vector<i64>\
    \ bfs01(F f, A s = {}) {\n    vector<i64> dist(N, -1);\n    vector<bool> vis(N,\
    \ 0);\n    deque<A> Q;\n    assert((*this)(s) != -1);\n    dist[(*this)(s)] =\
    \ 0;\n    Q.push_back(s);\n    while (!Q.empty()) {\n      A c = Q.front();\n\
    \      Q.pop_front();\n      i64 idc = (*this)(c);\n      if (vis[idc]) continue;\n\
    \      vis[idc] = true;\n      i64 dc = dist[idc];\n      f(c, [&](A d, i64 w)\
    \ {\n        i64 idd = (*this)(d);\n        if (idd == -1) return;\n        i64\
    \ dd = dist[idd];\n        if (dd == -1 || dc + w < dd) {\n          dist[idd]\
    \ = dc + w;\n          if (w == 0)\n            Q.push_front(d);\n          else\n\
    \            Q.push_back(d);\n        }\n      });\n    }\n    return dist;\n\
    \  }\n\n  vector<i64> dijkstra(function<void(A, function<void(A, i64)>)> f, A\
    \ s = {}) {\n    vector<i64> dist(N, -1);\n    using P = pair<i64, A>;\n    priority_queue<P,\
    \ vector<P>, greater<P>> Q;\n    assert((*this)(s) != -1);\n    Q.emplace(dist[(*this)(s)]\
    \ = 0, s);\n    while (!Q.empty()) {\n      i64 dc;\n      A c;\n      tie(dc,\
    \ c) = Q.top();\n      Q.pop();\n      i64 idc = (*this)(c);\n      if (dist[idc]\
    \ < dc) continue;\n      f(c, [&](const A &d, i64 w) {\n        i64 idd = (*this)(d);\n\
    \        if (idd == -1) return;\n        i64 dd = dist[idd];\n        if (dd ==\
    \ -1 || dd > dc + w) {\n          dist[idd] = dc + w;\n          Q.emplace(dc\
    \ + w, d);\n        }\n      });\n    }\n    return dist;\n  }\n\n  static vector<array<i64,\
    \ 2>> direction4() {\n    return {{{1, 0}}, {{0, 1}}, {{-1, 0}}, {{0, -1}}};\n\
    \  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"./graph-template.hpp\"\n\ntemplate <int64_t DIM>\nstruct DimensionExpandedGraph\
    \ {\n  using i64 = long long;\n  using A = array<i64, DIM>;\n\n  i64 N;\n  A g_size,\
    \ coeff;\n\n  template <typename... T>\n  DimensionExpandedGraph(const T &...\
    \ t) : N(1), g_size({t...}) {\n    set_coeff();\n  }\n\n  void set_coeff() {\n\
    \    coeff.fill(1);\n    for (i64 i = 0; i < DIM; i++) {\n      assert(g_size[i]\
    \ != 0);\n      for (i64 j = 0; j < i; j++) coeff[j] *= g_size[i];\n      N *=\
    \ g_size[i];\n    }\n  }\n\n  i64 operator()(const A &a) {\n    i64 ret = 0;\n\
    \    for (i64 i = 0; i < DIM; i++) {\n      if (a[i] < 0 or g_size[i] <= a[i])\
    \ return -1;\n      ret += a[i] * coeff[i];\n    }\n    return ret;\n  }\n\n \
    \ A inv(i64 n) {\n    A ret{};\n    for (i64 i = 0; i < DIM; i++) {\n      ret[i]\
    \ = n / coeff[i];\n      n %= coeff[i];\n    }\n    return ret;\n  }\n\n  i64\
    \ inner_id(i64, i64 n) { return n; }\n  template <typename T, typename... U>\n\
    \  i64 inner_id(i64 i, i64 n, T &&t, U &&... u) {\n    if (t < 0 or g_size[i]\
    \ <= t) return -1;\n    n += coeff[i++] * t;\n    return inner_id(i, n, forward<U>(u)...);\n\
    \  }\n  template <typename... T>\n  i64 operator()(const T &... t) {\n    return\
    \ inner_id(0, 0, t...);\n  }\n\n  i64 ok(const A &a) {\n    for (i64 i = 0; i\
    \ < DIM; i++)\n      if (a[i] < 0 or g_size[i] <= a[i]) return 0;\n    return\
    \ 1;\n  }\n\n  i64 inner_ok(i64) { return 1; }\n  template <typename T, typename...\
    \ U>\n  i64 inner_ok(i64 idx, T &&t, U &&... u) {\n    if (t < 0 or g_size[idx++]\
    \ <= t) return 0;\n    return inner_ok(idx, forward<U>(u)...);\n  }\n  template\
    \ <typename... T>\n  i64 ok(const T &... t) {\n    return inner_ok(0, t...);\n\
    \  }\n\n  template <typename F>\n  vector<i64> bfs(F f, A s = {}) {\n    vector<i64>\
    \ dist(N, -1);\n    queue<A> Q;\n    assert((*this)(s) != -1);\n    dist[(*this)(s)]\
    \ = 0;\n    Q.push(s);\n    while (!Q.empty()) {\n      A c = Q.front();\n   \
    \   Q.pop();\n      i64 idc = (*this)(c);\n      f(c, [&](A d) {\n        i64\
    \ idd = (*this)(d);\n        if (idd == -1) return;\n        if (dist[idd] ==\
    \ -1) {\n          dist[idd] = dist[idc] + 1;\n          Q.push(d);\n        }\n\
    \      });\n    }\n    return dist;\n  }\n\n  template <typename F>\n  vector<i64>\
    \ bfs01(F f, A s = {}) {\n    vector<i64> dist(N, -1);\n    vector<bool> vis(N,\
    \ 0);\n    deque<A> Q;\n    assert((*this)(s) != -1);\n    dist[(*this)(s)] =\
    \ 0;\n    Q.push_back(s);\n    while (!Q.empty()) {\n      A c = Q.front();\n\
    \      Q.pop_front();\n      i64 idc = (*this)(c);\n      if (vis[idc]) continue;\n\
    \      vis[idc] = true;\n      i64 dc = dist[idc];\n      f(c, [&](A d, i64 w)\
    \ {\n        i64 idd = (*this)(d);\n        if (idd == -1) return;\n        i64\
    \ dd = dist[idd];\n        if (dd == -1 || dc + w < dd) {\n          dist[idd]\
    \ = dc + w;\n          if (w == 0)\n            Q.push_front(d);\n          else\n\
    \            Q.push_back(d);\n        }\n      });\n    }\n    return dist;\n\
    \  }\n\n  vector<i64> dijkstra(function<void(A, function<void(A, i64)>)> f, A\
    \ s = {}) {\n    vector<i64> dist(N, -1);\n    using P = pair<i64, A>;\n    priority_queue<P,\
    \ vector<P>, greater<P>> Q;\n    assert((*this)(s) != -1);\n    Q.emplace(dist[(*this)(s)]\
    \ = 0, s);\n    while (!Q.empty()) {\n      i64 dc;\n      A c;\n      tie(dc,\
    \ c) = Q.top();\n      Q.pop();\n      i64 idc = (*this)(c);\n      if (dist[idc]\
    \ < dc) continue;\n      f(c, [&](const A &d, i64 w) {\n        i64 idd = (*this)(d);\n\
    \        if (idd == -1) return;\n        i64 dd = dist[idd];\n        if (dd ==\
    \ -1 || dd > dc + w) {\n          dist[idd] = dc + w;\n          Q.emplace(dc\
    \ + w, d);\n        }\n      });\n    }\n    return dist;\n  }\n\n  static vector<array<i64,\
    \ 2>> direction4() {\n    return {{{1, 0}}, {{0, 1}}, {{-1, 0}}, {{0, -1}}};\n\
    \  }\n};\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/dimension-expanded-graph.hpp
  requiredBy: []
  timestamp: '2020-11-12 23:29:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dimension-expanded-graph.hpp
layout: document
redirect_from:
- /library/graph/dimension-expanded-graph.hpp
- /library/graph/dimension-expanded-graph.hpp.html
title: graph/dimension-expanded-graph.hpp
---

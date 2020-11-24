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
    \ d;\n}\n#line 6 \"graph/dimension-expanded-graph.hpp\"\n\ntemplate <int DIM,\
    \ typename Data_t = long long>\nstruct DimensionExpandedGraph {\n  static_assert(is_signed<Data_t>::value,\
    \ \"Data_t must be signed.\");\n  using DG = DimensionExpandedGraph;\n\n  struct\
    \ A : array<int, DIM> {\n    using array<int, DIM>::operator[];\n#pragma GCC diagnostic\
    \ ignored \"-Wnarrowing\"\n    template <typename... Args>\n    A(Args... args)\
    \ : array<int, DIM>({args...}) {}\n#pragma GCC diagnostic warning \"-Wnarrowing\"\
    \n\n    A &operator+=(const A &r) {\n      for (int i = 0; i < DIM; i++) (*this)[i]\
    \ += r[i];\n      return *this;\n    }\n    A &operator-=(const A &r) {\n    \
    \  for (int i = 0; i < DIM; i++) (*this)[i] -= r[i];\n      return *this;\n  \
    \  }\n    A operator+(const A &r) { return (*this) += r; }\n    A operator-(const\
    \ A &r) { return (*this) -= r; }\n\n    int id() const { return DG::id(*this);\
    \ }\n    friend int id(const A &a) { return DG::id(a); }\n\n    bool ok() const\
    \ { return DG::ok(*this); }\n    friend bool ok(const A &a) { return DG::ok(a);\
    \ }\n\n    inline bool is_add() const { return (*this)[0] == ADD; }\n    friend\
    \ inline bool is_add(const A &a) { return a[0] == ADD; }\n\n    vector<A> near()\
    \ const {\n      static vector<A> res;\n      res.clear();\n      if (is_add()\
    \ == true) return res;\n      for (int i = 0; i < DIM; i++) {\n        A asc(*this),\
    \ dec(*this);\n        asc[i]++;\n        dec[i]--;\n        if (asc[i] != g_size[i])\
    \ res.push_back(asc);\n        if (dec[i] != -1) res.push_back(dec);\n      }\n\
    \      return res;\n    }\n    friend vector<A> near(const A &a) { return a.near();\
    \ }\n  };\n\n  static int N, add_node;\n  static A g_size, coeff;\n  static constexpr\
    \ int ADD = numeric_limits<int>::min();\n\n  static int id(const A &a) {\n   \
    \ if (a[0] == ADD) return N + a[1];\n    int ret = 0;\n    for (int i = 0; i <\
    \ DIM; i++) {\n      ret += a[i] * coeff[i];\n    }\n    return ret;\n  }\n  template\
    \ <typename... T>\n  static int id(const T &... t) {\n    return id(A{t...});\n\
    \  }\n\n  static bool ok(const A &a) {\n    if (a[0] == ADD) {\n      return 0\
    \ <= a[1] && a[1] < add_node;\n    }\n    for (int i = 0; i < DIM; i++)\n    \
    \  if (a[i] < 0 or g_size[i] <= a[i]) return false;\n    return true;\n  }\n \
    \ template <typename... T>\n  static bool ok(const T &... t) {\n    return ok(A{t...});\n\
    \  }\n\n  static A ad(int n) { return A{DG::ADD, n}; };\n\n  vector<char> grid;\n\
    \  vector<Data_t> dat;\n\n  explicit DimensionExpandedGraph() = default;\n  template\
    \ <typename... T>\n  explicit DimensionExpandedGraph(const T &... t) {\n    set(t...);\n\
    \  }\n\n  template <typename... T>\n  void set(const T &... t) {\n    N = 1;\n\
    \    g_size = A{t...};\n    coeff.fill(1);\n    for (int i = 0; i < DIM; i++)\
    \ {\n      assert(g_size[i] != 0);\n      for (int j = 0; j < i; j++) coeff[j]\
    \ *= g_size[i];\n      N *= g_size[i];\n    }\n    dat.resize(N + add_node, -1);\n\
    \  }\n\n  void add(int n) {\n    add_node = n;\n    dat.resize(N + add_node, -1);\n\
    \  }\n\n  void scan(istream &is = std::cin) {\n    grid.reserve(N);\n    int l\
    \ = g_size[DIM - 1];\n    for (int i = 0; i < N; i += l) {\n      string s;\n\
    \      is >> s;\n      copy(begin(s), end(s), back_inserter(grid));\n    }\n \
    \ }\n\n  friend istream &operator>>(istream &is, DG &g) {\n    g.scan(is);\n \
    \   return is;\n  }\n\n  char &operator()(const A &a) { return grid[id(a)]; }\n\
    \  template <typename... T>\n  char &operator()(const T &... t) {\n    return\
    \ grid[id(t...)];\n  }\n\n  A find(const char &c) {\n    A a{};\n    fill(begin(a),\
    \ end(a), 0);\n    a[DIM - 1] = -1;\n    while (true) {\n      a[DIM - 1]++;\n\
    \      for (int i = DIM - 1;; i--) {\n        if (a[i] != g_size[i]) break;\n\
    \        if (i == 0) return a;\n        a[i] = 0;\n        a[i - 1]++;\n     \
    \ }\n      if ((*this)(a) == c) return a;\n    }\n  }\n\n  template <typename\
    \ F, typename Dist_t = Data_t>\n  vector<Dist_t> bfs(F f, A s) {\n    vector<Dist_t>\
    \ dist(N + add_node, -1);\n    if (!ok(s)) return dist;\n    vector<A> Q;\n  \
    \  dist[id(s)] = 0;\n    Q.push_back(s);\n    while (!Q.empty()) {\n      A c\
    \ = Q.back();\n      Q.pop_back();\n      int dc = dist[id(c)];\n      f(c, [&](A\
    \ d) {\n        if (!ok(d)) return;\n        if (dist[id(d)] == -1) {\n      \
    \    dist[id(d)] = dc + 1;\n          Q.push_back(d);\n        }\n      });\n\
    \    }\n    return dist;\n  }\n\n  template <typename F, typename Dist_t = Data_t>\n\
    \  vector<Dist_t> bfs01(F f, A s) {\n    vector<Dist_t> dist(N + add_node, -1);\n\
    \    if (!ok(s)) return dist;\n    deque<A> Q;\n    dist[id(s)] = 0;\n    Q.push_back(s);\n\
    \    while (!Q.empty()) {\n      A c = Q.front();\n      Q.pop_front();\n    \
    \  int dc = dist[id(c)];\n      f(c, [&](A d, Data_t w) {\n        if (!ok(d))\
    \ return;\n        if (dist[id(d)] == -1) {\n          dist[id(d)] = dc + w;\n\
    \          if (w == 0)\n            Q.push_front(d);\n          else\n       \
    \     Q.push_back(d);\n        }\n      });\n    }\n    return dist;\n  }\n\n\
    \  template <typename F, typename Dist_t = Data_t>\n  static vector<Dist_t> dijkstra(F\
    \ f, A s) {\n    vector<Dist_t> dist(N, -1);\n    using P = pair<Dist_t, A>;\n\
    \    auto cmp = [](P &a, P &b) { return a.first > b.first; };\n    priority_queue<P,\
    \ vector<P>, decltype(cmp)> Q(cmp);\n    assert(id(s) != -1);\n    dist[id(s)]\
    \ = 0;\n    Q.emplace(0, s);\n    while (!Q.empty()) {\n      Dist_t dc;\n   \
    \   A c;\n      tie(dc, c) = Q.top();\n      Q.pop();\n      if (dist[id(c)] <\
    \ dc) continue;\n      f(c, [&](A d, Dist_t w) {\n        if (!ok(d)) return;\n\
    \        if (dist[id(d)] == -1 || dist[id(d)] > dc + w) {\n          dist[id(d)]\
    \ = dc + w;\n          Q.emplace(dc + w, d);\n        }\n      });\n    }\n  \
    \  return dist;\n  }\n\n  // Union Find\n  int find(A u) {\n    return dat[id(u)]\
    \ < 0 ? id(u) : dat[id(u)] = find(dat[id(u)]);\n  }\n  bool same(A u, A v) { return\
    \ find(u) == find(v); }\n  bool unite(A u, A v) {\n    if ((u = find(u)) == (v\
    \ = find(v))) return false;\n    int iu = id(u), iv = id(v);\n    if (dat[iu]\
    \ > dat[iv]) swap(iu, iv);\n    dat[iu] += dat[iv];\n    dat[iv] = iu;\n    return\
    \ true;\n  }\n  Data_t size(A u) { return -dat[find(u)]; }\n};\n\ntemplate <int\
    \ DIM, typename Data_t>\nint DimensionExpandedGraph<DIM, Data_t>::N = 0;\ntemplate\
    \ <int DIM, typename Data_t>\nint DimensionExpandedGraph<DIM, Data_t>::add_node\
    \ = 0;\ntemplate <int DIM, typename Data_t>\ntypename DimensionExpandedGraph<DIM,\
    \ Data_t>::A\n    DimensionExpandedGraph<DIM, Data_t>::g_size;\ntemplate <int\
    \ DIM, typename Data_t>\ntypename DimensionExpandedGraph<DIM, Data_t>::A\n   \
    \ DimensionExpandedGraph<DIM, Data_t>::coeff;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"./graph-template.hpp\"\n\ntemplate <int DIM, typename Data_t = long long>\n\
    struct DimensionExpandedGraph {\n  static_assert(is_signed<Data_t>::value, \"\
    Data_t must be signed.\");\n  using DG = DimensionExpandedGraph;\n\n  struct A\
    \ : array<int, DIM> {\n    using array<int, DIM>::operator[];\n#pragma GCC diagnostic\
    \ ignored \"-Wnarrowing\"\n    template <typename... Args>\n    A(Args... args)\
    \ : array<int, DIM>({args...}) {}\n#pragma GCC diagnostic warning \"-Wnarrowing\"\
    \n\n    A &operator+=(const A &r) {\n      for (int i = 0; i < DIM; i++) (*this)[i]\
    \ += r[i];\n      return *this;\n    }\n    A &operator-=(const A &r) {\n    \
    \  for (int i = 0; i < DIM; i++) (*this)[i] -= r[i];\n      return *this;\n  \
    \  }\n    A operator+(const A &r) { return (*this) += r; }\n    A operator-(const\
    \ A &r) { return (*this) -= r; }\n\n    int id() const { return DG::id(*this);\
    \ }\n    friend int id(const A &a) { return DG::id(a); }\n\n    bool ok() const\
    \ { return DG::ok(*this); }\n    friend bool ok(const A &a) { return DG::ok(a);\
    \ }\n\n    inline bool is_add() const { return (*this)[0] == ADD; }\n    friend\
    \ inline bool is_add(const A &a) { return a[0] == ADD; }\n\n    vector<A> near()\
    \ const {\n      static vector<A> res;\n      res.clear();\n      if (is_add()\
    \ == true) return res;\n      for (int i = 0; i < DIM; i++) {\n        A asc(*this),\
    \ dec(*this);\n        asc[i]++;\n        dec[i]--;\n        if (asc[i] != g_size[i])\
    \ res.push_back(asc);\n        if (dec[i] != -1) res.push_back(dec);\n      }\n\
    \      return res;\n    }\n    friend vector<A> near(const A &a) { return a.near();\
    \ }\n  };\n\n  static int N, add_node;\n  static A g_size, coeff;\n  static constexpr\
    \ int ADD = numeric_limits<int>::min();\n\n  static int id(const A &a) {\n   \
    \ if (a[0] == ADD) return N + a[1];\n    int ret = 0;\n    for (int i = 0; i <\
    \ DIM; i++) {\n      ret += a[i] * coeff[i];\n    }\n    return ret;\n  }\n  template\
    \ <typename... T>\n  static int id(const T &... t) {\n    return id(A{t...});\n\
    \  }\n\n  static bool ok(const A &a) {\n    if (a[0] == ADD) {\n      return 0\
    \ <= a[1] && a[1] < add_node;\n    }\n    for (int i = 0; i < DIM; i++)\n    \
    \  if (a[i] < 0 or g_size[i] <= a[i]) return false;\n    return true;\n  }\n \
    \ template <typename... T>\n  static bool ok(const T &... t) {\n    return ok(A{t...});\n\
    \  }\n\n  static A ad(int n) { return A{DG::ADD, n}; };\n\n  vector<char> grid;\n\
    \  vector<Data_t> dat;\n\n  explicit DimensionExpandedGraph() = default;\n  template\
    \ <typename... T>\n  explicit DimensionExpandedGraph(const T &... t) {\n    set(t...);\n\
    \  }\n\n  template <typename... T>\n  void set(const T &... t) {\n    N = 1;\n\
    \    g_size = A{t...};\n    coeff.fill(1);\n    for (int i = 0; i < DIM; i++)\
    \ {\n      assert(g_size[i] != 0);\n      for (int j = 0; j < i; j++) coeff[j]\
    \ *= g_size[i];\n      N *= g_size[i];\n    }\n    dat.resize(N + add_node, -1);\n\
    \  }\n\n  void add(int n) {\n    add_node = n;\n    dat.resize(N + add_node, -1);\n\
    \  }\n\n  void scan(istream &is = std::cin) {\n    grid.reserve(N);\n    int l\
    \ = g_size[DIM - 1];\n    for (int i = 0; i < N; i += l) {\n      string s;\n\
    \      is >> s;\n      copy(begin(s), end(s), back_inserter(grid));\n    }\n \
    \ }\n\n  friend istream &operator>>(istream &is, DG &g) {\n    g.scan(is);\n \
    \   return is;\n  }\n\n  char &operator()(const A &a) { return grid[id(a)]; }\n\
    \  template <typename... T>\n  char &operator()(const T &... t) {\n    return\
    \ grid[id(t...)];\n  }\n\n  A find(const char &c) {\n    A a{};\n    fill(begin(a),\
    \ end(a), 0);\n    a[DIM - 1] = -1;\n    while (true) {\n      a[DIM - 1]++;\n\
    \      for (int i = DIM - 1;; i--) {\n        if (a[i] != g_size[i]) break;\n\
    \        if (i == 0) return a;\n        a[i] = 0;\n        a[i - 1]++;\n     \
    \ }\n      if ((*this)(a) == c) return a;\n    }\n  }\n\n  template <typename\
    \ F, typename Dist_t = Data_t>\n  vector<Dist_t> bfs(F f, A s) {\n    vector<Dist_t>\
    \ dist(N + add_node, -1);\n    if (!ok(s)) return dist;\n    vector<A> Q;\n  \
    \  dist[id(s)] = 0;\n    Q.push_back(s);\n    while (!Q.empty()) {\n      A c\
    \ = Q.back();\n      Q.pop_back();\n      int dc = dist[id(c)];\n      f(c, [&](A\
    \ d) {\n        if (!ok(d)) return;\n        if (dist[id(d)] == -1) {\n      \
    \    dist[id(d)] = dc + 1;\n          Q.push_back(d);\n        }\n      });\n\
    \    }\n    return dist;\n  }\n\n  template <typename F, typename Dist_t = Data_t>\n\
    \  vector<Dist_t> bfs01(F f, A s) {\n    vector<Dist_t> dist(N + add_node, -1);\n\
    \    if (!ok(s)) return dist;\n    deque<A> Q;\n    dist[id(s)] = 0;\n    Q.push_back(s);\n\
    \    while (!Q.empty()) {\n      A c = Q.front();\n      Q.pop_front();\n    \
    \  int dc = dist[id(c)];\n      f(c, [&](A d, Data_t w) {\n        if (!ok(d))\
    \ return;\n        if (dist[id(d)] == -1) {\n          dist[id(d)] = dc + w;\n\
    \          if (w == 0)\n            Q.push_front(d);\n          else\n       \
    \     Q.push_back(d);\n        }\n      });\n    }\n    return dist;\n  }\n\n\
    \  template <typename F, typename Dist_t = Data_t>\n  static vector<Dist_t> dijkstra(F\
    \ f, A s) {\n    vector<Dist_t> dist(N, -1);\n    using P = pair<Dist_t, A>;\n\
    \    auto cmp = [](P &a, P &b) { return a.first > b.first; };\n    priority_queue<P,\
    \ vector<P>, decltype(cmp)> Q(cmp);\n    assert(id(s) != -1);\n    dist[id(s)]\
    \ = 0;\n    Q.emplace(0, s);\n    while (!Q.empty()) {\n      Dist_t dc;\n   \
    \   A c;\n      tie(dc, c) = Q.top();\n      Q.pop();\n      if (dist[id(c)] <\
    \ dc) continue;\n      f(c, [&](A d, Dist_t w) {\n        if (!ok(d)) return;\n\
    \        if (dist[id(d)] == -1 || dist[id(d)] > dc + w) {\n          dist[id(d)]\
    \ = dc + w;\n          Q.emplace(dc + w, d);\n        }\n      });\n    }\n  \
    \  return dist;\n  }\n\n  // Union Find\n  int find(A u) {\n    return dat[id(u)]\
    \ < 0 ? id(u) : dat[id(u)] = find(dat[id(u)]);\n  }\n  bool same(A u, A v) { return\
    \ find(u) == find(v); }\n  bool unite(A u, A v) {\n    if ((u = find(u)) == (v\
    \ = find(v))) return false;\n    int iu = id(u), iv = id(v);\n    if (dat[iu]\
    \ > dat[iv]) swap(iu, iv);\n    dat[iu] += dat[iv];\n    dat[iv] = iu;\n    return\
    \ true;\n  }\n  Data_t size(A u) { return -dat[find(u)]; }\n};\n\ntemplate <int\
    \ DIM, typename Data_t>\nint DimensionExpandedGraph<DIM, Data_t>::N = 0;\ntemplate\
    \ <int DIM, typename Data_t>\nint DimensionExpandedGraph<DIM, Data_t>::add_node\
    \ = 0;\ntemplate <int DIM, typename Data_t>\ntypename DimensionExpandedGraph<DIM,\
    \ Data_t>::A\n    DimensionExpandedGraph<DIM, Data_t>::g_size;\ntemplate <int\
    \ DIM, typename Data_t>\ntypename DimensionExpandedGraph<DIM, Data_t>::A\n   \
    \ DimensionExpandedGraph<DIM, Data_t>::coeff;\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/dimension-expanded-graph.hpp
  requiredBy: []
  timestamp: '2020-11-24 16:37:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dimension-expanded-graph.hpp
layout: document
redirect_from:
- /library/graph/dimension-expanded-graph.hpp
- /library/graph/dimension-expanded-graph.hpp.html
title: graph/dimension-expanded-graph.hpp
---

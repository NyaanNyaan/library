---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-aoj-other/aoj-1130-DG-bfs.test.cpp
    title: verify/verify-aoj-other/aoj-1130-DG-bfs.test.cpp
  - icon: ':x:'
    path: verify/verify-aoj-other/aoj-2945-DG-01bfs.test.cpp
    title: verify/verify-aoj-other/aoj-2945-DG-01bfs.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-0697.test.cpp
    title: verify/verify-yuki/yuki-0697.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1283.test.cpp
    title: verify/verify-yuki/yuki-1283.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u6B21\u5143\u62E1\u5F35\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "#line 2 \"graph/dimension-expanded-graph.hpp\"\n\ntemplate <int DIM,\
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
    \ int ADD = numeric_limits<int>::max();\n\n  static int id(const A &a) {\n   \
    \ if (a[0] == ADD) return N + a[1];\n    int ret = 0;\n    for (int i = 0; i <\
    \ DIM; i++) {\n      ret += a[i] * coeff[i];\n    }\n    return ret;\n  }\n  template\
    \ <typename... T>\n  static int id(const T &... t) {\n    return id(A{t...});\n\
    \  }\n\n  static bool ok(const A &a) {\n    if (a[0] == ADD) {\n      return 0\
    \ <= a[1] && a[1] < add_node;\n    }\n    for (int i = 0; i < DIM; i++)\n    \
    \  if (a[i] < 0 or g_size[i] <= a[i]) return false;\n    return true;\n  }\n \
    \ template <typename... T>\n  static bool ok(const T &... t) {\n    return ok(A{t...});\n\
    \  }\n\n  template <typename... Args>\n  static A cast(Args... args) {\n    return\
    \ A(args...);\n  }\n  static A ad(int n) { return A{DG::ADD, n}; };\n\n  vector<char>\
    \ grid;\n\n  explicit DimensionExpandedGraph() = default;\n  template <typename...\
    \ T>\n  explicit DimensionExpandedGraph(const T &... t) {\n    set(t...);\n  }\n\
    \n  template <typename... T>\n  void set(const T &... t) {\n    N = 1;\n    g_size\
    \ = A{t...};\n    coeff.fill(1);\n    for (int i = 0; i < DIM; i++) {\n      assert(g_size[i]\
    \ != 0);\n      for (int j = 0; j < i; j++) coeff[j] *= g_size[i];\n      N *=\
    \ g_size[i];\n    }\n  }\n\n  void add(int n) { add_node = n; }\n\n  void scan(istream\
    \ &is = std::cin) {\n    grid.reserve(N);\n    int l = g_size[DIM - 1];\n    for\
    \ (int i = 0; i < N; i += l) {\n      string s;\n      is >> s;\n      copy(begin(s),\
    \ end(s), back_inserter(grid));\n    }\n  }\n\n  friend istream &operator>>(istream\
    \ &is, DG &g) {\n    g.scan(is);\n    return is;\n  }\n\n  vector<char> &get_grid()\
    \ { return grid; }\n  char &operator()(const A &a) { return grid[id(a)]; }\n \
    \ template <typename... T>\n  char &operator()(const T &... t) {\n    return grid[id(t...)];\n\
    \  }\n\n  A find(const char &c) {\n    A a{};\n    fill(begin(a), end(a), 0);\n\
    \    a[DIM - 1] = -1;\n    while (true) {\n      a[DIM - 1]++;\n      for (int\
    \ i = DIM - 1;; i--) {\n        if (a[i] != g_size[i]) break;\n        if (i ==\
    \ 0) return a;\n        a[i] = 0;\n        a[i - 1]++;\n      }\n      if ((*this)(a)\
    \ == c) return a;\n    }\n  }\n\n  template <typename F, typename Dist_t = Data_t>\n\
    \  vector<Dist_t> bfs(F f, A s) {\n    vector<Dist_t> dist(N + add_node, -1);\n\
    \    if (!ok(s)) return dist;\n    vector<A> Q;\n    dist[id(s)] = 0;\n    Q.push_back(s);\n\
    \    while (!Q.empty()) {\n      A c = Q.back();\n      Q.pop_back();\n      int\
    \ dc = dist[id(c)];\n      f(c, [&](A d) {\n        if (!ok(d)) return;\n    \
    \    if (dist[id(d)] == -1) {\n          dist[id(d)] = dc + 1;\n          Q.push_back(d);\n\
    \        }\n      });\n    }\n    return dist;\n  }\n\n  template <typename F,\
    \ typename Dist_t = Data_t>\n  vector<Dist_t> bfs01(F f, A s) {\n    vector<Dist_t>\
    \ dist(N + add_node, -1);\n    if (!ok(s)) return dist;\n    deque<A> Q;\n   \
    \ dist[id(s)] = 0;\n    Q.push_back(s);\n    while (!Q.empty()) {\n      A c =\
    \ Q.front();\n      Q.pop_front();\n      int dc = dist[id(c)];\n      f(c, [&](A\
    \ d, Data_t w) {\n        if (!ok(d)) return;\n        if (dist[id(d)] == -1)\
    \ {\n          dist[id(d)] = dc + w;\n          if (w == 0)\n            Q.push_front(d);\n\
    \          else\n            Q.push_back(d);\n        }\n      });\n    }\n  \
    \  return dist;\n  }\n\n  template <typename F, typename Dist_t = Data_t>\n  static\
    \ vector<Dist_t> dijkstra(F f, A s) {\n    vector<Dist_t> dist(N, -1);\n    using\
    \ P = pair<Dist_t, A>;\n    auto cmp = [](P &a, P &b) { return a.first > b.first;\
    \ };\n    priority_queue<P, vector<P>, decltype(cmp)> Q(cmp);\n    assert(id(s)\
    \ != -1);\n    dist[id(s)] = 0;\n    Q.emplace(0, s);\n    while (!Q.empty())\
    \ {\n      Dist_t dc;\n      A c;\n      tie(dc, c) = Q.top();\n      Q.pop();\n\
    \      if (dist[id(c)] < dc) continue;\n      f(c, [&](A d, Dist_t w) {\n    \
    \    if (!ok(d)) return;\n        if (dist[id(d)] == -1 || dist[id(d)] > dc +\
    \ w) {\n          dist[id(d)] = dc + w;\n          Q.emplace(dc + w, d);\n   \
    \     }\n      });\n    }\n    return dist;\n  }\n\n  vector<A> dat;\n\n  template\
    \ <typename F>\n  void uf(F f) {\n    A dflt;\n    dflt[0] = -1;\n    dat.resize(N\
    \ + add_node, dflt);\n    A a{};\n    fill(begin(a), end(a), 0);\n    a[DIM -\
    \ 1] = -1;\n    while (true) {\n      a[DIM - 1]++;\n      for (int i = DIM -\
    \ 1;; i--) {\n        if (a[i] != g_size[i]) break;\n        if (i == 0) return;\n\
    \        a[i] = 0;\n        a[i - 1]++;\n      }\n      f(a, [&](A u, A v) { unite(u,\
    \ v); });\n    }\n  }\n\n  // Union Find\n  A find(A u) { return dat[id(u)][0]\
    \ < 0 ? u : dat[id(u)] = find(dat[id(u)]); }\n  bool same(A u, A v) { return find(u)\
    \ == find(v); }\n  bool unite(A u, A v) {\n    if ((u = find(u)) == (v = find(v)))\
    \ return false;\n    int iu = id(u), iv = id(v);\n    if (dat[iu] > dat[iv]) swap(u,\
    \ v), swap(iu, iv);\n    dat[iu] += dat[iv];\n    dat[iv] = u;\n    return true;\n\
    \  }\n  Data_t size(A u) { return -dat[id(find(u))][0]; }\n};\n\ntemplate <int\
    \ DIM, typename Data_t>\nint DimensionExpandedGraph<DIM, Data_t>::N = 0;\ntemplate\
    \ <int DIM, typename Data_t>\nint DimensionExpandedGraph<DIM, Data_t>::add_node\
    \ = 0;\ntemplate <int DIM, typename Data_t>\ntypename DimensionExpandedGraph<DIM,\
    \ Data_t>::A\n    DimensionExpandedGraph<DIM, Data_t>::g_size;\ntemplate <int\
    \ DIM, typename Data_t>\ntypename DimensionExpandedGraph<DIM, Data_t>::A\n   \
    \ DimensionExpandedGraph<DIM, Data_t>::coeff;\n\n/**\n * @brief \u6B21\u5143\u62E1\
    \u5F35\u30B0\u30E9\u30D5\n */\n"
  code: "#pragma once\n\ntemplate <int DIM, typename Data_t = long long>\nstruct DimensionExpandedGraph\
    \ {\n  static_assert(is_signed<Data_t>::value, \"Data_t must be signed.\");\n\
    \  using DG = DimensionExpandedGraph;\n\n  struct A : array<int, DIM> {\n    using\
    \ array<int, DIM>::operator[];\n#pragma GCC diagnostic ignored \"-Wnarrowing\"\
    \n    template <typename... Args>\n    A(Args... args) : array<int, DIM>({args...})\
    \ {}\n#pragma GCC diagnostic warning \"-Wnarrowing\"\n\n    A &operator+=(const\
    \ A &r) {\n      for (int i = 0; i < DIM; i++) (*this)[i] += r[i];\n      return\
    \ *this;\n    }\n    A &operator-=(const A &r) {\n      for (int i = 0; i < DIM;\
    \ i++) (*this)[i] -= r[i];\n      return *this;\n    }\n    A operator+(const\
    \ A &r) { return (*this) += r; }\n    A operator-(const A &r) { return (*this)\
    \ -= r; }\n\n    int id() const { return DG::id(*this); }\n    friend int id(const\
    \ A &a) { return DG::id(a); }\n\n    bool ok() const { return DG::ok(*this); }\n\
    \    friend bool ok(const A &a) { return DG::ok(a); }\n\n    inline bool is_add()\
    \ const { return (*this)[0] == ADD; }\n    friend inline bool is_add(const A &a)\
    \ { return a[0] == ADD; }\n\n    vector<A> near() const {\n      static vector<A>\
    \ res;\n      res.clear();\n      if (is_add() == true) return res;\n      for\
    \ (int i = 0; i < DIM; i++) {\n        A asc(*this), dec(*this);\n        asc[i]++;\n\
    \        dec[i]--;\n        if (asc[i] != g_size[i]) res.push_back(asc);\n   \
    \     if (dec[i] != -1) res.push_back(dec);\n      }\n      return res;\n    }\n\
    \    friend vector<A> near(const A &a) { return a.near(); }\n  };\n\n  static\
    \ int N, add_node;\n  static A g_size, coeff;\n  static constexpr int ADD = numeric_limits<int>::max();\n\
    \n  static int id(const A &a) {\n    if (a[0] == ADD) return N + a[1];\n    int\
    \ ret = 0;\n    for (int i = 0; i < DIM; i++) {\n      ret += a[i] * coeff[i];\n\
    \    }\n    return ret;\n  }\n  template <typename... T>\n  static int id(const\
    \ T &... t) {\n    return id(A{t...});\n  }\n\n  static bool ok(const A &a) {\n\
    \    if (a[0] == ADD) {\n      return 0 <= a[1] && a[1] < add_node;\n    }\n \
    \   for (int i = 0; i < DIM; i++)\n      if (a[i] < 0 or g_size[i] <= a[i]) return\
    \ false;\n    return true;\n  }\n  template <typename... T>\n  static bool ok(const\
    \ T &... t) {\n    return ok(A{t...});\n  }\n\n  template <typename... Args>\n\
    \  static A cast(Args... args) {\n    return A(args...);\n  }\n  static A ad(int\
    \ n) { return A{DG::ADD, n}; };\n\n  vector<char> grid;\n\n  explicit DimensionExpandedGraph()\
    \ = default;\n  template <typename... T>\n  explicit DimensionExpandedGraph(const\
    \ T &... t) {\n    set(t...);\n  }\n\n  template <typename... T>\n  void set(const\
    \ T &... t) {\n    N = 1;\n    g_size = A{t...};\n    coeff.fill(1);\n    for\
    \ (int i = 0; i < DIM; i++) {\n      assert(g_size[i] != 0);\n      for (int j\
    \ = 0; j < i; j++) coeff[j] *= g_size[i];\n      N *= g_size[i];\n    }\n  }\n\
    \n  void add(int n) { add_node = n; }\n\n  void scan(istream &is = std::cin) {\n\
    \    grid.reserve(N);\n    int l = g_size[DIM - 1];\n    for (int i = 0; i < N;\
    \ i += l) {\n      string s;\n      is >> s;\n      copy(begin(s), end(s), back_inserter(grid));\n\
    \    }\n  }\n\n  friend istream &operator>>(istream &is, DG &g) {\n    g.scan(is);\n\
    \    return is;\n  }\n\n  vector<char> &get_grid() { return grid; }\n  char &operator()(const\
    \ A &a) { return grid[id(a)]; }\n  template <typename... T>\n  char &operator()(const\
    \ T &... t) {\n    return grid[id(t...)];\n  }\n\n  A find(const char &c) {\n\
    \    A a{};\n    fill(begin(a), end(a), 0);\n    a[DIM - 1] = -1;\n    while (true)\
    \ {\n      a[DIM - 1]++;\n      for (int i = DIM - 1;; i--) {\n        if (a[i]\
    \ != g_size[i]) break;\n        if (i == 0) return a;\n        a[i] = 0;\n   \
    \     a[i - 1]++;\n      }\n      if ((*this)(a) == c) return a;\n    }\n  }\n\
    \n  template <typename F, typename Dist_t = Data_t>\n  vector<Dist_t> bfs(F f,\
    \ A s) {\n    vector<Dist_t> dist(N + add_node, -1);\n    if (!ok(s)) return dist;\n\
    \    vector<A> Q;\n    dist[id(s)] = 0;\n    Q.push_back(s);\n    while (!Q.empty())\
    \ {\n      A c = Q.back();\n      Q.pop_back();\n      int dc = dist[id(c)];\n\
    \      f(c, [&](A d) {\n        if (!ok(d)) return;\n        if (dist[id(d)] ==\
    \ -1) {\n          dist[id(d)] = dc + 1;\n          Q.push_back(d);\n        }\n\
    \      });\n    }\n    return dist;\n  }\n\n  template <typename F, typename Dist_t\
    \ = Data_t>\n  vector<Dist_t> bfs01(F f, A s) {\n    vector<Dist_t> dist(N + add_node,\
    \ -1);\n    if (!ok(s)) return dist;\n    deque<A> Q;\n    dist[id(s)] = 0;\n\
    \    Q.push_back(s);\n    while (!Q.empty()) {\n      A c = Q.front();\n     \
    \ Q.pop_front();\n      int dc = dist[id(c)];\n      f(c, [&](A d, Data_t w) {\n\
    \        if (!ok(d)) return;\n        if (dist[id(d)] == -1) {\n          dist[id(d)]\
    \ = dc + w;\n          if (w == 0)\n            Q.push_front(d);\n          else\n\
    \            Q.push_back(d);\n        }\n      });\n    }\n    return dist;\n\
    \  }\n\n  template <typename F, typename Dist_t = Data_t>\n  static vector<Dist_t>\
    \ dijkstra(F f, A s) {\n    vector<Dist_t> dist(N, -1);\n    using P = pair<Dist_t,\
    \ A>;\n    auto cmp = [](P &a, P &b) { return a.first > b.first; };\n    priority_queue<P,\
    \ vector<P>, decltype(cmp)> Q(cmp);\n    assert(id(s) != -1);\n    dist[id(s)]\
    \ = 0;\n    Q.emplace(0, s);\n    while (!Q.empty()) {\n      Dist_t dc;\n   \
    \   A c;\n      tie(dc, c) = Q.top();\n      Q.pop();\n      if (dist[id(c)] <\
    \ dc) continue;\n      f(c, [&](A d, Dist_t w) {\n        if (!ok(d)) return;\n\
    \        if (dist[id(d)] == -1 || dist[id(d)] > dc + w) {\n          dist[id(d)]\
    \ = dc + w;\n          Q.emplace(dc + w, d);\n        }\n      });\n    }\n  \
    \  return dist;\n  }\n\n  vector<A> dat;\n\n  template <typename F>\n  void uf(F\
    \ f) {\n    A dflt;\n    dflt[0] = -1;\n    dat.resize(N + add_node, dflt);\n\
    \    A a{};\n    fill(begin(a), end(a), 0);\n    a[DIM - 1] = -1;\n    while (true)\
    \ {\n      a[DIM - 1]++;\n      for (int i = DIM - 1;; i--) {\n        if (a[i]\
    \ != g_size[i]) break;\n        if (i == 0) return;\n        a[i] = 0;\n     \
    \   a[i - 1]++;\n      }\n      f(a, [&](A u, A v) { unite(u, v); });\n    }\n\
    \  }\n\n  // Union Find\n  A find(A u) { return dat[id(u)][0] < 0 ? u : dat[id(u)]\
    \ = find(dat[id(u)]); }\n  bool same(A u, A v) { return find(u) == find(v); }\n\
    \  bool unite(A u, A v) {\n    if ((u = find(u)) == (v = find(v))) return false;\n\
    \    int iu = id(u), iv = id(v);\n    if (dat[iu] > dat[iv]) swap(u, v), swap(iu,\
    \ iv);\n    dat[iu] += dat[iv];\n    dat[iv] = u;\n    return true;\n  }\n  Data_t\
    \ size(A u) { return -dat[id(find(u))][0]; }\n};\n\ntemplate <int DIM, typename\
    \ Data_t>\nint DimensionExpandedGraph<DIM, Data_t>::N = 0;\ntemplate <int DIM,\
    \ typename Data_t>\nint DimensionExpandedGraph<DIM, Data_t>::add_node = 0;\ntemplate\
    \ <int DIM, typename Data_t>\ntypename DimensionExpandedGraph<DIM, Data_t>::A\n\
    \    DimensionExpandedGraph<DIM, Data_t>::g_size;\ntemplate <int DIM, typename\
    \ Data_t>\ntypename DimensionExpandedGraph<DIM, Data_t>::A\n    DimensionExpandedGraph<DIM,\
    \ Data_t>::coeff;\n\n/**\n * @brief \u6B21\u5143\u62E1\u5F35\u30B0\u30E9\u30D5\
    \n */\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dimension-expanded-graph.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-aoj-other/aoj-2945-DG-01bfs.test.cpp
  - verify/verify-aoj-other/aoj-1130-DG-bfs.test.cpp
  - verify/verify-yuki/yuki-0697.test.cpp
  - verify/verify-yuki/yuki-1283.test.cpp
documentation_of: graph/dimension-expanded-graph.hpp
layout: document
redirect_from:
- /library/graph/dimension-expanded-graph.hpp
- /library/graph/dimension-expanded-graph.hpp.html
title: "\u6B21\u5143\u62E1\u5F35\u30B0\u30E9\u30D5"
---

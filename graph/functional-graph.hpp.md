---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: Union Find(Disjoint Set Union)
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: internal/internal-type-traits.hpp
    title: internal/internal-type-traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2891-2.test.cpp
    title: verify/verify-aoj-other/aoj-2891-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1254-2.test.cpp
    title: verify/verify-yuki/yuki-1254-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/functional-graph.hpp\"\n\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\nusing namespace std;\n\n#line 2 \"data-structure/union-find.hpp\"\
    \n\nstruct UnionFind {\n  vector<int> data;\n  UnionFind(int N) : data(N, -1)\
    \ {}\n\n  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]);\
    \ }\n\n  int unite(int x, int y) {\n    if ((x = find(x)) == (y = find(y))) return\
    \ false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n  \
    \  data[y] = x;\n    return true;\n  }\n\n  // f(x, y) : x \u306B y \u3092\u30DE\
    \u30FC\u30B8\n  template<typename F>\n  int unite(int x, int y,const F &f) {\n\
    \    if ((x = find(x)) == (y = find(y))) return false;\n    if (data[x] > data[y])\
    \ swap(x, y);\n    data[x] += data[y];\n    data[y] = x;\n    f(x, y);\n    return\
    \ true;\n  }\n\n  int size(int k) { return -data[find(k)]; }\n\n  int same(int\
    \ x, int y) { return find(x) == find(y); }\n};\n\n/**\n * @brief Union Find(Disjoint\
    \ Set Union)\n * @docs docs/data-structure/union-find.md\n */\n#line 2 \"internal/internal-type-traits.hpp\"\
    \n\n#include <type_traits>\nusing namespace std;\n\nnamespace internal {\ntemplate\
    \ <typename T>\nusing is_broadly_integral =\n    typename conditional_t<is_integral_v<T>\
    \ || is_same_v<T, __int128_t> ||\n                               is_same_v<T,\
    \ __uint128_t>,\n                           true_type, false_type>::type;\n\n\
    template <typename T>\nusing is_broadly_signed =\n    typename conditional_t<is_signed_v<T>\
    \ || is_same_v<T, __int128_t>,\n                           true_type, false_type>::type;\n\
    \ntemplate <typename T>\nusing is_broadly_unsigned =\n    typename conditional_t<is_unsigned_v<T>\
    \ || is_same_v<T, __uint128_t>,\n                           true_type, false_type>::type;\n\
    \n#define ENABLE_VALUE(x) \\\n  template <typename T> \\\n  constexpr bool x##_v\
    \ = x<T>::value;\n\nENABLE_VALUE(is_broadly_integral);\nENABLE_VALUE(is_broadly_signed);\n\
    ENABLE_VALUE(is_broadly_unsigned);\n#undef ENABLE_VALUE\n\n#define ENABLE_HAS_TYPE(var)\
    \                                   \\\n  template <class, class = void>     \
    \                          \\\n  struct has_##var : false_type {};           \
    \                 \\\n  template <class T>                                   \
    \        \\\n  struct has_##var<T, void_t<typename T::var>> : true_type {}; \\\
    \n  template <class T>                                           \\\n  constexpr\
    \ auto has_##var##_v = has_##var<T>::value;\n\n#define ENABLE_HAS_VAR(var)   \
    \                                  \\\n  template <class, class = void>      \
    \                          \\\n  struct has_##var : false_type {};           \
    \                  \\\n  template <class T>                                  \
    \          \\\n  struct has_##var<T, void_t<decltype(T::var)>> : true_type {};\
    \ \\\n  template <class T>                                            \\\n  constexpr\
    \ auto has_##var##_v = has_##var<T>::value;\n\n}  // namespace internal\n#line\
    \ 2 \"graph/graph-template.hpp\"\n\ntemplate <typename T>\nstruct edge {\n  int\
    \ src, to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost)\
    \ {}\n  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}\n\
    \n  edge &operator=(const int &x) {\n    to = x;\n    return *this;\n  }\n\n \
    \ operator int() const { return to; }\n};\ntemplate <typename T>\nusing Edges\
    \ = vector<edge<T>>;\ntemplate <typename T>\nusing WeightedGraph = vector<Edges<T>>;\n\
    using UnweightedGraph = vector<vector<int>>;\n\n// Input of (Unweighted) Graph\n\
    UnweightedGraph graph(int N, int M = -1, bool is_directed = false,\n         \
    \             bool is_1origin = true) {\n  UnweightedGraph g(N);\n  if (M == -1)\
    \ M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >>\
    \ y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n    if (!is_directed)\
    \ g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of Weighted Graph\ntemplate\
    \ <typename T>\nWeightedGraph<T> wgraph(int N, int M = -1, bool is_directed =\
    \ false,\n                        bool is_1origin = true) {\n  WeightedGraph<T>\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n    if (is_1origin) x--, y--;\n\
    \    g[x].emplace_back(x, y, c);\n    if (!is_directed) g[y].emplace_back(y, x,\
    \ c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate <typename T>\nEdges<T>\
    \ esgraph([[maybe_unused]] int N, int M, int is_weighted = true,\n           \
    \      bool is_1origin = true) {\n  Edges<T> es;\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x,\
    \ y, c);\n  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename\
    \ T>\nvector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n\
    \                           bool is_directed = false, bool is_1origin = true)\
    \ {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y]\
    \ = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 11 \"graph/functional-graph.hpp\"\n\nnamespace FunctionalGraphImpl\
    \ {\n\nENABLE_HAS_VAR(cost)\n\n// \u5168\u3066\u306E\u9802\u70B9\u306E\u51FA\u6B21\
    \u6570\u304C 1\ntemplate <typename T = int>\nstruct FunctionalGraph {\n  int N;\n\
    \  WeightedGraph<T> g;\n  vector<int> to, represent;\n  vector<T> weight;\n\n\
    \  FunctionalGraph() = default;\n\n  FunctionalGraph(int n, const vector<int>&\
    \ adj,\n                  const vector<T>& w = vector<int>{})\n      : N(n), g(N\
    \ + 1), to(N + 1, -1), represent(N + 1, -1), weight(N + 1) {\n    assert((int)adj.size()\
    \ == N);\n    assert((int)w.size() == N or w.empty());\n    for (auto& x : adj)\
    \ assert(0 <= x and x < N);\n\n    UnionFind uf(N);\n    for (int i = 0; i < N;\
    \ i++) {\n      int j = adj[i];\n      to[i] = j, weight[i] = w.empty() ? T{1}\
    \ : w[i];\n      if (uf.same(i, j)) {\n        g[N].emplace_back(N, i, weight[i]);\n\
    \      } else {\n        uf.unite(i, j);\n        g[j].emplace_back(j, i, weight[i]);\n\
    \      }\n    }\n    calc_represent(N, -1);\n  }\n\n  // _g \u306F\u7121\u5411\
    \u30B0\u30E9\u30D5\n  template <typename G>\n  FunctionalGraph(int n, const G&\
    \ _g)\n      : N(n), g(N + 1), to(N + 1, -1), represent(N + 1, -1), weight(N +\
    \ 1) {\n    constexpr bool cost_flag = has_cost_v<typename G::value_type::value_type>;\n\
    \    WeightedGraph<T> h(n);\n    UnionFind uf(N);\n    for (int i = 0; i < N;\
    \ i++) {\n      for (auto& j : _g[i]) {\n        if (i > j) continue;\n      \
    \  T cost;\n        if constexpr (cost_flag) {\n          cost = j.cost;\n   \
    \     } else {\n          cost = 1;\n        }\n        if (uf.same(i, j)) {\n\
    \          // i -> j \u5411\u304D\u3068\u3044\u3046\u3053\u3068\u306B\u3057\u3066\
    , i \u3092\u6839\u3068\u3059\u308B\n          g[N].emplace_back(N, i, 0);\n  \
    \        to[i] = j, weight[i] = cost;\n        } else {\n          uf.unite(i,\
    \ j);\n          h[i].emplace_back(i, j, cost);\n          h[j].emplace_back(j,\
    \ i, cost);\n        }\n      }\n    }\n\n    auto dfs = [&](auto rc, int c, int\
    \ p) -> void {\n      for (auto& d : h[c]) {\n        if (d == p) continue;\n\
    \        T cost;\n        if constexpr (cost_flag) {\n          cost = d.cost;\n\
    \        } else {\n          cost = 1;\n        }\n        to[d] = c, weight[d]\
    \ = cost;\n        g[c].emplace_back(c, d, cost);\n        rc(rc, d, c);\n   \
    \   }\n    };\n    for (auto& r : g[N]) dfs(dfs, r, -1);\n\n    calc_represent(N,\
    \ -1);\n  }\n\n  vector<vector<int>> get_loops() const {\n    vector<vector<int>>\
    \ res;\n    for (auto r : g[N]) {\n      vector<int> cur{r};\n      for (int i\
    \ = to[r]; i != r; i = to[i]) {\n        cur.push_back(i);\n      }\n      res.push_back(cur);\n\
    \    }\n    return res;\n  }\n\n  // (u, {weight of u-v}) (v, {weight of v-w}),\
    \ (w, ...) ...\n  vector<vector<pair<int, T>>> get_loops_with_weight() const {\n\
    \    vector<vector<pair<int, T>>> res;\n    for (auto r : g[N]) {\n      vector<pair<int,\
    \ T>> cur{make_pair(r, weight[r])};\n      for (int i = to[r]; i != r; i = to[i])\
    \ {\n        cur.emplace_back(i, weight[i]);\n      }\n      res.push_back(cur);\n\
    \    }\n    return res;\n  }\n\n private:\n  void calc_represent(int c, int r)\
    \ {\n    represent[c] = r;\n    for (auto& d : g[c]) calc_represent(d, r == -1\
    \ ? d : r);\n  }\n};\n\n}  // namespace FunctionalGraphImpl\n\nusing FunctionalGraphImpl::FunctionalGraph;\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\n#include \"../data-structure/union-find.hpp\"\n#include\
    \ \"../internal/internal-type-traits.hpp\"\n#include \"graph-template.hpp\"\n\n\
    namespace FunctionalGraphImpl {\n\nENABLE_HAS_VAR(cost)\n\n// \u5168\u3066\u306E\
    \u9802\u70B9\u306E\u51FA\u6B21\u6570\u304C 1\ntemplate <typename T = int>\nstruct\
    \ FunctionalGraph {\n  int N;\n  WeightedGraph<T> g;\n  vector<int> to, represent;\n\
    \  vector<T> weight;\n\n  FunctionalGraph() = default;\n\n  FunctionalGraph(int\
    \ n, const vector<int>& adj,\n                  const vector<T>& w = vector<int>{})\n\
    \      : N(n), g(N + 1), to(N + 1, -1), represent(N + 1, -1), weight(N + 1) {\n\
    \    assert((int)adj.size() == N);\n    assert((int)w.size() == N or w.empty());\n\
    \    for (auto& x : adj) assert(0 <= x and x < N);\n\n    UnionFind uf(N);\n \
    \   for (int i = 0; i < N; i++) {\n      int j = adj[i];\n      to[i] = j, weight[i]\
    \ = w.empty() ? T{1} : w[i];\n      if (uf.same(i, j)) {\n        g[N].emplace_back(N,\
    \ i, weight[i]);\n      } else {\n        uf.unite(i, j);\n        g[j].emplace_back(j,\
    \ i, weight[i]);\n      }\n    }\n    calc_represent(N, -1);\n  }\n\n  // _g \u306F\
    \u7121\u5411\u30B0\u30E9\u30D5\n  template <typename G>\n  FunctionalGraph(int\
    \ n, const G& _g)\n      : N(n), g(N + 1), to(N + 1, -1), represent(N + 1, -1),\
    \ weight(N + 1) {\n    constexpr bool cost_flag = has_cost_v<typename G::value_type::value_type>;\n\
    \    WeightedGraph<T> h(n);\n    UnionFind uf(N);\n    for (int i = 0; i < N;\
    \ i++) {\n      for (auto& j : _g[i]) {\n        if (i > j) continue;\n      \
    \  T cost;\n        if constexpr (cost_flag) {\n          cost = j.cost;\n   \
    \     } else {\n          cost = 1;\n        }\n        if (uf.same(i, j)) {\n\
    \          // i -> j \u5411\u304D\u3068\u3044\u3046\u3053\u3068\u306B\u3057\u3066\
    , i \u3092\u6839\u3068\u3059\u308B\n          g[N].emplace_back(N, i, 0);\n  \
    \        to[i] = j, weight[i] = cost;\n        } else {\n          uf.unite(i,\
    \ j);\n          h[i].emplace_back(i, j, cost);\n          h[j].emplace_back(j,\
    \ i, cost);\n        }\n      }\n    }\n\n    auto dfs = [&](auto rc, int c, int\
    \ p) -> void {\n      for (auto& d : h[c]) {\n        if (d == p) continue;\n\
    \        T cost;\n        if constexpr (cost_flag) {\n          cost = d.cost;\n\
    \        } else {\n          cost = 1;\n        }\n        to[d] = c, weight[d]\
    \ = cost;\n        g[c].emplace_back(c, d, cost);\n        rc(rc, d, c);\n   \
    \   }\n    };\n    for (auto& r : g[N]) dfs(dfs, r, -1);\n\n    calc_represent(N,\
    \ -1);\n  }\n\n  vector<vector<int>> get_loops() const {\n    vector<vector<int>>\
    \ res;\n    for (auto r : g[N]) {\n      vector<int> cur{r};\n      for (int i\
    \ = to[r]; i != r; i = to[i]) {\n        cur.push_back(i);\n      }\n      res.push_back(cur);\n\
    \    }\n    return res;\n  }\n\n  // (u, {weight of u-v}) (v, {weight of v-w}),\
    \ (w, ...) ...\n  vector<vector<pair<int, T>>> get_loops_with_weight() const {\n\
    \    vector<vector<pair<int, T>>> res;\n    for (auto r : g[N]) {\n      vector<pair<int,\
    \ T>> cur{make_pair(r, weight[r])};\n      for (int i = to[r]; i != r; i = to[i])\
    \ {\n        cur.emplace_back(i, weight[i]);\n      }\n      res.push_back(cur);\n\
    \    }\n    return res;\n  }\n\n private:\n  void calc_represent(int c, int r)\
    \ {\n    represent[c] = r;\n    for (auto& d : g[c]) calc_represent(d, r == -1\
    \ ? d : r);\n  }\n};\n\n}  // namespace FunctionalGraphImpl\n\nusing FunctionalGraphImpl::FunctionalGraph;\n"
  dependsOn:
  - data-structure/union-find.hpp
  - internal/internal-type-traits.hpp
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/functional-graph.hpp
  requiredBy: []
  timestamp: '2024-08-10 13:03:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-2891-2.test.cpp
  - verify/verify-yuki/yuki-1254-2.test.cpp
documentation_of: graph/functional-graph.hpp
layout: document
redirect_from:
- /library/graph/functional-graph.hpp
- /library/graph/functional-graph.hpp.html
title: graph/functional-graph.hpp
---

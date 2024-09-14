---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: tree/convert-tree.hpp
    title: "\u6839\u4ED8\u304D\u6728\u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\
      \u3078\u306E\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: tree/heavy-light-decomposition.hpp
    title: "Heavy Light Decomposition(\u91CD\u8EFD\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/static-top-tree-edge-based.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\n#line 2 \"tree/convert-tree.hpp\"\
    \n\n#line 2 \"graph/graph-template.hpp\"\n\ntemplate <typename T>\nstruct edge\
    \ {\n  int src, to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to),\
    \ cost(_cost) {}\n  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost)\
    \ {}\n\n  edge &operator=(const int &x) {\n    to = x;\n    return *this;\n  }\n\
    \n  operator int() const { return to; }\n};\ntemplate <typename T>\nusing Edges\
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
    \ */\n#line 4 \"tree/convert-tree.hpp\"\n\ntemplate <typename T>\nstruct has_cost\
    \ {\n private:\n  template <typename U>\n  static auto confirm(U u) -> decltype(u.cost,\
    \ std::true_type());\n  static auto confirm(...) -> std::false_type;\n\n public:\n\
    \  enum : bool { value = decltype(confirm(std::declval<T>()))::value };\n};\n\n\
    template <typename T>\nvector<vector<T>> inverse_tree(const vector<vector<T>>&\
    \ g) {\n  int N = (int)g.size();\n  vector<vector<T>> rg(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    for (auto& e : g[i]) {\n      if constexpr (is_same<T, int>::value)\
    \ {\n        rg[e].push_back(i);\n      } else if constexpr (has_cost<T>::value)\
    \ {\n        rg[e].emplace_back(e.to, i, e.cost);\n      } else {\n        assert(0);\n\
    \      }\n    }\n  }\n  return rg;\n}\n\ntemplate <typename T>\nvector<vector<T>>\
    \ rooted_tree(const vector<vector<T>>& g, int root = 0) {\n  int N = (int)g.size();\n\
    \  vector<vector<T>> rg(N);\n  vector<char> v(N, false);\n  v[root] = true;\n\
    \  queue<int> que;\n  que.emplace(root);\n  while (!que.empty()) {\n    auto p\
    \ = que.front();\n    que.pop();\n    for (auto& e : g[p]) {\n      if (v[e] ==\
    \ false) {\n        v[e] = true;\n        que.push(e);\n        rg[p].push_back(e);\n\
    \      }\n    }\n  }\n  return rg;\n}\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\
    \u30FB\u9006\u8FBA\u304B\u3089\u306A\u308B\u6728\u3078\u306E\u5909\u63DB\n */\n\
    #line 2 \"tree/heavy-light-decomposition.hpp\"\n\n#line 4 \"tree/heavy-light-decomposition.hpp\"\
    \n\ntemplate <typename G>\nstruct HeavyLightDecomposition {\n private:\n  void\
    \ dfs_sz(int cur) {\n    size[cur] = 1;\n    for (auto& dst : g[cur]) {\n    \
    \  if (dst == par[cur]) {\n        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n\
    \          swap(g[cur][0], g[cur][1]);\n        else\n          continue;\n  \
    \    }\n      depth[dst] = depth[cur] + 1;\n      par[dst] = cur;\n      dfs_sz(dst);\n\
    \      size[cur] += size[dst];\n      if (size[dst] > size[g[cur][0]]) {\n   \
    \     swap(dst, g[cur][0]);\n      }\n    }\n  }\n\n  void dfs_hld(int cur) {\n\
    \    down[cur] = id++;\n    for (auto dst : g[cur]) {\n      if (dst == par[cur])\
    \ continue;\n      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\
    \      dfs_hld(dst);\n    }\n    up[cur] = id;\n  }\n\n  // [u, v)\n  vector<pair<int,\
    \ int>> ascend(int u, int v) const {\n    vector<pair<int, int>> res;\n    while\
    \ (nxt[u] != nxt[v]) {\n      res.emplace_back(down[u], down[nxt[u]]);\n     \
    \ u = par[nxt[u]];\n    }\n    if (u != v) res.emplace_back(down[u], down[v] +\
    \ 1);\n    return res;\n  }\n\n  // (u, v]\n  vector<pair<int, int>> descend(int\
    \ u, int v) const {\n    if (u == v) return {};\n    if (nxt[u] == nxt[v]) return\
    \ {{down[u] + 1, down[v]}};\n    auto res = descend(u, par[nxt[v]]);\n    res.emplace_back(down[nxt[v]],\
    \ down[v]);\n    return res;\n  }\n\n public:\n  G& g;\n  int root, id;\n  vector<int>\
    \ size, depth, down, up, nxt, par;\n  HeavyLightDecomposition(G& _g, int _root\
    \ = 0)\n      : g(_g),\n        root(_root),\n        id(0),\n        size(g.size(),\
    \ 0),\n        depth(g.size(), 0),\n        down(g.size(), -1),\n        up(g.size(),\
    \ -1),\n        nxt(g.size(), root),\n        par(g.size(), root) {\n    dfs_sz(root);\n\
    \    dfs_hld(root);\n  }\n\n  pair<int, int> idx(int i) const { return make_pair(down[i],\
    \ up[i]); }\n\n  template <typename F>\n  void path_query(int u, int v, bool vertex,\
    \ const F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l))\
    \ {\n      int s = a + 1, t = b;\n      s > t ? f(t, s) : f(s, t);\n    }\n  \
    \  if (vertex) f(down[l], down[l] + 1);\n    for (auto&& [a, b] : descend(l, v))\
    \ {\n      int s = a, t = b + 1;\n      s > t ? f(t, s) : f(s, t);\n    }\n  }\n\
    \n  template <typename F>\n  void path_noncommutative_query(int u, int v, bool\
    \ vertex, const F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u,\
    \ l)) f(a + 1, b);\n    if (vertex) f(down[l], down[l] + 1);\n    for (auto&&\
    \ [a, b] : descend(l, v)) f(a, b + 1);\n  }\n\n  template <typename F>\n  void\
    \ subtree_query(int u, bool vertex, const F& f) {\n    f(down[u] + int(!vertex),\
    \ up[u]);\n  }\n\n  int lca(int a, int b) {\n    while (nxt[a] != nxt[b]) {\n\
    \      if (down[a] < down[b]) swap(a, b);\n      a = par[nxt[a]];\n    }\n   \
    \ return depth[a] < depth[b] ? a : b;\n  }\n\n  int dist(int a, int b) { return\
    \ depth[a] + depth[b] - depth[lca(a, b)] * 2; }\n};\n\n/**\n * @brief Heavy Light\
    \ Decomposition(\u91CD\u8EFD\u5206\u89E3)\n * @docs docs/tree/heavy-light-decomposition.md\n\
    \ */\n#line 10 \"tree/static-top-tree-edge-based.hpp\"\n\nnamespace StaticTopTreeImpl\
    \ {\n\nenum Type { Edge, Compress, Rake };\n\ntemplate <typename G>\nstruct StaticTopTree\
    \ {\n  const HeavyLightDecomposition<G>& hld;\n  vector<vector<int>> g;\n  int\
    \ root;     // \u5143\u306E\u6728\u306E root\n  int tt_root;  // top tree \u306E\
    \ root\n  vector<int> P, L, R;\n  vector<Type> T;\n\n  StaticTopTree(const HeavyLightDecomposition<G>&\
    \ _hld) : hld(_hld) {\n    root = hld.root;\n    g = rooted_tree(hld.g, root);\n\
    \    int n = g.size();\n    P.resize(n, -1), L.resize(n, -1), R.resize(n, -1);\n\
    \    T.resize(n, Type::Edge);\n    build();\n  }\n\n private:\n  int add(int l,\
    \ int r, Type t) {\n    if (t == Type::Compress or t == Type::Rake) {\n      assert(l\
    \ != -1 and r != -1);\n    }\n    assert(t != Type::Edge);\n    int k = P.size();\n\
    \    P.push_back(-1), L.push_back(l), R.push_back(r), T.push_back(t);\n    if\
    \ (l != -1) P[l] = k;\n    if (r != -1) P[r] = k;\n    return k;\n  }\n  pair<int,\
    \ int> merge(const vector<pair<int, int>>& a, Type t) {\n    assert(!a.empty());\n\
    \    if (a.size() == 1) return a[0];\n    int sum_s = 0;\n    for (auto& [_, s]\
    \ : a) sum_s += s;\n    vector<pair<int, int>> b, c;\n    for (auto& [i, s] :\
    \ a) {\n      (sum_s > s ? b : c).emplace_back(i, s);\n      sum_s -= s * 2;\n\
    \    }\n    auto [i, si] = merge(b, t);\n    auto [j, sj] = merge(c, t);\n   \
    \ return {add(i, j, t), si + sj};\n  }\n  pair<int, int> compress(int i) {\n \
    \   vector<pair<int, int>> chs{{i, 1}};\n    while (!g[i].empty()) {\n      chs.push_back(rake(i));\n\
    \      i = g[i][0];\n    }\n    return merge(chs, Type::Compress);\n  }\n  pair<int,\
    \ int> rake(int i) {\n    vector<pair<int, int>> chs{{g[i][0], 1}};\n    for (int\
    \ j = 1; j < (int)g[i].size(); j++) chs.push_back(compress(g[i][j]));\n    return\
    \ merge(chs, Type::Rake);\n  }\n  void build() {\n    auto [i, n] = compress(root);\n\
    \    assert((int)g.size() == n);\n    assert((int)P.size() == n * 2 - 1);\n  \
    \  tt_root = i;\n  }\n};\n\ntemplate <typename G, typename Data, typename Edge,\
    \ typename Compress,\n          typename Rake>\nstruct DPonStaticTopTree {\n \
    \ const StaticTopTree<G> tt;\n  vector<Data> dat;\n  const Edge edge;\n  const\
    \ Compress compress;\n  const Rake rake;\n\n  DPonStaticTopTree(const HeavyLightDecomposition<G>&\
    \ hld, const Edge& _edge,\n                    const Compress& _compress, const\
    \ Rake& _rake)\n      : tt(hld), edge(_edge), compress(_compress), rake(_rake)\
    \ {\n    int n = tt.P.size();\n    dat.resize(n);\n    dfs(tt.tt_root);\n  }\n\
    \n  Data get() { return dat[tt.tt_root]; }\n  void update(int k) {\n    while\
    \ (k != -1) _update(k), k = tt.P[k];\n  }\n\n private:\n  void _update(int k)\
    \ {\n    if (tt.T[k] == Type::Edge) {\n      dat[k] = edge(k);\n    } else if\
    \ (tt.T[k] == Type::Compress) {\n      dat[k] = compress(dat[tt.L[k]], dat[tt.R[k]]);\n\
    \    } else if (tt.T[k] == Type::Rake) {\n      dat[k] = rake(dat[tt.L[k]], dat[tt.R[k]]);\n\
    \    }\n  }\n\n  void dfs(int k) {\n    if (tt.L[k] != -1) dfs(tt.L[k]);\n   \
    \ if (tt.R[k] != -1) dfs(tt.R[k]);\n    _update(k);\n  }\n};\n\n}  // namespace\
    \ StaticTopTreeImpl\n\nusing StaticTopTreeImpl::DPonStaticTopTree;\nusing StaticTopTreeImpl::StaticTopTree;\n\
    \n/*\n  // template\n  using Data = ;\n  auto edge = [&](int i) -> Data {\n\n\
    \  };\n  auto compress = [&](const Data& p, const Data& c) -> Data {\n\n  };\n\
    \  auto rake = [&](const Data& p, const Data& c) -> Data {\n\n  };\n  HeavyLightDecomposition\
    \ hld{g};\n  DPonStaticTopTree<vector<vector<int>>, Data, decltype(edge),\n  \
    \                  decltype(compress), decltype(rake)>\n      dp(hld, edge, compress,\
    \ rake);\n*/\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\n#include \"convert-tree.hpp\"\n#include \"heavy-light-decomposition.hpp\"\
    \n\nnamespace StaticTopTreeImpl {\n\nenum Type { Edge, Compress, Rake };\n\ntemplate\
    \ <typename G>\nstruct StaticTopTree {\n  const HeavyLightDecomposition<G>& hld;\n\
    \  vector<vector<int>> g;\n  int root;     // \u5143\u306E\u6728\u306E root\n\
    \  int tt_root;  // top tree \u306E root\n  vector<int> P, L, R;\n  vector<Type>\
    \ T;\n\n  StaticTopTree(const HeavyLightDecomposition<G>& _hld) : hld(_hld) {\n\
    \    root = hld.root;\n    g = rooted_tree(hld.g, root);\n    int n = g.size();\n\
    \    P.resize(n, -1), L.resize(n, -1), R.resize(n, -1);\n    T.resize(n, Type::Edge);\n\
    \    build();\n  }\n\n private:\n  int add(int l, int r, Type t) {\n    if (t\
    \ == Type::Compress or t == Type::Rake) {\n      assert(l != -1 and r != -1);\n\
    \    }\n    assert(t != Type::Edge);\n    int k = P.size();\n    P.push_back(-1),\
    \ L.push_back(l), R.push_back(r), T.push_back(t);\n    if (l != -1) P[l] = k;\n\
    \    if (r != -1) P[r] = k;\n    return k;\n  }\n  pair<int, int> merge(const\
    \ vector<pair<int, int>>& a, Type t) {\n    assert(!a.empty());\n    if (a.size()\
    \ == 1) return a[0];\n    int sum_s = 0;\n    for (auto& [_, s] : a) sum_s +=\
    \ s;\n    vector<pair<int, int>> b, c;\n    for (auto& [i, s] : a) {\n      (sum_s\
    \ > s ? b : c).emplace_back(i, s);\n      sum_s -= s * 2;\n    }\n    auto [i,\
    \ si] = merge(b, t);\n    auto [j, sj] = merge(c, t);\n    return {add(i, j, t),\
    \ si + sj};\n  }\n  pair<int, int> compress(int i) {\n    vector<pair<int, int>>\
    \ chs{{i, 1}};\n    while (!g[i].empty()) {\n      chs.push_back(rake(i));\n \
    \     i = g[i][0];\n    }\n    return merge(chs, Type::Compress);\n  }\n  pair<int,\
    \ int> rake(int i) {\n    vector<pair<int, int>> chs{{g[i][0], 1}};\n    for (int\
    \ j = 1; j < (int)g[i].size(); j++) chs.push_back(compress(g[i][j]));\n    return\
    \ merge(chs, Type::Rake);\n  }\n  void build() {\n    auto [i, n] = compress(root);\n\
    \    assert((int)g.size() == n);\n    assert((int)P.size() == n * 2 - 1);\n  \
    \  tt_root = i;\n  }\n};\n\ntemplate <typename G, typename Data, typename Edge,\
    \ typename Compress,\n          typename Rake>\nstruct DPonStaticTopTree {\n \
    \ const StaticTopTree<G> tt;\n  vector<Data> dat;\n  const Edge edge;\n  const\
    \ Compress compress;\n  const Rake rake;\n\n  DPonStaticTopTree(const HeavyLightDecomposition<G>&\
    \ hld, const Edge& _edge,\n                    const Compress& _compress, const\
    \ Rake& _rake)\n      : tt(hld), edge(_edge), compress(_compress), rake(_rake)\
    \ {\n    int n = tt.P.size();\n    dat.resize(n);\n    dfs(tt.tt_root);\n  }\n\
    \n  Data get() { return dat[tt.tt_root]; }\n  void update(int k) {\n    while\
    \ (k != -1) _update(k), k = tt.P[k];\n  }\n\n private:\n  void _update(int k)\
    \ {\n    if (tt.T[k] == Type::Edge) {\n      dat[k] = edge(k);\n    } else if\
    \ (tt.T[k] == Type::Compress) {\n      dat[k] = compress(dat[tt.L[k]], dat[tt.R[k]]);\n\
    \    } else if (tt.T[k] == Type::Rake) {\n      dat[k] = rake(dat[tt.L[k]], dat[tt.R[k]]);\n\
    \    }\n  }\n\n  void dfs(int k) {\n    if (tt.L[k] != -1) dfs(tt.L[k]);\n   \
    \ if (tt.R[k] != -1) dfs(tt.R[k]);\n    _update(k);\n  }\n};\n\n}  // namespace\
    \ StaticTopTreeImpl\n\nusing StaticTopTreeImpl::DPonStaticTopTree;\nusing StaticTopTreeImpl::StaticTopTree;\n\
    \n/*\n  // template\n  using Data = ;\n  auto edge = [&](int i) -> Data {\n\n\
    \  };\n  auto compress = [&](const Data& p, const Data& c) -> Data {\n\n  };\n\
    \  auto rake = [&](const Data& p, const Data& c) -> Data {\n\n  };\n  HeavyLightDecomposition\
    \ hld{g};\n  DPonStaticTopTree<vector<vector<int>>, Data, decltype(edge),\n  \
    \                  decltype(compress), decltype(rake)>\n      dp(hld, edge, compress,\
    \ rake);\n*/\n"
  dependsOn:
  - tree/convert-tree.hpp
  - graph/graph-template.hpp
  - tree/heavy-light-decomposition.hpp
  isVerificationFile: false
  path: tree/static-top-tree-edge-based.hpp
  requiredBy: []
  timestamp: '2024-05-04 15:53:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/static-top-tree-edge-based.hpp
layout: document
redirect_from:
- /library/tree/static-top-tree-edge-based.hpp
- /library/tree/static-top-tree-edge-based.hpp.html
title: tree/static-top-tree-edge-based.hpp
---
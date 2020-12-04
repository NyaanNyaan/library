---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-c.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-d.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-d.test.cpp
  - icon: ':x:'
    path: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp
    title: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/tree/heavy-light-decomposition.md
    document_title: "Heavy Light Decomposition(\u91CD\u8EFD\u5206\u89E3)"
    links: []
  bundledCode: "#line 2 \"tree/heavy-light-decomposition.hpp\"\n\n\n\n#line 2 \"graph/graph-template.hpp\"\
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
    \ c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n#line 6 \"tree/heavy-light-decomposition.hpp\"\
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
    \ down[v]);\n    return res;\n  }\n\n public:\n  G& g;\n  int id;\n  vector<int>\
    \ size, depth, down, up, nxt, par;\n  HeavyLightDecomposition(G& _g, int root\
    \ = 0)\n      : g(_g),\n        id(0),\n        size(g.size(), 0),\n        depth(g.size(),\
    \ 0),\n        down(g.size(), -1),\n        up(g.size(), -1),\n        nxt(g.size(),\
    \ root),\n        par(g.size(), root) {\n    dfs_sz(root);\n    dfs_hld(root);\n\
    \  }\n\n  void build(int root) {\n    dfs_sz(root);\n    dfs_hld(root);\n  }\n\
    \n  pair<int, int> idx(int i) const { return make_pair(down[i], up[i]); }\n\n\
    \  template <typename F>\n  void path_query(int u, int v, bool vertex, const F&\
    \ f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l)) {\n   \
    \   int s = a + 1, t = b;\n      s > t ? f(t, s) : f(s, t);\n    }\n    if (vertex)\
    \ f(down[l], down[l] + 1);\n    for (auto&& [a, b] : descend(l, v)) {\n      int\
    \ s = a, t = b + 1;\n      s > t ? f(t, s) : f(s, t);\n    }\n  }\n\n  template\
    \ <typename F>\n  void path_noncommutative_query(int u, int v, bool vertex, const\
    \ F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l)) f(a\
    \ + 1, b);\n    if (vertex) f(down[l], down[l] + 1);\n    for (auto&& [a, b] :\
    \ descend(l, v)) f(a, b + 1);\n  }\n\n  template <typename F>\n  void subtree_query(int\
    \ u, bool vertex, const F& f) {\n    f(down[u] + int(!vertex), up[u]);\n  }\n\n\
    \  int lca(int a, int b) {\n    while (nxt[a] != nxt[b]) {\n      if (down[a]\
    \ < down[b]) swap(a, b);\n      a = par[nxt[a]];\n    }\n    return depth[a] <\
    \ depth[b] ? a : b;\n  }\n};\n\n/**\n * @brief Heavy Light Decomposition(\u91CD\
    \u8EFD\u5206\u89E3)\n * @docs docs/tree/heavy-light-decomposition.md\n */\n"
  code: "#pragma once\n\n\n\n#include \"../graph/graph-template.hpp\"\n\ntemplate\
    \ <typename G>\nstruct HeavyLightDecomposition {\n private:\n  void dfs_sz(int\
    \ cur) {\n    size[cur] = 1;\n    for (auto& dst : g[cur]) {\n      if (dst ==\
    \ par[cur]) {\n        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n\
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
    \ down[v]);\n    return res;\n  }\n\n public:\n  G& g;\n  int id;\n  vector<int>\
    \ size, depth, down, up, nxt, par;\n  HeavyLightDecomposition(G& _g, int root\
    \ = 0)\n      : g(_g),\n        id(0),\n        size(g.size(), 0),\n        depth(g.size(),\
    \ 0),\n        down(g.size(), -1),\n        up(g.size(), -1),\n        nxt(g.size(),\
    \ root),\n        par(g.size(), root) {\n    dfs_sz(root);\n    dfs_hld(root);\n\
    \  }\n\n  void build(int root) {\n    dfs_sz(root);\n    dfs_hld(root);\n  }\n\
    \n  pair<int, int> idx(int i) const { return make_pair(down[i], up[i]); }\n\n\
    \  template <typename F>\n  void path_query(int u, int v, bool vertex, const F&\
    \ f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l)) {\n   \
    \   int s = a + 1, t = b;\n      s > t ? f(t, s) : f(s, t);\n    }\n    if (vertex)\
    \ f(down[l], down[l] + 1);\n    for (auto&& [a, b] : descend(l, v)) {\n      int\
    \ s = a, t = b + 1;\n      s > t ? f(t, s) : f(s, t);\n    }\n  }\n\n  template\
    \ <typename F>\n  void path_noncommutative_query(int u, int v, bool vertex, const\
    \ F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l)) f(a\
    \ + 1, b);\n    if (vertex) f(down[l], down[l] + 1);\n    for (auto&& [a, b] :\
    \ descend(l, v)) f(a, b + 1);\n  }\n\n  template <typename F>\n  void subtree_query(int\
    \ u, bool vertex, const F& f) {\n    f(down[u] + int(!vertex), up[u]);\n  }\n\n\
    \  int lca(int a, int b) {\n    while (nxt[a] != nxt[b]) {\n      if (down[a]\
    \ < down[b]) swap(a, b);\n      a = par[nxt[a]];\n    }\n    return depth[a] <\
    \ depth[b] ? a : b;\n  }\n};\n\n/**\n * @brief Heavy Light Decomposition(\u91CD\
    \u8EFD\u5206\u89E3)\n * @docs docs/tree/heavy-light-decomposition.md\n */\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/heavy-light-decomposition.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-5-c.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-d.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp
  - verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
documentation_of: tree/heavy-light-decomposition.hpp
layout: document
redirect_from:
- /library/tree/heavy-light-decomposition.hpp
- /library/tree/heavy-light-decomposition.hpp.html
title: "Heavy Light Decomposition(\u91CD\u8EFD\u5206\u89E3)"
---
## Heavy Light Decomposition(重軽分解)

#### 概要

Heavy Light Decomposition(重軽分解、HLDec)とは、木のパスをheavy pathとlight pathに分けて管理するデータ構造である。

HLDecの特長は「任意のパスを$\rm{O}(\log N)$本の列に分解する」という点である。木をHLDecで管理することで木に対する問題を列に対する問題として処理することができるため、「パス上の頂点の持つ値を同時に更新する」といった木上のパスに関するクエリを容易に処理することが出来るようになる。

#### 使い方

- `HeavyLightDecomposition(g, root=0)`:`root`を根とした重軽分解を構築する。$\mathrm{O}(N)$
- `idx(i)`: 頂点iのオイラーツアー順を`pair(down, up)`の形で返す。$\mathrm{O}(1)$
- `path_query(u, v, vertex, f)`: **可換な**パスクエリを処理する。$\mathrm{O}(\log^2N)$
- `path_noncommutative_query(u, v, vertex, f)`: **非可換な**パスクエリを処理する。$\mathrm{O}(\log^2N)$
- `subtree_query(u, vertex, f)`: 部分木クエリを処理する。$\mathrm{O}(\log^N)$
- `lca(u, v)`: uとvの最小共通祖先(LCA)を返す。$\mathrm{O}(\log^N)$

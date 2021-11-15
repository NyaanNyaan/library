---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-euler-tree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-euler-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-euler-tour.test.cpp
    title: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-euler-tour.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/euler-tour.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
    links: []
  bundledCode: "#line 2 \"tree/euler-tour.hpp\"\n\n\n\n#line 2 \"graph/graph-template.hpp\"\
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
    \ c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n#line 6 \"tree/euler-tour.hpp\"\
    \n\ntemplate <typename G>\nstruct EulerTour {\n private:\n  struct RMQ {\n   \
    \ int n, s;\n    using P = pair<int, int>;\n    vector<P> seg;\n    P UNIT = P(1\
    \ << 30, -1);\n\n    RMQ(int N) : n(N), s(1) {\n      while (s < N) s <<= 1;\n\
    \      seg.assign(2 * s, UNIT);\n    }\n\n    void set(int k, P x) { seg[k + s]\
    \ = x; }\n\n    P operator[](int k) const { return seg[k + s]; }\n\n    void build()\
    \ {\n      for (int k = s - 1; k > 0; k--) {\n        seg[k] = min(seg[2 * k],\
    \ seg[2 * k + 1]);\n      }\n    }\n\n    P query(int a, int b) const {\n    \
    \  P R = UNIT;\n      for (a += s, b += s; a < b; a >>= 1, b >>= 1) {\n      \
    \  if (a & 1) R = min(R, seg[a++]);\n        if (b & 1) R = min(R, seg[--b]);\n\
    \      }\n      return R;\n    }\n\n    int size() const { return n; }\n  };\n\
    \n  vector<int> down, up;\n  int id;\n  RMQ rmq;\n\n  void init(G &g, int root)\
    \ {\n    dfs(g, root, -1, 0);\n    if (id < rmq.size()) rmq.set(id++, {-1, -1});\n\
    \    for (int i = 0; i < (int)g.size(); i++) {\n      if (down[i] == -1) {\n \
    \       rmq.set(id++, {-1, -1});\n        dfs(g, i, -1, 0);\n        if (id <\
    \ rmq.size()) rmq.set(id++, {-1, -1});\n      }\n    }\n    rmq.build();\n  }\n\
    \n  void dfs(G &g, int c, int p, int dp) {\n    down[c] = id;\n    rmq.set(id++,\
    \ {dp, c});\n    for (auto &d : g[c]) {\n      if (d == p) continue;\n      dfs(g,\
    \ d, c, dp + 1);\n    }\n    up[c] = id;\n    if (p != -1) rmq.set(id++, {dp -\
    \ 1, p});\n  }\n\n public:\n  // remind : because of additional node,\n  // DS\
    \ on tour should reserve 2 * n nodes.\n  EulerTour(G &g, int root = 0)\n     \
    \ : down(g.size(), -1), up(g.size(), -1), id(0), rmq(2 * g.size()) {\n    init(g,\
    \ root);\n  }\n\n  pair<int, int> idx(int i) const { return {down[i], up[i]};\
    \ }\n\n  int lca(int a, int b) const {\n    if (down[a] > down[b]) swap(a, b);\n\
    \    return rmq.query(down[a], down[b] + 1).second;\n  }\n\n  template <typename\
    \ F>\n  void node_query(int a, int b, const F &f) {\n    int l = lca(a, b);\n\
    \    f(down[l], down[a] + 1);\n    f(down[l] + 1, down[b] + 1);\n  }\n\n  template\
    \ <typename F>\n  void edge_query(int a, int b, const F &f) {\n    int l = lca(a,\
    \ b);\n    f(down[l] + 1, down[a] + 1);\n    f(down[l] + 1, down[b] + 1);\n  }\n\
    \n  template <typename F>\n  void subtree_query(int a, const F &f) {\n    f(down[a],\
    \ up[a]);\n  }\n\n  int size() const { return int(rmq.size()); }\n};\n\n/**\n\
    \ * @brief \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\n * @docs docs/tree/euler-tour.md\n\
    \ */\n"
  code: "#pragma once\n\n\n\n#include \"../graph/graph-template.hpp\"\n\ntemplate\
    \ <typename G>\nstruct EulerTour {\n private:\n  struct RMQ {\n    int n, s;\n\
    \    using P = pair<int, int>;\n    vector<P> seg;\n    P UNIT = P(1 << 30, -1);\n\
    \n    RMQ(int N) : n(N), s(1) {\n      while (s < N) s <<= 1;\n      seg.assign(2\
    \ * s, UNIT);\n    }\n\n    void set(int k, P x) { seg[k + s] = x; }\n\n    P\
    \ operator[](int k) const { return seg[k + s]; }\n\n    void build() {\n     \
    \ for (int k = s - 1; k > 0; k--) {\n        seg[k] = min(seg[2 * k], seg[2 *\
    \ k + 1]);\n      }\n    }\n\n    P query(int a, int b) const {\n      P R = UNIT;\n\
    \      for (a += s, b += s; a < b; a >>= 1, b >>= 1) {\n        if (a & 1) R =\
    \ min(R, seg[a++]);\n        if (b & 1) R = min(R, seg[--b]);\n      }\n     \
    \ return R;\n    }\n\n    int size() const { return n; }\n  };\n\n  vector<int>\
    \ down, up;\n  int id;\n  RMQ rmq;\n\n  void init(G &g, int root) {\n    dfs(g,\
    \ root, -1, 0);\n    if (id < rmq.size()) rmq.set(id++, {-1, -1});\n    for (int\
    \ i = 0; i < (int)g.size(); i++) {\n      if (down[i] == -1) {\n        rmq.set(id++,\
    \ {-1, -1});\n        dfs(g, i, -1, 0);\n        if (id < rmq.size()) rmq.set(id++,\
    \ {-1, -1});\n      }\n    }\n    rmq.build();\n  }\n\n  void dfs(G &g, int c,\
    \ int p, int dp) {\n    down[c] = id;\n    rmq.set(id++, {dp, c});\n    for (auto\
    \ &d : g[c]) {\n      if (d == p) continue;\n      dfs(g, d, c, dp + 1);\n   \
    \ }\n    up[c] = id;\n    if (p != -1) rmq.set(id++, {dp - 1, p});\n  }\n\n public:\n\
    \  // remind : because of additional node,\n  // DS on tour should reserve 2 *\
    \ n nodes.\n  EulerTour(G &g, int root = 0)\n      : down(g.size(), -1), up(g.size(),\
    \ -1), id(0), rmq(2 * g.size()) {\n    init(g, root);\n  }\n\n  pair<int, int>\
    \ idx(int i) const { return {down[i], up[i]}; }\n\n  int lca(int a, int b) const\
    \ {\n    if (down[a] > down[b]) swap(a, b);\n    return rmq.query(down[a], down[b]\
    \ + 1).second;\n  }\n\n  template <typename F>\n  void node_query(int a, int b,\
    \ const F &f) {\n    int l = lca(a, b);\n    f(down[l], down[a] + 1);\n    f(down[l]\
    \ + 1, down[b] + 1);\n  }\n\n  template <typename F>\n  void edge_query(int a,\
    \ int b, const F &f) {\n    int l = lca(a, b);\n    f(down[l] + 1, down[a] + 1);\n\
    \    f(down[l] + 1, down[b] + 1);\n  }\n\n  template <typename F>\n  void subtree_query(int\
    \ a, const F &f) {\n    f(down[a], up[a]);\n  }\n\n  int size() const { return\
    \ int(rmq.size()); }\n};\n\n/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
    \u30FC\n * @docs docs/tree/euler-tour.md\n */\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/euler-tour.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-euler-tour.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-euler-tree.test.cpp
documentation_of: tree/euler-tour.hpp
layout: document
redirect_from:
- /library/tree/euler-tour.hpp
- /library/tree/euler-tour.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC"
---
## Euler Tour

無向森が与えられたときにそれぞれの木に対してEuler Tourを構築するライブラリ。

#### 概要

TODO: アルゴリズムの説明を書く

TODO: 森が与えられた時と辺クエリのverifyを書いていないので、書く

備忘録

- <span style="font-size: 200%; color: red;">アーベル環を載せたパスクエリは$[\mathrm{down}(i)+1,\mathrm{down}(j)+1)$に$\mathrm{lca}(i,j)$を加えたもの！</span>

- LCAを求めるときとパスクエリで記録する値が違う
  - LCAの時は原義のオイラーツアー(たぶん)
  - パスクエリは入る時と出る時を記録
- 逆元つきモノイドはEuler Tourでクエリ$\mathrm{O}(\log N)$
- 逆元なしモノイドはHL Decでクエリ$\mathrm{O}(\log^2 N)$

#### 使い方

- `EulerTour(g, root)`: グラフ`g`に対して`root`を最初の根とするオイラーツアーを構築する。
- `lca(u, v)`:$\mathrm{lca}(u,v)$を返す。
- `idx(i)` : `make_pair(down[i], up[i])`を返す。ここで`down[i]`は頂点iに入った時のid、`up[i]`は頂点iから出た時のidである。
- `path_query(u, v, f)`: 頂点クエリ用の関数。
- `edge_query(u, v, f)`: 辺クエリ用の関数。
- `subtree_query(u, v, f)`: 部分木クエリ用の関数。

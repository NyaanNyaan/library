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
  bundledCode: "#line 2 \"tree/euler-tour.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 3 \"graph/graph-template.hpp\"\nusing namespace std;\n\ntemplate\
    \ <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int _to, T\
    \ _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int _src, int _to, T _cost)\
    \ : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const int &x) {\n\
    \    to = x;\n    return *this;\n  }\n\n  operator int() const { return to; }\n\
    };\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\ntemplate <typename\
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
    \ d;\n}\n#line 6 \"tree/euler-tour.hpp\"\n\n// ** NOT RECOMMEND TO USE **\n//\
    \ euler tour of node \nstruct EulerTour {\n  struct UnionFind {\n    vector<int>\
    \ data;\n    UnionFind(int N) : data(N, -1) {}\n\n    int find(int k) { return\
    \ data[k] < 0 ? k : data[k] = find(data[k]); }\n\n    int unite(int x, int y)\
    \ {\n      if ((x = find(x)) == (y = find(y))) return false;\n      if (data[x]\
    \ > data[y]) swap(x, y);\n      data[x] += data[y];\n      data[y] = x;\n    \
    \  return true;\n    }\n\n    int size(int k) { return -data[find(k)]; }\n\n \
    \   int same(int x, int y) { return find(x) == find(y); }\n  };\n\n  struct SegmentTree_RangeMin\
    \ {\n    int size;\n    using P = pair<int, int>;\n    vector<P> seg;\n    P UNIT\
    \ = P(1 << 30, -1);\n\n    SegmentTree_RangeMin() {}\n\n    SegmentTree_RangeMin(int\
    \ N) {\n      size = 1;\n      while (size < N) size <<= 1;\n      seg.assign(2\
    \ * size, UNIT);\n    }\n\n    void set(int k, P x) { seg[k + size] = x; }\n\n\
    \    void build() {\n      for (int k = size - 1; k > 0; k--) {\n        seg[k]\
    \ = min(seg[2 * k], seg[2 * k + 1]);\n      }\n    }\n\n    // query to [a, b)\n\
    \    P query(int a, int b) {\n      P L = UNIT, R = UNIT;\n      for (a += size,\
    \ b += size; a < b; a >>= 1, b >>= 1) {\n        if (a & 1) L = min(L, seg[a++]);\n\
    \        if (b & 1) R = min(seg[--b], R);\n      }\n      return min(L, R);\n\
    \    }\n  };\n\n  using G = vector<vector<int>>;\n\n  UnionFind uf;\n  vector<int>\
    \ down, up, tour, par, depth;\n  int i_;\n  SegmentTree_RangeMin lca_seg;\n\n\
    \  EulerTour(G &g)\n      : uf(g.size()),\n        down(g.size(), -1),\n     \
    \   up(g.size()),\n        tour(g.size() * 2),\n        par(g.size()),\n     \
    \   depth(g.size(), -1),\n        i_(0),\n        lca_seg(2 * g.size()) {\n  \
    \  vector<int> isroot(g.size(), 1);\n    for (int i = 0; i < (int)g.size(); i++)\
    \ {\n      for (auto &d : g[i]) isroot[d] = 0;\n    }\n    for (int i = 0; i <\
    \ (int)g.size(); i++) {\n      if (!isroot[i]) continue;\n      dfs(g, i, -1);\n\
    \    }\n    lca_seg.build();\n  }\n\n  void dfs(G &g, int c, int p) {\n    down[c]\
    \ = i_;\n    par[c] = p;\n    depth[c] = ~p ? depth[p] + 1 : 0;\n    lca_seg.set(i_,\
    \ {depth[c], c});\n    tour[i_++] = c;\n    if (~p) uf.unite(c, p);\n    for (auto\
    \ &d : g[c]) {\n      if (d == p) continue;\n      dfs(g, d, c);\n    }\n    up[c]\
    \ = i_;\n    if (~p) lca_seg.set(i_, {depth[p], p});\n    tour[i_++] = c;\n  }\n\
    \n  int lca(int a, int b) {\n    if (!uf.same(a, b)) return -1;\n    if (down[a]\
    \ > down[b]) swap(a, b);\n    return lca_seg.query(down[a], down[b] + 1).second;\n\
    \  }\n\n  template <typename F>\n  void node_query(int a, int b, F &f) {\n   \
    \ int l = lca(a, b);\n    assert(l != -1);\n    f(down[l], down[a] + 1);\n   \
    \ f(down[l] + 1, down[b] + 1);\n  }\n\n  template <typename F>\n  void edge_query(int\
    \ a, int b, F &f) {\n    int l = lca(a, b);\n    assert(l != -1);\n    f(down[l]\
    \ + 1, down[a] + 1);\n    f(down[l] + 1, down[b] + 1);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../graph/graph-template.hpp\"\n\n// ** NOT RECOMMEND TO USE **\n// euler tour\
    \ of node \nstruct EulerTour {\n  struct UnionFind {\n    vector<int> data;\n\
    \    UnionFind(int N) : data(N, -1) {}\n\n    int find(int k) { return data[k]\
    \ < 0 ? k : data[k] = find(data[k]); }\n\n    int unite(int x, int y) {\n    \
    \  if ((x = find(x)) == (y = find(y))) return false;\n      if (data[x] > data[y])\
    \ swap(x, y);\n      data[x] += data[y];\n      data[y] = x;\n      return true;\n\
    \    }\n\n    int size(int k) { return -data[find(k)]; }\n\n    int same(int x,\
    \ int y) { return find(x) == find(y); }\n  };\n\n  struct SegmentTree_RangeMin\
    \ {\n    int size;\n    using P = pair<int, int>;\n    vector<P> seg;\n    P UNIT\
    \ = P(1 << 30, -1);\n\n    SegmentTree_RangeMin() {}\n\n    SegmentTree_RangeMin(int\
    \ N) {\n      size = 1;\n      while (size < N) size <<= 1;\n      seg.assign(2\
    \ * size, UNIT);\n    }\n\n    void set(int k, P x) { seg[k + size] = x; }\n\n\
    \    void build() {\n      for (int k = size - 1; k > 0; k--) {\n        seg[k]\
    \ = min(seg[2 * k], seg[2 * k + 1]);\n      }\n    }\n\n    // query to [a, b)\n\
    \    P query(int a, int b) {\n      P L = UNIT, R = UNIT;\n      for (a += size,\
    \ b += size; a < b; a >>= 1, b >>= 1) {\n        if (a & 1) L = min(L, seg[a++]);\n\
    \        if (b & 1) R = min(seg[--b], R);\n      }\n      return min(L, R);\n\
    \    }\n  };\n\n  using G = vector<vector<int>>;\n\n  UnionFind uf;\n  vector<int>\
    \ down, up, tour, par, depth;\n  int i_;\n  SegmentTree_RangeMin lca_seg;\n\n\
    \  EulerTour(G &g)\n      : uf(g.size()),\n        down(g.size(), -1),\n     \
    \   up(g.size()),\n        tour(g.size() * 2),\n        par(g.size()),\n     \
    \   depth(g.size(), -1),\n        i_(0),\n        lca_seg(2 * g.size()) {\n  \
    \  vector<int> isroot(g.size(), 1);\n    for (int i = 0; i < (int)g.size(); i++)\
    \ {\n      for (auto &d : g[i]) isroot[d] = 0;\n    }\n    for (int i = 0; i <\
    \ (int)g.size(); i++) {\n      if (!isroot[i]) continue;\n      dfs(g, i, -1);\n\
    \    }\n    lca_seg.build();\n  }\n\n  void dfs(G &g, int c, int p) {\n    down[c]\
    \ = i_;\n    par[c] = p;\n    depth[c] = ~p ? depth[p] + 1 : 0;\n    lca_seg.set(i_,\
    \ {depth[c], c});\n    tour[i_++] = c;\n    if (~p) uf.unite(c, p);\n    for (auto\
    \ &d : g[c]) {\n      if (d == p) continue;\n      dfs(g, d, c);\n    }\n    up[c]\
    \ = i_;\n    if (~p) lca_seg.set(i_, {depth[p], p});\n    tour[i_++] = c;\n  }\n\
    \n  int lca(int a, int b) {\n    if (!uf.same(a, b)) return -1;\n    if (down[a]\
    \ > down[b]) swap(a, b);\n    return lca_seg.query(down[a], down[b] + 1).second;\n\
    \  }\n\n  template <typename F>\n  void node_query(int a, int b, F &f) {\n   \
    \ int l = lca(a, b);\n    assert(l != -1);\n    f(down[l], down[a] + 1);\n   \
    \ f(down[l] + 1, down[b] + 1);\n  }\n\n  template <typename F>\n  void edge_query(int\
    \ a, int b, F &f) {\n    int l = lca(a, b);\n    assert(l != -1);\n    f(down[l]\
    \ + 1, down[a] + 1);\n    f(down[l] + 1, down[b] + 1);\n  }\n};"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/euler-tour.hpp
  requiredBy: []
  timestamp: '2020-11-24 16:37:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/euler-tour.hpp
layout: document
redirect_from:
- /library/tree/euler-tour.hpp
- /library/tree/euler-tour.hpp.html
title: tree/euler-tour.hpp
---

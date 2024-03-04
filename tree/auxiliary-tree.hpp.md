---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: tree/heavy-light-decomposition.hpp
    title: "Heavy Light Decomposition(\u91CD\u8EFD\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2588.test.cpp
    title: verify/verify-yuki/yuki-2588.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Auxiliary Tree
    links: []
  bundledCode: "#line 2 \"tree/auxiliary-tree.hpp\"\n\n#include <algorithm>\n#include\
    \ <utility>\n#include <vector>\nusing namespace std;\n\n#line 2 \"tree/heavy-light-decomposition.hpp\"\
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
    \ d;\n}\n\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \n * @docs docs/graph/graph-template.md\n */\n#line 4 \"tree/heavy-light-decomposition.hpp\"\
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
    \ depth[b] ? a : b;\n  }\n\n  int dist(int a, int b) { return depth[a] + depth[b]\
    \ - depth[lca(a, b)] * 2; }\n};\n\n/**\n * @brief Heavy Light Decomposition(\u91CD\
    \u8EFD\u5206\u89E3)\n * @docs docs/tree/heavy-light-decomposition.md\n */\n#line\
    \ 9 \"tree/auxiliary-tree.hpp\"\n\ntemplate <typename G>\nstruct AuxiliaryTree\
    \ {\n  G g;\n  HeavyLightDecomposition<G> hld;\n  AuxiliaryTree(const G& _g, int\
    \ root = 0) : g(_g), hld(g, root) {}\n\n  // ps : \u9802\u70B9\u96C6\u5408\n \
    \ // \u8FD4\u308A\u5024 : (aux tree, aux tree \u306E\u9802\u70B9\u3068 g \u306E\
    \u9802\u70B9\u306E\u5BFE\u5FDC\u8868)\n  // aux tree \u306F \u89AA->\u5B50 \u306E\
    \u5411\u304D\u306E\u8FBA\u306E\u307F\u542B\u307E\u308C\u308B\n  // ps \u304C\u7A7A\
    \u306E\u5834\u5408\u306F\u7A7A\u306E\u30B0\u30E9\u30D5\u3092\u8FD4\u3059\n  pair<vector<vector<int>>,\
    \ vector<int>> get(vector<int> ps) {\n    if (ps.empty()) return {};\n    auto\
    \ comp = [&](int i, int j) { return hld.down[i] < hld.down[j]; };\n    sort(begin(ps),\
    \ end(ps), comp);\n    for (int i = 0, ie = ps.size(); i + 1 < ie; i++) {\n  \
    \    ps.push_back(hld.lca(ps[i], ps[i + 1]));\n    }\n    sort(begin(ps), end(ps),\
    \ comp);\n    ps.erase(unique(begin(ps), end(ps)), end(ps));\n\n    vector<vector<int>>\
    \ aux(ps.size());\n    vector<int> rs;\n    rs.push_back(0);\n    for (int i =\
    \ 1; i < (int)ps.size(); i++) {\n      int l = hld.lca(ps[rs.back()], ps[i]);\n\
    \      while (ps[rs.back()] != l) rs.pop_back();\n      aux[rs.back()].push_back(i);\n\
    \      rs.push_back(i);\n    }\n    return make_pair(aux, ps);\n  }\n};\n\n/**\n\
    \ * @brief Auxiliary Tree\n */\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\n#include \"heavy-light-decomposition.hpp\"\n\ntemplate\
    \ <typename G>\nstruct AuxiliaryTree {\n  G g;\n  HeavyLightDecomposition<G> hld;\n\
    \  AuxiliaryTree(const G& _g, int root = 0) : g(_g), hld(g, root) {}\n\n  // ps\
    \ : \u9802\u70B9\u96C6\u5408\n  // \u8FD4\u308A\u5024 : (aux tree, aux tree \u306E\
    \u9802\u70B9\u3068 g \u306E\u9802\u70B9\u306E\u5BFE\u5FDC\u8868)\n  // aux tree\
    \ \u306F \u89AA->\u5B50 \u306E\u5411\u304D\u306E\u8FBA\u306E\u307F\u542B\u307E\
    \u308C\u308B\n  // ps \u304C\u7A7A\u306E\u5834\u5408\u306F\u7A7A\u306E\u30B0\u30E9\
    \u30D5\u3092\u8FD4\u3059\n  pair<vector<vector<int>>, vector<int>> get(vector<int>\
    \ ps) {\n    if (ps.empty()) return {};\n    auto comp = [&](int i, int j) { return\
    \ hld.down[i] < hld.down[j]; };\n    sort(begin(ps), end(ps), comp);\n    for\
    \ (int i = 0, ie = ps.size(); i + 1 < ie; i++) {\n      ps.push_back(hld.lca(ps[i],\
    \ ps[i + 1]));\n    }\n    sort(begin(ps), end(ps), comp);\n    ps.erase(unique(begin(ps),\
    \ end(ps)), end(ps));\n\n    vector<vector<int>> aux(ps.size());\n    vector<int>\
    \ rs;\n    rs.push_back(0);\n    for (int i = 1; i < (int)ps.size(); i++) {\n\
    \      int l = hld.lca(ps[rs.back()], ps[i]);\n      while (ps[rs.back()] != l)\
    \ rs.pop_back();\n      aux[rs.back()].push_back(i);\n      rs.push_back(i);\n\
    \    }\n    return make_pair(aux, ps);\n  }\n};\n\n/**\n * @brief Auxiliary Tree\n\
    \ */\n"
  dependsOn:
  - tree/heavy-light-decomposition.hpp
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/auxiliary-tree.hpp
  requiredBy: []
  timestamp: '2024-03-04 16:48:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-2588.test.cpp
documentation_of: tree/auxiliary-tree.hpp
layout: document
redirect_from:
- /library/tree/auxiliary-tree.hpp
- /library/tree/auxiliary-tree.hpp.html
title: Auxiliary Tree
---

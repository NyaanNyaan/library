---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp
    title: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/heavy-light-decomposition.hpp\"\n#include <bits/stdc++.h>\n\
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
    \ d;\n}\n#line 6 \"tree/heavy-light-decomposition.hpp\"\n\ntemplate <typename\
    \ G>\nstruct HeavyLightDecomposition {\n  G& g;\n  int idx;\n  vector<int> size,\
    \ depth, in, out, nxt, par;\n  HeavyLightDecomposition(G& g, int root = 0)\n \
    \     : g(g),\n        idx(0),\n        size(g.size(), 0),\n        depth(g.size(),\
    \ 0),\n        in(g.size(), -1),\n        out(g.size(), -1),\n        nxt(g.size(),\
    \ root),\n        par(g.size(), root) {\n    dfs_sz(root);\n    dfs_hld(root);\n\
    \  }\n\n  void build(int root) {\n    dfs_sz(root);\n    dfs_hld(root);\n  }\n\
    \n  void dfs_sz(int cur) {\n    size[cur] = 1;\n    for (auto& dst : g[cur]) {\n\
    \      if (dst == par[cur]) {\n        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n\
    \          swap(g[cur][0], g[cur][1]);\n        else\n          continue;\n  \
    \    }\n      depth[dst] = depth[cur] + 1;\n      par[dst] = cur;\n      dfs_sz(dst);\n\
    \      size[cur] += size[dst];\n      if (size[dst] > size[g[cur][0]]) {\n   \
    \     swap(dst, g[cur][0]);\n      }\n    }\n  }\n\n  void dfs_hld(int cur) {\n\
    \    in[cur] = idx++;\n    for (auto dst : g[cur]) {\n      if (dst == par[cur])\
    \ continue;\n      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\
    \      dfs_hld(dst);\n    }\n    out[cur] = idx;\n  }\n\n  template <typename\
    \ F>\n  void edge_query(int u, int v, const F& f) {\n    while (1) {\n      if\
    \ (in[u] > in[v]) swap(u, v);\n      if (nxt[u] != nxt[v]) {\n        f(in[nxt[v]],\
    \ in[v] + 1);\n        v = par[nxt[v]];\n      } else {\n        if (u != v) f(in[u]\
    \ + 1, in[v] + 1);\n        break;\n      }\n    }\n  }\n\n  // TODO : verify\n\
    \  template <typename F>\n  void uncommutable_edge_query(int u, int v, const F&\
    \ f) {\n    while (1) {\n      if (nxt[u] != nxt[v]) {\n        if (in[u] > in[v])\
    \ {\n          f(in[u] + 1, in[nxt[u]], true);\n          u = par[nxt[u]];\n \
    \       } else {\n          f(in[nxt[v]], in[v] + 1, false);\n          v = par[nxt[v]];\n\
    \        }\n      } else {\n        if (in[u] != in[v]) {\n          if (in[u]\
    \ > in[v])\n            f(in[u] + 1, in[v] + 1, true);\n          else\n     \
    \       f(in[u] + 1, in[v] + 1, true);\n        }\n        break;\n      }\n \
    \   }\n  }\n\n  template <typename F>\n  void node_query(int u, int v, const F&\
    \ f) {\n    while (1) {\n      if (in[u] > in[v]) swap(u, v);\n      if (nxt[u]\
    \ != nxt[v]) {\n        f(in[nxt[v]], in[v] + 1);\n        v = par[nxt[v]];\n\
    \      } else {\n        f(in[u], in[v] + 1);\n        break;\n      }\n    }\n\
    \  }\n\n  template <typename F>\n  void uncommutable_node_query(int u, int v,\
    \ const F& f) {\n    while (1) {\n      if (nxt[u] != nxt[v]) {\n        if (in[u]\
    \ > in[v]) {\n          f(in[u] + 1, in[nxt[u]], true);\n          u = par[nxt[u]];\n\
    \        } else {\n          f(in[nxt[v]], in[v] + 1, false);\n          v = par[nxt[v]];\n\
    \        }\n      } else {\n        if (in[u] > in[v])\n          f(in[u] + 1,\
    \ in[v], true);\n        else\n          f(in[u], in[v] + 1, true);\n        break;\n\
    \      }\n    }\n  }\n\n  template <typename F>\n  void sub_edge_query(int u,\
    \ const F& f) {\n    f(in[u] + 1, out[u]);\n  }\n\n  template <typename F>\n \
    \ void sub_node_query(int u, const F& f) {\n    f(in[u], out[u]);\n  }\n\n  int\
    \ lca(int a, int b) {\n    while (nxt[a] != nxt[b]) {\n      if (in[a] < in[b])\
    \ swap(a, b);\n      a = par[nxt[a]];\n    }\n    return depth[a] < depth[b] ?\
    \ a : b;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../graph/graph-template.hpp\"\n\ntemplate <typename G>\nstruct HeavyLightDecomposition\
    \ {\n  G& g;\n  int idx;\n  vector<int> size, depth, in, out, nxt, par;\n  HeavyLightDecomposition(G&\
    \ g, int root = 0)\n      : g(g),\n        idx(0),\n        size(g.size(), 0),\n\
    \        depth(g.size(), 0),\n        in(g.size(), -1),\n        out(g.size(),\
    \ -1),\n        nxt(g.size(), root),\n        par(g.size(), root) {\n    dfs_sz(root);\n\
    \    dfs_hld(root);\n  }\n\n  void build(int root) {\n    dfs_sz(root);\n    dfs_hld(root);\n\
    \  }\n\n  void dfs_sz(int cur) {\n    size[cur] = 1;\n    for (auto& dst : g[cur])\
    \ {\n      if (dst == par[cur]) {\n        if (g[cur].size() >= 2 && int(dst)\
    \ == int(g[cur][0]))\n          swap(g[cur][0], g[cur][1]);\n        else\n  \
    \        continue;\n      }\n      depth[dst] = depth[cur] + 1;\n      par[dst]\
    \ = cur;\n      dfs_sz(dst);\n      size[cur] += size[dst];\n      if (size[dst]\
    \ > size[g[cur][0]]) {\n        swap(dst, g[cur][0]);\n      }\n    }\n  }\n\n\
    \  void dfs_hld(int cur) {\n    in[cur] = idx++;\n    for (auto dst : g[cur])\
    \ {\n      if (dst == par[cur]) continue;\n      nxt[dst] = (int(dst) == int(g[cur][0])\
    \ ? nxt[cur] : int(dst));\n      dfs_hld(dst);\n    }\n    out[cur] = idx;\n \
    \ }\n\n  template <typename F>\n  void edge_query(int u, int v, const F& f) {\n\
    \    while (1) {\n      if (in[u] > in[v]) swap(u, v);\n      if (nxt[u] != nxt[v])\
    \ {\n        f(in[nxt[v]], in[v] + 1);\n        v = par[nxt[v]];\n      } else\
    \ {\n        if (u != v) f(in[u] + 1, in[v] + 1);\n        break;\n      }\n \
    \   }\n  }\n\n  // TODO : verify\n  template <typename F>\n  void uncommutable_edge_query(int\
    \ u, int v, const F& f) {\n    while (1) {\n      if (nxt[u] != nxt[v]) {\n  \
    \      if (in[u] > in[v]) {\n          f(in[u] + 1, in[nxt[u]], true);\n     \
    \     u = par[nxt[u]];\n        } else {\n          f(in[nxt[v]], in[v] + 1, false);\n\
    \          v = par[nxt[v]];\n        }\n      } else {\n        if (in[u] != in[v])\
    \ {\n          if (in[u] > in[v])\n            f(in[u] + 1, in[v] + 1, true);\n\
    \          else\n            f(in[u] + 1, in[v] + 1, true);\n        }\n     \
    \   break;\n      }\n    }\n  }\n\n  template <typename F>\n  void node_query(int\
    \ u, int v, const F& f) {\n    while (1) {\n      if (in[u] > in[v]) swap(u, v);\n\
    \      if (nxt[u] != nxt[v]) {\n        f(in[nxt[v]], in[v] + 1);\n        v =\
    \ par[nxt[v]];\n      } else {\n        f(in[u], in[v] + 1);\n        break;\n\
    \      }\n    }\n  }\n\n  template <typename F>\n  void uncommutable_node_query(int\
    \ u, int v, const F& f) {\n    while (1) {\n      if (nxt[u] != nxt[v]) {\n  \
    \      if (in[u] > in[v]) {\n          f(in[u] + 1, in[nxt[u]], true);\n     \
    \     u = par[nxt[u]];\n        } else {\n          f(in[nxt[v]], in[v] + 1, false);\n\
    \          v = par[nxt[v]];\n        }\n      } else {\n        if (in[u] > in[v])\n\
    \          f(in[u] + 1, in[v], true);\n        else\n          f(in[u], in[v]\
    \ + 1, true);\n        break;\n      }\n    }\n  }\n\n  template <typename F>\n\
    \  void sub_edge_query(int u, const F& f) {\n    f(in[u] + 1, out[u]);\n  }\n\n\
    \  template <typename F>\n  void sub_node_query(int u, const F& f) {\n    f(in[u],\
    \ out[u]);\n  }\n\n  int lca(int a, int b) {\n    while (nxt[a] != nxt[b]) {\n\
    \      if (in[a] < in[b]) swap(a, b);\n      a = par[nxt[a]];\n    }\n    return\
    \ depth[a] < depth[b] ? a : b;\n  }\n};"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/heavy-light-decomposition.hpp
  requiredBy: []
  timestamp: '2020-08-05 02:19:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-5-d.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-e.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-c.test.cpp
  - verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp
documentation_of: tree/heavy-light-decomposition.hpp
layout: document
redirect_from:
- /library/tree/heavy-light-decomposition.hpp
- /library/tree/heavy-light-decomposition.hpp.html
title: tree/heavy-light-decomposition.hpp
---

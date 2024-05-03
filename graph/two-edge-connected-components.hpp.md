---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: graph/lowlink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-two-edge-cc.test.cpp
    title: verify/verify-yosupo-graph/yosupo-two-edge-cc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/two-edge-connected-components.hpp\"\n\n#line 2 \"\
    graph/graph-template.hpp\"\n\ntemplate <typename T>\nstruct edge {\n  int src,\
    \ to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n\
    \  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}\n\n \
    \ edge &operator=(const int &x) {\n    to = x;\n    return *this;\n  }\n\n  operator\
    \ int() const { return to; }\n};\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\n\
    template <typename T>\nusing WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph\
    \ = vector<vector<int>>;\n\n// Input of (Unweighted) Graph\nUnweightedGraph graph(int\
    \ N, int M = -1, bool is_directed = false,\n                      bool is_1origin\
    \ = true) {\n  UnweightedGraph g(N);\n  if (M == -1) M = N - 1;\n  for (int _\
    \ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    if (is_1origin) x--,\
    \ y--;\n    g[x].push_back(y);\n    if (!is_directed) g[y].push_back(x);\n  }\n\
    \  return g;\n}\n\n// Input of Weighted Graph\ntemplate <typename T>\nWeightedGraph<T>\
    \ wgraph(int N, int M = -1, bool is_directed = false,\n                      \
    \  bool is_1origin = true) {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N -\
    \ 1;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n   \
    \ T c;\n    cin >> c;\n    if (is_1origin) x--, y--;\n    g[x].emplace_back(x,\
    \ y, c);\n    if (!is_directed) g[y].emplace_back(y, x, c);\n  }\n  return g;\n\
    }\n\n// Input of Edges\ntemplate <typename T>\nEdges<T> esgraph([[maybe_unused]]\
    \ int N, int M, int is_weighted = true,\n                 bool is_1origin = true)\
    \ {\n  Edges<T> es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >>\
    \ x >> y;\n    T c;\n    if (is_weighted)\n      cin >> c;\n    else\n      c\
    \ = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n  }\n  return\
    \ es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename T>\nvector<vector<T>>\
    \ adjgraph(int N, int M, T INF, int is_weighted = true,\n                    \
    \       bool is_directed = false, bool is_1origin = true) {\n  vector<vector<T>>\
    \ d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n \
    \   cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin >> c;\n    else\n\
    \      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y] = c;\n    if (!is_directed)\
    \ d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief \u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n */\n#line\
    \ 2 \"graph/lowlink.hpp\"\n\n#include <vector>\nusing namespace std;\n\n#line\
    \ 7 \"graph/lowlink.hpp\"\n\n// bridge ... \u6A4B (\u8FBA (u, v) \u304C u < v\
    \ \u3068\u306A\u308B\u3088\u3046\u306B\u683C\u7D0D)\n// articulation point ...\
    \ \u95A2\u7BC0\u70B9\ntemplate <typename G>\nstruct LowLink {\n  const G &g;\n\
    \  int N;\n  vector<int> ord, low, articulation;\n  vector<pair<int, int> > bridge;\n\
    \n  LowLink(const G &_g) : g(_g), N(g.size()), ord(N, -1), low(N, -1) {\n    for\
    \ (int i = 0, k = 0; i < N; i++) {\n      if (ord[i] == -1) {\n        k = dfs(i,\
    \ k, -1);\n      }\n    }\n  }\n\n  int dfs(int idx, int k, int par) {\n    low[idx]\
    \ = (ord[idx] = k++);\n    int cnt = 0;\n    bool arti = false, second = false;\n\
    \    for (auto &to : g[idx]) {\n      if (ord[to] == -1) {\n        cnt++;\n \
    \       k = dfs(to, k, idx);\n        low[idx] = min(low[idx], low[to]);\n   \
    \     arti |= (par != -1) && (low[to] >= ord[idx]);\n        if (ord[idx] < low[to])\
    \ {\n          bridge.emplace_back(minmax(idx, (int)to));\n        }\n      }\
    \ else if (to != par || second) {\n        low[idx] = min(low[idx], ord[to]);\n\
    \      } else {\n        second = true;\n      }\n    }\n    arti |= par == -1\
    \ && cnt > 1;\n    if (arti) articulation.push_back(idx);\n    return k;\n  }\n\
    };\n#line 5 \"graph/two-edge-connected-components.hpp\"\n\ntemplate <typename\
    \ G>\nstruct TwoEdgeConnectedComponents {\n  const G &g;\n  LowLink<G> low;\n\
    \  vector<int> comp;\n  int k;\n  vector<vector<int>> groups, tree;\n  TwoEdgeConnectedComponents(const\
    \ G &g_)\n      : g(g_), low(g_), comp(g_.size(), -1), k(0) {\n    for (int i\
    \ = 0; i < (int)g.size(); i++) {\n      if (comp[i] == -1) dfs(i, -1);\n    }\n\
    \    groups.resize(k);\n    tree.resize(k);\n    for (int i = 0; i < (int)g.size();\
    \ i++) {\n      groups[comp[i]].push_back(i);\n    }\n    for (auto &e : low.bridge)\
    \ {\n      int u = comp[e.first], v = comp[e.second];\n      tree[u].push_back(v);\n\
    \    }\n  };\n\n  int operator[](const int &k) const { return comp[k]; }\n\n \
    \ void dfs(int i, int p) {\n    if (p >= 0 && low.ord[p] >= low.low[i])\n    \
    \  comp[i] = comp[p];\n    else\n      comp[i] = k++;\n    for (auto &d : g[i])\
    \ {\n      if (comp[d] == -1) dfs(d, i);\n    }\n  }\n};\n"
  code: "#pragma once\n\n#include \"./graph-template.hpp\"\n#include \"./lowlink.hpp\"\
    \n\ntemplate <typename G>\nstruct TwoEdgeConnectedComponents {\n  const G &g;\n\
    \  LowLink<G> low;\n  vector<int> comp;\n  int k;\n  vector<vector<int>> groups,\
    \ tree;\n  TwoEdgeConnectedComponents(const G &g_)\n      : g(g_), low(g_), comp(g_.size(),\
    \ -1), k(0) {\n    for (int i = 0; i < (int)g.size(); i++) {\n      if (comp[i]\
    \ == -1) dfs(i, -1);\n    }\n    groups.resize(k);\n    tree.resize(k);\n    for\
    \ (int i = 0; i < (int)g.size(); i++) {\n      groups[comp[i]].push_back(i);\n\
    \    }\n    for (auto &e : low.bridge) {\n      int u = comp[e.first], v = comp[e.second];\n\
    \      tree[u].push_back(v);\n    }\n  };\n\n  int operator[](const int &k) const\
    \ { return comp[k]; }\n\n  void dfs(int i, int p) {\n    if (p >= 0 && low.ord[p]\
    \ >= low.low[i])\n      comp[i] = comp[p];\n    else\n      comp[i] = k++;\n \
    \   for (auto &d : g[i]) {\n      if (comp[d] == -1) dfs(d, i);\n    }\n  }\n\
    };\n"
  dependsOn:
  - graph/graph-template.hpp
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/two-edge-connected-components.hpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-two-edge-cc.test.cpp
documentation_of: graph/two-edge-connected-components.hpp
layout: document
redirect_from:
- /library/graph/two-edge-connected-components.hpp
- /library/graph/two-edge-connected-components.hpp.html
title: graph/two-edge-connected-components.hpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/tree-path.test.cpp
    title: verify/verify-unit-test/tree-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-tree-util.test.cpp
    title: verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-tree-util.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6728\u306B\u5BFE\u3059\u308B\u4E00\u822C\u7684\u306A\u30AF\u30A8\
      \u30EA"
    links: []
  bundledCode: "#line 2 \"tree/tree-path.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
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
    \ d;\n}\n#line 6 \"tree/tree-path.hpp\"\n\ntemplate <typename G>\nstruct Tree\
    \ {\n private:\n  G& g;\n  int root;\n  vector<vector<int>> bl;\n  vector<int>\
    \ dp;\n  void build() {\n    bl.resize(g.size());\n    dp.resize(g.size());\n\
    \    dfs(root, -1, 0);\n  }\n\n  void dfs(int c, int p, int _dp) {\n    dp[c]\
    \ = _dp;\n    for (int i = p, x = -1; i != -1;) {\n      bl[c].push_back(i);\n\
    \      i = ++x < (int)bl[i].size() ? bl[i][x] : -1;\n    }\n    for (auto& d :\
    \ g[c]) {\n      if (d == p) continue;\n      dfs(d, c, _dp + 1);\n    }\n  }\n\
    \n public:\n  Tree(G& _g, int _r = 0) : g(_g), root(_r) { build(); }\n\n  int\
    \ depth(int u) const { return dp[u]; }\n\n  int par(int u) const { return u ==\
    \ root ? -1 : bl[u][0]; }\n\n  int kth_ancestor(int u, int k) const {\n    if\
    \ (dp[u] < k) return -1;\n    for (int i = k ? __lg(k) : -1; i >= 0; --i) {\n\
    \      if ((k >> i) & 1) u = bl[u][i];\n    }\n    return u;\n  }\n\n  int nxt(int\
    \ s, int t) const {\n    if (dp[s] >= dp[t]) return par(s);\n    int u = kth_ancestor(t,\
    \ dp[t] - dp[s] - 1);\n    return bl[u][0] == s ? u : bl[s][0];\n  }\n\n  vector<int>\
    \ path(int s, int t) const {\n    vector<int> pre, suf;\n    while (dp[s] > dp[t])\
    \ {\n      pre.push_back(s);\n      s = bl[s][0];\n    }\n    while (dp[s] < dp[t])\
    \ {\n      suf.push_back(t);\n      t = bl[t][0];\n    }\n    while (s != t) {\n\
    \      pre.push_back(s);\n      suf.push_back(t);\n      s = bl[s][0];\n     \
    \ t = bl[t][0];\n    }\n    pre.push_back(s);\n    reverse(begin(suf), end(suf));\n\
    \    copy(begin(suf), end(suf), back_inserter(pre));\n    return pre;\n  }\n\n\
    \  int lca(int u, int v) {\n    if (dp[u] != dp[v]) {\n      if (dp[u] > dp[v])\
    \ swap(u, v);\n      v = kth_ancestor(v, dp[v] - dp[u]);\n    }\n    if (u ==\
    \ v) return u;\n    for (int i = __lg(dp[u]); i >= 0; --i) {\n      if (dp[u]\
    \ < (1 << i)) continue;\n      if (bl[u][i] != bl[v][i]) u = bl[u][i], v = bl[v][i];\n\
    \    }\n    return bl[u][0];\n  }\n};\n\n/**\n * @brief \u6728\u306B\u5BFE\u3059\
    \u308B\u4E00\u822C\u7684\u306A\u30AF\u30A8\u30EA\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../graph/graph-template.hpp\"\n\ntemplate <typename G>\nstruct Tree {\n private:\n\
    \  G& g;\n  int root;\n  vector<vector<int>> bl;\n  vector<int> dp;\n  void build()\
    \ {\n    bl.resize(g.size());\n    dp.resize(g.size());\n    dfs(root, -1, 0);\n\
    \  }\n\n  void dfs(int c, int p, int _dp) {\n    dp[c] = _dp;\n    for (int i\
    \ = p, x = -1; i != -1;) {\n      bl[c].push_back(i);\n      i = ++x < (int)bl[i].size()\
    \ ? bl[i][x] : -1;\n    }\n    for (auto& d : g[c]) {\n      if (d == p) continue;\n\
    \      dfs(d, c, _dp + 1);\n    }\n  }\n\n public:\n  Tree(G& _g, int _r = 0)\
    \ : g(_g), root(_r) { build(); }\n\n  int depth(int u) const { return dp[u]; }\n\
    \n  int par(int u) const { return u == root ? -1 : bl[u][0]; }\n\n  int kth_ancestor(int\
    \ u, int k) const {\n    if (dp[u] < k) return -1;\n    for (int i = k ? __lg(k)\
    \ : -1; i >= 0; --i) {\n      if ((k >> i) & 1) u = bl[u][i];\n    }\n    return\
    \ u;\n  }\n\n  int nxt(int s, int t) const {\n    if (dp[s] >= dp[t]) return par(s);\n\
    \    int u = kth_ancestor(t, dp[t] - dp[s] - 1);\n    return bl[u][0] == s ? u\
    \ : bl[s][0];\n  }\n\n  vector<int> path(int s, int t) const {\n    vector<int>\
    \ pre, suf;\n    while (dp[s] > dp[t]) {\n      pre.push_back(s);\n      s = bl[s][0];\n\
    \    }\n    while (dp[s] < dp[t]) {\n      suf.push_back(t);\n      t = bl[t][0];\n\
    \    }\n    while (s != t) {\n      pre.push_back(s);\n      suf.push_back(t);\n\
    \      s = bl[s][0];\n      t = bl[t][0];\n    }\n    pre.push_back(s);\n    reverse(begin(suf),\
    \ end(suf));\n    copy(begin(suf), end(suf), back_inserter(pre));\n    return\
    \ pre;\n  }\n\n  int lca(int u, int v) {\n    if (dp[u] != dp[v]) {\n      if\
    \ (dp[u] > dp[v]) swap(u, v);\n      v = kth_ancestor(v, dp[v] - dp[u]);\n   \
    \ }\n    if (u == v) return u;\n    for (int i = __lg(dp[u]); i >= 0; --i) {\n\
    \      if (dp[u] < (1 << i)) continue;\n      if (bl[u][i] != bl[v][i]) u = bl[u][i],\
    \ v = bl[v][i];\n    }\n    return bl[u][0];\n  }\n};\n\n/**\n * @brief \u6728\
    \u306B\u5BFE\u3059\u308B\u4E00\u822C\u7684\u306A\u30AF\u30A8\u30EA\n */\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/tree-path.hpp
  requiredBy: []
  timestamp: '2020-11-26 16:49:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-lowest-common-ancestor-tree-util.test.cpp
  - verify/verify-unit-test/tree-path.test.cpp
documentation_of: tree/tree-path.hpp
layout: document
redirect_from:
- /library/tree/tree-path.hpp
- /library/tree/tree-path.hpp.html
title: "\u6728\u306B\u5BFE\u3059\u308B\u4E00\u822C\u7684\u306A\u30AF\u30A8\u30EA"
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-b.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-b.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/rerooting.hpp\"\n\n\n\n#line 2 \"graph/graph-template.hpp\"\
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
    \ c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n#line 6 \"tree/rerooting.hpp\"\
    \n\n// Rerooting\n// f1(c1, c2) ... merge value of child node\n// f2(memo[i],\
    \ chd, par) ... return value from child node to parent node\n// memo[i] ... result\
    \ of subtree rooted i\n// dp[i] ... result of tree rooted i\ntemplate <typename\
    \ T, typename G, typename F1, typename F2>\nstruct Rerooting {\n  const G &g;\n\
    \  const F1 f1;\n  const F2 f2;\n  vector<T> memo, dp;\n  T I;\n\n  Rerooting(const\
    \ G &g, const F1 f1, const F2 f2, const T &I)\n      : g(g), f1(f1), f2(f2), memo(g.size(),\
    \ I), dp(g.size(), I), I(I) {\n    dfs(0, -1);\n    efs(0, -1, I);\n  }\n\n  const\
    \ T &operator[](int i) const { return dp[i]; }\n\n  void dfs(int cur, int par)\
    \ {\n    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n      dfs(dst,\
    \ cur);\n      memo[cur] = f1(memo[cur], f2(memo[dst], dst, cur));\n    }\n  }\n\
    \n  void efs(int cur, int par, const T &pval) {\n    // get cumulative sum\n \
    \   vector<T> buf;\n    for (auto dst : g[cur]) {\n      if (dst == par) continue;\n\
    \      buf.push_back(f2(memo[dst], dst, cur));\n    }\n    vector<T> head(buf.size()\
    \ + 1), tail(buf.size() + 1);\n    head[0] = tail[buf.size()] = I;\n    for (int\
    \ i = 0; i < (int)buf.size(); i++) head[i + 1] = f1(head[i], buf[i]);\n    for\
    \ (int i = (int)buf.size() - 1; i >= 0; i--)\n      tail[i] = f1(tail[i + 1],\
    \ buf[i]);\n\n    // update\n    dp[cur] = par == -1 ? head.back() : f1(pval,\
    \ head.back());\n\n    // propagate\n    int idx = 0;\n    for (auto &dst : g[cur])\
    \ {\n      if (dst == par) continue;\n      efs(dst, cur, f2(f1(pval, f1(head[idx],\
    \ tail[idx + 1])), cur, dst));\n      idx++;\n    }\n  }\n};\n\n/*\n\nusing T\
    \ = ;\n// identify element of f1, and answer of leaf\nT I = ;\n// merge value\
    \ of child node\nauto f1 = [&](T x, T y) -> T {\n\n};\n// return value from child\
    \ node to parent node\nauto f2 = [&](T x, int chd, int par) -> T {\n\n};\nRerooting<T,\
    \ decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);\n\n*/\n"
  code: "#pragma once\n\n\n\n#include \"../graph/graph-template.hpp\"\n\n// Rerooting\n\
    // f1(c1, c2) ... merge value of child node\n// f2(memo[i], chd, par) ... return\
    \ value from child node to parent node\n// memo[i] ... result of subtree rooted\
    \ i\n// dp[i] ... result of tree rooted i\ntemplate <typename T, typename G, typename\
    \ F1, typename F2>\nstruct Rerooting {\n  const G &g;\n  const F1 f1;\n  const\
    \ F2 f2;\n  vector<T> memo, dp;\n  T I;\n\n  Rerooting(const G &g, const F1 f1,\
    \ const F2 f2, const T &I)\n      : g(g), f1(f1), f2(f2), memo(g.size(), I), dp(g.size(),\
    \ I), I(I) {\n    dfs(0, -1);\n    efs(0, -1, I);\n  }\n\n  const T &operator[](int\
    \ i) const { return dp[i]; }\n\n  void dfs(int cur, int par) {\n    for (auto\
    \ &dst : g[cur]) {\n      if (dst == par) continue;\n      dfs(dst, cur);\n  \
    \    memo[cur] = f1(memo[cur], f2(memo[dst], dst, cur));\n    }\n  }\n\n  void\
    \ efs(int cur, int par, const T &pval) {\n    // get cumulative sum\n    vector<T>\
    \ buf;\n    for (auto dst : g[cur]) {\n      if (dst == par) continue;\n     \
    \ buf.push_back(f2(memo[dst], dst, cur));\n    }\n    vector<T> head(buf.size()\
    \ + 1), tail(buf.size() + 1);\n    head[0] = tail[buf.size()] = I;\n    for (int\
    \ i = 0; i < (int)buf.size(); i++) head[i + 1] = f1(head[i], buf[i]);\n    for\
    \ (int i = (int)buf.size() - 1; i >= 0; i--)\n      tail[i] = f1(tail[i + 1],\
    \ buf[i]);\n\n    // update\n    dp[cur] = par == -1 ? head.back() : f1(pval,\
    \ head.back());\n\n    // propagate\n    int idx = 0;\n    for (auto &dst : g[cur])\
    \ {\n      if (dst == par) continue;\n      efs(dst, cur, f2(f1(pval, f1(head[idx],\
    \ tail[idx + 1])), cur, dst));\n      idx++;\n    }\n  }\n};\n\n/*\n\nusing T\
    \ = ;\n// identify element of f1, and answer of leaf\nT I = ;\n// merge value\
    \ of child node\nauto f1 = [&](T x, T y) -> T {\n\n};\n// return value from child\
    \ node to parent node\nauto f2 = [&](T x, int chd, int par) -> T {\n\n};\nRerooting<T,\
    \ decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);\n\n*/"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/rerooting.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-b.test.cpp
documentation_of: tree/rerooting.hpp
layout: document
redirect_from:
- /library/tree/rerooting.hpp
- /library/tree/rerooting.hpp.html
title: tree/rerooting.hpp
---

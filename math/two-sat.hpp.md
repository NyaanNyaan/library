---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':question:'
    path: graph/strongly-connected-components.hpp
    title: graph/strongly-connected-components.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-math/yosupo-two-sat.test.cpp
    title: verify/verify-yosupo-math/yosupo-two-sat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/two-sat.md
    document_title: 2-SAT
    links: []
  bundledCode: "#line 2 \"math/two-sat.hpp\"\n\n\n\n#line 2 \"graph/strongly-connected-components.hpp\"\
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
    \ d;\n}\n#line 4 \"graph/strongly-connected-components.hpp\"\n\n// Strongly Connected\
    \ Components\n// DAG of SC graph   ... scc.dag (including multiedges)\n// new\
    \ node of k     ... scc[k]\n// inv of scc[k] = i ... scc.belong(i)\ntemplate <typename\
    \ G>\nstruct StronglyConnectedComponents {\n private:\n  const G &g;\n  vector<vector<int>>\
    \ rg;\n  vector<int> comp, order;\n  vector<char> used;\n  vector<vector<int>>\
    \ blng;\n\n public:\n  vector<vector<int>> dag;\n  StronglyConnectedComponents(G\
    \ &g) : g(g), used(g.size(), 0) { build(); }\n\n  int operator[](int k) { return\
    \ comp[k]; }\n\n  vector<int> &belong(int i) { return blng[i]; }\n\n private:\n\
    \  void dfs(int idx) {\n    if (used[idx]) return;\n    used[idx] = true;\n  \
    \  for (auto to : g[idx]) dfs(int(to));\n    order.push_back(idx);\n  }\n\n  void\
    \ rdfs(int idx, int cnt) {\n    if (comp[idx] != -1) return;\n    comp[idx] =\
    \ cnt;\n    for (int to : rg[idx]) rdfs(to, cnt);\n  }\n\n  void build() {\n \
    \   for (int i = 0; i < (int)g.size(); i++) dfs(i);\n    reverse(begin(order),\
    \ end(order));\n    used.clear();\n    used.shrink_to_fit();\n\n    comp.resize(g.size(),\
    \ -1);\n\n    rg.resize(g.size());\n    for (int i = 0; i < (int)g.size(); i++)\
    \ {\n      for (auto e : g[i]) {\n        rg[(int)e].emplace_back(i);\n      }\n\
    \    }\n    int ptr = 0;\n    for (int i : order)\n      if (comp[i] == -1) rdfs(i,\
    \ ptr), ptr++;\n    rg.clear();\n    rg.shrink_to_fit();\n    order.clear();\n\
    \    order.shrink_to_fit();\n\n    dag.resize(ptr);\n    blng.resize(ptr);\n \
    \   for (int i = 0; i < (int)g.size(); i++) {\n      blng[comp[i]].push_back(i);\n\
    \      for (auto &to : g[i]) {\n        int x = comp[i], y = comp[to];\n     \
    \   if (x == y) continue;\n        dag[x].push_back(y);\n      }\n    }\n  }\n\
    };\n#line 6 \"math/two-sat.hpp\"\n\nstruct TwoSAT {\n  int N;\n  vector<vector<int>>\
    \ g;\n\n  TwoSAT(int n) : N(n), g(2 * n) {}\n\n  inline int id(int node, int cond)\
    \ { return node + (cond ? N : 0); }\n\n  void add_cond(int s, int fs, int t, int\
    \ ft) {\n    g[id(s, !(fs))].push_back(id(t, ft));\n    g[id(t, !(ft))].push_back(id(s,\
    \ fs));\n  };\n\n  vector<int> run() {\n    StronglyConnectedComponents<decltype(g)>\
    \ scc(g);\n    vector<int> ret(N);\n    for (int i = 0; i < N; i++) {\n      if\
    \ (scc[i] == scc[N + i])\n        return {};\n      else\n        ret[i] = scc[i]\
    \ < scc[N + i];\n    }\n    return ret;\n  }\n};\n\n/**\n * @brief 2-SAT\n * @docs\
    \ docs/math/two-sat.md\n */\n"
  code: "#pragma once\n\n\n\n#include \"../graph/strongly-connected-components.hpp\"\
    \n\nstruct TwoSAT {\n  int N;\n  vector<vector<int>> g;\n\n  TwoSAT(int n) : N(n),\
    \ g(2 * n) {}\n\n  inline int id(int node, int cond) { return node + (cond ? N\
    \ : 0); }\n\n  void add_cond(int s, int fs, int t, int ft) {\n    g[id(s, !(fs))].push_back(id(t,\
    \ ft));\n    g[id(t, !(ft))].push_back(id(s, fs));\n  };\n\n  vector<int> run()\
    \ {\n    StronglyConnectedComponents<decltype(g)> scc(g);\n    vector<int> ret(N);\n\
    \    for (int i = 0; i < N; i++) {\n      if (scc[i] == scc[N + i])\n        return\
    \ {};\n      else\n        ret[i] = scc[i] < scc[N + i];\n    }\n    return ret;\n\
    \  }\n};\n\n/**\n * @brief 2-SAT\n * @docs docs/math/two-sat.md\n */\n"
  dependsOn:
  - graph/strongly-connected-components.hpp
  - graph/graph-template.hpp
  isVerificationFile: false
  path: math/two-sat.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-two-sat.test.cpp
documentation_of: math/two-sat.hpp
layout: document
redirect_from:
- /library/math/two-sat.hpp
- /library/math/two-sat.hpp.html
title: 2-SAT
---
## 2-SAT

2-SATを$\mathrm{O}(N + M)$($N$は論理変数の個数、$M$は節の個数)で計算するライブラリ。

#### 概要

SAT(充足可能性問題,satisfiability problem)とは、論理変数$x_1,x_2,\ldots x_n$からなる論理式が与えられたときに、変数に真か偽かを割り当てることで式全体を真にできるかを判定する問題である。

SATは一般にはNP困難であることが知られているが、連言標準形に直したときに節内の変数の数が2以下であるものを2-SATと呼び、多項式時間で解くことが出来る。

#### 使い方

- `TwoSAT(n)`　: $n$頂点のSATを初期化する。
- `add_cond(s, fs, t, ft)` : $v(i,0)=x_i,v(i,1)=\lnot x_i$としたとき、$(v(x_s,s) \wedge v(x_t,t))$を条件に加える。
- `run()` : 2-SATを解く。条件を満たす組み合わせが存在するときは各変数の値が格納された配列を、存在しないときは空の配列を返す。

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-cartesian.test.cpp
    title: verify/verify-yosupo-graph/yosupo-cartesian.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/cartesian-tree.md
    document_title: Cartesian Tree
    links: []
  bundledCode: "#line 2 \"tree/cartesian-tree.hpp\"\n\n\n\n#line 2 \"graph/graph-template.hpp\"\
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
    \ c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 6 \"tree/cartesian-tree.hpp\"\n\n// return value : pair<graph, root>\n\
    template <typename T>\npair<vector<vector<int>>, int> CartesianTree(vector<T>\
    \ &a) {\n  int N = (int)a.size();\n  vector<vector<int>> g(N);\n  vector<int>\
    \ p(N, -1), st;\n  st.reserve(N);\n  for (int i = 0; i < N; i++) {\n    int prv\
    \ = -1;\n    while (!st.empty() && a[i] < a[st.back()]) {\n      prv = st.back();\n\
    \      st.pop_back();\n    }\n    if (prv != -1) p[prv] = i;\n    if (!st.empty())\
    \ p[i] = st.back();\n    st.push_back(i);\n  }\n  int root = -1;\n  for (int i\
    \ = 0; i < N; i++) {\n    if (p[i] != -1)\n      g[p[i]].push_back(i);\n    else\n\
    \      root = i;\n  }\n  return make_pair(g, root);\n}\n\n/**\n * @brief Cartesian\
    \ Tree\n * @docs docs/tree/cartesian-tree.md\n */\n"
  code: "#pragma once\n\n\n\n#include \"../graph/graph-template.hpp\"\n\n// return\
    \ value : pair<graph, root>\ntemplate <typename T>\npair<vector<vector<int>>,\
    \ int> CartesianTree(vector<T> &a) {\n  int N = (int)a.size();\n  vector<vector<int>>\
    \ g(N);\n  vector<int> p(N, -1), st;\n  st.reserve(N);\n  for (int i = 0; i <\
    \ N; i++) {\n    int prv = -1;\n    while (!st.empty() && a[i] < a[st.back()])\
    \ {\n      prv = st.back();\n      st.pop_back();\n    }\n    if (prv != -1) p[prv]\
    \ = i;\n    if (!st.empty()) p[i] = st.back();\n    st.push_back(i);\n  }\n  int\
    \ root = -1;\n  for (int i = 0; i < N; i++) {\n    if (p[i] != -1)\n      g[p[i]].push_back(i);\n\
    \    else\n      root = i;\n  }\n  return make_pair(g, root);\n}\n\n/**\n * @brief\
    \ Cartesian Tree\n * @docs docs/tree/cartesian-tree.md\n */"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/cartesian-tree.hpp
  requiredBy: []
  timestamp: '2021-11-23 10:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp
  - verify/verify-yosupo-graph/yosupo-cartesian.test.cpp
documentation_of: tree/cartesian-tree.hpp
layout: document
redirect_from:
- /library/tree/cartesian-tree.hpp
- /library/tree/cartesian-tree.hpp.html
title: Cartesian Tree
---
## Cartesian Tree

#### 概要

数列$(a_n)$が与えられたとき、区間$[0,n)$に対して次の操作を再帰的に繰り返すことで得られる二分木をCartesian Treeと呼ぶ。
- 区間$[l,r)$が与えられたとき、$i \in [l,r)$のうちa_iが最小の$i$(複数ある場合は$i$が最も小さい点)を$m$と置く。
- 頂点$m$を根、区間$[l,m)$から得られる二分木を左の子、区間$[m+1,r)$から得られる二分木を右の子とした木を返す。

Cartesian Treeの構築にかかる時間計算量は直感的には$\mathrm{O}(n \log n)$だが、実はstackを利用することで$\mathrm{O}(n)$での構築が可能である。

Cartesian Treeの長所として「頂点$(u,v)$のLCAが区間$[u,v]$の最小値に対応する」という点があり、前計算$\mathrm{O}(n)$-クエリ$\mathrm{O}(1)$のRMQなどに利用されている。

参考：[EXPREP(codechef)](https://www.codechef.com/JULY20A/problems/EXPREP)　SAを計算して手に入れたLCP配列から構築したCartesian TreeをHLDecしてRSQ+RAQを載せることで解くことが出来る。(想定解はSuffix AutomatonとDSU on TreeとRSQ+RAQらしいが…)

#### 使い方

- `CartesianTree(a)` : 配列$a$に対して`{`グラフ`,`根`}`を返す。

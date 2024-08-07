---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/biconnected-components.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: graph/lowlink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-3022.test.cpp
    title: verify/verify-aoj-other/aoj-3022.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1326.test.cpp
    title: verify/verify-yuki/yuki-1326.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Block Cut Tree
    links: []
  bundledCode: "#line 2 \"tree/block-cut-tree.hpp\"\n\n#line 2 \"graph/biconnected-components.hpp\"\
    \n\n#line 2 \"graph/lowlink.hpp\"\n\n#include <vector>\nusing namespace std;\n\
    \n#line 2 \"graph/graph-template.hpp\"\n\ntemplate <typename T>\nstruct edge {\n\
    \  int src, to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost)\
    \ {}\n  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}\n\
    \n  edge &operator=(const int &x) {\n    to = x;\n    return *this;\n  }\n\n \
    \ operator int() const { return to; }\n};\ntemplate <typename T>\nusing Edges\
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
    \ esgraph([[maybe_unused]] int N, int M, int is_weighted = true,\n           \
    \      bool is_1origin = true) {\n  Edges<T> es;\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x,\
    \ y, c);\n  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename\
    \ T>\nvector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n\
    \                           bool is_directed = false, bool is_1origin = true)\
    \ {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y]\
    \ = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 7 \"graph/lowlink.hpp\"\n\n// bridge ... \u6A4B (\u8FBA (u, v) \u304C\
    \ u < v \u3068\u306A\u308B\u3088\u3046\u306B\u683C\u7D0D)\n// articulation point\
    \ ... \u95A2\u7BC0\u70B9\ntemplate <typename G>\nstruct LowLink {\n  const G &g;\n\
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
    };\n#line 4 \"graph/biconnected-components.hpp\"\n\ntemplate <typename G>\nstruct\
    \ BiConnectedComponents : LowLink<G> {\n  using LL = LowLink<G>;\n\n  vector<int>\
    \ used;\n  vector<vector<pair<int, int> > > bc;\n  vector<pair<int, int> > tmp;\n\
    \n  BiConnectedComponents(const G &_g) : LL(_g) { build(); }\n\n  void build()\
    \ {\n    used.assign(this->g.size(), 0);\n    for (int i = 0; i < (int)used.size();\
    \ i++) {\n      if (!used[i]) dfs(i, -1);\n    }\n  }\n\n  void dfs(int idx, int\
    \ par) {\n    used[idx] = true;\n    for (auto &to : this->g[idx]) {\n      if\
    \ (to == par) continue;\n      if (!used[to] || this->ord[to] < this->ord[idx])\
    \ {\n        tmp.emplace_back(minmax<int>(idx, to));\n      }\n      if (!used[to])\
    \ {\n        dfs(to, idx);\n        if (this->low[to] >= this->ord[idx]) {\n \
    \         bc.emplace_back();\n          while(true) {\n            auto e = tmp.back();\n\
    \            bc.back().emplace_back(e);\n            tmp.pop_back();\n       \
    \     if (e.first == min<int>(idx, to) && e.second == max<int>(idx, to)) {\n \
    \             break;\n            }\n          }\n        }\n      }\n    }\n\
    \  }\n};\n\n/**\n * @brief \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u5206\u89E3\n\
    \ */\n#line 4 \"tree/block-cut-tree.hpp\"\n\n// aux : block cut tree\n// id(V)\
    \ : new id of node V\n// is_arti(V) : return if V is articulation\ntemplate <typename\
    \ G>\nstruct BlockCutTree {\n  const G& g;\n  BiConnectedComponents<G> bcc;\n\
    \  vector<vector<int>> aux;\n  vector<int> idar, idcc;\n\n  BlockCutTree(const\
    \ G& _g) : g(_g), bcc(g) { build(); }\n\n  void build() {\n    auto ar = bcc.articulation;\n\
    \    idar.resize(g.size(), -1);\n    idcc.resize(g.size(), -1);\n    for (int\
    \ i = 0; i < (int)ar.size(); i++) idar[ar[i]] = i;\n\n    aux.resize(ar.size()\
    \ + bcc.bc.size());\n    vector<int> last(g.size(), -1);\n    for (int i = 0;\
    \ i < (int)bcc.bc.size(); i++) {\n      vector<int> st;\n      for (auto& [u,\
    \ v] : bcc.bc[i]) st.push_back(u), st.push_back(v);\n      for (auto& u : st)\
    \ {\n        if (idar[u] == -1) idcc[u] = i + ar.size();\n        else if(last[u]\
    \ != i){\n          add(i + ar.size(), idar[u]);\n          last[u] = i;\n   \
    \     }\n      }\n    }\n  }\n\n  vector<int>& operator[](int i) { return aux[i];\
    \ }\n\n  int size() const { return aux.size(); }\n\n  int id(int i) { return idar[i]\
    \ == -1 ? idcc[i] : idar[i]; }\n\n  bool is_arti(int i) { return idar[i] != -1;\
    \ }\n\n  int arti() const { return bcc.articulation.size(); }\n\n private:\n \
    \ void add(int i, int j) {\n    if (i == -1 or j == -1) return;\n    aux[i].push_back(j);\n\
    \    aux[j].push_back(i);\n  };\n};\n\n/**\n * @brief Block Cut Tree\n */\n"
  code: "#pragma once\n\n#include \"../graph/biconnected-components.hpp\"\n\n// aux\
    \ : block cut tree\n// id(V) : new id of node V\n// is_arti(V) : return if V is\
    \ articulation\ntemplate <typename G>\nstruct BlockCutTree {\n  const G& g;\n\
    \  BiConnectedComponents<G> bcc;\n  vector<vector<int>> aux;\n  vector<int> idar,\
    \ idcc;\n\n  BlockCutTree(const G& _g) : g(_g), bcc(g) { build(); }\n\n  void\
    \ build() {\n    auto ar = bcc.articulation;\n    idar.resize(g.size(), -1);\n\
    \    idcc.resize(g.size(), -1);\n    for (int i = 0; i < (int)ar.size(); i++)\
    \ idar[ar[i]] = i;\n\n    aux.resize(ar.size() + bcc.bc.size());\n    vector<int>\
    \ last(g.size(), -1);\n    for (int i = 0; i < (int)bcc.bc.size(); i++) {\n  \
    \    vector<int> st;\n      for (auto& [u, v] : bcc.bc[i]) st.push_back(u), st.push_back(v);\n\
    \      for (auto& u : st) {\n        if (idar[u] == -1) idcc[u] = i + ar.size();\n\
    \        else if(last[u] != i){\n          add(i + ar.size(), idar[u]);\n    \
    \      last[u] = i;\n        }\n      }\n    }\n  }\n\n  vector<int>& operator[](int\
    \ i) { return aux[i]; }\n\n  int size() const { return aux.size(); }\n\n  int\
    \ id(int i) { return idar[i] == -1 ? idcc[i] : idar[i]; }\n\n  bool is_arti(int\
    \ i) { return idar[i] != -1; }\n\n  int arti() const { return bcc.articulation.size();\
    \ }\n\n private:\n  void add(int i, int j) {\n    if (i == -1 or j == -1) return;\n\
    \    aux[i].push_back(j);\n    aux[j].push_back(i);\n  };\n};\n\n/**\n * @brief\
    \ Block Cut Tree\n */\n"
  dependsOn:
  - graph/biconnected-components.hpp
  - graph/lowlink.hpp
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/block-cut-tree.hpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1326.test.cpp
  - verify/verify-aoj-other/aoj-3022.test.cpp
documentation_of: tree/block-cut-tree.hpp
layout: document
redirect_from:
- /library/tree/block-cut-tree.hpp
- /library/tree/block-cut-tree.hpp.html
title: Block Cut Tree
---

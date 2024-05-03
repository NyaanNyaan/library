---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-5-b.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-5-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/rerooting.test.cpp
    title: verify/verify-unit-test/rerooting.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-tree-path-composite-sum.test.cpp
    title: verify/verify-yosupo-graph/yosupo-tree-path-composite-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/rerooting.md
    document_title: "Rerooting(\u5168\u65B9\u4F4D\u6728DP)"
    links: []
  bundledCode: "#line 2 \"tree/rerooting.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
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
    \ <typename T>\nEdges<T> esgraph([[maybe_unused]] int N, int M, int is_weighted\
    \ = true,\n                 bool is_1origin = true) {\n  Edges<T> es;\n  for (int\
    \ _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n\
    \      cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x,\
    \ y, c);\n  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename\
    \ T>\nvector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n\
    \                           bool is_directed = false, bool is_1origin = true)\
    \ {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y]\
    \ = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 4 \"tree/rerooting.hpp\"\n\n// Rerooting\n// f1(c1, c2) ... merge\
    \ value of child node\n// f2(memo[i], chd, par) ... return value from child node\
    \ to parent node\n// memo[i] ... result of subtree rooted i\n// dp[i] ... result\
    \ of tree rooted i\ntemplate <typename T, typename G, typename F1, typename F2>\n\
    struct Rerooting {\n  const G &g;\n  const F1 f1;\n  const F2 f2;\n  vector<T>\
    \ memo, dp;\n  T leaf;\n\n  Rerooting(const G &_g, const F1 _f1, const F2 _f2,\
    \ const T &_leaf)\n      : g(_g), f1(_f1), f2(_f2), memo(g.size()), dp(g.size()),\
    \ leaf(_leaf) {\n    dfs(0, -1);\n    dfs2(0, -1, T{});\n  }\n\n  const T &operator[](int\
    \ i) const { return dp[i]; }\n\n  void dfs(int cur, int par) {\n    vector<T>\
    \ chds;\n    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n   \
    \   dfs(dst, cur);\n      chds.push_back(f2(memo[dst], dst, cur));\n    }\n  \
    \  if (chds.empty()) {\n      memo[cur] = leaf;\n    } else {\n      memo[cur]\
    \ = chds[0];\n      for (int i = 1; i < (int)chds.size(); i++) {\n        memo[cur]\
    \ = f1(memo[cur], chds[i]);\n      }\n    }\n  }\n\n  void dfs2(int cur, int par,\
    \ const T &pval) {\n    // get cumulative sum\n    vector<T> buf;\n    if (cur\
    \ != 0) buf.push_back(pval);\n    for (auto dst : g[cur]) {\n      if (dst ==\
    \ par) continue;\n      buf.push_back(f2(memo[dst], dst, cur));\n    }\n    vector<T>\
    \ head(buf.size()), tail(buf.size());\n    if (!buf.empty()) {\n      head[0]\
    \ = buf[0];\n      for (int i = 1; i < (int)buf.size(); i++) {\n        head[i]\
    \ = f1(head[i - 1], buf[i]);\n      }\n      tail.back() = buf.back();\n     \
    \ for (int i = (int)buf.size() - 2; i >= 0; i--) {\n        tail[i] = f1(tail[i\
    \ + 1], buf[i]);\n      }\n    }\n    dp[cur] = head.empty() ? leaf : head.back();\n\
    \    int idx = cur == 0 ? 0 : 1;\n    for (auto &dst : g[cur]) {\n      if (dst\
    \ == par) continue;\n      T val;\n      bool first = idx == 0;\n      bool last\
    \ = idx + 1 == (int)head.size();\n      if (first and last) {\n        val = leaf;\n\
    \      } else if (first) {\n        val = tail[idx + 1];\n      } else if (last)\
    \ {\n        val = head[idx - 1];\n      } else {\n        val = f1(head[idx -\
    \ 1], tail[idx + 1]);\n      }\n      dfs2(dst, cur, f2(val, cur, dst));\n   \
    \   idx++;\n    }\n  }\n};\n\n/**\n * @brief Rerooting(\u5168\u65B9\u4F4D\u6728\
    DP)\n * @docs docs/tree/rerooting.md\n */\n"
  code: "#pragma once\n\n#include \"../graph/graph-template.hpp\"\n\n// Rerooting\n\
    // f1(c1, c2) ... merge value of child node\n// f2(memo[i], chd, par) ... return\
    \ value from child node to parent node\n// memo[i] ... result of subtree rooted\
    \ i\n// dp[i] ... result of tree rooted i\ntemplate <typename T, typename G, typename\
    \ F1, typename F2>\nstruct Rerooting {\n  const G &g;\n  const F1 f1;\n  const\
    \ F2 f2;\n  vector<T> memo, dp;\n  T leaf;\n\n  Rerooting(const G &_g, const F1\
    \ _f1, const F2 _f2, const T &_leaf)\n      : g(_g), f1(_f1), f2(_f2), memo(g.size()),\
    \ dp(g.size()), leaf(_leaf) {\n    dfs(0, -1);\n    dfs2(0, -1, T{});\n  }\n\n\
    \  const T &operator[](int i) const { return dp[i]; }\n\n  void dfs(int cur, int\
    \ par) {\n    vector<T> chds;\n    for (auto &dst : g[cur]) {\n      if (dst ==\
    \ par) continue;\n      dfs(dst, cur);\n      chds.push_back(f2(memo[dst], dst,\
    \ cur));\n    }\n    if (chds.empty()) {\n      memo[cur] = leaf;\n    } else\
    \ {\n      memo[cur] = chds[0];\n      for (int i = 1; i < (int)chds.size(); i++)\
    \ {\n        memo[cur] = f1(memo[cur], chds[i]);\n      }\n    }\n  }\n\n  void\
    \ dfs2(int cur, int par, const T &pval) {\n    // get cumulative sum\n    vector<T>\
    \ buf;\n    if (cur != 0) buf.push_back(pval);\n    for (auto dst : g[cur]) {\n\
    \      if (dst == par) continue;\n      buf.push_back(f2(memo[dst], dst, cur));\n\
    \    }\n    vector<T> head(buf.size()), tail(buf.size());\n    if (!buf.empty())\
    \ {\n      head[0] = buf[0];\n      for (int i = 1; i < (int)buf.size(); i++)\
    \ {\n        head[i] = f1(head[i - 1], buf[i]);\n      }\n      tail.back() =\
    \ buf.back();\n      for (int i = (int)buf.size() - 2; i >= 0; i--) {\n      \
    \  tail[i] = f1(tail[i + 1], buf[i]);\n      }\n    }\n    dp[cur] = head.empty()\
    \ ? leaf : head.back();\n    int idx = cur == 0 ? 0 : 1;\n    for (auto &dst :\
    \ g[cur]) {\n      if (dst == par) continue;\n      T val;\n      bool first =\
    \ idx == 0;\n      bool last = idx + 1 == (int)head.size();\n      if (first and\
    \ last) {\n        val = leaf;\n      } else if (first) {\n        val = tail[idx\
    \ + 1];\n      } else if (last) {\n        val = head[idx - 1];\n      } else\
    \ {\n        val = f1(head[idx - 1], tail[idx + 1]);\n      }\n      dfs2(dst,\
    \ cur, f2(val, cur, dst));\n      idx++;\n    }\n  }\n};\n\n/**\n * @brief Rerooting(\u5168\
    \u65B9\u4F4D\u6728DP)\n * @docs docs/tree/rerooting.md\n */\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: tree/rerooting.hpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/rerooting.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-b.test.cpp
  - verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp
  - verify/verify-yosupo-graph/yosupo-tree-path-composite-sum.test.cpp
documentation_of: tree/rerooting.hpp
layout: document
redirect_from:
- /library/tree/rerooting.hpp
- /library/tree/rerooting.hpp.html
title: "Rerooting(\u5168\u65B9\u4F4D\u6728DP)"
---
## 全方位木DP

#### テンプレート

```
// 「T : 根が virtual である根付き木」に対応する情報を管理する
using T = ;
// 空の状態に対応する情報
T leaf = ;
// T 同士をマージ
auto f1 = [&](T x, T y) -> T {
  
};
// T の根に頂点 c および辺 c-p を追加する (p は virtual)
auto f2 = [&](T x, int c, int p) -> T {
  
};
Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, leaf);
```



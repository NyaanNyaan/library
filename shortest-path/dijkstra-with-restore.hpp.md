---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/radix-heap.hpp
    title: Radix Heap
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path-2.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path-2.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/shortest-path/dijkstra-with-restore.md
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5FA9\u5143\u4ED8\
      \u304D)"
    links: []
  bundledCode: "#line 2 \"shortest-path/dijkstra-with-restore.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"data-structure/radix-heap.hpp\"\nusing namespace\
    \ std;\n\ntemplate <typename Key, typename Val>\nstruct RadixHeap {\n  using uint\
    \ = typename make_unsigned<Key>::type;\n  static constexpr int bit = sizeof(Key)\
    \ * 8;\n  array<vector<pair<uint, Val> >, bit + 1> vs;\n  array<uint, bit + 1>\
    \ ms;\n\n  int s;\n  uint last;\n\n  RadixHeap() : s(0), last(0) { fill(begin(ms),\
    \ end(ms), uint(-1)); }\n\n  bool empty() const { return s == 0; }\n\n  int size()\
    \ const { return s; }\n\n  __attribute__((target(\"lzcnt\"))) inline uint64_t\
    \ getbit(uint a) const {\n    return 64 - _lzcnt_u64(a);\n  }\n\n  void push(const\
    \ uint &key, const Val &val) {\n    s++;\n    uint64_t b = getbit(key ^ last);\n\
    \    vs[b].emplace_back(key, val);\n    ms[b] = min(key, ms[b]);\n  }\n\n  pair<uint,\
    \ Val> pop() {\n    if (ms[0] == uint(-1)) {\n      int idx = 1;\n      while\
    \ (ms[idx] == uint(-1)) idx++;\n      last = ms[idx];\n      for (auto &p : vs[idx])\
    \ {\n        uint64_t b = getbit(p.first ^ last);\n        vs[b].emplace_back(p);\n\
    \        ms[b] = min(p.first, ms[b]);\n      }\n      vs[idx].clear();\n     \
    \ ms[idx] = uint(-1);\n    }\n    --s;\n    auto res = vs[0].back();\n    vs[0].pop_back();\n\
    \    if (vs[0].empty()) ms[0] = uint(-1);\n    return res;\n  }\n};\n\n/**\n *\
    \ @brief Radix Heap\n * @docs docs/data-structure/radix-heap.md\n */\n#line 3\
    \ \"graph/graph-template.hpp\"\nusing namespace std;\n\ntemplate <typename T>\n\
    struct edge {\n  int src, to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1),\
    \ to(_to), cost(_cost) {}\n  edge(int _src, int _to, T _cost) : src(_src), to(_to),\
    \ cost(_cost) {}\n\n  edge &operator=(const int &x) {\n    to = x;\n    return\
    \ *this;\n  }\n\n  operator int() const { return to; }\n};\ntemplate <typename\
    \ T>\nusing Edges = vector<edge<T>>;\ntemplate <typename T>\nusing WeightedGraph\
    \ = vector<Edges<T>>;\nusing UnweightedGraph = vector<vector<int>>;\n\n// Input\
    \ of (Unweighted) Graph\nUnweightedGraph graph(int N, int M = -1, bool is_directed\
    \ = false,\n                      bool is_1origin = true) {\n  UnweightedGraph\
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
    \ d;\n}\n#line 7 \"shortest-path/dijkstra-with-restore.hpp\"\n\n// unreachable\
    \ -> {-1, -1}\ntemplate <typename T>\nvector<pair<T, int>> dijkstra_restore(WeightedGraph<T>\
    \ &g, int start = 0) {\n  int N = (int)g.size();\n  using P = pair<T, int>;\n\
    \  vector<P> d(N, P{-1, -1});\n  RadixHeap<T, int> Q;\n  d[start].first = 0;\n\
    \  Q.push(0, start);\n  while (!Q.empty()) {\n    auto p = Q.pop();\n    int cur\
    \ = p.second;\n    T dc = d[cur].first;\n    if (dc < T(p.first)) continue;\n\
    \    for (auto dst : g[cur]) {\n      if (d[dst].first == T(-1) || dc + dst.cost\
    \ < d[dst].first) {\n        d[dst] = P{dc + dst.cost, cur};\n        Q.push(dc\
    \ + dst.cost, dst);\n      }\n    }\n  }\n  return d;\n}\n\n/*\n * @brief \u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5FA9\u5143\u4ED8\u304D)\n * @docs docs/shortest-path/dijkstra-with-restore.md\n\
    \ **/\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../data-structure/radix-heap.hpp\"\n#include \"../graph/graph-template.hpp\"\
    \n\n// unreachable -> {-1, -1}\ntemplate <typename T>\nvector<pair<T, int>> dijkstra_restore(WeightedGraph<T>\
    \ &g, int start = 0) {\n  int N = (int)g.size();\n  using P = pair<T, int>;\n\
    \  vector<P> d(N, P{-1, -1});\n  RadixHeap<T, int> Q;\n  d[start].first = 0;\n\
    \  Q.push(0, start);\n  while (!Q.empty()) {\n    auto p = Q.pop();\n    int cur\
    \ = p.second;\n    T dc = d[cur].first;\n    if (dc < T(p.first)) continue;\n\
    \    for (auto dst : g[cur]) {\n      if (d[dst].first == T(-1) || dc + dst.cost\
    \ < d[dst].first) {\n        d[dst] = P{dc + dst.cost, cur};\n        Q.push(dc\
    \ + dst.cost, dst);\n      }\n    }\n  }\n  return d;\n}\n\n/*\n * @brief \u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5FA9\u5143\u4ED8\u304D)\n * @docs docs/shortest-path/dijkstra-with-restore.md\n\
    \ **/\n"
  dependsOn:
  - data-structure/radix-heap.hpp
  - graph/graph-template.hpp
  isVerificationFile: false
  path: shortest-path/dijkstra-with-restore.hpp
  requiredBy: []
  timestamp: '2020-11-27 13:31:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-shortest-path-2.test.cpp
documentation_of: shortest-path/dijkstra-with-restore.hpp
layout: document
redirect_from:
- /library/shortest-path/dijkstra-with-restore.hpp
- /library/shortest-path/dijkstra-with-restore.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5FA9\u5143\u4ED8\u304D)"
---

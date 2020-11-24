---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/radix-heap.hpp
    title: Radix Heap
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/shortest-path/dijkstra-fast.md
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\
      \u9AD8\u901F\u5316)"
    links: []
  bundledCode: "#line 2 \"shortest-path/dijkstra-fast.hpp\"\n#include <bits/stdc++.h>\n\
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
    \ @brief Radix Heap\n * @docs docs/data-structure/radix-heap.md\n */\n#line 6\
    \ \"shortest-path/dijkstra-fast.hpp\"\n\ntemplate <typename T, int N, int M>\n\
    struct DijkstraGraph {\n  array<int, N> first;\n  array<int, M + 1> succ, V;\n\
    \  array<T, M + 1> C;\n  int ec;\n\n  constexpr DijkstraGraph() : ec(0) { fill(begin(first),\
    \ end(first), 0); }\n\n  void add_edge(int u, int v, T c) {\n    ++ec;\n    succ[ec]\
    \ = first[u];\n    first[u] = ec;\n    V[ec] = v;\n    C[ec] = c;\n  }\n\n  vector<T>\
    \ dijkstra(int start = 0) {\n    vector<T> d(N, T(-1));\n    RadixHeap<T, int>\
    \ Q;\n    d[start] = 0;\n    Q.push(0, start);\n    while (!Q.empty()) {\n   \
    \   auto p = Q.pop();\n      int u = p.second;\n      if (d[u] < T(p.first)) continue;\n\
    \      T du = d[u];\n      for (int id = first[u]; id; id = succ[id]) {\n    \
    \    int v = V[id];\n        T c = C[id];\n        if (d[v] == T(-1) or du + c\
    \ < d[v]) {\n          d[v] = du + c;\n          Q.push(d[v], v);\n        }\n\
    \      }\n    }\n    return d;\n  }\n};\n\n/*\n * @brief \u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\u5316)\n * @docs docs/shortest-path/dijkstra-fast.md\n\
    **/\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../data-structure/radix-heap.hpp\"\n\ntemplate <typename T, int N, int M>\n\
    struct DijkstraGraph {\n  array<int, N> first;\n  array<int, M + 1> succ, V;\n\
    \  array<T, M + 1> C;\n  int ec;\n\n  constexpr DijkstraGraph() : ec(0) { fill(begin(first),\
    \ end(first), 0); }\n\n  void add_edge(int u, int v, T c) {\n    ++ec;\n    succ[ec]\
    \ = first[u];\n    first[u] = ec;\n    V[ec] = v;\n    C[ec] = c;\n  }\n\n  vector<T>\
    \ dijkstra(int start = 0) {\n    vector<T> d(N, T(-1));\n    RadixHeap<T, int>\
    \ Q;\n    d[start] = 0;\n    Q.push(0, start);\n    while (!Q.empty()) {\n   \
    \   auto p = Q.pop();\n      int u = p.second;\n      if (d[u] < T(p.first)) continue;\n\
    \      T du = d[u];\n      for (int id = first[u]; id; id = succ[id]) {\n    \
    \    int v = V[id];\n        T c = C[id];\n        if (d[v] == T(-1) or du + c\
    \ < d[v]) {\n          d[v] = du + c;\n          Q.push(d[v], v);\n        }\n\
    \      }\n    }\n    return d;\n  }\n};\n\n/*\n * @brief \u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\u5316)\n * @docs docs/shortest-path/dijkstra-fast.md\n\
    **/\n"
  dependsOn:
  - data-structure/radix-heap.hpp
  isVerificationFile: false
  path: shortest-path/dijkstra-fast.hpp
  requiredBy: []
  timestamp: '2020-11-24 21:53:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
documentation_of: shortest-path/dijkstra-fast.hpp
layout: document
redirect_from:
- /library/shortest-path/dijkstra-fast.hpp
- /library/shortest-path/dijkstra-fast.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\u5316\
  )"
---
## 定数倍高速化ダイクストラ法

ダイクストラ法の定数倍高速化ライブラリ。

#### 概要

ダイクストラ法を空間・時間ともに定数倍高速化したライブラリ。具体的には、隣接リストを配列3本で表現することで空間計算量を2倍改善して、ヒープに[Radix Heap(基数ヒープ)](https://nyaannyaan.github.io/library/data-structure/radix-heap.hpp)を使用することで最小値の取得にかかる時間計算量も2倍改善している。

[ナイーブな実装](https://nyaannyaan.github.io/library/shortest-path/dijkstra.hpp)と雑なランダムケースで比較したところ、全体としておよそ3倍程度の高速化がなされるようだ。

#### 使い方

- `DijkstraGraph<T, N, M>` :辺の重みがTで、頂点数の最大が`N`、辺数の最大が`M`であるグラフを生成する。
- `add_edge(u, v, c)`: uからvへ向かう重みcの有向辺を追加する。
- `dijkstra(s)`: sを始点としたダイクストラ法を行い、計算結果を返す。


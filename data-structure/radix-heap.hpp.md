---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra-fast.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\
      \u5316)"
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra-radix-heap.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(Radix Heap)"
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra-with-restore.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5FA9\u5143\u4ED8\u304D)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-1-a-radix-heap.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-1-a-radix-heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/dijkstra.test.cpp
    title: verify/verify-unit-test/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/radix-heap.test.cpp
    title: verify/verify-unit-test/radix-heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path-2.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1320.test.cpp
    title: verify/verify-yuki/yuki-1320.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/radix-heap.md
    document_title: Radix Heap
    links: []
  bundledCode: "#line 2 \"data-structure/radix-heap.hpp\"\n\ntemplate <typename Key,\
    \ typename Val>\nstruct RadixHeap {\n  using uint = typename make_unsigned<Key>::type;\n\
    \  static constexpr int bit = sizeof(Key) * 8;\n  array<vector<pair<uint, Val>\
    \ >, bit + 1> vs;\n  array<uint, bit + 1> ms;\n\n  int s;\n  uint last;\n\n  RadixHeap()\
    \ : s(0), last(0) { fill(begin(ms), end(ms), uint(-1)); }\n\n  bool empty() const\
    \ { return s == 0; }\n\n  int size() const { return s; }\n\n  __attribute__((target(\"\
    lzcnt\"))) inline uint64_t getbit(uint a) const {\n    return 64 - _lzcnt_u64(a);\n\
    \  }\n\n  void push(const uint &key, const Val &val) {\n    s++;\n    uint64_t\
    \ b = getbit(key ^ last);\n    vs[b].emplace_back(key, val);\n    ms[b] = min(key,\
    \ ms[b]);\n  }\n\n  pair<uint, Val> pop() {\n    if (ms[0] == uint(-1)) {\n  \
    \    int idx = 1;\n      while (ms[idx] == uint(-1)) idx++;\n      last = ms[idx];\n\
    \      for (auto &p : vs[idx]) {\n        uint64_t b = getbit(p.first ^ last);\n\
    \        vs[b].emplace_back(p);\n        ms[b] = min(p.first, ms[b]);\n      }\n\
    \      vs[idx].clear();\n      ms[idx] = uint(-1);\n    }\n    --s;\n    auto\
    \ res = vs[0].back();\n    vs[0].pop_back();\n    if (vs[0].empty()) ms[0] = uint(-1);\n\
    \    return res;\n  }\n};\n\n/**\n * @brief Radix Heap\n * @docs docs/data-structure/radix-heap.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename Key, typename Val>\nstruct RadixHeap {\n\
    \  using uint = typename make_unsigned<Key>::type;\n  static constexpr int bit\
    \ = sizeof(Key) * 8;\n  array<vector<pair<uint, Val> >, bit + 1> vs;\n  array<uint,\
    \ bit + 1> ms;\n\n  int s;\n  uint last;\n\n  RadixHeap() : s(0), last(0) { fill(begin(ms),\
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
    \ @brief Radix Heap\n * @docs docs/data-structure/radix-heap.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/radix-heap.hpp
  requiredBy:
  - shortest-path/dijkstra-with-restore.hpp
  - shortest-path/dijkstra-fast.hpp
  - shortest-path/dijkstra-radix-heap.hpp
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
  - verify/verify-aoj-grl/aoj-grl-1-a-radix-heap.test.cpp
  - verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
  - verify/verify-yosupo-graph/yosupo-shortest-path-2.test.cpp
  - verify/verify-yuki/yuki-1320.test.cpp
  - verify/verify-unit-test/radix-heap.test.cpp
  - verify/verify-unit-test/dijkstra.test.cpp
documentation_of: data-structure/radix-heap.hpp
layout: document
redirect_from:
- /library/data-structure/radix-heap.hpp
- /library/data-structure/radix-heap.hpp.html
title: Radix Heap
---
## Radix Heap

#### 概要

Radix Heap(基数ヒープ)とは、単調順位ヒープ(追加した値が最後に取り出した値より大きい必要があるヒープ)の一種である。`std::priority_queue`と比べて定数倍が軽いことからDijkstra法に用いて定数倍高速化に使用される。

#### 使い方

- `RadixHeap<Key, Val>()`: コンストラクタ。`Key`は整数型のみを取る。
- `push(Key, Val)`: ヒープにpushする。
- `pop()`: ヒープの要素のうち最小のものをpopして返す。
- `size()`: ヒープ内の要素数を返す。
- `empty()`: ヒープが空かどうかを返す。

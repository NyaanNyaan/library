---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/radix-heap.hpp
    title: Radix Heap
  - icon: ':heavy_check_mark:'
    path: graph/static-graph.hpp
    title: Static Graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/dijkstra.test.cpp
    title: verify/verify-unit-test/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/shortest-path/dijkstra-fast.md
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\
      \u9AD8\u901F\u5316)"
    links: []
  bundledCode: "#line 2 \"shortest-path/dijkstra-fast.hpp\"\n\n\n\n#line 2 \"data-structure/radix-heap.hpp\"\
    \n\ntemplate <typename Key, typename Val>\nstruct RadixHeap {\n  using uint =\
    \ typename make_unsigned<Key>::type;\n  static constexpr int bit = sizeof(Key)\
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
    \ @brief Radix Heap\n * @docs docs/data-structure/radix-heap.md\n */\n#line 2\
    \ \"graph/static-graph.hpp\"\n\nnamespace StaticGraphImpl {\n\ntemplate <typename\
    \ T, bool Cond = is_void<T>::value>\nstruct E;\ntemplate <typename T>\nstruct\
    \ E<T, false> {\n  int to;\n  T cost;\n  E() {}\n  E(const int& v, const T& c)\
    \ : to(v), cost(c) {}\n  operator int() const { return to; }\n};\ntemplate <typename\
    \ T>\nstruct E<T, true> {\n  int to;\n  E() {}\n  E(const int& v) : to(v) {}\n\
    \  operator int() const { return to; }\n};\n\ntemplate <typename T = void>\nstruct\
    \ StaticGraph {\n private:\n  template <typename It>\n  struct Es {\n    It b,\
    \ e;\n    It begin() const { return b; }\n    It end() const { return e; }\n \
    \   int size() const { return int(e - b); }\n    auto&& operator[](int i) const\
    \ { return b[i]; }\n  };\n  \n  int N, M, ec;\n  vector<int> head;\n  vector<pair<int,\
    \ E<T>>> buf;\n  vector<E<T>> es;\n\n  void build() {\n    partial_sum(begin(head),\
    \ end(head), begin(head));\n    es.resize(M);\n    for (auto&& [u, e] : buf) es[--head[u]]\
    \ = e;\n  }\n\n public:\n  StaticGraph(int _n, int _m) : N(_n), M(_m), ec(0),\
    \ head(N + 1, 0) {\n    buf.reserve(M);\n  }\n\n  template <typename... Args>\n\
    \  void add_edge(int u, Args&&... args) {\n#pragma GCC diagnostic ignored \"-Wnarrowing\"\
    \n    buf.emplace_back(u, E<T>{std::forward<Args>(args)...});\n#pragma GCC diagnostic\
    \ warning \"-Wnarrowing\"\n    ++head[u];\n    if ((int)buf.size() == M) build();\n\
    \  }\n\n  Es<typename vector<E<T>>::iterator> operator[](int u) {\n    return\
    \ {begin(es) + head[u], begin(es) + head[u + 1]};\n  }\n  const Es<typename vector<E<T>>::const_iterator>\
    \ operator[](int u) const {\n    return {begin(es) + head[u], begin(es) + head[u\
    \ + 1]};\n  }\n  int size() const { return N; }\n};\n\n}  // namespace StaticGraphImpl\n\
    \nusing StaticGraphImpl::StaticGraph;\n\n/**\n * @brief Static Graph\n * @docs\
    \ docs/graph/static-graph.md\n */\n#line 7 \"shortest-path/dijkstra-fast.hpp\"\
    \n\ntemplate <typename T>\nvector<T> dijkstra(StaticGraph<T>& g, int start = 0)\
    \ {\n  vector<T> d(g.size(), T(-1));\n  RadixHeap<T, int> Q;\n  d[start] = 0;\n\
    \  Q.push(0, start);\n  while (!Q.empty()) {\n    auto p = Q.pop();\n    int u\
    \ = p.second;\n    if (d[u] < T(p.first)) continue;\n    T du = d[u];\n    for\
    \ (auto&& [v, c] : g[u]) {\n      if (d[v] == T(-1) || du + c < d[v]) {\n    \
    \    d[v] = du + c;\n        Q.push(d[v], v);\n      }\n    }\n  }\n  return d;\n\
    }\n\ntemplate <typename T>\nvector<pair<T, int>> dijkstra_restore(StaticGraph<T>&\
    \ g, int start = 0) {\n  vector<pair<T, int>> d(g.size(), {T(-1), -1});\n  RadixHeap<T,\
    \ int> Q;\n  d[start] = {0, -1};\n  Q.push(0, start);\n  while (!Q.empty()) {\n\
    \    auto p = Q.pop();\n    int u = p.second;\n    if (d[u].first < T(p.first))\
    \ continue;\n    T du = d[u].first;\n    for (auto&& [v, c] : g[u]) {\n      if\
    \ (d[v].first == T(-1) || du + c < d[v].first) {\n        d[v] = {du + c, u};\n\
    \        Q.push(du + c, v);\n      }\n    }\n  }\n  return d;\n}\n\n/*\n * @brief\
    \ \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\u5316\
    )\n * @docs docs/shortest-path/dijkstra-fast.md\n **/\n"
  code: "#pragma once\n\n\n\n#include \"../data-structure/radix-heap.hpp\"\n#include\
    \ \"../graph/static-graph.hpp\"\n\ntemplate <typename T>\nvector<T> dijkstra(StaticGraph<T>&\
    \ g, int start = 0) {\n  vector<T> d(g.size(), T(-1));\n  RadixHeap<T, int> Q;\n\
    \  d[start] = 0;\n  Q.push(0, start);\n  while (!Q.empty()) {\n    auto p = Q.pop();\n\
    \    int u = p.second;\n    if (d[u] < T(p.first)) continue;\n    T du = d[u];\n\
    \    for (auto&& [v, c] : g[u]) {\n      if (d[v] == T(-1) || du + c < d[v]) {\n\
    \        d[v] = du + c;\n        Q.push(d[v], v);\n      }\n    }\n  }\n  return\
    \ d;\n}\n\ntemplate <typename T>\nvector<pair<T, int>> dijkstra_restore(StaticGraph<T>&\
    \ g, int start = 0) {\n  vector<pair<T, int>> d(g.size(), {T(-1), -1});\n  RadixHeap<T,\
    \ int> Q;\n  d[start] = {0, -1};\n  Q.push(0, start);\n  while (!Q.empty()) {\n\
    \    auto p = Q.pop();\n    int u = p.second;\n    if (d[u].first < T(p.first))\
    \ continue;\n    T du = d[u].first;\n    for (auto&& [v, c] : g[u]) {\n      if\
    \ (d[v].first == T(-1) || du + c < d[v].first) {\n        d[v] = {du + c, u};\n\
    \        Q.push(du + c, v);\n      }\n    }\n  }\n  return d;\n}\n\n/*\n * @brief\
    \ \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\u5316\
    )\n * @docs docs/shortest-path/dijkstra-fast.md\n **/\n"
  dependsOn:
  - data-structure/radix-heap.hpp
  - graph/static-graph.hpp
  isVerificationFile: false
  path: shortest-path/dijkstra-fast.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
  - verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
  - verify/verify-unit-test/dijkstra.test.cpp
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

ダイクストラ法を空間・時間ともに定数倍高速化したライブラリ。

[ナイーブな実装](https://nyaannyaan.github.io/library/shortest-path/dijkstra.hpp)と雑なランダムケースで比較したところ、全体としておよそ2倍程度の高速化がなされるようだ。

#### 使い方

- `dijkstra(g, s)`: sを始点としたダイクストラ法を行い、計算結果を返す。
- `dijkstra_restore(g, s)`: sを始点としたダイクストラ法(復元付き)を行い、計算結果を返す。
  - いずれの場合もgは[`StaticGraph`](https://nyaannyaan.github.io/library/graph/static-graph.hpp)である必要がある。

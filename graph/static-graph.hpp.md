---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: shortest-path/dijkstra-fast.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u5B9A\u6570\u500D\u9AD8\u901F\
      \u5316)"
  - icon: ':heavy_check_mark:'
    path: shortest-path/dijkstra-skew-heap.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(Skew Heap)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
    title: verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2995.test.cpp
    title: verify/verify-aoj-other/aoj-2995.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/dijkstra.test.cpp
    title: verify/verify-unit-test/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-euler-tree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-euler-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path-4.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path-4.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1320.test.cpp
    title: verify/verify-yuki/yuki-1320.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/graph/static-graph.md
    document_title: Static Graph
    links: []
  bundledCode: "#line 2 \"graph/static-graph.hpp\"\n\nnamespace StaticGraphImpl {\n\
    \ntemplate <typename T, bool Cond = is_void<T>::value>\nstruct E;\ntemplate <typename\
    \ T>\nstruct E<T, false> {\n  int to;\n  T cost;\n  E() {}\n  E(const int& v,\
    \ const T& c) : to(v), cost(c) {}\n  operator int() const { return to; }\n};\n\
    template <typename T>\nstruct E<T, true> {\n  int to;\n  E() {}\n  E(const int&\
    \ v) : to(v) {}\n  operator int() const { return to; }\n};\n\ntemplate <typename\
    \ T = void>\nstruct StaticGraph {\n private:\n  template <typename It>\n  struct\
    \ Es {\n    It b, e;\n    It begin() const { return b; }\n    It end() const {\
    \ return e; }\n    int size() const { return int(e - b); }\n    auto&& operator[](int\
    \ i) const { return b[i]; }\n  };\n  \n  int N, M, ec;\n  vector<int> head;\n\
    \  vector<pair<int, E<T>>> buf;\n  vector<E<T>> es;\n\n  void build() {\n    partial_sum(begin(head),\
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
    \ docs/graph/static-graph.md\n */\n"
  code: "#pragma once\n\nnamespace StaticGraphImpl {\n\ntemplate <typename T, bool\
    \ Cond = is_void<T>::value>\nstruct E;\ntemplate <typename T>\nstruct E<T, false>\
    \ {\n  int to;\n  T cost;\n  E() {}\n  E(const int& v, const T& c) : to(v), cost(c)\
    \ {}\n  operator int() const { return to; }\n};\ntemplate <typename T>\nstruct\
    \ E<T, true> {\n  int to;\n  E() {}\n  E(const int& v) : to(v) {}\n  operator\
    \ int() const { return to; }\n};\n\ntemplate <typename T = void>\nstruct StaticGraph\
    \ {\n private:\n  template <typename It>\n  struct Es {\n    It b, e;\n    It\
    \ begin() const { return b; }\n    It end() const { return e; }\n    int size()\
    \ const { return int(e - b); }\n    auto&& operator[](int i) const { return b[i];\
    \ }\n  };\n  \n  int N, M, ec;\n  vector<int> head;\n  vector<pair<int, E<T>>>\
    \ buf;\n  vector<E<T>> es;\n\n  void build() {\n    partial_sum(begin(head), end(head),\
    \ begin(head));\n    es.resize(M);\n    for (auto&& [u, e] : buf) es[--head[u]]\
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
    \ docs/graph/static-graph.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: graph/static-graph.hpp
  requiredBy:
  - shortest-path/dijkstra-fast.hpp
  - shortest-path/dijkstra-skew-heap.hpp
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-1-a-fast-dijkstra.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-euler-tree.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
  - verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
  - verify/verify-aoj-other/aoj-2995.test.cpp
  - verify/verify-unit-test/dijkstra.test.cpp
  - verify/verify-yuki/yuki-1320.test.cpp
  - verify/verify-yosupo-graph/yosupo-shortest-path-3.test.cpp
  - verify/verify-yosupo-graph/yosupo-shortest-path-4.test.cpp
documentation_of: graph/static-graph.hpp
layout: document
redirect_from:
- /library/graph/static-graph.hpp
- /library/graph/static-graph.hpp.html
title: Static Graph
---
## Static Graph

静的なグラフライブラリ。通常のグラフライブラリと同様に隣接リストで辺を保存しているが、全ての辺を連続領域に保存することでアクセス時のキャッシュミスを減らし高速化している。

#### 使い方

- `StaticGraph<T>(N, M)`: N頂点M辺で重みの型が`T`(重み無しの場合は`void`)であるグラフを作成する。
- `add_edge(u, args...)`: uからvへ向かう重みcの辺を追加する。`args...`には`v, c`あるいは`v`が入る。

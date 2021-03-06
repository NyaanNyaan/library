---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/static-graph.hpp
    title: Static Graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-graph/yosupo-shortest-path-4.test.cpp
    title: verify/verify-yosupo-graph/yosupo-shortest-path-4.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/shortest-path/dijkstra-skew-heap.md
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(Skew Heap)"
    links: []
  bundledCode: "#line 2 \"shortest-path/dijkstra-skew-heap.hpp\"\n\n#line 2 \"graph/static-graph.hpp\"\
    \n\nnamespace StaticGraphImpl {\n\ntemplate <typename T, bool Cond = is_void<T>::value>\n\
    struct E;\ntemplate <typename T>\nstruct E<T, false> {\n  int to;\n  T cost;\n\
    \  E() {}\n  E(const int& v, const T& c) : to(v), cost(c) {}\n  operator int()\
    \ const { return to; }\n};\ntemplate <typename T>\nstruct E<T, true> {\n  int\
    \ to;\n  E() {}\n  E(const int& v) : to(v) {}\n  operator int() const { return\
    \ to; }\n};\n\ntemplate <typename T = void>\nstruct StaticGraph {\n private:\n\
    \  template <typename It>\n  struct Es {\n    It b, e;\n    It begin() const {\
    \ return b; }\n    It end() const { return e; }\n    int size() const { return\
    \ int(e - b); }\n    auto&& operator[](int i) const { return b[i]; }\n  };\n \
    \ \n  int N, M, ec;\n  vector<int> head;\n  vector<pair<int, E<T>>> buf;\n  vector<E<T>>\
    \ es;\n\n  void build() {\n    partial_sum(begin(head), end(head), begin(head));\n\
    \    es.resize(M);\n    for (auto&& [u, e] : buf) es[--head[u]] = e;\n  }\n\n\
    \ public:\n  StaticGraph(int _n, int _m) : N(_n), M(_m), ec(0), head(N + 1, 0)\
    \ {\n    buf.reserve(M);\n  }\n\n  template <typename... Args>\n  void add_edge(int\
    \ u, Args&&... args) {\n#pragma GCC diagnostic ignored \"-Wnarrowing\"\n    buf.emplace_back(u,\
    \ E<T>{std::forward<Args>(args)...});\n#pragma GCC diagnostic warning \"-Wnarrowing\"\
    \n    ++head[u];\n    if ((int)buf.size() == M) build();\n  }\n\n  Es<typename\
    \ vector<E<T>>::iterator> operator[](int u) {\n    return {begin(es) + head[u],\
    \ begin(es) + head[u + 1]};\n  }\n  const Es<typename vector<E<T>>::const_iterator>\
    \ operator[](int u) const {\n    return {begin(es) + head[u], begin(es) + head[u\
    \ + 1]};\n  }\n  int size() const { return N; }\n};\n\n}  // namespace StaticGraphImpl\n\
    \nusing StaticGraphImpl::StaticGraph;\n\n/**\n * @brief Static Graph\n * @docs\
    \ docs/graph/static-graph.md\n */\n#line 4 \"shortest-path/dijkstra-skew-heap.hpp\"\
    \n\ntemplate <typename T>\nstruct SkewHeap {\n  struct alignas(32) Node {\n  \
    \  T key;\n    int p, l, r;\n    Node(const T& k = T()) : key(k), p(-1), l(-1),\
    \ r(-1) {}\n  };\n\n  vector<Node> v;\n  int rt = -1;\n\n  SkewHeap(int n) : v(n)\
    \ {}\n\n  int meld(int x, int y) {\n    if (x == -1 || y == -1) return x == -1\
    \ ? y : x;\n    if (v[x].key > v[y].key) swap(x, y);\n    v[x].r = meld(v[x].r,\
    \ y);\n    v[v[x].r].p = x;\n    swap(v[x].l, v[x].r);\n    return x;\n  }\n\n\
    \  void pop() { rt = meld(v[rt].l, v[rt].r); }\n\n  void update(int x, const T&\
    \ k) {\n    Node& n = v[x];\n    v[x].key = k;\n    if (x == rt) return;\n   \
    \ Node& p = v[n.p];\n    if (p.key <= k) return;\n    (p.l == x ? p.l : p.r) =\
    \ -1;\n    n.p = -1;\n    rt = meld(rt, x);\n  }\n\n  bool empty() { return rt\
    \ == -1; }\n};\n\ntemplate <typename T>\nvector<pair<T, int>> dijkstra_restore(StaticGraph<T>&\
    \ g, int start = 0) {\n  int N = (int)g.size();\n  using P = pair<T, int>;\n \
    \ vector<P> d(N, P{-1, -1});\n  SkewHeap<T> Q(N);\n  d[start].first = 0;\n  Q.v[start].key\
    \ = 0;\n  Q.rt = start;\n  while (!Q.empty()) {\n    T dc = Q.v[Q.rt].key;\n \
    \   int cur = Q.rt;\n    Q.pop();\n    for (auto dst : g[cur]) {\n      if (d[dst].first\
    \ == T(-1)) {\n        d[dst] = P{dc + dst.cost, cur};\n        Q.v[dst].key =\
    \ dc + dst.cost;\n        Q.rt = Q.meld(Q.rt, dst);\n      } else if (dc + dst.cost\
    \ < d[dst].first) {\n        d[dst] = P{dc + dst.cost, cur};\n        Q.update(dst,\
    \ dc + dst.cost);\n      }\n    }\n  }\n  return d;\n}\n/*\n * @brief \u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u6CD5(Skew Heap)\n * @docs docs/shortest-path/dijkstra-skew-heap.md\n\
    **/\n"
  code: "#pragma once\n\n#include \"../graph/static-graph.hpp\"\n\ntemplate <typename\
    \ T>\nstruct SkewHeap {\n  struct alignas(32) Node {\n    T key;\n    int p, l,\
    \ r;\n    Node(const T& k = T()) : key(k), p(-1), l(-1), r(-1) {}\n  };\n\n  vector<Node>\
    \ v;\n  int rt = -1;\n\n  SkewHeap(int n) : v(n) {}\n\n  int meld(int x, int y)\
    \ {\n    if (x == -1 || y == -1) return x == -1 ? y : x;\n    if (v[x].key > v[y].key)\
    \ swap(x, y);\n    v[x].r = meld(v[x].r, y);\n    v[v[x].r].p = x;\n    swap(v[x].l,\
    \ v[x].r);\n    return x;\n  }\n\n  void pop() { rt = meld(v[rt].l, v[rt].r);\
    \ }\n\n  void update(int x, const T& k) {\n    Node& n = v[x];\n    v[x].key =\
    \ k;\n    if (x == rt) return;\n    Node& p = v[n.p];\n    if (p.key <= k) return;\n\
    \    (p.l == x ? p.l : p.r) = -1;\n    n.p = -1;\n    rt = meld(rt, x);\n  }\n\
    \n  bool empty() { return rt == -1; }\n};\n\ntemplate <typename T>\nvector<pair<T,\
    \ int>> dijkstra_restore(StaticGraph<T>& g, int start = 0) {\n  int N = (int)g.size();\n\
    \  using P = pair<T, int>;\n  vector<P> d(N, P{-1, -1});\n  SkewHeap<T> Q(N);\n\
    \  d[start].first = 0;\n  Q.v[start].key = 0;\n  Q.rt = start;\n  while (!Q.empty())\
    \ {\n    T dc = Q.v[Q.rt].key;\n    int cur = Q.rt;\n    Q.pop();\n    for (auto\
    \ dst : g[cur]) {\n      if (d[dst].first == T(-1)) {\n        d[dst] = P{dc +\
    \ dst.cost, cur};\n        Q.v[dst].key = dc + dst.cost;\n        Q.rt = Q.meld(Q.rt,\
    \ dst);\n      } else if (dc + dst.cost < d[dst].first) {\n        d[dst] = P{dc\
    \ + dst.cost, cur};\n        Q.update(dst, dc + dst.cost);\n      }\n    }\n \
    \ }\n  return d;\n}\n/*\n * @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\
    (Skew Heap)\n * @docs docs/shortest-path/dijkstra-skew-heap.md\n**/\n"
  dependsOn:
  - graph/static-graph.hpp
  isVerificationFile: false
  path: shortest-path/dijkstra-skew-heap.hpp
  requiredBy: []
  timestamp: '2021-02-11 00:13:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-shortest-path-4.test.cpp
documentation_of: shortest-path/dijkstra-skew-heap.hpp
layout: document
redirect_from:
- /library/shortest-path/dijkstra-skew-heap.hpp
- /library/shortest-path/dijkstra-skew-heap.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(Skew Heap)"
---
## ダイクストラ法(Skew Heap)

ダイクストラ法の定数倍高速化ライブラリ。

#### 概要

ダイクストラ法のヒープにSkew Heap(ねじれヒープ)を使用することで最小値の取得にかかる時間計算量を高速化したライブラリ。

#### 使い方

- `dijkstra(g, start = 0)`: sを始点としたダイクストラ法を行い、計算結果を返す。

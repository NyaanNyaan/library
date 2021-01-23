---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree.hpp
    title: segment-tree/segment-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure-2d/ds-2d.md
    document_title: "\u9818\u57DF\u6728(Segment Tree)"
    links: []
  bundledCode: "#line 2 \"data-structure-2d/segment-tree-on-range-tree.hpp\"\n\n\n\
    \n#line 2 \"segment-tree/segment-tree.hpp\"\n\n\n\ntemplate <typename T, typename\
    \ F>\nstruct SegmentTree {\n  int size;\n  vector<T> seg;\n  const F f;\n  const\
    \ T I;\n\n  SegmentTree(F _f, const T &I_) : size(0), f(_f), I(I_) {}\n\n  SegmentTree(int\
    \ N, F _f, const T &I_) : f(_f), I(I_) { init(N); }\n\n  SegmentTree(const vector<T>\
    \ &v, F _f, T I_) : f(_f), I(I_) {\n    init(v.size());\n    for (int i = 0; i\
    \ < (int)v.size(); i++) {\n      seg[i + size] = v[i];\n    }\n    build();\n\
    \  }\n\n  void init(int N) {\n    size = 1;\n    while (size < N) size <<= 1;\n\
    \    seg.assign(2 * size, I);\n  }\n\n  void set(int k, T x) { seg[k + size] =\
    \ x; }\n\n  void build() {\n    for (int k = size - 1; k > 0; k--) {\n      seg[k]\
    \ = f(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\n  void update(int k, T x) {\n\
    \    k += size;\n    seg[k] = x;\n    while (k >>= 1) {\n      seg[k] = f(seg[2\
    \ * k], seg[2 * k + 1]);\n    }\n  }\n\n  void add(int k, T x) {\n    k += size;\n\
    \    seg[k] += x;\n    while (k >>= 1) {\n      seg[k] = f(seg[2 * k], seg[2 *\
    \ k + 1]);\n    }\n  }\n\n  // query to [a, b)\n  T query(int a, int b) {\n  \
    \  T L = I, R = I;\n    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n\
    \      if (a & 1) L = f(L, seg[a++]);\n      if (b & 1) R = f(seg[--b], R);\n\
    \    }\n    return f(L, R);\n  }\n\n  T &operator[](const int &k) { return seg[k\
    \ + size]; }\n\n  template <typename C>\n  int find_subtree(int a, const C &check,\
    \ T &M, bool type) {\n    while (a < size) {\n      T nxt = type ? f(seg[2 * a\
    \ + type], M) : f(M, seg[2 * a + type]);\n      if (check(nxt))\n        a = 2\
    \ * a + type;\n      else\n        M = nxt, a = 2 * a + 1 - type;\n    }\n   \
    \ return a - size;\n  }\n\n  template <typename C>\n  int find_first(int a, const\
    \ C &check) {\n    T L = I;\n    if (a <= 0) {\n      if (check(f(L, seg[1])))\
    \ return find_subtree(1, check, L, false);\n      return -1;\n    }\n    int b\
    \ = size;\n    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n      if\
    \ (a & 1) {\n        T nxt = f(L, seg[a]);\n        if (check(nxt)) return find_subtree(a,\
    \ check, L, false);\n        L = nxt;\n        ++a;\n      }\n    }\n    return\
    \ -1;\n  }\n\n  template <typename C>\n  int find_last(int b, const C &check)\
    \ {\n    T R = I;\n    if (b >= size) {\n      if (check(f(seg[1], R))) return\
    \ find_subtree(1, check, R, true);\n      return -1;\n    }\n    int a = size;\n\
    \    for (b += size; a < b; a >>= 1, b >>= 1) {\n      if (b & 1) {\n        T\
    \ nxt = f(seg[--b], R);\n        if (check(nxt)) return find_subtree(b, check,\
    \ R, true);\n        R = nxt;\n      }\n    }\n    return -1;\n  }\n};\n#line\
    \ 6 \"data-structure-2d/segment-tree-on-range-tree.hpp\"\n\n// S ... index_type\n\
    // T ... value_type\n// F ... function_type\ntemplate <typename S, typename T,\
    \ typename F>\nstruct RangeTree {\n  using Seg = SegmentTree<T, F>;\n  using P\
    \ = pair<S, S>;\n\n  S N, M;\n  const F f;\n  T ti;\n  vector<SegmentTree<T, F>>\
    \ seg;\n  vector<vector<S>> ys;\n  vector<P> ps;\n\n  RangeTree(const F& f_, const\
    \ T& ti_) : f(f_), ti(ti_) {}\n\n  void add_point(S x, S y) { ps.push_back(make_pair(x,\
    \ y)); }\n\n  void build() {\n    sort(begin(ps), end(ps));\n    ps.erase(unique(begin(ps),\
    \ end(ps)), end(ps));\n    N = ps.size();\n    for (int i = 0; i < 2 * N; ++i)\
    \ seg.push_back(Seg{f, ti});\n    ys.resize(2 * N);\n    for (int i = 0; i < N;\
    \ ++i) {\n      ys[i + N].push_back(ps[i].second);\n      seg[i + N].init(1);\n\
    \    }\n    for (int i = N - 1; i > 0; --i) {\n      ys[i].resize(ys[i << 1].size()\
    \ + ys[(i << 1) | 1].size());\n      merge(begin(ys[(i << 1) | 0]), end(ys[(i\
    \ << 1) | 0]),\n            begin(ys[(i << 1) | 1]), end(ys[(i << 1) | 1]), begin(ys[i]));\n\
    \      ys[i].erase(unique(begin(ys[i]), end(ys[i])), end(ys[i]));\n      seg[i].init(ys[i].size());\n\
    \    }\n  }\n\n  int id(S x) const {\n    return lower_bound(\n              \
    \ begin(ps), end(ps), make_pair(x, S()),\n               [](const P& a, const\
    \ P& b) { return a.first < b.first; }) -\n           begin(ps);\n  }\n\n  int\
    \ id(int i, S y) const {\n    return lower_bound(begin(ys[i]), end(ys[i]), y)\
    \ - begin(ys[i]);\n  }\n\n  void add(S x, S y, T a) {\n    int i = lower_bound(begin(ps),\
    \ end(ps), make_pair(x, y)) - begin(ps);\n    assert(ps[i] == make_pair(x, y));\n\
    \    for (i += N; i; i >>= 1) seg[i].add(id(i, y), a);\n  }\n\n  T sum(S xl, S\
    \ yl, S xr, S yr) {\n    T L = ti, R = ti;\n    int a = id(xl), b = id(xr);\n\
    \    for (a += N, b += N; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L = f(L,\
    \ seg[a].query(id(a, yl), id(a, yr))), ++a;\n      if (b & 1) --b, R = f(seg[b].query(id(b,\
    \ yl), id(b, yr)), R);\n    }\n    return f(L, R);\n  }\n};\n\n/*\n * @brief \u9818\
    \u57DF\u6728(Segment Tree)\n * @docs docs/data-structure-2d/ds-2d.md\n */\n"
  code: "#pragma once\n\n\n\n#include \"../segment-tree/segment-tree.hpp\"\n\n// S\
    \ ... index_type\n// T ... value_type\n// F ... function_type\ntemplate <typename\
    \ S, typename T, typename F>\nstruct RangeTree {\n  using Seg = SegmentTree<T,\
    \ F>;\n  using P = pair<S, S>;\n\n  S N, M;\n  const F f;\n  T ti;\n  vector<SegmentTree<T,\
    \ F>> seg;\n  vector<vector<S>> ys;\n  vector<P> ps;\n\n  RangeTree(const F& f_,\
    \ const T& ti_) : f(f_), ti(ti_) {}\n\n  void add_point(S x, S y) { ps.push_back(make_pair(x,\
    \ y)); }\n\n  void build() {\n    sort(begin(ps), end(ps));\n    ps.erase(unique(begin(ps),\
    \ end(ps)), end(ps));\n    N = ps.size();\n    for (int i = 0; i < 2 * N; ++i)\
    \ seg.push_back(Seg{f, ti});\n    ys.resize(2 * N);\n    for (int i = 0; i < N;\
    \ ++i) {\n      ys[i + N].push_back(ps[i].second);\n      seg[i + N].init(1);\n\
    \    }\n    for (int i = N - 1; i > 0; --i) {\n      ys[i].resize(ys[i << 1].size()\
    \ + ys[(i << 1) | 1].size());\n      merge(begin(ys[(i << 1) | 0]), end(ys[(i\
    \ << 1) | 0]),\n            begin(ys[(i << 1) | 1]), end(ys[(i << 1) | 1]), begin(ys[i]));\n\
    \      ys[i].erase(unique(begin(ys[i]), end(ys[i])), end(ys[i]));\n      seg[i].init(ys[i].size());\n\
    \    }\n  }\n\n  int id(S x) const {\n    return lower_bound(\n              \
    \ begin(ps), end(ps), make_pair(x, S()),\n               [](const P& a, const\
    \ P& b) { return a.first < b.first; }) -\n           begin(ps);\n  }\n\n  int\
    \ id(int i, S y) const {\n    return lower_bound(begin(ys[i]), end(ys[i]), y)\
    \ - begin(ys[i]);\n  }\n\n  void add(S x, S y, T a) {\n    int i = lower_bound(begin(ps),\
    \ end(ps), make_pair(x, y)) - begin(ps);\n    assert(ps[i] == make_pair(x, y));\n\
    \    for (i += N; i; i >>= 1) seg[i].add(id(i, y), a);\n  }\n\n  T sum(S xl, S\
    \ yl, S xr, S yr) {\n    T L = ti, R = ti;\n    int a = id(xl), b = id(xr);\n\
    \    for (a += N, b += N; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L = f(L,\
    \ seg[a].query(id(a, yl), id(a, yr))), ++a;\n      if (b & 1) --b, R = f(seg[b].query(id(b,\
    \ yl), id(b, yr)), R);\n    }\n    return f(L, R);\n  }\n};\n\n/*\n * @brief \u9818\
    \u57DF\u6728(Segment Tree)\n * @docs docs/data-structure-2d/ds-2d.md\n */\n"
  dependsOn:
  - segment-tree/segment-tree.hpp
  isVerificationFile: false
  path: data-structure-2d/segment-tree-on-range-tree.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-dseg2d.test.cpp
documentation_of: data-structure-2d/segment-tree-on-range-tree.hpp
layout: document
redirect_from:
- /library/data-structure-2d/segment-tree-on-range-tree.hpp
- /library/data-structure-2d/segment-tree-on-range-tree.hpp.html
title: "\u9818\u57DF\u6728(Segment Tree)"
---
## 領域木

TODO: 書く
TODO: Merge Treeと領域木の呼び方が良くわかっていないので調べる

- 矩形和クエリ
  - 2D累積和
  - 永続セグメント木
  - Merge Tree
  - Wavelet Matrix
- 一点更新・矩形和クエリ
  - 2D Fenwick Tree
  - 2D Segment Tree
  - 動的 2D Fenwick Tree
  - 領域木(Segment Tree)
  - 抽象化領域木
  - 領域木(Fenwick Tree)
  - 動的Wavelet Matrix

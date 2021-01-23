---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure-2d/ds-2d.md
    document_title: "\u62BD\u8C61\u5316\u9818\u57DF\u6728"
    links: []
  bundledCode: "#line 2 \"data-structure-2d/abstract-range-tree.hpp\"\n\n// DS ...\
    \ data_structure_type\n// S ... size_type\n// T ... value_type\ntemplate <typename\
    \ DS, typename S, typename T>\nstruct RangeTree {\n  using NEW = function<DS*(int)>;\n\
    \  using ADD = function<void(DS&, int, T)>;\n  using SUM = function<T(DS&, int,\
    \ int)>;\n  using MRG = function<T(T, T)>;\n  using P = pair<S, S>;\n\n  S N,\
    \ M;\n  const NEW ds_new;\n  const ADD ds_add;\n  const SUM ds_sum;\n  const MRG\
    \ t_merge;\n  const T ti;\n  vector<DS*> ds;\n  vector<vector<S>> ys;\n  vector<P>\
    \ ps;\n\n  RangeTree(const NEW& nw, const ADD& ad, const SUM& sm, const MRG& mrg,\n\
    \            const T& ti_)\n      : ds_new(nw), ds_add(ad), ds_sum(sm), t_merge(mrg),\
    \ ti(ti_) {}\n\n  void add_point(S x, S y) { ps.push_back(make_pair(x, y)); }\n\
    \n  void build() {\n    sort(begin(ps), end(ps));\n    ps.erase(unique(begin(ps),\
    \ end(ps)), end(ps));\n    N = ps.size();\n    ds.resize(2 * N, nullptr);\n  \
    \  ys.resize(2 * N);\n    for (int i = 0; i < N; ++i) {\n      ys[i + N].push_back(ps[i].second);\n\
    \      ds[i + N] = ds_new(1);\n    }\n    for (int i = N - 1; i > 0; --i) {\n\
    \      ys[i].resize(ys[i << 1].size() + ys[(i << 1) | 1].size());\n      merge(begin(ys[(i\
    \ << 1) | 0]), end(ys[(i << 1) | 0]),\n            begin(ys[(i << 1) | 1]), end(ys[(i\
    \ << 1) | 1]), begin(ys[i]));\n      ys[i].erase(unique(begin(ys[i]), end(ys[i])),\
    \ end(ys[i]));\n      ds[i] = ds_new(ys[i].size());\n    }\n  }\n\n  int id(S\
    \ x) const {\n    return lower_bound(\n               begin(ps), end(ps), make_pair(x,\
    \ S()),\n               [](const P& a, const P& b) { return a.first < b.first;\
    \ }) -\n           begin(ps);\n  }\n\n  int id(int i, S y) const {\n    return\
    \ lower_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]);\n  }\n\n  void add(S\
    \ x, S y, T a) {\n    int i = lower_bound(begin(ps), end(ps), make_pair(x, y))\
    \ - begin(ps);\n    assert(ps[i] == make_pair(x, y));\n    for (i += N; i; i >>=\
    \ 1) ds_add(*ds[i], id(i, y), a);\n  }\n\n  T sum(S xl, S yl, S xr, S yr) {\n\
    \    T L = ti, R = ti;\n    int a = id(xl), b = id(xr);\n    for (a += N, b +=\
    \ N; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L = t_merge(L, ds_sum(*ds[a],\
    \ id(a, yl), id(a, yr))), ++a;\n      if (b & 1) --b, R = t_merge(ds_sum(*ds[b],\
    \ id(b, yl), id(b, yr)), R);\n    }\n    return t_merge(L, R);\n  }\n};\n\n/*\n\
    \ * @brief \u62BD\u8C61\u5316\u9818\u57DF\u6728\n * @docs docs/data-structure-2d/ds-2d.md\n\
    \ */\n"
  code: "#pragma once\n\n// DS ... data_structure_type\n// S ... size_type\n// T ...\
    \ value_type\ntemplate <typename DS, typename S, typename T>\nstruct RangeTree\
    \ {\n  using NEW = function<DS*(int)>;\n  using ADD = function<void(DS&, int,\
    \ T)>;\n  using SUM = function<T(DS&, int, int)>;\n  using MRG = function<T(T,\
    \ T)>;\n  using P = pair<S, S>;\n\n  S N, M;\n  const NEW ds_new;\n  const ADD\
    \ ds_add;\n  const SUM ds_sum;\n  const MRG t_merge;\n  const T ti;\n  vector<DS*>\
    \ ds;\n  vector<vector<S>> ys;\n  vector<P> ps;\n\n  RangeTree(const NEW& nw,\
    \ const ADD& ad, const SUM& sm, const MRG& mrg,\n            const T& ti_)\n \
    \     : ds_new(nw), ds_add(ad), ds_sum(sm), t_merge(mrg), ti(ti_) {}\n\n  void\
    \ add_point(S x, S y) { ps.push_back(make_pair(x, y)); }\n\n  void build() {\n\
    \    sort(begin(ps), end(ps));\n    ps.erase(unique(begin(ps), end(ps)), end(ps));\n\
    \    N = ps.size();\n    ds.resize(2 * N, nullptr);\n    ys.resize(2 * N);\n \
    \   for (int i = 0; i < N; ++i) {\n      ys[i + N].push_back(ps[i].second);\n\
    \      ds[i + N] = ds_new(1);\n    }\n    for (int i = N - 1; i > 0; --i) {\n\
    \      ys[i].resize(ys[i << 1].size() + ys[(i << 1) | 1].size());\n      merge(begin(ys[(i\
    \ << 1) | 0]), end(ys[(i << 1) | 0]),\n            begin(ys[(i << 1) | 1]), end(ys[(i\
    \ << 1) | 1]), begin(ys[i]));\n      ys[i].erase(unique(begin(ys[i]), end(ys[i])),\
    \ end(ys[i]));\n      ds[i] = ds_new(ys[i].size());\n    }\n  }\n\n  int id(S\
    \ x) const {\n    return lower_bound(\n               begin(ps), end(ps), make_pair(x,\
    \ S()),\n               [](const P& a, const P& b) { return a.first < b.first;\
    \ }) -\n           begin(ps);\n  }\n\n  int id(int i, S y) const {\n    return\
    \ lower_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]);\n  }\n\n  void add(S\
    \ x, S y, T a) {\n    int i = lower_bound(begin(ps), end(ps), make_pair(x, y))\
    \ - begin(ps);\n    assert(ps[i] == make_pair(x, y));\n    for (i += N; i; i >>=\
    \ 1) ds_add(*ds[i], id(i, y), a);\n  }\n\n  T sum(S xl, S yl, S xr, S yr) {\n\
    \    T L = ti, R = ti;\n    int a = id(xl), b = id(xr);\n    for (a += N, b +=\
    \ N; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L = t_merge(L, ds_sum(*ds[a],\
    \ id(a, yl), id(a, yr))), ++a;\n      if (b & 1) --b, R = t_merge(ds_sum(*ds[b],\
    \ id(b, yl), id(b, yr)), R);\n    }\n    return t_merge(L, R);\n  }\n};\n\n/*\n\
    \ * @brief \u62BD\u8C61\u5316\u9818\u57DF\u6728\n * @docs docs/data-structure-2d/ds-2d.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/abstract-range-tree.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
documentation_of: data-structure-2d/abstract-range-tree.hpp
layout: document
redirect_from:
- /library/data-structure-2d/abstract-range-tree.hpp
- /library/data-structure-2d/abstract-range-tree.hpp.html
title: "\u62BD\u8C61\u5316\u9818\u57DF\u6728"
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

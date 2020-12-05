---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-rtree-fenwick.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-rtree-fenwick.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure-2d/ds-2d.md
    document_title: "\u9818\u57DF\u6728(Binary Indexed Tree)"
    links: []
  bundledCode: "#line 2 \"data-structure-2d/fenwick-tree-on-range-tree.hpp\"\n\n\n\
    \n// S ... size_type\n// T ... value_type\ntemplate <typename S, typename T>\n\
    struct FenwickRangeTree {\n  struct BIT {\n    int N;\n    vector<T> data;\n\n\
    \    BIT() = default;\n    BIT(int size) { init(size); }\n\n    void init(int\
    \ size) {\n      N = size;\n      data.assign(N + 1, 0);\n    }\n\n    void add(int\
    \ k, T x) {\n      for (++k; k <= N; k += k & -k) data[k] += x;\n    }\n\n   \
    \ T sum(int k) const {\n      T ret = T();\n      for (; k; k -= k & -k) ret +=\
    \ data[k];\n      return ret;\n    }\n\n    inline T sum(int l, int r) const {\n\
    \      T ret = T();\n      while (l != r) {\n        if (l < r) {\n          ret\
    \ += data[r];\n          r -= r & -r;\n        } else {\n          ret -= data[l];\n\
    \          l -= l & -l;\n        }\n      }\n      return ret;\n    }\n  };\n\n\
    \  using P = pair<S, S>;\n  S N, M;\n  vector<BIT> bit;\n  vector<vector<S>> ys;\n\
    \  vector<P> ps;\n\n  FenwickRangeTree() = default;\n\n  void add_point(S x, S\
    \ y) { ps.push_back(make_pair(x, y)); }\n\n  void build() {\n    sort(begin(ps),\
    \ end(ps));\n    ps.erase(unique(begin(ps), end(ps)), end(ps));\n    N = ps.size();\n\
    \    bit.resize(N + 1);\n    ys.resize(N + 1);\n    for (int i = 0; i <= N; ++i)\
    \ {\n      for (int j = i + 1; j <= N; j += j & -j) ys[j].push_back(ps[i].second);\n\
    \      sort(begin(ys[i]), end(ys[i]));\n      ys[i].erase(unique(begin(ys[i]),\
    \ end(ys[i])), end(ys[i]));\n      bit[i].init(ys[i].size());\n    }\n  }\n\n\
    \  int id(S x) const {\n    return lower_bound(\n               begin(ps), end(ps),\
    \ make_pair(x, S()),\n               [](const P& a, const P& b) { return a.first\
    \ < b.first; }) -\n           begin(ps);\n  }\n\n  int id(int i, S y) const {\n\
    \    return lower_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]);\n  }\n\n\
    \  void add(S x, S y, T a) {\n    int i = lower_bound(begin(ps), end(ps), make_pair(x,\
    \ y)) - begin(ps);\n    assert(ps[i] == make_pair(x, y));\n    for (++i; i <=\
    \ N; i += i & -i) bit[i].add(id(i, y), a);\n  }\n\n  T sum(S x, S y) const {\n\
    \    T ret = T();\n    for (int a = id(x); a; a -= a & -a) ret += bit[a].sum(id(a,\
    \ y));\n    return ret;\n  }\n\n  T sum(S xl, S yl, S xr, S yr) const {\n    T\
    \ ret = T();\n    int a = id(xl), b = id(xr);\n    while (a != b) {\n      if\
    \ (a < b) {\n        ret += bit[b].sum(id(b, yl), id(b, yr));\n        b -= b\
    \ & -b;\n      } else {\n        ret -= bit[a].sum(id(a, yl), id(a, yr));\n  \
    \      a -= a & -a;\n      }\n    }\n    return ret;\n  }\n};\n\n/*\n * @brief\
    \ \u9818\u57DF\u6728(Binary Indexed Tree)\n * @docs docs/data-structure-2d/ds-2d.md\n\
    \ */\n"
  code: "#pragma once\n\n\n\n// S ... size_type\n// T ... value_type\ntemplate <typename\
    \ S, typename T>\nstruct FenwickRangeTree {\n  struct BIT {\n    int N;\n    vector<T>\
    \ data;\n\n    BIT() = default;\n    BIT(int size) { init(size); }\n\n    void\
    \ init(int size) {\n      N = size;\n      data.assign(N + 1, 0);\n    }\n\n \
    \   void add(int k, T x) {\n      for (++k; k <= N; k += k & -k) data[k] += x;\n\
    \    }\n\n    T sum(int k) const {\n      T ret = T();\n      for (; k; k -= k\
    \ & -k) ret += data[k];\n      return ret;\n    }\n\n    inline T sum(int l, int\
    \ r) const {\n      T ret = T();\n      while (l != r) {\n        if (l < r) {\n\
    \          ret += data[r];\n          r -= r & -r;\n        } else {\n       \
    \   ret -= data[l];\n          l -= l & -l;\n        }\n      }\n      return\
    \ ret;\n    }\n  };\n\n  using P = pair<S, S>;\n  S N, M;\n  vector<BIT> bit;\n\
    \  vector<vector<S>> ys;\n  vector<P> ps;\n\n  FenwickRangeTree() = default;\n\
    \n  void add_point(S x, S y) { ps.push_back(make_pair(x, y)); }\n\n  void build()\
    \ {\n    sort(begin(ps), end(ps));\n    ps.erase(unique(begin(ps), end(ps)), end(ps));\n\
    \    N = ps.size();\n    bit.resize(N + 1);\n    ys.resize(N + 1);\n    for (int\
    \ i = 0; i <= N; ++i) {\n      for (int j = i + 1; j <= N; j += j & -j) ys[j].push_back(ps[i].second);\n\
    \      sort(begin(ys[i]), end(ys[i]));\n      ys[i].erase(unique(begin(ys[i]),\
    \ end(ys[i])), end(ys[i]));\n      bit[i].init(ys[i].size());\n    }\n  }\n\n\
    \  int id(S x) const {\n    return lower_bound(\n               begin(ps), end(ps),\
    \ make_pair(x, S()),\n               [](const P& a, const P& b) { return a.first\
    \ < b.first; }) -\n           begin(ps);\n  }\n\n  int id(int i, S y) const {\n\
    \    return lower_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]);\n  }\n\n\
    \  void add(S x, S y, T a) {\n    int i = lower_bound(begin(ps), end(ps), make_pair(x,\
    \ y)) - begin(ps);\n    assert(ps[i] == make_pair(x, y));\n    for (++i; i <=\
    \ N; i += i & -i) bit[i].add(id(i, y), a);\n  }\n\n  T sum(S x, S y) const {\n\
    \    T ret = T();\n    for (int a = id(x); a; a -= a & -a) ret += bit[a].sum(id(a,\
    \ y));\n    return ret;\n  }\n\n  T sum(S xl, S yl, S xr, S yr) const {\n    T\
    \ ret = T();\n    int a = id(xl), b = id(xr);\n    while (a != b) {\n      if\
    \ (a < b) {\n        ret += bit[b].sum(id(b, yl), id(b, yr));\n        b -= b\
    \ & -b;\n      } else {\n        ret -= bit[a].sum(id(a, yl), id(a, yr));\n  \
    \      a -= a & -a;\n      }\n    }\n    return ret;\n  }\n};\n\n/*\n * @brief\
    \ \u9818\u57DF\u6728(Binary Indexed Tree)\n * @docs docs/data-structure-2d/ds-2d.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/fenwick-tree-on-range-tree.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-rtree-fenwick.test.cpp
documentation_of: data-structure-2d/fenwick-tree-on-range-tree.hpp
layout: document
redirect_from:
- /library/data-structure-2d/fenwick-tree-on-range-tree.hpp
- /library/data-structure-2d/fenwick-tree-on-range-tree.hpp.html
title: "\u9818\u57DF\u6728(Binary Indexed Tree)"
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

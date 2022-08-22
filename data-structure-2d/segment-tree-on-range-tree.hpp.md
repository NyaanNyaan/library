---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    document_title: "\u9818\u57DF\u6728(Segment Tree)"
    links: []
  bundledCode: "#line 2 \"data-structure-2d/segment-tree-on-range-tree.hpp\"\n\n\n\
    \n#line 2 \"segment-tree/segment-tree.hpp\"\n\ntemplate <typename T, typename\
    \ F>\nstruct SegmentTree {\n  int N;\n  int size;\n  vector<T> seg;\n  const F\
    \ f;\n  const T I;\n\n  SegmentTree(F _f, const T &I_) : N(0), size(0), f(_f),\
    \ I(I_) {}\n\n  SegmentTree(int _N, F _f, const T &I_) : f(_f), I(I_) { init(_N);\
    \ }\n\n  SegmentTree(const vector<T> &v, F _f, T I_) : f(_f), I(I_) {\n    init(v.size());\n\
    \    for (int i = 0; i < (int)v.size(); i++) {\n      seg[i + size] = v[i];\n\
    \    }\n    build();\n  }\n\n  void init(int _N) {\n    N = _N;\n    size = 1;\n\
    \    while (size < N) size <<= 1;\n    seg.assign(2 * size, I);\n  }\n\n  void\
    \ set(int k, T x) { seg[k + size] = x; }\n\n  void build() {\n    for (int k =\
    \ size - 1; k > 0; k--) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n   \
    \ }\n  }\n\n  void update(int k, T x) {\n    k += size;\n    seg[k] = x;\n   \
    \ while (k >>= 1) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\
    \n  void add(int k, T x) {\n    k += size;\n    seg[k] += x;\n    while (k >>=\
    \ 1) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n    }\n  }\n\n  // query\
    \ to [a, b)\n  T query(int a, int b) {\n    T L = I, R = I;\n    for (a += size,\
    \ b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L = f(L, seg[a++]);\n\
    \      if (b & 1) R = f(seg[--b], R);\n    }\n    return f(L, R);\n  }\n\n  T\
    \ &operator[](const int &k) { return seg[k + size]; }\n\n  // check(a[l] * ...\
    \  * a[r-1]) \u304C true \u3068\u306A\u308B\u6700\u5927\u306E r\n  // (\u53F3\u7AEF\
    \u307E\u3067\u3059\u3079\u3066 true \u306A\u3089 N \u3092\u8FD4\u3059)\n  template\
    \ <class C>\n  int max_right(int l, C check) {\n    assert(0 <= l && l <= N);\n\
    \    assert(check(I) == true);\n    if (l == N) return N;\n    l += size;\n  \
    \  T sm = I;\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(f(sm,\
    \ seg[l]))) {\n        while (l < size) {\n          l = (2 * l);\n          if\
    \ (check(f(sm, seg[l]))) {\n            sm = f(sm, seg[l]);\n            l++;\n\
    \          }\n        }\n        return l - size;\n      }\n      sm = f(sm, seg[l]);\n\
    \      l++;\n    } while ((l & -l) != l);\n    return N;\n  }\n\n  // check(a[l]\
    \ * ... * a[r-1]) \u304C true \u3068\u306A\u308B\u6700\u5C0F\u306E l\n  // (\u5DE6\
    \u7AEF\u307E\u3067 true \u306A\u3089 0 \u3092\u8FD4\u3059)\n  template <typename\
    \ C>\n  int min_left(int r, C check) {\n    assert(0 <= r && r <= N);\n    assert(check(I)\
    \ == true);\n    if (r == 0) return 0;\n    r += size;\n    T sm = I;\n    do\
    \ {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!check(f(seg[r],\
    \ sm))) {\n        while (r < size) {\n          r = (2 * r + 1);\n          if\
    \ (check(f(seg[r], sm))) {\n            sm = f(seg[r], sm);\n            r--;\n\
    \          }\n        }\n        return r + 1 - size;\n      }\n      sm = f(seg[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n};\n#line 6 \"data-structure-2d/segment-tree-on-range-tree.hpp\"\
    \n\n// S ... index_type\n// T ... value_type\n// F ... function_type\ntemplate\
    \ <typename S, typename T, typename F>\nstruct RangeTree {\n  using Seg = SegmentTree<T,\
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
    \u57DF\u6728(Segment Tree)\n */\n"
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
    \u57DF\u6728(Segment Tree)\n */\n"
  dependsOn:
  - segment-tree/segment-tree.hpp
  isVerificationFile: false
  path: data-structure-2d/segment-tree-on-range-tree.hpp
  requiredBy: []
  timestamp: '2021-12-30 19:20:16+09:00'
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

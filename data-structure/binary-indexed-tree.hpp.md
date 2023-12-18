---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/range-sum-range-add-bit.hpp
    title: data-structure/range-sum-range-add-bit.hpp
  - icon: ':heavy_check_mark:'
    path: dp/inversion-counting.hpp
    title: dp/inversion-counting.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-b-bit.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-b-bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-e-imos.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-e-imos.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-range-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-range-inversion-query-2.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-range-inversion-query-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
    title: verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
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
    path: verify/verify-yuki/yuki-1115.test.cpp
    title: verify/verify-yuki/yuki-1115.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/binary-indexed-tree.md
    document_title: Binary Indexed Tree(Fenwick Tree)
    links: []
  bundledCode: "#line 2 \"data-structure/binary-indexed-tree.hpp\"\n\ntemplate <typename\
    \ T>\nstruct BinaryIndexedTree {\n  int N;\n  vector<T> data;\n\n  BinaryIndexedTree()\
    \ = default;\n\n  BinaryIndexedTree(int size) { init(size); }\n\n  void init(int\
    \ size) {\n    N = size + 2;\n    data.assign(N + 1, {});\n  }\n\n  // get sum\
    \ of [0,k]\n  T sum(int k) const {\n    if (k < 0) return T{};  // return 0 if\
    \ k < 0\n    T ret{};\n    for (++k; k > 0; k -= k & -k) ret += data[k];\n   \
    \ return ret;\n  }\n\n  // getsum of [l,r]\n  inline T sum(int l, int r) const\
    \ { return sum(r) - sum(l - 1); }\n\n  // get value of k\n  inline T operator[](int\
    \ k) const { return sum(k) - sum(k - 1); }\n\n  // data[k] += x\n  void add(int\
    \ k, T x) {\n    for (++k; k < N; k += k & -k) data[k] += x;\n  }\n\n  // range\
    \ add x to [l,r]\n  void imos(int l, int r, T x) {\n    add(l, x);\n    add(r\
    \ + 1, -x);\n  }\n\n  // minimize i s.t. sum(i) >= w\n  int lower_bound(T w) {\n\
    \    if (w <= 0) return 0;\n    int x = 0;\n    for (int k = 1 << __lg(N); k;\
    \ k >>= 1) {\n      if (x + k <= N - 1 && data[x + k] < w) {\n        w -= data[x\
    \ + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n\n  // minimize\
    \ i s.t. sum(i) > w\n  int upper_bound(T w) {\n    if (w < 0) return 0;\n    int\
    \ x = 0;\n    for (int k = 1 << __lg(N); k; k >>= 1) {\n      if (x + k <= N -\
    \ 1 && data[x + k] <= w) {\n        w -= data[x + k];\n        x += k;\n     \
    \ }\n    }\n    return x;\n  }\n};\n\n/**\n * @brief Binary Indexed Tree(Fenwick\
    \ Tree)\n * @docs docs/data-structure/binary-indexed-tree.md\n */\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct BinaryIndexedTree {\n  int\
    \ N;\n  vector<T> data;\n\n  BinaryIndexedTree() = default;\n\n  BinaryIndexedTree(int\
    \ size) { init(size); }\n\n  void init(int size) {\n    N = size + 2;\n    data.assign(N\
    \ + 1, {});\n  }\n\n  // get sum of [0,k]\n  T sum(int k) const {\n    if (k <\
    \ 0) return T{};  // return 0 if k < 0\n    T ret{};\n    for (++k; k > 0; k -=\
    \ k & -k) ret += data[k];\n    return ret;\n  }\n\n  // getsum of [l,r]\n  inline\
    \ T sum(int l, int r) const { return sum(r) - sum(l - 1); }\n\n  // get value\
    \ of k\n  inline T operator[](int k) const { return sum(k) - sum(k - 1); }\n\n\
    \  // data[k] += x\n  void add(int k, T x) {\n    for (++k; k < N; k += k & -k)\
    \ data[k] += x;\n  }\n\n  // range add x to [l,r]\n  void imos(int l, int r, T\
    \ x) {\n    add(l, x);\n    add(r + 1, -x);\n  }\n\n  // minimize i s.t. sum(i)\
    \ >= w\n  int lower_bound(T w) {\n    if (w <= 0) return 0;\n    int x = 0;\n\
    \    for (int k = 1 << __lg(N); k; k >>= 1) {\n      if (x + k <= N - 1 && data[x\
    \ + k] < w) {\n        w -= data[x + k];\n        x += k;\n      }\n    }\n  \
    \  return x;\n  }\n\n  // minimize i s.t. sum(i) > w\n  int upper_bound(T w) {\n\
    \    if (w < 0) return 0;\n    int x = 0;\n    for (int k = 1 << __lg(N); k; k\
    \ >>= 1) {\n      if (x + k <= N - 1 && data[x + k] <= w) {\n        w -= data[x\
    \ + k];\n        x += k;\n      }\n    }\n    return x;\n  }\n};\n\n/**\n * @brief\
    \ Binary Indexed Tree(Fenwick Tree)\n * @docs docs/data-structure/binary-indexed-tree.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-indexed-tree.hpp
  requiredBy:
  - data-structure/range-sum-range-add-bit.hpp
  - dp/inversion-counting.hpp
  timestamp: '2021-12-20 22:10:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1115.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-e-imos.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-2-b-bit.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-dst-on-tree.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum-euler-tree.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-add-range-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-abstruct-range-tree.test.cpp
  - verify/verify-yosupo-ds/yosupo-static-range-inversion-query-2.test.cpp
documentation_of: data-structure/binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/data-structure/binary-indexed-tree.hpp
- /library/data-structure/binary-indexed-tree.hpp.html
title: Binary Indexed Tree(Fenwick Tree)
---
## Binary Indexed Tree

#### 概要

Binary Indexed Tree(BIT, Fenwick Treeとも)とは、要素数$n$の数列に対して、値の一点加算と区間和の取得を$\mathrm{O}(\log n)$で行うことが出来るデータ構造である。実装がシンプルで定数倍が非常に軽い一方、Segment Treeと異なり逆元が存在しないと区間和が求められないという欠点もある。

また、imos法と併用することで区間加算と一点取得を$\mathrm{O}(\log N)$で行うこともできる。(実はimos法を使用しなくても実装を少し書き換えれば区間加算・一点取得BITは実現できるがここでは実装していない。)

#### 使い方

- `BinaryIndexedTree<T>(size)`: 要素数$size+1$のBITを作成する。
- `add(k, x)`: k番目の要素にxを加算する。
- `operator[](k)`: k番目の要素を取得する。
- `sum(k)`: 区間`[0, k]`の和を取得する。(閉区間に注意)
- `sum(l, r)`: 区間`[l, r]`の和を取得する。(閉区間に注意)
- `imos(l, r, k)`: imos法を利用するとき、`[l, r]`にkを加算する。(この時、一点取得は`sum(k)`で行う。)
- `lower_bound(w)`: 要素が全て非負の時、`[0, k]`の区間和がw以上となるような最小のkを求める。
- `upper_bound(w)`: 要素が全て非負の時、`[0, k]`の区間和がwよりも大きくなるような最小のkを求める。

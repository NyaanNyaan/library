---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/minimum-cost-arborescence.hpp
    title: graph/minimum-cost-arborescence.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-directed-mst.test.cpp
    title: verify/verify-yosupo-graph/yosupo-directed-mst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/skew-heap.md
    document_title: Skew Heap
    links: []
  bundledCode: "#line 2 \"data-structure/skew-heap.hpp\"\n\ntemplate <typename T,\
    \ bool isMin = true>\nstruct SkewHeap {\n  struct Node {\n    T key, laz;\n  \
    \  Node *l, *r;\n    int idx;\n    Node() = default;\n    Node(const T &k, int\
    \ i = -1)\n        : key(k), laz(0), l(nullptr), r(nullptr), idx(i) {}\n  };\n\
    \  using Ptr = Node *;\n\n  static void propagate(Ptr x) {\n    if (x->laz ==\
    \ 0) return;\n    if (x->l) x->l->laz += x->laz;\n    if (x->r) x->r->laz += x->laz;\n\
    \    x->key += x->laz;\n    x->laz = 0;\n  }\n\n  static Ptr meld(Ptr x, Ptr y)\
    \ {\n    if (!x || !y) return x ? x : y;\n    if (!comp(x, y)) swap(x, y);\n \
    \   propagate(x);\n    x->r = meld(x->r, y);\n    swap(x->l, x->r);\n    return\
    \ x;\n  }\n\n  static Ptr alloc(const T &key, int idx = -1) { return new Node(key,\
    \ idx); }\n\n  static Ptr pop(Ptr x) {\n    propagate(x);\n    return meld(x->l,\
    \ x->r);\n  }\n\n  static Ptr push(Ptr x, const T &key, int idx = -1) {\n    return\
    \ meld(x, alloc(key, idx));\n  }\n\n  static void apply(Ptr x, const T &laz) {\n\
    \    x->laz += laz;\n    propagate(x);\n  }\n\n private:\n  static inline bool\
    \ comp(Ptr x, Ptr y) {\n    if constexpr (isMin) {\n      return x->key + x->laz\
    \ < y->key + y->laz;\n    } else {\n      return x->key + x->laz > y->key + y->laz;\n\
    \    }\n  }\n};\n\n/**\n * @brief Skew Heap\n * @docs docs/data-structure/skew-heap.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename T, bool isMin = true>\nstruct SkewHeap\
    \ {\n  struct Node {\n    T key, laz;\n    Node *l, *r;\n    int idx;\n    Node()\
    \ = default;\n    Node(const T &k, int i = -1)\n        : key(k), laz(0), l(nullptr),\
    \ r(nullptr), idx(i) {}\n  };\n  using Ptr = Node *;\n\n  static void propagate(Ptr\
    \ x) {\n    if (x->laz == 0) return;\n    if (x->l) x->l->laz += x->laz;\n   \
    \ if (x->r) x->r->laz += x->laz;\n    x->key += x->laz;\n    x->laz = 0;\n  }\n\
    \n  static Ptr meld(Ptr x, Ptr y) {\n    if (!x || !y) return x ? x : y;\n   \
    \ if (!comp(x, y)) swap(x, y);\n    propagate(x);\n    x->r = meld(x->r, y);\n\
    \    swap(x->l, x->r);\n    return x;\n  }\n\n  static Ptr alloc(const T &key,\
    \ int idx = -1) { return new Node(key, idx); }\n\n  static Ptr pop(Ptr x) {\n\
    \    propagate(x);\n    return meld(x->l, x->r);\n  }\n\n  static Ptr push(Ptr\
    \ x, const T &key, int idx = -1) {\n    return meld(x, alloc(key, idx));\n  }\n\
    \n  static void apply(Ptr x, const T &laz) {\n    x->laz += laz;\n    propagate(x);\n\
    \  }\n\n private:\n  static inline bool comp(Ptr x, Ptr y) {\n    if constexpr\
    \ (isMin) {\n      return x->key + x->laz < y->key + y->laz;\n    } else {\n \
    \     return x->key + x->laz > y->key + y->laz;\n    }\n  }\n};\n\n/**\n * @brief\
    \ Skew Heap\n * @docs docs/data-structure/skew-heap.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/skew-heap.hpp
  requiredBy:
  - graph/minimum-cost-arborescence.hpp
  timestamp: '2021-02-04 22:39:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-directed-mst.test.cpp
documentation_of: data-structure/skew-heap.hpp
layout: document
redirect_from:
- /library/data-structure/skew-heap.hpp
- /library/data-structure/skew-heap.hpp.html
title: Skew Heap
---
## Skew Heap

Skew Heapを実装したライブラリ。

## 概要

Skew Heapとは、ヒープ同士のマージ(融合, meld)やヒープ全体に定数を加算する操作を高速に行うことが出来るヒープである。アルゴリズム自体は一読して理解できる程度に簡潔だが計算量解析は難しい。[(参考)](http://hos.ac/blog/#blog0001)

ヒープ全体への定数の加算を諦める代わりに特定のノードの値を高速に更新する機能をつけることが出来て、ダイクストラ法の定数倍高速化に利用される。

#### 使い方

平衡二分木などのライブラリと同様に根のノードをポインタで持つ形で管理する。`push, pop`などの操作を行ったときに根が変化するので、返り値で新しい根を返す。

根に最小の値が入っていて、`p->key + p->add`で`key`を、`p->idx`で`key`に関連する情報を取得することが出来る。

- `SkewHeap<T, isMin = true>`: 型`T`を`key`の型として最小値が根になるヒープ。`isMin`をFalseにすると最大値が根になる。
- `Ptr push(Ptr x, const T& key, int idx)`: 根を`x`とするヒープに`(key, idx)`を挿入して新しい根へのポインタを返す。
- `Ptr pop(Ptr x)`: 根のノードを削除して新しい根へのポインタを返す。
- `Ptr alloc(const T& key, int idx)`: `(key, idx)`を持ったノードを新しく作成して、ポインタを返す。
- `meld(Ptr x, Ptr y)`: `x`と`y`を融合して新たな根のポインタを返す。

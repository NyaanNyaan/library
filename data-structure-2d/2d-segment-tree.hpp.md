---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-5-b-2dseg.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-5-b-2dseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-1068.test.cpp
    title: verify/verify-aoj-other/aoj-1068.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure-2d/2d-segment-tree.md
    document_title: "\u4E8C\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"data-structure-2d/2d-segment-tree.hpp\"\n\ntemplate <typename\
    \ T, typename F>\nstruct SegmentTree2D {\n private:\n  int id(int h, int w) const\
    \ { return h * 2 * W + w; }\n\n public:\n  int H, W;\n  vector<T> seg;\n  const\
    \ F f;\n  const T I;\n\n  SegmentTree2D(int h, int w, F _f, const T& i) : f(_f),\
    \ I(i) { init(h, w); }\n\n  void init(int h, int w) {\n    H = W = 1;\n    while\
    \ (H < h) H <<= 1;\n    while (W < w) W <<= 1;\n    seg.assign(4 * H * W, I);\n\
    \  }\n\n  // build \u306B\u306E\u307F\u547C\u3076\n  void set(int h, int w, const\
    \ T& x) { seg[id(h + H, w + W)] = x; }\n\n  void build() {\n    // w in [W, 2W)\n\
    \    for (int w = W; w < 2 * W; w++) {\n      for (int h = H - 1; h; h--) {\n\
    \        seg[id(h, w)] = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);\n  \
    \    }\n    }\n    // h in [0, 2H)\n    for (int h = 0; h < 2 * H; h++) {\n  \
    \    for (int w = W - 1; w; w--) {\n        seg[id(h, w)] = f(seg[id(h, 2 * w\
    \ + 0)], seg[id(h, 2 * w + 1)]);\n      }\n    }\n  }\n\n  T get(int h, int w)\
    \ const { return seg[id(h + H, w + W)]; }\n  T operator()(int h, int w) const\
    \ { return seg[id(h + H, w + W)]; }\n\n  void update(int h, int w, const T& x)\
    \ {\n    h += H, w += W;\n    seg[id(h, w)] = x;\n    for (int i = h >> 1; i;\
    \ i >>= 1) {\n      seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1,\
    \ w)]);\n    }\n    for (; h; h >>= 1) {\n      for (int j = w >> 1; j; j >>=\
    \ 1) {\n        seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);\n\
    \      }\n    }\n  }\n\n  T _inner_query(int h, int w1, int w2) {\n    T res =\
    \ I;\n    for (; w1 < w2; w1 >>= 1, w2 >>= 1) {\n      if (w1 & 1) res = f(res,\
    \ seg[id(h, w1)]), w1++;\n      if (w2 & 1) --w2, res = f(res, seg[id(h, w2)]);\n\
    \    }\n    return res;\n  }\n\n  // [ (h1,w1), (h2,w2) ) \u534A\u958B\n  T query(int\
    \ h1, int w1, int h2, int w2) {\n    if (h1 >= h2 || w1 >= w2) return I;\n   \
    \ T res = I;\n    h1 += H, h2 += H, w1 += W, w2 += W;\n    for (; h1 < h2; h1\
    \ >>= 1, h2 >>= 1) {\n      if (h1 & 1) res = f(res, _inner_query(h1, w1, w2)),\
    \ h1++;\n      if (h2 & 1) --h2, res = f(res, _inner_query(h2, w1, w2));\n   \
    \ }\n    return res;\n  }\n};\n\n/**\n * @brief \u4E8C\u6B21\u5143\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @docs docs/data-structure-2d/2d-segment-tree.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename T, typename F>\nstruct SegmentTree2D {\n\
    \ private:\n  int id(int h, int w) const { return h * 2 * W + w; }\n\n public:\n\
    \  int H, W;\n  vector<T> seg;\n  const F f;\n  const T I;\n\n  SegmentTree2D(int\
    \ h, int w, F _f, const T& i) : f(_f), I(i) { init(h, w); }\n\n  void init(int\
    \ h, int w) {\n    H = W = 1;\n    while (H < h) H <<= 1;\n    while (W < w) W\
    \ <<= 1;\n    seg.assign(4 * H * W, I);\n  }\n\n  // build \u306B\u306E\u307F\u547C\
    \u3076\n  void set(int h, int w, const T& x) { seg[id(h + H, w + W)] = x; }\n\n\
    \  void build() {\n    // w in [W, 2W)\n    for (int w = W; w < 2 * W; w++) {\n\
    \      for (int h = H - 1; h; h--) {\n        seg[id(h, w)] = f(seg[id(2 * h +\
    \ 0, w)], seg[id(2 * h + 1, w)]);\n      }\n    }\n    // h in [0, 2H)\n    for\
    \ (int h = 0; h < 2 * H; h++) {\n      for (int w = W - 1; w; w--) {\n       \
    \ seg[id(h, w)] = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);\n      }\n\
    \    }\n  }\n\n  T get(int h, int w) const { return seg[id(h + H, w + W)]; }\n\
    \  T operator()(int h, int w) const { return seg[id(h + H, w + W)]; }\n\n  void\
    \ update(int h, int w, const T& x) {\n    h += H, w += W;\n    seg[id(h, w)] =\
    \ x;\n    for (int i = h >> 1; i; i >>= 1) {\n      seg[id(i, w)] = f(seg[id(2\
    \ * i + 0, w)], seg[id(2 * i + 1, w)]);\n    }\n    for (; h; h >>= 1) {\n   \
    \   for (int j = w >> 1; j; j >>= 1) {\n        seg[id(h, j)] = f(seg[id(h, 2\
    \ * j + 0)], seg[id(h, 2 * j + 1)]);\n      }\n    }\n  }\n\n  T _inner_query(int\
    \ h, int w1, int w2) {\n    T res = I;\n    for (; w1 < w2; w1 >>= 1, w2 >>= 1)\
    \ {\n      if (w1 & 1) res = f(res, seg[id(h, w1)]), w1++;\n      if (w2 & 1)\
    \ --w2, res = f(res, seg[id(h, w2)]);\n    }\n    return res;\n  }\n\n  // [ (h1,w1),\
    \ (h2,w2) ) \u534A\u958B\n  T query(int h1, int w1, int h2, int w2) {\n    if\
    \ (h1 >= h2 || w1 >= w2) return I;\n    T res = I;\n    h1 += H, h2 += H, w1 +=\
    \ W, w2 += W;\n    for (; h1 < h2; h1 >>= 1, h2 >>= 1) {\n      if (h1 & 1) res\
    \ = f(res, _inner_query(h1, w1, w2)), h1++;\n      if (h2 & 1) --h2, res = f(res,\
    \ _inner_query(h2, w1, w2));\n    }\n    return res;\n  }\n};\n\n/**\n * @brief\
    \ \u4E8C\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs docs/data-structure-2d/2d-segment-tree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/2d-segment-tree.hpp
  requiredBy: []
  timestamp: '2023-09-08 22:52:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-5-b-2dseg.test.cpp
  - verify/verify-aoj-other/aoj-1068.test.cpp
documentation_of: data-structure-2d/2d-segment-tree.hpp
layout: document
redirect_from:
- /library/data-structure-2d/2d-segment-tree.hpp
- /library/data-structure-2d/2d-segment-tree.hpp.html
title: "\u4E8C\u6B21\u5143\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
## 二次元セグメント木

#### 概要

二次元セグメント木とは、二次元配列上において非可換なモノイドに関する演算を計算するときに使用できるデータ構造である。

大きさ $H \times W$ の二次元配列に対して

- 要素の一点更新
- 二次元領域の総積の取得

を $\mathrm{O}(\log H \log W)$ で行うことができる。

#### 使い方

- テンプレート引数 `T` : データの型。
- テンプレート引数 `F` : モノイドを計算する関数の型。
- `SegmentTree2D(h, w, _f, const T& i)` : コンストラクタ。`h,w` は配列の縦横のサイズ、`_f` はモノイドを計算する関数、`i` はモノイドの単位元が載る。時間・空間ともに $\mathrm{O}(hw)$
- `void init(h, w)` : サイズを $h \times w$ に、要素を単位元 $I$ に初期化する。$\mathrm{O}(hw)$
- `void set(h, w, x)` : 配列を $A$ として $A_{h,w}$ の値を更新する。**`build` より前に呼ぶ必要がある。** $\mathrm{O}(1)$ 
- `void build()` : データ構造を構築する。$\mathrm{O}(hw)$
- `T& get(h, w)`, `operator()(h, w)` : $A_{h,w}$ の値を取得する。 $\mathrm{O}(1)$
- `void update(h, w, x)` : 配列を $A$ として $A_{h,w}$ の値を更新する。いつでも呼ぶことができる。 $\mathrm{O}(\log H \log W)$ 
- `void query(h1, w1, h2, w2)` : 区間 $[A_{h_1,w_1}, A_{h2, w2})$ の総積を取得する。$\mathrm{O}(\log H \log W)$ 
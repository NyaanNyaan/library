---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-5-b-bit2d.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-5-b-bit2d.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure-2d/ds-2d.md
    document_title: "\u4E8C\u6B21\u5143Binary Indexed Tree"
    links: []
  bundledCode: "#line 2 \"data-structure-2d/2d-binary-indexed-tree.hpp\"\n\ntemplate\
    \ <typename T>\nstruct BinaryIndexedTree2D {\n  int H, W;\n  vector<vector<T>>\
    \ bit;\n  BinaryIndexedTree2D(int H, int W) : H(H + 1), W(W + 1) {\n    bit.resize(H\
    \ + 3, vector<T>(W + 3, 0));\n  }\n  // \u95A2\u6570\u306E\u5165\u529B\u306Eindex\u306F\
    0-origin\u3092\u60F3\u5B9A\n\n  // (x,y)\u306Bw\u3092\u8DB3\u3059\n  // \u7BC4\
    \u56F2\u5916\u306E\u6642\u306F\u8DB3\u3055\u306A\u3044\n  void add(int x, int\
    \ y, T w) {\n    if (x < 0 || x >= H || y < 0 || y >= W) return;\n    for (int\
    \ a = (++y, ++x); a <= H; a += a & -a) {\n      for (int b = y; b <= W; b += b\
    \ & -b) {\n        bit[a][b] += w;\n      }\n    }\n  }\n\n  // imos\u6CD5\u3067\
    [(x1,y1) , (x2,y2)]\u306Bw\u3092\u8DB3\u3059\n  void imos(int x1, int y1, int\
    \ x2, int y2, T w) {\n    add(x1, y1, w);\n    add(x1, y2 + 1, -w);\n    add(x2\
    \ + 1, y1, -w);\n    add(x2 + 1, y2 + 1, w);\n  }\n\n  //  [(0,0) , (x,y)]\u306E\
    \u548C\u3000\u9589\u533A\u9593\u306B\u6CE8\u610F\uFF01\n  // x,y<0\u306E\u6642\
    \u306F0 x>=H y>=W\u306E\u3068\u304D\u306Fx=H-1,y=W-1\u3068\u307F\u306A\u3059\n\
    \  // ( imos\u6CD5\u306E\u6642\u306F (x,y)\u306E\u5024\u3092\u8FD4\u3059 )\n \
    \ T sum(int x, int y) {\n    if (x < 0 || y < 0) return 0;\n    if (x >= H) x\
    \ = H - 1;\n    if (y >= W) y = W - 1;\n    T ret = 0;\n    for (int a = (++y,\
    \ ++x); a > 0; a -= a & -a) {\n      for (int b = y; b > 0; b -= b & -b) {\n \
    \       ret += bit[a][b];\n      }\n    }\n    return ret;\n  }\n\n  // [(x1,y1)\
    \ , (x2,y2)] \u306E\u548C\n  // x1 > x2, y1 > y2\u306E\u6642\u306Fswap\n  T sum(int\
    \ x1, int y1, int x2, int y2) {\n    if (x1 > x2 || y1 > y2) return T(0);\n  \
    \  return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) +\n           sum(x1\
    \ - 1, y1 - 1);\n  }\n};\n\n/*\n * @brief \u4E8C\u6B21\u5143Binary Indexed Tree\n\
    \ * @docs docs/data-structure-2d/ds-2d.md\n */\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct BinaryIndexedTree2D {\n  int\
    \ H, W;\n  vector<vector<T>> bit;\n  BinaryIndexedTree2D(int H, int W) : H(H +\
    \ 1), W(W + 1) {\n    bit.resize(H + 3, vector<T>(W + 3, 0));\n  }\n  // \u95A2\
    \u6570\u306E\u5165\u529B\u306Eindex\u306F0-origin\u3092\u60F3\u5B9A\n\n  // (x,y)\u306B\
    w\u3092\u8DB3\u3059\n  // \u7BC4\u56F2\u5916\u306E\u6642\u306F\u8DB3\u3055\u306A\
    \u3044\n  void add(int x, int y, T w) {\n    if (x < 0 || x >= H || y < 0 || y\
    \ >= W) return;\n    for (int a = (++y, ++x); a <= H; a += a & -a) {\n      for\
    \ (int b = y; b <= W; b += b & -b) {\n        bit[a][b] += w;\n      }\n    }\n\
    \  }\n\n  // imos\u6CD5\u3067[(x1,y1) , (x2,y2)]\u306Bw\u3092\u8DB3\u3059\n  void\
    \ imos(int x1, int y1, int x2, int y2, T w) {\n    add(x1, y1, w);\n    add(x1,\
    \ y2 + 1, -w);\n    add(x2 + 1, y1, -w);\n    add(x2 + 1, y2 + 1, w);\n  }\n\n\
    \  //  [(0,0) , (x,y)]\u306E\u548C\u3000\u9589\u533A\u9593\u306B\u6CE8\u610F\uFF01\
    \n  // x,y<0\u306E\u6642\u306F0 x>=H y>=W\u306E\u3068\u304D\u306Fx=H-1,y=W-1\u3068\
    \u307F\u306A\u3059\n  // ( imos\u6CD5\u306E\u6642\u306F (x,y)\u306E\u5024\u3092\
    \u8FD4\u3059 )\n  T sum(int x, int y) {\n    if (x < 0 || y < 0) return 0;\n \
    \   if (x >= H) x = H - 1;\n    if (y >= W) y = W - 1;\n    T ret = 0;\n    for\
    \ (int a = (++y, ++x); a > 0; a -= a & -a) {\n      for (int b = y; b > 0; b -=\
    \ b & -b) {\n        ret += bit[a][b];\n      }\n    }\n    return ret;\n  }\n\
    \n  // [(x1,y1) , (x2,y2)] \u306E\u548C\n  // x1 > x2, y1 > y2\u306E\u6642\u306F\
    swap\n  T sum(int x1, int y1, int x2, int y2) {\n    if (x1 > x2 || y1 > y2) return\
    \ T(0);\n    return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) +\n      \
    \     sum(x1 - 1, y1 - 1);\n  }\n};\n\n/*\n * @brief \u4E8C\u6B21\u5143Binary\
    \ Indexed Tree\n * @docs docs/data-structure-2d/ds-2d.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/2d-binary-indexed-tree.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-5-b-bit2d.test.cpp
documentation_of: data-structure-2d/2d-binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/data-structure-2d/2d-binary-indexed-tree.hpp
- /library/data-structure-2d/2d-binary-indexed-tree.hpp.html
title: "\u4E8C\u6B21\u5143Binary Indexed Tree"
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

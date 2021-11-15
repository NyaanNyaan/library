---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-5-b.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-5-b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure-2d/ds-2d.md
    document_title: "\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 2 \"data-structure-2d/2d-cumulative-sum.hpp\"\n\ntemplate <class\
    \ T>\nstruct CumulativeSum2D {\n  vector<vector<T> > data;\n\n  CumulativeSum2D(int\
    \ H, int W) : data(H + 3, vector<int>(W + 3, 0)) {}\n\n  void add(int i, int j,\
    \ T z) {\n    ++i, ++j;\n    if (i >= (int)data.size() || j >= (int)data[0].size())\
    \ return;\n    data[i][j] += z;\n  }\n\n  // \u534A\u958B\n  void imos(int i1,\
    \ int j1, int i2, int j2, T z = 1) {\n    add(i1, j1, z);\n    add(i1, j2, -z);\n\
    \    add(i2, j1, -z);\n    add(i2, j2, z);\n  }\n\n  void build() {\n    for (int\
    \ i = 1; i < (int)data.size(); i++) {\n      for (int j = 1; j < (int)data[i].size();\
    \ j++) {\n        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j\
    \ - 1];\n      }\n    }\n  }\n\n  // imos (i,j) \u3092 get\n  T imos_get(int i,\
    \ int j) { return data[i + 1][j + 1]; }\n\n  // \u534A\u958B\n  T query(int i1,\
    \ int j1, int i2, int j2) {\n    return (data[i2][j2] - data[i1][j2] - data[i2][j1]\
    \ + data[i1][j1]);\n  }\n};\n\n/*\n * @brief \u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C\
    \n * @docs docs/data-structure-2d/ds-2d.md\n */\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct CumulativeSum2D {\n  vector<vector<T>\
    \ > data;\n\n  CumulativeSum2D(int H, int W) : data(H + 3, vector<int>(W + 3,\
    \ 0)) {}\n\n  void add(int i, int j, T z) {\n    ++i, ++j;\n    if (i >= (int)data.size()\
    \ || j >= (int)data[0].size()) return;\n    data[i][j] += z;\n  }\n\n  // \u534A\
    \u958B\n  void imos(int i1, int j1, int i2, int j2, T z = 1) {\n    add(i1, j1,\
    \ z);\n    add(i1, j2, -z);\n    add(i2, j1, -z);\n    add(i2, j2, z);\n  }\n\n\
    \  void build() {\n    for (int i = 1; i < (int)data.size(); i++) {\n      for\
    \ (int j = 1; j < (int)data[i].size(); j++) {\n        data[i][j] += data[i][j\
    \ - 1] + data[i - 1][j] - data[i - 1][j - 1];\n      }\n    }\n  }\n\n  // imos\
    \ (i,j) \u3092 get\n  T imos_get(int i, int j) { return data[i + 1][j + 1]; }\n\
    \n  // \u534A\u958B\n  T query(int i1, int j1, int i2, int j2) {\n    return (data[i2][j2]\
    \ - data[i1][j2] - data[i2][j1] + data[i1][j1]);\n  }\n};\n\n/*\n * @brief \u4E8C\
    \u6B21\u5143\u7D2F\u7A4D\u548C\n * @docs docs/data-structure-2d/ds-2d.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/2d-cumulative-sum.hpp
  requiredBy: []
  timestamp: '2021-11-14 23:34:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-5-b.test.cpp
documentation_of: data-structure-2d/2d-cumulative-sum.hpp
layout: document
redirect_from:
- /library/data-structure-2d/2d-cumulative-sum.hpp
- /library/data-structure-2d/2d-cumulative-sum.hpp.html
title: "\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
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

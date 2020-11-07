---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/dynamic-union-find.md
    document_title: "\u52D5\u7684Union Find"
    links: []
  bundledCode: "#line 2 \"data-structure/dynamic-union-find.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct DynamicUnionFind {\n  unordered_map<int, int> m;\n\
    \  DynamicUnionFind() {}\n\n  int data(int k) {\n    auto itk = m.find(k);\n \
    \   return itk == m.end() ? m[k] = -1 : itk->second;\n  }\n  int find(int k) {\n\
    \    int datk = data(k);\n    return datk < 0 ? k : m[k] = find(datk);\n  }\n\n\
    \  int unite(int x, int y) {\n    if ((x = find(x)) == (y = find(y))) return false;\n\
    \    auto itx = m.find(x), ity = m.find(y);\n    if (itx->second > ity->second)\
    \ {\n      ity->second += itx->second;\n      itx->second = y;\n    } else {\n\
    \      itx->second += ity->second;\n      ity->second = x;\n    }\n    return\
    \ true;\n  }\n\n  int size(int k) { return -data(find(k)); }\n\n  int same(int\
    \ x, int y) { return find(x) == find(y); }\n};\n\n/**\n * @brief \u52D5\u7684\
    Union Find\n * @docs docs/data-structure/dynamic-union-find.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct DynamicUnionFind\
    \ {\n  unordered_map<int, int> m;\n  DynamicUnionFind() {}\n\n  int data(int k)\
    \ {\n    auto itk = m.find(k);\n    return itk == m.end() ? m[k] = -1 : itk->second;\n\
    \  }\n  int find(int k) {\n    int datk = data(k);\n    return datk < 0 ? k :\
    \ m[k] = find(datk);\n  }\n\n  int unite(int x, int y) {\n    if ((x = find(x))\
    \ == (y = find(y))) return false;\n    auto itx = m.find(x), ity = m.find(y);\n\
    \    if (itx->second > ity->second) {\n      ity->second += itx->second;\n   \
    \   itx->second = y;\n    } else {\n      itx->second += ity->second;\n      ity->second\
    \ = x;\n    }\n    return true;\n  }\n\n  int size(int k) { return -data(find(k));\
    \ }\n\n  int same(int x, int y) { return find(x) == find(y); }\n};\n\n/**\n *\
    \ @brief \u52D5\u7684Union Find\n * @docs docs/data-structure/dynamic-union-find.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic-union-find.hpp
  requiredBy: []
  timestamp: '2020-11-08 01:02:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp
documentation_of: data-structure/dynamic-union-find.hpp
layout: document
redirect_from:
- /library/data-structure/dynamic-union-find.hpp
- /library/data-structure/dynamic-union-find.hpp.html
title: "\u52D5\u7684Union Find"
---
## 動的Union Find

#### 概要

[Union Find](https://nyaannyaan.github.io/library/data-structure/union-find.hpp)の動的版。配列を使っていた部分を連想配列に変えることで空間計算量を削減している。

#### 使い方

- `UnionFind(int sz)`：サイズ$sz$のUnionFindを生成する。計算量$\mathrm{O}(1)$
- `unite(int x, int y)`：xとyをマージする。返り値はマージに成功したら`true`、失敗したら`false`を返す。計算量$\mathrm{O}(\alpha(n))$($n$はUnionFindのサイズ)
- `find(int k)`：kの根を返す。計算量$\mathrm{O}(\alpha(n))$
- `same(int x, int y)`：xとyが同じ連結成分に所属しているかを返す。計算量$\mathrm{O}(\alpha(n))$
- `size(int k)`：xを含む連結成分のサイズを返す。

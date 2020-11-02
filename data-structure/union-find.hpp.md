---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-1-a.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-2-a.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-2-a.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/union-find.md
    document_title: Union Find(Disjoint Set Union)
    links: []
  bundledCode: "#line 2 \"data-structure/union-find.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct UnionFind {\n  vector<int> data;\n  UnionFind(int\
    \ N) : data(N, -1) {}\n\n  int find(int k) { return data[k] < 0 ? k : data[k]\
    \ = find(data[k]); }\n\n  int unite(int x, int y) {\n    if ((x = find(x)) ==\
    \ (y = find(y))) return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x]\
    \ += data[y];\n    data[y] = x;\n    return true;\n  }\n\n  int size(int k) {\
    \ return -data[find(k)]; }\n\n  int same(int x, int y) { return find(x) == find(y);\
    \ }\n};\n\n/**\n * @brief Union Find(Disjoint Set Union)\n * @docs docs/data-structure/union-find.md\n\
    \ */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct UnionFind\
    \ {\n  vector<int> data;\n  UnionFind(int N) : data(N, -1) {}\n\n  int find(int\
    \ k) { return data[k] < 0 ? k : data[k] = find(data[k]); }\n\n  int unite(int\
    \ x, int y) {\n    if ((x = find(x)) == (y = find(y))) return false;\n    if (data[x]\
    \ > data[y]) swap(x, y);\n    data[x] += data[y];\n    data[y] = x;\n    return\
    \ true;\n  }\n\n  int size(int k) { return -data[find(k)]; }\n\n  int same(int\
    \ x, int y) { return find(x) == find(y); }\n};\n\n/**\n * @brief Union Find(Disjoint\
    \ Set Union)\n * @docs docs/data-structure/union-find.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2020-11-02 22:41:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-grl/aoj-grl-2-a.test.cpp
  - verify/verify-aoj-dsl/aoj-dsl-1-a.test.cpp
documentation_of: data-structure/union-find.hpp
layout: document
redirect_from:
- /library/data-structure/union-find.hpp
- /library/data-structure/union-find.hpp.html
title: Union Find(Disjoint Set Union)
---
## rollbackつきUnion-Find

#### 概要

素集合のマージ・および同じ連結成分に所属しているかを$\mathrm{O}(\alpha(n))$で高速に判定するライブラリ。($\alpha(n)$はアッカーマン関数の逆関数)

#### 使い方

- `UnionFind(int sz)`：サイズ$sz$のUnionFindを生成する。計算量$\mathrm{O}(1)$
- `unite(int x, int y)`：xとyをマージする。返り値はマージに成功したら`true`、失敗したら`false`を返す。計算量$\mathrm{O}(\alpha(n))$($n$はUnionFindのサイズ)
- `find(int k)`：kの根を返す。計算量$\mathrm{O}(\alpha(n))$
- `same(int x, int y)`：xとyが同じ連結成分に所属しているかを返す。計算量$\mathrm{O}(\alpha(n))$

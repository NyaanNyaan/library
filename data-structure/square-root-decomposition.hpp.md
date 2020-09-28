---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/sqrt-dec.md
    document_title: "\u5E73\u65B9\u5206\u5272"
    links: []
  bundledCode: "#line 2 \"data-structure/square-root-decomposition.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename MERGE, typename\
    \ block, int B>\nstruct SquareRootDecomposition {\n  int N;\n  vector<block> sq;\n\
    \  MERGE merge;\n  typename block::T UNIT;\n  SquareRootDecomposition(int N_,\
    \ MERGE merge_, typename block::T UNIT_)\n      : N(N_), sq(N / B + 1), merge(merge_),\
    \ UNIT(UNIT_) {\n    for(int i = 0; i < (int)sq.size(); i++) sq[i].init(i);\n\
    \  }\n\n  void update(int l, int r, typename block::S x) {\n    if (l / B == r\
    \ / B) {\n      sq[l / B].update_part(l % B, r % B, x);\n    } else {\n      sq[l\
    \ / B].update_part(l % B, B, x);\n      for (int i = l / B + 1; i < r / B; i++)\
    \ sq[i].update_all(x);\n      sq[r / B].update_part(0, r % B, x);\n    }\n  }\n\
    \n  typename block::T query(int l, int r) {\n    if (l / B == r / B) return sq[l\
    \ / B].query_part(l % B, r % B);\n    typename block::T ret = UNIT;\n    ret =\
    \ merge(ret, sq[l / B].query_part(l % B, B));\n    for (int i = l / B + 1; i <\
    \ r / B; i++) ret = merge(ret, sq[i].query_all());\n    ret = merge(ret, sq[r\
    \ / B].query_part(0, r % B));\n    return ret;\n  }\n};\n\n/**\n * @brief \u5E73\
    \u65B9\u5206\u5272\n * @docs docs/data-structure/sqrt-dec.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename MERGE, typename block, int B>\nstruct SquareRootDecomposition {\n\
    \  int N;\n  vector<block> sq;\n  MERGE merge;\n  typename block::T UNIT;\n  SquareRootDecomposition(int\
    \ N_, MERGE merge_, typename block::T UNIT_)\n      : N(N_), sq(N / B + 1), merge(merge_),\
    \ UNIT(UNIT_) {\n    for(int i = 0; i < (int)sq.size(); i++) sq[i].init(i);\n\
    \  }\n\n  void update(int l, int r, typename block::S x) {\n    if (l / B == r\
    \ / B) {\n      sq[l / B].update_part(l % B, r % B, x);\n    } else {\n      sq[l\
    \ / B].update_part(l % B, B, x);\n      for (int i = l / B + 1; i < r / B; i++)\
    \ sq[i].update_all(x);\n      sq[r / B].update_part(0, r % B, x);\n    }\n  }\n\
    \n  typename block::T query(int l, int r) {\n    if (l / B == r / B) return sq[l\
    \ / B].query_part(l % B, r % B);\n    typename block::T ret = UNIT;\n    ret =\
    \ merge(ret, sq[l / B].query_part(l % B, B));\n    for (int i = l / B + 1; i <\
    \ r / B; i++) ret = merge(ret, sq[i].query_all());\n    ret = merge(ret, sq[r\
    \ / B].query_part(0, r % B));\n    return ret;\n  }\n};\n\n/**\n * @brief \u5E73\
    \u65B9\u5206\u5272\n * @docs docs/data-structure/sqrt-dec.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/square-root-decomposition.hpp
  requiredBy: []
  timestamp: '2020-09-03 23:56:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp
documentation_of: data-structure/square-root-decomposition.hpp
layout: document
redirect_from:
- /library/data-structure/square-root-decomposition.hpp
- /library/data-structure/square-root-decomposition.hpp.html
title: "\u5E73\u65B9\u5206\u5272"
---
## 平方分割

要素数$N$の列を$\mathrm{O}(\sqrt{N})$個のバケットに分割して管理することで列上のクエリを高速に答えるアルゴリズムを平方分割と呼ぶ。

セグメント木にない特長として、バケット上に重たいデータ構造を乗せることが出来るという点がある。例えば次の二つのクエリに答える問題を考える。

- `add(l,r,x)` : $[a_l,a_r)$に$x$を足す
- `count[l,r,x)` : $[a_l,a_r)$内にある$x$の個数を数える
- $1 \leq l < r \leq N=10^5,$クエリ数$Q=10^5,a_i \leq 10^9, x \leq 10^9$

この問題にセグメント木を適用するとノード上に大量のhashmapを乗せることになり計算量が悪化するが、平方分割ならばhashmapの空間計算量が$\mathrm{O}(N)$で抑えられるため$\mathrm{O}((N+Q)\sqrt{N})$で解くことが出来る。(range addは適切に遅延評価すればよい。)

#### 使い方

次のようなblockを作成して本体に乗せると上手く動く。

```cpp=
struct block {
  // S 作用素の型 T 要素の型
  using S = ;
  using T = ;

  int i;

  block() {}

  // i ... 何個目のブロックか
  // i * B + j ... (jをブロック内のidxとして)全体でのidx
  int idx(int j) const { return i * B + j; }
  
  // 変数とブロックの初期化を忘れない！
  void init(int _) { 
    i = _; 
  }

  void build() {

  }

  void update_all(S x) {

  }

  void update_part(int l, int r, S x) { 
    
    build(); 
  }

  T query_all() {

  }

  T query_part(int l, int r) {

  }
};
```
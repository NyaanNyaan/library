## 動的Union Find

#### 概要

[Union Find](https://nyaannyaan.github.io/library/data-structure/union-find.hpp)の動的版。配列を使っていた部分を連想配列に変えることで空間計算量を削減している。

#### 使い方

- `UnionFind(int sz)`：サイズ$sz$のUnionFindを生成する。計算量$\mathrm{O}(1)$
- `unite(int x, int y)`：xとyをマージする。返り値はマージに成功したら`true`、失敗したら`false`を返す。計算量$\mathrm{O}(\alpha(n))$($n$はUnionFindのサイズ)
- `find(int k)`：kの根を返す。計算量$\mathrm{O}(\alpha(n))$
- `same(int x, int y)`：xとyが同じ連結成分に所属しているかを返す。計算量$\mathrm{O}(\alpha(n))$
- `size(int k)`：xを含む連結成分のサイズを返す。

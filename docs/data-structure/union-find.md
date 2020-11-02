## Union-Find Tree(Disjoint Set Union)

#### 概要

Union-Find Treeとは、素集合データ構造に対して

- 頂点$x,y$が属している二つの集合をマージする
- 頂点$x,y$が同じ集合に属しているかを判定する

という二つの操作をともに$\mathrm{O}(\alpha(n))$で高速に実行するライブラリである。($\alpha(n)$はアッカーマン関数$A(n, n)$の逆関数)

#### 使い方

- `UnionFind(int sz)`：サイズ$sz$のUnionFindを生成する。計算量$\mathrm{O}(1)$
- `unite(int x, int y)`：xとyをマージする。返り値はマージに成功したら`true`、失敗したら`false`を返す。計算量$\mathrm{O}(\alpha(n))$($n$はUnionFindのサイズ)
- `find(int k)`：kの根を返す。計算量$\mathrm{O}(\alpha(n))$
- `same(int x, int y)`：xとyが同じ連結成分に所属しているかを返す。計算量$\mathrm{O}(\alpha(n))$

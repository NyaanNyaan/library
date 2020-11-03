## 動的Binary Indexed Tree

#### 概要

[Binary Indexed Tree](https://nyaannyaan.github.io/library/data-structure/binary-indexed-tree.hpp)を動的にしたライブラリ。

Binary Indexed Tree(BIT)は区間和と一点加算が配列長を$n$として時間計算量$\mathrm{O}(\log n)$で出来るが、空間計算量が$\mathrm{O}(n)$になるため$n$がメモリサイズより大きいときに使用できない。そこで、配列の代わりに連想配列を利用することで空間計算量を(クエリ数を$q$として)$\mathrm{O}(q \log n)$で抑えたものが動的Binary Indexed Treeである。

#### 使い方

- `DynamicBinaryIndexedTree<T>(int n)`: $[0, n]$を添え字の値として取れるBITを作成する。
- `add(k, x)`: k番目の要素にxを加算する。
- `operator[](k)`: k番目の要素を取得する。
- `sum(k)`: 区間`[0, k)`の和を取得する。
- `sum(l, r)`: 区間`[l, r)`の和を取得する。
- `operator[](k)`: `k`番目の要素の値を取得する。
- `lower_bound(w)`: 要素が全て非負の時、`[0, k]`の区間和がw以上となるような最小のkを求める。

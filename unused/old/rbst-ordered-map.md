## OrderedMap(順序付き連想配列)

順序付き連想配列をRandomized Binary Search Tree(merge-splitベース)を内部実装として実装したもの。計算量は言及がない限り$\mathrm{O}(\log N)$。

#### 使い方

内部ではノードへのポインタを`NodePtr`型で管理しており、一部の関数は`NodePtr`型が返り値となる。`NodePtr p`に対して`*p`で`pair(const key&, val&)`を取得することが出来る。(インクリメント等は実装しておらず参照にしか使えない。)また、`NodePtr::nil()`は`nullptr`と同様の意味を持っており、`bool(NodePtr) = false`を返す設計となっている。

- 初期化
  - `OrderedMap<Key, Val>()`:　初期化する。`Key`はキーの型、`Val`は値の型。
  - `build(const vector<Val>& v)`:　`(i, v[i])`を初期値として構築する。計算量$\mathrm{O}(N)$
  - `set_monoid(const F &f, const Val &I)`: `I`を単位元とする`f` : `Val` $\times$`Val`$\rightarrow$`Val`を載せる。
- 挿入・削除
  - `insert(const Key& x, const Val& y)`: キーが`x`であるノードの値に`y`を代入する。
  - `apply(const Key &x, const Val &y)`: キーが`k`であるノードの値を`f(*this[k], y)`に更新する。
  - `erase(const Key &x)`:　キーが`k`であるノードを削除する。
- 参照・検索
  - `[](const Key& k)`:　キーが`k`であるノードの値への参照を返す(代入も可能)。存在しない場合は新たに初期化したノードを追加して参照する。
  - `get(const Key& k) const`: キーが`k`であるノードのポインタを返す。存在しない場合は`nil`を返す。
  - `first_ptr() const`: キーが最も小さいノードのポインタを返す。存在しない場合は`nil`を返す。
  - `last_ptr() const`: キーが最も小さいノードのポインタを返す。存在しない場合は`nil`を返す。
- それ以外の機能
  - `enumerate() const`: 要素を昇順に列挙した`vector`を返す。計算量$\mathrm{O}(N)$
  - `lower_bound(const Key &x)`:　キーが`x`より小さいノードの個数を数える。
  - `lower_bound(const Key &x)`:　キーが`x`より大きいノードの個数を数える。
  - `kth_element(int n)`:　キーが`n`番目(0-indexed)に小さいノードのポインタを返す。存在しない場合は`nil`を返す。
  - `fold(const Key &l, const Key &r)`:　`[l, r)`番目のノードにモノイド`f`を作用させた時の値の和を返す。
  - `size() const`:　要素数を返す。計算量$\mathrm{O}(1)$

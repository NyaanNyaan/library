## OrderedMap(順序付き集合)

順序付き連想配列をRandomized Binary Search Tree(merge-splitベース)を内部実装として実装したもの。計算量は言及がない限り$\mathrm{O}(\log N)$。

#### 使い方

- `OrderedSet(class T, int S = 2000000)`: 型`T`、`OrderedSet`のオブジェクト全体での`insert`を呼ぶ回数が最大S回であるような`OrderedSet`を生成する。$\mathrm{O}(1)$
- `insert(x)`: xを追加する。
- `delete(x)`: xを削除する。
- `lower_bound(x)`: x未満の要素の個数を返す。
- `upper_bound(x)`: x以上の要素の個数を返す。
- `count(x)`: xの個数を返す。
- `kth_element(int k)`: k番目の要素を返す。
- `size()`: sizeを返す。$\mathrm{O}(1)$

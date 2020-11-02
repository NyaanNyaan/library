## rollbackつきUnion-Find

#### 概要

Union-FindにUndo機能やrollback機能をつけたライブラリ。

UnionFindの内部実装をQuickFindと呼ばれる経路圧縮を行わない実装にすることで、マージ1回ごとに値が変更される箇所が高々2か所になる。よってマージするごとにマージ前の配列の値を保存すれば、Undoはunite前の値を復元することで$\mathrm{O}(1)$で実行することが出来る。同様にしてrollbackも高速に処理できる。

#### 使い方

- `RollbackUnionFind(int sz)`：サイズ$sz$のUnionFindを生成する。計算量$\mathrm{O}(1)$
- `unite(int x, int y)`：xとyをマージする。返り値はマージに成功したら`true`、失敗したら`false`を返す。計算量$\mathrm{O}(\log n)$($n$はUnionFindのサイズ)
- `find(int k)`：kの根を返す。計算量$\mathrm{O}(\log n)$
- `same(int x, int y)`：xとyが同じ連結成分に所属しているかを返す。計算量$\mathrm{O}(\log n)$
- `undo()`：直前のuniteの操作を取り消す。計算量$\mathrm{O}(1)$
- `snapshot()`：現在のUnionFindの状態を保存する。(保存した状態はrollback()で再現できる。)計算量$\mathrm{O}(1)$
- `get_state()`：現在の`unite`が呼ばれた回数を返す。
- `rollback(int state = -1)`：UnionFindをロールバックする。計算量は状況による。(ボトルネックにはならない)
  - `state = -1`のとき：`snapshot()`で保存した状態にロールバックする。
  - そうでないとき：`unite`が`state`回呼び出された時の状態にロールバックする。
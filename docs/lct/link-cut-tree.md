## Link/Cut Tree

木の回転・辺の削除・辺の追加などを$\mathrm{O}(\log n)$で行うライブラリ。

### 概要

忘れないうちに簡潔にまとめる。

#### 情報の持ち方

参考：[うしさんの非常に分かりやすい資料](https://ei1333.hateblo.jp/entry/2018/05/29/011140)

- (反転可能Splay Treeの実装は前提知識とする)

- Link Cut Treeの内部では木を根付き木として管理している

- 重軽分解のようにPreferred EdgeとNormal Edgeの二つに塗り分けられていて、一つの頂点から子に生えるPreferred Edgeは高々1つ

- Preferred Edgeからなるパス、Preferred Pathの内部の点は深さを比較関数としたSplay Treeに載せられている

  - Preferred Pathは内部の実装では双方向にリンクしている。つまり、uの左の頂点がvの場合`u->l == v && v->p == u`が成り立つ

- Preferred Pathの最も根に近い頂点を`v`と置くと、`v`が木全体の根でないとき`v`の親`u`へのパス(Normal Path)が存在する。このパスは、**`v`の所属する平衡二分木の根**から`u`に向けて(根の方向に)生えているとみなす
  - Normal Pathは片方向にリンクしている。つまり、`(vの所属するSplay Treeの根)->p == u`であるが`u`は`v`に関する情報を持たない

#### `expose`

- 以上に説明した方法で木を管理したとき、内部でのポインタ操作によってPreferred EdgeとNormal Edgeを入れ替えることが出来る

  - `splay(u), u->r = nullptr`　$\leftrightarrow$ `u`から子に生えるPreferred EdgeをNormal Edgeに替える
  - `v`から`u`にNormal Edgeが生えているとき、`splay(u), u->r = v` $\leftrightarrow$ `u`から子に生えるPreferred EdgeをNormal Edgeに替える

- 上の二つを組み合わせると、Link Cut Treeの核である`expose(x)`：根から`x`までのパスをPreferred Edgeからなるパスにする関数を実装できる

```
Ptr expose(Ptr t) {
  Ptr rp = nullptr;
  for(Ptr cur = t; cur; ) {
    splay(cur); 
    // Preferred Edgeをxの所属する辺につなぎかえる
    cur->r = rp; 
    // curの子に関する情報を更新する
    update(cur);
    // 次の親に渡すポインタをメモする
    rp = cur; 
    // 次のPreferred Edgeに移動
    cur = cur->p;
  }
  splay(t);
  return rp;
}
```

#### その他の関数

- `expose`を利用すれば`link/cut`をはじめとした様々な関数を実装できる

- `evert(u)`: 頂点`u`を木全体の根とする
  - `expose(u)`した後に`toggle(u)`するだけ
    - Preferred Edgeの最も根から遠い頂点に対して`splay(u), toggle(u)`をするとsplay Treeの順序関係が反転するため`u`がPreferred Edgeの根側になる

- `link(u, v)`: 頂点`u`と頂点`v`をつなぐ(`u, v`は連結成分でないことを仮定)
  - `u`の親を`v`にすることを考える
  - `evert(u)`することで`u`を木全体の根とする
    - `expose(u)`でも内部的には`u->p = nullptr`になるが、実際の木は`u`の親が存在するため破綻する
  - `expose(v)`する
  - `u->p = v`として`u`と`v`をNormal Edgeでつなぐ
    - `evert(u)`または`expose(u)`した頂点は親が`nullptr`になっていることを利用
  - 疑問点: linkするだけなら`expose(v)`いらなくない？`evert(u), u->p = v`でいい気がする
    - [Gifted Infantの実装](http://yosupo06.github.io/Algorithm/src/datastructure/linkcuttree.hpp)は`evert(u), expose(v)`している
    - [kimiyukiさんの提出](https://judge.yosupo.jp/submission/4151)だと`expose(v)`の行に`// for the time complexity`と書いてある
    - [Library Checkerのfastest](https://judge.yosupo.jp/submission/31941)だと`expose(v)`していない
    - 以上をまとめると「あっても無くても良さそう？計算量解析に踏み入らないと理由はわからなそう？」という結論に
    - パス加算クエリや部分木クエリに対応するときは`expose(v)`は必要そう(根方向からの伝播を反映させる必要があるため)

- `cut(u, v)`：頂点`u`,`v`を切り離す
  - `evert(u), expose(v)`する
  - この時`v->l == u`になっている
  - `v->l = u->p = nullptr`とすれば辺が切れる

- 実装の際は評価更新用の関数`update()`と評価伝播用の関数`push()`を適切に入れる必要がある
  - 子の辺を張り変える**前**は`push()`で伝播させる
  - 子の辺を張り変えた**後**は`update()`で新しい子の情報を更新する

#### 使い方

- `expose(u)`：根から`u`までのパスをPreferred Edgeからなるパスにする
- `evert(u)`: 頂点`u`を木全体の根とする
- `link(u, v)`: 頂点`u`と頂点`v`をつなぐ(`u, v`は連結成分でないことを仮定)
- `cut(u, v)`：頂点`u`,`v`を切り離す
- `get_root(u)`：`u`の所属する木の根を返す
- `set_key(u, key)`：頂点`u`の`key`を書き換える
- `get_key(u, key)`：頂点`u`の`key`の値を得る
- `fold(u, v)` : `u, v`間のパスの`key`の和を得る

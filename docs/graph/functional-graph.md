## Functional Graph(なもりグラフ)

頂点数$n$のなもりグラフを$\mathrm{O}(n\alpha (n))$で分解するライブラリ。

#### 使い方

##### メンバ関数

- `Namori<T>(int n)`: $n$頂点のなもりグラフのコンストラクタ。(`T`は辺の重みの型)
- `add_edge(int u, int v, T w)`: 重み`w`の`(u, v)`パスを追加する。
- `idx(int i)`: 頂点$i$の新しいインデックス$(r,x)$を返す。($r$番目の部分木の$x$番目の頂点を意味する)
- `root(int i)`: $i$番目の頂点の根$j$(古いインデックス)を返す。

##### メンバ変数

- `vector<pair<int, T>> loop`: なもりグラフのループ部分のグラフ。
  - `loop[i].second` は `loop[i]` と `loop[i+1]` の間の辺の重みを意味する。
- `vector<WeightedGraph<T>> aux`: ループ部分に付随する部分木のグラフ。
  - `aux[i]` は `loop[i]` を根とするグラフ。
- `vector<HeavyLightDecomposition<G>> hld`: `aux`をHL分解したもの。
  - `hld[i].idx(i).first`と`Namori::idx(i).first`が一致するようにしている(はず)
  - TODO: ここ自信がないのでverifyを書く

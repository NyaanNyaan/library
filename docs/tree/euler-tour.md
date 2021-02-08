## Euler Tour

無向森が与えられたときにそれぞれの木に対してEuler Tourを構築するライブラリ。

#### 概要

TODO: アルゴリズムの説明を書く

TODO: 森が与えられた時と辺クエリのverifyを書いていないので、書く

備忘録

- <span style="font-size: 200%; color: red;">アーベル環を載せたパスクエリは$[\mathrm{down}(i)+1,\mathrm{down}(j)+1)$に$\mathrm{lca}(i,j)$を加えたもの！</span>

- LCAを求めるときとパスクエリで記録する値が違う
  - LCAの時は原義のオイラーツアー(たぶん)
  - パスクエリは入る時と出る時を記録
- 逆元つきモノイドはEuler Tourでクエリ$\mathrm{O}(\log N)$
- 逆元なしモノイドはHL Decでクエリ$\mathrm{O}(\log^2 N)$

#### 使い方

- `EulerTour(g, root)`: グラフ`g`に対して`root`を最初の根とするオイラーツアーを構築する。
- `lca(u, v)`:$\mathrm{lca}(u,v)$を返す。
- `idx(i)` : `make_pair(down[i], up[i])`を返す。ここで`down[i]`は頂点iに入った時のid、`up[i]`は頂点iから出た時のidである。
- `path_query(u, v, f)`: 頂点クエリ用の関数。
- `edge_query(u, v, f)`: 辺クエリ用の関数。
- `subtree_query(u, v, f)`: 部分木クエリ用の関数。

## 木に対する一般的なクエリ

#### 概要

木を触る時によく使うクエリを詰め込んだデータ構造。ダブリングをベースに実装している。


#### 余談

`nxt(s, t)`を$\langle$前計算$\mathrm{O}(N)$,クエリ$\mathrm{O}(1)$$\rangle$で出来るか考えたけど良くわからなかった。$\langle\mathrm{O}(N),\mathrm{O}(1)\rangle$RMQとかで出来るんだろうか…

ちなみにsparse tableを使えば$\langle\mathrm{O}(N\log N),\mathrm{O}(1)\rangle$は達成可能だと思う。自分の実装は$\langle\mathrm{O}(N\log N),\mathrm{O}(\log N)\rangle$だが空間の定数倍がsparse tableより2倍くらいよい(多分)のでMLEに強いはず…

#### 使い方

- `Tree(g, root = 0)`: rootを根としてデータ構造を構築する。(以下のクエリでgはrootを根とした根付き木とみなされる。)　$\mathrm{O}(N \log N)$
- `depth(u)`: uの深さを返す。$\mathrm{O}(1)$
- `par(u)`: uの親ノードを返す。(存在しない場合-1を返す。)　$\mathrm{O}(1)$
- `kth_ancestor(u, k)`: $\mathrm{par}^k(u)$を返す。(存在しない場合-1を返す。)　$\mathrm{O}(\log N)$
- `nxt(s, t)`: s-t間のパス上の点のうちsに隣接する点を返す。 $\mathrm{O}(\log N)$
- `lca(u, v)`: uとvのlcaを返す。$\mathrm{O}(\log N)$
- `path(s, t)`: s-t間のパス$p$をパスに所属する頂点の列で返す。$\mathrm{O}(\lvert p\rvert)$

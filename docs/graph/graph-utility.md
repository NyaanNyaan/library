## グラフユーティリティ

### 概要

与えられたグラフgに関して計算を行う。グラフの頂点数を$N$とする。

グラフのデータ型はグラフテンプレート(graph-template.hpp)で定義されている。

### 使い方

- `vector<int> Depth(const UnweightedGraph &g, int start = 0)`:

  返り値の$i$番の要素は、頂点$\mathrm{start}$から頂点$i$までの最短パスの長さ。最短パスがない場合は$-1$とする。計算量$\mathrm{O}(N)$

- `vector<T> Depth<T>(WeightedGraph<T> g, int start = 0)`:

  グラフ$g$は根付き木でなくてはならない。
  
  返り値の$i$番の要素は、頂点startから頂点$i$までの最短パスの長さ。パスがない場合は$-1$を返す。計算量$\mathrm{O}(N)$

- `pair<pair<int, int>, int> Diameter(const UnweightedGraph &g)` , `pair<pair<int, int>, T> Diameter<T>(const WeightedGraph<T> &g)`

  グラフ$g$は木でなくてはならない。

  木の直径の長さを$d$、両端の頂点を$u,v$として$((u,v),d)$を返す。計算量$\mathrm{O}(N)$

- `vector<int> Path<G>(G &g, int u, int v)`:

  型`G`は`UnweightedGraph`または`WeightedGraph<T>`で、グラフは木でなくてはならない。
  
  頂点$u$から$v$に至るパスが通る頂点($u$,$v$を含む)の列を返す。計算量$\mathrm{O}(N)$

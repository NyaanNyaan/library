## Range Chmin Chmax Add Update Range Min Max Sum Segment Tree Beats

Range (Chmin Chmax Add Update)クエリとRange (Min Max Sum)クエリに対応したSegment Tree Beatsのライブラリ。

#### 使い方

- `range_chmin(l, r, x)`: for each $i \in [l, r)$, $a_i \leftarrow \min(a_i,x)$
- `range_chmax(l, r, x)`: for each $i \in [l, r)$, $a_i \leftarrow \max(a_i,x)$
- `range_add(l, r, x)`: for each $i \in [l, r)$, $a_i \leftarrow a_i + x$
- `range_update(l, r, x)`: for each $i \in [l, r)$, $a_i \leftarrow x$
- `range_min(l, r)`: return $\min(a_l,\ldots,a_{r-1})$
- `range_max(l, r)`: return $\max(a_l,\ldots,a_{r-1})$
- `range_sum(l, r)`: return $\sum_{i=l}^{r-1}a_i$

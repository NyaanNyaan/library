## 使用頻度の高い遅延セグメント木

使用頻度の高い遅延セグメント木を特殊化してライブラリ化したもの。

#### 使い方

以下の6種類の遅延セグメント木を特殊化している。いずれも`クラス名(初期値の入ったvector)`で初期化、`update(l, r, x)`で`[l, r)`に`x`を作用、`query(l, r)`で`[l, r)`の積を取得できる。

- `AddMax_LazySegmentTree` : Range Add Query & Range Max Query
- `AddMin_LazySegmentTree` : Range Min Query & Range Min Query
- `AddSum_LazySegmentTree` : Range Sum Query & Range Sum Query
- `UpdateMax_LazySegmentTree` : Range Update Query & Range Max Query
- `UpdateMin_LazySegmentTree` : Range Update Query & Range Min Query
- `UpdateSum_LazySegmentTree` : Range Update Query & Range Sum Query

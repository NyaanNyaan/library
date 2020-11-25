## ダイクストラ法(Radix Heap)

ダイクストラ法の定数倍高速化ライブラリ。

#### 概要

ダイクストラ法のヒープに[Radix Heap(基数ヒープ)](https://nyaannyaan.github.io/library/data-structure/radix-heap.hpp)を使用することで最小値の取得にかかる時間計算量を高速化したライブラリ。

#### 使い方

- `dijkstra(g, start = 0)`: sを始点としたダイクストラ法を行い、計算結果を返す。

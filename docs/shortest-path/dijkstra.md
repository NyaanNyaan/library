## ダイクストラ法

ダイクストラ法を$\mathrm{O}(E \log V)$で行うライブラリ。

#### 概要

ダイクストラ法とは負辺の無い有向グラフでの単一始点最短経路を$\mathrm{O}(E \log V)$で計算するアルゴリズムである。[基数ヒープ](https://nyaannyaan.github.io/library/shortest-path/dijkstra-radix-heap.hpp)やフィボナッチヒープを用いた高速化も知られている。

#### 使い方

- `dijkstra(g, start = 0)`: sを始点としたダイクストラ法を行い、sからの距離(到達できない場合`-1`)が格納された配列を返す。

## 定数倍高速化ダイクストラ法

ダイクストラ法の定数倍高速化ライブラリ。

#### 概要

ダイクストラ法を空間・時間ともに定数倍高速化したライブラリ。具体的には、隣接リストを配列3本で表現することで空間計算量を2倍改善して、ヒープに[Radix Heap(基数ヒープ)](https://nyaannyaan.github.io/library/data-structure/radix-heap.hpp)を使用することで最小値の取得にかかる時間計算量も2倍改善している。

[ナイーブな実装](https://nyaannyaan.github.io/library/shortest-path/dijkstra.hpp)と雑なランダムケースで比較したところ、全体としておよそ3倍程度の高速化がなされるようだ。

#### 使い方

- `DijkstraGraph<T, N, M>` :辺の重みがTで、頂点数の最大が`N`、辺数の最大が`M`であるグラフを生成する。
- `add_edge(u, v, c)`: uからvへ向かう重みcの有向辺を追加する。
- `dijkstra(s)`: sを始点としたダイクストラ法を行い、計算結果を返す。


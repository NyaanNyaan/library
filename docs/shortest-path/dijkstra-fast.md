## 定数倍高速化ダイクストラ法

ダイクストラ法の定数倍高速化ライブラリ。

#### 概要

ダイクストラ法を空間・時間ともに定数倍高速化したライブラリ。

[ナイーブな実装](https://nyaannyaan.github.io/library/shortest-path/dijkstra.hpp)と雑なランダムケースで比較したところ、全体としておよそ2倍程度の高速化がなされるようだ。

#### 使い方

- `dijkstra(g, s)`: sを始点としたダイクストラ法を行い、計算結果を返す。
- `dijkstra_restore(g, s)`: sを始点としたダイクストラ法(復元付き)を行い、計算結果を返す。
  - いずれの場合もgは[`StaticGraph`](https://nyaannyaan.github.io/library/graph/static-graph.hpp)である必要がある。

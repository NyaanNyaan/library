## 頂点間の距離の度数分布

頂点間の距離の度数分布を$\mathrm{O}(n \log^2 n)$で計算するライブラリ。

#### 使い方

- `FrequencyTableOfTreeDistance(const G &g)`: 重心分解用のデータ構造を構築する。
- `get(start = 0)`: startを根として計算した結果を返す。

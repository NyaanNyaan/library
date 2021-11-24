## 最大長方形

### 概要

短く言うと、ヒストグラム中の長方形の最大面積を求める。

非負整数列$A$を入力とする。非負整数$l,r,h$ $(l \leq r \lt N)$が$h \leq A_i$ $(l \leq i \leq r)$ を満たすとき、$h(r-l+1)$の最大値を求める。

### 使い方

- `MaximalRectangle(buf)`: `buf`で非負整数列$A$を与える。求める最大値を返す。計算量$\mathrm{O}(\vert A \vert)$

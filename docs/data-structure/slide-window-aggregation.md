## Slide Window Aggrigation

#### 概要

Slide Window Aggrigation は、モノイド$(S,\bullet,I)$の$S$の要素の列$A$に対して、以下の操作を高速に実行できる構造である。
- 末尾への要素の挿入
- 先頭の要素の削除
- $A$全体の集約値$A_0 \bullet A_1 \bullet A_2 \bullet \cdots \bullet A_{\vert A \vert -1}$の取得

構造は、挿入用と削除用の$2$つのスタックを持ち、削除用のスタックの中身が尽きたときに挿入用からすべての要素を移し替える。

#### 使い方

- テンプレート引数 `typename T`: $S$の要素の型。
- テンプレート引数 `typename F`: 演算$\bullet$を定義するオブジェクトの型。オブジェクトは`T f(const T& a,const T& b);`の形の関数として呼び出せて、$a \bullet b$の値を返す。
- `SlideWindowAggregation<F, T>(f_, I_)`: `f_`を演算、`I_`を単位元として設定し、$A$を空の列で初期化する。
- `push(x)`: 要素`x`を$A$の末尾に挿入する。計算量均し$\mathrm{O}(1)$。
- `pop()`: $A$から先頭の要素を削除する。計算量均し$\mathrm{O}(1)$。
- `query()`: 集約値$A_0 \bullet A_1 \bullet A_2 \bullet \cdots \bullet A_ {\vert A \vert -1}$を返す。計算量$\mathrm{O}(1)$。

#### 注意点

- $A$が空のときに`pop`を呼んではならない。
- 上記の計算量では`f_`の計算量を$\mathrm{O}(1)$と仮定している。

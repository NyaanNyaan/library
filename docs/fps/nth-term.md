## 線形回帰数列の高速計算(Berlekamp-Massey/Bostan-Mori)

線形回帰数列の前$k$項が与えられたときに第$n$項を$\mathrm{O}(k^2+k \log k\log n)$で計算するライブラリ。

#### 概要

斉次線形漸化式

$$a_i=\sum_{j=1}^k c_j a_{i-j} (i\geq k)$$

の形で表される数列を線形回帰数列と呼ぶ。ここで$(a_i)$の母関数を考えると、$(a_i)$は適当な$P(x)$および$c_1,c_2\ldots,c_k$を用いて

$$\sum_{i=0}^\infty a_i x^i = \frac{P(x)}{1-c_1x-c_2x^2-\ldots -c_kx^k}$$

と表せる。ここで$P(x)$および$c_1,c_2\ldots,c_k$は[Berlekamp-Massey algorithm](https://nyaannyaan.github.io/library/fps/berlekamp-massey.hpp)で計算できて、さらに線形漸化式の第$n$項は[Bostan-Mori algorithm](https://nyaannyaan.github.io/library/fps/kitamasa.hpp)で高速に計算できる。

#### 使い方

- `nth-term(N, a)`: 数列$(a_i)$の第$N$項を計算する。
 
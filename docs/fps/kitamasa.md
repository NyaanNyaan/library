## 線形漸化式の第$N$項を高速に求めるライブラリ

$[x^N]\frac{P(x)}{Q(x)}$($\mathrm{deg}(Q) = k$)を$\mathrm{O}(N \log k \log N)$で計算するライブラリ。

#### 概要

$k$項間漸化式

$$a_n = c_1a_{n-1}+c_2a_{n-2} \ldots + c_ka_{n-k}$$

の第$N$項は

$$Q(x)=1-c_1x-c_2x^2-\ldots -c_kx^k$$

$$P(x)=Q(x)(a_0+a_1x+a_2x^2+\ldots) \mod x^k$$

と置いたとき

$$a_N = [x^N]\frac{P(x)}{Q(x)}$$

になり、これはBostan-Mori Algorithmを使って$\mathrm{O}(N \log k \log N)$で計算できる。[日本語での解説](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)

さらに、もし素数$p$がNTT素数だった場合は1回のループ当たりの操作が長さQの畳み込み4回で済むので、愚直なアルゴリズム(ループ当たり計算量$2M(n)$)に対して3倍(計算量$2/3M(n)$)の高速化が見込める。(詳細は実装を参考のこと。)

verify(AtCoder 双子コン#3 G フィボナッチ数の総和) $\mathrm{O}(N \log k \log N), N=200000,k=10^{18}$
- [ナイーブな実装](https://atcoder.jp/contests/s8pc-3/submissions/15526069) 1846ms
- [高速化した場合](https://atcoder.jp/contests/s8pc-3/submissions/15520531) 631ms

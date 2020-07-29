# 線形漸化式の第$N$項を高速に求めるライブラリ

$k$項間漸化式
$$a_n = c_1a_{n-1}+c_2a_{n-2} \ldots + c_ka_{n-k}$$
の第$N$項は
$$Q(x)=1-c_1x-c_2x^2-\ldots -c_kx^k$$
$$P(x)=Q(x)(a_0+a_1x+a_2x^2+\ldots) \mod x^k$$
と置いたとき
$$a_N = [x^N]\frac{P(x)}{Q(x)}$$
になり、これは[リンク先のアルゴリズム](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)を使って$\mathrm{O}(N \log k \log N)$で計算できる。
さらに、もし素数$p$がNTT素数だった場合、1回のループ当たりの操作が長さ|Q|の畳み込み4回で済むので愚直なアルゴリズム(ループ当たり計算量$2M(N)$)に対して3倍速くなり(計算量$2/3M(N)$)、十分高速化できる。

[verify(AtCoder 双子コン第3回 G フィボナッチ数の総和)](https://atcoder.jp/contests/s8pc-3/submissions/15520531)
$\mathrm{O}(N \log k \log N), N=200000,k=10^{18}$で631ms
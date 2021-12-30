## 線形漸化式の高速計算

分子分母が高々 $k$ 次の多項式で表される分数 $\frac{P(x)}{Q(x)}$ が与えられたときに、$[x^N]\frac{P(x)}{Q(x)}$ を $\mathrm{O}(k \log k \log N)$ で計算するライブラリ。

#### 概要

$k$ 項間漸化式

$$a_n = c_1a_{n-1}+c_2a_{n-2} \ldots + c_ka_{n-k}$$

の第 $N$ 項は

$$Q(x)=1-c_1x-c_2x^2-\ldots -c_kx^k$$

$$P(x)=Q(x)(a_0+a_1x+a_2x^2+\ldots) \mod x^k$$

と置いたとき

$$a_N = [x^N]\frac{P(x)}{Q(x)}$$

になり、これはBostan-Mori Algorithmを使って$\mathrm{O}(k \log k \log N)$で計算できる。

- [論文](https://arxiv.org/abs/2008.08822) [日本語での解説](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html) [解説2](https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a)

(線形漸化式の高速計算アルゴリズムは「高速きたまさ法」と通称されるアルゴリズムが競プロ界では非常に有名で、計算量も$\mathrm{O}(k \log k \log N)$と等速だが、Bostan-Mori Algorithmの方が一般のケースに対して定数倍がよい。)

さらに、もし素数 $p$ がいわゆる NTT 素数だった場合は FFT のダブリングを利用することで $1$ 回のループ当たりの操作が長さ $k$ の畳み込み4回で済むので、愚直なアルゴリズム(ループ当たり計算量 $2M(k)$)に対して $3$倍 (計算量 $\frac{2}{3}M(k)$ ) の高速化が見込める。(詳細は実装を参考のこと。)

#### 使い方

- `LinearRecurrence(k, Q, P)` : $\lbrack x^k \rbrack \frac{P(x)}{Q(x)}$ を求める。
- `LinearRecurrence(N, Q, a)` : $$\forall n \leq k, Q_0 a_{n} + Q_1 a_{n-1} + \dots + Q_{k} a_{n-k} = 0, Q_0 = 1$$ である $a, Q$ に対して $a_N$ を求める。

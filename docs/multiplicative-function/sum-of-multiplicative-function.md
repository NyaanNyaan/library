
## 乗法的関数の和

乗法的関数 $f(p)$ のprefix sum 

$$S(N) = \sum_{i=1}^N f(i)$$

を $\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$ で求めるアルゴリズムを実装したライブラリ。
(ただし、素数 $p$ について $f(p)=g(p)$ を満たす多項式 $g(p)$ が存在するとする。)

#### アルゴリズムの概要

前計算として 

$$S_p(n) = \sum_{p \leq n | p : \mathrm{prime}} f(i)$$

を $n = k, \left\lfloor \frac{N}{k} \right\rfloor$ $(1\leq k\leq N)$ に対して列挙するアルゴリズムを以下に説明する。

$p$ が素数の時 $f(p)$ は多項式なので、 $p$ の次数ごとに分解すると $f(N)$ は

$$S_c(N) = \sum_{p\leq N | p : \mathrm{prime}} p^c$$

の線形和で表すことが出来る。 $S_c(\lfloor \frac{N}{k} \rfloor)$ は[素数カウント](https://nyaannyaan.github.io/library/library/multiplicative-function/prime-counting.hpp.html)のアルゴリズム (いわゆる Lucy DP) を一般的に拡張した方法で高速に求められる。(素数カウントの時に求めた $\pi(n)$ は $c=0$ の時の場合であると言える。)

- $f(x,n) :=$ ( $n$ 以下の自然数のうち $x$ 以下の素数を因数に持たない整数 $p$ に対する $p^c$ の和)

とおくと $x$ が素数の時に

$$f(x,n) = f(x - 1, n) - f(x-1,\left\lfloor\frac{n}{x}\right\rfloor)x^c$$

が成り立つ。ここで $n < x$ のとき $f(x,n) = f(x-1,n)$ 、$x \leq n < x^2$ のとき$ f(x,n) = f(x-1,n) - x^c$ となることを利用して $g(x,n) = f(x, n) + S_c(\min(x,n))$ とおくと、 $x$ が素数の時に

$$g(x,n) = \begin{cases} g(x-1,n) & \mathrm{if}\ n < x^2 \\ g(x-1,n) - \lbrace g(x-1,\lfloor\frac{n}{x}\rfloor) - S_c(x-1) - 1 \rbrace x^c& \mathrm{otherwise} \end{cases}$$

となる。 

$$S_c(\lfloor\sqrt{N}\rfloor,N)=g(\lfloor\sqrt{N}\rfloor,N)-1$$ 

であるから $h(x,n)=g(x,n)-1$ と補正すると

$$
\begin{aligned}
S_c(N) &= h(\lfloor\sqrt{N}\rfloor,N)\\
h(0,n) &= -1 + \sum_{0 \leq m \leq n}m^c
\end{aligned}\\
h(x,n) = \begin{cases} h(x-1,n) & \mathrm{if}\ x\ \mathrm{is}\ \mathrm{not}\  \mathrm{prime}\ \cup\ n < x^2 \\ h(x-1,n) - \lbrace h(x-1,\lfloor\frac{n}{x}\rfloor) - S_c(x-1) \rbrace x^c& \mathrm{otherwise} \end{cases}
$$

を得る。(なお、 $S_c(x-1)=h(x-1,x-1)$ である。)以上より、素数カウントと同様のアルゴリズムで DP を行うことで $\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$ で前計算ができる。

以上に説明したアルゴリズムによって $S_p(\left\lfloor \frac{N}{k} \right\rfloor)$ を列挙することが出来た。$S_p(\left\lfloor\frac{N}{k}\right\rfloor)$ から $S(N)$ を求めるアルゴリズムには洲閣篩(Zhouge sieve) や [min_25篩](https://min-25.hatenablog.com/entry/2018/11/11/172216) などが知られているが、ここでは Black Algorithm を用いた解法を説明する。 [参考文献](http://baihacker.github.io/main/2020/The_prefix-sum_of_multiplicative_function_the_black_algorithm.html)

まず、以下の条件を満たす $1$ から $N$ の頂点ラベルがついた木を考える。
- 頂点 $1$ を根とする。
- 頂点 $n(\neq 1)$ の親は $n$ の最大の素因数を $p$ とした時に $\frac{n}{p}$ と表せる。

この木の上を DFS して訪れた頂点 $n$ に対して $f(n)$ を加算するという操作を行うと $S(N)$ は計算できるが $\mathrm{O}(N)$ かかってしまう。そこで一工夫して、訪れた頂点 $n$ の子 $c$ について $f(c)$ を計算することを考える。

今、葉でない木上の頂点 $n$ および $f(n)$ が分かっているとする。この時、子の頂点に書かれた数の集合 $T$ に対して $\sum_{c \in T}f(c)$ は以下に説明する方法で高速に計算することが出来る。

- $k$ 番目に小さい素数を $p_k$ と表して、$n$ の最大の素因数を $p_i$ とおく。すると $n$ の子の頂点を小さい順に並べた列は $np_i, np_{i+1}, \ldots, np_l$ のように表せる。($p_l$ は $np_l \leq N$ を満たす最大の素数) また、葉でないという条件から $p_i \leq \sqrt{n}$ が従う。
- このうち $n$ と $p_{i+1},\ldots,p_{l}$ は互いに素であるから、乗法性を利用して

$$\sum_{i+1\leq j\leq l} f(np_{j})=f(n)\sum_{i+1\leq j\leq l} f(p_{j})=f(n)\left(S_p\left(\left\lfloor\frac{N}{n}\right\rfloor\right)-S_p\left(p_i\right)\right)$$

と $S_p$ を用いて高速に計算できる。
-  $f(np_i)$ は $n=m\cdot p_i^e(\gcd(m,p_i)=1)$ と素因数分解すれば個別に計算できる。

以上のアルゴリズムを用いれば、$N$ 頂点の木の葉でない頂点を適切な情報をもってDFSすることで高速に $S(N)$ を求めることが出来る。

DFS の計算量は葉でないノードの個数に一致して $\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$ らしい。(参考文献のリンク先に書いてあるが中国語なので読めていない…) 以上より $S(N)$ を全体で $\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$ で求めることができた。

関連：[yukicoder No.1322 Totient Bound](https://yukicoder.me/problems/no/1322) $\pi(N)$ の列挙と木上の DFS を使うとかなり見通しよく解くことが出来る。[提出](https://yukicoder.me/submissions/595840)

ライブラリの使い方は verify のコードを適宜参照のこと。

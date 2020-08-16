# 素数カウント

## 素数の個数$\pi(N)$を計算する

$\pi(N)$を$\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$で計算するライブラリ。

#### 概要

まず初めに、$f(x,n):=$($n$以下の自然数のうち$x$以下の素数を因数に持たない数の個数)とおく。

この時、

$\pi(N) = f(\lfloor\sqrt{N}\rfloor,N) + \pi(\lfloor\sqrt{N}\rfloor) - 1$

であり、また

$f(x,n) = f(x-1,n) \ \ \ \ \ \mathrm{(if\ x\ is\ not\ prime)}$

$f(x,n) = f(x - 1, n) - \unicode{35} \lbrace i | (i \in [1, n] \wedge x|i )\rbrace$
$= f(x-1,n)-f(x-1,\frac{n}{x}) \ \ \ \ \ \mathrm{(if\ x\ is\ prime)}$

となるので、$x$を$\sqrt{N}$以下の素数、$n =\lfloor\frac{N}{K}\rfloor$を範囲として、$x$を大きくしていくin-placeな動的計画法で$\pi(N)$を求められる。計算量は
- $\sqrt{N}$以下の素数の個数 $\ldots$ 素数定理より$\mathrm{O}\left(\frac{\sqrt{N}}{\log N}\right)$
- DPテーブルの長さ $\ldots$ $\lfloor\frac{N}{K}\rfloor$の個数なので$\mathrm{O}(\sqrt{N})$

なので掛けて$\mathrm{O}\left(\frac{N}{\log N}\right)$となる。

さらに高速化する。$g(x,n) :=f(x,n) + \pi(\min(n,x))$とおくと、$g(x,n)$は$n$以下の数に$x$以下の素数でふるいを掛けた時に残ったもの($1$を含む)となる。ここから

$g(\lfloor\sqrt{N}\rfloor,N) = \pi(N) - 1$

であり、また$f$に代入すると

$g(x,n) = g(x-1,n) \ \ \ \ \ \mathrm{if\ x\ is\ not\ prime\ or}\ n<x^2$

$g(x,n) = g(x-1,n)-g(x-1,\lfloor\frac{n}{x}\rfloor) + \pi(x) \ \ \ \ \ \mathrm{otherwise}$

を示せる。

ほしいものは$g(x,n)-1$なので$h(x,n) = g(x,n)-1$とおいて微調整すると、

$\pi(x) = h(\lfloor\sqrt{N}\rfloor,n)$

$h(x,n) = h(x-1,n) \ \ \ \ \ \mathrm{if\ x\ is\ not\ prime\ or}\ n<x^2$

$h(x,n) = h(x-1,n)-h(x-1,\lfloor\frac{n}{x}\rfloor) + \pi(x-1) \ \ \ \ \ \mathrm{otherwise}$

となる。動的計画法での更新回数は

- $2 \leq x \leq N^{\frac{1}{4}}$のとき $\ldots$ 素数は$\mathrm{O}\left(\frac{N^{\frac{1}{4}}}{\log N}\right)$個あってDPテーブルの長さは$\mathrm{O}(\sqrt{N})$なので合計$\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$回
- $N^{\frac{1}{4}} \leq x \leq \sqrt{N}$のとき 各$x$についてそれぞれ$\ldots$ $x^2< n < N$を満たす部分を更新する。$\sqrt{N} < x^2$より$n$は$\mathrm{O}\left(\frac{N}{x^2}\right)$個なので、合計$\mathrm{O}\left(\frac{1}{\log N}\int_{N^{\frac{1}{4}}}^{\sqrt{N}} \frac{N}{x^2}dx\right)=\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)回$

以上より全体の計算量は$\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$となる。

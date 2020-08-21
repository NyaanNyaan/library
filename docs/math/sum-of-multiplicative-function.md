
## 乗法的関数の和

乗法的関数のprefix sumを$\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$で求めるアルゴリズムを実装したライブラリ。
(ただし、素数$p$について$f(p)=g(p)$を満たす多項式が存在するとする。)

実装例ではトーシェント関数$\phi(N)$を計算しているが、適切に書き換えることで条件を満たす乗法的関数に適用できる。

#### 乗法的関数

$f(n)$が任意の$\gcd(a,b) = 1$である自然数$a,b$に対して$f(ab) = f(a)f(b)$となる時、$f(n)$は乗法的であると呼ぶ。特に任意の$a,b$について$f(ab)=f(a)f(b)$が成り立つ時は完全乗法的であると呼ぶ。代表的なものを下に挙げる。

TODO:書く

乗法的関数の重要な性質は以下のようなものが挙げられる。

TODO:書く

#### アルゴリズムの概要

前計算として$S(N) = \sum_{i=1}^N f(i)$を求めるアルゴリズムを以下に説明する。

まず初めに、$1\leq k\leq N$に対して

$$S_p(\lfloor \frac{N}{k} \rfloor) = \sum_{p\ \mathrm{is}\ \mathrm{prime},1\leq p\leq \left\lfloor \frac{N}{k} \right\rfloor} f(p)$$

を求めたい。$p$が素数の時$f(p)$は多項式なので、$p$の次数ごとに分解すると$f(N)$は

$$S_c(N) = \sum_{p\ \mathrm{is}\ \mathrm{prime},1\leq p\leq N} p^c$$

の線形和で表すことが出来る。$S_c(\lfloor \frac{N}{k} \rfloor)$は[素数カウント](https://nyaannyaan.github.io/library/library/math/prime-counting.hpp.html)のアルゴリズムを一般的に拡張した方法で高速に求められる。(素数カウントの時に求めた$\pi(n)$は$c=0$の時の場合でると言える。)

$f(x,n) :=$ ($n$以下の自然数のうち$x$以下の素数を因数に持たない整数$p$に対する$p^c$の和)

とおくと$x$が素数の時に

$$f(x,n) = f(x - 1, n) - f(x-1,\lfloor\frac{n}{x}\rfloor)x^c$$

が成り立つ。ここで$n < x$のとき$f(x,n) = f(x-1,n)$、$x \leq n < x^2$のとき$f(x,n) = f(x-1,n) - x^c$となることを利用して$g(x,n) = f(x, n) + S_c(\min(x,n))$とおくと、$x$が素数の時に

$$g(x,n) = \begin{cases} g(x-1,n) & \mathrm{if}\ n < x^2 \newline g(x-1,n) - \lbrace g(x-1,\lfloor\frac{n}{x}\rfloor) - S_c(x-1) - 1 \rbrace x^c& \mathrm{otherwise} \end{cases}$$

となる。$S_c(\lfloor\sqrt{N}\rfloor,N)=g(\lfloor\sqrt{N}\rfloor,N)-1$であるから$h(x,n)=g(x,n)-1$と補正すると

$$S_c(N) = h(\lfloor\sqrt{N}\rfloor,N)$$

$$h(0,n) = -1 + \sum_{0 \leq m \leq n}m^c$$

$$h(x,n) = \begin{cases} h(x-1,n) & \mathrm{if}\ x\ \mathrm{is}\ \mathrm{not}\  \mathrm{prime}\ \cup\ n < x^2 \newline h(x-1,n) - \lbrace h(x-1,\lfloor\frac{n}{x}\rfloor) - S_c(x-1) \rbrace x^c& \mathrm{otherwise} \end{cases}$$

を得る。(なお、$S_c(x-1)=h(x-1,x-1)$である。)以上より、素数カウントと同様のアルゴリズムでDPを行うことで$\mathrm{O}(\frac{N^\frac{3}{4}}{\log N})$あるいは$\mathrm{O}(N^\frac{2}{3})$を達成できる。

TODO:続きを書く [参考文献1](https://min-25.hatenablog.com/entry/2018/11/11/172216) [参考文献2](http://baihacker.github.io/main/2020/The_prefix-sum_of_multiplicative_function_the_black_algorithm.html)

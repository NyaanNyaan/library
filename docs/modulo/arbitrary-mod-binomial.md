## 任意mod二項係数

$\binom{n}{m} \mod M$を前計算$\mathrm{O}(M)$、クエリ$\mathrm{O}(\log n + \log M)$で計算するライブラリ。

### 概要

[論文](https://github.com/rishirajsinghjhelumi/Coding-Templates/blob/master/Extras/BinCoeff.pdf)　[ferinさんの記事](https://ferin-tech.hatenablog.com/entry/2018/01/17/010829)　[hly1204さんの記事](https://hly1204.github.io/blog/1-12-2021-Lucas_theorem/)

$\binom{n}{m} \mod p^q$を計算出来ればCRTで$\binom{n}{m} \mod M$を復元できるので、ここでは素数冪に限定して議論する。

### $\binom{n}{m} \pmod p$の公式

$\binom{n}{m} \mod p$は比較的容易に計算できる。

> $\binom{n}{k} \mod p$は
> 
> $$n = a_r p^r + \cdots + a_1 p + a_0$$
> 
> $$k = b_r p^r + \cdots + b_1 p + b_0$$
>
>としたとき次の式で表される。
>
>$$\binom{n}{k} \equiv \prod_{i=0}^r \binom{a_i}{b_i} \pmod p$$
>

(証明)

$$(1+x)^n \equiv \prod_{i=0}^r ((1+x)^{p^i})^{a_i}$$

$$\equiv \prod_{i=0}^r (1 + x^{p^i})^{a_i} \equiv \prod_{i=0}^r \left(\sum_j \binom{a_i}{j} x^{jp^i}\right) \pmod p$$

と変形できるので、

$$\binom{n}{k} \equiv \lbrack x^k \rbrack (1 + x)^n$$

と合わせて上式を得る。

### $\binom{n}{m}\mod p^k$の公式

法が素数冪の場合は様々な定理を用いる必要がある。

#### Willsonの定理

> 素数$p$に対して次の合同式が成り立つ。
>
> $$(p - 1)! \equiv -1 \pmod p$$

(証明) $\mod p$上で$1,\ldots,p-1$は逆元をただ一つ持つ。そのうち$a^2 \equiv 1 \pmod p \iff a \equiv \pm 1 \pmod p$を除いた$a=2,\ldots,p-2$は逆元を$2$から$p-2$の中に持つことから、$\prod_{a=2}^{p-2} a\equiv 1$を得る。よって$(p-1)! \equiv 1 \cdot (-1) \equiv -1 \pmod p$になる。

#### 補題1

> 整数$n$に対して$(n!)_p$を$p$の倍数を除いた$n$以下の正整数の総積と置く。このとき素数冪$p^q$に対して
> 
> $$(p^q !)_p \equiv \delta \pmod {p^q}$$
>
> が成り立つ。ただし$\delta$は$p=2,q\geq 3$の時は$1$、それ以外の時は$-1$とする。

(証明) Willsonの定理と同様に証明する。$\mod p^q$上で$p$と互いに素な数は唯一の逆元を持つため、$a^2 \not \equiv 1 \pmod {p^q}$である$a$の総積は$1$である。$a^2 \equiv 1 \pmod {p^q}$の解は

$$a=\left\lbrace
\begin{array}{cc} 
1 & p = 2 \wedge q = 1\newline
\pm 1, 2^{q-1} \pm 1 & p = 2 \wedge q \geq 3 \newline
\pm 1 & \mathrm{otherwise}
\end{array}
\right.
$$

であるから、$\delta$は$p=2,q\geq 3$のとき$1$でそれ以外は$-1$になる。

また、$n \geq p^q$である$n$に対して補題を適用すると、$n = N_0 \bmod{p^q}$とおいて

$$(n!)_p \equiv \delta ^{\lfloor n / p^q \rfloor} (N_0!)_p  \pmod{p ^ q}$$

という式が導かれる。

#### Legendreの定理ととKummerの定理

Legendreの定理とは次の有名な定理である。(証明略)

> $n!$が$p$で割り切れる回数$\nu_p(n!)$は次の式で表される。
> 
> $$\nu_p(n!) =\sum_{1 \leq i} \left\lfloor \frac{n}{p^i} \right\rfloor $$

ここで次の補題2を考える。

> $n$を$p$進数表示したときの各桁の和を$\sigma_p(n)$とおくと、$\sigma_p(n)$と$\nu_p(n!)$の間には次の関係式が成り立つ。
>
> $$ \nu_p(n!) = \frac{n - \sigma_p(n)}{p - 1}$$
>

証明は帰納的に行うことが出来る。

この補題を利用すると、次に説明するKummerの定理が証明できる。

>
> $\binom{n}{m}$が$p$で割り切れる回数は$n-m$と$m$を$p$進数表示で足し算した時の繰り上がりの回数と等しい。
>

(証明)

$r = n - m$とおき、$p$進表示を$n = \sum_i n_i p^i$のように表すとする。また、$\epsilon_j$を$j$桁目で繰り上がりが起きた時$1$、起きないとき$0$を表す数とする。このとき、

$$n_j = m_j + r_j + \epsilon _{j-1} - p \epsilon_j$$

であり、

$$\nu_p\left(\frac{n!}{m!r!}\right) = \nu_p(n!) - \nu_p(m!) - \nu_p(r!) $$

$$ = \frac{\sigma_p(m) + \sigma_p(r) - \sigma_p(n)}{p - 1} $$

$$= \sum_j \frac{m_j + r_j - n_j}{p - 1}$$

$$= \sum_j \frac{\epsilon_j - p\epsilon_{j-1}}{p - 1} = \sum_j \epsilon_j$$

を得る。なお、$\epsilon_j$は次の式によって得られる。(Kummerの定理から従う。)

$$\epsilon_j = \left\lfloor \frac{n}{p^{j+1}}\right\rfloor - \left\lfloor \frac{m}{p^{j+1}}\right\rfloor - \left\lfloor \frac{r}{p^{j+1}}\right\rfloor$$

#### $n! \pmod {p^q}$の公式

> 正整数$n$と素数冪$p^q$に対して次の関係式が成り立つ。
> 
> $${n!} / {p^{\sum_{j \geq 1} \lfloor n / p^j \rfloor }} \equiv \delta^{\sum_{j \geq q} \lfloor n / p^j \rfloor} \prod_{j \geq 0} (N_j !)_p \pmod{p^q}$$
>
> ただし$N_j$は$\lfloor n / p^j \rfloor$と$\mod p^q$で合同な最小の非負整数とする。

(証明)

$j \geq 0$のとき

$$\lfloor n / p^j \rfloor ! / (p ^ {\lfloor n / p^{j + 1} \rfloor } \lfloor n / p^{j + 1} \rfloor ! ) \equiv (\lfloor n / p^{j} \rfloor !)_p $$

$$\equiv \delta^{\lfloor n / p^{j + q} \rfloor} (N_j !)_p \pmod{p ^ q}$$

であるから、$j \geq 0$について上式を辺々掛ければ示せる。

#### $\binom{n}{m} \pmod {p^q}$の公式

上の式からただちに二項係数に対する以下の関係式が従う。

> 非負整数$n,m$と素数冪$p^q$について以下の式が成り立つ。
> 
> $$\frac{1}{p^{e_0}}\binom{n}{m} = \delta^{e_{q-1}} \prod_{j \geq 0} \frac{(N_j!)_p}{(M_j!)_p (R_j!)_p}$$
> 
> ただし$e_j$は$j$桁目以上で繰り上がりが発生した回数で、次の式で表される。
>
> $$e_j = \sum_{j \lt i}\left(\left\lfloor \frac{n}{p^{i}}\right\rfloor - \left\lfloor \frac{m}{p^{i}}\right\rfloor - \left\lfloor \frac{r}{p^{i}}\right\rfloor\right)$$

$a \lt p^q$に対して$(a!)_p \bmod{p^q}$と$(a!)_p^{-1} \bmod{p^q}$を前計算しておくことで上の式は$\mathrm{O}(\log n)$で計算できる。

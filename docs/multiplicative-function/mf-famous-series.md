## 有名な乗法的関数

来るべきDGF(ディリクレ母関数)の流行に備えて(本当に流行るのか？)、自分が理解していることをメモしておく…

#### 乗法的関数

$f(n)$が任意の$\gcd(a,b) = 1$である自然数$a,b$に対して$f(ab) = f(a)f(b)$となる時、$f(n)$は乗法的であると呼ぶ。特に任意の$a,b$について$f(ab)=f(a)f(b)$が成り立つ時は完全乗法的であると呼ぶ。

乗法的関数の重要な性質は以下のようなものが挙げられる。

- $f(n),g(n)$が乗法的である時、$h(n)=f(n)g(n)$も乗法的である。
- $f(n),g(n)$が乗法的である時、ディリクレの畳み込みで得られる関数$h(n)=\sum_{d\mid n}f(d)g\left(\frac{n}{d}\right)$も乗法的である。

また、乗法的関数に関するアルゴリズムは以下のものが知られている。

- $f(n)$が乗法的であり、かつ$f(p^k)$が$\mathrm{O}(1)$で求まるとき、
  - $f(n)$の計算が$\mathrm{O}(n^{\frac{1}{4}})$　(Pollard's Rho法)
  - $f(n)$の初め$n$項の列挙が$\mathrm{O}(n)$　([実装](https://nyaannyaan.github.io/library/multiplicative-function/enamurate-multiplicative-function.hpp))
  - $f(n)$の初め$n$項のprefix sumが$\mathrm{O}(n^{\frac{2}{3}})$　([実装](https://nyaannyaan.github.io/library/multiplicative-function/enamurate-multiplicative-function.hpp))
  - $g(n)=\sum_{d\mid n}\mu\left(\frac{n}{d}\right)f(d)$の初め$n$項の列挙が$\mathrm{O}(n \log \log n)$　([実装](https://nyaannyaan.github.io/library/multiplicative-function/divisor-multiple-transform.hpp))

#### 有名な乗法的関数

- 定数関数　$\mathrm{I}(n)=c$
- 恒等写像　$\mathrm{Id}(n)=n$
- 指数関数　$\mathrm{Id}_a(n)=n^a$
- Unit Function $\epsilon(n)=[n = 1]$
- メビウス関数　$\mu(p^k) =[k = 0]-[k = 1]$
- 約数関数 $\sigma_a(p^k) = \sum_{i=0}^k p^{ai}$
- トーシェント関数　$\phi(p^k) = p^k - p^{k-1}$

このうち下の3つは次の畳み込みの関係が知られている。

- メビウス関数　$\sum_{d \mid n} \mu(n) = \epsilon(n)$
- 約数関数 $\sum_{d \mid n} d^a = \sigma_a(n)$
- トーシェント関数　$\sum_{d \mid n} \phi(d) = n$

#### メビウス関数　$\mu(n)$

メビウス関数に関する説明は[ここ](https://nyaannyaan.github.io/library/multiplicative-function/divisor-multiple-transform.hpp)に詳しく書いた。

競技プログラミングにおいてのメビウス関数の利用法は(雑に説明すると)包除原理の$(-1)^k$と似た使い方をすることが多い。実際に具体例を見てみる。

##### 例題1

- $N$の約数$n$に対して$g(n)=\sum_{d\mid n}f(d)$と$\mu(n)$がわかっているとする。この時$f(N)$を$\mathrm{O}(\sigma(N))$で計算せよ。

約数系包除を使えば$\mathrm{O}(\sigma(N)^2)$で解けるがより高速な解法を考えたい。
まずは反転公式を使わずに考察してみる。具体的な$N$についていくつか実験してみると、

$$f(16)=g(16)-g(8)$$

$$f(12)=g(12)-g(6)-g(4)+g(2)$$

$$f(30)=g(30)-g(15)-g(10)-g(6)+g(5)+g(3)+g(2)-g(1)$$

のようになり、これは包除原理+BIT全探索で解くことが出来る。([tsutajさんの非常にわかりやすい包除PDF](https://compro.tsutaj.com//archive/181015_incexc.pdf)に類題の詳しい説明がある。)

一方、反転公式を使うと、例えば$n=12$の時は

$$f(12) = \sum_{d \in \lbrace 1,2,3,4,6,12\rbrace}\mu\left(\frac{n}{d}\right)g(d)=g(12)-g(6)-g(4)+g(2)$$

となり包除原理によって得られる結果と一致する。

下位集合に対するゼータ変換が包除原理で解けることと、約数集合に対するゼータ変換がメビウス関数で解けることは同じような関係にある(？)と言える。

##### 例題2：[Cube-loving Numbers　(HackerRank)](https://www.hackerrank.com/contests/university-codesprint-5/challenges)

- $N$が与えられるので、「自然数$a>1,b\geq 1$を用いて$a^3\times b$と表せる$N$以下の自然数の個数」を$\mathrm{O}(\sqrt[3]{N})$で計算せよ。

$1\leq n\leq N$において自然数$a,b$を用いて$n=a^3\times b$と表せる$n$の個数$g(a)$は$g(a)=\lfloor\frac{N}{a^3}\rfloor$と容易に表せるので、この式をうまく利用して答えを求めたい。(直感的には、$g(n)$は一つの自然数を複数回カウントする関数なのでメビウス変換したいという気持ちになる。)

対象を重複なく数え上げるために、自然数$n$に一対一対応する$(a,b)$を決定したい。具体的には、「$n=A^3\times B$を満たす自然数の組$(A,B)$の中で最も$B$が小さい組」を$n$に対応する組$(a,b)$とおく。そして、$f(a)$を「$(a,\frac{n}{a^3})$と対応している$N$以下の自然数$n$の個数」とおく。

$f$と$g$の関係式を得るために、$g(a)$でカウントされている自然数$n$が$f$のどこでカウントされているかを考える。$n=a^3\times b$としたとき、$b$に一対一対応する整数の組を$(c,d)$とおくと、$n$に対応する組は$(ca,d)$であるから$f(ca)$で数え上げられていることが分かる。逆に$f(ca)$で数え上げられた$n$が$g(a)$で数えられていることも示せる。よって$f(a)$と$g(a)$の間には

$$g(a)=\sum_{a\mid m}f(m) \leftrightarrow f(a)=\sum_{a\mid m}\mu\left(\frac{m}{a}\right)g(m)$$

という倍数変換の関係式が成り立つことがわかる。また、求める答えは$M=\lfloor\sqrt[3]{N}\rfloor$と置いたとき$\sum_{a=2}^Mf(a)$である。
($M\lt a$のとき$f(a)=g(a)=0$である事実を利用している。)

よって倍数メビウス変換を用いれば$\mathrm{O}(M\log \log M)$で計算できることが示せたが、メビウス関数を用いることでさらなる高速化を図りたい。$\sum_{a=2}^Mf(a)$を$g(m)$の線形和に分解したときの$g(m)$の寄与を考察すると、

$$\sum_{a=2}^M f(a)=\sum_{2\leq a\leq M, a\mid m} \left( \mu\left(\frac{m}{a}\right)g(m)\right)$$

$$=\sum_{2\leq m\leq M} g(m)\left(\sum_{a\mid m,a\neq 1}\mu\left(\frac{m}{a}\right)\right)$$

$$=\sum_{2\leq m\leq M} g(m)(-\mu(m)+\sum_{a\mid m}\mu(a))=-\sum_{2\leq m\leq M} g(m)\mu(m)$$

と非常にきれいな式になる。$\mu(m)$および$g(m)$は線形で列挙できるため、求める答えも線形で列挙できる。以上よりこの問題を$\mathrm{O}(\sqrt[3]{N})$で解くことが出来た。

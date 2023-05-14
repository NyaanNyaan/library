## 多項式GCD

多項式GCDを$\mathrm{O}(N \log ^ 2 N)$($N$は多項式の次数)で求めるライブラリ。

#### 概要

[参考資料その１](http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf)　[参考資料その２](https://scrapbox.io/37zigen-43465887/half-GCD)

多項式$a(x),b(x)$がある。$h\mid a,h\mid b$が成り立つ任意の多項式$h$に対して$g\mid h$となるような$g$を多項式のGCDとして$\gcd(a,b)$と置く。

$\gcd(a,b)$は通常のgcdと同様にユークリッドの互除法で求まるが、一回の除算につき次数は最低1しか減らないため、愚直に計算すると計算量が$\mathrm{O}(N^2 \log N)$程度になってしまう。そこで高速化のためにHalf-GCD法と呼ばれるアルゴリズムを使用する。

通常のユークリッドの互除法における一回の操作を行列で表すと下のようになる。

$$\left(
    \begin{array}{cc}
      0 & 1  \\
     1 & -\mathrm{quo}(a,b) 
    \end{array}
  \right)
  \left(
      \begin{array}{c}
          a \\ 
          b
      \end{array}
  \right)=
  \left(
      \begin{array}{c}
          b \\
          a - b\cdot \mathrm{quo}(a,b)
      \end{array}
  \right)$$
 
 同様に、ユークリッドの互除法全体は次のように表される。

$$
  M_i M_{i-1}\cdots M_2M_1\left(
      \begin{array}{c}
          a \\ 
          b
      \end{array}
  \right)=
  \left(
      \begin{array}{c}
          \gcd(a,b) \\ 
          0
      \end{array}
  \right)$$
  
よって、行列$M_1,M_2,M_3,\ldots,M_i$を求められれば$\gcd(a,b)$が求められることになる。

Half-GCD法とは次に示す性質を生かして、より少ない計算量で行列の列$M$のおよそ前半分を求めるアルゴリズムである。
  
- $a = a_0 + a_1x^k, b=b_0+b_1x^k$とおく。($k \lt \deg(a))$この時、$(a_1,b_1)$にユークリッドの互除法を適用したときに得られる行列$L_1,L_2,\dots$と$M_1,M_2\ldots$は、先頭から順に一部が一致する。

証明は参考文献を参照のこと。(~~ちゃんと理解していない...直感的な理解としては、多項式の除算のプロセスを考えると商が上位の次に依存しそう。~~)

自分の実装では$\mathrm{HGCD}(N)$を1回実行するのに$\mathrm{HGCD}(\frac{N}{2})$を2回+$N$次の除算1回を呼んでいる。計算量は$\mathrm{T}(N) = 2\mathrm{T}(\frac{N}{2}) + N\log N$を解いて$\mathrm{O}(N \log ^2 N)$となる。

#### inv of polynomials

[inv of polynomials(Library Checker)](https://judge.yosupo.jp/problem/inv_of_polynomials)は多項式GCDのverify用問題である。問題概要は次の通りである。

- 多項式$f(x),g(x)$に対して$f(x)h(x) \equiv 1 \mod g(x)$を満たす$h(x)$を求めよ。(ただし$\deg (h(x)) \lt \deg g(x)$)

この問題はいわゆる拡張ユークリッド法と同様のアルゴリズムで解くことが出来る。まず、$\gcd(f,g) \neq 1$のとき$fh \equiv 0 \not \equiv 1 \mod \gcd(f,g)$より$h$は解なしとなる。次に$\gcd(f,g) = 1$の時、題意を満たす$h$と$f,g$の関係式は、適当な多項式$s$を用いて次のように表される。

$$(f, g)^T h = (sg+1,gh)^T$$

$f,g$を多項式GCDの関数に代入したときに得られる行列$M$を両辺に掛けると

$$M(f,g)^Th=(1,0)=M(sg+1,gh)^T$$

となり、辺々$\mod g(x)$を取って

$$(1,0)^T h \equiv M(1,0)^T \mod g(x)$$

を得るので、$h \equiv M_{11} \mod g(x)$が従う。

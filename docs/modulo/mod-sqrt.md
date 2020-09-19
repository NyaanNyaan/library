## mod sqrt(Tonelli-Shanks algorithm)

整数$a$、素数$p$に対して$x^2 \equiv a \mod p$を満たす$x$を$\mathrm{O}(\log ^2 p)$で計算するライブラリ。

#### 概要

[37zigenさんの記事](https://37zigen.com/tonelli-shank-%e3%81%ae%e3%82%a2%e3%83%ab%e3%82%b4%e3%83%aa%e3%82%ba%e3%83%a0/)を大きく参考にした。

まず、オイラーの規準により

$$a^\frac{p-1}{2} \equiv 1 \mod p$$

であることが$a$が平方剰余を持つ必要十分条件である。以降は$a$が平方剰余を持つ場合のみ考える。

$\mod p$上の原始根を$r$と置き、$x\equiv r^y,a\equiv r^b$とすると上の等式は

$$x^2 \equiv a \mod p \leftrightarrow 2y \equiv b \mod p-1$$

と言い換えられる。よって原始根がわかれば解は求まるが、離散対数問題を解く部分が$\mathrm{O}(\sqrt{p})$程度の計算量となり遅い。そこで、原始根を計算せずにうまく$a$を利用して$x$を計算できるように工夫をする。(つまり、$\mod p-1$の世界での計算を$\mod p$の世界での計算にうまく置き換えて解く。)

$p - 1 =s\cdot 2^t$($t$は奇数)を満たすように$s,t$を取ると、中国剰余定理より

$$2y \equiv b \mod s \wedge 2y \equiv b \mod 2^t$$

となる$y$を見つければ良いとわかる。ここで、$x,y$の初期値として

$$x_0=a^\frac{s+1}{2} \rightarrow y_0 = \frac{s+1}{2}b\mod p-1$$

を取ると、$2y_0 \equiv b \mod s, 2y_0 \equiv (s+1)b \mod 2^t$となり、$\mod s$は求める$y$に一致するので、$sb$だけずれている$\mod t$の方をうまく微調整すればよいとわかる。

ここで、$u^\frac{p-1}{2} \not\equiv 1\mod p$である$u$を乱択で選ぶと、

$$\mathrm{Ind}_r u^s \equiv0 \mod s,\ \mathrm{Ind}_r u^s \equiv 1 \mod 2$$

が従う。よって$x$に$u^s$を掛けると、$y \mod s$は変わらず$y \mod 2^t$の1ビット目が反転することになる。この$u^s$を利用して誤差を調整する。

まず、現在の$y$の誤差項$2y-b\mod 2^t$の最下位ビットは、現在の$a^{-1}x^2$を自乗していって$1$になるまでにかかった回数を$t'$としたときに$t-t'$ビット目になる。最下位ビットが分かれば、$x$に$\mathrm{pow}(u^s,2^{t-t'-1})$を掛けることで最下位ビットを$0$にすることが出来る。このアルゴリズムを用いて小さいビットから0にしていき、$a^{-1}x^2 \equiv 1$になるまで繰り返せば$x$を求めることが出来る。

計算量は、誤差調整の1回あたり$\mathrm{O}(\log p)$で最大$t=\mathrm{O}(\log p)$回かかるので全体で$\mathrm{O}(\log ^2 p)$となる。


## kth root

整数$a,k$、素数$p$に対して$x^k \equiv a \mod p$を満たす$x$を$\mathrm{O}(\min (p,k)^{\frac{1}{4}})$で計算するライブラリ。

#### 概要

[37zigenさんの解説](https://yukicoder.me/problems/no/981/editorial)を参考にしました。

原始根を利用して考察する。$\mod p$上の原始根を$r$と置き、$x\equiv r^y,a\equiv r^b$とすると上の等式は

$$x^k \equiv a \mod p \leftrightarrow ky \equiv b \mod p-1$$

と言い換えられる。ここで$g = \gcd(k,p-1)$と置くと、上の合同式が成り立つ条件は$b \equiv 0 \mod g$であることがわかる。よって、

- $b \not \equiv 0 \mod g$の場合は解が存在しない。
- $b \equiv 0 \mod g$の場合は、$\frac{k}{g}$と$\frac{p-1}{g}$が互いに素なので$\left(\frac{k}{g}\right)^{-1}\mod \frac{p-1}{g}$が存在して、この時$y \equiv \frac{b}{g} \left(\frac{k}{g}\right)^{-1}\mod \frac{p-1}{g}$が解となる。

以上より解を求めることが出来たが、このままでは計算量は離散対数問題と同じ$\mathrm{O}(\sqrt{p})$なので、[mod sqrt](https://nyaannyaan.github.io/library/library/modulo/mod-sqrt.hpp.html)の時と同様にTonelli-Shanks algorithmを利用して高速化を図る。

まず、解の存在条件は

$$b \equiv 0 \mod g$$

$$\leftrightarrow \frac{b(p-1)}{g}\equiv 0 \mod p-1$$

$$\leftrightarrow a^\frac{p-1}{g} \equiv 1 \mod p$$

となる。以下は解が存在する時のみ考える。

$k\left(gk^{-1} \mod \frac{p-1}{g}\right)\equiv g\mod p-1$であるから、与式は

$$x^k \equiv a \mod p \leftrightarrow x^g\equiv \mathrm{pow}\left(a,gk^{-1} \mod \frac{p-1}{g}\right)\mod p$$

となる。(このように$x$の底を$k$から$g$に変換することで、$g\mid p-1$の性質を利用したToneli-Shanksのアルゴリズムが適用可能になる。)ここで$g = \Pi_i p_i^{e_i}$と置いたとき、

$$z^{p_i^{e_i}}\equiv c \mod p \ \ \ \cdots (\ast)$$

を解くことが出来れば、($\ast$)を繰り返し元の式に適用することで$x$を求めることが出来る。よって($\ast$)を高速に計算する方法を考えればよく、この問題は[mod sqrt](https://nyaannyaan.github.io/library/library/modulo/mod-sqrt.hpp.html)と同様にしてTonelli-Shanksのアルゴリズムが適用出来る。

原始根$r$に対して$r^w=z,r^d=c,p-1=sp_i^t$($\gcd(s,p_i)=1$)とおくと、

$$(\ast) \leftrightarrow p_i^{e_i}w\equiv d\mod p$$

$$\leftrightarrow p_i^{e_i}w\equiv d\mod s\ \wedge p_i^{e_i} w\equiv d\mod p_i^t$$

となる。ここで、$\left(-s^{-1} \mod {p_i}^{e_i}\right)=u$と置き、$z$の初期値を$z_0 \equiv \mathrm{pow}(c,\frac{su+1}{ {p_i}^{e_i}}) \mod p$とおくと、

$$p_i^{e_i}w_0 \equiv d(su+1) \mod p-1$$

$$\leftrightarrow p_i^{e_i}w_0\equiv d\mod s\ \wedge p_i^{e_i} w\equiv d(su+1)\mod p_i^t$$

となるので$\mod s$の方は条件を満たしており、$\mod p_i^{t_i}$を調整すればよいとわかる。

ここで、$\mathrm{pow}\left(v,\frac{p-1}{p_i}\right)\not\equiv 1$である$v$を乱択で選ぶ。(条件を満たす$v$は$1-\frac{1}{p_i}$の確率で手に入る。)この時、

$$\mathrm{Ind}_r v^{s} \equiv 0\mod s\ ,\mathrm{Ind}_r v^s \not\equiv 0\mod p_i$$

が成り立つ。($\mathrm{Ind}_r$は$r$を底、$p$を法としたときの指数。)この$v^s$を利用してTonelli-Shanks algorithmを実行する。

まず、現在の$z$の誤差項$p_i^{e^i} z - d\mod p_i^{e_i}$の誤差が$np_i^e$と表せるとする。この時$e$は、$c^{-1}z^{p_i^{e_i}}$を$p_i$乗していって$1$になるまでにかかった回数を$t'$としたときに
$e=t-t'$となる。$e$が分かったら、$z^{ {p_i}^{t'-1}}\equiv 1$を満たすまで$z$に$\mathrm{pow}(v^s,p^{e-e_i})$を掛け続ける。このアルゴリズムを$t'=0$になるまで繰り返せば$z$を求めることが出来る。

このままだとTonelli-Shanksのループ一回あたり最大$p_i-1$回の乗算が必要となるが、最後の$\mathrm{pow}(v^s,2^{e-e_i})$を掛ける所でBaby Step Giant Stepを利用することで、ループあたりの乗算回数を$\mathrm{O}(\sqrt{p_i})$回に落とすことが出来る。

また、Tonelli-Shanksのループ回数は高々$\lfloor\log_{p_i}p\rfloor - 1$回となる。つまり、$t=e_i=1$の時($g$と$p-1$がともに$p_i$で1回ずつしか割り切れないとき)はループに入らないので、$p_i \gt \sqrt{p-1}$である素数に対しては高速に解が計算できるとわかる。よって、全体の計算量は$g=\gcd(k,p-1)$が$\mathrm{O}(\sqrt{p})$程度の重複度2の素因数を含む時が最大で、この時$\mathrm{O}(g^{\frac{1}{4}})=\mathrm{O}(\min (p,k)^{\frac{1}{4}})$となる。

$g$の素因数分解も[Millar-rabinとPollardの$\rho$法](https://nyaannyaan.github.io/library/prime/fast-factorize.hpp)を利用すれば$\mathrm{O}(g^{\frac{1}{4}})$で計算できるので、全体の計算量は$\mathrm{O}(\min (p,k)^{\frac{1}{4}})$となる。

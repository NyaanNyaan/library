# 形式的冪級数
多項式/形式的冪級数の基本操作を行うライブラリ。

次の3つのファイルから成り、modが$998244353$の時は1番目と2番目を、$1e9+7$の時は1番目と3番目をincludeして使用する。

- `formal-power-series.hpp` $\cdots$ 共通部分のみ実装したもの。
- `ntt-friendly-fps.hpp` $\cdots$ NTT素数mod用の高速な実装を行ったもの。
- `arbitrary-fps.hpp` $\cdots$ 任意mod畳み込み用の実装を行ったもの。

実装の一部はうしさんのライブラリを大きく参考にしました。感謝…

TODO: 実装していない関数の実装

TODO: invやexpはNTT$\cdot$INTTを利用した高速化があるので実装する

### 加算・減算

$\mathrm{O}(N)$

### 乗算

$h(x)=f(x)g(x)$となる$h(x)$を求める。これはFFT/NTT(FMT)で求められる。$\mathrm{O}(N \log N)$

### 除算

$f(x) = g(x)q(x) + r(x)$となる多項式$q,r$を求めたい。($f$は$n-1$次、$g$は$m-1$次($n>m$),$q$は$n-m$次とする。)ここで、

$$f^R := f(\frac{1}{x})\cdot x^{n-1}$$

のようにおくと$f^R$は多項式になる。最初の式を$x \leftarrow \frac{1}{x}$に置き換えると、

$$f(\frac{1}{x})  = g(\frac{1}{x})q(\frac{1}{x})+r(\frac{1}{x})$$

両辺に$x^{n-1}$を掛けると

$$f(\frac{1}{x}) x^{n-1} = g(\frac{1}{x})x^{m-1}\cdot q(\frac{1}{x})x^{n-m}+r(\frac{1}{x})x^{m-2} \cdot x^{n-m+1}$$

$$\leftrightarrow f^R = g^R q^R + r^R x^{n-m+1}$$

$$\rightarrow f^R \equiv g^R q^R \mod x^{n-m+1}$$

を得る。$q^R$は$n-m$次なので$\mod x^{n-m+1}$を利用して

$$\frac{f^R}{g^R} \equiv q^R \mod x^{n-m+1}$$

となるので、ここから$q$と$r$を計算できる。(逆元の出し方は後述)

### 微分・積分

$\mathrm{O}(N)$

なお、微分/積分は数列に対するimos法/累積和に対応している。また、形式的冪級数の数式的な操作としては、$1-x$を掛けるのが微分、$\frac{1}{1-x}$を掛けるのが積分に対応している。

### ダブリング

$f \mod x^n$を求めたい時に、$f = f_0 \mod n$から始めて精度を倍々にして求める手法のことをダブリングと呼ぶ。

具体的には、$\hat{f} \equiv f \mod x^k$から$f \mod x^{2k}$を

$$(f - \hat{f})^2 \equiv 0 \mod x^{2k}$$

を利用して計算する。これを利用して逆元を求める。

### 逆元

$fg\equiv 1 \mod x^n$となる$f$の逆元$g$をダブリングで求めたい。

まず$g \equiv f_0^{-1} \mod x$である。次に、$g = \hat{g} \mod x^k$が分かっているとき$g \mod x^{2k}$を出す。

$$(g-\hat{g})^2\equiv g^2-2g\hat{g}+\hat{g}^2\equiv0 \mod x^{2k}$$

両辺に$f$を掛けると

$$fg^2-2fg\hat{g}+f\hat{g}^2\equiv0 \mod x^{2k}$$

$fg \equiv 1 \mod x^{2k}$を利用して$fg$を消すと

$$g\equiv2\hat{g}-f\hat{g}^2 \mod x^{2k}$$

を得る。計算量は$T(n)=T(n/2)+\mathrm{O}(N \log N)$を解いて$T(n)=\mathrm{O}(N \log N)$となる。

### log

$f_0 = 1$を満たす$f$について$g\equiv\log f \mod x^n$となる$g$は

$$\log f\equiv \int \frac{f'}{f} \mod x^n$$

から求まる。($g_0 = 0$とすると$x=0$を代入したとき両辺が$0$になるので、積分による定数項周りの心配は不要)

### ニュートン法

$G(g) \equiv f \mod x^n$を満たすFPSである$g$を求めたい。普通のニュートン法+ダブリングの要領で

$$g \equiv \hat{g} - \frac{G(\hat{g})-f}{G'(\hat{g})} \mod x^{2n}$$

が従う。(証明は$G(\hat{g})$を$\hat{g}=0$でテイラー展開すると求まる)これを使ってexpを求める。

### exp

$g \equiv e^f \mod x^n$となる$g$を求める。

$$\log g \equiv f \mod x^n$$

等式が成り立つには$f_0=0$が必要でこの時$g_0=1$。次にニュートン法を使うと、

$$g \equiv \hat{g} - \frac{\log\hat{g}-f}{\log'\hat{g}} \mod x^{2n}$$

$\log' \hat{g}=\frac{1}{\hat{g}}$より

$$g\equiv \hat{g}(1-\log \hat{g}+f) \mod x^{2n}$$

となりダブリングで求まる。$\mathrm{O}(N \log N)$ (分割統治+FFTの方が高速に動作する？)

### 累乗

$g \equiv f^k \mod x^n$となる$g$を求めたい。繰り返し自乗法を用いると$\mathrm{O}(N \log k \log N)$で求まるがexpを使うともっと早くなる。

$f$の一番次数の低い項が$a_p x^p \ (p \neq 0)$のときは$\left(\frac{f}{a_p x^p}\right)^k$を計算して最後に$a_p^kx^{kp}$を掛ければよいため、$f$の定数項が$1$である場合のみ考えればよい。このとき$f^k$は$f^k\equiv e^{(\log f)k}$から計算できる。

### 平方根

$f$は$t^2=f_0$を満たす$t$が存在する多項式とする。このとき$g \equiv \sqrt{f} \mod x^n$となる$g$を求めたい。

まず、$g \equiv t \mod x$である。次にニュートン法で$g^2 \equiv f$を満たす$g$を求めると、$g=\hat{g} \mod x^k$ のとき 

$$g \equiv \hat{g} - \frac{\hat{g}^2-f}{(\hat{g}^2)'} \mod x^{2k}$$

$$\leftrightarrow g \equiv \frac{1}{2}\left(\hat{g}+\frac{f}{\hat{g}}\right) \mod x^{2k}$$

を得てダブリングで求まる。

### 三角関数

$g \equiv \cos f, h \equiv \sin f \mod x^n$を求めたい。これは$e^{if}=\cos f+i\sin f$から計算できる。($e^{if}$の計算は実部と虚部に分けて行う必要がある。例えば掛け算の時は4回乗算して適切に足し合わせる感じ。)

### 平行移動

$g(x) = f(x+a)$となる$g(x)$を求める。書きかけ
# 形式的冪級数
多項式/形式的冪級数の基本操作を行うライブラリ。

次の3つのファイルから成り、modが$998244353$の時は1番目と2番目を、$1e9+7$の時は1番目と3番目をincludeして使用する。

- `formal-power-series.hpp` $\cdots$ 共通部分のみ実装したもの。
- `ntt-friendly-fps.hpp` $\cdots$ NTT素数mod用の高速な実装を行ったもの。
- `arbitrary-fps.hpp` $\cdots$ 任意mod畳み込み用の実装を行ったもの。

実装の一部は[うしさんのライブラリ](https://ei1333.github.io/library/library/math/fps/formal-power-series.cpp.html)を大きく参考にしました。感謝…

### 加算・減算

$\mathrm{O}(N)$

### 乗算

$h(x)=f(x)g(x)$となる$h(x)$を求める。これはFFT/NTT(FMT)で求められる。$\mathrm{O}(N \log N)$

### 除算

(注：この項に書かれている除算は多項式としての除算である。)

$f(x) = g(x)q(x) + r(x)$となる多項式$q,r$を求めたい。($f$は$n-1$次、$g$は$m-1$次($n \gt m$),$q$は$n-m$次とする。)ここで、

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

### ダブリング

$f \mod x^n$を求めたい時に、$f \equiv f_0 \mod x$から始めて精度を倍々にして求める手法のことをダブリングと呼ぶ。

具体的には、$\hat{f} \equiv f \mod x^k$から$f \mod x^{2k}$を

$$(f - \hat{f})^2 \equiv 0 \mod x^{2k}$$

を利用して計算する。これを利用して逆元を求める。

### 逆元

$fg\equiv 1 \mod x^n$となる$f$の逆元$g$をダブリングで求めたい。

まず$g \equiv f_0^{-1} \mod x$である。次に、$g \equiv \hat{g} \mod x^k$が分かっているとき$g \mod x^{2k}$を出す。

$$(g-\hat{g})^2\equiv g^2-2g\hat{g}+\hat{g}^2\equiv0 \mod x^{2k}$$

両辺に$f$を掛けると

$$fg^2-2fg\hat{g}+f\hat{g}^2\equiv0 \mod x^{2k}$$

$fg \equiv 1 \mod x^{2k}$を利用して$fg$を消すと

$$g\equiv2\hat{g}-f\hat{g}^2 \mod x^{2k}$$

を得る。計算量は$T(n)=T(n/2)+\mathrm{O}(N \log N)$を解いて$T(n)=\mathrm{O}(N \log N)$となる。

なお、modがNTT素数の場合は実装を工夫することで定数倍が2倍以上軽くなる。

### log

$f_0 = 1$を満たす$f$に対して、$e^f \equiv g \mod x^n$を満たす$g$を$g\equiv\log f \mod x^n$として定義する。この時、$g$は

$$\log f \equiv \int \frac{f'}{f} dx \mod x^n$$

から求まる。(なお、上の式は一見すると不定積分の定数項のズレが心配に見えるが、$g_0 = 0$とおくと$x=0$を代入したとき両辺が等しくなるので問題ない。)

### ニュートン法

数値解析におけるニュートン法とは、$f(x)=0$を満たす$x$の値を、漸化式

$$x_{n+1} = x_{n}-\frac{f(x_n)}{f'(x_n)}$$

を利用した反復計算により真の値を得るアルゴリズムであった。このアルゴリズムを形式的冪級数にも応用する。

$G(g) \equiv f \mod x^n$を満たす形式的冪級数$g$を求めたい。$G(\hat{g}) \equiv f \mod x^n$を満たす$\hat{g}$が求まっている時、$\hat{g}$と$g \mod x^{2n}$の間に成り立つ関係式を考える。

$G(g)$の$g = \hat{g}$におけるテイラー展開の式は

$$G(g) = G(\hat{g}) + G'(\hat{g})(g-\hat{g})+\mathrm{O}((g-\hat{g})^2)$$

となるが、$g - \hat{g} \equiv 0 \mod x$なので形式的冪級数を考えてもよい。辺々$\mod x^{2n}$を取ると、$(g-\hat{g})^2 \equiv 0 \mod x ^{2n}$より

$$G(g) \equiv f \equiv G(\hat{g}) + G'(\hat{g})(g-\hat{g}) \mod x^{2n}$$

であり、これをさらに変形して

$$g \equiv \hat{g} - \frac{G(\hat{g})-f}{G'(\hat{g})} \mod x^{2n}$$

を得る。この式を使って$\mathrm{exp}$や$\mathrm{sqrt}$を計算することが出来る。

### exp

$g \equiv e^f \mod x^n$となる$g$を求める。

$$\log g \equiv f \mod x^n$$

等式が成り立つには$f_0=0$が必要でこの時$g_0=1$。次にニュートン法を使うと、

$$g \equiv \hat{g} - \frac{\log\hat{g}-f}{\log'\hat{g}} \mod x^{2n}$$

$\log' \hat{g}\equiv\frac{1}{\hat{g}}$より

$$g\equiv \hat{g}(1-\log \hat{g}+f) \mod x^{2n}$$

となりダブリングで求まる。$\mathrm{O}(N \log N)$ 

### 累乗

$g \equiv f^k \mod x^n$となる$g$を求めたい。繰り返し自乗法を用いると$\mathrm{O}(N \log k \log N)$で求まるがexpを使うともっと早くなる。

$f$の一番次数の低い項が$a_p x^p \ (p \neq 0)$のときは$\left(\frac{f}{a_p x^p}\right)^k$を計算して最後に$a_p^kx^{kp}$を掛ければよいため、$f$の定数項が$1$である場合のみ考えればよい。このとき$f^k$は$f^k\equiv e^{(\log f)k}$から計算できる。

### 平方根

[fps/fps-sqrt.hpp](https://nyaannyaan.github.io/library/library/fps/fps-sqrt.hpp.html)にて解説。

### 三角関数

[fps/fps-circular.hpp](https://nyaannyaan.github.io/library/library/fps/fps-circular.hpp.html)にて解説。

### 平行移動

[fps/taylor-shift.hpp](https://nyaannyaan.github.io/library/library/fps/taylor-shift.hpp.html)にて解説。

### 階差(imos法)/累積和

(関数は未実装)
数列に対して階差を取る(imos法)、あるいはその逆に累積和を取ることを形式的冪級数の数式的な操作に置き換えると、それぞれ$1-x$を掛ける/割る操作に対応している。計算量はともに$\mathrm{O}(N)$である。

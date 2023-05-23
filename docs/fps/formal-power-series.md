# 形式的冪級数

多項式/形式的冪級数の基本操作を行うライブラリ。

次の3つのファイルから成り、mod が $998244353$ のような NTT 素数の時は 1 番目と 2 番目を、 $10^9 + 7$ の時は 1 番目と 3 番目を include して使用する。

- `formal-power-series.hpp` $\cdots$ 共通部分のみ実装したもの。
- `ntt-friendly-fps.hpp` $\cdots$ NTT 素数 mod 用の高速な実装を行ったもの。
- `arbitrary-fps.hpp` $\cdots$ 任意 mod 畳み込み用の実装を行ったもの。

実装の一部は[うしさんのライブラリ](https://ei1333.github.io/library/library/math/fps/formal-power-series.cpp.html)を大きく参考にしました。感謝…

### 加算・減算

$\mathrm{O}(N)$

### 乗算

多項式 $f(x), g(x)$ に対して $h(x)=f(x)g(x)$ となる $h(x)$ を求める。これは FFT/NTT(FMT) で求められる。  
計算量は $\deg(f) + \deg(g) = N$ として $\mathrm{O}(N \log N)$ である。

### 除算

(注：この項に書かれている除算は多項式としての除算である。)

$f(x) = g(x)q(x) + r(x)$ となる多項式 $q,r$ を求めたい。( $\deg(f) = n - 1, \deg(g) = m - 1, \deg(q) = n-m \geq 0$ とする。) ここで、

$$\mathrm{rev}(f) := f(x^{-1})\cdot x^{n-1}$$

のようにおくと $\mathrm{rev}(f)$ もまた $n-1$ 次の多項式になる。最初の式を $x \leftarrow x^{-1}$ に置き換えると

$$f(x^{-1}) = g(x^{-1})q(x^{-1})+r(x^{-1})$$

両辺に $x^{n-1}$ を掛けると

$$f(x^{-1}) x^{n-1} = g(x^{-1})x^{m-1}\cdot q(x^{-1})x^{n-m}+r(x^{-1})x^{m-2} \cdot x^{n-m+1}$$

$$\leftrightarrow \mathrm{rev}(f) = \mathrm{rev}(g) \mathrm{rev}(q) + \mathrm{rev}(r) x^{n-m+1}$$

$$\rightarrow \mathrm{rev}(f) \equiv \mathrm{rev}(g) \mathrm{rev}(q) \pmod{x^{n-m+1}}$$

を得る。$\mathrm{rev}(g)$ の定数項は非 $0$ なので $\text{mod }x^{n-m+1}$ 上で逆元を取ることができて (逆元の出し方は後述)

$$\frac{\mathrm{rev}(f)}{\mathrm{rev}(g)} \equiv \mathrm{rev}(q) \pmod{x^{n-m+1}}$$

となるのでこの式から $q$ を計算できて、$r$ もまた $f - gq$ から計算できる。  
計算量は $\deg(f) + \deg(g) = N$ として $\mathrm{O}(N \log N)$ である。

### 微分・積分

$\mathrm{O}(N)$

### ダブリング

$f \bmod{x^n}$ を求めたい時に、$f \equiv f_0 \pmod{x}$ から始めて精度を倍々にして求める手法のことをダブリングと呼ぶ。

具体的には、$\hat{f} \equiv f \pmod{x^k}$ から $f \bmod{x^{2k}}$ を

$$(f - \hat{f})^2 \equiv 0 \pmod{x^{2k}}$$

を利用して計算する。

### 逆元

$fg\equiv 1 \pmod{x^n}$ となる $f$ の逆元 $g$ をダブリングで求めたい。

まず $g \equiv f_0^{-1} \pmod{x}$ である。次に、$g \equiv \hat{g} \pmod{x^k}$ が分かっているとき $g \bmod{x^{2k}}$ を求める。

$$(g-\hat{g})^2\equiv g^2-2g\hat{g}+\hat{g}^2\equiv0 \pmod{x^{2k}}$$

両辺に $f$ を掛けて

$$fg^2-2fg\hat{g}+f\hat{g}^2\equiv0 \pmod{x^{2k}}$$

$fg \equiv 1 \pmod{x^{2k}}$ を利用して $fg$ を消すと

$$g\equiv2\hat{g}-f\hat{g}^2 \pmod{x^{2k}}$$

を得る。計算量は $T(n)=T(n/2)+\mathrm{O}(n \log n)$ を解いて $T(n)=\mathrm{O}(N \log N)$ となる (出力の次数を $N$ とする)

(なお、mod が NTT 素数の場合は実装を工夫することで定数倍が 2 倍以上軽くなる。)

### log

$f_0 = 1$ を満たす $f$ に対して、$f \equiv e^g \mod x^n$ を満たす $g$ を $g\equiv\log f \pmod{x^n}$ として定義する。この時、$g$ は

$$\log f \equiv \int \frac{f'}{f} dx \pmod{x^n}$$

から求まる。(なお、上の式は一見すると不定積分の定数項のズレが心配に見えるが、$g_0 = 0$ とおくと $x=0$ を代入したとき両辺が等しくなるので問題ない。) 計算量は $\mathrm{O}(N \log N)$ である。(出力の次数を $N$ とする)

### ニュートン法

ダブリングを利用した逆元の計算ではいささか唐突に $(g-\hat{g})^2$ を計算したが、このアルゴリズムを一般化した手法としてニュートン法を説明する。

数値解析におけるニュートン法とは、$f(x)=0$ を満たす $x$ の値を、漸化式

$$x_{n+1} = x_{n}-\frac{f(x_n)}{f'(x_n)}$$

を利用した反復計算により真の値を得るアルゴリズムであった。このアルゴリズムを形式的冪級数にも応用する。

$G(g) \equiv 0 \pmod{x^n}$ を満たす形式的冪級数 $g$ を求めたい。$G(\hat{g}) \equiv 0 \pmod{x^n}$ を満たす $\hat{g}$ が求まっている時、$\hat{g}$ と $g \bmod{x^{2n}}$ の間に成り立つ関係式を考える。

$G(g)$ の $g = \hat{g}$ におけるテイラー展開の式は

$$G(g) = G(\hat{g}) + G'(\hat{g})(g-\hat{g})+\mathrm{O}((g-\hat{g})^2)$$

となる。両辺 $\text{mod }x^{2n}$ を取ると ($g - \hat{g}$ の定数項は $0$ なので形式的冪級数とみなして考えても問題が起こらない)、$(g-\hat{g})^2 \equiv 0 \pmod{x ^{2n}}$ より

$$0 \equiv G(g) \equiv G(\hat{g}) + G'(\hat{g})(g-\hat{g}) \pmod{x^{2n}}$$

であり、これをさらに変形して

$$g \equiv \hat{g} - \frac{G(\hat{g})}{G'(\hat{g})} \pmod{x^{2n}}$$

を得る。この式を使って $\mathrm{exp}(f)$ や $\mathrm{sqrt}(f)$ を計算することが出来る。

### exp

$g \equiv e^f \pmod{x^n}$ となる $g$ を求める。

$$\log g \equiv f \pmod{x^n}$$

等式が成り立つには $f_0=0$ が必要でこの時 $g_0=1$ である。次にニュートン法を使うと、

$$g \equiv \hat{g} - \frac{\log\hat{g}-f}{\log'\hat{g}} \pmod{x^{2n}}$$

$\log' \hat{g}\equiv\frac{1}{\hat{g}}$ より

$$g\equiv \hat{g}(1-\log \hat{g}+f) \pmod{x^{2n}}$$

となり、この式を利用して長さを倍々にしていくことができる。計算量は $\mathrm{O}(N \log N)$ である。(出力の次数を $N$ とする)

### 累乗

$g \equiv f^k \pmod{x^n}$ となる $g$ を求めたい。繰り返し自乗法を用いると $\mathrm{O}(N \log k \log N)$ で求まるがexpを使うともっと早くなる。

$f$ の一番次数の低い項が $a_p x^p \ (p \neq 0)$ のときは $\left(\frac{f}{a_p x^p}\right)^k$ を計算して最後に $a_p^kx^{kp}$ を掛ければよいため、$f$ の定数項が $1$ である場合のみ考えればよい。このとき $f^k$ は $f^k\equiv e^{(\log f)k}$ から計算できる。  
計算量は $\mathrm{O}(N \log N)$ である。(出力の次数を $N$ とする)

### 平方根

[fps/fps-sqrt.hpp](https://nyaannyaan.github.io/library/library/fps/fps-sqrt.hpp.html) にて解説。

### 三角関数

[fps/fps-circular.hpp](https://nyaannyaan.github.io/library/library/fps/fps-circular.hpp.html) にて解説。

### 平行移動

[fps/taylor-shift.hpp](https://nyaannyaan.github.io/library/library/fps/taylor-shift.hpp.html) にて解説。

### 階差(imos法)/累積和

(関数は未実装)  
数列に対して階差を取る(いわゆる imos 法)、あるいはその逆に累積和を取る操作を形式的冪級数の数式的な操作に置き換えると、それぞれ $1-x$ を掛ける/割る操作に対応している。計算量はともに $\mathrm{O}(N)$ である。


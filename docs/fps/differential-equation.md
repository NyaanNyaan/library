## 常微分方程式

$$\frac{d}{dx}f \equiv F(f) \mod x^n,\ f(0) = f_0$$

を満たす形式的冪級数$f$をダブリングを利用して$\mathrm{O}(N \log N)$で求めるアルゴリズム。($F$は$\mathrm{O}(k \log k)$で$\mod x^k$まで計算できる関数とする。)

[出典(codeforces)](https://codeforces.com/blog/entry/76447)　調べてみると中国のブログに記述が散見されることから、中国では比較的一般的なテクニックのようである。

#### 概要

$\hat{f} \equiv f \mod x^k$が求まっているとき$f \mod x^{2k}$と$\hat{f}$の関係式を導出する。

$F(f)$の$f=\hat{f}$におけるテイラー展開の式

$$F(f) = \sum_{k=0}^\infty \frac{F^{(k)}(\hat{f})}{k!}(f-\hat{f})^k$$

は$f - \hat{f} \equiv 0 \mod x$なので形式的冪級数に適用できる。

$$\frac{d}{dx}f \equiv F(f) \equiv \sum_{k=0}^\infty \frac{F^{(k)}(\hat{f})}{k!}(f-\hat{f})^k \mod x^{2k}$$

$(f-\hat{f})^2 \equiv 0 \mod x^{2k}$を利用して

$$\frac{d}{dx}f \equiv F(\hat{f}) +F'(\hat{f})(f-\hat{f}) \mod x^{2k} \cdots (\ast)$$

を得る。ここで、

$$r \equiv e^{-\int F'(\hat{f})dx} \mod x^{2k}$$

とおくと、

$$\frac{d}{dx}r\equiv e^{-\int F'(\hat{f})dx}\cdot (-F'(\hat{f}))=-F'(\hat{f})r\mod x^{2k-1}$$

となる。$(\ast)$を変形して両辺に$r$を掛けると

$$\frac{d}{dx}f\cdot r -F'(\hat{f})f\cdot r\equiv (F(\hat{f}) -F'(\hat{f})\hat{f})\cdot r \mod x^{2k-1}$$

であるが、左辺は$\frac{d}{dx}(f\cdot r)$に等しいので、両辺を積分すると

$$f\cdot r \equiv \int \left( \left(F(\hat{f}) -F'(\hat{f})\hat{f}\right)\cdot r\right)dx + C \mod x^{2k}$$

となり、$r(0) = 1$より両辺の定数項を比較して$C=f_0$が従う。以上より$f$と$\hat{f}$の関係式として次の式を得る。

$$f\equiv r^{-1}\left( \int \left( \left(F(\hat{f}) -F'(\hat{f})\hat{f}\right)\cdot r\right)dx + f_0\right) \mod x^{2k}$$

この式を利用して初項を$f \equiv f_0 \mod x$としたダブリングを行うことで、常微分方程式を$\mathrm{O}(N \log N)$で計算できる。

なお、低速なexp/invを使用している場合は(計算量の劣る)分割統治FFTの方が高速に動作するようである。

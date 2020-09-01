## Tetration

$a \uparrow \uparrow b \mod m$を$\mathrm{O}(\sqrt{M})$で計算するライブラリ。$a \uparrow \uparrow b$とは、

$$a \uparrow \uparrow b =\begin{cases} 1 & \mathrm{if}\ \ b = 0\newline a^{a \uparrow \uparrow (b-1)} & \mathrm{otherwise}\end{cases}$$

として定められる二項演算である。

#### 概要

$a\uparrow \uparrow b$と$a\uparrow \uparrow (b-1)$の関係式を元に再帰的に計算する。

$a$と$m$が互いに素の時は、オイラーの定理$a ^ {\phi(m)}\equiv 1 \mod m$より、

$$a \uparrow \uparrow b \equiv a^{a \uparrow \uparrow (b-1)} \equiv a^{(a \uparrow \uparrow (b-1) \mod \phi(m))} \mod m$$

という関係式を得ることができる。

次に$a$と$m$が互いに素でない場合を考える。$m=kl$を$l$と$a$が互いに素で$k$が$a$の素因数の積で表されるように取る。

この時、$a^i \mod k$は$i$が十分に大きいときに$0$に等しくなり、$a^i \mod l$はオイラーの定理より$\phi(l)$周期を持つ。よって中国剰余定理と合わせて$a^i \mod m$は$i$が十分に大きい時に$\phi(m)$周期になることがわかる。

ここで具体的に$m=kl$を具体的に計算する必要はないことに留意する。というのも、トーシェント関数の乗法性より$a^i \mod m$は$\phi(m)$周期を持つためである。また、$\lfloor\log_2 m\rfloor \leq \phi(m)$ より$a^{\phi(m)} \equiv 0 \mod k$になることから、$i$が$\phi(m)$未満の時は愚直に計算して、それより$i$が大きいときは周期性を利用して計算すればよい。(実装の際は$a\uparrow \uparrow b$が$m$以上かどうかをフラグとして持っておけばよい。)

以上より、$a\uparrow \uparrow b \mod m$は$a\uparrow \uparrow (b-1) \mod \phi(m)$の値から導出できることがわかった。計算量はアルゴリズム全体でのトーシェント関数の計算量に依存するので、計算量を求めるために数列$m,\phi(m),\phi(\phi(m))\ldots$の性質を考察する。

ここで、$m$が偶数の時$\phi(m)$は$\frac{m}{2}$以下になる。また、$m$が奇数の時、$\phi(m)$は偶数なので$\phi(\phi(m))$は$\frac{\phi(m)}{2}$以下になる。以上より、上記の数列は少なくとも$2$個おきに半減して、$\mathrm{O}(\log_2 m)$回で$1$に収束する。よって全体の計算量は$T(m) = \mathrm{O}(\sqrt{m})+T(\frac{m}{2})$を解いて$\mathrm{O}(\sqrt{m})$となる。

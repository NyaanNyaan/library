## fps-平方根

$N$次の形式的冪級数$f(x)$に対して$g(x) \equiv \sqrt{f(x)} \mod x^N$を満たす$g(x)$を$\mathrm{O}(N \log N)$で計算するライブラリ。ここで$\sqrt{f(x)}$は$g^2(x) \equiv f(x) \mod x^N$を満たす形式的冪級数を意味する。

#### 概要

$f$は$t^2=f_0$を満たす$t$が存在する多項式とする。このとき$g \equiv \sqrt{f} \mod x^n$となる$g$を求めたい。

まず、$g \equiv t \mod x$である。次にニュートン法で$g^2 \equiv f$を満たす$g$を求めると、$g=\hat{g} \mod x^k$ のとき 

$$g \equiv \hat{g} - \frac{\hat{g}^2-f}{(\hat{g}^2)'} \mod x^{2k}$$

$$\leftrightarrow g \equiv \frac{1}{2}\left(\hat{g}+\frac{f}{\hat{g}}\right) \mod x^{2k}$$

を得てダブリングで求まる。計算量は$\mathrm{O}(N \log N)$。

#### 使い方

- `sqrt(f, deg)`: FPSである$f$について$\sqrt f$をdeg次の項まで求める。


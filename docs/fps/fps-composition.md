
## 関数の合成

形式的冪級数$P(x),Q(x)$(ただし$P_0 = 0$)に対して$Q(P) \mod x^{n}$を$\mathrm{O}(\left(n\log n\right)^{\frac{3}{2}})$で求めるライブラリ。

[出典の論文](http://www.eecs.harvard.edu/~htk/publication/1978-jacm-brent-kung.pdf)

#### 概要

まず、$P$を$P = P_m + P_r,\ \ P_r \equiv 0 \mod x^m$を満たす$P_m,P_r$に分けて考える。($m$は後で値を決める。)この時、テイラー展開の式

$$Q(P)=\sum_{i=0}^\infty\frac{Q^{(i)}(P_m)}{i!}(P-P_m)^i=\sum_{i=0}^\infty\frac{Q^{(i)}(P_m)}{i!}(P_r)^i$$

の前$\lfloor\frac{n}{m}\rfloor$次の項を計算できればよいので($P_r \equiv 0 \mod x$に留意する)、$Q^{(i)}(P),0 \leq i \leq \lfloor\frac{n}{m}\rfloor$を高速に列挙できればよい。

まず、$Q(P(x))\mod x^n$は$\deg(Q) = j$($j$は2冪)とした時

$$Q(P) = Q_1(P) + P^{\frac{j}{2}}\cdot Q_2(P)$$

を利用して再帰的に求めることで$\mathrm{O}(jm\log^2 n)$で計算できる。また、$Q^{(i)}(P_m)$は連鎖律$\frac{d}{dx}Q(P) = \frac{dP} {dx} \cdot \frac{dQ}{dP}$を利用して

$$Q^{(i)}{(P_m)} \equiv \frac{\left(Q^{(i-1)}{(P_m)}\right)'}{P_m'} \mod x^{n-i}$$

より$\mathrm{O}(\lfloor\frac{n}{m}\rfloor n \log n)$で列挙できる。(実装においては、$m \geq 2$かつ$P$の$2$次の係数が$0$の時に$\frac{1}{P_m'}$が定義されないコーナーケースを意識して適切に逆元を取る必要がある。)

最後にテイラー展開の式に基づいて足し合わせる部分も愚直に計算すると$\mathrm{O}(\lfloor\frac{n}{m}\rfloor n \log n)$で計算できる。

以上より$j = n$とすると$\mathrm{O}(nm\log^2 n + \lfloor\frac{n}{m}\rfloor n \log n)$で$Q(P(x))$を計算することが出来た。ここで$m = \sqrt{\frac{n} {\log n}}$とおくと$\mathrm{O}(\left(n\log n\right)^{\frac{3}{2}})$となる。

###### 余談

実装してから思ったが、元の論文には行列積を使用した$O(\sqrt{N}\cdot T(\sqrt{N}))$($T(n)$は行列積のオーダー)のアルゴリズムも載っており、オーダーは実質2乗だがSIMDの利用などにより定数倍高速化が見込める。

$N \leq 8192$とすると、感覚的には解説したアルゴリズムよりも大きさ$100$の行列積$100回$の方が高速に動作する気がする… 

$\rightarrow$実装したら3倍速かった [実装](https://nyaannyaan.github.io/library/library/fps/fps-composition-fast.hpp.html)

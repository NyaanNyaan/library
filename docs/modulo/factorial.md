## 階乗 $\mod p$

$n! \mod p$を$\mathrm{O}(\sqrt{p} \log p)$で計算するライブラリ。

#### アルゴリズム

min_25氏の記事(削除済み)を大きく参考にしました。

$G_d(i)$を次のように定める。
- $g_d(x) \equiv (x+1)(x+2)\ldots (x+d) \mod p$を$x=i,v+i\ldots,dv+i$で多点評価した値の組

この時$G_d(0)$の$i$番目の要素$G_d(0)_i$は$(vi+1)(vi+2)\ldots(vi+d) \mod p$になる。ここで、$d = v\geq \sqrt{p}$であるとき、
$$n! \equiv \left(\prod_{0 \leq i \lt \lfloor\frac{n}{v}\rfloor} G_v(0)_i \right)\cdot \left( \prod_{\lfloor\frac{n}{v}\rfloor \cdot v \lt i \leq n} i \right) \pmod p$$
になることが容易に確認できる。よって$G_v(0)$を高速に計算するアルゴリズムを見つければよい。

$G_v(0)$の計算は$G_d(0)$から$G_{2d}(0)$を$\mathrm{O}(d \log d)$で計算するアルゴリズムを利用する。これを利用すればダブリングの要領で$G_v(0)$を$\mathrm{O}(v \log v)$で計算できる。

アルゴリズムの内容は上に示したブログで詳述されているので概要のみまとめる。$g_{2d}(x) = g_d(x) g_d(x + d)$を利用すると、
  - $G_{2d}(0)$の前$d + 1$項$\cdots$ $G_d(0) \ast G_d(d)$   ($\ast$はアダマール積)
  - 残りの部分 $\cdots$ $G_d(dv + v) \ast G_d(dv + v + d)$の前$d$項

となるので、$G_d(d), G_d(dv + d), G_d(dv + v + d)$を標本点のシフトを利用して計算すればよい。

ここでは簡単のため$v$を固定した実装にしているが、$p$の値によっては$v = 32768$が不適切になることに注意する必要がある。

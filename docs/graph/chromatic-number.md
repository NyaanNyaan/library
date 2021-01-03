## 彩色数

頂点数$n$のグラフの彩色数を$\mathrm{O}(2^n n)$で求めるライブラリ。

#### 概要

[wata氏の指数時間アルゴリズムの資料](https://www.slideshare.net/wata_orz/ss-12131479)や[noshi氏のライブラリの解説](https://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/chromatic_number.rs)などに詳しい。

$\lbrace1,2,\ldots,m\rbrace$の部分集合からなる集合を$[m]$、実数の集合$R$を$[m]$に対して拡張したものを$R[U_m]$と置き、subset zeta convolutionを$R[U_m]$上の乗法とする。

この時、グラフ$G(V,E),|V|=n$が$k$彩色可能であることは、$d[s]=[s$が独立集合である$]$を満たす$d \in R[U_n]$について$d^k[\lbrace1,2,\ldots,n\rbrace] \neq 0$
であることと同値である。

よって、係数が非零になるまで$d^k$を昇順に計算していけば彩色数が求まる。これは愚直に計算すると$\mathrm{O}(2^n n^2)$だが、必要な係数は一つだけなのでゼータ/メビウス変換を陽に計算する必要はない事実を利用すると計算量を$\mathrm{O}(2^n n)$に改善できる。

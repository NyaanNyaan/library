
## Subset Convolution

$n$要素の集合の部分集合$S$に対する関数$f(S),g(S)$に対して、

$$(f \circ g)(S) = \sum_{T \subseteq S}f(T)g(S\setminus T)$$

を$\mathrm{O}(2^N N^2)$で計算するライブラリ。

#### 概要

[指数時間アルゴリズム](https://www.slideshare.net/wata_orz/ss-12131479)の包除定理の項目を参考にした。

関数$f$に対して、要素$n$が入っていない集合を定義域とする関数を$f_1$、
入っている集合を定義域とする関数を$f_2$とおく。(厳密に書くと、

$$f_1(S) = f(S),\ f_2(S) = f(S \cap \lbrace n\rbrace) \ \ \ (S\subset\lbrace1,2,\ldots n-1\rbrace)$$

となる。)この時、

$$ (f\circ g)_1 = f_1 \circ g_1$$

$$ (f\circ g)_2 = f_1 \circ g_2 + f_2 \circ g_1$$

となり、これを愚直に計算すると、$2^n$要素の畳み込みが$2^{n-1}$要素の畳み込み$3$回で計算できるので$\mathrm{O}(3^N)$となる。

高速化のために多項式を導入する。関数の加法やスカラー倍を$(f+g)(S)=f(S)+g(S),(f\cdot x)(S)=f(S)x$のように定義すると、

$$(f\circ g)_2\cdot x\equiv (f_1+f_2\cdot x)\circ(g_1+g_2\cdot x)-f_1\circ g_1 \mod x^2$$

となり、$f\circ g$が$2^{n-1}$サイズの畳み込み$2$回を用いて再帰的に計算できるようになる。再帰の末尾で次数$n$の多項式乗算$2^n$回が必要になるため計算量は$T(n)=2T(n-1)+\mathrm{O}(n^2 2^n)$を解いて$\mathrm{O}(2^N N^2)$となる。

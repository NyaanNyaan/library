## fps-平行移動

$N$次の多項式$f(x)$に対して$g(x) = f(x+a)$を満たす$g(x)$を$\mathrm{O}(N \log N)$で計算するライブラリ。

#### 概要

$N$次の多項式$f(x)$に対して$g(x) = f(x+a)$となる$g(x)$を求める。これは、

$$f(x+a) = \sum_{n=0}^N f_n(x+a)^n$$

$$=\sum_{i=0}^Nx^i\sum_{n=i}^N(a^{n-i}f_n\ _nC_i)$$

$m=N-n,j=N-i$とおいて

$$=\sum_{j=0}^N\frac{x^j}{(N-j)!}\sum_{m=0}^j\frac{a^{j-m}}{(j-m)!}\left((N-m)!f_{N-m}\right)$$

と変形できるので畳み込みに帰着される。

#### 使い方

- `TaylorShift(f, a, C, deg)`: 多項式$f$について$f(x+a)$をdeg次の項まで求める。CにはBinomial構造体を渡す。

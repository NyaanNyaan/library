
## Multivariate Multiplication

$k$変数多項式$f(x_1,\ldots,x_k),g(x_1,\ldots,x_k)$に対して、

$$f(x_1,\ldots,x_k)\cdot g(x_1,\ldots,x_k) \mod (x_1^{n_1},x_2^{n_2},\ldots,x_k^{n_k})$$

を、$N= \prod_i n_i$と置いたときに$\mathrm{O}(kN \log N)$で計算するライブラリ。

参考文献

- [EntropyIncreaser氏のブログ](https://www.luogu.com.cn/blog/EntropyIncreaser/hello-multivariate-multiplication)　他にも色々アルゴリズムを発明してるけど一体何者なんですかね…
- [参考](https://rushcheyo.blog.uoj.ac/blog/6547)　同内容だけどこっちのサイトの方が翻訳機に投げた時に文字が乱れないのでよさげ

#### 概要

ここで紹介するアルゴリズムはsubset convolutionを一般の次数に対して拡張したものとして解釈できる。(実際、$\forall i, n_i = 2$の時がsubset convolutionと同じ演算になる。)そこで、subset convolutionのアルゴリズムと比較しながら説明する。

まず、指数部分の添え字$(i_1,i_2,\ldots,i_k)$を$(n_1,n_2,\ldots,n_k)$進数に置き換える。すなわち、$i = i_1 + i_2 n_i + \ldots + i_n n_1 \cdot n_2 \cdots n_{k-1}$と置き換える。こうすることで$(i_1,i_2,\ldots,i_k)$同士の加算を$i$同士の加算として扱えるが、繰り上がりが発生する部分の寄与を取り除く必要がある。

そこで、subset convolutionと同様にして畳み込みに新たな情報を載せることで繰り上がりがない部分のみを取り出せないかを考える。今、$i$に対応する占位関数$\chi(i)$を、$i+j$が繰り上がりせず、かつその時に限り$\chi(i) + \chi(j) = \chi(i+j)$が成り立つように定める。すると、$f$を占位多項式$\sum_i f_i x^i t^{\chi(i)}$へと変換して畳み込みを行い、得られた式の$x^i t^{\chi(i)}$次の項を見れば答えが求まる。

subset convolutionと同様に考えると$\chi(i)$は$\sum_j i_j$なら上手くいくとわかる。しかし計算量の観点から考えると$n_j$が非常に大きいときに$\chi(i)$は大きくなってしまいよろしくない。

発想を転換して考える。$i$ごとに$\lbrace \chi(i-j) + \chi(j) \vert 0 \leq j \leq i \rbrace$の得られる集合が極めて小さければ、しきい値$D$を置いて$\mod(t^D - 1)$上で計算すればよいとわかる。そこで、占位関数$\chi(i)$を

$$\chi(i) = \lfloor\frac{i}{n_1}\rfloor + \lfloor\frac{i}{n_1n_2}\rfloor + \ldots + \lfloor\frac{i}{n_1n_2\ldots n_{k-1}}\rfloor$$

とおく。この式はよく観察すると$\chi(i+j) - (\chi(i) + \chi(j))  = $($i+j$で繰り上がりが起こった回数)になるとわかる。よって$\chi(i) + \chi(j) - \chi(i+j) \in \lbrack -k+1,0 \rbrack$になるので、$\sum_i f_i x^i t^{\chi(i)}$を$\mod (t^k - 1)$上で多項式乗算を行えば復元可能な計算ができるとわかる。

計算量を考える。行う操作としては$f,g$を$x$に対して長さ$2N$のDFTを行った後に$t$について愚直に$f,g$の畳み込みを行いIDFTして元に戻すので$\mathrm{O}(k N \log N + k^2 N)$であるが、$k \leq \log_2 N$なので$\mathrm{O}(k N \log N)$と書ける。

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-ntt/yosupo-multiplicative-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-multiplicative-convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/ntt/multivariate-multiplication.md
    document_title: Multivariate Multiplication
    links: []
  bundledCode: "#line 2 \"ntt/multivariate-multiplication.hpp\"\n\ntemplate <typename\
    \ fps>\nfps multivariate_multiplication(const fps& f, const fps& g,\n        \
    \                        const vector<int>& base) {\n  int n = f.size(), s = base.size(),\
    \ W = 1;\n  if (s == 0) return fps{f[0] * g[0]};\n  while (W < 2 * n) W *= 2;\n\
    \n  vector<int> chi(n);\n  for (int i = 0; i < n; i++) {\n    int x = i;\n   \
    \ for (int j = 0; j < s - 1; j++) chi[i] += (x /= base[j]);\n    chi[i] %= s;\n\
    \  }\n\n  vector<fps> F(s, fps(W)), G(s, fps(W));\n  for (int i = 0; i < n; i++)\
    \ F[chi[i]][i] = f[i], G[chi[i]][i] = g[i];\n\n  for (auto& x : F) x.ntt();\n\
    \  for (auto& x : G) x.ntt();\n  fps a(s);\n  for (int k = 0; k < W; k++) {\n\
    \    fill(begin(a), end(a), typename fps::value_type());\n    for (int i = 0;\
    \ i < s; i++)\n      for (int j = 0; j < s; j++) {\n        a[i + j - (i + j >=\
    \ s ? s : 0)] += F[i][k] * G[j][k];\n      }\n    for (int i = 0; i < s; i++)\
    \ F[i][k] = a[i];\n  }\n  for (auto& x : F) x.intt();\n  fps h(n);\n  for (int\
    \ i = 0; i < n; i++) h[i] = F[chi[i]][i];\n  return h;\n}\n\n/**\n * @brief Multivariate\
    \ Multiplication\n * @docs docs/ntt/multivariate-multiplication.md\n */\n"
  code: "#pragma once\n\ntemplate <typename fps>\nfps multivariate_multiplication(const\
    \ fps& f, const fps& g,\n                                const vector<int>& base)\
    \ {\n  int n = f.size(), s = base.size(), W = 1;\n  if (s == 0) return fps{f[0]\
    \ * g[0]};\n  while (W < 2 * n) W *= 2;\n\n  vector<int> chi(n);\n  for (int i\
    \ = 0; i < n; i++) {\n    int x = i;\n    for (int j = 0; j < s - 1; j++) chi[i]\
    \ += (x /= base[j]);\n    chi[i] %= s;\n  }\n\n  vector<fps> F(s, fps(W)), G(s,\
    \ fps(W));\n  for (int i = 0; i < n; i++) F[chi[i]][i] = f[i], G[chi[i]][i] =\
    \ g[i];\n\n  for (auto& x : F) x.ntt();\n  for (auto& x : G) x.ntt();\n  fps a(s);\n\
    \  for (int k = 0; k < W; k++) {\n    fill(begin(a), end(a), typename fps::value_type());\n\
    \    for (int i = 0; i < s; i++)\n      for (int j = 0; j < s; j++) {\n      \
    \  a[i + j - (i + j >= s ? s : 0)] += F[i][k] * G[j][k];\n      }\n    for (int\
    \ i = 0; i < s; i++) F[i][k] = a[i];\n  }\n  for (auto& x : F) x.intt();\n  fps\
    \ h(n);\n  for (int i = 0; i < n; i++) h[i] = F[chi[i]][i];\n  return h;\n}\n\n\
    /**\n * @brief Multivariate Multiplication\n * @docs docs/ntt/multivariate-multiplication.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: ntt/multivariate-multiplication.hpp
  requiredBy: []
  timestamp: '2021-03-03 00:56:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-multiplicative-convolution.test.cpp
documentation_of: ntt/multivariate-multiplication.hpp
layout: document
redirect_from:
- /library/ntt/multivariate-multiplication.hpp
- /library/ntt/multivariate-multiplication.hpp.html
title: Multivariate Multiplication
---

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

#### 問題例：[UOJ 596 三維立体混元勁](https://uoj.ac/problem/596)

> 色$1,2,\ldots,k$のついたラベル付き頂点がそれぞれ$n_1,n_2,\ldots,n_k$個あり、色$i$の着いた頂点とと色$j$の着いた頂点の間には$a_{ij}$本のラベル付き辺が張られている。($i=j$の時にも辺は貼られているが自己ループは存在しない。)
> 部分グラフのうち全ての頂点が連結になるグラフの個数は？

グラフが連結でない場合を認めるとこの問題は容易に解くことが出来る。そこで、頂点を$i_1,i_2,\ldots,i_k$個ずつ持つ無向連結グラフ/無向グラフの個数のEGFをそれぞれ$f(x_1,\ldots,x_k),g(x_1,\ldots,x_k)$と置くと

$$e^f \equiv g \leftrightarrow f \equiv \log g \pmod{x_1^{n_1}\ldots x_k^{n_k}}$$

という関係を得るので、$\log g$をうまく計算できればよいとわかる。
一変数FPSの時は$\log$は微積分と逆元を適切に定義することで計算が可能であったが、多変数における$\log$の定義の仕方を次に説明する。

#### 多変数FPSの逆元

subset convolutionの逆元はゼータした後に$t$の式についてinvを取れば上手くいったが、今回は$t$を$\pmod {t^k-1}$で計算しているため上手くいかない。

そこで、通常のFPSと同様にニュートン法を行う。つまり、乗算を占位多項式の乗算によって定めた多項式$F(x)$に対して、$G_{(k)}(x) := \equiv G(x) \bmod{x^k}$を

$$G_{(1)} = (\lbrack x^0\rbrack F(x))^{-1}$$

$$G_{(2k)} \equiv 2G_{(k)} - FG_{(k)}^2 \mod x^{2k}$$

という漸化式に基づいて計算する。乗算ごとに正しい項のみを取り出す操作を行えば不要な項が寄与するのを防げるため、このアルゴリズムは適切に動作する。

### 多変数冪級数の微積分

冪級数$f(x)$に対して特殊な微分演算子$\mathfrak{D}F$を

$$\mathfrak{D}f = \sum i f_i x^i $$

によって定める。するとこの演算子は、多変数冪級数$f,g$、および冪級数$h$に対して

$$\mathfrak{D}(fg) = f\mathfrak{D}g+ g\mathfrak{D}f $$

$$\mathfrak{D}(h\circ g) = (h' \circ g)\cdot \mathfrak{D}g $$

が成り立つ。この式を$f \equiv \log g$に適用すると

$$\mathfrak{D}(f) = \mathfrak{D}(\log g) = \frac{\mathfrak{D}(g)}{g} $$

が成り立つので、$g$から$f \equiv \log g$を計算することが出来た。

[提出](https://uoj.ac/submission/460059)　$\mathrm{O}(\frac{5}{3}M(n))$の逆元を利用しないと通らないTL設定になっており、マニア向けの色合いが極めて強い。

---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: set-function/exp-of-set-power-series.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570\u306E exp"
  - icon: ':heavy_check_mark:'
    path: set-function/polynomial-composite-set-power-series.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570\u306E\u5408\u6210"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-exp-of-set-power-series.test.cpp
    title: verify/verify-yosupo-graph/yosupo-exp-of-set-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-polynomial-composite-set-power-series.test.cpp
    title: verify/verify-yosupo-math/yosupo-polynomial-composite-set-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
    title: verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/set-function/subset-convolution.md
    document_title: Subset Convolution
    links: []
  bundledCode: "#line 2 \"set-function/subset-convolution.hpp\"\n\n#include <array>\n\
    #include <vector>\nusing namespace std;\n\ntemplate <typename mint, int _s>\n\
    struct SubsetConvolution {\n  using fps = array<mint, _s + 1>;\n  static constexpr\
    \ int s = _s;\n  vector<int> pc;\n\n  SubsetConvolution() : pc(1 << s) {\n   \
    \ for (int i = 1; i < (1 << s); i++) pc[i] = pc[i - (i & -i)] + 1;\n  }\n\n  void\
    \ add(fps& l, const fps& r, int d) {\n    for (int i = 0; i < d; ++i) l[i] +=\
    \ r[i];\n  }\n\n  void sub(fps& l, const fps& r, int d) {\n    for (int i = d;\
    \ i <= s; ++i) l[i] -= r[i];\n  }\n\n  void zeta(vector<fps>& a) {\n    int n\
    \ = a.size();\n    for (int w = 1; w < n; w *= 2) {\n      for (int k = 0; k <\
    \ n; k += w * 2) {\n        for (int i = 0; i < w; ++i) {\n          add(a[k +\
    \ w + i], a[k + i], pc[k + w + i]);\n        }\n      }\n    }\n  }\n\n  void\
    \ mobius(vector<fps>& a) {\n    int n = a.size();\n    for (int w = n >> 1; w;\
    \ w >>= 1) {\n      for (int k = 0; k < n; k += w * 2) {\n        for (int i =\
    \ 0; i < w; ++i) {\n          sub(a[k + w + i], a[k + i], pc[k + w + i]);\n  \
    \      }\n      }\n    }\n  }\n\n  vector<fps> lift(const vector<mint>& a) {\n\
    \    vector<fps> A(a.size());\n    for (int i = 0; i < (int)a.size(); i++) {\n\
    \      fill(begin(A[i]), end(A[i]), mint());\n      A[i][pc[i]] = a[i];\n    }\n\
    \    return A;\n  }\n\n  vector<mint> unlift(const vector<fps>& A) {\n    vector<mint>\
    \ a(A.size());\n    for (int i = 0; i < (int)A.size(); i++) a[i] = A[i][pc[i]];\n\
    \    return a;\n  }\n\n  void prod(vector<fps>& A, const vector<fps>& B) {\n \
    \   int n = A.size(), d = __builtin_ctz(n);\n    for (int i = 0; i < n; i++) {\n\
    \      fps c{};\n      for (int j = 0; j <= d; j++) {\n        for (int k = 0;\
    \ k <= d - j; k++) {\n          c[j + k] += A[i][j] * B[i][k];\n        }\n  \
    \    }\n      A[i].swap(c);\n    }\n  }\n\n  vector<mint> multiply(const vector<mint>&\
    \ a, const vector<mint>& b) {\n    vector<fps> A = lift(a), B = lift(b);\n   \
    \ zeta(A), zeta(B);\n    prod(A, B);\n    mobius(A);\n    return unlift(A);\n\
    \  }\n};\n\n/**\n * @brief Subset Convolution\n * @docs docs/set-function/subset-convolution.md\n\
    \ */\n"
  code: "#pragma once\n\n#include <array>\n#include <vector>\nusing namespace std;\n\
    \ntemplate <typename mint, int _s>\nstruct SubsetConvolution {\n  using fps =\
    \ array<mint, _s + 1>;\n  static constexpr int s = _s;\n  vector<int> pc;\n\n\
    \  SubsetConvolution() : pc(1 << s) {\n    for (int i = 1; i < (1 << s); i++)\
    \ pc[i] = pc[i - (i & -i)] + 1;\n  }\n\n  void add(fps& l, const fps& r, int d)\
    \ {\n    for (int i = 0; i < d; ++i) l[i] += r[i];\n  }\n\n  void sub(fps& l,\
    \ const fps& r, int d) {\n    for (int i = d; i <= s; ++i) l[i] -= r[i];\n  }\n\
    \n  void zeta(vector<fps>& a) {\n    int n = a.size();\n    for (int w = 1; w\
    \ < n; w *= 2) {\n      for (int k = 0; k < n; k += w * 2) {\n        for (int\
    \ i = 0; i < w; ++i) {\n          add(a[k + w + i], a[k + i], pc[k + w + i]);\n\
    \        }\n      }\n    }\n  }\n\n  void mobius(vector<fps>& a) {\n    int n\
    \ = a.size();\n    for (int w = n >> 1; w; w >>= 1) {\n      for (int k = 0; k\
    \ < n; k += w * 2) {\n        for (int i = 0; i < w; ++i) {\n          sub(a[k\
    \ + w + i], a[k + i], pc[k + w + i]);\n        }\n      }\n    }\n  }\n\n  vector<fps>\
    \ lift(const vector<mint>& a) {\n    vector<fps> A(a.size());\n    for (int i\
    \ = 0; i < (int)a.size(); i++) {\n      fill(begin(A[i]), end(A[i]), mint());\n\
    \      A[i][pc[i]] = a[i];\n    }\n    return A;\n  }\n\n  vector<mint> unlift(const\
    \ vector<fps>& A) {\n    vector<mint> a(A.size());\n    for (int i = 0; i < (int)A.size();\
    \ i++) a[i] = A[i][pc[i]];\n    return a;\n  }\n\n  void prod(vector<fps>& A,\
    \ const vector<fps>& B) {\n    int n = A.size(), d = __builtin_ctz(n);\n    for\
    \ (int i = 0; i < n; i++) {\n      fps c{};\n      for (int j = 0; j <= d; j++)\
    \ {\n        for (int k = 0; k <= d - j; k++) {\n          c[j + k] += A[i][j]\
    \ * B[i][k];\n        }\n      }\n      A[i].swap(c);\n    }\n  }\n\n  vector<mint>\
    \ multiply(const vector<mint>& a, const vector<mint>& b) {\n    vector<fps> A\
    \ = lift(a), B = lift(b);\n    zeta(A), zeta(B);\n    prod(A, B);\n    mobius(A);\n\
    \    return unlift(A);\n  }\n};\n\n/**\n * @brief Subset Convolution\n * @docs\
    \ docs/set-function/subset-convolution.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: set-function/subset-convolution.hpp
  requiredBy:
  - set-function/polynomial-composite-set-power-series.hpp
  - set-function/exp-of-set-power-series.hpp
  timestamp: '2023-05-27 23:17:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-polynomial-composite-set-power-series.test.cpp
  - verify/verify-yosupo-math/yosupo-subset-convolution.test.cpp
  - verify/verify-yosupo-graph/yosupo-exp-of-set-power-series.test.cpp
documentation_of: set-function/subset-convolution.hpp
layout: document
redirect_from:
- /library/set-function/subset-convolution.hpp
- /library/set-function/subset-convolution.hpp.html
title: Subset Convolution
---

## Subset Convolution

### 概要

参考：[wataさんのスライド](https://www.slideshare.net/wata_orz/ss-12131479)　[arxivの論文](https://arxiv.org/pdf/cs/0611101.pdf) [hosさんの関連記事(わかりやすい)](https://hos-lyric.hatenablog.com/entry/2021/01/14/201231)

$\lbrace {1,2,\ldots,n}\rbrace$の全ての部分集合を元とする集合を$[n]$とする。$[n]$上で定義される集合関数$f,g$に対して

$$h(S) = \sum_{T \subseteq S} f(T)g(S \setminus T)$$

を満たす$h$を計算するアルゴリズムをsubset convolutionと呼ぶ。

### 原理

subset convolutionの話をする前に、まずはbitwise or convolutionのアルゴリズムについて説明する。

bitwise or convolutionとは、関数$f,g$に対して

$$h(S) = \sum_{T \cup U = S} f(T)g(U)$$

を満たす関数$h$を計算するアルゴリズムを言う。

このアルゴリズムは高速ゼータ変換・高速メビウス変換を利用して解くことが出来る。$f,g$をゼータ変換して得られる

$$F(S) = \sum_{T \subseteq S} f(T) , G(S) = \sum_{T \subseteq S} g(T)$$

に対して、$F,G$の各点積$H$は

$$H(S) = F(S) G(S) = \sum_{T\subseteq S} A(T) \sum_{U \subseteq S}B(U) $$

$$= \sum_{(T \cup U) \subseteq S} A(T) B(U)$$

を満たすので、$H$をメビウス変換すれば$h$を得る。

このアルゴリズムに一工夫を加えることでsubset convolutionを計算できるようにしたい。(もちろんそのままだと両方1が立っているbitの部分で壊れるので、何らかの情報を加えることでアルゴリズムが上手く回るようにしたい。)

そこで、subset convolutionが$H = F \mid G$かつ$\vert H \vert = \vert F \vert + \vert G \vert$なのに注目して、集合の大きさの情報を加えたランク付き集合関数を考える。すなわち、集合関数$f$を

$$f \leftarrow \sum_{S \in \lbrack n \rbrack} f(S) x^{\vert S \vert}$$

のようにランクの情報を付け加えた状態に置き換える。こうして得られた$f,g$に対してbitwise or convolutionを行うと、得られた結果は

$$h(S) = \sum_{T \mid U = S} f(T) g(U) x ^{\vert T \vert + \vert U \vert}$$

のようにランクの情報が付加されたものになるので、$x^{\vert S \vert}$次の項が求める答えとなる。計算量は$\mathrm{O}(n^2 2^n)$である。

[verify用問題](https://judge.yosupo.jp/problem/subset_convolution) $N=2^{20}$だとSIMDを使わない実装で1.0s程度が相場のようだ。

### 応用

集合関数$f,g$に対して加法を各点和、積をsubset convolutionとして定めると集合関数が環になる。この時、乗法の単位元$1$は$1(\emptyset) = 1, 1(S) = 0(S \neq \emptyset)$を満たす関数になる。

また、集合関数に対してinv,exp,log,sqrtなどを定義して計算することも出来る。計算方法は積の時と同様である。すなわち、$\phi(f)$を計算するには$f$をゼータ変換して、各点について多項式関数での$\phi(F)$を計算した後にメビウス変換で戻せばよい。

### 例題

#### [ARC 105F Lights Out on Connected Graph](https://atcoder.jp/contests/arc105/tasks/arc105_f)

> $N$頂点$M$辺のグラフ$G$が与えられる。頂点$1$から$N$を含む$G$の部分グラフのうち二部グラフであるようなものの個数は？
>
> $N \leq 17$

[Elegia氏(EntropyIncreaser氏)](https://codeforces.com/blog/entry/83535?#comment-709269)のコメントにより日本にSubset Convolutionが広まるきっかけとなった問題である。

まず、$e(S)$を$u,v \in S$である辺の本数と置く。これは$\mathrm{O}(M + N 2^N)$で求まる。

次に、集合関数$f(S)$を「頂点集合$S$に対して、$v \in S$頂点を赤と青に塗り分けて色の異なる頂点同士にのみ辺を貼る組み合わせ」のように置く。すると$F(S)$は、赤く塗る頂点集合を固定することで次の式により求まる。

$$f(S) = \sum_{T \subseteq S} 2^{e(S) - e(T) - e(S \setminus T)}$$

上式は整理すると$T$の式と$T\setminus S$の式の畳み込みの形をしているので$\mathrm{O}(N^2 2^N)$で計算できる。

次に$g(S)$を「($f(S)$の条件) + 連結性を満たすグラフの個数」と置く。すると、$f,g$の母関数$F(S),G(S)$は

$$F(S) = 1 + G(S) + \frac{G^2(S)}{2} + \ldots = e^{G(S)}$$

を満たすので、

$$G(S) = \log F(S)$$

を満たす母関数$G(S)$が答えになるとわかる。

#### [Xmas2020 H](https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h)

(問題概要は省略)

葉にふさわしい集合に対応する集合母関数を$L(S)$とすると、求める数え上げの答えの母関数$F(S)$は

$$F(S) = L(S) + \frac{F^2(S)}{2}$$

と表される。これを変形して

$$ (F(S) - 1) ^ 2 = 1 - 2L(S)$$

になる。ここで$g^2(S)=1-2L(S)$を満たす関数のうち$g(\emptyset)=1$である方を$\sqrt{1-2L(S)}$とおくと、$F(S) = 1 \pm \sqrt{1-2L(S)}$が成り立つことが帰納的に証明できる。よって、$F(\emptyset) = 0$とあわせて

$$F(S) = 1 - \sqrt{1 - 2 L(S)}$$

を計算すればよいとわかる。


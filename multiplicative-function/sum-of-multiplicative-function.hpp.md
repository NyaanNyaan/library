---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-sum-of-totient.test.cpp
    title: verify/verify-yosupo-math/yosupo-sum-of-totient.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/multiplicative-function/sum-of-multiplicative-function.md
    document_title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306E\u548C"
    links: []
  bundledCode: "#line 2 \"multiplicative-function/sum-of-multiplicative-function.hpp\"\
    \n\n\n\ntemplate <typename T>\nT sum_of_totient(long long N) {\n  if (N < 2) return\
    \ N;\n  using i64 = long long;\n\n  auto f = [](i64 v, i64 p, i64) -> i64 { return\
    \ v / p * (p - 1); };\n  vector<i64> ns{0}, p;\n  for (i64 i = N; i > 0; i = N\
    \ / (N / i + 1)) ns.push_back(i);\n  i64 s = ns.size(), sq = sqrt(N);\n  auto\
    \ idx = [&](i64 n) { return n <= sq ? s - n : N / n; };\n\n  vector<T> h0(s),\
    \ h1(s), buf(s);\n  for (int i = 0; i < s; i++) {\n    T x = ns[i];\n    h0[i]\
    \ = x - 1;\n    h1[i] = x * (x + 1) / 2 - 1;\n  }\n\n  for (i64 x = 2; x <= sq;\
    \ ++x) {\n    if (h0[s - x] == h0[s - x + 1]) continue;\n    p.push_back(x);\n\
    \    i64 x2 = x * x;\n    for (i64 i = 1, n = ns[i]; i < s && n >= x2; n = ns[++i])\
    \ {\n      int id = (i * x <= sq ? i * x : s - n / x);\n      h0[i] -= h0[id]\
    \ - h0[s - x + 1];\n      h1[i] -= (h1[id] - h1[s - x + 1]) * x;\n    }\n  }\n\
    \n  for (int i = 0; i < s; i++) buf[i] = h1[i] - h0[i];\n  T ans = buf[idx(N)]\
    \ + 1;\n\n  auto dfs = [&](auto rec, int i, int c, i64 v, i64 lim, T cur) -> void\
    \ {\n    ans += cur * f(p[i] * v, p[i], c + 1);\n    if (lim >= p[i] * p[i]) rec(rec,\
    \ i, c + 1, p[i] * v, lim / p[i], cur);\n    cur *= f(v, p[i], c);\n    ans +=\
    \ cur * (buf[idx(lim)] - buf[idx(p[i])]);\n    for (int j = i + 1; j < (int)p.size()\
    \ && p[j] * p[j] <= lim; j++) {\n      rec(rec, j, 1, p[j], lim / p[j], cur);\n\
    \    }\n  };\n\n  for (int i = 0; i < (int)p.size(); i++) dfs(dfs, i, 1, p[i],\
    \ N / p[i], 1);\n  return ans;\n}\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570\
    \u306E\u548C\n * @docs docs/multiplicative-function/sum-of-multiplicative-function.md\n\
    \ */\n"
  code: "#pragma once\n\n\n\ntemplate <typename T>\nT sum_of_totient(long long N)\
    \ {\n  if (N < 2) return N;\n  using i64 = long long;\n\n  auto f = [](i64 v,\
    \ i64 p, i64) -> i64 { return v / p * (p - 1); };\n  vector<i64> ns{0}, p;\n \
    \ for (i64 i = N; i > 0; i = N / (N / i + 1)) ns.push_back(i);\n  i64 s = ns.size(),\
    \ sq = sqrt(N);\n  auto idx = [&](i64 n) { return n <= sq ? s - n : N / n; };\n\
    \n  vector<T> h0(s), h1(s), buf(s);\n  for (int i = 0; i < s; i++) {\n    T x\
    \ = ns[i];\n    h0[i] = x - 1;\n    h1[i] = x * (x + 1) / 2 - 1;\n  }\n\n  for\
    \ (i64 x = 2; x <= sq; ++x) {\n    if (h0[s - x] == h0[s - x + 1]) continue;\n\
    \    p.push_back(x);\n    i64 x2 = x * x;\n    for (i64 i = 1, n = ns[i]; i <\
    \ s && n >= x2; n = ns[++i]) {\n      int id = (i * x <= sq ? i * x : s - n /\
    \ x);\n      h0[i] -= h0[id] - h0[s - x + 1];\n      h1[i] -= (h1[id] - h1[s -\
    \ x + 1]) * x;\n    }\n  }\n\n  for (int i = 0; i < s; i++) buf[i] = h1[i] - h0[i];\n\
    \  T ans = buf[idx(N)] + 1;\n\n  auto dfs = [&](auto rec, int i, int c, i64 v,\
    \ i64 lim, T cur) -> void {\n    ans += cur * f(p[i] * v, p[i], c + 1);\n    if\
    \ (lim >= p[i] * p[i]) rec(rec, i, c + 1, p[i] * v, lim / p[i], cur);\n    cur\
    \ *= f(v, p[i], c);\n    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);\n    for\
    \ (int j = i + 1; j < (int)p.size() && p[j] * p[j] <= lim; j++) {\n      rec(rec,\
    \ j, 1, p[j], lim / p[j], cur);\n    }\n  };\n\n  for (int i = 0; i < (int)p.size();\
    \ i++) dfs(dfs, i, 1, p[i], N / p[i], 1);\n  return ans;\n}\n\n/**\n * @brief\
    \ \u4E57\u6CD5\u7684\u95A2\u6570\u306E\u548C\n * @docs docs/multiplicative-function/sum-of-multiplicative-function.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: multiplicative-function/sum-of-multiplicative-function.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-sum-of-totient.test.cpp
documentation_of: multiplicative-function/sum-of-multiplicative-function.hpp
layout: document
redirect_from:
- /library/multiplicative-function/sum-of-multiplicative-function.hpp
- /library/multiplicative-function/sum-of-multiplicative-function.hpp.html
title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306E\u548C"
---

## 乗法的関数の和

乗法的関数のprefix sumを$\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$で求めるアルゴリズムを実装したライブラリ。
(ただし、素数$p$について$f(p)=g(p)$を満たす多項式が存在するとする。)

実装例ではトーシェント関数$\phi(N)$を計算しているが、適切に書き換えることで条件を満たす乗法的関数に適用できる。

#### アルゴリズムの概要

前計算として$S(N) = \sum_{i=1}^N f(i)$を求めるアルゴリズムを以下に説明する。

まず初めに、$1\leq k\leq N$に対して

$$S_p(\left\lfloor \frac{N}{k} \right\rfloor) = \sum_{p\ \mathrm{is}\ \mathrm{prime},1\leq p\leq \left\lfloor \frac{N}{k} \right\rfloor} f(p)$$

を列挙したい。$p$が素数の時$f(p)$は多項式なので、$p$の次数ごとに分解すると$f(N)$は

$$S_c(N) = \sum_{p\ \mathrm{is}\ \mathrm{prime},1\leq p\leq N} p^c$$

の線形和で表すことが出来る。$S_c(\lfloor \frac{N}{k} \rfloor)$は[素数カウント](https://nyaannyaan.github.io/library/library/multiplicative-function/prime-counting.hpp.html)のアルゴリズムを一般的に拡張した方法で高速に求められる。(素数カウントの時に求めた$\pi(n)$は$c=0$の時の場合でると言える。)

$f(x,n) :=$ ($n$以下の自然数のうち$x$以下の素数を因数に持たない整数$p$に対する$p^c$の和)

とおくと$x$が素数の時に

$$f(x,n) = f(x - 1, n) - f(x-1,\left\lfloor\frac{n}{x}\right\rfloor)x^c$$

が成り立つ。ここで$n < x$のとき$f(x,n) = f(x-1,n)$、$x \leq n < x^2$のとき$f(x,n) = f(x-1,n) - x^c$となることを利用して$g(x,n) = f(x, n) + S_c(\min(x,n))$とおくと、$x$が素数の時に

$$g(x,n) = \begin{cases} g(x-1,n) & \mathrm{if}\ n < x^2 \\ g(x-1,n) - \lbrace g(x-1,\lfloor\frac{n}{x}\rfloor) - S_c(x-1) - 1 \rbrace x^c& \mathrm{otherwise} \end{cases}$$

となる。$S_c(\lfloor\sqrt{N}\rfloor,N)=g(\lfloor\sqrt{N}\rfloor,N)-1$であるから$h(x,n)=g(x,n)-1$と補正すると

$$S_c(N) = h(\lfloor\sqrt{N}\rfloor,N)$$

$$h(0,n) = -1 + \sum_{0 \leq m \leq n}m^c$$

$$h(x,n) = \begin{cases} h(x-1,n) & \mathrm{if}\ x\ \mathrm{is}\ \mathrm{not}\  \mathrm{prime}\ \cup\ n < x^2 \\ h(x-1,n) - \lbrace h(x-1,\lfloor\frac{n}{x}\rfloor) - S_c(x-1) \rbrace x^c& \mathrm{otherwise} \end{cases}$$

を得る。(なお、$S_c(x-1)=h(x-1,x-1)$である。)以上より、素数カウントと同様のアルゴリズムでDPを行うことで$\mathrm{O}(\frac{N^\frac{3}{4}}{\log N})$あるいは$\mathrm{O}(N^\frac{2}{3})$を達成できる。

以上に説明したアルゴリズムによって$S_p(\left\lfloor \frac{N}{k} \right\rfloor)$を計算することが出来た。$S_p(\left\lfloor\frac{N}{k}\right\rfloor)$から$S(N)$を求めるアルゴリズムには洲閣篩(Zhouge sieve)や[min_25篩](https://min-25.hatenablog.com/entry/2018/11/11/172216)などが有名だが、ここではBlack Algorithmを用いた解法を説明する。　[参考文献](http://baihacker.github.io/main/2020/The_prefix-sum_of_multiplicative_function_the_black_algorithm.html)

まず、以下の条件を満たす$1$から$N$の頂点ラベルがついた木を考える。
- 頂点$1$を根とする。
- 頂点$n(\neq 1)$の親は$n$の最大の素因数を$p$とした時に$\frac{n}{p}$と表せる。

この木の上をDFSして訪れた頂点$n$に対して$f(n)$を加算するという操作を行うと$S(N)$は計算できるが$\mathrm{O}(N)$かかってしまう。そこで一工夫して、訪れた頂点$n$の子$c$について$f(c)$を計算することを考える。

今、葉でない木上の頂点$n$および$f(n)$が分かっているとする。この時、子の頂点に書かれた数の集合$T$に対して$\sum_{c \in T}f(c)$は以下に説明する方法で高速に計算することが出来る。

- $k$番目に小さい素数を$p_k$と表して、$n$の最大の素因数を$p_i$とおく。すると$n$の子の頂点を小さい順に並べた列は$np_i, np_{i+1},\ldots , np_l$のように表せる。($p_l$は$np_l \leq N$を満たす最大の素数。)また、葉でないという条件から$p_i \leq \sqrt{n}$が従う。
- このうち$n$と$p_{i+1},\ldots,p_{l}$は互いに素であるから、乗法性を利用して

$$\sum_{i+1\leq j\leq l} f(np_{j})=f(n)\sum_{i+1\leq j\leq l} f(p_{j})=f(n)\left(S_p\left(\left\lfloor\frac{N}{n}\right\rfloor\right)-S_p\left(p_i\right)\right)$$

と$S_p$を用いて高速に計算できる。
- $f(np_i)$は$n=m\cdot p_i^e(\gcd(m,p_i)=1)$と素因数分解すれば個別に計算できる。

以上のアルゴリズムを用いれば、$N$頂点の木の葉でない頂点を適切な情報をもってDFSすることで高速に$S(N)$を求めることが出来る。(実装の際は$n=v\cdot p_i^c$とおいて$(i, c, v, f(v))$の組を引数にするとDFSが書きやすくなる。)

DFSの計算量は葉でないノードの個数に一致して$\mathrm{O}(\frac{N^{\frac{3}{4}}}{\log N})$らしい。(参考文献のリンク先に書いてあるが中国語なので読めていない…)

関連：[yukicoder No.1322 Totient Bound](https://yukicoder.me/problems/no/1322)　$\pi(N)$の列挙と木上のDFSを使うとかなり見通しよく解くことが出来る。[提出](https://yukicoder.me/submissions/595840)

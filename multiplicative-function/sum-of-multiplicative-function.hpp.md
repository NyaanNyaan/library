---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/sum-of-mf.test.cpp
    title: verify/verify-unit-test/sum-of-mf.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1781.test.cpp
    title: verify/verify-yuki/yuki-1781.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/multiplicative-function/sum-of-multiplicative-function.md
    document_title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum"
    links: []
  bundledCode: "#line 2 \"multiplicative-function/sum-of-multiplicative-function.hpp\"\
    \n\n#line 2 \"prime/prime-enumerate.hpp\"\n\n// Prime Sieve {2, 3, 5, 7, 11, 13,\
    \ 17, ...}\nvector<int> prime_enumerate(int N) {\n  vector<bool> sieve(N / 3 +\
    \ 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6\
    \ - d, i++) {\n    if (!sieve[i]) continue;\n    for (int q = p * p / 3, r = d\
    \ * p / 3 + (d * p % 3 == 2), s = 2 * p,\n             qe = sieve.size();\n  \
    \       q < qe; q += r = s - r)\n      sieve[q] = 0;\n  }\n  vector<int> ret{2,\
    \ 3};\n  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i])\
    \ ret.push_back(p);\n  while (!ret.empty() && ret.back() > N) ret.pop_back();\n\
    \  return ret;\n}\n#line 4 \"multiplicative-function/sum-of-multiplicative-function.hpp\"\
    \n\n// f(p, c) : f(p^c) \u306E\u5024\u3092\u8FD4\u3059\ntemplate <typename T,\
    \ T (*f)(long long, long long)>\nstruct mf_prefix_sum {\n  using i64 = long long;\n\
    \n  i64 M, sq, s;\n  vector<int> p;\n  int ps;\n  vector<T> buf;\n  T ans;\n\n\
    \  mf_prefix_sum(i64 m) : M(m) {\n    assert(m < (1LL << 42));\n    sq = sqrt(M);\n\
    \    while (sq * sq > M) sq--;\n    while ((sq + 1) * (sq + 1) <= M) sq++;\n\n\
    \    if (M != 0) {\n      i64 hls = md(M, sq);\n      if (hls != 1 && md(M, hls\
    \ - 1) == sq) hls--;\n      s = hls + sq;\n\n      p = prime_enumerate(sq);\n\
    \      ps = p.size();\n      ans = T{};\n    }\n  }\n\n  // \u7D20\u6570\u306E\
    \u500B\u6570\u95A2\u6570\u306B\u95A2\u3059\u308B\u30C6\u30FC\u30D6\u30EB\n  vector<T>\
    \ pi_table() {\n    if (M == 0) return {};\n    i64 hls = md(M, sq);\n    if (hls\
    \ != 1 && md(M, hls - 1) == sq) hls--;\n\n    vector<i64> hl(hls);\n    for (int\
    \ i = 1; i < hls; i++) hl[i] = md(M, i) - 1;\n\n    vector<int> hs(sq + 1);\n\
    \    iota(begin(hs), end(hs), -1);\n\n    int pi = 0;\n    for (auto& x : p) {\n\
    \      i64 x2 = i64(x) * x;\n      i64 imax = min<i64>(hls, md(M, x2) + 1);\n\
    \      for (i64 i = 1, ix = x; i < imax; ++i, ix += x) {\n        hl[i] -= (ix\
    \ < hls ? hl[ix] : hs[md(M, ix)]) - pi;\n      }\n      for (int n = sq; n >=\
    \ x2; n--) hs[n] -= hs[md(n, x)] - pi;\n      pi++;\n    }\n\n    vector<T> res;\n\
    \    res.reserve(2 * sq + 10);\n    for (auto& x : hl) res.push_back(x);\n   \
    \ for (int i = hs.size(); --i;) res.push_back(hs[i]);\n    assert((int)res.size()\
    \ == s);\n    return res;\n  }\n\n  // \u7D20\u6570\u306E prefix sum \u306B\u95A2\
    \u3059\u308B\u30C6\u30FC\u30D6\u30EB\n  vector<T> prime_sum_table() {\n    if\
    \ (M == 0) return {};\n    i64 hls = md(M, sq);\n    if (hls != 1 && md(M, hls\
    \ - 1) == sq) hls--;\n\n    vector<T> h(s);\n    T inv2 = T{2}.inverse();\n  \
    \  for (int i = 1; i < hls; i++) {\n      T x = md(M, i);\n      h[i] = x * (x\
    \ + 1) * inv2 - 1;\n    }\n    for (int i = 1; i <= sq; i++) {\n      T x = i;\n\
    \      h[s - i] = x * (x + 1) / 2 - 1;\n    }\n\n    for (auto& x : p) {\n   \
    \   T xt = x;\n      T pi = h[s - x + 1];\n      i64 x2 = i64(x) * x;\n      i64\
    \ imax = min<i64>(hls, md(M, x2) + 1);\n      i64 ix = x;\n      for (i64 i =\
    \ 1; i < imax; ++i, ix += x) {\n        h[i] -= ((ix < hls ? h[ix] : h[s - md(M,\
    \ ix)]) - pi) * xt;\n      }\n      for (int n = sq; n >= x2; n--) {\n       \
    \ h[s - n] -= (h[s - md(n, x)] - pi) * xt;\n      }\n    }\n\n    assert((int)h.size()\
    \ == s);\n    return h;\n  }\n\n  void dfs(int i, int c, i64 prod, T cur) {\n\
    \    ans += cur * f(p[i], c + 1);\n    i64 lim = md(M, prod);\n    if (lim >=\
    \ 1LL * p[i] * p[i]) dfs(i, c + 1, p[i] * prod, cur);\n    cur *= f(p[i], c);\n\
    \    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);\n    int j = i + 1;\n    //\
    \ M < 2**42 -> p_j < 2**21 -> (p_j)^3 < 2**63\n    for (; j < ps && 1LL * p[j]\
    \ * p[j] * p[j] <= lim; j++) {\n      dfs(j, 1, prod * p[j], cur);\n    }\n  \
    \  for (; j < ps && 1LL * p[j] * p[j] <= lim; j++) {\n      T sm = f(p[j], 2);\n\
    \      int id1 = idx(md(lim, p[j])), id2 = idx(p[j]);\n      sm += f(p[j], 1)\
    \ * (buf[id1] - buf[id2]);\n      ans += cur * sm;\n    }\n  }\n\n  // fprime\
    \ \u7834\u58CA\u7684\n  T run(vector<T>& fprime) {\n    if (M == 0) return {};\n\
    \    set_buf(fprime);\n    assert((int)buf.size() == s);\n    ans = buf[idx(M)]\
    \ + 1;\n    for (int i = 0; i < ps; i++) dfs(i, 1, p[i], 1);\n    return ans;\n\
    \  }\n\n  i64 md(i64 n, i64 d) { return double(n) / d; }\n  i64 idx(i64 n) { return\
    \ n <= sq ? s - n : md(M, n); }\n  void set_buf(vector<T>& _buf) { swap(buf, _buf);\
    \ }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum\n * @docs\
    \ docs/multiplicative-function/sum-of-multiplicative-function.md\n */\n"
  code: "#pragma once\n\n#include \"../prime/prime-enumerate.hpp\"\n\n// f(p, c) :\
    \ f(p^c) \u306E\u5024\u3092\u8FD4\u3059\ntemplate <typename T, T (*f)(long long,\
    \ long long)>\nstruct mf_prefix_sum {\n  using i64 = long long;\n\n  i64 M, sq,\
    \ s;\n  vector<int> p;\n  int ps;\n  vector<T> buf;\n  T ans;\n\n  mf_prefix_sum(i64\
    \ m) : M(m) {\n    assert(m < (1LL << 42));\n    sq = sqrt(M);\n    while (sq\
    \ * sq > M) sq--;\n    while ((sq + 1) * (sq + 1) <= M) sq++;\n\n    if (M !=\
    \ 0) {\n      i64 hls = md(M, sq);\n      if (hls != 1 && md(M, hls - 1) == sq)\
    \ hls--;\n      s = hls + sq;\n\n      p = prime_enumerate(sq);\n      ps = p.size();\n\
    \      ans = T{};\n    }\n  }\n\n  // \u7D20\u6570\u306E\u500B\u6570\u95A2\u6570\
    \u306B\u95A2\u3059\u308B\u30C6\u30FC\u30D6\u30EB\n  vector<T> pi_table() {\n \
    \   if (M == 0) return {};\n    i64 hls = md(M, sq);\n    if (hls != 1 && md(M,\
    \ hls - 1) == sq) hls--;\n\n    vector<i64> hl(hls);\n    for (int i = 1; i <\
    \ hls; i++) hl[i] = md(M, i) - 1;\n\n    vector<int> hs(sq + 1);\n    iota(begin(hs),\
    \ end(hs), -1);\n\n    int pi = 0;\n    for (auto& x : p) {\n      i64 x2 = i64(x)\
    \ * x;\n      i64 imax = min<i64>(hls, md(M, x2) + 1);\n      for (i64 i = 1,\
    \ ix = x; i < imax; ++i, ix += x) {\n        hl[i] -= (ix < hls ? hl[ix] : hs[md(M,\
    \ ix)]) - pi;\n      }\n      for (int n = sq; n >= x2; n--) hs[n] -= hs[md(n,\
    \ x)] - pi;\n      pi++;\n    }\n\n    vector<T> res;\n    res.reserve(2 * sq\
    \ + 10);\n    for (auto& x : hl) res.push_back(x);\n    for (int i = hs.size();\
    \ --i;) res.push_back(hs[i]);\n    assert((int)res.size() == s);\n    return res;\n\
    \  }\n\n  // \u7D20\u6570\u306E prefix sum \u306B\u95A2\u3059\u308B\u30C6\u30FC\
    \u30D6\u30EB\n  vector<T> prime_sum_table() {\n    if (M == 0) return {};\n  \
    \  i64 hls = md(M, sq);\n    if (hls != 1 && md(M, hls - 1) == sq) hls--;\n\n\
    \    vector<T> h(s);\n    T inv2 = T{2}.inverse();\n    for (int i = 1; i < hls;\
    \ i++) {\n      T x = md(M, i);\n      h[i] = x * (x + 1) * inv2 - 1;\n    }\n\
    \    for (int i = 1; i <= sq; i++) {\n      T x = i;\n      h[s - i] = x * (x\
    \ + 1) / 2 - 1;\n    }\n\n    for (auto& x : p) {\n      T xt = x;\n      T pi\
    \ = h[s - x + 1];\n      i64 x2 = i64(x) * x;\n      i64 imax = min<i64>(hls,\
    \ md(M, x2) + 1);\n      i64 ix = x;\n      for (i64 i = 1; i < imax; ++i, ix\
    \ += x) {\n        h[i] -= ((ix < hls ? h[ix] : h[s - md(M, ix)]) - pi) * xt;\n\
    \      }\n      for (int n = sq; n >= x2; n--) {\n        h[s - n] -= (h[s - md(n,\
    \ x)] - pi) * xt;\n      }\n    }\n\n    assert((int)h.size() == s);\n    return\
    \ h;\n  }\n\n  void dfs(int i, int c, i64 prod, T cur) {\n    ans += cur * f(p[i],\
    \ c + 1);\n    i64 lim = md(M, prod);\n    if (lim >= 1LL * p[i] * p[i]) dfs(i,\
    \ c + 1, p[i] * prod, cur);\n    cur *= f(p[i], c);\n    ans += cur * (buf[idx(lim)]\
    \ - buf[idx(p[i])]);\n    int j = i + 1;\n    // M < 2**42 -> p_j < 2**21 -> (p_j)^3\
    \ < 2**63\n    for (; j < ps && 1LL * p[j] * p[j] * p[j] <= lim; j++) {\n    \
    \  dfs(j, 1, prod * p[j], cur);\n    }\n    for (; j < ps && 1LL * p[j] * p[j]\
    \ <= lim; j++) {\n      T sm = f(p[j], 2);\n      int id1 = idx(md(lim, p[j])),\
    \ id2 = idx(p[j]);\n      sm += f(p[j], 1) * (buf[id1] - buf[id2]);\n      ans\
    \ += cur * sm;\n    }\n  }\n\n  // fprime \u7834\u58CA\u7684\n  T run(vector<T>&\
    \ fprime) {\n    if (M == 0) return {};\n    set_buf(fprime);\n    assert((int)buf.size()\
    \ == s);\n    ans = buf[idx(M)] + 1;\n    for (int i = 0; i < ps; i++) dfs(i,\
    \ 1, p[i], 1);\n    return ans;\n  }\n\n  i64 md(i64 n, i64 d) { return double(n)\
    \ / d; }\n  i64 idx(i64 n) { return n <= sq ? s - n : md(M, n); }\n  void set_buf(vector<T>&\
    \ _buf) { swap(buf, _buf); }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570\
    \u306Eprefix sum\n * @docs docs/multiplicative-function/sum-of-multiplicative-function.md\n\
    \ */\n"
  dependsOn:
  - prime/prime-enumerate.hpp
  isVerificationFile: false
  path: multiplicative-function/sum-of-multiplicative-function.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1781.test.cpp
  - verify/verify-yosupo-math/yosupo-sum-of-totient-2.test.cpp
  - verify/verify-unit-test/sum-of-mf.test.cpp
documentation_of: multiplicative-function/sum-of-multiplicative-function.hpp
layout: document
redirect_from:
- /library/multiplicative-function/sum-of-multiplicative-function.hpp
- /library/multiplicative-function/sum-of-multiplicative-function.hpp.html
title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum"
---

## 乗法的関数の和

乗法的関数 $f(p)$ のprefix sum 

$$S(N) = \sum_{i=1}^N f(i)$$

を $\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$ で求めるアルゴリズムを実装したライブラリ。

ただし、素数 $p$ について $f(p)=g(p)$ を満たす多項式 $g(p)$ が存在するとする。

- 追記： $g(p)$ は多項式である必要はなく、 $\sum_{i} g(i)$ が高速に計算できれば上手くいくようだ。[参考](https://twitter.com/maspy_stars/status/1495101747781517313)
 
#### アルゴリズムの概要

前計算として 

$$S_p(n) = \sum_{p \leq n | p : \mathrm{prime}} f(i)$$

を $n = k, \left\lfloor \frac{N}{k} \right\rfloor$ $(1\leq k\leq N)$ に対して列挙するアルゴリズムを以下に説明する。

$p$ が素数の時 $f(p)$ は多項式なので、 $p$ の次数ごとに分解すると $f(N)$ は

$$S_c(N) = \sum_{p\leq N | p : \mathrm{prime}} p^c$$

の線形和で表すことが出来る。 $S_c(\lfloor \frac{N}{k} \rfloor)$ は[素数カウント](https://nyaannyaan.github.io/library/library/multiplicative-function/prime-counting.hpp.html)のアルゴリズム (いわゆる Lucy DP) を一般的に拡張した方法で高速に求められる。(素数カウントの時に求めた $\pi(n)$ は $c=0$ の時の場合であると言える。)

- $f(x,n) :=$ ( $n$ 以下の自然数のうち $x$ 以下の素数を因数に持たない整数 $p$ に対する $p^c$ の和)

とおくと $x$ が素数の時に

$$f(x,n) = f(x - 1, n) - f(x-1,\left\lfloor\frac{n}{x}\right\rfloor)x^c$$

が成り立つ。ここで $n < x$ のとき $f(x,n) = f(x-1,n)$ 、$x \leq n < x^2$ のとき$ f(x,n) = f(x-1,n) - x^c$ となることを利用して $g(x,n) = f(x, n) + S_c(\min(x,n))$ とおくと、 $x$ が素数の時に

$$g(x,n) = \begin{cases} g(x-1,n) & \mathrm{if}\ n < x^2 \\ g(x-1,n) - \lbrace g(x-1,\lfloor\frac{n}{x}\rfloor) - S_c(x-1) - 1 \rbrace x^c& \mathrm{otherwise} \end{cases}$$

となる。 

$$S_c(\lfloor\sqrt{N}\rfloor,N)=g(\lfloor\sqrt{N}\rfloor,N)-1$$ 

であるから $h(x,n)=g(x,n)-1$ と補正すると

$$
\begin{aligned}
S_c(N) &= h(\lfloor\sqrt{N}\rfloor,N)\\
h(0,n) &= -1 + \sum_{0 \leq m \leq n}m^c
\end{aligned}\\
h(x,n) = \begin{cases} h(x-1,n) & \mathrm{if}\ x\ \mathrm{is}\ \mathrm{not}\  \mathrm{prime}\ \cup\ n < x^2 \\ h(x-1,n) - \lbrace h(x-1,\lfloor\frac{n}{x}\rfloor) - S_c(x-1) \rbrace x^c& \mathrm{otherwise} \end{cases}
$$

を得る。(なお、 $S_c(x-1)=h(x-1,x-1)$ である。)以上より、素数カウントと同様のアルゴリズムで DP を行うことで $\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$ で前計算ができる。

以上に説明したアルゴリズムによって $S_p(\left\lfloor \frac{N}{k} \right\rfloor)$ を列挙することが出来た。$S_p(\left\lfloor\frac{N}{k}\right\rfloor)$ から $S(N)$ を求めるアルゴリズムには洲閣篩(Zhouge sieve) や [min_25篩](https://min-25.hatenablog.com/entry/2018/11/11/172216) などが知られているが、ここでは Black Algorithm を用いた解法を説明する。 [参考文献](http://baihacker.github.io/main/2020/The_prefix-sum_of_multiplicative_function_the_black_algorithm.html)

まず、以下の条件を満たす $1$ から $N$ の頂点ラベルがついた木を考える。
- 頂点 $1$ を根とする。
- 頂点 $n(\neq 1)$ の親は $n$ の最大の素因数を $p$ とした時に $\frac{n}{p}$ と表せる。

この木の上を DFS して訪れた頂点 $n$ に対して $f(n)$ を加算するという操作を行うと $S(N)$ は計算できるが $\mathrm{O}(N)$ かかってしまう。そこで一工夫して、訪れた頂点 $n$ の子 $c$ について $f(c)$ を計算することを考える。

今、葉でない木上の頂点 $n$ および $f(n)$ が分かっているとする。この時、子の頂点に書かれた数の集合 $T$ に対して $\sum_{c \in T}f(c)$ は以下に説明する方法で高速に計算することが出来る。

- $k$ 番目に小さい素数を $p_k$ と表して、$n$ の最大の素因数を $p_i$ とおく。すると $n$ の子の頂点を小さい順に並べた列は $np_i, np_{i+1}, \ldots, np_l$ のように表せる。($p_l$ は $np_l \leq N$ を満たす最大の素数) また、葉でないという条件から $p_i \leq \sqrt{n}$ が従う。
- このうち $n$ と $p_{i+1},\ldots,p_{l}$ は互いに素であるから、乗法性を利用して

$$\sum_{i+1\leq j\leq l} f(np_{j})=f(n)\sum_{i+1\leq j\leq l} f(p_{j})=f(n)\left(S_p\left(\left\lfloor\frac{N}{n}\right\rfloor\right)-S_p\left(p_i\right)\right)$$

と $S_p$ を用いて高速に計算できる。
-  $f(np_i)$ は $n=m\cdot p_i^e(\gcd(m,p_i)=1)$ と素因数分解すれば個別に計算できる。

以上のアルゴリズムを用いれば、$N$ 頂点の木の葉でない頂点を適切な情報をもってDFSすることで高速に $S(N)$ を求めることが出来る。

DFS の計算量は葉でないノードの個数に一致して $\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$ らしい。(参考文献のリンク先に書いてあるが中国語なので読めていない…) 以上より $S(N)$ を全体で $\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$ で求めることができた。

関連：[yukicoder No.1322 Totient Bound](https://yukicoder.me/problems/no/1322) $\pi(N)$ の列挙と木上の DFS を使うとかなり見通しよく解くことが出来る。[提出](https://yukicoder.me/submissions/595840)

ライブラリの使い方は verify のコードを適宜参照のこと。

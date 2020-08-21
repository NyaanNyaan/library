---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: 乗法的関数の和 <small>(math/sum-of-multiplicative-function.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/sum-of-multiplicative-function.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-22 00:42:49+09:00





## 乗法的関数の和

乗法的関数のprefix sumを$\mathrm{O}\left(\frac{N^{\frac{3}{4}}}{\log N}\right)$で求めるアルゴリズムを実装したライブラリ。
(ただし、素数$p$について$f(p)=g(p)$を満たす多項式が存在するとする。)

実装例ではトーシェント関数$\phi(N)$を計算しているが、適切に書き換えることで条件を満たす乗法的関数に適用できる。

#### 乗法的関数

$f(n)$が任意の$\gcd(a,b) = 1$である自然数$a,b$に対して$f(ab) = f(a)f(b)$となる時、$f(n)$は乗法的であると呼ぶ。特に任意の$a,b$について$f(ab)=f(a)f(b)$が成り立つ時は完全乗法的であると呼ぶ。代表的なものを下に挙げる。

TODO:書く

乗法的関数の重要な性質は以下のようなものが挙げられる。

TODO:書く

#### アルゴリズムの概要

前計算として$S(N) = \sum_{i=1}^N f(i)$を求めるアルゴリズムを以下に説明する。

まず初めに、$1\leq k\leq N$に対して

$$S_p(\lfloor \frac{N}{k} \rfloor) = \sum_{p\ \mathrm{is}\ \mathrm{prime},1\leq p\leq \left\lfloor \frac{N}{k} \right\rfloor} f(p)$$

を求めたい。$p$が素数の時$f(p)$は多項式なので、$p$の次数ごとに分解すると$f(N)$は

$$S_c(N) = \sum_{p\ \mathrm{is}\ \mathrm{prime},1\leq p\leq N} p^c$$

の線形和で表すことが出来る。$S_c(\lfloor \frac{N}{k} \rfloor)$は[素数カウント](https://nyaannyaan.github.io/library/library/math/prime-counting.hpp.html)のアルゴリズムを一般的に拡張した方法で高速に求められる。(素数カウントの時に求めた$\pi(n)$は$c=0$の時の場合でると言える。)

$f(x,n) :=$ ($n$以下の自然数のうち$x$以下の素数を因数に持たない整数$p$に対する$p^c$の和)

とおくと$x$が素数の時に

$$f(x,n) = f(x - 1, n) - f(x-1,\lfloor\frac{n}{x}\rfloor)x^c$$

が成り立つ。ここで$n < x$のとき$f(x,n) = f(x-1,n)$、$x \leq n < x^2$のとき$f(x,n) = f(x-1,n) - x^c$となることを利用して$g(x,n) = f(x, n) + S_c(\min(x,n))$とおくと、$x$が素数の時に

$$g(x,n) = \begin{cases} g(x-1,n) & \mathrm{if}\ n < x^2 \newline g(x-1,n) - \lbrace g(x-1,\lfloor\frac{n}{x}\rfloor) - S_c(x-1) - 1 \rbrace x^c& \mathrm{otherwise} \end{cases}$$

となる。$S_c(\lfloor\sqrt{N}\rfloor,N)=g(\lfloor\sqrt{N}\rfloor,N)-1$であるから$h(x,n)=g(x,n)-1$と補正すると

$$S_c(N) = h(\lfloor\sqrt{N}\rfloor,N)$$

$$h(0,n) = -1 + \sum_{0 \leq m \leq n}m^c$$

$$h(x,n) = \begin{cases} h(x-1,n) & \mathrm{if}\ x\ \mathrm{is}\ \mathrm{not}\  \mathrm{prime}\ \cup\ n < x^2 \newline h(x-1,n) - \lbrace h(x-1,\lfloor\frac{n}{x}\rfloor) - S_c(x-1) \rbrace x^c& \mathrm{otherwise} \end{cases}$$

を得る。(なお、$S_c(x-1)=h(x-1,x-1)$である。)以上より、素数カウントと同様のアルゴリズムでDPを行うことで$\mathrm{O}(\frac{N^\frac{3}{4}}{\log N})$あるいは$\mathrm{O}(N^\frac{2}{3})$を達成できる。

TODO:続きを書く [参考文献1](https://min-25.hatenablog.com/entry/2018/11/11/172216) [参考文献2](http://baihacker.github.io/main/2020/The_prefix-sum_of_multiplicative_function_the_black_algorithm.html)


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-sum-of-totient.test.cpp.html">verify/verify-yosupo-math/yosupo-sum-of-totient.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
T sum_of_totient(long long N) {
  if (N < 2) return N;
  using i64 = long long;

  auto f = [](i64 v, i64 p, i64) -> i64 { return v / p * (p - 1); };
  vector<i64> ns{0}, p;
  for (i64 i = N; i > 0; i = N / (N / i + 1)) ns.push_back(i);
  i64 s = ns.size(), sq = sqrt(N);
  auto idx = [&](i64 n) { return n <= sq ? s - n : N / n; };

  vector<T> h0(s), h1(s), buf(s);
  for (int i = 0; i < s; i++) {
    T x = ns[i];
    h0[i] = x - 1;
    h1[i] = x * (x + 1) / 2 - 1;
  }

  for (i64 x = 2; x <= sq; ++x) {
    if (h0[s - x] == h0[s - x + 1]) continue;
    p.push_back(x);
    i64 x2 = x * x;
    for (i64 i = 1, n = ns[i]; i < s && n >= x2; n = ns[++i]) {
      int id = (i * x <= sq ? i * x : s - n / x);
      h0[i] -= h0[id] - h0[s - x + 1];
      h1[i] -= (h1[id] - h1[s - x + 1]) * x;
    }
  }

  for (int i = 0; i < s; i++) buf[i] = h1[i] - h0[i];
  T ans = buf[idx(N)] + 1;

  auto dfs = [&](auto rec, int i, int c, i64 v, i64 lim, T cur) -> void {
    ans += cur * f(p[i] * v, p[i], c + 1);
    if (lim >= p[i] * p[i]) rec(rec, i, c + 1, p[i] * v, lim / p[i], cur);
    cur *= f(v, p[i], c);
    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);
    for (int j = i + 1; j < (int)p.size() && p[j] * p[j] <= lim; j++) {
      rec(rec, j, 1, p[j], lim / p[j], cur);
    }
  };

  for (int i = 0; i < (int)p.size(); i++) dfs(dfs, i, 1, p[i], N / p[i], 1);
  return ans;
}

/**
 * @brief 乗法的関数の和
 * @docs docs/math/sum-of-multiplicative-function.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/sum-of-multiplicative-function.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
T sum_of_totient(long long N) {
  if (N < 2) return N;
  using i64 = long long;

  auto f = [](i64 v, i64 p, i64) -> i64 { return v / p * (p - 1); };
  vector<i64> ns{0}, p;
  for (i64 i = N; i > 0; i = N / (N / i + 1)) ns.push_back(i);
  i64 s = ns.size(), sq = sqrt(N);
  auto idx = [&](i64 n) { return n <= sq ? s - n : N / n; };

  vector<T> h0(s), h1(s), buf(s);
  for (int i = 0; i < s; i++) {
    T x = ns[i];
    h0[i] = x - 1;
    h1[i] = x * (x + 1) / 2 - 1;
  }

  for (i64 x = 2; x <= sq; ++x) {
    if (h0[s - x] == h0[s - x + 1]) continue;
    p.push_back(x);
    i64 x2 = x * x;
    for (i64 i = 1, n = ns[i]; i < s && n >= x2; n = ns[++i]) {
      int id = (i * x <= sq ? i * x : s - n / x);
      h0[i] -= h0[id] - h0[s - x + 1];
      h1[i] -= (h1[id] - h1[s - x + 1]) * x;
    }
  }

  for (int i = 0; i < s; i++) buf[i] = h1[i] - h0[i];
  T ans = buf[idx(N)] + 1;

  auto dfs = [&](auto rec, int i, int c, i64 v, i64 lim, T cur) -> void {
    ans += cur * f(p[i] * v, p[i], c + 1);
    if (lim >= p[i] * p[i]) rec(rec, i, c + 1, p[i] * v, lim / p[i], cur);
    cur *= f(v, p[i], c);
    ans += cur * (buf[idx(lim)] - buf[idx(p[i])]);
    for (int j = i + 1; j < (int)p.size() && p[j] * p[j] <= lim; j++) {
      rec(rec, j, 1, p[j], lim / p[j], cur);
    }
  };

  for (int i = 0; i < (int)p.size(); i++) dfs(dfs, i, 1, p[i], N / p[i], 1);
  return ans;
}

/**
 * @brief 乗法的関数の和
 * @docs docs/math/sum-of-multiplicative-function.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


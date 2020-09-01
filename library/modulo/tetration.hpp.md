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


# :heavy_check_mark: tetration <small>(modulo/tetration.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5dcb4a1ea5a35da52691d50c8313c333">modulo</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulo/tetration.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 02:03:54+09:00




## Tetration

$a \uparrow \uparrow b \mod m$を$\mathrm{O}(\sqrt{M})$で計算するライブラリ。$a \uparrow \uparrow b$とは、

$$a \uparrow \uparrow b =\begin{cases} 1 & \mathrm{if}\ \ b = 0\newline a^{a \uparrow \uparrow (b-1)} & \mathrm{otherwise}\end{cases}$$

として定められる二項演算である。

#### 概要

$a\uparrow \uparrow b$と$a\uparrow \uparrow (b-1)$の関係式を元に再帰的に計算する。

$a$と$m$が互いに素の時は、オイラーの定理$a ^ {\phi(m)}\equiv 1 \mod m$より、

$$a \uparrow \uparrow b \equiv a^{a \uparrow \uparrow (b-1)} \equiv a^{(a \uparrow \uparrow (b-1) \mod \phi(m))} \mod m$$

という関係式を得ることができる。

次に$a$と$m$が互いに素でない場合を考える。$m=kl$を$l$と$a$が互いに素で$k$が$a$の素因数の積で表されるように取る。

この時、$a^i \mod k$は$i$が十分に大きいときに$0$に等しくなり、$a^i \mod l$はオイラーの定理より$\phi(l)$周期を持つ。よって中国剰余定理と合わせて$a^i \mod m$は$i$が十分に大きい時に$\phi(r)$周期になることがわかる。

ここで具体的に$m=kl$を具体的に計算する必要はないことに留意する。というのも、トーシェント関数の乗法性より$a^i \mod m$は$\phi(m)$周期を持つためである。また、$\log_2(m) \leq \phi(m)$ より$a^{\phi(m)} \equiv 0 \mod k$になることから、$i$が$\phi(m)$未満の時は愚直に計算して、それより$i$が大きいときは周期性を利用して計算すればよい。(実装の際は$a\uparrow \uparrow b$が$m$以上かどうかをフラグとして持っておけばよい。)

以上より、$a\uparrow \uparrow b \mod m$は$a\uparrow \uparrow (b-1) \mod \phi(m)$の値から導出できることがわかった。計算量はアルゴリズム全体でのトーシェント関数の計算量に依存するので、計算量を求めるために数列$m,\phi(m),\phi(\phi(m))\ldots$の性質を考察する。

ここで、$m$が偶数の時$\phi(m)$は$\frac{m}{2}$以下になる。また、$m$が奇数の時、$\phi(m)$は偶数なので$\phi(\phi(m))$は$\frac{\phi(m)}{2}$以下になる。以上より、上記の数列は少なくとも$2$個おきに半減して、$\mathrm{O}(\log_2 m)$回で$1$に収束する。よって全体の計算量は$T(m) = \mathrm{O}(\sqrt{m})+T(\frac{m}{2})$を解いて$\mathrm{O}(\sqrt{m})$となる。


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-tetration-mod.test.cpp.html">verify/verify-yosupo-math/yosupo-tetration-mod.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T = uint32_t, typename U = uint64_t, T MAX = 1000000000>
T tetration(uint64_t a, uint64_t b, uint64_t m) {
  auto prime_table = [](T m) -> vector<int> {
    T thres = sqrt(m) + 1;
    vector<bool> flg(thres + 1);
    for (T i = 2; i * i <= thres; ++i) {
      if (!flg[i])
        for (T j = i * i; j <= thres; j += i) flg[j] = 1;
    }
    vector<int> ret;
    for (T i = 2; i <= thres; i++)
      if (!flg[i]) ret.push_back(i);
    return ret;
  };

  static const vector<int> ps = prime_table(MAX);

  auto totient = [&](T n) -> T {
    T ret = n;
    for (auto& p : ps) {
      if (p * p > n) break;
      if (n % p == 0) {
        ret = ret / p * (p - 1);
        while (n % p == 0) n /= p;
      }
    }
    if (n != 1) ret = ret / n * (n - 1);
    return ret;
  };

  auto mpow = [](U a, U p, T m) -> pair<T, int> {
    U ret = 1 % m;
    int flg = true;
    for (; p; p >>= 1) {
      if (p & 1)
        if ((ret *= a) >= m) flg = 0, ret %= m;
      if (p == 1) break;
      if ((a *= a) >= m) flg = 0, a %= m;
    }
    return {ret, flg};
  };

  auto calc = [&](auto rec, T a, U b, T m) -> pair<T, int> {
    if (a == 0) return {!(b & 1), true};
    if (a == 1) return {1, true};
    if (m == 1) return {0, false};
    if (b == 0) return {1, true};
    if (b == 1) return {a % m, a < m};
    T phi_m = totient(m), pre, ret;
    int flg1, flg2;
    tie(pre, flg1) = rec(rec, a, b - 1, phi_m);
    tie(ret, flg2) = mpow(a % m, U(pre) + (flg1 ? 0 : phi_m), m);
    return {ret, flg1 && flg2};
  };

  return calc(calc, a, b, m).first % m;
}

/**
 * @brief tetration
 * @docs docs/modulo/tetration.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modulo/tetration.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T = uint32_t, typename U = uint64_t, T MAX = 1000000000>
T tetration(uint64_t a, uint64_t b, uint64_t m) {
  auto prime_table = [](T m) -> vector<int> {
    T thres = sqrt(m) + 1;
    vector<bool> flg(thres + 1);
    for (T i = 2; i * i <= thres; ++i) {
      if (!flg[i])
        for (T j = i * i; j <= thres; j += i) flg[j] = 1;
    }
    vector<int> ret;
    for (T i = 2; i <= thres; i++)
      if (!flg[i]) ret.push_back(i);
    return ret;
  };

  static const vector<int> ps = prime_table(MAX);

  auto totient = [&](T n) -> T {
    T ret = n;
    for (auto& p : ps) {
      if (p * p > n) break;
      if (n % p == 0) {
        ret = ret / p * (p - 1);
        while (n % p == 0) n /= p;
      }
    }
    if (n != 1) ret = ret / n * (n - 1);
    return ret;
  };

  auto mpow = [](U a, U p, T m) -> pair<T, int> {
    U ret = 1 % m;
    int flg = true;
    for (; p; p >>= 1) {
      if (p & 1)
        if ((ret *= a) >= m) flg = 0, ret %= m;
      if (p == 1) break;
      if ((a *= a) >= m) flg = 0, a %= m;
    }
    return {ret, flg};
  };

  auto calc = [&](auto rec, T a, U b, T m) -> pair<T, int> {
    if (a == 0) return {!(b & 1), true};
    if (a == 1) return {1, true};
    if (m == 1) return {0, false};
    if (b == 0) return {1, true};
    if (b == 1) return {a % m, a < m};
    T phi_m = totient(m), pre, ret;
    int flg1, flg2;
    tie(pre, flg1) = rec(rec, a, b - 1, phi_m);
    tie(ret, flg2) = mpow(a % m, U(pre) + (flg1 ? 0 : phi_m), m);
    return {ret, flg1 && flg2};
  };

  return calc(calc, a, b, m).first % m;
}

/**
 * @brief tetration
 * @docs docs/modulo/tetration.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


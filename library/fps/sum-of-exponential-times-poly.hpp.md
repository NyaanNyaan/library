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


# :heavy_check_mark: $\sum_{i}a^i f(i)$ <small>(fps/sum-of-exponential-times-poly.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/sum-of-exponential-times-poly.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 22:48:29+09:00





## $\sum_{i}a^i f(i)$

#### 問題

$k$次多項式$f(n)$に$f(0),f(1),\ldots,f(k)$を代入したものが与えられる。$\sum_{0\leq i<n}f(i)a^i$を求めよ。

[出題例(codechef)](https://www.codechef.com/problems/QPOLYSUM)

[参考文献(Min氏のブログ)](https://min-25.hatenablog.com/entry/2015/04/24/031413)

#### 概要

以下の説明では、$f(t)$が$k$次の多項式であるとき、$f(t)$の母関数は$\frac{F(x)}{(1-x)^{k+1}}$と表せる事実を利用する。

(証明はニュートン基底$n_i(t)=t(t-1)\cdots(t-i+1)$の母関数が$\frac{i!x^i}{(1-x)^{i+1}}$と表されることが帰納的に示せることと、$f(t)$は$n_0(t)\ldots n_k(t)$の線形和で表せることから従う。)

数列$f(0)a^0, f(1)a^1, \ldots$の母関数は$k$次以下の多項式$G(x)$を用いて$\frac{G(x)}{(1-ax)^{k+1}}$と表せる。この時、求めたいものは

$$[x^{n-1}]\left(\frac{1}{1-x}\cdot \frac{G(x)}{(1-ax)^{k+1}}\right)$$

となる。上の式は定数$c$と$k$次以下の多項式$S(x)$を用いて

$$\frac{G(x)}{(1-x)(1-ax)^{k+1}}=\frac{c}{1-x}+\frac{S(x)}{(1-ax)^{k+1}}$$

と変形できるので、解は$k$次以下の多項式$t(n)$を用いて$c+a^nt(n)$と表せることがわかる。

次に$c$を具体的に求める。$c,G,S$の間には

$$G(x)=c(1-ax)^{k+1}+S(x)(1-x)$$

が成り立つ。多項式なので両辺に$x=1$を代入してもよく、

$$G(1)=c(1-a)^{k+1}$$

を得るので$G(1)$を求めればよい。$G(1)$は

$$G(x) = \left((1-ax)^{k+1}\sum_{i=0}^k f(i)(ax)^i \mod  x^{k+1}\right)$$

の右辺を累積和と階乗の前計算を使って$\mathrm{O}(k)$で計算できる。

$c$が計算できたので、あとは多項式補間を使えば答えが求まる。具体的には、

$$t(i) = a^{-n}\cdot\left(-c + \sum_{j=0}^i f(i)a^i \right)$$

とおいて$t(0),t(1)\ldots t(k)$を計算した後、ラグランジュ補間で$t(n-1)$を$\mathrm{O}(k)$で計算すればよい。

(注：この解法では$a$と$1-a$の逆元が必要なため、$a=0,a=1$の時は場合分けして別に実装する。)


## Depends on

* :heavy_check_mark: <a href="../modulo/binomial.hpp.html">modulo/binomial.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp.html">verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp.html">verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../modulo/binomial.hpp"

// given  : f(0)...f(k) (deg(f) = k), a, n
// return : \sum_{i=0...n-1} a^i f(i)
template <typename mint>
mint sum_of_exp(const vector<mint>& f, mint a, long long n,
                const Binomial<mint>& C) {
  if (n == 0) return mint(0);
  if (a == mint(0)) return f[0];
  if (a == mint(1)) {
    vector<mint> g(f.size() + 1, mint(0));
    for (int i = 1; i < (int)g.size(); i++) g[i] = g[i - 1] + f[i - 1];
    return lagrange_interpolation(g, n, C);
  }
  int K = f.size() - 1;
  vector<mint> g(f.size());
  mint buf = 1;
  for (int i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;
  for (int i = 1; i < (int)g.size(); i++) g[i] += g[i - 1];
  mint c = 0, buf2 = 1;
  for (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *= -a;
  c /= (-a + 1).pow(K + 1);
  mint buf3 = 1, ia = a.inverse();
  for (int i = 0; i < (int)g.size(); i++) g[i] = (g[i] - c) * buf3, buf3 *= ia;
  mint tn = lagrange_interpolation(g, n - 1, C);
  return tn * a.pow(n - 1) + c;
}

// given  : f(0)...f(k) (deg(f) = k), a
// return : \sum_{i=0...infty} a^i f(i)
template <typename mint>
mint sum_of_exp_limit(const vector<mint>& f, mint a, const Binomial<mint>& C) {
  if (a == mint(0)) return f[0];
  int K = f.size() - 1;
  vector<mint> g(f.size());
  mint buf = 1;
  for (int i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;
  for (int i = 1; i < (int)g.size(); i++) g[i] += g[i - 1];
  mint c = 0, buf2 = 1;
  for (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *= -a;
  c /= (-a + 1).pow(K + 1);
  return c;
}

// given  : p, n
// return : (0^p, 1^p, ... , n^p)
template <typename mint>
vector<mint> exp_enamurate(int p, int n) {
  vector<mint> f(n + 1, mint(0));
  if (!p) {
    f[0] = 1;
    return std::move(f);
  }
  f[1] = 1;
  vector<bool> sieve(n + 1, false);
  vector<int> ps;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      f[i] = mint(i).pow(p);
      ps.push_back(i);
    }
    for (int j = 0; j < (int)ps.size() && i * ps[j] <= n; j++) {
      sieve[i * ps[j]] = 1;
      f[i * ps[j]] = f[i] * f[ps[j]];
      if (i % ps[j] == 0) break;
    }
  }
  return std::move(f);
}

// given  : d, r, n
// return : \sum_{i=0...n-1} r^i i^d
template <typename mint>
mint sum_of_exp2(int d, mint r, long long n, const Binomial<mint>& C) {
  vector<mint> f = exp_enamurate<mint>(d, d);
  return sum_of_exp(f, r, n, C);
}

// given  : d, r
// return : \sum_{i=0...infty} r^i i^d
template <typename mint>
mint sum_of_exp_limit2(int d, mint r, const Binomial<mint>& C) {
  vector<mint> f = exp_enamurate<mint>(d, d);
  return sum_of_exp_limit(f, r, C);
}

/**
 * @brief $\sum_{i}a^i f(i)$
 * @docs docs/fps/sum-of-exponential-times-poly.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "fps/sum-of-exponential-times-poly.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 3 "modulo/binomial.hpp"
using namespace std;

template <typename T>
struct Binomial {
  vector<T> fac_, finv_, inv_;
  Binomial(int MAX) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {
    MAX += 9;
    fac_[0] = finv_[0] = inv_[0] = 1;
    for (int i = 1; i <= MAX; i++) fac_[i] = fac_[i - 1] * i;
    finv_[MAX] = fac_[MAX].inverse();
    for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);
    for (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];
  }

  inline T fac(int i) const { return fac_[i]; }
  inline T finv(int i) const { return finv_[i]; }
  inline T inv(int i) const { return inv_[i]; }

  T C(int n, int r) const {
    if (n < r || r < 0) return T(0);
    return fac_[n] * finv_[n - r] * finv_[r];
  }

  T C_naive(int n, int r) const {
    if (n < r || r < 0) return T(0);
    T ret = 1;
    for (T i = 1; i <= r; i += T(1)) {
      ret *= n--;
      ret *= i.inverse();
    }
    return ret;
  }

  T P(int n, int r) const {
    if (n < r || r < 0) return T(0);
    return fac_[n] * finv_[n - r];
  }

  T H(int n, int r) const {
    if (n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
#line 6 "fps/sum-of-exponential-times-poly.hpp"

// given  : f(0)...f(k) (deg(f) = k), a, n
// return : \sum_{i=0...n-1} a^i f(i)
template <typename mint>
mint sum_of_exp(const vector<mint>& f, mint a, long long n,
                const Binomial<mint>& C) {
  if (n == 0) return mint(0);
  if (a == mint(0)) return f[0];
  if (a == mint(1)) {
    vector<mint> g(f.size() + 1, mint(0));
    for (int i = 1; i < (int)g.size(); i++) g[i] = g[i - 1] + f[i - 1];
    return lagrange_interpolation(g, n, C);
  }
  int K = f.size() - 1;
  vector<mint> g(f.size());
  mint buf = 1;
  for (int i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;
  for (int i = 1; i < (int)g.size(); i++) g[i] += g[i - 1];
  mint c = 0, buf2 = 1;
  for (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *= -a;
  c /= (-a + 1).pow(K + 1);
  mint buf3 = 1, ia = a.inverse();
  for (int i = 0; i < (int)g.size(); i++) g[i] = (g[i] - c) * buf3, buf3 *= ia;
  mint tn = lagrange_interpolation(g, n - 1, C);
  return tn * a.pow(n - 1) + c;
}

// given  : f(0)...f(k) (deg(f) = k), a
// return : \sum_{i=0...infty} a^i f(i)
template <typename mint>
mint sum_of_exp_limit(const vector<mint>& f, mint a, const Binomial<mint>& C) {
  if (a == mint(0)) return f[0];
  int K = f.size() - 1;
  vector<mint> g(f.size());
  mint buf = 1;
  for (int i = 0; i < (int)g.size(); i++) g[i] = f[i] * buf, buf *= a;
  for (int i = 1; i < (int)g.size(); i++) g[i] += g[i - 1];
  mint c = 0, buf2 = 1;
  for (int i = 0; i <= K; i++) c += C.C(K + 1, i) * buf2 * g[K - i], buf2 *= -a;
  c /= (-a + 1).pow(K + 1);
  return c;
}

// given  : p, n
// return : (0^p, 1^p, ... , n^p)
template <typename mint>
vector<mint> exp_enamurate(int p, int n) {
  vector<mint> f(n + 1, mint(0));
  if (!p) {
    f[0] = 1;
    return std::move(f);
  }
  f[1] = 1;
  vector<bool> sieve(n + 1, false);
  vector<int> ps;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      f[i] = mint(i).pow(p);
      ps.push_back(i);
    }
    for (int j = 0; j < (int)ps.size() && i * ps[j] <= n; j++) {
      sieve[i * ps[j]] = 1;
      f[i * ps[j]] = f[i] * f[ps[j]];
      if (i % ps[j] == 0) break;
    }
  }
  return std::move(f);
}

// given  : d, r, n
// return : \sum_{i=0...n-1} r^i i^d
template <typename mint>
mint sum_of_exp2(int d, mint r, long long n, const Binomial<mint>& C) {
  vector<mint> f = exp_enamurate<mint>(d, d);
  return sum_of_exp(f, r, n, C);
}

// given  : d, r
// return : \sum_{i=0...infty} r^i i^d
template <typename mint>
mint sum_of_exp_limit2(int d, mint r, const Binomial<mint>& C) {
  vector<mint> f = exp_enamurate<mint>(d, d);
  return sum_of_exp_limit(f, r, C);
}

/**
 * @brief $\sum_{i}a^i f(i)$
 * @docs docs/fps/sum-of-exponential-times-poly.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


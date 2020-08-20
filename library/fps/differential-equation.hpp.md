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


# :x: 常微分方程式 <small>(fps/differential-equation.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/differential-equation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-20 12:22:55+09:00




## 常微分方程式

$$\frac{d}{dx}f \equiv F(f) \mod x^n,\ f(0) = f_0$$

を満たす形式的冪級数$f$をダブリングを利用して$\mathrm{O}(N \log N)$で求めるアルゴリズム。($F$は$\mathrm{O}(k \log k)$で$\mod x^k$まで計算できる関数とする。)

[出典(codeforces)](https://codeforces.com/blog/entry/76447)　調べてみると中国のブログに記述が散見されることから、中国では比較的一般的なテクニックのようである。

#### 概要

$\hat{f} \equiv f \mod x^k$が求まっているとき$f \mod x^{2k}$と$\hat{f}$の関係式を導出する。

$F(f)$の$f=\hat{f}$におけるテイラー展開の式

$$F(f) = \sum_{k=0}^\infty \frac{F^{(k)}(\hat{f})}{k!}(f-\hat{f})^k$$

は$f - \hat{f} \equiv 0 \mod x$なので形式的冪級数に適用できる。

$$\frac{d}{dx}f \equiv F(f) \equiv \sum_{k=0}^\infty \frac{F^{(k)}(\hat{f})}{k!}(f-\hat{f})^k \mod x^{2k}$$

$(f-\hat{f})^2 \equiv 0 \mod x^{2k}$を利用して

$$\frac{d}{dx}f \equiv F(\hat{f}) +F'(\hat{f})(f-\hat{f}) \mod x^{2k} \cdots (\ast)$$

を得る。ここで、

$$r \equiv e^{-\int F'(\hat{f})dx} \mod x^{2k}$$

とおくと、

$$\frac{d}{dx}r\equiv e^{-\int F'(\hat{f})dx}\cdot (-F'(\hat{f}))=-F'(\hat{f})r\mod x^{2k-1}$$

となる。$(\ast)$を変形して両辺に$r$を掛けると

$$\frac{d}{dx}f\cdot r -F'(\hat{f})f\cdot r\equiv (F(\hat{f}) -F'(\hat{f})\hat{f})\cdot r \mod x^{2k-1}$$

であるが、左辺は$\frac{d}{dx}(f\cdot r)$に等しいので、両辺を積分すると

$$f\cdot r \equiv \int \left( \left(F(\hat{f}) -F'(\hat{f})\hat{f}\right)\cdot r\right)dx + C \mod x^{2k}$$

となり、$r(0) = 1$より両辺の定数項を比較して$C=f_0$が従う。以上より$f$と$\hat{f}$の関係式として次の式を得る。

$$f\equiv r^{-1}\left( \int \left( \left(F(\hat{f}) -F'(\hat{f})\hat{f}\right)\cdot r\right)dx + f_0\right) \mod x^{2k}$$

この式を利用して初項を$f \equiv f_0 \mod x$としたダブリングを行うことで、常微分方程式を$\mathrm{O}(N \log N)$で計算できる。

なお、低速なexp/invを使用している場合は(計算量の劣る)分割統治FFTの方が高速に動作するようである。


## Depends on

* :question: <a href="formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>


## Verified with

* :x: <a href="../../verify/verify/verify-yuki/yuki-0963.test.cpp.html">verify/verify-yuki/yuki-0963.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "formal-power-series.hpp"

// find f, saitsfying equation f' = g(f) mod x ^ deg
template <typename mint>
FormalPowerSeries<mint> DifferentialEquation(
    function<FormalPowerSeries<mint>(FormalPowerSeries<mint>, int)> g,
    function<FormalPowerSeries<mint>(FormalPowerSeries<mint>, int)> gprime,
    mint f0, int deg) {
  using fps = FormalPowerSeries<mint>;
  fps f{f0};
  for (int i = 1; i < deg; i <<= 1) {
    fps r = (-gprime(f, i << 1)).integral().exp(i << 1);
    fps h = ((g(f, i << 1) - gprime(f, i << 1) * f) * r).pre(i << 1).integral();
    f = ((h + f0) * r.inv(i << 1)).pre(i << 1);
  }
  return f.pre(deg);
}

/**
 * @brief 常微分方程式
 * @docs docs/fps/differential-equation.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "fps/formal-power-series.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename mint>
struct FormalPowerSeries : vector<mint> {
  using vector<mint>::vector;
  using FPS = FormalPowerSeries;

  FPS &operator+=(const FPS &r) {
    if (r.size() > this->size()) this->resize(r.size());
    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];
    return *this;
  }

  FPS &operator+=(const mint &r) {
    if (this->empty()) this->resize(1);
    (*this)[0] += r;
    return *this;
  }

  FPS &operator-=(const FPS &r) {
    if (r.size() > this->size()) this->resize(r.size());
    for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];
    return *this;
  }

  FPS &operator-=(const mint &r) {
    if (this->empty()) this->resize(1);
    (*this)[0] -= r;
    return *this;
  }

  FPS &operator*=(const mint &v) {
    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;
    return *this;
  }

  FPS &operator/=(const FPS &r) {
    if (this->size() < r.size()) {
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();
  }

  FPS &operator%=(const FPS &r) {
    *this -= *this / r * r;
    shrink();
    return *this;
  }

  FPS operator+(const FPS &r) const { return FPS(*this) += r; }
  FPS operator+(const mint &v) const { return FPS(*this) += v; }
  FPS operator-(const FPS &r) const { return FPS(*this) -= r; }
  FPS operator-(const mint &v) const { return FPS(*this) -= v; }
  FPS operator*(const FPS &r) const { return FPS(*this) *= r; }
  FPS operator*(const mint &v) const { return FPS(*this) *= v; }
  FPS operator/(const FPS &r) const { return FPS(*this) /= r; }
  FPS operator%(const FPS &r) const { return FPS(*this) %= r; }
  FPS operator-() const {
    FPS ret(this->size());
    for (int i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  void shrink() {
    while (this->size() && this->back() == mint(0)) this->pop_back();
  }

  FPS rev() const {
    FPS ret(*this);
    reverse(begin(ret), end(ret));
    return ret;
  }

  FPS dot(FPS r) const {
    FPS ret(min(this->size(), r.size()));
    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];
    return ret;
  }

  FPS pre(int sz) const {
    return FPS(begin(*this), begin(*this) + min((int)this->size(), sz));
  }

  FPS operator>>(int sz) const {
    if ((int)this->size() <= sz) return {};
    FPS ret(*this);
    ret.erase(ret.begin(), ret.begin() + sz);
    return ret;
  }

  FPS operator<<(int sz) const {
    FPS ret(*this);
    ret.insert(ret.begin(), sz, mint(0));
    return ret;
  }

  FPS diff() const {
    const int n = (int)this->size();
    FPS ret(max(0, n - 1));
    mint one(1), coeff(1);
    for (int i = 1; i < n; i++) {
      ret[i - 1] = (*this)[i] * coeff;
      coeff += one;
    }
    return ret;
  }

  FPS integral() const {
    const int n = (int)this->size();
    FPS ret(n + 1);
    ret[0] = mint(0);
    if (n > 0) ret[1] = mint(1);
    auto mod = mint::get_mod();
    for (int i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);
    for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];
    return ret;
  }

  mint eval(mint x) const {
    mint r = 0, w = 1;
    for (auto &v : *this) r += w * v, w *= x;
    return r;
  }

  FPS log(int deg = -1) const {
    assert((*this)[0] == mint(1));
    if (deg == -1) deg = (int)this->size();
    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
  }

  FPS pow(int64_t k, int deg = -1) const {
    const int n = (int)this->size();
    if (deg == -1) deg = n;
    for (int i = 0; i < n; i++) {
      if ((*this)[i] != mint(0)) {
        if (i * k > deg) return FPS(deg, mint(0));
        mint rev = mint(1) / (*this)[i];
        FPS ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));
        ret = (ret << (i * k)).pre(deg);
        if ((int)ret.size() < deg) ret.resize(deg, mint(0));
        return ret;
      }
    }
    return FPS(deg, mint(0));
  }

  static void *ntt_ptr;
  static void set_fft();
  FPS &operator*=(const FPS &r);
  void ntt();
  void intt();
  void ntt_doubling();
  static int ntt_pr();
  FPS inv(int deg = -1) const;
  FPS exp(int deg = -1) const;
};
template <typename mint>
void *FormalPowerSeries<mint>::ntt_ptr = nullptr;

/**
 * @brief 多項式/形式的冪級数ライブラリ
 * @docs docs/fps/formal-power-series.md
 */
#line 3 "fps/differential-equation.hpp"

// find f, saitsfying equation f' = g(f) mod x ^ deg
template <typename mint>
FormalPowerSeries<mint> DifferentialEquation(
    function<FormalPowerSeries<mint>(FormalPowerSeries<mint>, int)> g,
    function<FormalPowerSeries<mint>(FormalPowerSeries<mint>, int)> gprime,
    mint f0, int deg) {
  using fps = FormalPowerSeries<mint>;
  fps f{f0};
  for (int i = 1; i < deg; i <<= 1) {
    fps r = (-gprime(f, i << 1)).integral().exp(i << 1);
    fps h = ((g(f, i << 1) - gprime(f, i << 1) * f) * r).pre(i << 1).integral();
    f = ((h + f0) * r.inv(i << 1)).pre(i << 1);
  }
  return f.pre(deg);
}

/**
 * @brief 常微分方程式
 * @docs docs/fps/differential-equation.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


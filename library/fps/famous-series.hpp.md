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


# :warning: fps/famous-series.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/famous-series.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-05 01:07:13+09:00




## Depends on

* :heavy_check_mark: <a href="formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>
* :heavy_check_mark: <a href="../modulo/binomial.hpp.html">modulo/binomial.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "./formal-power-series.hpp"
#include "../modulo/binomial.hpp"

template <typename mint>
FormalPowerSeries<mint> Stirling1st(int N, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  if (N <= 0) return fps{1};
  int lg = 31 - __builtin_clz(N);
  fps f = {0, 1};
  for (int i = lg - 1; i >= 0; i--) {
    int n = N >> i;
    f *= TaylorShift(f, mint(n >> 1), C);
    if (n & 1) f = (f << 1) + f * (n - 1);
  }
  return f;
}

template <typename mint>
FormalPowerSeries<mint> Stirling2nd(int N, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  fps f(N + 1), g(N + 1);
  for (int i = 0; i <= N; i++) {
    f[i] = mint(i).pow(N) * C.finv(i);
    g[i] = (i & 1) ? -C.finv(i) : C.finv(i);
  }
  return (f * g).pre(N + 1);
}

template <typename mint>
FormalPowerSeries<mint> BernoulliEGF(int N, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  fps f(N + 1);
  for (int i = 0; i <= N; i++) f[i] = C.finv(i + 1);
  return f.inv(N + 1);
}

template <typename mint>
FormalPowerSeries<mint> Partition(int N, Binomial<mint> &) {
  using fps = FormalPowerSeries<mint>;
  fps f(N + 1);
  f[0] = 1;
  for (int k = 1; k <= N; k++) {
    long long k1 = 1LL * k * (3 * k + 1) / 2;
    long long k2 = 1LL * k * (3 * k - 1) / 2;
    if (k2 > N) break;
    if (k1 <= N) f[k1] += ((k & 1) ? -1 : 1);
    if (k2 <= N) f[k2] += ((k & 1) ? -1 : 1);
  }
  return f.inv();
}

template <typename mint>
vector<mint> Montmort(int N) {
  if (N <= 1) return {0};
  if (N == 2) return {0, 1};
  vector<mint> f(N);
  f[0] = 0, f[1] = 1;
  mint coeff = 2, one = 1;
  for (int i = 2; i < N; i++) {
    f[i] = (f[i - 1] + f[i - 2]) * coeff;
    coeff += one;
  }
  return f;
};
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
    for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * mint(i);
    return ret;
  }

  FPS integral() const {
    const int n = (int)this->size();
    FPS ret(n + 1);
    ret[0] = mint(0);
    for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / mint(i + 1);
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
 * @docs docs/formal-power-series.md
 */
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
#line 4 "fps/famous-series.hpp"

template <typename mint>
FormalPowerSeries<mint> Stirling1st(int N, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  if (N <= 0) return fps{1};
  int lg = 31 - __builtin_clz(N);
  fps f = {0, 1};
  for (int i = lg - 1; i >= 0; i--) {
    int n = N >> i;
    f *= TaylorShift(f, mint(n >> 1), C);
    if (n & 1) f = (f << 1) + f * (n - 1);
  }
  return f;
}

template <typename mint>
FormalPowerSeries<mint> Stirling2nd(int N, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  fps f(N + 1), g(N + 1);
  for (int i = 0; i <= N; i++) {
    f[i] = mint(i).pow(N) * C.finv(i);
    g[i] = (i & 1) ? -C.finv(i) : C.finv(i);
  }
  return (f * g).pre(N + 1);
}

template <typename mint>
FormalPowerSeries<mint> BernoulliEGF(int N, Binomial<mint> &C) {
  using fps = FormalPowerSeries<mint>;
  fps f(N + 1);
  for (int i = 0; i <= N; i++) f[i] = C.finv(i + 1);
  return f.inv(N + 1);
}

template <typename mint>
FormalPowerSeries<mint> Partition(int N, Binomial<mint> &) {
  using fps = FormalPowerSeries<mint>;
  fps f(N + 1);
  f[0] = 1;
  for (int k = 1; k <= N; k++) {
    long long k1 = 1LL * k * (3 * k + 1) / 2;
    long long k2 = 1LL * k * (3 * k - 1) / 2;
    if (k2 > N) break;
    if (k1 <= N) f[k1] += ((k & 1) ? -1 : 1);
    if (k2 <= N) f[k2] += ((k & 1) ? -1 : 1);
  }
  return f.inv();
}

template <typename mint>
vector<mint> Montmort(int N) {
  if (N <= 1) return {0};
  if (N == 2) return {0, 1};
  vector<mint> f(N);
  f[0] = 0, f[1] = 1;
  mint coeff = 2, one = 1;
  for (int i = 2; i < N; i++) {
    f[i] = (f[i - 1] + f[i - 2]) * coeff;
    coeff += one;
  }
  return f;
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


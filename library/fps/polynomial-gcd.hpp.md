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


# :heavy_check_mark: 多項式GCD <small>(fps/polynomial-gcd.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/polynomial-gcd.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-21 15:57:02+09:00




## 多項式GCD

## Depends on

* :question: <a href="formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp.html">verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "./formal-power-series.hpp"

namespace poly_gcd {

template <typename mint>
using FPS = FormalPowerSeries<mint>;
template <typename mint>
using Arr = pair<FPS<mint>, FPS<mint>>;

template <typename mint>
struct Mat {
  using fps = FPS<mint>;
  fps a00, a01, a10, a11;

  Mat() = default;
  Mat(const fps& a00_, const fps& a01_, const fps& a10_, const fps& a11_)
      : a00(a00_), a01(a01_), a10(a10_), a11(a11_) {}

  Mat& operator*=(const Mat& r) {
    fps A00 = a00 * r.a00 + a01 * r.a10;
    fps A01 = a00 * r.a01 + a01 * r.a11;
    fps A10 = a10 * r.a00 + a11 * r.a10;
    fps A11 = a10 * r.a01 + a11 * r.a11;
    A00.shrink();
    A01.shrink();
    A10.shrink();
    A11.shrink();
    swap(A00, a00);
    swap(A01, a01);
    swap(A10, a10);
    swap(A11, a11);
    return *this;
  }

  static Mat I() { return Mat(fps{mint(1)}, fps(), fps(), fps{mint(1)}); }

  Mat operator*(const Mat& r) const { return Mat(*this) *= r; }
};

template <typename mint>
Arr<mint> operator*(const Mat<mint>& m, const Arr<mint>& a) {
  using fps = FPS<mint>;
  fps b0 = m.a00 * a.first + m.a01 * a.second;
  fps b1 = m.a10 * a.first + m.a11 * a.second;
  b0.shrink();
  b1.shrink();
  return {b0, b1};
};

template <typename mint>
void InnerNaiveGCD(Mat<mint>& m, Arr<mint>& p) {
  using fps = FPS<mint>;
  fps quo = p.first / p.second;
  fps rem = p.first - p.second * quo;
  fps b10 = m.a00 - m.a10 * quo;
  fps b11 = m.a01 - m.a11 * quo;
  rem.shrink();
  b10.shrink();
  b11.shrink();
  swap(b10, m.a10);
  swap(b11, m.a11);
  swap(b10, m.a00);
  swap(b11, m.a01);
  p = {p.second, rem};
}

template <typename mint>
Mat<mint> InnerHalfGCD(Arr<mint> p) {
  int n = p.first.size(), m = p.second.size();
  int k = (n + 1) / 2;
  if (m <= k) return Mat<mint>::I();
  Mat<mint> m1 = InnerHalfGCD(make_pair(p.first >> k, p.second >> k));
  p = m1 * p;
  if ((int)p.second.size() <= k) return m1;
  InnerNaiveGCD(m1, p);
  if ((int)p.second.size() <= k) return m1;
  int l = (int)p.first.size() - 1;
  int j = 2 * k - l;
  p.first = p.first >> j;
  p.second = p.second >> j;
  return InnerHalfGCD(p) * m1;
}

template <typename mint>
Mat<mint> InnerPolyGCD(const FPS<mint>& a, const FPS<mint>& b) {
  Arr<mint> p{a, b};
  p.first.shrink();
  p.second.shrink();
  int n = p.first.size(), m = p.second.size();
  if (n < m) {
    Mat<mint> mat = InnerPolyGCD(p.second, p.first);
    swap(mat.a00, mat.a01);
    swap(mat.a10, mat.a11);
    return mat;
  }

  Mat<mint> res = Mat<mint>::I();
  while (1) {
    Mat<mint> m1 = InnerHalfGCD(p);
    p = m1 * p;
    if (p.second.empty()) return m1 * res;
    InnerNaiveGCD(m1, p);
    if (p.second.empty()) return m1 * res;
    res = m1 * res;
  }
}

template <typename mint>
FPS<mint> PolyGCD(const FPS<mint>& a, const FPS<mint>& b) {
  Arr<mint> p(a, b);
  Mat<mint> m = InnerPolyGCD(a, b);
  p = m * p;
  if (!p.first.empty()) {
    mint coeff = p.first.back().inverse();
    for (auto& x : p.first) x *= coeff;
  }
  return p.first;
}

template <typename mint>
pair<int, FPS<mint>> PolyInv(const FPS<mint>& f, const FPS<mint>& g) {
  using fps = FPS<mint>;
  pair<fps, fps> p(f, g);
  Mat<mint> m = InnerPolyGCD(f, g);
  fps gcd_ = (m * p).first;
  if (gcd_.size() != 1) return {false, fps()};
  pair<fps, fps> x(fps{mint(1)}, g);
  return {true, ((m * x).first % g) * gcd_[0].inverse()};
}

}  // namespace poly_gcd
using poly_gcd::PolyGCD;
using poly_gcd::PolyInv;

/**
 * @brief 多項式GCD
 * @docs docs/fps/polynomial-gcd.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "fps/polynomial-gcd.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 3 "fps/formal-power-series.hpp"
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
    if ((int)r.size() <= 64) {
      FPS f(*this), g(r);
      g.shrink();
      mint coeff = g.back().inverse();
      for (auto &x : g) x *= coeff;
      int deg = (int)f.size() - (int)g.size() + 1;
      int gs = g.size();
      FPS quo(deg);
      for (int i = deg - 1; i >= 0; i--) {
        quo[i] = f[i + gs - 1];
        for (int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];
      }
      *this = quo * coeff;
      this->resize(n, mint(0));
      return *this;
    }
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
#line 6 "fps/polynomial-gcd.hpp"

namespace poly_gcd {

template <typename mint>
using FPS = FormalPowerSeries<mint>;
template <typename mint>
using Arr = pair<FPS<mint>, FPS<mint>>;

template <typename mint>
struct Mat {
  using fps = FPS<mint>;
  fps a00, a01, a10, a11;

  Mat() = default;
  Mat(const fps& a00_, const fps& a01_, const fps& a10_, const fps& a11_)
      : a00(a00_), a01(a01_), a10(a10_), a11(a11_) {}

  Mat& operator*=(const Mat& r) {
    fps A00 = a00 * r.a00 + a01 * r.a10;
    fps A01 = a00 * r.a01 + a01 * r.a11;
    fps A10 = a10 * r.a00 + a11 * r.a10;
    fps A11 = a10 * r.a01 + a11 * r.a11;
    A00.shrink();
    A01.shrink();
    A10.shrink();
    A11.shrink();
    swap(A00, a00);
    swap(A01, a01);
    swap(A10, a10);
    swap(A11, a11);
    return *this;
  }

  static Mat I() { return Mat(fps{mint(1)}, fps(), fps(), fps{mint(1)}); }

  Mat operator*(const Mat& r) const { return Mat(*this) *= r; }
};

template <typename mint>
Arr<mint> operator*(const Mat<mint>& m, const Arr<mint>& a) {
  using fps = FPS<mint>;
  fps b0 = m.a00 * a.first + m.a01 * a.second;
  fps b1 = m.a10 * a.first + m.a11 * a.second;
  b0.shrink();
  b1.shrink();
  return {b0, b1};
};

template <typename mint>
void InnerNaiveGCD(Mat<mint>& m, Arr<mint>& p) {
  using fps = FPS<mint>;
  fps quo = p.first / p.second;
  fps rem = p.first - p.second * quo;
  fps b10 = m.a00 - m.a10 * quo;
  fps b11 = m.a01 - m.a11 * quo;
  rem.shrink();
  b10.shrink();
  b11.shrink();
  swap(b10, m.a10);
  swap(b11, m.a11);
  swap(b10, m.a00);
  swap(b11, m.a01);
  p = {p.second, rem};
}

template <typename mint>
Mat<mint> InnerHalfGCD(Arr<mint> p) {
  int n = p.first.size(), m = p.second.size();
  int k = (n + 1) / 2;
  if (m <= k) return Mat<mint>::I();
  Mat<mint> m1 = InnerHalfGCD(make_pair(p.first >> k, p.second >> k));
  p = m1 * p;
  if ((int)p.second.size() <= k) return m1;
  InnerNaiveGCD(m1, p);
  if ((int)p.second.size() <= k) return m1;
  int l = (int)p.first.size() - 1;
  int j = 2 * k - l;
  p.first = p.first >> j;
  p.second = p.second >> j;
  return InnerHalfGCD(p) * m1;
}

template <typename mint>
Mat<mint> InnerPolyGCD(const FPS<mint>& a, const FPS<mint>& b) {
  Arr<mint> p{a, b};
  p.first.shrink();
  p.second.shrink();
  int n = p.first.size(), m = p.second.size();
  if (n < m) {
    Mat<mint> mat = InnerPolyGCD(p.second, p.first);
    swap(mat.a00, mat.a01);
    swap(mat.a10, mat.a11);
    return mat;
  }

  Mat<mint> res = Mat<mint>::I();
  while (1) {
    Mat<mint> m1 = InnerHalfGCD(p);
    p = m1 * p;
    if (p.second.empty()) return m1 * res;
    InnerNaiveGCD(m1, p);
    if (p.second.empty()) return m1 * res;
    res = m1 * res;
  }
}

template <typename mint>
FPS<mint> PolyGCD(const FPS<mint>& a, const FPS<mint>& b) {
  Arr<mint> p(a, b);
  Mat<mint> m = InnerPolyGCD(a, b);
  p = m * p;
  if (!p.first.empty()) {
    mint coeff = p.first.back().inverse();
    for (auto& x : p.first) x *= coeff;
  }
  return p.first;
}

template <typename mint>
pair<int, FPS<mint>> PolyInv(const FPS<mint>& f, const FPS<mint>& g) {
  using fps = FPS<mint>;
  pair<fps, fps> p(f, g);
  Mat<mint> m = InnerPolyGCD(f, g);
  fps gcd_ = (m * p).first;
  if (gcd_.size() != 1) return {false, fps()};
  pair<fps, fps> x(fps{mint(1)}, g);
  return {true, ((m * x).first % g) * gcd_[0].inverse()};
}

}  // namespace poly_gcd
using poly_gcd::PolyGCD;
using poly_gcd::PolyInv;

/**
 * @brief 多項式GCD
 * @docs docs/fps/polynomial-gcd.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


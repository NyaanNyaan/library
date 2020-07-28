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


# :warning: fps/ntt-friendly-fps.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/ntt-friendly-fps.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 18:29:00+09:00




## Depends on

* :warning: <a href="formal-power-series.hpp.html">Formal Power Series <small>(fps/formal-power-series.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "./formal-power-series.hpp"

template <typename mint>
FormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(
    const FormalPowerSeries<mint>& r) {
  if (this->empty() || r.empty()) {
    this->clear();
    return *this;
  }
  static NTT<mint> ntt;
  static_assert(ntt.level >= 20);
  auto ret = ntt.multiply(*this, r);
  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg = -1) const {
  assert((*this)[0] != mint(0));
  if (deg == -1) deg = (*this).size();
  FormalPowerSeries<mint> ret({mint(1) / (*this)[0]});
  for (int i = 1; i < deg; i <<= 1)
    ret = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);
  return ret.pre(deg);
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::log(int deg = -1) const {
  assert((*this)[0] == mint(1));
  if (deg == -1) deg = (int)this->size();
  return (this->diff() * this->inv()).pre(deg - 1).integral();
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int deg = -1) const {
  assert((*this)[0] == mint(0));
  if (deg == -1) deg = (int)this->size();
  FormalPowerSeries<mint> ret({mint(1)});
  for (int i = 1; i < deg; i <<= 1) {
    ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
  }
  return ret.pre(deg);
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::pow(int64_t k,
                                                     int deg = -1) const {
  const int n = (int)this->size();
  if (deg == -1) deg = n;
  for (int i = 0; i < n; i++) {
    if ((*this)[i] != mint(0)) {
      if (i * k > deg) return FormalPowerSeries<mint>(deg, mint(0));
      mint rev = mint(1) / (*this)[i];
      FormalPowerSeries<mint> ret =
          (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));
      ret = (ret << (i * k)).pre(deg);
      if (ret.size() < deg) ret.resize(deg, mint(0));
      return ret;
    }
  }
  return *this;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "fps/ntt-friendly-fps.hpp"
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
    shrink();
    return *this;
  }

  FPS &operator-=(const mint &r) {
    if (this->empty()) this->resize(1);
    (*this)[0] -= r;
    shrink();
    return *this;
  }

  FPS &operator*=(const FPS &r);

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

  FPS &operator%=(const FPS &r) { return *this -= *this / r * r; }
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
    if (this->size() <= sz) return {};
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

  FPS inv(int deg = -1) const;
  FPS log(int deg = -1) const;
  FPS exp(int deg = -1) const;
  FPS pow(int64_t k, int deg = -1) const;
  // FPS sqrt(int deg = -1) const;
};

/**
 * @brief Formal Power Series
 * @docs docs/formal-power-series.md
 */
#line 6 "fps/ntt-friendly-fps.hpp"

template <typename mint>
FormalPowerSeries<mint>& FormalPowerSeries<mint>::operator*=(
    const FormalPowerSeries<mint>& r) {
  if (this->empty() || r.empty()) {
    this->clear();
    return *this;
  }
  static NTT<mint> ntt;
  static_assert(ntt.level >= 20);
  auto ret = ntt.multiply(*this, r);
  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg = -1) const {
  assert((*this)[0] != mint(0));
  if (deg == -1) deg = (*this).size();
  FormalPowerSeries<mint> ret({mint(1) / (*this)[0]});
  for (int i = 1; i < deg; i <<= 1)
    ret = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);
  return ret.pre(deg);
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::log(int deg = -1) const {
  assert((*this)[0] == mint(1));
  if (deg == -1) deg = (int)this->size();
  return (this->diff() * this->inv()).pre(deg - 1).integral();
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::exp(int deg = -1) const {
  assert((*this)[0] == mint(0));
  if (deg == -1) deg = (int)this->size();
  FormalPowerSeries<mint> ret({mint(1)});
  for (int i = 1; i < deg; i <<= 1) {
    ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
  }
  return ret.pre(deg);
}

template <typename mint>
FormalPowerSeries<mint> FormalPowerSeries<mint>::pow(int64_t k,
                                                     int deg = -1) const {
  const int n = (int)this->size();
  if (deg == -1) deg = n;
  for (int i = 0; i < n; i++) {
    if ((*this)[i] != mint(0)) {
      if (i * k > deg) return FormalPowerSeries<mint>(deg, mint(0));
      mint rev = mint(1) / (*this)[i];
      FormalPowerSeries<mint> ret =
          (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));
      ret = (ret << (i * k)).pre(deg);
      if (ret.size() < deg) ret.resize(deg, mint(0));
      return ret;
    }
  }
  return *this;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


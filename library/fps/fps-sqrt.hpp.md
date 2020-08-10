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


# :heavy_check_mark: 平方根 <small>(fps/fps-sqrt.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/fps-sqrt.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-05 01:10:03+09:00




# fps-平方根

$f$は$t^2=f_0$を満たす$t$が存在する多項式とする。このとき$g \equiv \sqrt{f} \mod x^n$となる$g$を求めたい。

まず、$g \equiv t \mod x$である。次にニュートン法で$g^2 \equiv f$を満たす$g$を求めると、$g=\hat{g} \mod x^k$ のとき 

$$g \equiv \hat{g} - \frac{\hat{g}^2-f}{(\hat{g}^2)'} \mod x^{2k}$$

$$\leftrightarrow g \equiv \frac{1}{2}\left(\hat{g}+\frac{f}{\hat{g}}\right) \mod x^{2k}$$

を得てダブリングで求まる。計算量は$\mathrm{O}(N \log N)$。

#### 使い方

- `sqrt(f, deg)`: FPSである$f$について$\sqrt f$をdeg次の項まで求める。


## Depends on

* :question: <a href="formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>
* :question: <a href="../modint/arbitrary-prime-modint.hpp.html">modint/arbitrary-prime-modint.hpp</a>
* :heavy_check_mark: <a href="../modulo/mod-sqrt.hpp.html">modulo/mod-sqrt.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-sqrt.test.cpp.html">verify/verify-yosupo-fps/yosupo-sqrt.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../fps/formal-power-series.hpp"
#include "../modulo/mod-sqrt.hpp"

template <typename mint>
FormalPowerSeries<mint> sqrt(const FormalPowerSeries<mint> &f, int deg = -1) {
  if (deg == -1) deg = (int)f.size();
  if ((int)f.size() == 0) return FormalPowerSeries<mint>(deg, 0);
  if (f[0] == mint(0)) {
    for (int i = 1; i < (int)f.size(); i++) {
      if (f[i] != mint(0)) {
        if (i & 1) return {};
        if (deg - i / 2 <= 0) break;
        auto ret = sqrt(f >> i, deg - i / 2);
        if (ret.empty()) return {};
        ret = ret << (i / 2);
        if ((int)ret.size() < deg) ret.resize(deg, mint(0));
        return ret;
      }
    }
    return FormalPowerSeries<mint>(deg, 0);
  }

  int64_t sqr = mod_sqrt(f[0].get(), mint::get_mod());
  if (sqr == -1) return {};
  assert(sqr * sqr % mint::get_mod() == f[0].get());
  FormalPowerSeries<mint> ret = {mint(sqr)};
  mint inv2 = mint(2).inverse();
  for (int i = 1; i < deg; i <<= 1) {
    ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;
  }
  return ret.pre(deg);
}

/**
 * @brief 平方根
 * @docs docs/fps-sqrt.md
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
#line 3 "modint/arbitrary-prime-modint.hpp"
using namespace std;

struct ArbitraryLazyMontgomeryModInt {
  using mint = ArbitraryLazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static u32 mod;
  static u32 r;
  static u32 n2;

  static u32 get_r() {
    u32 ret = mod;
    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
    return ret;
  }

  static void set_mod(u32 m) {
    assert(m < (1 << 30));
    assert((m & 1) == 1);
    mod = m;
    n2 = -u64(m) % m;
    r = get_r();
    assert(r * mod == 1);
  }

  u32 a;

  ArbitraryLazyMontgomeryModInt() : a(0) {}
  ArbitraryLazyMontgomeryModInt(const int64_t &b)
      : a(reduce(u64(b % mod + mod) * n2)){};

  static u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }

  mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  mint operator+(const mint &b) const { return mint(*this) += b; }
  mint operator-(const mint &b) const { return mint(*this) -= b; }
  mint operator*(const mint &b) const { return mint(*this) *= b; }
  mint operator/(const mint &b) const { return mint(*this) /= b; }
  bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  mint operator-() const { return mint() - mint(*this); }

  mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = ArbitraryLazyMontgomeryModInt(t);
    return (is);
  }

  mint inverse() const { return pow(mod - 2); }

  u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static u32 get_mod() { return mod; }
};
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::mod;
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::r;
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::n2;
#line 3 "modulo/mod-sqrt.hpp"

int64_t mod_sqrt(const int64_t &a, const int64_t &p) {
  if (a == 0) return 0;
  if (p == 2) return a;
  using mint = ArbitraryLazyMontgomeryModInt;
  mint::set_mod(p);
  if (mint(a).pow((p - 1) >> 1) != 1) return -1;
  mint b = 1, one = 1;
  while (b.pow((p - 1) >> 1) == 1) b += one;
  int64_t m = p - 1, e = 0;
  while (m % 2 == 0) m >>= 1, e += 1;
  mint x = mint(a).pow((m - 1) >> 1);
  mint y = mint(a) * x * x;
  x *= a;
  mint z = mint(b).pow(m);
  while (y != 1) {
    int64_t j = 0;
    mint t = y;
    while (t != one) {
      j += 1;
      t *= t;
    }
    z = z.pow(int64_t(1) << (e - j - 1));
    x *= z;
    z *= z;
    y *= z;
    e = j;
  }
  return x.get();
}
#line 4 "fps/fps-sqrt.hpp"

template <typename mint>
FormalPowerSeries<mint> sqrt(const FormalPowerSeries<mint> &f, int deg = -1) {
  if (deg == -1) deg = (int)f.size();
  if ((int)f.size() == 0) return FormalPowerSeries<mint>(deg, 0);
  if (f[0] == mint(0)) {
    for (int i = 1; i < (int)f.size(); i++) {
      if (f[i] != mint(0)) {
        if (i & 1) return {};
        if (deg - i / 2 <= 0) break;
        auto ret = sqrt(f >> i, deg - i / 2);
        if (ret.empty()) return {};
        ret = ret << (i / 2);
        if ((int)ret.size() < deg) ret.resize(deg, mint(0));
        return ret;
      }
    }
    return FormalPowerSeries<mint>(deg, 0);
  }

  int64_t sqr = mod_sqrt(f[0].get(), mint::get_mod());
  if (sqr == -1) return {};
  assert(sqr * sqr % mint::get_mod() == f[0].get());
  FormalPowerSeries<mint> ret = {mint(sqr)};
  mint inv2 = mint(2).inverse();
  for (int i = 1; i < deg; i <<= 1) {
    ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;
  }
  return ret.pre(deg);
}

/**
 * @brief 平方根
 * @docs docs/fps-sqrt.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


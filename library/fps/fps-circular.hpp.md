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


# :heavy_check_mark: 三角関数 <small>(fps/fps-circular.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/fps-circular.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 23:20:42+09:00




## fps-三角関数

$g \equiv \cos f, h \equiv \sin f \mod x^n$を求めたい。

これはオイラーの公式$e^{if}=\cos f+i\sin f$を利用すると$exp$と同様の方法で求まる。

なお、計算は実部と虚部に分けて行う必要がある。例えば掛け算の時は4回乗算して適切に足し合わせる。

#### 使い方

- `circular(fre, fim, deg)` : $Re[f]=fre,Im[f]=fim$であるFPS $f$について$\cos f,\sin f$をdeg次の項まで求める。


## Depends on

* :heavy_check_mark: <a href="formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>
* :heavy_check_mark: <a href="../modint/montgomery-modint.hpp.html">modint/montgomery-modint.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-0963-circular.test.cpp.html">verify/verify-yuki/yuki-0963-circular.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-1080.test.cpp.html">verify/verify-yuki/yuki-1080.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../fps/formal-power-series.hpp"
#include "../modint/montgomery-modint.hpp"

template <typename mint>
pair<FormalPowerSeries<mint>, FormalPowerSeries<mint>> circular(
    const FormalPowerSeries<mint> &fre, const FormalPowerSeries<mint> &fim,
    int deg = -1) {
  using fps = FormalPowerSeries<mint>;
  assert(fre.size() == 0 || fre[0] == mint(0));
  assert(fim.size() == 0 || fim[0] == mint(0));
  if (deg == -1) deg = (int)max(fre.size(), fim.size());
  fps re({mint(1)}), im({mint(0)});

  fps::set_fft();
  if (fps::ntt_ptr == nullptr) {
    for (int i = 1; i < deg; i <<= 1) {
      fps dre = re.diff();
      fps dim = im.diff();
      fps fhypot = (re * re + im * im).inv(i << 1);
      fps ere = dre * re + dim * im;
      fps eim = dim * re - dre * im;
      fps logre = (ere * fhypot).pre((i << 1) - 1).integral();
      fps logim = (eim * fhypot).pre((i << 1) - 1).integral();
      fps gre = (-logre) + mint(1) - fim.pre(i << 1);
      fps gim = (-logim) + fre.pre(i << 1);
      fps hre = (re * gre - im * gim).pre(i << 1);
      fps him = (re * gim + im * gre).pre(i << 1);
      swap(re, hre);
      swap(im, him);
    }
  } else {
    for (int i = 1; i < deg; i <<= 1) {
      fps dre = re.diff();
      fps dim = im.diff();
      re.resize(i << 1);
      im.resize(i << 1);
      dre.resize(i << 1);
      dim.resize(i << 1);
      re.ntt();
      im.ntt();
      dre.ntt();
      dim.ntt();
      fps fhypot(i << 1), ere(i << 1), eim(i << 1);
      for (int j = 0; j < 2 * i; j++) {
        fhypot[j] = re[j] * re[j] + im[j] * im[j];
        ere[j] = dre[j] * re[j] + dim[j] * im[j];
        eim[j] = dim[j] * re[j] - dre[j] * im[j];
      }
      fhypot.intt();
      fhypot = fhypot.inv(i << 1);
      fhypot.resize(i << 2);
      fhypot.ntt();
      ere.ntt_doubling();
      eim.ntt_doubling();
      fps logre(i << 2), logim(i << 2);
      for (int j = 0; j < 4 * i; j++) {
        logre[j] = ere[j] * fhypot[j];
        logim[j] = eim[j] * fhypot[j];
      }
      logre.intt();
      logim.intt();
      logre = logre.pre((i << 1) - 1).integral();
      logim = logim.pre((i << 1) - 1).integral();
      fps gre = (-logre) + mint(1) - fim.pre(i << 1);
      fps gim = (-logim) + fre.pre(i << 1);
      gre.resize(i << 2);
      gim.resize(i << 2);
      gre.ntt();
      gim.ntt();
      re.ntt_doubling();
      im.ntt_doubling();
      fps hre(i << 2), him(i << 2);
      for (int j = 0; j < 4 * i; j++) {
        hre[j] = re[j] * gre[j] - im[j] * gim[j];
        him[j] = re[j] * gim[j] + im[j] * gre[j];
      }
      hre.intt();
      him.intt();
      hre = hre.pre(i << 1);
      him = him.pre(i << 1);
      swap(re, hre);
      swap(im, him);
    }
  }
  return make_pair(re.pre(deg), im.pre(deg));
}

/**
 * @brief 三角関数
 * @docs docs/fps/fps-circular.md
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
#line 3 "modint/montgomery-modint.hpp"
using namespace std;

template <uint32_t mod>
struct LazyMontgomeryModInt {
  using mint = LazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 get_r() {
    u32 ret = mod;
    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
    return ret;
  }

  static constexpr u32 r = get_r();
  static constexpr u32 n2 = -u64(mod) % mod;
  static_assert(r * mod == 1, "invalid, r * mod != 1");
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");

  u32 a;

  constexpr LazyMontgomeryModInt() : a(0) {}
  constexpr LazyMontgomeryModInt(const int64_t &b)
      : a(reduce(u64(b % mod + mod) * n2)){};

  static constexpr u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }

  constexpr mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  constexpr mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  constexpr mint operator+(const mint &b) const { return mint(*this) += b; }
  constexpr mint operator-(const mint &b) const { return mint(*this) -= b; }
  constexpr mint operator*(const mint &b) const { return mint(*this) *= b; }
  constexpr mint operator/(const mint &b) const { return mint(*this) /= b; }
  constexpr bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr mint operator-() const { return mint() - mint(*this); }

  constexpr mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  
  constexpr mint inverse() const { return pow(mod - 2); }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = LazyMontgomeryModInt<mod>(t);
    return (is);
  }
  
  constexpr u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static constexpr u32 get_mod() { return mod; }
};
#line 4 "fps/fps-circular.hpp"

template <typename mint>
pair<FormalPowerSeries<mint>, FormalPowerSeries<mint>> circular(
    const FormalPowerSeries<mint> &fre, const FormalPowerSeries<mint> &fim,
    int deg = -1) {
  using fps = FormalPowerSeries<mint>;
  assert(fre.size() == 0 || fre[0] == mint(0));
  assert(fim.size() == 0 || fim[0] == mint(0));
  if (deg == -1) deg = (int)max(fre.size(), fim.size());
  fps re({mint(1)}), im({mint(0)});

  fps::set_fft();
  if (fps::ntt_ptr == nullptr) {
    for (int i = 1; i < deg; i <<= 1) {
      fps dre = re.diff();
      fps dim = im.diff();
      fps fhypot = (re * re + im * im).inv(i << 1);
      fps ere = dre * re + dim * im;
      fps eim = dim * re - dre * im;
      fps logre = (ere * fhypot).pre((i << 1) - 1).integral();
      fps logim = (eim * fhypot).pre((i << 1) - 1).integral();
      fps gre = (-logre) + mint(1) - fim.pre(i << 1);
      fps gim = (-logim) + fre.pre(i << 1);
      fps hre = (re * gre - im * gim).pre(i << 1);
      fps him = (re * gim + im * gre).pre(i << 1);
      swap(re, hre);
      swap(im, him);
    }
  } else {
    for (int i = 1; i < deg; i <<= 1) {
      fps dre = re.diff();
      fps dim = im.diff();
      re.resize(i << 1);
      im.resize(i << 1);
      dre.resize(i << 1);
      dim.resize(i << 1);
      re.ntt();
      im.ntt();
      dre.ntt();
      dim.ntt();
      fps fhypot(i << 1), ere(i << 1), eim(i << 1);
      for (int j = 0; j < 2 * i; j++) {
        fhypot[j] = re[j] * re[j] + im[j] * im[j];
        ere[j] = dre[j] * re[j] + dim[j] * im[j];
        eim[j] = dim[j] * re[j] - dre[j] * im[j];
      }
      fhypot.intt();
      fhypot = fhypot.inv(i << 1);
      fhypot.resize(i << 2);
      fhypot.ntt();
      ere.ntt_doubling();
      eim.ntt_doubling();
      fps logre(i << 2), logim(i << 2);
      for (int j = 0; j < 4 * i; j++) {
        logre[j] = ere[j] * fhypot[j];
        logim[j] = eim[j] * fhypot[j];
      }
      logre.intt();
      logim.intt();
      logre = logre.pre((i << 1) - 1).integral();
      logim = logim.pre((i << 1) - 1).integral();
      fps gre = (-logre) + mint(1) - fim.pre(i << 1);
      fps gim = (-logim) + fre.pre(i << 1);
      gre.resize(i << 2);
      gim.resize(i << 2);
      gre.ntt();
      gim.ntt();
      re.ntt_doubling();
      im.ntt_doubling();
      fps hre(i << 2), him(i << 2);
      for (int j = 0; j < 4 * i; j++) {
        hre[j] = re[j] * gre[j] - im[j] * gim[j];
        him[j] = re[j] * gim[j] + im[j] * gre[j];
      }
      hre.intt();
      him.intt();
      hre = hre.pre(i << 1);
      him = him.pre(i << 1);
      swap(re, hre);
      swap(im, him);
    }
  }
  return make_pair(re.pre(deg), im.pre(deg));
}

/**
 * @brief 三角関数
 * @docs docs/fps/fps-circular.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


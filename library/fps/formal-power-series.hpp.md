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


# :heavy_check_mark: 多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/formal-power-series.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-21 15:57:02+09:00




# 形式的冪級数
多項式/形式的冪級数の基本操作を行うライブラリ。

次の3つのファイルから成り、modが$998244353$の時は1番目と2番目を、$1e9+7$の時は1番目と3番目をincludeして使用する。

- `formal-power-series.hpp` $\cdots$ 共通部分のみ実装したもの。
- `ntt-friendly-fps.hpp` $\cdots$ NTT素数mod用の高速な実装を行ったもの。
- `arbitrary-fps.hpp` $\cdots$ 任意mod畳み込み用の実装を行ったもの。

実装の一部は[うしさんのライブラリ](https://ei1333.github.io/library/library/math/fps/formal-power-series.cpp.html)を大きく参考にしました。感謝…

### 加算・減算

$\mathrm{O}(N)$

### 乗算

$h(x)=f(x)g(x)$となる$h(x)$を求める。これはFFT/NTT(FMT)で求められる。$\mathrm{O}(N \log N)$

### 除算

(注：この項に書かれている除算は多項式としての除算である。)

$f(x) = g(x)q(x) + r(x)$となる多項式$q,r$を求めたい。($f$は$n-1$次、$g$は$m-1$次($n>m$),$q$は$n-m$次とする。)ここで、

$$f^R := f(\frac{1}{x})\cdot x^{n-1}$$

のようにおくと$f^R$は多項式になる。最初の式を$x \leftarrow \frac{1}{x}$に置き換えると、

$$f(\frac{1}{x})  = g(\frac{1}{x})q(\frac{1}{x})+r(\frac{1}{x})$$

両辺に$x^{n-1}$を掛けると

$$f(\frac{1}{x}) x^{n-1} = g(\frac{1}{x})x^{m-1}\cdot q(\frac{1}{x})x^{n-m}+r(\frac{1}{x})x^{m-2} \cdot x^{n-m+1}$$

$$\leftrightarrow f^R = g^R q^R + r^R x^{n-m+1}$$

$$\rightarrow f^R \equiv g^R q^R \mod x^{n-m+1}$$

を得る。$q^R$は$n-m$次なので$\mod x^{n-m+1}$を利用して

$$\frac{f^R}{g^R} \equiv q^R \mod x^{n-m+1}$$

となるので、ここから$q$と$r$を計算できる。(逆元の出し方は後述)

### 微分・積分

$\mathrm{O}(N)$

### ダブリング

$f \mod x^n$を求めたい時に、$f \equiv f_0 \mod x$から始めて精度を倍々にして求める手法のことをダブリングと呼ぶ。

具体的には、$\hat{f} \equiv f \mod x^k$から$f \mod x^{2k}$を

$$(f - \hat{f})^2 \equiv 0 \mod x^{2k}$$

を利用して計算する。これを利用して逆元を求める。

### 逆元

$fg\equiv 1 \mod x^n$となる$f$の逆元$g$をダブリングで求めたい。

まず$g \equiv f_0^{-1} \mod x$である。次に、$g \equiv \hat{g} \mod x^k$が分かっているとき$g \mod x^{2k}$を出す。

$$(g-\hat{g})^2\equiv g^2-2g\hat{g}+\hat{g}^2\equiv0 \mod x^{2k}$$

両辺に$f$を掛けると

$$fg^2-2fg\hat{g}+f\hat{g}^2\equiv0 \mod x^{2k}$$

$fg \equiv 1 \mod x^{2k}$を利用して$fg$を消すと

$$g\equiv2\hat{g}-f\hat{g}^2 \mod x^{2k}$$

を得る。計算量は$T(n)=T(n/2)+\mathrm{O}(N \log N)$を解いて$T(n)=\mathrm{O}(N \log N)$となる。

なお、modがNTT素数の場合は実装を工夫することで定数倍が2倍以上軽くなる。

### log

$f_0 = 1$を満たす$f$に対して、$e^f \equiv g \mod x^n$を満たす$g$を$g\equiv\log f \mod x^n$として定義する。この時、$g$は

$$\log f \equiv \int \frac{f'}{f} \mod x^n$$

から求まる。(なお、上の式は一見すると不定積分の定数項のズレが心配に見えるが、$g_0 = 0$とおくと$x=0$を代入したとき両辺が等しくなるので問題ない。)

### ニュートン法

$G(g) \equiv f \mod x^n$を満たすFPSである$g$を求めたい。$G(\hat{g}) \equiv f \mod x^n$を満たす$\hat{g}$が求まっている時、$\hat{g}$と$g \equiv x^{2n}$の間には次の関係式が従う。

$$g \equiv \hat{g} - \frac{G(\hat{g})-f}{G'(\hat{g})} \mod x^{2n}$$

証明は$G(\hat{g})$を$\hat{g}=0$でテイラー展開すると求まる。この式を使って$\mathrm{exp}$や$\mathrm{sqrt}$を計算することが出来る。

### exp

$g \equiv e^f \mod x^n$となる$g$を求める。

$$\log g \equiv f \mod x^n$$

等式が成り立つには$f_0=0$が必要でこの時$g_0=1$。次にニュートン法を使うと、

$$g \equiv \hat{g} - \frac{\log\hat{g}-f}{\log'\hat{g}} \mod x^{2n}$$

$\log' \hat{g}\equiv\frac{1}{\hat{g}}$より

$$g\equiv \hat{g}(1-\log \hat{g}+f) \mod x^{2n}$$

となりダブリングで求まる。$\mathrm{O}(N \log N)$ 

### 累乗

$g \equiv f^k \mod x^n$となる$g$を求めたい。繰り返し自乗法を用いると$\mathrm{O}(N \log k \log N)$で求まるがexpを使うともっと早くなる。

$f$の一番次数の低い項が$a_p x^p \ (p \neq 0)$のときは$\left(\frac{f}{a_p x^p}\right)^k$を計算して最後に$a_p^kx^{kp}$を掛ければよいため、$f$の定数項が$1$である場合のみ考えればよい。このとき$f^k$は$f^k\equiv e^{(\log f)k}$から計算できる。

### 平方根

[fps/fps-sqrt.hpp](https://nyaannyaan.github.io/library/library/fps/fps-sqrt.hpp.html)にて解説。

### 三角関数

[fps/fps-circular.hpp](https://nyaannyaan.github.io/library/library/fps/fps-circular.hpp.html)にて解説。

### 平行移動

[fps/taylor-shift.hpp](https://nyaannyaan.github.io/library/library/fps/taylor-shift.hpp.html)にて解説。

### 階差(imos法)/累積和

(関数は未実装)
数列に対して階差を取る(imos法)、あるいはその逆に累積和を取ることを形式的冪級数の数式的な操作に置き換えると、それぞれ$1-x$を掛ける/割る操作に対応している。計算量はともに$\mathrm{O}(N)$である。


## Required by

* :heavy_check_mark: <a href="arbitrary-fps.hpp.html">fps/arbitrary-fps.hpp</a>
* :heavy_check_mark: <a href="differential-equation.hpp.html">常微分方程式 <small>(fps/differential-equation.hpp)</small></a>
* :warning: <a href="famous-series.hpp.html">fps/famous-series.hpp</a>
* :warning: <a href="fast-multieval.hpp.html">fps/fast-multieval.hpp</a>
* :heavy_check_mark: <a href="fps-circular.hpp.html">三角関数 <small>(fps/fps-circular.hpp)</small></a>
* :warning: <a href="fps-composition-fast.hpp.html">関数の合成( $\mathrm{O}(N^2)$ ) <small>(fps/fps-composition-fast.hpp)</small></a>
* :heavy_check_mark: <a href="fps-composition.hpp.html">関数の合成( $\mathrm{O}\left((N \log N)^{\frac{3}{2}}\right)$ ) <small>(fps/fps-composition.hpp)</small></a>
* :heavy_check_mark: <a href="fps-sqrt.hpp.html">平方根 <small>(fps/fps-sqrt.hpp)</small></a>
* :heavy_check_mark: <a href="kitamasa.hpp.html">線形漸化式の高速計算 <small>(fps/kitamasa.hpp)</small></a>
* :heavy_check_mark: <a href="multipoint-evaluation.hpp.html">fps/multipoint-evaluation.hpp</a>
* :heavy_check_mark: <a href="ntt-friendly-fps.hpp.html">fps/ntt-friendly-fps.hpp</a>
* :heavy_check_mark: <a href="polynomial-gcd.hpp.html">多項式GCD <small>(fps/polynomial-gcd.hpp)</small></a>
* :heavy_check_mark: <a href="polynomial-interpolation.hpp.html">fps/polynomial-interpolation.hpp</a>
* :heavy_check_mark: <a href="taylor-shift.hpp.html">平行移動 <small>(fps/taylor-shift.hpp)</small></a>
* :heavy_check_mark: <a href="utility.hpp.html">fps/utility.hpp</a>
* :warning: <a href="../modulo/strassen.hpp.html">modulo/strassen.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-composition.test.cpp.html">verify/verify-yosupo-fps/yosupo-composition.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-exp-arb.test.cpp.html">verify/verify-yosupo-fps/yosupo-exp-arb.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-exp.test.cpp.html">verify/verify-yosupo-fps/yosupo-exp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-interpolation.test.cpp.html">verify/verify-yosupo-fps/yosupo-interpolation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-inv-arb.test.cpp.html">verify/verify-yosupo-fps/yosupo-inv-arb.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp.html">verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-inv.test.cpp.html">verify/verify-yosupo-fps/yosupo-inv.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-log-arb.test.cpp.html">verify/verify-yosupo-fps/yosupo-log-arb.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-log.test.cpp.html">verify/verify-yosupo-fps/yosupo-log.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-multieval.test.cpp.html">verify/verify-yosupo-fps/yosupo-multieval.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-pow-arb.test.cpp.html">verify/verify-yosupo-fps/yosupo-pow-arb.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-pow.test.cpp.html">verify/verify-yosupo-fps/yosupo-pow.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-sqrt.test.cpp.html">verify/verify-yosupo-fps/yosupo-sqrt.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp.html">verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-0214.test.cpp.html">verify/verify-yuki/yuki-0214.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-0215.test.cpp.html">verify/verify-yuki/yuki-0215.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-0963-circular.test.cpp.html">verify/verify-yuki/yuki-0963-circular.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-0963.test.cpp.html">verify/verify-yuki/yuki-0963.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-1080.test.cpp.html">verify/verify-yuki/yuki-1080.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-1145.test.cpp.html">verify/verify-yuki/yuki-1145.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


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


# :heavy_check_mark: 関数の合成 <small>(fps/fps-composition.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/fps-composition.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-20 12:22:55+09:00





## 関数の合成

形式的冪級数$P(x),Q(x)$(ただし$P_0 = 0$)に対して$Q(P) \mod x^{n}$を$\mathrm{O}(\left(n\log n\right)^{\frac{3}{2}})$で求めるライブラリ。

[出典の論文](http://www.eecs.harvard.edu/~htk/publication/1978-jacm-brent-kung.pdf)

#### 概要

まず、$P$を$P = P_m + P_r,\ \ P_r \equiv 0 \mod x^m$を満たす$P_m,P_r$に分けて考える。($m$は後で値を決める。)この時、テイラー展開の式

$$Q(P)=\sum_{i=0}^\infty\frac{Q^{(i)}(P_m)}{i!}(P-P_m)^i=\sum_{i=0}^\infty\frac{Q^{(i)}(P_m)}{i!}(P_r)^i$$

の前$\lfloor\frac{n}{m}\rfloor$次の項を計算できればよいので($P_r \equiv 0 \mod x$に留意する)、$Q^{(i)}(P),0 \leq i \leq \lfloor\frac{n}{m}\rfloor$を高速に列挙できればよい。

まず、$Q(P(x))\mod x^n$は$\deg(Q) = j$($j$は2冪)とした時

$$Q(P) = Q_1(P) + P^{\frac{j}{2}}\cdot Q_2(P)$$

を利用して再帰的に求めることで$\mathrm{O}(jm\log^2 n)$で計算できる。また、$Q^{(i)}(P_m)$は連鎖律$\frac{d}{dx}Q(P) = \frac{dP} {dx} \cdot \frac{dQ}{dP}$を利用して

$$Q^{(i)}{(P_m)} \equiv \frac{\left(Q^{(i-1)}{(P_m)}\right)'}{P_m'} \mod x^{n-i}$$

より$\mathrm{O}(\lfloor\frac{n}{m}\rfloor n \log n)$で列挙できる。(実装においては、$m \geq 2$かつ$P$の$2$次の係数が$0$の時に$\frac{1}{P_m'}$が定義されないコーナーケースを意識して適切に逆元を取る必要がある。)

最後にテイラー展開の式に基づいて足し合わせる部分も愚直に計算すると$\mathrm{O}(\lfloor\frac{n}{m}\rfloor n \log n)$で計算できる。

以上より$j = n$とすると$\mathrm{O}(nm\log^2 n + \lfloor\frac{n}{m}\rfloor n \log n)$で$Q(P(x))$を計算することが出来た。ここで$m = \sqrt{\frac{n} {\log n}}$とおくと$\mathrm{O}(\left(n\log n\right)^{\frac{3}{2}})$となる。

###### 余談

実装してから思ったが、元の論文には行列積を使用した$O(\sqrt{N}\cdot T(\sqrt{N}))$($T(n)$は行列積のオーダー)のアルゴリズムも載っており、オーダーは実質2乗だがSIMDの利用などにより定数倍高速化が見込める。

$N \leq 8192$とすると、感覚的には解説したアルゴリズムよりも大きさ$100$の行列積$100回$の方が高速に動作する気がする…(まあそんなことを言い始めたらFFTよりkaratsubaの方が早いのでは？みたいな話になるのでキリがないけど…)


## Depends on

* :heavy_check_mark: <a href="formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>
* :heavy_check_mark: <a href="../modulo/binomial.hpp.html">modulo/binomial.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-composition.test.cpp.html">verify/verify-yosupo-fps/yosupo-composition.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "../modulo/binomial.hpp"
#include "./formal-power-series.hpp"

// find Q(P(x)) mod x ^ min(deg(P), deg(Q))
template <typename mint>
FormalPowerSeries<mint> Composition(FormalPowerSeries<mint> P,
                                    FormalPowerSeries<mint> Q,
                                    Binomial<mint>& C, int deg = -1) {
  using fps = FormalPowerSeries<mint>;
  int N = (deg == -1) ? min(P.size(), Q.size()) : deg;
  if (N == 0) return fps{};
  P.shrink();
  if (P.size() == 0) {
    fps R(N, mint(0));
    R[0] = Q.empty() ? mint(0) : Q[0];
    return R;
  }
  if (N == 1) return fps{Q.eval(P[0])};

  P.resize(N, mint(0));
  Q.resize(N, mint(0));
  int M = max<int>(1, sqrt(N / log2(N)));
  int L = (N + M - 1) / M;
  fps Pm = fps{begin(P), begin(P) + M};
  fps Pr = fps{begin(P) + M, end(P)};

  int J = 31 - __builtin_clz(N - 1) + 1;
  vector<fps> pms(J);
  pms[0] = Pm;
  for (int i = 1; i < J; i++) pms[i] = (pms[i - 1] * pms[i - 1]).pre(N);

  auto comp = [&](auto rec, int left, int j) -> fps {
    if (j == 1) {
      mint Q1 = left + 0 < (int)Q.size() ? Q[left + 0] : mint(0);
      mint Q2 = left + 1 < (int)Q.size() ? Q[left + 1] : mint(0);
      return (pms[0].pre(N) * Q2 + Q1).pre(N);
    }
    if (N <= left) return fps{};
    fps Q1 = rec(rec, left, j - 1);
    fps Q2 = rec(rec, left + (1 << (j - 1)), j - 1);
    return (Q1 + pms[j - 1].pre(N) * Q2).pre(N);
  };

  fps QPm = comp(comp, 0, J);
  fps R = QPm;
  fps pw_Pr{mint(1)};
  fps dPm = Pm.diff();
  dPm.shrink();
  // if dPm[0] == 0, dPm.inv() is undefined
  int deg_dPm = 0;
  while (deg_dPm != (int)dPm.size() && dPm[deg_dPm] == mint(0)) deg_dPm++;
  fps idPm = dPm.empty() ? fps{} : (dPm >> deg_dPm).inv(N);

  for (int l = 1, d = M; l <= L && d < N; l++, d += M) {
    pw_Pr = (pw_Pr * Pr).pre(N - d);
    if (dPm.empty()) {
      R += (pw_Pr * Q[l]) << d;
    } else {
      idPm.resize(N - d);
      QPm = ((QPm.diff().pre(N - d) >> deg_dPm) * idPm).pre(N - d);
      R += ((QPm * pw_Pr).pre(N - d) * C.finv(l)) << d;
    };
  }
  R.resize(N, mint(0));
  return R;
}

/**
 * @brief 関数の合成
 * @docs docs/fps/fps-composition.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "fps/fps-composition.hpp"
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
#line 6 "fps/fps-composition.hpp"

// find Q(P(x)) mod x ^ min(deg(P), deg(Q))
template <typename mint>
FormalPowerSeries<mint> Composition(FormalPowerSeries<mint> P,
                                    FormalPowerSeries<mint> Q,
                                    Binomial<mint>& C, int deg = -1) {
  using fps = FormalPowerSeries<mint>;
  int N = (deg == -1) ? min(P.size(), Q.size()) : deg;
  if (N == 0) return fps{};
  P.shrink();
  if (P.size() == 0) {
    fps R(N, mint(0));
    R[0] = Q.empty() ? mint(0) : Q[0];
    return R;
  }
  if (N == 1) return fps{Q.eval(P[0])};

  P.resize(N, mint(0));
  Q.resize(N, mint(0));
  int M = max<int>(1, sqrt(N / log2(N)));
  int L = (N + M - 1) / M;
  fps Pm = fps{begin(P), begin(P) + M};
  fps Pr = fps{begin(P) + M, end(P)};

  int J = 31 - __builtin_clz(N - 1) + 1;
  vector<fps> pms(J);
  pms[0] = Pm;
  for (int i = 1; i < J; i++) pms[i] = (pms[i - 1] * pms[i - 1]).pre(N);

  auto comp = [&](auto rec, int left, int j) -> fps {
    if (j == 1) {
      mint Q1 = left + 0 < (int)Q.size() ? Q[left + 0] : mint(0);
      mint Q2 = left + 1 < (int)Q.size() ? Q[left + 1] : mint(0);
      return (pms[0].pre(N) * Q2 + Q1).pre(N);
    }
    if (N <= left) return fps{};
    fps Q1 = rec(rec, left, j - 1);
    fps Q2 = rec(rec, left + (1 << (j - 1)), j - 1);
    return (Q1 + pms[j - 1].pre(N) * Q2).pre(N);
  };

  fps QPm = comp(comp, 0, J);
  fps R = QPm;
  fps pw_Pr{mint(1)};
  fps dPm = Pm.diff();
  dPm.shrink();
  // if dPm[0] == 0, dPm.inv() is undefined
  int deg_dPm = 0;
  while (deg_dPm != (int)dPm.size() && dPm[deg_dPm] == mint(0)) deg_dPm++;
  fps idPm = dPm.empty() ? fps{} : (dPm >> deg_dPm).inv(N);

  for (int l = 1, d = M; l <= L && d < N; l++, d += M) {
    pw_Pr = (pw_Pr * Pr).pre(N - d);
    if (dPm.empty()) {
      R += (pw_Pr * Q[l]) << d;
    } else {
      idPm.resize(N - d);
      QPm = ((QPm.diff().pre(N - d) >> deg_dPm) * idPm).pre(N - d);
      R += ((QPm * pw_Pr).pre(N - d) * C.finv(l)) << d;
    };
  }
  R.resize(N, mint(0));
  return R;
}

/**
 * @brief 関数の合成
 * @docs docs/fps/fps-composition.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


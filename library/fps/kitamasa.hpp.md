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


# :heavy_check_mark: 線形漸化式の高速計算 <small>(fps/kitamasa.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/kitamasa.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-20 12:22:55+09:00




## 線形漸化式の第$N$項を高速に求めるライブラリ

$k$項間漸化式

$$a_n = c_1a_{n-1}+c_2a_{n-2} \ldots + c_ka_{n-k}$$

の第$N$項は

$$Q(x)=1-c_1x-c_2x^2-\ldots -c_kx^k$$

$$P(x)=Q(x)(a_0+a_1x+a_2x^2+\ldots) \mod x^k$$

と置いたとき

$$a_N = [x^N]\frac{P(x)}{Q(x)}$$

になり、これは[リンク先のアルゴリズム](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)を使って$\mathrm{O}(N \log k \log N)$で計算できる。

さらに、もし素数$p$がNTT素数だった場合は1回のループ当たりの操作が長さQの畳み込み4回で済むので、愚直なアルゴリズム(ループ当たり計算量$2M(n)$)に対して3倍(計算量$2/3M(n)$)の高速化が見込める。(詳細は実装を参考のこと。)

verify(AtCoder 双子コン#3 G フィボナッチ数の総和) $\mathrm{O}(N \log k \log N), N=200000,k=10^{18}$
- [ナイーブな実装](https://atcoder.jp/contests/s8pc-3/submissions/15526069) 1846ms
- [高速化した場合](https://atcoder.jp/contests/s8pc-3/submissions/15520531) 631ms


## Depends on

* :heavy_check_mark: <a href="formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-0214.test.cpp.html">verify/verify-yuki/yuki-0214.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-0215.test.cpp.html">verify/verify-yuki/yuki-0215.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "formal-power-series.hpp"

template <typename mint>
mint LinearRecursionFormula(long long k, FormalPowerSeries<mint> Q,
                            FormalPowerSeries<mint> P) {
  Q.shrink();
  mint ret = 0;
  if (P.size() >= Q.size()) {
    auto R = P / Q;
    P -= R * Q;
    P.shrink();
    if (k < (int)R.size()) ret += R[k];
  }
  if ((int)P.size() == 0) return ret;

  FormalPowerSeries<mint>::set_fft();
  if (FormalPowerSeries<mint>::ntt_ptr == nullptr) {
    P.resize((int)Q.size() - 1);
    while (k) {
      auto Q2 = Q;
      for (int i = 1; i < (int)Q2.size(); i += 2) Q2[i] = -Q2[i];
      auto S = P * Q2;
      auto T = Q * Q2;
      if (k & 1) {
        for (int i = 1; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
        for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
      } else {
        for (int i = 0; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
        for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
      }
      k >>= 1;
    }
    return ret + P[0];
  } else {
    int N = 1;
    while (N < (int)Q.size()) N <<= 1;

    P.resize(2 * N);
    Q.resize(2 * N);
    P.ntt();
    Q.ntt();
    vector<mint> S(2 * N), T(2 * N);

    vector<int> btr(N);
    for (int i = 0, logn = __builtin_ctz(N); i < (1 << logn); i++) {
      btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (logn - 1));
    }
    mint dw = mint(FormalPowerSeries<mint>::ntt_pr())
                  .inverse()
                  .pow((mint::get_mod() - 1) / (2 * N));

    while (k) {
      mint inv2 = mint(2).inverse();

      // even degree of Q(x)Q(-x)
      T.resize(N);
      for (int i = 0; i < N; i++) T[i] = Q[(i << 1) | 0] * Q[(i << 1) | 1];

      S.resize(N);
      if (k & 1) {
        // odd degree of P(x)Q(-x)
        for (auto &i : btr) {
          S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] -
                  P[(i << 1) | 1] * Q[(i << 1) | 0]) *
                 inv2;
          inv2 *= dw;
        }
      } else {
        // even degree of P(x)Q(-x)
        for (int i = 0; i < N; i++) {
          S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] +
                  P[(i << 1) | 1] * Q[(i << 1) | 0]) *
                 inv2;
        }
      }
      swap(P, S);
      swap(Q, T);
      k >>= 1;
      if (k < N) break;
      P.ntt_doubling();
      Q.ntt_doubling();
    }
    P.intt();
    Q.intt();
    return ret + (P * (Q.inv()))[k];
  }
}

template <typename mint>
mint kitamasa(long long N, FormalPowerSeries<mint> Q,
              FormalPowerSeries<mint> a) {
  int k = Q.size() - 1;
  assert((int)a.size() == k);
  auto P = a * Q;
  P.resize(Q.size() - 1);
  return LinearRecursionFormula<mint>(N, Q, P);
}

/**
 * @brief 線形漸化式の高速計算
 * @docs docs/linear-recursive.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "fps/kitamasa.hpp"
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
#line 6 "fps/kitamasa.hpp"

template <typename mint>
mint LinearRecursionFormula(long long k, FormalPowerSeries<mint> Q,
                            FormalPowerSeries<mint> P) {
  Q.shrink();
  mint ret = 0;
  if (P.size() >= Q.size()) {
    auto R = P / Q;
    P -= R * Q;
    P.shrink();
    if (k < (int)R.size()) ret += R[k];
  }
  if ((int)P.size() == 0) return ret;

  FormalPowerSeries<mint>::set_fft();
  if (FormalPowerSeries<mint>::ntt_ptr == nullptr) {
    P.resize((int)Q.size() - 1);
    while (k) {
      auto Q2 = Q;
      for (int i = 1; i < (int)Q2.size(); i += 2) Q2[i] = -Q2[i];
      auto S = P * Q2;
      auto T = Q * Q2;
      if (k & 1) {
        for (int i = 1; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
        for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
      } else {
        for (int i = 0; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
        for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
      }
      k >>= 1;
    }
    return ret + P[0];
  } else {
    int N = 1;
    while (N < (int)Q.size()) N <<= 1;

    P.resize(2 * N);
    Q.resize(2 * N);
    P.ntt();
    Q.ntt();
    vector<mint> S(2 * N), T(2 * N);

    vector<int> btr(N);
    for (int i = 0, logn = __builtin_ctz(N); i < (1 << logn); i++) {
      btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (logn - 1));
    }
    mint dw = mint(FormalPowerSeries<mint>::ntt_pr())
                  .inverse()
                  .pow((mint::get_mod() - 1) / (2 * N));

    while (k) {
      mint inv2 = mint(2).inverse();

      // even degree of Q(x)Q(-x)
      T.resize(N);
      for (int i = 0; i < N; i++) T[i] = Q[(i << 1) | 0] * Q[(i << 1) | 1];

      S.resize(N);
      if (k & 1) {
        // odd degree of P(x)Q(-x)
        for (auto &i : btr) {
          S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] -
                  P[(i << 1) | 1] * Q[(i << 1) | 0]) *
                 inv2;
          inv2 *= dw;
        }
      } else {
        // even degree of P(x)Q(-x)
        for (int i = 0; i < N; i++) {
          S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] +
                  P[(i << 1) | 1] * Q[(i << 1) | 0]) *
                 inv2;
        }
      }
      swap(P, S);
      swap(Q, T);
      k >>= 1;
      if (k < N) break;
      P.ntt_doubling();
      Q.ntt_doubling();
    }
    P.intt();
    Q.intt();
    return ret + (P * (Q.inv()))[k];
  }
}

template <typename mint>
mint kitamasa(long long N, FormalPowerSeries<mint> Q,
              FormalPowerSeries<mint> a) {
  int k = Q.size() - 1;
  assert((int)a.size() == k);
  auto P = a * Q;
  P.resize(Q.size() - 1);
  return LinearRecursionFormula<mint>(N, Q, P);
}

/**
 * @brief 線形漸化式の高速計算
 * @docs docs/linear-recursive.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


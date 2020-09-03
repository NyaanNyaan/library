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


# :warning: 関数の合成( $\mathrm{O}(N^2)$ ) <small>(fps/fps-composition-fast.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/fps-composition-fast.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 03:20:25+09:00




## Depends on

* :heavy_check_mark: <a href="formal-power-series.hpp.html">多項式/形式的冪級数ライブラリ <small>(fps/formal-power-series.hpp)</small></a>
* :warning: <a href="../misc/timer.hpp.html">misc/timer.hpp</a>
* :question: <a href="../modint/montgomery-modint.hpp.html">modint/montgomery-modint.hpp</a>
* :heavy_check_mark: <a href="../modint/simd-montgomery.hpp.html">modint/simd-montgomery.hpp</a>
* :warning: <a href="../modulo/strassen.hpp.html">modulo/strassen.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../fps/formal-power-series.hpp"
#include "../modint/montgomery-modint.hpp"
#include "../modulo/strassen.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) fps Composition(
    fps P, fps Q, int deg = -1) {
  int N = (deg == -1) ? min(P.size(), Q.size()) : deg;
  if (N == 0) return fps{};
  P.shrink();
  if (P.size() == 0) {
    fps R(N, mint(0));
    R[0] = Q.empty() ? mint(0) : Q[0];
    return R;
  }
  if (N == 1) return fps{Q.eval(P[0])};

  int K = max<int>(ceil(sqrt(N)), 2);
  assert(N <= K * K);

  vector<fps> PS(K + 1);
  {
    // step 1
    PS[0].resize(N, mint());
    PS[0][0] = 1;
    PS[1] = P;
    fps::set_fft();
    if (fps::ntt_ptr == nullptr) {
      for (int i = 2; i <= K; i++) PS[i] = (PS[i - 1] * P).pre(N);
    } else {
      int len = 1 << (32 - __builtin_clz(2 * N - 2));
      fps Pomega = P;
      Pomega.resize(len);
      Pomega.ntt();
      for (int i = 2; i <= K; i++) {
        PS[i].resize(len);
        for (int j = 0; j < N; j++) PS[i][j] = PS[i - 1][j];
        PS[i].ntt();
        for (int j = 0; j < len; j++) PS[i][j] *= Pomega[j];
        PS[i].intt();
        PS[i].resize(N);
        PS[i].shrink_to_fit();
      }
    }
  }

  vector<fps> TS(K);
  {
    // step 2
    TS[0].resize(N, mint());
    TS[0][0] = 1;
    TS[1] = PS[K];
    if (fps::ntt_ptr == nullptr) {
      for (int i = 2; i < K; i++) TS[i] = (TS[i - 1] * TS[1]).pre(N);
    } else {
      int len = 1 << (32 - __builtin_clz(2 * N - 2));
      fps Tomega = TS[1];
      Tomega.resize(len);
      Tomega.ntt();
      for (int i = 2; i < K; i++) {
        TS[i].resize(len);
        for (int j = 0; j < N; j++) TS[i][j] = TS[i - 1][j];
        TS[i].ntt();
        for (int j = 0; j < len; j++) TS[i][j] *= Tomega[j];
        TS[i].intt();
        TS[i].resize(N);
        TS[i].shrink_to_fit();
      }
    }
  }

  // step 3
  vector<fps> QP;
  {
    PS.pop_back();
    vector<fps> QS(K, fps(K, mint()));
    for (int i = 0; i < K; i++)
      for (int j = 0; j < K; j++) {
        QS[i][j] = (i * K + j) < (int)Q.size() ? Q[i * K + j] : mint();
      }
    QP = FastMatProd::strassen(QS, PS);
  }

  fps ans(N, mint());
  {
    // step 4,5
    for (int i = 0; i < K; i++) ans += (QP[i] * TS[i]).pre(N);
  }
  return ans;
}

/**
 * @brief 関数の合成( $\mathrm{O}(N^2)$ )
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
#line 2 "modulo/strassen.hpp"
#include <immintrin.h>
//
#line 5 "modulo/strassen.hpp"
using namespace std;

#line 3 "modint/simd-montgomery.hpp"
using namespace std;
#line 5 "modint/simd-montgomery.hpp"

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
my128_mullo_epu32(const __m128i &a, const __m128i &b) {
  return _mm_mullo_epi32(a, b);
}

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
my128_mulhi_epu32(const __m128i &a, const __m128i &b) {
  __m128i a13 = _mm_shuffle_epi32(a, 0xF5);
  __m128i b13 = _mm_shuffle_epi32(b, 0xF5);
  __m128i prod02 = _mm_mul_epu32(a, b);
  __m128i prod13 = _mm_mul_epu32(a13, b13);
  __m128i prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02, prod13),
                                    _mm_unpackhi_epi32(prod02, prod13));
  return prod;
}

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
montgomery_mul_128(const __m128i &a, const __m128i &b, const __m128i &r,
                   const __m128i &m1) {
  return _mm_sub_epi32(
      _mm_add_epi32(my128_mulhi_epu32(a, b), m1),
      my128_mulhi_epu32(my128_mullo_epu32(my128_mullo_epu32(a, b), r), m1));
}

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
montgomery_add_128(const __m128i &a, const __m128i &b, const __m128i &m2,
                   const __m128i &m0) {
  __m128i ret = _mm_sub_epi32(_mm_add_epi32(a, b), m2);
  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
montgomery_sub_128(const __m128i &a, const __m128i &b, const __m128i &m2,
                   const __m128i &m0) {
  __m128i ret = _mm_sub_epi32(a, b);
  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("avx2"))) __attribute__((always_inline)) __m256i
my256_mullo_epu32(const __m256i &a, const __m256i &b) {
  return _mm256_mullo_epi32(a, b);
}

__attribute__((target("avx2"))) __attribute__((always_inline)) __m256i
my256_mulhi_epu32(const __m256i &a, const __m256i &b) {
  __m256i a13 = _mm256_shuffle_epi32(a, 0xF5);
  __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);
  __m256i prod02 = _mm256_mul_epu32(a, b);
  __m256i prod13 = _mm256_mul_epu32(a13, b13);
  __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02, prod13),
                                       _mm256_unpackhi_epi32(prod02, prod13));
  return prod;
}

__attribute__((target("avx2"))) __attribute__((always_inline)) __m256i
montgomery_mul_256(const __m256i &a, const __m256i &b, const __m256i &r,
                   const __m256i &m1) {
  return _mm256_sub_epi32(
      _mm256_add_epi32(my256_mulhi_epu32(a, b), m1),
      my256_mulhi_epu32(my256_mullo_epu32(my256_mullo_epu32(a, b), r), m1));
}

__attribute__((target("avx2"))) __attribute__((always_inline)) __m256i
montgomery_add_256(const __m256i &a, const __m256i &b, const __m256i &m2,
                   const __m256i &m0) {
  __m256i ret = _mm256_sub_epi32(_mm256_add_epi32(a, b), m2);
  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0, ret), m2),
                          ret);
}

__attribute__((target("avx2"))) __attribute__((always_inline)) __m256i
montgomery_sub_256(const __m256i &a, const __m256i &b, const __m256i &m2,
                   const __m256i &m0) {
  __m256i ret = _mm256_sub_epi32(a, b);
  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0, ret), m2),
                          ret);
}
#line 10 "modulo/strassen.hpp"

namespace FastMatProd {

using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;
using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using m256 = __m256i;

constexpr u32 SHIFT_ = 6;
u32 a[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));
u32 b[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));
u32 c[1 << (SHIFT_ * 2)] __attribute__((aligned(64)));

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
inner_simd_mul(u32 n, u32 m, u32 p) {
  memset(c, 0, sizeof(c));
  const m256 R = _mm256_set1_epi32(mint::r);
  const m256 M0 = _mm256_set1_epi32(0);
  const m256 M1 = _mm256_set1_epi32(mint::get_mod());
  const m256 M2 = _mm256_set1_epi32(mint::get_mod() << 1);

  u32 k0 = 0;
  for (; i32(k0) < i32(p) - 3; k0 += 4) {
    const u32 k1 = k0 + 1;
    const u32 k2 = k0 + 2;
    const u32 k3 = k0 + 3;
    u32 j0 = 0;
    for (; i32(j0) < i32(m) - 7; j0 += 8) {
      const m256 B00 = _mm256_load_si256((m256*)(b + (k0 << SHIFT_) + j0));
      const m256 B10 = _mm256_load_si256((m256*)(b + (k1 << SHIFT_) + j0));
      const m256 B20 = _mm256_load_si256((m256*)(b + (k2 << SHIFT_) + j0));
      const m256 B30 = _mm256_load_si256((m256*)(b + (k3 << SHIFT_) + j0));
      for (u32 i0 = 0; i0 < n; ++i0) {
        const m256 A00 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k0]);
        const m256 A01 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k1]);
        const m256 A02 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k2]);
        const m256 A03 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k3]);
        const m256 A00B00 = montgomery_mul_256(A00, B00, R, M1);
        const m256 A01B10 = montgomery_mul_256(A01, B10, R, M1);
        const m256 A02B20 = montgomery_mul_256(A02, B20, R, M1);
        const m256 A03B30 = montgomery_mul_256(A03, B30, R, M1);
        const u32* pc00 = c + (i0 << SHIFT_) + j0;
        const m256 C00 = _mm256_load_si256((m256*)pc00);
        const m256 C00_01 = montgomery_add_256(A00B00, A01B10, M2, M0);
        const m256 C00_23 = montgomery_add_256(A02B20, A03B30, M2, M0);
        const m256 C00_al = montgomery_add_256(C00_01, C00_23, M2, M0);
        const m256 C00_ad = montgomery_add_256(C00, C00_al, M2, M0);
        _mm256_store_si256((m256*)pc00, C00_ad);
      }
    }
    for (; j0 < m; j0++) {
      for (u32 i0 = 0; i0 < n; ++i0) {
        u32 ab0 =
            mint::reduce(u64(a[(i0 << SHIFT_) | k0]) * b[(k0 << SHIFT_) | j0]);
        u32 ab1 =
            mint::reduce(u64(a[(i0 << SHIFT_) | k1]) * b[(k1 << SHIFT_) | j0]);
        u32 ab2 =
            mint::reduce(u64(a[(i0 << SHIFT_) | k2]) * b[(k2 << SHIFT_) | j0]);
        u32 ab3 =
            mint::reduce(u64(a[(i0 << SHIFT_) | k3]) * b[(k3 << SHIFT_) | j0]);
        if ((ab0 += ab1) >= 2 * mint::get_mod()) ab0 -= 2 * mint::get_mod();
        if ((ab2 += ab3) >= 2 * mint::get_mod()) ab2 -= 2 * mint::get_mod();
        if ((ab0 += ab2) >= 2 * mint::get_mod()) ab0 -= 2 * mint::get_mod();
        if ((c[(i0 << SHIFT_) | j0] += ab0) >= 2 * mint::get_mod())
          c[(i0 << SHIFT_) | j0] -= 2 * mint::get_mod();
      }
    }
  }

  for (; k0 < p; k0++) {
    u32 j0 = 0;
    for (; i32(j0) < i32(m) - 7; j0 += 8) {
      const m256 B00 = _mm256_load_si256((m256*)(b + (k0 << SHIFT_) + j0));
      for (u32 i0 = 0; i0 < n; ++i0) {
        const m256 A00 = _mm256_set1_epi32(a[(i0 << SHIFT_) | k0]);
        const m256 A00B00 = montgomery_mul_256(A00, B00, R, M1);
        const u32* pc00 = c + (i0 << SHIFT_) + j0;
        const m256 C00 = _mm256_load_si256((m256*)pc00);
        const m256 C00_ad = montgomery_add_256(C00, A00B00, M2, M0);
        _mm256_store_si256((m256*)pc00, C00_ad);
      }
    }
    for (; j0 < m; j0++) {
      for (u32 i0 = 0; i0 < n; ++i0) {
        u32 ab0 =
            mint::reduce(u64(a[(i0 << SHIFT_) | k0]) * b[(k0 << SHIFT_) | j0]);
        if ((c[(i0 << SHIFT_) | j0] += ab0) >= 2 * mint::get_mod())
          c[(i0 << SHIFT_) | j0] -= 2 * mint::get_mod();
      }
    }
  }
}

// for debug
__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vvm naive_mul(
    const vvm& a, const vvm& b) {
  int n = a.size(), m = b[0].size(), p = b.size();
  assert(p == (int)a[0].size());
  vvm c(n, fps(m, 0));
  for (int i = 0; i < n; i++)
    for (int k = 0; k < p; k++)
      for (int j = 0; j < m; j++) c[i][j] += a[i][k] * b[k][j];
  return c;
}

struct Mat {
  int H, W, HM, WM;
  mint* a;

  Mat(int H_, int W_, mint* a_) : H(H_), W(W_), a(a_) {
    HM = (H >> 1) + (H & 1);
    WM = (W >> 1) + (W & 1);
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
  range_add(mint* b, int as, int ae, int bs) const {
    const m256 M0 = _mm256_set1_epi32(0);
    const m256 M2 = _mm256_set1_epi32(mint::get_mod() * 2);
    for (; as < ae - 31; as += 32, bs += 32) {
      int a0 = as;
      int a1 = as + 8;
      int a2 = as + 16;
      int a3 = as + 24;
      int b0 = bs;
      int b1 = bs + 8;
      int b2 = bs + 16;
      int b3 = bs + 24;
      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));
      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));
      const m256 A2 = _mm256_loadu_si256((m256*)(a + a2));
      const m256 A3 = _mm256_loadu_si256((m256*)(a + a3));
      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));
      const m256 BA0 = montgomery_add_256(B0, A0, M2, M0);
      const m256 BA1 = montgomery_add_256(B1, A1, M2, M0);
      const m256 BA2 = montgomery_add_256(B2, A2, M2, M0);
      const m256 BA3 = montgomery_add_256(B3, A3, M2, M0);
      _mm256_storeu_si256((m256*)(b + b0), BA0);
      _mm256_storeu_si256((m256*)(b + b1), BA1);
      _mm256_storeu_si256((m256*)(b + b2), BA2);
      _mm256_storeu_si256((m256*)(b + b3), BA3);
    }
    for (; as < ae; ++as, ++bs) b[bs] += a[as];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
  range_sub(mint* b, int as, int ae, int bs) const {
    const m256 M0 = _mm256_set1_epi32(0);
    const m256 M2 = _mm256_set1_epi32(mint::get_mod() * 2);
    for (; as < ae - 31; as += 32, bs += 32) {
      int a0 = as;
      int a1 = as + 8;
      int a2 = as + 16;
      int a3 = as + 24;
      int b0 = bs;
      int b1 = bs + 8;
      int b2 = bs + 16;
      int b3 = bs + 24;
      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));
      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));
      const m256 A2 = _mm256_loadu_si256((m256*)(a + a2));
      const m256 A3 = _mm256_loadu_si256((m256*)(a + a3));
      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));
      const m256 BA0 = montgomery_sub_256(B0, A0, M2, M0);
      const m256 BA1 = montgomery_sub_256(B1, A1, M2, M0);
      const m256 BA2 = montgomery_sub_256(B2, A2, M2, M0);
      const m256 BA3 = montgomery_sub_256(B3, A3, M2, M0);
      _mm256_storeu_si256((m256*)(b + b0), BA0);
      _mm256_storeu_si256((m256*)(b + b1), BA1);
      _mm256_storeu_si256((m256*)(b + b2), BA2);
      _mm256_storeu_si256((m256*)(b + b3), BA3);
    }
    for (; as < ae; ++as, ++bs) b[bs] -= a[as];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
  op_range_add(mint* b, int as, int ae, int bs) const {
    const m256 M0 = _mm256_set1_epi32(0);
    const m256 M2 = _mm256_set1_epi32(mint::get_mod() * 2);
    for (; as < ae - 31; as += 32, bs += 32) {
      int a0 = as;
      int a1 = as + 8;
      int a2 = as + 16;
      int a3 = as + 24;
      int b0 = bs;
      int b1 = bs + 8;
      int b2 = bs + 16;
      int b3 = bs + 24;
      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));
      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));
      const m256 A2 = _mm256_loadu_si256((m256*)(a + a2));
      const m256 A3 = _mm256_loadu_si256((m256*)(a + a3));
      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));
      const m256 BA0 = montgomery_add_256(B0, A0, M2, M0);
      const m256 BA1 = montgomery_add_256(B1, A1, M2, M0);
      const m256 BA2 = montgomery_add_256(B2, A2, M2, M0);
      const m256 BA3 = montgomery_add_256(B3, A3, M2, M0);
      _mm256_storeu_si256((m256*)(a + a0), BA0);
      _mm256_storeu_si256((m256*)(a + a1), BA1);
      _mm256_storeu_si256((m256*)(a + a2), BA2);
      _mm256_storeu_si256((m256*)(a + a3), BA3);
    }
    for (; as < ae; ++as, ++bs) a[as] += b[bs];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
  op_range_sub(mint* b, int as, int ae, int bs) const {
    const m256 M0 = _mm256_set1_epi32(0);
    const m256 M2 = _mm256_set1_epi32(mint::get_mod() * 2);
    for (; as < ae - 31; as += 32, bs += 32) {
      int a0 = as;
      int a1 = as + 8;
      int a2 = as + 16;
      int a3 = as + 24;
      int b0 = bs;
      int b1 = bs + 8;
      int b2 = bs + 16;
      int b3 = bs + 24;
      const m256 A0 = _mm256_loadu_si256((m256*)(a + a0));
      const m256 A1 = _mm256_loadu_si256((m256*)(a + a1));
      const m256 A2 = _mm256_loadu_si256((m256*)(a + a2));
      const m256 A3 = _mm256_loadu_si256((m256*)(a + a3));
      const m256 B0 = _mm256_loadu_si256((m256*)(b + b0));
      const m256 B1 = _mm256_loadu_si256((m256*)(b + b1));
      const m256 B2 = _mm256_loadu_si256((m256*)(b + b2));
      const m256 B3 = _mm256_loadu_si256((m256*)(b + b3));
      const m256 BA0 = montgomery_sub_256(A0, B0, M2, M0);
      const m256 BA1 = montgomery_sub_256(A1, B1, M2, M0);
      const m256 BA2 = montgomery_sub_256(A2, B2, M2, M0);
      const m256 BA3 = montgomery_sub_256(A3, B3, M2, M0);
      _mm256_storeu_si256((m256*)(a + a0), BA0);
      _mm256_storeu_si256((m256*)(a + a1), BA1);
      _mm256_storeu_si256((m256*)(a + a2), BA2);
      _mm256_storeu_si256((m256*)(a + a3), BA3);
    }
    for (; as < ae; ++as, ++bs) a[as] -= b[bs];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A11(mint* b) const {
    for (int i = 0; i < HM; i++)
      memcpy(b + i * WM, a + i * W, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A12(mint* b) const {
    for (int i = 0; i < HM; i++)
      memcpy(b + i * WM, a + i * W + WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A21(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(b + i * WM, a + (i + HM) * W, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  A22(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(b + i * WM, a + (i + HM) * W + WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  subA11(mint* b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W;
      int ae = i * W + WM;
      int bs = i * WM;
      range_sub(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  addA12(mint* b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W + WM;
      int ae = i * W + W;
      int bs = i * WM;
      range_add(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  addA22(mint* b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W + WM;
      int ae = as + W - WM;
      int bs = i * WM;
      range_add(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  subA22(mint* b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W + WM;
      int ae = as + W - WM;
      int bs = i * WM;
      range_sub(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA11(mint* b) const {
    for (int i = 0; i < HM; i++)
      memcpy(a + i * W, b + i * WM, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA12(mint* b) const {
    for (int i = 0; i < HM; i++)
      memcpy(a + i * W + WM, b + i * WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA21(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(a + (i + HM) * W, b + i * WM, WM * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  updA22(mint* b) const {
    for (int i = 0; i < H - HM; i++)
      memcpy(a + (i + HM) * W + WM, b + i * WM, (W - WM) * sizeof(int));
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA11(mint* b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W;
      int ae = i * W + WM;
      int bs = i * WM;
      op_range_add(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA12(mint* b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W + WM;
      int ae = i * W + W;
      int bs = i * WM;
      op_range_add(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA21(mint* b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W;
      int ae = (i + HM) * W + WM;
      int bs = i * WM;
      op_range_add(b, as, ae, bs);
    }
    //  for (int j = 0; j < WM; j++) a[(i + HM) * W + j] += b[i * WM + j];
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opaddA22(mint* b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W + WM;
      int ae = (i + HM) * W + W;
      int bs = i * WM;
      op_range_add(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opsubA11(mint* b) const {
    for (int i = 0; i < HM; i++) {
      int as = i * W;
      int ae = i * W + WM;
      int bs = i * WM;
      op_range_sub(b, as, ae, bs);
    }
  }

  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) inline void
  opsubA22(mint* b) const {
    for (int i = 0; i < H - HM; i++) {
      int as = (i + HM) * W + WM;
      int ae = (i + HM) * W + W;
      int bs = i * WM;
      op_range_sub(b, as, ae, bs);
    }
  }

  void dump() const {
    cerr << "[ " << endl << " ";
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)
        cerr << a[i * W + j] << (j == W - 1 ? ",\n " : " ");
    cerr << "] " << endl;
  }
};

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (1 << 21)
#endif
mint A[BUFFER_SIZE] __attribute__((aligned(64)));
mint B[BUFFER_SIZE] __attribute__((aligned(64)));
mint C[BUFFER_SIZE] __attribute__((aligned(64)));

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
inner_fast_mul(const Mat* s, const Mat* t, const Mat* u) {
  int n = s->H, m = t->W, p = s->W;
  for (int i = 0; i < n; i++)
    memcpy((mint*)(a + (i << SHIFT_)), s->a + i * p, p * sizeof(int));
  for (int i = 0; i < p; i++)
    memcpy((mint*)(b + (i << SHIFT_)), t->a + i * m, m * sizeof(int));
  inner_simd_mul(n, m, p);
  for (int i = 0; i < n; i++)
    memcpy(u->a + i * m, (mint*)(c + (i << SHIFT_)), m * sizeof(int));
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
inner_block_dec_mul(const Mat* s, const Mat* t, const Mat* u) {
  int n = s->H, m = t->W, p = s->W;
  memset((int*)(u->a), 0, n * m * sizeof(int));
  for (int is = 0; is < n; is += (1 << SHIFT_))
    for (int ks = 0; ks < p; ks += (1 << SHIFT_))
      for (int js = 0; js < m; js += (1 << SHIFT_)) {
        int ie = min(is + (1 << SHIFT_), n);
        int je = min(js + (1 << SHIFT_), m);
        int ke = min(ks + (1 << SHIFT_), p);
        for (int l = is; l < ie; l++)
          memcpy((mint*)(a + ((l - is) << SHIFT_)), s->a + l * p + ks,
                 (ke - ks) * sizeof(int));
        for (int l = ks; l < ke; l++)
          memcpy((mint*)(b + ((l - ks) << SHIFT_)), t->a + l * m + js,
                 (je - js) * sizeof(int));
        inner_simd_mul(ie - is, je - js, ke - ks);
        for (int l = is; l < ie; l++) {
          for (int ll = js; ll < je; ll++) {
            u->a[l * m + ll] +=
                *reinterpret_cast<mint*>(c + ((l - is) << SHIFT_) + (ll - js));
          }
        }
      }
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) void
inner_strassen(const Mat* a, const Mat* b, const Mat* c) {
  int n = a->H, m = b->W, p = a->W;
  if (max({n, m, p}) <= (1 << SHIFT_)) {
    inner_fast_mul(a, b, c);
    return;
  }
  if (min({n, m, p}) <= (1 << (SHIFT_ - 2))) {
    inner_block_dec_mul(a, b, c);
    return;
  }
  int nm = n / 2 + (n & 1);
  int mm = m / 2 + (m & 1);
  int pm = p / 2 + (p & 1);

  Mat s(nm, pm, a->a + n * p);
  Mat t(pm, mm, b->a + p * m);
  Mat u(nm, mm, c->a + n * m);

  // P1 = (A11 + A22) * (B11 + B22)
  a->A11(s.a);
  a->addA22(s.a);
  b->A11(t.a);
  b->addA22(t.a);
  inner_strassen(&s, &t, &u);
  c->updA11(u.a);
  c->updA22(u.a);

  // P2 = (A21 + A22) * B11
  memset((int*)s.a, 0, nm * pm * sizeof(int));
  a->A21(s.a);
  a->addA22(s.a);
  b->A11(t.a);
  inner_strassen(&s, &t, &u);
  c->updA21(u.a);
  c->opsubA22(u.a);

  // P3 = A11 (B12 - B22)
  a->A11(s.a);
  memset((int*)t.a, 0, pm * mm * sizeof(int));
  b->A12(t.a);
  b->subA22(t.a);
  inner_strassen(&s, &t, &u);
  c->updA12(u.a);
  c->opaddA22(u.a);

  // P4 = A22 (B21 - B11)
  memset((int*)s.a, 0, nm * pm * sizeof(int));
  a->A22(s.a);
  memset((int*)t.a + (pm - 1) * mm, 0, mm * sizeof(int));
  b->A21(t.a);
  b->subA11(t.a);
  inner_strassen(&s, &t, &u);
  c->opaddA11(u.a);
  c->opaddA21(u.a);

  // P5 = (A11 + A12) B22
  memset((int*)t.a, 0, pm * mm * sizeof(int));
  a->A11(s.a);
  a->addA12(s.a);
  b->A22(t.a);
  inner_strassen(&s, &t, &u);
  c->opsubA11(u.a);
  c->opaddA12(u.a);

  // P6 = (A21 - A11) (B11 + B12)
  memset((int*)s.a + (nm - 1) * pm, 0, pm * sizeof(int));
  a->A21(s.a);
  a->subA11(s.a);
  b->A11(t.a);
  b->addA12(t.a);
  inner_strassen(&s, &t, &u);
  c->opaddA22(u.a);

  // P7 = (A12 - A22) (B21 + B22)
  memset((int*)s.a, 0, nm * pm * sizeof(int));
  a->A12(s.a);
  a->subA22(s.a);
  memset((int*)t.a + (pm - 1) * mm, 0, mm * sizeof(int));
  b->A21(t.a);
  b->addA22(t.a);
  inner_strassen(&s, &t, &u);
  c->opaddA11(u.a);
}

using vfps = vector<fps>;

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vvm block_dec(
    const vvm& s, const vvm& t) {
  int n = s.size(), p = s[0].size(), m = t[0].size();
  assert(int(n * p * 1.4) <= BUFFER_SIZE);
  assert(int(p * m * 1.4) <= BUFFER_SIZE);
  assert(int(n * m * 1.4) <= BUFFER_SIZE);
  memset(A, 0, int(n * p * 1.4) * sizeof(int));
  memset(B, 0, int(p * m * 1.4) * sizeof(int));
  memset(C, 0, int(m * n * 1.4) * sizeof(int));

  for (int i = 0; i < n; i++) memcpy(A + i * p, s[i].data(), p * sizeof(int));
  for (int i = 0; i < p; i++) memcpy(B + i * m, t[i].data(), m * sizeof(int));

  Mat S(n, p, A), T(p, m, B), U(n, m, C);
  inner_block_dec_mul(&S, &T, &U);
  vvm u(n, vm(m));
  for (int i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));
  return std::move(u);
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vfps block_dec(
    const vfps& s, const vfps& t) {
  int n = s.size(), p = s[0].size(), m = t[0].size();
  assert(int(n * p * 1.4) <= BUFFER_SIZE);
  assert(int(p * m * 1.4) <= BUFFER_SIZE);
  assert(int(n * m * 1.4) <= BUFFER_SIZE);
  memset(A, 0, int(n * p * 1.4) * sizeof(int));
  memset(B, 0, int(p * m * 1.4) * sizeof(int));
  memset(C, 0, int(m * n * 1.4) * sizeof(int));

  for (int i = 0; i < n; i++) memcpy(A + i * p, s[i].data(), p * sizeof(int));
  for (int i = 0; i < p; i++) memcpy(B + i * m, t[i].data(), m * sizeof(int));

  Mat S(n, p, A), T(p, m, B), U(n, m, C);
  inner_block_dec_mul(&S, &T, &U);
  vfps u(n, fps(m));
  for (int i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));
  return std::move(u);
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vvm strassen(
    const vvm& s, const vvm& t) {
  int n = s.size(), p = s[0].size(), m = t[0].size();
  assert(int(n * p * 1.4) <= BUFFER_SIZE);
  assert(int(p * m * 1.4) <= BUFFER_SIZE);
  assert(int(n * m * 1.4) <= BUFFER_SIZE);
  memset(A, 0, int(n * p * 1.4) * sizeof(int));
  memset(B, 0, int(p * m * 1.4) * sizeof(int));
  memset(C, 0, int(m * n * 1.4) * sizeof(int));

  for (int i = 0; i < n; i++) memcpy(A + i * p, s[i].data(), p * sizeof(int));
  for (int i = 0; i < p; i++) memcpy(B + i * m, t[i].data(), m * sizeof(int));

  Mat S(n, p, A), T(p, m, B), U(n, m, C);
  inner_strassen(&S, &T, &U);
  vvm u(n, vm(m));
  for (int i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));
  return std::move(u);
}

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) vfps strassen(
    const vfps& s, const vfps& t) {
  int n = s.size(), p = s[0].size(), m = t[0].size();
  assert(int(n * p * 1.4) <= BUFFER_SIZE);
  assert(int(p * m * 1.4) <= BUFFER_SIZE);
  assert(int(n * m * 1.4) <= BUFFER_SIZE);
  memset(A, 0, int(n * p * 1.4) * sizeof(int));
  memset(B, 0, int(p * m * 1.4) * sizeof(int));
  memset(C, 0, int(m * n * 1.4) * sizeof(int));

  for (int i = 0; i < n; i++) memcpy(A + i * p, s[i].data(), p * sizeof(int));
  for (int i = 0; i < p; i++) memcpy(B + i * m, t[i].data(), m * sizeof(int));

  Mat S(n, p, A), T(p, m, B), U(n, m, C);
  inner_strassen(&S, &T, &U);
  vfps u(n, fps(m));
  for (int i = 0; i < n; i++) memcpy(u[i].data(), C + i * m, m * sizeof(int));
  return std::move(u);
}

#ifdef BUFFER_SIZE
#undef BUFFER_SIZE
#endif

#line 3 "misc/timer.hpp"
using namespace std;

struct Timer {
  chrono::high_resolution_clock::time_point st;

  Timer() { reset(); }

  void reset() { st = chrono::high_resolution_clock::now(); }

  chrono::milliseconds::rep elapsed() {
    auto ed = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();
  }
};
#line 635 "modulo/strassen.hpp"
void time_test() {
  int N = 1024;
  int P = N, M = N;
  mt19937 rng(58);
  vvm s(N, vm(P)), t(P, vm(M));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < P; j++) s[i][j] = rng() % 998244353;
  for (int i = 0; i < P; i++)
    for (int j = 0; j < M; j++) t[i][j] = rng() % 998244353;
  vvm u, u2;
  Timer timer;

  int loop = 5;
  timer.reset();
  for (int i = 0; i < loop; i++) u = FastMatProd::strassen(s, t);
  cout << "strassen " << (timer.elapsed() / loop) << endl;

  timer.reset();
  u2 = FastMatProd::naive_mul(s, t);
  cout << "naive " << (timer.elapsed() / loop) << endl;

  timer.reset();
  auto u3 = FastMatProd::block_dec(s, t);
  cout << "block dec " << (timer.elapsed() / loop) << endl;

  assert(u == u2);
  assert(u == u3);
}

void debug_test() {
  // time_test();
  int N, P, M;
  mt19937 rng(58);
  int loop = 1000;
  while (loop--) {
    N = rng() % 500 + 1;
    M = rng() % 500 + 1;
    P = rng() % 500 + 1;
    vvm s(N, vm(P)), t(P, vm(M));
    for (int i = 0; i < N; i++)
      for (int j = 0; j < P; j++) s[i][j] = rng() % 998244353;
    for (int i = 0; i < P; i++)
      for (int j = 0; j < M; j++) t[i][j] = rng() % 998244353;
    auto u = strassen(s, t);
    auto u2 = naive_mul(s, t);
    auto u3 = block_dec(s, t);
    if (u != u2) {
      cout << "ng u1 " << N << " " << P << " " << M << endl;
      exit(1);
    } else if (u != u3) {
      cout << "ng u1 " << N << " " << P << " " << M << endl;
      exit(1);
    } else {
      cout << "ok " << N << " " << P << " " << M << endl;
    }
  }
  cout << "all ok";
}
}  // namespace FastMatProd
#line 5 "fps/fps-composition-fast.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) fps Composition(
    fps P, fps Q, int deg = -1) {
  int N = (deg == -1) ? min(P.size(), Q.size()) : deg;
  if (N == 0) return fps{};
  P.shrink();
  if (P.size() == 0) {
    fps R(N, mint(0));
    R[0] = Q.empty() ? mint(0) : Q[0];
    return R;
  }
  if (N == 1) return fps{Q.eval(P[0])};

  int K = max<int>(ceil(sqrt(N)), 2);
  assert(N <= K * K);

  vector<fps> PS(K + 1);
  {
    // step 1
    PS[0].resize(N, mint());
    PS[0][0] = 1;
    PS[1] = P;
    fps::set_fft();
    if (fps::ntt_ptr == nullptr) {
      for (int i = 2; i <= K; i++) PS[i] = (PS[i - 1] * P).pre(N);
    } else {
      int len = 1 << (32 - __builtin_clz(2 * N - 2));
      fps Pomega = P;
      Pomega.resize(len);
      Pomega.ntt();
      for (int i = 2; i <= K; i++) {
        PS[i].resize(len);
        for (int j = 0; j < N; j++) PS[i][j] = PS[i - 1][j];
        PS[i].ntt();
        for (int j = 0; j < len; j++) PS[i][j] *= Pomega[j];
        PS[i].intt();
        PS[i].resize(N);
        PS[i].shrink_to_fit();
      }
    }
  }

  vector<fps> TS(K);
  {
    // step 2
    TS[0].resize(N, mint());
    TS[0][0] = 1;
    TS[1] = PS[K];
    if (fps::ntt_ptr == nullptr) {
      for (int i = 2; i < K; i++) TS[i] = (TS[i - 1] * TS[1]).pre(N);
    } else {
      int len = 1 << (32 - __builtin_clz(2 * N - 2));
      fps Tomega = TS[1];
      Tomega.resize(len);
      Tomega.ntt();
      for (int i = 2; i < K; i++) {
        TS[i].resize(len);
        for (int j = 0; j < N; j++) TS[i][j] = TS[i - 1][j];
        TS[i].ntt();
        for (int j = 0; j < len; j++) TS[i][j] *= Tomega[j];
        TS[i].intt();
        TS[i].resize(N);
        TS[i].shrink_to_fit();
      }
    }
  }

  // step 3
  vector<fps> QP;
  {
    PS.pop_back();
    vector<fps> QS(K, fps(K, mint()));
    for (int i = 0; i < K; i++)
      for (int j = 0; j < K; j++) {
        QS[i][j] = (i * K + j) < (int)Q.size() ? Q[i * K + j] : mint();
      }
    QP = FastMatProd::strassen(QS, PS);
  }

  fps ans(N, mint());
  {
    // step 4,5
    for (int i = 0; i < K; i++) ans += (QP[i] * TS[i]).pre(N);
  }
  return ans;
}

/**
 * @brief 関数の合成( $\mathrm{O}(N^2)$ )
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


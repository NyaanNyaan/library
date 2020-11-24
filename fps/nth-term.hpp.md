---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/berlekamp-massey.hpp
    title: fps/berlekamp-massey.hpp
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/kitamasa.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/fps/kitamasa.md
    document_title: "\u4E0E\u3048\u3089\u308C\u305F\u6570\u5217\u306E\u7B2C$n$\u9805\
      \u3092\u8A08\u7B97(Berlekamp-Massey/Bostan-Mori)"
    links: []
  bundledCode: "#line 2 \"fps/nth-term.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 3 \"fps/berlekamp-massey.hpp\"\nusing namespace std;\n\ntemplate\
    \ <typename mint>\nvector<mint> BerlekampMassey(const vector<mint> &s) {\n  const\
    \ int N = (int)s.size();\n  vector<mint> b, c;\n  b.reserve(N + 1);\n  c.reserve(N\
    \ + 1);\n  b.push_back(mint(1));\n  c.push_back(mint(1));\n  mint y = mint(1);\n\
    \  for (int ed = 1; ed <= N; ed++) {\n    int l = int(c.size()), m = int(b.size());\n\
    \    mint x = 0;\n    for (int i = 0; i < l; i++) x += c[i] * s[ed - l + i];\n\
    \    b.emplace_back(mint(0));\n    m++;\n    if (x == mint(0)) continue;\n   \
    \ mint freq = x / y;\n    if (l < m) {\n      auto tmp = c;\n      c.insert(begin(c),\
    \ m - l, mint(0));\n      for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m\
    \ - 1 - i];\n      b = tmp;\n      y = x;\n    } else {\n      for (int i = 0;\
    \ i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];\n    }\n  }\n  reverse(begin(c),\
    \ end(c));\n  return c;\n}\n#line 3 \"fps/kitamasa.hpp\"\nusing namespace std;\n\
    \n#line 3 \"fps/formal-power-series.hpp\"\nusing namespace std;\n\ntemplate <typename\
    \ mint>\nstruct FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n\
    \  using FPS = FormalPowerSeries;\n\n  FPS &operator+=(const FPS &r) {\n    if\
    \ (r.size() > this->size()) this->resize(r.size());\n    for (int i = 0; i < (int)r.size();\
    \ i++) (*this)[i] += r[i];\n    return *this;\n  }\n\n  FPS &operator+=(const\
    \ mint &r) {\n    if (this->empty()) this->resize(1);\n    (*this)[0] += r;\n\
    \    return *this;\n  }\n\n  FPS &operator-=(const FPS &r) {\n    if (r.size()\
    \ > this->size()) this->resize(r.size());\n    for (int i = 0; i < (int)r.size();\
    \ i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n  FPS &operator-=(const\
    \ mint &r) {\n    if (this->empty()) this->resize(1);\n    (*this)[0] -= r;\n\
    \    return *this;\n  }\n\n  FPS &operator*=(const mint &v) {\n    for (int k\
    \ = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n    return *this;\n  }\n\n\
    \  FPS &operator/=(const FPS &r) {\n    if (this->size() < r.size()) {\n     \
    \ this->clear();\n      return *this;\n    }\n    int n = this->size() - r.size()\
    \ + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this), g(r);\n      g.shrink();\n\
    \      mint coeff = g.back().inverse();\n      for (auto &x : g) x *= coeff;\n\
    \      int deg = (int)f.size() - (int)g.size() + 1;\n      int gs = g.size();\n\
    \      FPS quo(deg);\n      for (int i = deg - 1; i >= 0; i--) {\n        quo[i]\
    \ = f[i + gs - 1];\n        for (int j = 0; j < gs; j++) f[i + j] -= quo[i] *\
    \ g[j];\n      }\n      *this = quo * coeff;\n      this->resize(n, mint(0));\n\
    \      return *this;\n    }\n    return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \  }\n\n  FPS &operator%=(const FPS &r) {\n    *this -= *this / r * r;\n    shrink();\n\
    \    return *this;\n  }\n\n  FPS operator+(const FPS &r) const { return FPS(*this)\
    \ += r; }\n  FPS operator+(const mint &v) const { return FPS(*this) += v; }\n\
    \  FPS operator-(const FPS &r) const { return FPS(*this) -= r; }\n  FPS operator-(const\
    \ mint &v) const { return FPS(*this) -= v; }\n  FPS operator*(const FPS &r) const\
    \ { return FPS(*this) *= r; }\n  FPS operator*(const mint &v) const { return FPS(*this)\
    \ *= v; }\n  FPS operator/(const FPS &r) const { return FPS(*this) /= r; }\n \
    \ FPS operator%(const FPS &r) const { return FPS(*this) %= r; }\n  FPS operator-()\
    \ const {\n    FPS ret(this->size());\n    for (int i = 0; i < (int)this->size();\
    \ i++) ret[i] = -(*this)[i];\n    return ret;\n  }\n\n  void shrink() {\n    while\
    \ (this->size() && this->back() == mint(0)) this->pop_back();\n  }\n\n  FPS rev()\
    \ const {\n    FPS ret(*this);\n    reverse(begin(ret), end(ret));\n    return\
    \ ret;\n  }\n\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(), r.size()));\n\
    \    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n \
    \   return ret;\n  }\n\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
    \ begin(*this) + min((int)this->size(), sz));\n  }\n\n  FPS operator>>(int sz)\
    \ const {\n    if ((int)this->size() <= sz) return {};\n    FPS ret(*this);\n\
    \    ret.erase(ret.begin(), ret.begin() + sz);\n    return ret;\n  }\n\n  FPS\
    \ operator<<(int sz) const {\n    FPS ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, mint(0));\n    return ret;\n  }\n\n  FPS diff() const {\n    const int n\
    \ = (int)this->size();\n    FPS ret(max(0, n - 1));\n    mint one(1), coeff(1);\n\
    \    for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n \
    \     coeff += one;\n    }\n    return ret;\n  }\n\n  FPS integral() const {\n\
    \    const int n = (int)this->size();\n    FPS ret(n + 1);\n    ret[0] = mint(0);\n\
    \    if (n > 0) ret[1] = mint(1);\n    auto mod = mint::get_mod();\n    for (int\
    \ i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);\n    for (int i =\
    \ 0; i < n; i++) ret[i + 1] *= (*this)[i];\n    return ret;\n  }\n\n  mint eval(mint\
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto &v : *this) r += w * v, w\
    \ *= x;\n    return r;\n  }\n\n  FPS log(int deg = -1) const {\n    assert((*this)[0]\
    \ == mint(1));\n    if (deg == -1) deg = (int)this->size();\n    return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n  }\n\n  FPS pow(int64_t k, int\
    \ deg = -1) const {\n    const int n = (int)this->size();\n    if (deg == -1)\
    \ deg = n;\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i] != mint(0))\
    \ {\n        if (i * k > deg) return FPS(deg, mint(0));\n        mint rev = mint(1)\
    \ / (*this)[i];\n        FPS ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n\
    \        ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg)\
    \ ret.resize(deg, mint(0));\n        return ret;\n      }\n    }\n    return FPS(deg,\
    \ mint(0));\n  }\n\n  static void *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const\
    \ FPS &r);\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int\
    \ ntt_pr();\n  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n\
    };\ntemplate <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\
    \n/**\n * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n */\n#line\
    \ 6 \"fps/kitamasa.hpp\"\n\ntemplate <typename mint>\nmint LinearRecursionFormula(long\
    \ long k, FormalPowerSeries<mint> Q,\n                            FormalPowerSeries<mint>\
    \ P) {\n  Q.shrink();\n  mint ret = 0;\n  if (P.size() >= Q.size()) {\n    auto\
    \ R = P / Q;\n    P -= R * Q;\n    P.shrink();\n    if (k < (int)R.size()) ret\
    \ += R[k];\n  }\n  if ((int)P.size() == 0) return ret;\n\n  FormalPowerSeries<mint>::set_fft();\n\
    \  if (FormalPowerSeries<mint>::ntt_ptr == nullptr) {\n    P.resize((int)Q.size()\
    \ - 1);\n    while (k) {\n      auto Q2 = Q;\n      for (int i = 1; i < (int)Q2.size();\
    \ i += 2) Q2[i] = -Q2[i];\n      auto S = P * Q2;\n      auto T = Q * Q2;\n  \
    \    if (k & 1) {\n        for (int i = 1; i < (int)S.size(); i += 2) P[i >> 1]\
    \ = S[i];\n        for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];\n\
    \      } else {\n        for (int i = 0; i < (int)S.size(); i += 2) P[i >> 1]\
    \ = S[i];\n        for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];\n\
    \      }\n      k >>= 1;\n    }\n    return ret + P[0];\n  } else {\n    int N\
    \ = 1;\n    while (N < (int)Q.size()) N <<= 1;\n\n    P.resize(2 * N);\n    Q.resize(2\
    \ * N);\n    P.ntt();\n    Q.ntt();\n    vector<mint> S(2 * N), T(2 * N);\n\n\
    \    vector<int> btr(N);\n    for (int i = 0, logn = __builtin_ctz(N); i < (1\
    \ << logn); i++) {\n      btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (logn - 1));\n\
    \    }\n    mint dw = mint(FormalPowerSeries<mint>::ntt_pr())\n              \
    \    .inverse()\n                  .pow((mint::get_mod() - 1) / (2 * N));\n\n\
    \    while (k) {\n      mint inv2 = mint(2).inverse();\n\n      // even degree\
    \ of Q(x)Q(-x)\n      T.resize(N);\n      for (int i = 0; i < N; i++) T[i] = Q[(i\
    \ << 1) | 0] * Q[(i << 1) | 1];\n\n      S.resize(N);\n      if (k & 1) {\n  \
    \      // odd degree of P(x)Q(-x)\n        for (auto &i : btr) {\n          S[i]\
    \ = (P[(i << 1) | 0] * Q[(i << 1) | 1] -\n                  P[(i << 1) | 1] *\
    \ Q[(i << 1) | 0]) *\n                 inv2;\n          inv2 *= dw;\n        }\n\
    \      } else {\n        // even degree of P(x)Q(-x)\n        for (int i = 0;\
    \ i < N; i++) {\n          S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] +\n     \
    \             P[(i << 1) | 1] * Q[(i << 1) | 0]) *\n                 inv2;\n \
    \       }\n      }\n      swap(P, S);\n      swap(Q, T);\n      k >>= 1;\n   \
    \   if (k < N) break;\n      P.ntt_doubling();\n      Q.ntt_doubling();\n    }\n\
    \    P.intt();\n    Q.intt();\n    return ret + (P * (Q.inv()))[k];\n  }\n}\n\n\
    template <typename mint>\nmint kitamasa(long long N, FormalPowerSeries<mint> Q,\n\
    \              FormalPowerSeries<mint> a) {\n  assert(!Q.empty() && Q[0] != 0);\n\
    \  if(N < (int)a.size()) return a[N];\n  assert((int)a.size() >= int(Q.size())\
    \ - 1);\n  auto P = a.pre((int)Q.size() - 1) * Q;\n  P.resize(Q.size() - 1);\n\
    \  return LinearRecursionFormula<mint>(N, Q, P);\n}\n\n/**\n * @brief \u7DDA\u5F62\
    \u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97\n * @docs docs/fps/kitamasa.md\n\
    \ */\n#line 7 \"fps/nth-term.hpp\"\n\ntemplate <typename mint>\nmint nth_term(int\
    \ n, const vector<mint> &s) {\n  using fps = FormalPowerSeries<mint>;\n  auto\
    \ bm = BerlekampMassey<mint>(s);\n  return kitamasa(n, fps{begin(bm), end(bm)},\
    \ fps{begin(s), end(s)});\n}\n\n/**\n * @brief \u4E0E\u3048\u3089\u308C\u305F\u6570\
    \u5217\u306E\u7B2C$n$\u9805\u3092\u8A08\u7B97(Berlekamp-Massey/Bostan-Mori)\n\
    \ * @docs docs/fps/kitamasa.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"berlekamp-massey.hpp\"\n#include \"kitamasa.hpp\"\n\ntemplate <typename mint>\n\
    mint nth_term(int n, const vector<mint> &s) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  auto bm = BerlekampMassey<mint>(s);\n  return kitamasa(n, fps{begin(bm), end(bm)},\
    \ fps{begin(s), end(s)});\n}\n\n/**\n * @brief \u4E0E\u3048\u3089\u308C\u305F\u6570\
    \u5217\u306E\u7B2C$n$\u9805\u3092\u8A08\u7B97(Berlekamp-Massey/Bostan-Mori)\n\
    \ * @docs docs/fps/kitamasa.md\n */\n"
  dependsOn:
  - fps/berlekamp-massey.hpp
  - fps/kitamasa.hpp
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/nth-term.hpp
  requiredBy: []
  timestamp: '2020-11-24 16:37:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/nth-term.hpp
layout: document
redirect_from:
- /library/fps/nth-term.hpp
- /library/fps/nth-term.hpp.html
title: "\u4E0E\u3048\u3089\u308C\u305F\u6570\u5217\u306E\u7B2C$n$\u9805\u3092\u8A08\
  \u7B97(Berlekamp-Massey/Bostan-Mori)"
---
## 線形漸化式の第$N$項を高速に求めるライブラリ

$[x^N]\frac{P(x)}{Q(x)}$($\mathrm{deg}(Q) = k$)を$\mathrm{O}(N \log k \log N)$で計算するライブラリ。

#### 概要

$k$項間漸化式

$$a_n = c_1a_{n-1}+c_2a_{n-2} \ldots + c_ka_{n-k}$$

の第$N$項は

$$Q(x)=1-c_1x-c_2x^2-\ldots -c_kx^k$$

$$P(x)=Q(x)(a_0+a_1x+a_2x^2+\ldots) \mod x^k$$

と置いたとき

$$a_N = [x^N]\frac{P(x)}{Q(x)}$$

になり、これはBostan-Mori Algorithmを使って$\mathrm{O}(N \log k \log N)$で計算できる。[日本語での解説](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)

さらに、もし素数$p$がNTT素数だった場合は1回のループ当たりの操作が長さQの畳み込み4回で済むので、愚直なアルゴリズム(ループ当たり計算量$2M(n)$)に対して3倍(計算量$2/3M(n)$)の高速化が見込める。(詳細は実装を参考のこと。)

verify(AtCoder 双子コン#3 G フィボナッチ数の総和) $\mathrm{O}(N \log k \log N), N=200000,k=10^{18}$
- [ナイーブな実装](https://atcoder.jp/contests/s8pc-3/submissions/15526069) 1846ms
- [高速化した場合](https://atcoder.jp/contests/s8pc-3/submissions/15520531) 631ms

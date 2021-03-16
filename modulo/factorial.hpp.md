---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/sample-point-shift.hpp
    title: fps/sample-point-shift.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0502.test.cpp
    title: verify/verify-yuki/yuki-0502.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/modulo/factorial.md
    document_title: "\u968E\u4E57 $\\mod p$"
    links: []
  bundledCode: "#line 2 \"modulo/factorial.hpp\"\n\n#line 2 \"fps/formal-power-series.hpp\"\
    \n\ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n  using\
    \ vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\n  FPS &operator+=(const\
    \ FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n    for\
    \ (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n\n  FPS &operator+=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n\n  FPS &operator-=(const FPS &r)\
    \ {\n    if (r.size() > this->size()) this->resize(r.size());\n    for (int i\
    \ = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n\n\
    \  FPS &operator-=(const mint &r) {\n    if (this->empty()) this->resize(1);\n\
    \    (*this)[0] -= r;\n    return *this;\n  }\n\n  FPS &operator*=(const mint\
    \ &v) {\n    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\n  \
    \  return *this;\n  }\n\n  FPS &operator/=(const FPS &r) {\n    if (this->size()\
    \ < r.size()) {\n      this->clear();\n      return *this;\n    }\n    int n =\
    \ this->size() - r.size() + 1;\n    if ((int)r.size() <= 64) {\n      FPS f(*this),\
    \ g(r);\n      g.shrink();\n      mint coeff = g.back().inverse();\n      for\
    \ (auto &x : g) x *= coeff;\n      int deg = (int)f.size() - (int)g.size() + 1;\n\
    \      int gs = g.size();\n      FPS quo(deg);\n      for (int i = deg - 1; i\
    \ >= 0; i--) {\n        quo[i] = f[i + gs - 1];\n        for (int j = 0; j < gs;\
    \ j++) f[i + j] -= quo[i] * g[j];\n      }\n      *this = quo * coeff;\n     \
    \ this->resize(n, mint(0));\n      return *this;\n    }\n    return *this = ((*this).rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n  }\n\n  FPS &operator%=(const FPS &r) {\n\
    \    *this -= *this / r * r;\n    shrink();\n    return *this;\n  }\n\n  FPS operator+(const\
    \ FPS &r) const { return FPS(*this) += r; }\n  FPS operator+(const mint &v) const\
    \ { return FPS(*this) += v; }\n  FPS operator-(const FPS &r) const { return FPS(*this)\
    \ -= r; }\n  FPS operator-(const mint &v) const { return FPS(*this) -= v; }\n\
    \  FPS operator*(const FPS &r) const { return FPS(*this) *= r; }\n  FPS operator*(const\
    \ mint &v) const { return FPS(*this) *= v; }\n  FPS operator/(const FPS &r) const\
    \ { return FPS(*this) /= r; }\n  FPS operator%(const FPS &r) const { return FPS(*this)\
    \ %= r; }\n  FPS operator-() const {\n    FPS ret(this->size());\n    for (int\
    \ i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];\n    return ret;\n\
    \  }\n\n  void shrink() {\n    while (this->size() && this->back() == mint(0))\
    \ this->pop_back();\n  }\n\n  FPS rev() const {\n    FPS ret(*this);\n    reverse(begin(ret),\
    \ end(ret));\n    return ret;\n  }\n\n  FPS dot(FPS r) const {\n    FPS ret(min(this->size(),\
    \ r.size()));\n    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\n    return ret;\n  }\n\n  FPS pre(int sz) const {\n    return FPS(begin(*this),\
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
    \ / (*this)[i];\n        FPS ret =\n            (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg) * ((*this)[i].pow(k));\n        ret = (ret << (i * k)).pre(deg);\n\
    \        if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return\
    \ ret;\n      }\n    }\n    return FPS(deg, mint(0));\n  }\n\n  static void *ntt_ptr;\n\
    \  static void set_fft();\n  FPS &operator*=(const FPS &r);\n  void ntt();\n \
    \ void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n  FPS inv(int\
    \ deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\n\
    void *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n * @brief \u591A\u9805\
    \u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n *\
    \ @docs docs/fps/formal-power-series.md\n */\n#line 2 \"fps/sample-point-shift.hpp\"\
    \n\n#line 2 \"modulo/binomial.hpp\"\n\ntemplate <typename T>\nstruct Binomial\
    \ {\n  vector<T> fac_, finv_, inv_;\n  Binomial(int MAX = 0) : fac_(MAX + 10),\
    \ finv_(MAX + 10), inv_(MAX + 10) {\n    assert(T::get_mod() != 0);\n    MAX +=\
    \ 9;\n    fac_[0] = finv_[0] = inv_[0] = 1;\n    for (int i = 1; i <= MAX; i++)\
    \ fac_[i] = fac_[i - 1] * i;\n    finv_[MAX] = fac_[MAX].inverse();\n    for (int\
    \ i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);\n    for (int i\
    \ = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];\n  }\n\n  void extend()\
    \ {\n    int n = fac_.size();\n    T fac = fac_.back() * n;\n    T inv = (-inv_[T::get_mod()\
    \ % n]) * (T::get_mod() / n);\n    T finv = finv_.back() * inv;\n    fac_.push_back(fac);\n\
    \    finv_.push_back(finv);\n    inv_.push_back(inv);\n  }\n\n  T fac(int i) {\n\
    \    if(i < 0) return T(0);\n    while (i >= (int)fac_.size()) extend();\n   \
    \ return fac_[i];\n  }\n\n  T finv(int i) {\n    if(i < 0) return T(0);\n    while\
    \ (i >= (int)finv_.size()) extend();\n    return finv_[i];\n  }\n\n  T inv(int\
    \ i) {\n    if(i < 0) return T(0);\n    while (i >= (int)inv_.size()) extend();\n\
    \    return inv_[i];\n  }\n\n  T C(int n, int r) {\n    if (n < 0 || n < r ||\
    \ r < 0) return T(0);\n    return fac(n) * finv(n - r) * finv(r);\n  }\n\n  T\
    \ C_naive(int n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n   \
    \ T ret = T(1);\n    r = min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret\
    \ *= inv(i) * (n--);\n    return ret;\n  }\n\n  T P(int n, int r) {\n    if (n\
    \ < 0 || n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r);\n  }\n\
    \n  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n    return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 5 \"fps/sample-point-shift.hpp\"\n\n\
    // input  : h(0), h(1), ..., h(d - 1)\n// output : h(m), h(m + 1), ..., h(m +\
    \ d - 1)\ntemplate <typename mint>\nFormalPowerSeries<mint> SamplePointShift(FormalPowerSeries<mint>&\
    \ ys, mint m) {\n  static Binomial<mint> C;\n  int d = ys.size() - 1;\n  FormalPowerSeries<mint>\
    \ f(d + 1), g(d * 2 + 1);\n  for (int i = 0; i <= d; i++) {\n    f[i] = ys[i]\
    \ * C.finv(i) * C.finv(d - i);\n    if ((d - i) & 1) f[i] = -f[i];\n  }\n  for\
    \ (int i = 0; i <= 2 * d; i++) {\n    assert(m - d + i != mint(0));\n    g[i]\
    \ = (m - d + i).inverse();\n  }\n  auto h = f * g;\n  mint coeff = 1;\n  for (int\
    \ i = 0; i <= d; i++) coeff *= (m - d + i);\n  for (int i = 0; i <= d; i++) {\n\
    \    h[i + d] *= coeff;\n    coeff *= (m + i + 1) * g[i];\n  }\n  return FormalPowerSeries<mint>{begin(h)\
    \ + d, begin(h) + 2 * d + 1};\n}\n#line 5 \"modulo/factorial.hpp\"\n\ntemplate\
    \ <typename mint>\nmint factorial(int n) {\n  if (n <= 1) return 1;\n  using fps\
    \ = FormalPowerSeries<mint>;\n  long long v = 1;\n  while(v * v < n) v *= 2;\n\
    \  mint iv = mint(v).inverse();\n  fps G{1, v + 1};\n  for (long long d = 1; d\
    \ != v; d <<= 1) {\n    fps G1 = SamplePointShift(G, mint(d) * iv);\n    fps G2\
    \ = SamplePointShift(G, mint(d * v + v) * iv);\n    fps G3 = SamplePointShift(G,\
    \ mint(d * v + d + v) * iv);\n    for (int i = 0; i <= d; i++) G[i] *= G1[i],\
    \ G2[i] *= G3[i];\n    copy(begin(G2), end(G2) - 1, back_inserter(G));\n  }\n\
    \  mint res = 1;\n  long long i = 0;\n  while (i + v <= n) res *= G[i / v], i\
    \ += v;\n  while (i < n) res *= ++i;\n  return res;\n}\n\n/**\n * @brief \u968E\
    \u4E57 $\\mod p$\n * @docs docs/modulo/factorial.md\n */\n"
  code: "#pragma once\n\n#include \"../fps/formal-power-series.hpp\"\n#include \"\
    ../fps/sample-point-shift.hpp\"\n\ntemplate <typename mint>\nmint factorial(int\
    \ n) {\n  if (n <= 1) return 1;\n  using fps = FormalPowerSeries<mint>;\n  long\
    \ long v = 1;\n  while(v * v < n) v *= 2;\n  mint iv = mint(v).inverse();\n  fps\
    \ G{1, v + 1};\n  for (long long d = 1; d != v; d <<= 1) {\n    fps G1 = SamplePointShift(G,\
    \ mint(d) * iv);\n    fps G2 = SamplePointShift(G, mint(d * v + v) * iv);\n  \
    \  fps G3 = SamplePointShift(G, mint(d * v + d + v) * iv);\n    for (int i = 0;\
    \ i <= d; i++) G[i] *= G1[i], G2[i] *= G3[i];\n    copy(begin(G2), end(G2) - 1,\
    \ back_inserter(G));\n  }\n  mint res = 1;\n  long long i = 0;\n  while (i + v\
    \ <= n) res *= G[i / v], i += v;\n  while (i < n) res *= ++i;\n  return res;\n\
    }\n\n/**\n * @brief \u968E\u4E57 $\\mod p$\n * @docs docs/modulo/factorial.md\n\
    \ */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - fps/sample-point-shift.hpp
  - modulo/binomial.hpp
  isVerificationFile: false
  path: modulo/factorial.hpp
  requiredBy: []
  timestamp: '2021-03-16 18:55:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0502.test.cpp
documentation_of: modulo/factorial.hpp
layout: document
redirect_from:
- /library/modulo/factorial.hpp
- /library/modulo/factorial.hpp.html
title: "\u968E\u4E57 $\\mod p$"
---
## 階乗 $\mod p$

$n! \mod p$を$\mathrm{O}(\sqrt{p} \log p)$で計算するライブラリ。

#### アルゴリズム

min_25氏の記事(削除済み)を大きく参考にしました。

$v \geq \sqrt{p}$である$v$に対して$G_d(i)$を次のように定める。

- $g_d(x) \equiv (x+1)(x+2)\ldots (x+d) \mod p$を$x=i,v+i\ldots,dv+i$で多点評価した値の組

この時$G_d(0)$の$i$番目の要素$G_d(0)_i$は$(vi+1)(vi+2)\ldots(vi+d) \mod p$になる。ここで、$d = v\geq \sqrt{p}$であるとき、

$$n! \equiv \left(\prod_{0 \leq i \lt \lfloor\frac{n}{v}\rfloor} G_v(0)_i \right) \cdot \prod _ { \lfloor\frac{n}{v}\rfloor \cdot v \lt i \leq n} i\pmod p$$
になることが容易に確認できる。右辺の第2項は$\mathrm{O}(\sqrt{p})$で計算できるので、$G_v(0)$を高速に計算するアルゴリズムを見つければよい。

$G_v(0)$の計算は$G_d(0)$から$G_{2d}(0)$を$\mathrm{O}(d \log d)$で計算するアルゴリズムを利用する。これを利用すればダブリングの要領で$G_v(0)$を$\mathrm{O}(v \log v)=\mathrm{O}(\sqrt{p} \log p)$で計算できる。

アルゴリズムの内容は上に示したブログで詳述されているので概要のみまとめる。$g_{2d}(x) = g_d(x) g_d(x + d)$を利用すると、
  - $G_{2d}(0)$の前$d + 1$項$\cdots$ $G_d(0) \ast G_d(d)$   ($\ast$はアダマール積)
  - 残りの部分 $\cdots$ $G_d(dv + v) \ast G_d(dv + v + d)$の前$d$項

となるので、$G_d(d), G_d(dv + d), G_d(dv + v + d)$を標本点のシフトを利用して計算すればよい。

ここでは簡単のため$v$を固定した実装にしているが、$p$の値によっては$v = 32768$が不適切になることに注意する必要がある。

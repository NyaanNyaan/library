---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0963.test.cpp
    title: verify/verify-yuki/yuki-0963.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/differential-equation.md
    document_title: "\u5E38\u5FAE\u5206\u65B9\u7A0B\u5F0F"
    links: []
  bundledCode: "#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <typename mint>\n\
    struct FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n  using\
    \ FPS = FormalPowerSeries;\n\n  FPS &operator+=(const FPS &r) {\n    if (r.size()\
    \ > this->size()) this->resize(r.size());\n    for (int i = 0; i < (int)r.size();\
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
    \ 3 \"fps/differential-equation.hpp\"\n\n// find f, saitsfying equation f' = g(f)\
    \ mod x ^ deg\ntemplate <typename mint>\nFormalPowerSeries<mint> DifferentialEquation(\n\
    \    function<FormalPowerSeries<mint>(FormalPowerSeries<mint>, int)> g,\n    function<FormalPowerSeries<mint>(FormalPowerSeries<mint>,\
    \ int)> gprime,\n    mint f0, int deg) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  fps f{f0};\n  for (int i = 1; i < deg; i <<= 1) {\n    fps r = (-gprime(f,\
    \ i << 1)).integral().exp(i << 1);\n    fps h = ((g(f, i << 1) - gprime(f, i <<\
    \ 1) * f) * r).pre(i << 1).integral();\n    f = ((h + f0) * r.inv(i << 1)).pre(i\
    \ << 1);\n  }\n  return f.pre(deg);\n}\n\n/**\n * @brief \u5E38\u5FAE\u5206\u65B9\
    \u7A0B\u5F0F\n * @docs docs/fps/differential-equation.md\n */\n"
  code: "#pragma once\n#include \"formal-power-series.hpp\"\n\n// find f, saitsfying\
    \ equation f' = g(f) mod x ^ deg\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ DifferentialEquation(\n    function<FormalPowerSeries<mint>(FormalPowerSeries<mint>,\
    \ int)> g,\n    function<FormalPowerSeries<mint>(FormalPowerSeries<mint>, int)>\
    \ gprime,\n    mint f0, int deg) {\n  using fps = FormalPowerSeries<mint>;\n \
    \ fps f{f0};\n  for (int i = 1; i < deg; i <<= 1) {\n    fps r = (-gprime(f, i\
    \ << 1)).integral().exp(i << 1);\n    fps h = ((g(f, i << 1) - gprime(f, i <<\
    \ 1) * f) * r).pre(i << 1).integral();\n    f = ((h + f0) * r.inv(i << 1)).pre(i\
    \ << 1);\n  }\n  return f.pre(deg);\n}\n\n/**\n * @brief \u5E38\u5FAE\u5206\u65B9\
    \u7A0B\u5F0F\n * @docs docs/fps/differential-equation.md\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/differential-equation.hpp
  requiredBy: []
  timestamp: '2020-12-05 08:16:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0963.test.cpp
documentation_of: fps/differential-equation.hpp
layout: document
redirect_from:
- /library/fps/differential-equation.hpp
- /library/fps/differential-equation.hpp.html
title: "\u5E38\u5FAE\u5206\u65B9\u7A0B\u5F0F"
---
## 常微分方程式

$$\frac{d}{dx}f \equiv F(f) \mod x^n,\ f(0) = f_0$$

を満たす形式的冪級数$f$をダブリングを利用して$\mathrm{O}(N \log N)$で求めるアルゴリズム。($F$は$\mathrm{O}(k \log k)$で$\mod x^k$まで計算できる関数とする。)

[出典(codeforces)](https://codeforces.com/blog/entry/76447)　調べてみると中国のブログに記述が散見されることから、中国では比較的一般的なテクニックのようである。

#### 概要

$\hat{f} \equiv f \mod x^k$が求まっているとき$f \mod x^{2k}$と$\hat{f}$の関係式を導出する。

$F(f)$の$f=\hat{f}$におけるテイラー展開の式

$$F(f) = \sum_{k=0}^\infty \frac{F^{(k)}(\hat{f})}{k!}(f-\hat{f})^k$$

は$f - \hat{f} \equiv 0 \mod x$なので形式的冪級数に適用できる。

$$\frac{d}{dx}f \equiv F(f) \equiv \sum_{k=0}^\infty \frac{F^{(k)}(\hat{f})}{k!}(f-\hat{f})^k \mod x^{2k}$$

$(f-\hat{f})^2 \equiv 0 \mod x^{2k}$を利用して

$$\frac{d}{dx}f \equiv F(\hat{f}) +F'(\hat{f})(f-\hat{f}) \mod x^{2k} \cdots (\ast)$$

を得る。ここで、

$$r \equiv e^{-\int F'(\hat{f})dx} \mod x^{2k}$$

とおくと、

$$\frac{d}{dx}r\equiv e^{-\int F'(\hat{f})dx}\cdot (-F'(\hat{f}))=-F'(\hat{f})r\mod x^{2k-1}$$

となる。$(\ast)$を変形して両辺に$r$を掛けると

$$\frac{d}{dx}f\cdot r -F'(\hat{f})f\cdot r\equiv (F(\hat{f}) -F'(\hat{f})\hat{f})\cdot r \mod x^{2k-1}$$

であるが、左辺は$\frac{d}{dx}(f\cdot r)$に等しいので、両辺を積分すると

$$f\cdot r \equiv \int \left( \left(F(\hat{f}) -F'(\hat{f})\hat{f}\right)\cdot r\right)dx + C \mod x^{2k}$$

となり、$r(0) = 1$より両辺の定数項を比較して$C=f_0$が従う。以上より$f$と$\hat{f}$の関係式として次の式を得る。

$$f\equiv r^{-1}\left( \int \left( \left(F(\hat{f}) -F'(\hat{f})\hat{f}\right)\cdot r\right)dx + f_0\right) \mod x^{2k}$$

この式を利用して初項を$f \equiv f_0 \mod x$としたダブリングを行うことで、常微分方程式を$\mathrm{O}(N \log N)$で計算できる。

なお、低速なexp/invを使用している場合は(計算量の劣る)分割統治FFTの方が高速に動作するようである。

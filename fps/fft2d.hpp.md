---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fft2d.hpp\"\n\n#line 2 \"fps/formal-power-series.hpp\"\
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
    \ deg = n;\n    if (k == 0) {\n      FPS ret(n);\n      if (n) ret[0] = 1;\n \
    \     return ret;\n    }\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i]\
    \ != mint(0)) {\n        if (max<int64_t>(k, i * k) >= deg) return FPS(deg, mint(0));\n\
    \        mint rev = mint(1) / (*this)[i];\n        FPS ret = (((*this * rev) >>\
    \ i).log(deg) * k).exp(deg);\n        ret *= (*this)[i].pow(k);\n        ret =\
    \ (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n        return ret;\n      }\n      if (max<int64_t>(k, i * k) >=\
    \ deg) return FPS(deg, mint(0));\n    }\n    return FPS(deg, mint(0));\n  }\n\n\
    \  static void *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const FPS\
    \ &r);\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n\
    \  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate\
    \ <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n\
    \ * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\
    \u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n */\n#line 4 \"\
    fps/fft2d.hpp\"\n\ntemplate <typename mint>\nvoid fft2d(vector<FormalPowerSeries<mint>>&\
    \ a) {\n  int H = a.size(), W = a[0].size();\n  assert((H & (H - 1)) == 0);\n\
    \  assert((W & (W - 1)) == 0);\n  for (int i = 0; i < H; i++) {\n    bool ok =\
    \ false;\n    for (auto& x : a[i]) {\n      if (x != mint()) {\n        ok = true;\n\
    \        break;\n      }\n    }\n    if (ok) a[i].ntt();\n  }\n  FormalPowerSeries<mint>\
    \ buf(H);\n  for (int i = 0; i < W; i++) {\n    for (int j = 0; j < H; j++) buf[j]\
    \ = a[j][i];\n    buf.ntt();\n    for (int j = 0; j < H; j++) a[j][i] = buf[j];\n\
    \  }\n}\n\ntemplate <typename mint>\nvoid ifft2d(vector<FormalPowerSeries<mint>>&\
    \ a) {\n  int H = a.size(), W = a[0].size();\n  assert((H & (H - 1)) == 0);\n\
    \  assert((W & (W - 1)) == 0);\n  FormalPowerSeries<mint> buf(H);\n  for (int\
    \ i = 0; i < W; i++) {\n    for (int j = 0; j < H; j++) buf[j] = a[j][i];\n  \
    \  buf.intt();\n    for (int j = 0; j < H; j++) a[j][i] = buf[j];\n  }\n  for\
    \ (int i = 0; i < H; i++) {\n    bool ok = false;\n    for (auto& x : a[i]) {\n\
    \      if (x != mint()) {\n        ok = true;\n        break;\n      }\n    }\n\
    \    if (ok) a[i].intt();\n  }\n}\n"
  code: "#pragma once\n\n#include \"formal-power-series.hpp\"\n\ntemplate <typename\
    \ mint>\nvoid fft2d(vector<FormalPowerSeries<mint>>& a) {\n  int H = a.size(),\
    \ W = a[0].size();\n  assert((H & (H - 1)) == 0);\n  assert((W & (W - 1)) == 0);\n\
    \  for (int i = 0; i < H; i++) {\n    bool ok = false;\n    for (auto& x : a[i])\
    \ {\n      if (x != mint()) {\n        ok = true;\n        break;\n      }\n \
    \   }\n    if (ok) a[i].ntt();\n  }\n  FormalPowerSeries<mint> buf(H);\n  for\
    \ (int i = 0; i < W; i++) {\n    for (int j = 0; j < H; j++) buf[j] = a[j][i];\n\
    \    buf.ntt();\n    for (int j = 0; j < H; j++) a[j][i] = buf[j];\n  }\n}\n\n\
    template <typename mint>\nvoid ifft2d(vector<FormalPowerSeries<mint>>& a) {\n\
    \  int H = a.size(), W = a[0].size();\n  assert((H & (H - 1)) == 0);\n  assert((W\
    \ & (W - 1)) == 0);\n  FormalPowerSeries<mint> buf(H);\n  for (int i = 0; i <\
    \ W; i++) {\n    for (int j = 0; j < H; j++) buf[j] = a[j][i];\n    buf.intt();\n\
    \    for (int j = 0; j < H; j++) a[j][i] = buf[j];\n  }\n  for (int i = 0; i <\
    \ H; i++) {\n    bool ok = false;\n    for (auto& x : a[i]) {\n      if (x !=\
    \ mint()) {\n        ok = true;\n        break;\n      }\n    }\n    if (ok) a[i].intt();\n\
    \  }\n}\n"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/fft2d.hpp
  requiredBy: []
  timestamp: '2022-08-22 21:35:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps/fft2d.hpp
layout: document
redirect_from:
- /library/fps/fft2d.hpp
- /library/fps/fft2d.hpp.html
title: fps/fft2d.hpp
---

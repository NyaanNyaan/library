---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':question:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/partial-fraction-decomposition.test.cpp
    title: verify/verify-unit-test/partial-fraction-decomposition.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1145.test.cpp
    title: verify/verify-yuki/yuki-1145.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulo/binomial.hpp\"\n\ntemplate <typename T>\nstruct Binomial\
    \ {\n  vector<T> f, g, h;\n  Binomial(int MAX = 0) {\n    assert(T::get_mod()\
    \ != 0 && \"Binomial<mint>()\");\n    f.resize(1, T{1});\n    g.resize(1, T{1});\n\
    \    h.resize(1, T{1});\n    while (MAX >= (int)f.size()) extend();\n  }\n\n \
    \ void extend() {\n    int n = f.size();\n    int m = n * 2;\n    f.resize(m);\n\
    \    g.resize(m);\n    h.resize(m);\n    for (int i = n; i < m; i++) f[i] = f[i\
    \ - 1] * T(i);\n    g[m - 1] = f[m - 1].inverse();\n    h[m - 1] = g[m - 1] *\
    \ f[m - 2];\n    for (int i = m - 2; i >= n; i--) {\n      g[i] = g[i + 1] * T(i\
    \ + 1);\n      h[i] = g[i] * f[i - 1];\n    }\n  }\n\n  T fac(int i) {\n    if\
    \ (i < 0) return T(0);\n    while (i >= (int)f.size()) extend();\n    return f[i];\n\
    \  }\n\n  T finv(int i) {\n    if (i < 0) return T(0);\n    while (i >= (int)g.size())\
    \ extend();\n    return g[i];\n  }\n\n  T inv(int i) {\n    if (i < 0) return\
    \ -inv(-i);\n    while (i >= (int)h.size()) extend();\n    return h[i];\n  }\n\
    \n  T C(int n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    return\
    \ fac(n) * finv(n - r) * finv(r);\n  }\n\n  inline T operator()(int n, int r)\
    \ { return C(n, r); }\n\n  template <typename I>\n  T multinomial(const vector<I>&\
    \ r) {\n    static_assert(is_integral<I>::value == true);\n    int n = 0;\n  \
    \  for (auto& x : r) {\n      if (x < 0) return T(0);\n      n += x;\n    }\n\
    \    T res = fac(n);\n    for (auto& x : r) res *= finv(x);\n    return res;\n\
    \  }\n\n  template <typename I>\n  T operator()(const vector<I>& r) {\n    return\
    \ multinomial(r);\n  }\n\n  T C_naive(int n, int r) {\n    if (n < 0 || n < r\
    \ || r < 0) return T(0);\n    T ret = T(1);\n    r = min(r, n - r);\n    for (int\
    \ i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n    return ret;\n  }\n\n  T P(int\
    \ n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    return fac(n)\
    \ * finv(n - r);\n  }\n\n  T H(int n, int r) {\n    if (n < 0 || r < 0) return\
    \ T(0);\n    return r == 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 2 \"fps/formal-power-series.hpp\"\
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
    \ @docs docs/fps/formal-power-series.md\n */\n#line 4 \"fps/utility.hpp\"\n\n\
    template <typename mint>\nFormalPowerSeries<mint> Pi(vector<FormalPowerSeries<mint>>\
    \ v) {\n  using fps = FormalPowerSeries<mint>;\n  if ((int)v.size() == 0) return\
    \ fps{mint(1)};\n  sort(begin(v), end(v), [](fps& a, fps& b) { return a.size()\
    \ < b.size(); });\n  queue<fps> q;\n  for (auto& f : v) q.push(f);\n  while ((int)q.size()\
    \ > 1) {\n    fps a = q.front();\n    q.pop();\n    fps b = q.front();\n    q.pop();\n\
    \    q.push(a * b);\n  }\n  return q.front();\n}\n\ntemplate <typename mint>\n\
    void OGFtoEGF(FormalPowerSeries<mint>& f, Binomial<mint>& C) {\n  for (int i =\
    \ 0; i < (int)f.size(); i++) f[i] *= C.finv(i);\n}\n\ntemplate <typename mint>\n\
    void EGFtoOGF(FormalPowerSeries<mint>& f, Binomial<mint>& C) {\n  for (int i =\
    \ 0; i < (int)f.size(); i++) f[i] *= C.fac(i);\n}\n\ntemplate <typename mint>\n\
    FormalPowerSeries<mint> e_x(int deg, Binomial<mint>& C) {\n  while ((int)C.g.size()\
    \ < deg) C.extend();\n  FormalPowerSeries<mint> ret{begin(C.g), begin(C.g) + deg};\n\
    \  return ret;\n}\n\n// f *= (1 + c x^n)\ntemplate <typename mint>\nvoid sparse_mul(FormalPowerSeries<mint>&\
    \ f, int n, mint c, int expand = true) {\n  if (expand) f.resize(f.size() + n);\n\
    \  for (int i = (int)f.size() - 1; i >= 0; --i) {\n    if (i - n >= 0) f[i] +=\
    \ f[i - n] * c;\n  }\n}\n\n// f /= (1 + c x^n)\ntemplate <typename mint>\nvoid\
    \ sparse_div(FormalPowerSeries<mint>& f, int n, mint c) {\n  for (int i = 0; i\
    \ < (int)f.size(); ++i) {\n    if (i + n < (int)f.size()) f[i + n] -= f[i] * c;\n\
    \  }\n}\n"
  code: "#pragma once\n#include \"../modulo/binomial.hpp\"\n#include \"./formal-power-series.hpp\"\
    \n\ntemplate <typename mint>\nFormalPowerSeries<mint> Pi(vector<FormalPowerSeries<mint>>\
    \ v) {\n  using fps = FormalPowerSeries<mint>;\n  if ((int)v.size() == 0) return\
    \ fps{mint(1)};\n  sort(begin(v), end(v), [](fps& a, fps& b) { return a.size()\
    \ < b.size(); });\n  queue<fps> q;\n  for (auto& f : v) q.push(f);\n  while ((int)q.size()\
    \ > 1) {\n    fps a = q.front();\n    q.pop();\n    fps b = q.front();\n    q.pop();\n\
    \    q.push(a * b);\n  }\n  return q.front();\n}\n\ntemplate <typename mint>\n\
    void OGFtoEGF(FormalPowerSeries<mint>& f, Binomial<mint>& C) {\n  for (int i =\
    \ 0; i < (int)f.size(); i++) f[i] *= C.finv(i);\n}\n\ntemplate <typename mint>\n\
    void EGFtoOGF(FormalPowerSeries<mint>& f, Binomial<mint>& C) {\n  for (int i =\
    \ 0; i < (int)f.size(); i++) f[i] *= C.fac(i);\n}\n\ntemplate <typename mint>\n\
    FormalPowerSeries<mint> e_x(int deg, Binomial<mint>& C) {\n  while ((int)C.g.size()\
    \ < deg) C.extend();\n  FormalPowerSeries<mint> ret{begin(C.g), begin(C.g) + deg};\n\
    \  return ret;\n}\n\n// f *= (1 + c x^n)\ntemplate <typename mint>\nvoid sparse_mul(FormalPowerSeries<mint>&\
    \ f, int n, mint c, int expand = true) {\n  if (expand) f.resize(f.size() + n);\n\
    \  for (int i = (int)f.size() - 1; i >= 0; --i) {\n    if (i - n >= 0) f[i] +=\
    \ f[i - n] * c;\n  }\n}\n\n// f /= (1 + c x^n)\ntemplate <typename mint>\nvoid\
    \ sparse_div(FormalPowerSeries<mint>& f, int n, mint c) {\n  for (int i = 0; i\
    \ < (int)f.size(); ++i) {\n    if (i + n < (int)f.size()) f[i + n] -= f[i] * c;\n\
    \  }\n}\n"
  dependsOn:
  - modulo/binomial.hpp
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/utility.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:21:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-unit-test/partial-fraction-decomposition.test.cpp
  - verify/verify-yuki/yuki-1145.test.cpp
documentation_of: fps/utility.hpp
layout: document
redirect_from:
- /library/fps/utility.hpp
- /library/fps/utility.hpp.html
title: fps/utility.hpp
---

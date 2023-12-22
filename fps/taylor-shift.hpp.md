---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps-famous-series.hpp
    title: "\u6709\u540D\u306A\u6570\u5217"
  - icon: ':heavy_check_mark:'
    path: fps/fualhuber.hpp
    title: fps/fualhuber.hpp
  - icon: ':heavy_check_mark:'
    path: fps/partial-fraction-decomposition.hpp
    title: "\u90E8\u5206\u5206\u6570\u5206\u89E3(\u5206\u6BCD\u304C1\u6B21\u5F0F\u306E\
      \u7A4D\u3067\u8868\u305B\u308B\u5834\u5408)"
  - icon: ':heavy_check_mark:'
    path: set-function/polynomial-composite-set-power-series.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570\u306E\u5408\u6210"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/dual-fps.test.cpp
    title: verify/verify-unit-test/dual-fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/partial-fraction-decomposition.test.cpp
    title: verify/verify-unit-test/partial-fraction-decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-stirling-1st-row.test.cpp
    title: verify/verify-yosupo-fps/yosupo-stirling-1st-row.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
    title: verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
    title: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-polynomial-composite-set-power-series.test.cpp
    title: verify/verify-yosupo-math/yosupo-polynomial-composite-set-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1504.test.cpp
    title: verify/verify-yuki/yuki-1504.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1510.test.cpp
    title: verify/verify-yuki/yuki-1510.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1875.test.cpp
    title: verify/verify-yuki/yuki-1875.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2580.test.cpp
    title: verify/verify-yuki/yuki-2580.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/fps-taylor-shift.md
    document_title: "\u5E73\u884C\u79FB\u52D5"
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
    \   return ret;\n  }\n\n  // \u524D sz \u9805\u3092\u53D6\u3063\u3066\u304F\u308B\
    \u3002sz \u306B\u8DB3\u308A\u306A\u3044\u9805\u306F 0 \u57CB\u3081\u3059\u308B\
    \n  FPS pre(int sz) const {\n    FPS ret(begin(*this), begin(*this) + min((int)this->size(),\
    \ sz));\n    if ((int)ret.size() < sz) ret.resize(sz);\n    return ret;\n  }\n\
    \n  FPS operator>>(int sz) const {\n    if ((int)this->size() <= sz) return {};\n\
    \    FPS ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n    return\
    \ ret;\n  }\n\n  FPS operator<<(int sz) const {\n    FPS ret(*this);\n    ret.insert(ret.begin(),\
    \ sz, mint(0));\n    return ret;\n  }\n\n  FPS diff() const {\n    const int n\
    \ = (int)this->size();\n    FPS ret(max(0, n - 1));\n    mint one(1), coeff(1);\n\
    \    for (int i = 1; i < n; i++) {\n      ret[i - 1] = (*this)[i] * coeff;\n \
    \     coeff += one;\n    }\n    return ret;\n  }\n\n  FPS integral() const {\n\
    \    const int n = (int)this->size();\n    FPS ret(n + 1);\n    ret[0] = mint(0);\n\
    \    if (n > 0) ret[1] = mint(1);\n    auto mod = mint::get_mod();\n    for (int\
    \ i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);\n    for (int i =\
    \ 0; i < n; i++) ret[i + 1] *= (*this)[i];\n    return ret;\n  }\n\n  mint eval(mint\
    \ x) const {\n    mint r = 0, w = 1;\n    for (auto &v : *this) r += w * v, w\
    \ *= x;\n    return r;\n  }\n\n  FPS log(int deg = -1) const {\n    assert(!(*this).empty()\
    \ && (*this)[0] == mint(1));\n    if (deg == -1) deg = (int)this->size();\n  \
    \  return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n  }\n\n  FPS\
    \ pow(int64_t k, int deg = -1) const {\n    const int n = (int)this->size();\n\
    \    if (deg == -1) deg = n;\n    if (k == 0) {\n      FPS ret(deg);\n      if\
    \ (deg) ret[0] = 1;\n      return ret;\n    }\n    for (int i = 0; i < n; i++)\
    \ {\n      if ((*this)[i] != mint(0)) {\n        mint rev = mint(1) / (*this)[i];\n\
    \        FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg);\n        ret\
    \ *= (*this)[i].pow(k);\n        ret = (ret << (i * k)).pre(deg);\n        if\
    \ ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return ret;\n   \
    \   }\n      if (__int128_t(i + 1) * k >= deg) return FPS(deg, mint(0));\n   \
    \ }\n    return FPS(deg, mint(0));\n  }\n\n  static void *ntt_ptr;\n  static void\
    \ set_fft();\n  FPS &operator*=(const FPS &r);\n  void ntt();\n  void intt();\n\
    \  void ntt_doubling();\n  static int ntt_pr();\n  FPS inv(int deg = -1) const;\n\
    \  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr\
    \ = nullptr;\n\n/**\n * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\
    \u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n\
    \ */\n#line 2 \"modulo/binomial.hpp\"\n\n#include <cassert>\n#include <type_traits>\n\
    #include <vector>\nusing namespace std;\n\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u306E MAX \u306B \u300CC(n, r) \u3084 fac(n) \u3067\u30AF\u30A8\u30EA\u3092\
    \u6295\u3052\u308B\u6700\u5927\u306E n \u300D\n// \u3092\u5165\u308C\u308B\u3068\
    \u500D\u901F\u304F\u3089\u3044\u306B\u306A\u308B\n// mod \u3092\u8D85\u3048\u3066\
    \u524D\u8A08\u7B97\u3057\u3066 0 \u5272\u308A\u3092\u8E0F\u3080\u30D0\u30B0\u306F\
    \u5BFE\u7B56\u6E08\u307F\ntemplate <typename T>\nstruct Binomial {\n  vector<T>\
    \ f, g, h;\n  Binomial(int MAX = 0) {\n    assert(T::get_mod() != 0 && \"Binomial<mint>()\"\
    );\n    f.resize(1, T{1});\n    g.resize(1, T{1});\n    h.resize(1, T{1});\n \
    \   if (MAX > 0) extend(MAX + 1);\n  }\n\n  void extend(int m = -1) {\n    int\
    \ n = f.size();\n    if (m == -1) m = n * 2;\n    m = min<int>(m, T::get_mod());\n\
    \    if (n >= m) return;\n    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n\
    \    for (int i = n; i < m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m -\
    \ 1].inverse();\n    h[m - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2;\
    \ i >= n; i--) {\n      g[i] = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i -\
    \ 1];\n    }\n  }\n\n  T fac(int i) {\n    if (i < 0) return T(0);\n    while\
    \ (i >= (int)f.size()) extend();\n    return f[i];\n  }\n\n  T finv(int i) {\n\
    \    if (i < 0) return T(0);\n    while (i >= (int)g.size()) extend();\n    return\
    \ g[i];\n  }\n\n  T inv(int i) {\n    if (i < 0) return -inv(-i);\n    while (i\
    \ >= (int)h.size()) extend();\n    return h[i];\n  }\n\n  T C(int n, int r) {\n\
    \    if (n < 0 || n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r)\
    \ * finv(r);\n  }\n\n  inline T operator()(int n, int r) { return C(n, r); }\n\
    \n  template <typename I>\n  T multinomial(const vector<I>& r) {\n    static_assert(is_integral<I>::value\
    \ == true);\n    int n = 0;\n    for (auto& x : r) {\n      if (x < 0) return\
    \ T(0);\n      n += x;\n    }\n    T res = fac(n);\n    for (auto& x : r) res\
    \ *= finv(x);\n    return res;\n  }\n\n  template <typename I>\n  T operator()(const\
    \ vector<I>& r) {\n    return multinomial(r);\n  }\n\n  T C_naive(int n, int r)\
    \ {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n    r =\
    \ min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n  \
    \  return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n < r || r < 0)\
    \ return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  // [x^r] 1 / (1-x)^n\n\
    \  T H(int n, int r) {\n    if (n < 0 || r < 0) return T(0);\n    return r ==\
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 4 \"fps/taylor-shift.hpp\"\n\n// calculate\
    \ F(x + a)\ntemplate <typename mint>\nFormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint>\
    \ f, mint a,\n                                    Binomial<mint>& C) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  int N = f.size();\n  for (int i = 0; i < N;\
    \ i++) f[i] *= C.fac(i);\n  reverse(begin(f), end(f));\n  fps g(N, mint(1));\n\
    \  for (int i = 1; i < N; i++) g[i] = g[i - 1] * a * C.inv(i);\n  f = (f * g).pre(N);\n\
    \  reverse(begin(f), end(f));\n  for (int i = 0; i < N; i++) f[i] *= C.finv(i);\n\
    \  return f;\n}\n\n/**\n * @brief \u5E73\u884C\u79FB\u52D5\n * @docs docs/fps/fps-taylor-shift.md\n\
    \ */\n"
  code: "#pragma once\n#include \"./formal-power-series.hpp\"\n#include \"../modulo/binomial.hpp\"\
    \n\n// calculate F(x + a)\ntemplate <typename mint>\nFormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint>\
    \ f, mint a,\n                                    Binomial<mint>& C) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  int N = f.size();\n  for (int i = 0; i < N;\
    \ i++) f[i] *= C.fac(i);\n  reverse(begin(f), end(f));\n  fps g(N, mint(1));\n\
    \  for (int i = 1; i < N; i++) g[i] = g[i - 1] * a * C.inv(i);\n  f = (f * g).pre(N);\n\
    \  reverse(begin(f), end(f));\n  for (int i = 0; i < N; i++) f[i] *= C.finv(i);\n\
    \  return f;\n}\n\n/**\n * @brief \u5E73\u884C\u79FB\u52D5\n * @docs docs/fps/fps-taylor-shift.md\n\
    \ */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - modulo/binomial.hpp
  isVerificationFile: false
  path: fps/taylor-shift.hpp
  requiredBy:
  - fps/fps-famous-series.hpp
  - fps/partial-fraction-decomposition.hpp
  - fps/fualhuber.hpp
  - set-function/polynomial-composite-set-power-series.hpp
  timestamp: '2023-08-31 20:44:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1510.test.cpp
  - verify/verify-yuki/yuki-1504.test.cpp
  - verify/verify-yuki/yuki-1875.test.cpp
  - verify/verify-yuki/yuki-2580.test.cpp
  - verify/verify-unit-test/dual-fps.test.cpp
  - verify/verify-unit-test/partial-fraction-decomposition.test.cpp
  - verify/verify-yosupo-math/yosupo-polynomial-composite-set-power-series.test.cpp
  - verify/verify-yosupo-fps/yosupo-stirling-1st-row.test.cpp
  - verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
  - verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
documentation_of: fps/taylor-shift.hpp
layout: document
redirect_from:
- /library/fps/taylor-shift.hpp
- /library/fps/taylor-shift.hpp.html
title: "\u5E73\u884C\u79FB\u52D5"
---
## fps-平行移動

$N$次の多項式 $f(x)$ に対して $g(x) = f(x+a)$ を満たす $g(x)$ を $\mathrm{O}(N \log N)$ で計算するライブラリ。

#### 概要

$N$ 次の多項式 $f(x)$ に対して $g(x) = f(x+a)$ となる $g(x)$ を求める。これは、

$$f(x+a) = \sum_{n=0}^N f_n(x+a)^n$$

$$=\sum_{i=0}^Nx^i\sum_{n=i}^N(a^{n-i}f_n\ _nC_i)$$

$m=N-n,j=N-i$ とおいて

$$=\sum_{j=0}^N\frac{x^j}{(N-j)!}\sum_{m=0}^j\frac{a^{j-m}}{(j-m)!}\left((N-m)!f_{N-m}\right)$$

と変形できるので畳み込みに帰着される。

#### 使い方

- `TaylorShift(f, a, C, deg)`: 多項式$f$について $f(x+a)$ を deg 次の項まで求める。 $C$ には `Binomial` 構造体を渡す。

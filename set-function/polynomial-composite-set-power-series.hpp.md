---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/taylor-shift.hpp
    title: "\u5E73\u884C\u79FB\u52D5"
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  - icon: ':heavy_check_mark:'
    path: set-function/subset-convolution.hpp
    title: Subset Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-polynomial-composite-set-power-series.test.cpp
    title: verify/verify-yosupo-math/yosupo-polynomial-composite-set-power-series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u96C6\u5408\u51AA\u7D1A\u6570\u306E\u5408\u6210"
    links: []
  bundledCode: "#line 2 \"set-function/polynomial-composite-set-power-series.hpp\"\
    \n\n#include <cassert>\n#include <vector>\nusing namespace std;\n\n#line 2 \"\
    fps/formal-power-series.hpp\"\n\ntemplate <typename mint>\nstruct FormalPowerSeries\
    \ : vector<mint> {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\
    \n  FPS &operator+=(const FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n\
    \    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
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
    \ * r[i];\n    return ret;\n  }\n\n  // \u524D sz \u9805\u3092\u53D6\u3063\u3066\
    \u304F\u308B\u3002sz \u306B\u8DB3\u308A\u306A\u3044\u9805\u306F 0 \u57CB\u3081\
    \u3059\u308B\n  FPS pre(int sz) const {\n    FPS ret(begin(*this), begin(*this)\
    \ + min((int)this->size(), sz));\n    if ((int)ret.size() < sz) ret.resize(sz);\n\
    \    return ret;\n  }\n\n  FPS operator>>(int sz) const {\n    if ((int)this->size()\
    \ <= sz) return {};\n    FPS ret(*this);\n    ret.erase(ret.begin(), ret.begin()\
    \ + sz);\n    return ret;\n  }\n\n  FPS operator<<(int sz) const {\n    FPS ret(*this);\n\
    \    ret.insert(ret.begin(), sz, mint(0));\n    return ret;\n  }\n\n  FPS diff()\
    \ const {\n    const int n = (int)this->size();\n    FPS ret(max(0, n - 1));\n\
    \    mint one(1), coeff(1);\n    for (int i = 1; i < n; i++) {\n      ret[i -\
    \ 1] = (*this)[i] * coeff;\n      coeff += one;\n    }\n    return ret;\n  }\n\
    \n  FPS integral() const {\n    const int n = (int)this->size();\n    FPS ret(n\
    \ + 1);\n    ret[0] = mint(0);\n    if (n > 0) ret[1] = mint(1);\n    auto mod\
    \ = mint::get_mod();\n    for (int i = 2; i <= n; i++) ret[i] = (-ret[mod % i])\
    \ * (mod / i);\n    for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];\n  \
    \  return ret;\n  }\n\n  mint eval(mint x) const {\n    mint r = 0, w = 1;\n \
    \   for (auto &v : *this) r += w * v, w *= x;\n    return r;\n  }\n\n  FPS log(int\
    \ deg = -1) const {\n    assert(!(*this).empty() && (*this)[0] == mint(1));\n\
    \    if (deg == -1) deg = (int)this->size();\n    return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n  }\n\n  FPS pow(int64_t k, int deg = -1) const {\n    const\
    \ int n = (int)this->size();\n    if (deg == -1) deg = n;\n    if (k == 0) {\n\
    \      FPS ret(deg);\n      if (deg) ret[0] = 1;\n      return ret;\n    }\n \
    \   for (int i = 0; i < n; i++) {\n      if ((*this)[i] != mint(0)) {\n      \
    \  mint rev = mint(1) / (*this)[i];\n        FPS ret = (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg);\n        ret *= (*this)[i].pow(k);\n        ret = (ret << (i\
    \ * k)).pre(deg);\n        if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n\
    \        return ret;\n      }\n      if (__int128_t(i + 1) * k >= deg) return\
    \ FPS(deg, mint(0));\n    }\n    return FPS(deg, mint(0));\n  }\n\n  static void\
    \ *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const FPS &r);\n  void\
    \ ntt();\n  void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n  FPS\
    \ inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate <typename\
    \ mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n * @brief \u591A\
    \u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\
    \n * @docs docs/fps/formal-power-series.md\n */\n#line 2 \"modulo/binomial.hpp\"\
    \n\n#line 4 \"modulo/binomial.hpp\"\n#include <type_traits>\n#line 6 \"modulo/binomial.hpp\"\
    \nusing namespace std;\n\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306E\
    \ MAX \u306B \u300CC(n, r) \u3084 fac(n) \u3067\u30AF\u30A8\u30EA\u3092\u6295\u3052\
    \u308B\u6700\u5927\u306E n \u300D\n// \u3092\u5165\u308C\u308B\u3068\u500D\u901F\
    \u304F\u3089\u3044\u306B\u306A\u308B\n// mod \u3092\u8D85\u3048\u3066\u524D\u8A08\
    \u7B97\u3057\u3066 0 \u5272\u308A\u3092\u8E0F\u3080\u30D0\u30B0\u306F\u5BFE\u7B56\
    \u6E08\u307F\ntemplate <typename T>\nstruct Binomial {\n  vector<T> f, g, h;\n\
    \  Binomial(int MAX = 0) {\n    assert(T::get_mod() != 0 && \"Binomial<mint>()\"\
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
    \ */\n#line 2 \"set-function/subset-convolution.hpp\"\n\n#include <array>\n#line\
    \ 5 \"set-function/subset-convolution.hpp\"\nusing namespace std;\n\ntemplate\
    \ <typename mint, int _s>\nstruct SubsetConvolution {\n  using fps = array<mint,\
    \ _s + 1>;\n  static constexpr int s = _s;\n  vector<int> pc;\n\n  SubsetConvolution()\
    \ : pc(1 << s) {\n    for (int i = 1; i < (1 << s); i++) pc[i] = pc[i - (i & -i)]\
    \ + 1;\n  }\n\n  void add(fps& l, const fps& r, int d) {\n    for (int i = 0;\
    \ i < d; ++i) l[i] += r[i];\n  }\n\n  void sub(fps& l, const fps& r, int d) {\n\
    \    for (int i = d; i <= s; ++i) l[i] -= r[i];\n  }\n\n  void zeta(vector<fps>&\
    \ a) {\n    int n = a.size();\n    for (int w = 1; w < n; w *= 2) {\n      for\
    \ (int k = 0; k < n; k += w * 2) {\n        for (int i = 0; i < w; ++i) {\n  \
    \        add(a[k + w + i], a[k + i], pc[k + w + i]);\n        }\n      }\n   \
    \ }\n  }\n\n  void mobius(vector<fps>& a) {\n    int n = a.size();\n    for (int\
    \ w = n >> 1; w; w >>= 1) {\n      for (int k = 0; k < n; k += w * 2) {\n    \
    \    for (int i = 0; i < w; ++i) {\n          sub(a[k + w + i], a[k + i], pc[k\
    \ + w + i]);\n        }\n      }\n    }\n  }\n\n  vector<fps> lift(const vector<mint>&\
    \ a) {\n    vector<fps> A(a.size());\n    for (int i = 0; i < (int)a.size(); i++)\
    \ {\n      fill(begin(A[i]), end(A[i]), mint());\n      A[i][pc[i]] = a[i];\n\
    \    }\n    return A;\n  }\n\n  vector<mint> unlift(const vector<fps>& A) {\n\
    \    vector<mint> a(A.size());\n    for (int i = 0; i < (int)A.size(); i++) a[i]\
    \ = A[i][pc[i]];\n    return a;\n  }\n\n  void prod(vector<fps>& A, const vector<fps>&\
    \ B) {\n    int n = A.size(), d = __builtin_ctz(n);\n    for (int i = 0; i < n;\
    \ i++) {\n      fps c{};\n      for (int j = 0; j <= d; j++) {\n        for (int\
    \ k = 0; k <= d - j; k++) {\n          c[j + k] += A[i][j] * B[i][k];\n      \
    \  }\n      }\n      A[i].swap(c);\n    }\n  }\n\n  vector<mint> multiply(const\
    \ vector<mint>& a, const vector<mint>& b) {\n    vector<fps> A = lift(a), B =\
    \ lift(b);\n    zeta(A), zeta(B);\n    prod(A, B);\n    mobius(A);\n    return\
    \ unlift(A);\n  }\n};\n\n/**\n * @brief Subset Convolution\n * @docs docs/set-function/subset-convolution.md\n\
    \ */\n#line 10 \"set-function/polynomial-composite-set-power-series.hpp\"\n\n\
    template <typename mint, int MAX = 21>\nvector<mint> polynomial_composite_set_power_series(int\
    \ n, FormalPowerSeries<mint> f,\n                                            vector<mint>\
    \ g) {\n  assert(0 <= n && n <= MAX);\n  static SubsetConvolution<mint, MAX> ss;\n\
    \n  Binomial<mint> binom(f.size());\n  if (g[0] != 0) {\n    f = TaylorShift(f,\
    \ g[0], binom);\n    g[0] = 0;\n  }\n  f.resize(n + 1), g.resize(1 << n);\n\n\
    \  for (int i = 0; i <= n; i++) f[i] *= binom.fac(i);\n  vector h(n + 1, vector(n\
    \ + 1, vector<mint>{}));\n  for (int i = 0; i <= n; i++) h[0][i] = {f[i]};\n \
    \ for (int k = 1; k <= n; k++) {\n    auto A = ss.lift({begin(g) + (1 << (k -\
    \ 1)), begin(g) + (1 << k)});\n    ss.zeta(A);\n    for (int j = 0; j <= n - k;\
    \ j++) {\n      h[k][j] = h[k - 1][j];\n      auto B = ss.lift(h[k - 1][j + 1]);\n\
    \      ss.zeta(B);\n      ss.prod(B, A);\n      ss.mobius(B);\n      auto c =\
    \ ss.unlift(B);\n      copy(begin(c), end(c), back_inserter(h[k][j]));\n    }\n\
    \  }\n  return h[n][0];\n}\n\n/**\n * @brief \u96C6\u5408\u51AA\u7D1A\u6570\u306E\
    \u5408\u6210\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \n#include \"../fps/formal-power-series.hpp\"\n#include \"../fps/taylor-shift.hpp\"\
    \n#include \"subset-convolution.hpp\"\n\ntemplate <typename mint, int MAX = 21>\n\
    vector<mint> polynomial_composite_set_power_series(int n, FormalPowerSeries<mint>\
    \ f,\n                                            vector<mint> g) {\n  assert(0\
    \ <= n && n <= MAX);\n  static SubsetConvolution<mint, MAX> ss;\n\n  Binomial<mint>\
    \ binom(f.size());\n  if (g[0] != 0) {\n    f = TaylorShift(f, g[0], binom);\n\
    \    g[0] = 0;\n  }\n  f.resize(n + 1), g.resize(1 << n);\n\n  for (int i = 0;\
    \ i <= n; i++) f[i] *= binom.fac(i);\n  vector h(n + 1, vector(n + 1, vector<mint>{}));\n\
    \  for (int i = 0; i <= n; i++) h[0][i] = {f[i]};\n  for (int k = 1; k <= n; k++)\
    \ {\n    auto A = ss.lift({begin(g) + (1 << (k - 1)), begin(g) + (1 << k)});\n\
    \    ss.zeta(A);\n    for (int j = 0; j <= n - k; j++) {\n      h[k][j] = h[k\
    \ - 1][j];\n      auto B = ss.lift(h[k - 1][j + 1]);\n      ss.zeta(B);\n    \
    \  ss.prod(B, A);\n      ss.mobius(B);\n      auto c = ss.unlift(B);\n      copy(begin(c),\
    \ end(c), back_inserter(h[k][j]));\n    }\n  }\n  return h[n][0];\n}\n\n/**\n\
    \ * @brief \u96C6\u5408\u51AA\u7D1A\u6570\u306E\u5408\u6210\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - fps/taylor-shift.hpp
  - modulo/binomial.hpp
  - set-function/subset-convolution.hpp
  isVerificationFile: false
  path: set-function/polynomial-composite-set-power-series.hpp
  requiredBy: []
  timestamp: '2023-08-31 20:44:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-polynomial-composite-set-power-series.test.cpp
documentation_of: set-function/polynomial-composite-set-power-series.hpp
layout: document
redirect_from:
- /library/set-function/polynomial-composite-set-power-series.hpp
- /library/set-function/polynomial-composite-set-power-series.hpp.html
title: "\u96C6\u5408\u51AA\u7D1A\u6570\u306E\u5408\u6210"
---

---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':x:'
    path: fps/taylor-shift.hpp
    title: "\u5E73\u884C\u79FB\u52D5"
  - icon: ':question:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
    title: verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u6709\u540D\u306A\u6570\u5217"
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
    \ / (*this)[i];\n        FPS ret =\n            (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg) * ((*this)[i].pow(k));\n        ret = (ret << (i * k)).pre(deg);\n\
    \        if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return\
    \ ret;\n      }\n    }\n    return FPS(deg, mint(0));\n  }\n\n  static void *ntt_ptr;\n\
    \  static void set_fft();\n  FPS &operator*=(const FPS &r);\n  void ntt();\n \
    \ void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n  FPS inv(int\
    \ deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\n\
    void *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n * @brief \u591A\u9805\
    \u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n *\
    \ @docs docs/fps/formal-power-series.md\n */\n#line 2 \"modulo/binomial.hpp\"\n\
    \n\n\ntemplate <typename T>\nstruct Binomial {\n  vector<T> fac_, finv_, inv_;\n\
    \  Binomial(int MAX = 0) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {\n\
    \    assert(T::get_mod() != 0);\n    MAX += 9;\n    fac_[0] = finv_[0] = inv_[0]\
    \ = 1;\n    for (int i = 1; i <= MAX; i++) fac_[i] = fac_[i - 1] * i;\n    finv_[MAX]\
    \ = fac_[MAX].inverse();\n    for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i\
    \ + 1] * (i + 1);\n    for (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i\
    \ - 1];\n  }\n\n  void extend() {\n    int n = fac_.size();\n    T fac = fac_.back()\
    \ * n;\n    T inv = (-inv_[T::get_mod() % n]) * (T::get_mod() / n);\n    T finv\
    \ = finv_.back() * inv;\n    fac_.push_back(fac);\n    finv_.push_back(finv);\n\
    \    inv_.push_back(inv);\n  }\n\n  T fac(int i) {\n    while (i >= (int)fac_.size())\
    \ extend();\n    return fac_[i];\n  }\n\n  T finv(int i) {\n    while (i >= (int)finv_.size())\
    \ extend();\n    return finv_[i];\n  }\n\n  T inv(int i) {\n    while (i >= (int)inv_.size())\
    \ extend();\n    return inv_[i];\n  }\n\n  T C(int n, int r) {\n    if (n < r\
    \ || r < 0) return T(0);\n    return fac(n) * finv(n - r) * finv(r);\n  }\n\n\
    \  T C_naive(int n, int r) {\n    if (n < r || r < 0) return T(0);\n    T ret\
    \ = T(1);\n    r = min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i)\
    \ * (n--);\n    return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < r || r\
    \ < 0) return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  T H(int n, int\
    \ r) {\n    if (n < 0 || r < 0) return T(0);\n    return r == 0 ? 1 : C(n + r\
    \ - 1, r);\n  }\n};\n#line 4 \"fps/taylor-shift.hpp\"\n\n// calculate F(x + a)\n\
    template <typename mint>\nFormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint>\
    \ f, mint a,\n                                    Binomial<mint>& C) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  int N = f.size();\n  for (int i = 0; i < N;\
    \ i++) f[i] *= C.fac(i);\n  reverse(begin(f), end(f));\n  fps g(N, mint(1));\n\
    \  for (int i = 1; i < N; i++) g[i] = g[i - 1] * a * C.inv(i);\n  f = (f * g).pre(N);\n\
    \  reverse(begin(f), end(f));\n  for (int i = 0; i < N; i++) f[i] *= C.finv(i);\n\
    \  return f;\n}\n\n/**\n * @brief \u5E73\u884C\u79FB\u52D5\n * @docs docs/fps/fps-taylor-shift.md\n\
    \ */\n#line 5 \"fps/fps-famous-series.hpp\"\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ Stirling1st(int N, Binomial<mint> &C) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  if (N <= 0) return fps{1};\n  int lg = 31 - __builtin_clz(N);\n  fps f = {0,\
    \ 1};\n  for (int i = lg - 1; i >= 0; i--) {\n    int n = N >> i;\n    f *= TaylorShift(f,\
    \ mint(n >> 1), C);\n    if (n & 1) f = (f << 1) + f * (n - 1);\n  }\n  return\
    \ f;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint> Stirling2nd(int N,\
    \ Binomial<mint> &C) {\n  using fps = FormalPowerSeries<mint>;\n  fps f(N + 1),\
    \ g(N + 1);\n  for (int i = 0; i <= N; i++) {\n    f[i] = mint(i).pow(N) * C.finv(i);\n\
    \    g[i] = (i & 1) ? -C.finv(i) : C.finv(i);\n  }\n  return (f * g).pre(N + 1);\n\
    }\n\ntemplate <typename mint>\nFormalPowerSeries<mint> BernoulliEGF(int N, Binomial<mint>\
    \ &C) {\n  using fps = FormalPowerSeries<mint>;\n  fps f(N + 1);\n  for (int i\
    \ = 0; i <= N; i++) f[i] = C.finv(i + 1);\n  return f.inv(N + 1);\n}\n\ntemplate\
    \ <typename mint>\nFormalPowerSeries<mint> Partition(int N, Binomial<mint> &)\
    \ {\n  using fps = FormalPowerSeries<mint>;\n  fps f(N + 1);\n  f[0] = 1;\n  for\
    \ (int k = 1; k <= N; k++) {\n    long long k1 = 1LL * k * (3 * k + 1) / 2;\n\
    \    long long k2 = 1LL * k * (3 * k - 1) / 2;\n    if (k2 > N) break;\n    if\
    \ (k1 <= N) f[k1] += ((k & 1) ? -1 : 1);\n    if (k2 <= N) f[k2] += ((k & 1) ?\
    \ -1 : 1);\n  }\n  return f.inv();\n}\n\ntemplate <typename mint>\nvector<mint>\
    \ Montmort(int N) {\n  if (N <= 1) return {0};\n  if (N == 2) return {0, 1};\n\
    \  vector<mint> f(N);\n  f[0] = 0, f[1] = 1;\n  mint coeff = 2, one = 1;\n  for\
    \ (int i = 2; i < N; i++) {\n    f[i] = (f[i - 1] + f[i - 2]) * coeff;\n    coeff\
    \ += one;\n  }\n  return f;\n};\n\n/**\n * @brief \u6709\u540D\u306A\u6570\u5217\
    \n */\n"
  code: "#pragma once\n#include \"./formal-power-series.hpp\"\n#include \"../modulo/binomial.hpp\"\
    \n#include \"taylor-shift.hpp\"\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ Stirling1st(int N, Binomial<mint> &C) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  if (N <= 0) return fps{1};\n  int lg = 31 - __builtin_clz(N);\n  fps f = {0,\
    \ 1};\n  for (int i = lg - 1; i >= 0; i--) {\n    int n = N >> i;\n    f *= TaylorShift(f,\
    \ mint(n >> 1), C);\n    if (n & 1) f = (f << 1) + f * (n - 1);\n  }\n  return\
    \ f;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint> Stirling2nd(int N,\
    \ Binomial<mint> &C) {\n  using fps = FormalPowerSeries<mint>;\n  fps f(N + 1),\
    \ g(N + 1);\n  for (int i = 0; i <= N; i++) {\n    f[i] = mint(i).pow(N) * C.finv(i);\n\
    \    g[i] = (i & 1) ? -C.finv(i) : C.finv(i);\n  }\n  return (f * g).pre(N + 1);\n\
    }\n\ntemplate <typename mint>\nFormalPowerSeries<mint> BernoulliEGF(int N, Binomial<mint>\
    \ &C) {\n  using fps = FormalPowerSeries<mint>;\n  fps f(N + 1);\n  for (int i\
    \ = 0; i <= N; i++) f[i] = C.finv(i + 1);\n  return f.inv(N + 1);\n}\n\ntemplate\
    \ <typename mint>\nFormalPowerSeries<mint> Partition(int N, Binomial<mint> &)\
    \ {\n  using fps = FormalPowerSeries<mint>;\n  fps f(N + 1);\n  f[0] = 1;\n  for\
    \ (int k = 1; k <= N; k++) {\n    long long k1 = 1LL * k * (3 * k + 1) / 2;\n\
    \    long long k2 = 1LL * k * (3 * k - 1) / 2;\n    if (k2 > N) break;\n    if\
    \ (k1 <= N) f[k1] += ((k & 1) ? -1 : 1);\n    if (k2 <= N) f[k2] += ((k & 1) ?\
    \ -1 : 1);\n  }\n  return f.inv();\n}\n\ntemplate <typename mint>\nvector<mint>\
    \ Montmort(int N) {\n  if (N <= 1) return {0};\n  if (N == 2) return {0, 1};\n\
    \  vector<mint> f(N);\n  f[0] = 0, f[1] = 1;\n  mint coeff = 2, one = 1;\n  for\
    \ (int i = 2; i < N; i++) {\n    f[i] = (f[i - 1] + f[i - 2]) * coeff;\n    coeff\
    \ += one;\n  }\n  return f;\n};\n\n/**\n * @brief \u6709\u540D\u306A\u6570\u5217\
    \n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - modulo/binomial.hpp
  - fps/taylor-shift.hpp
  isVerificationFile: false
  path: fps/fps-famous-series.hpp
  requiredBy: []
  timestamp: '2021-01-31 00:21:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
documentation_of: fps/fps-famous-series.hpp
layout: document
redirect_from:
- /library/fps/fps-famous-series.hpp
- /library/fps/fps-famous-series.hpp.html
title: "\u6709\u540D\u306A\u6570\u5217"
---

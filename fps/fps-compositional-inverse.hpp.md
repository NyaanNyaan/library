---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/fps-composition.hpp
    title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}\\left((N \\log N)^{\\frac{3}{2}}\\\
      right)$ )"
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-compositional-inverse.test.cpp
    title: verify/verify-yosupo-fps/yosupo-compositional-inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1939.test.cpp
    title: verify/verify-yuki/yuki-1939.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps-compositional-inverse.hpp\"\n\n#include <cassert>\n\
    #include <functional>\nusing namespace std;\n\n#line 2 \"modulo/binomial.hpp\"\
    \n\n#line 4 \"modulo/binomial.hpp\"\n#include <type_traits>\n#include <vector>\n\
    using namespace std;\n\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306E MAX\
    \ \u306B \u300CC(n, r) \u3084 fac(n) \u3067\u30AF\u30A8\u30EA\u3092\u6295\u3052\
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
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 2 \"fps/formal-power-series.hpp\"\n\
    \ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n  using\
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
    \ deg = n;\n    if (k == 0) {\n      FPS ret(deg);\n      if (deg) ret[0] = 1;\n\
    \      return ret;\n    }\n    for (int i = 0; i < n; i++) {\n      if ((*this)[i]\
    \ != mint(0)) {\n        mint rev = mint(1) / (*this)[i];\n        FPS ret = (((*this\
    \ * rev) >> i).log(deg) * k).exp(deg);\n        ret *= (*this)[i].pow(k);\n  \
    \      ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n        return ret;\n      }\n      if (__int128_t(i + 1) * k >=\
    \ deg) return FPS(deg, mint(0));\n    }\n    return FPS(deg, mint(0));\n  }\n\n\
    \  static void *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const FPS\
    \ &r);\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n\
    \  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate\
    \ <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n\
    \ * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\
    \u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n */\n#line 2 \"\
    fps/fps-composition.hpp\"\n\n#line 5 \"fps/fps-composition.hpp\"\n\n// find Q(P(x))\
    \ mod x ^ min(deg(P), deg(Q))\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ Composition(FormalPowerSeries<mint> P,\n                                   \
    \ FormalPowerSeries<mint> Q,\n                                    Binomial<mint>&\
    \ C, int deg = -1) {\n  using fps = FormalPowerSeries<mint>;\n  int N = (deg ==\
    \ -1) ? min(P.size(), Q.size()) : deg;\n  if (N == 0) return fps{};\n  P.shrink();\n\
    \  if (P.size() == 0) {\n    fps R(N, mint(0));\n    R[0] = Q.empty() ? mint(0)\
    \ : Q[0];\n    return R;\n  }\n  if (N == 1) return fps{Q.eval(P[0])};\n\n  P.resize(N,\
    \ mint(0));\n  Q.resize(N, mint(0));\n  int M = max<int>(1, sqrt(N / log2(N)));\n\
    \  int L = (N + M - 1) / M;\n  fps Pm = fps{begin(P), begin(P) + M};\n  fps Pr\
    \ = fps{begin(P) + M, end(P)};\n\n  int J = 31 - __builtin_clz(N - 1) + 1;\n \
    \ vector<fps> pms(J);\n  pms[0] = Pm;\n  for (int i = 1; i < J; i++) pms[i] =\
    \ (pms[i - 1] * pms[i - 1]).pre(N);\n\n  auto comp = [&](auto rec, int left, int\
    \ j) -> fps {\n    if (j == 1) {\n      mint Q1 = left + 0 < (int)Q.size() ? Q[left\
    \ + 0] : mint(0);\n      mint Q2 = left + 1 < (int)Q.size() ? Q[left + 1] : mint(0);\n\
    \      return (pms[0].pre(N) * Q2 + Q1).pre(N);\n    }\n    if (N <= left) return\
    \ fps{};\n    fps Q1 = rec(rec, left, j - 1);\n    fps Q2 = rec(rec, left + (1\
    \ << (j - 1)), j - 1);\n    return (Q1 + pms[j - 1].pre(N) * Q2).pre(N);\n  };\n\
    \n  fps QPm = comp(comp, 0, J);\n  fps R = QPm;\n  fps pw_Pr{mint(1)};\n  fps\
    \ dPm = Pm.diff();\n  dPm.shrink();\n  // if dPm[0] == 0, dPm.inv() is undefined\n\
    \  int deg_dPm = 0;\n  while (deg_dPm != (int)dPm.size() && dPm[deg_dPm] == mint(0))\
    \ deg_dPm++;\n  fps idPm = dPm.empty() ? fps{} : (dPm >> deg_dPm).inv(N);\n\n\
    \  for (int l = 1, d = M; l <= L && d < N; l++, d += M) {\n    pw_Pr = (pw_Pr\
    \ * Pr).pre(N - d);\n    if (dPm.empty()) {\n      R += (pw_Pr * Q[l]) << d;\n\
    \    } else {\n      idPm.resize(N - d);\n      QPm = ((QPm.diff() >> deg_dPm)\
    \ * idPm).pre(N - d);\n      R += ((QPm * pw_Pr).pre(N - d) * C.finv(l)) << d;\n\
    \    };\n  }\n  R.resize(N, mint(0));\n  return R;\n}\n\n/**\n * @brief \u95A2\
    \u6570\u306E\u5408\u6210( $\\mathrm{O}\\left((N \\log N)^{\\frac{3}{2}}\\right)$\
    \ )\n * @docs docs/fps/fps-composition.md\n */\n#line 10 \"fps/fps-compositional-inverse.hpp\"\
    \n\n// f \u3092\u5165\u529B\u3068\u3057\u3066, f(g(x)) = x \u3092\u6E80\u305F\u3059\
    \ g(x) mod x^{deg} \u3092\u8FD4\u3059\ntemplate <typename fps>\nfps compositional_inverse(fps\
    \ f, int deg = -1) {\n  using mint = typename fps::value_type;\n  if (deg == -1)\
    \ deg = f.size();\n  assert((int)f.size() >= 2 && f[0] == 0 && f[1] != 0);\n \
    \ fps g{0, f[1].inverse()};\n  Binomial<mint> binom;\n  for (int d = 2; d < deg;\
    \ d *= 2) {\n    fps f2{begin(f), begin(f) + min(2 * d + 1, (int)f.size())};\n\
    \    fps fg = Composition<mint>(g, f2, binom, 2 * d + 1);\n    fps fdg = (fg.diff()\
    \ * g.diff().inv(2 * d)).pre(2 * d);\n    assert(fdg[0] != 0);\n    g = (g - (fg\
    \ - fps{0, 1}) * fdg.inv(2 * d)).pre(2 * d);\n  }\n  return {begin(g), begin(g)\
    \ + deg};\n}\n\n// f(g(x)) = x \u3092\u6E80\u305F\u3059 g(x) mod x^{deg} \u3092\
    \u8FD4\u3059\n// calc_f(g, d) \u306F f(g(x)) mod x^d \u3092\u8A08\u7B97\u3059\u308B\
    \u95A2\u6570\ntemplate <typename fps>\nfps compositional_inverse(function<fps(fps,\
    \ int)> calc_f, int deg) {\n  fps g = calc_f(fps{0, 1}, 2);\n  assert(g[0] ==\
    \ 0 && g[1] != 0);\n  g[1] = g[1].inverse();\n  for (int d = 2; d < deg; d *=\
    \ 2) {\n    fps fg = calc_f(g, 2 * d + 1);\n    trc(fg);\n    fps fdg = (fg.diff()\
    \ * g.diff().inv(2 * d)).pre(2 * d);\n    trc(fdg);\n    g = (g - (fg - fps{0,\
    \ 1}) * fdg.inv(2 * d)).pre(2 * d);\n  }\n  return {begin(g), begin(g) + deg};\n\
    }\n\n/*\n *  \u9006\u95A2\u6570\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\nusing namespace\
    \ std;\n\n#include \"../modulo/binomial.hpp\"\n#include \"formal-power-series.hpp\"\
    \n#include \"fps-composition.hpp\"\n\n// f \u3092\u5165\u529B\u3068\u3057\u3066\
    , f(g(x)) = x \u3092\u6E80\u305F\u3059 g(x) mod x^{deg} \u3092\u8FD4\u3059\ntemplate\
    \ <typename fps>\nfps compositional_inverse(fps f, int deg = -1) {\n  using mint\
    \ = typename fps::value_type;\n  if (deg == -1) deg = f.size();\n  assert((int)f.size()\
    \ >= 2 && f[0] == 0 && f[1] != 0);\n  fps g{0, f[1].inverse()};\n  Binomial<mint>\
    \ binom;\n  for (int d = 2; d < deg; d *= 2) {\n    fps f2{begin(f), begin(f)\
    \ + min(2 * d + 1, (int)f.size())};\n    fps fg = Composition<mint>(g, f2, binom,\
    \ 2 * d + 1);\n    fps fdg = (fg.diff() * g.diff().inv(2 * d)).pre(2 * d);\n \
    \   assert(fdg[0] != 0);\n    g = (g - (fg - fps{0, 1}) * fdg.inv(2 * d)).pre(2\
    \ * d);\n  }\n  return {begin(g), begin(g) + deg};\n}\n\n// f(g(x)) = x \u3092\
    \u6E80\u305F\u3059 g(x) mod x^{deg} \u3092\u8FD4\u3059\n// calc_f(g, d) \u306F\
    \ f(g(x)) mod x^d \u3092\u8A08\u7B97\u3059\u308B\u95A2\u6570\ntemplate <typename\
    \ fps>\nfps compositional_inverse(function<fps(fps, int)> calc_f, int deg) {\n\
    \  fps g = calc_f(fps{0, 1}, 2);\n  assert(g[0] == 0 && g[1] != 0);\n  g[1] =\
    \ g[1].inverse();\n  for (int d = 2; d < deg; d *= 2) {\n    fps fg = calc_f(g,\
    \ 2 * d + 1);\n    trc(fg);\n    fps fdg = (fg.diff() * g.diff().inv(2 * d)).pre(2\
    \ * d);\n    trc(fdg);\n    g = (g - (fg - fps{0, 1}) * fdg.inv(2 * d)).pre(2\
    \ * d);\n  }\n  return {begin(g), begin(g) + deg};\n}\n\n/*\n *  \u9006\u95A2\u6570\
    \n */\n"
  dependsOn:
  - modulo/binomial.hpp
  - fps/formal-power-series.hpp
  - fps/fps-composition.hpp
  isVerificationFile: false
  path: fps/fps-compositional-inverse.hpp
  requiredBy: []
  timestamp: '2023-05-27 23:17:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1939.test.cpp
  - verify/verify-yosupo-fps/yosupo-compositional-inverse.test.cpp
documentation_of: fps/fps-compositional-inverse.hpp
layout: document
redirect_from:
- /library/fps/fps-compositional-inverse.hpp
- /library/fps/fps-compositional-inverse.hpp.html
title: fps/fps-compositional-inverse.hpp
---

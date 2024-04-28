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
    path: verify/verify-unit-test/composition.test.cpp
    title: verify/verify-unit-test/composition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-composition-large.test.cpp
    title: verify/verify-yosupo-fps/yosupo-composition-large.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N \\log^2 N)$ )"
    links: []
  bundledCode: "#line 2 \"fps/fps-composition.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\n#line 2 \"fps/formal-power-series.hpp\"\n\n\
    template <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n\
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
    \ */\n#line 8 \"fps/fps-composition.hpp\"\n\n// g(f(x)) \u3092\u8A08\u7B97\ntemplate\
    \ <typename mint>\nFormalPowerSeries<mint> composition(FormalPowerSeries<mint>\
    \ f,\n                                    FormalPowerSeries<mint> g, int deg =\
    \ -1) {\n  using fps = FormalPowerSeries<mint>;\n\n  auto dfs = [&](auto rc, fps\
    \ Q, int n, int h, int k) -> fps {\n    if (n == 0) {\n      fps T{begin(Q), begin(Q)\
    \ + k};\n      T.push_back(1);\n      fps u = g * T.rev().inv().rev();\n     \
    \ fps P(h * k);\n      for (int i = 0; i < (int)g.size(); i++) P[k - 1 - i] =\
    \ u[i + k];\n      return P;\n    }\n    fps nQ(4 * h * k), nR(2 * h * k);\n \
    \   for (int i = 0; i < k; i++) {\n      copy(begin(Q) + i * h, begin(Q) + i *\
    \ h + n + 1, begin(nQ) + i * 2 * h);\n    }\n    nQ[k * 2 * h] += 1;\n    nQ.ntt();\n\
    \    for (int i = 0; i < 4 * h * k; i += 2) swap(nQ[i], nQ[i + 1]);\n    for (int\
    \ i = 0; i < 2 * h * k; i++) nR[i] = nQ[i * 2] * nQ[i * 2 + 1];\n    nR.intt();\n\
    \    nR[0] -= 1;\n    Q.assign(h * k, 0);\n    for (int i = 0; i < 2 * k; i++)\
    \ {\n      for (int j = 0; j <= n / 2; j++) {\n        Q[i * h / 2 + j] = nR[i\
    \ * h + j];\n      }\n    }\n    auto P = rc(rc, Q, n / 2, h / 2, k * 2);\n  \
    \  fps nP(4 * h * k);\n    for (int i = 0; i < 2 * k; i++) {\n      for (int j\
    \ = 0; j <= n / 2; j++) {\n        nP[i * 2 * h + j * 2 + n % 2] = P[i * h / 2\
    \ + j];\n      }\n    }\n    nP.ntt();\n    for (int i = 1; i < 4 * h * k; i *=\
    \ 2) {\n      reverse(begin(nQ) + i, begin(nQ) + i * 2);\n    }\n    for (int\
    \ i = 0; i < 4 * h * k; i++) nP[i] *= nQ[i];\n    nP.intt();\n    P.assign(h *\
    \ k, 0);\n    for (int i = 0; i < k; i++) {\n      copy(begin(nP) + i * 2 * h,\
    \ begin(nP) + i * 2 * h + n + 1,\n           begin(P) + i * h);\n    }\n    return\
    \ P;\n  };\n\n  if (deg == -1) deg = max(f.size(), g.size());\n  f.resize(deg),\
    \ g.resize(deg);\n  int n = f.size() - 1, k = 1;\n  int h = 1;\n  while (h < n\
    \ + 1) h *= 2;\n  fps Q(h * k);\n  for (int i = 0; i <= n; i++) Q[i] = -f[i];\n\
    \  fps P = dfs(dfs, Q, n, h, k);\n  return P.pre(n + 1).rev();\n}\n\n/**\n * @brief\
    \ \u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N \\log^2 N)$ )\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \n#include \"formal-power-series.hpp\"\n\n// g(f(x)) \u3092\u8A08\u7B97\ntemplate\
    \ <typename mint>\nFormalPowerSeries<mint> composition(FormalPowerSeries<mint>\
    \ f,\n                                    FormalPowerSeries<mint> g, int deg =\
    \ -1) {\n  using fps = FormalPowerSeries<mint>;\n\n  auto dfs = [&](auto rc, fps\
    \ Q, int n, int h, int k) -> fps {\n    if (n == 0) {\n      fps T{begin(Q), begin(Q)\
    \ + k};\n      T.push_back(1);\n      fps u = g * T.rev().inv().rev();\n     \
    \ fps P(h * k);\n      for (int i = 0; i < (int)g.size(); i++) P[k - 1 - i] =\
    \ u[i + k];\n      return P;\n    }\n    fps nQ(4 * h * k), nR(2 * h * k);\n \
    \   for (int i = 0; i < k; i++) {\n      copy(begin(Q) + i * h, begin(Q) + i *\
    \ h + n + 1, begin(nQ) + i * 2 * h);\n    }\n    nQ[k * 2 * h] += 1;\n    nQ.ntt();\n\
    \    for (int i = 0; i < 4 * h * k; i += 2) swap(nQ[i], nQ[i + 1]);\n    for (int\
    \ i = 0; i < 2 * h * k; i++) nR[i] = nQ[i * 2] * nQ[i * 2 + 1];\n    nR.intt();\n\
    \    nR[0] -= 1;\n    Q.assign(h * k, 0);\n    for (int i = 0; i < 2 * k; i++)\
    \ {\n      for (int j = 0; j <= n / 2; j++) {\n        Q[i * h / 2 + j] = nR[i\
    \ * h + j];\n      }\n    }\n    auto P = rc(rc, Q, n / 2, h / 2, k * 2);\n  \
    \  fps nP(4 * h * k);\n    for (int i = 0; i < 2 * k; i++) {\n      for (int j\
    \ = 0; j <= n / 2; j++) {\n        nP[i * 2 * h + j * 2 + n % 2] = P[i * h / 2\
    \ + j];\n      }\n    }\n    nP.ntt();\n    for (int i = 1; i < 4 * h * k; i *=\
    \ 2) {\n      reverse(begin(nQ) + i, begin(nQ) + i * 2);\n    }\n    for (int\
    \ i = 0; i < 4 * h * k; i++) nP[i] *= nQ[i];\n    nP.intt();\n    P.assign(h *\
    \ k, 0);\n    for (int i = 0; i < k; i++) {\n      copy(begin(nP) + i * 2 * h,\
    \ begin(nP) + i * 2 * h + n + 1,\n           begin(P) + i * h);\n    }\n    return\
    \ P;\n  };\n\n  if (deg == -1) deg = max(f.size(), g.size());\n  f.resize(deg),\
    \ g.resize(deg);\n  int n = f.size() - 1, k = 1;\n  int h = 1;\n  while (h < n\
    \ + 1) h *= 2;\n  fps Q(h * k);\n  for (int i = 0; i <= n; i++) Q[i] = -f[i];\n\
    \  fps P = dfs(dfs, Q, n, h, k);\n  return P.pre(n + 1).rev();\n}\n\n/**\n * @brief\
    \ \u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N \\log^2 N)$ )\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/fps-composition.hpp
  requiredBy: []
  timestamp: '2024-03-23 07:13:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/composition.test.cpp
  - verify/verify-yosupo-fps/yosupo-composition-large.test.cpp
documentation_of: fps/fps-composition.hpp
layout: document
redirect_from:
- /library/fps/fps-composition.hpp
- /library/fps/fps-composition.hpp.html
title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N \\log^2 N)$ )"
---

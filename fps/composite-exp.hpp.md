---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/stirling-matrix.hpp
    title: fps/stirling-matrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/composite-exp.test.cpp
    title: verify/verify-unit-test/composite-exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/stirling-matrix.test.cpp
    title: verify/verify-unit-test/stirling-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1875.test.cpp
    title: verify/verify-yuki/yuki-1875.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "$f(exp(cx))$ \u306E\u8A08\u7B97"
    links: []
  bundledCode: "#line 2 \"fps/composite-exp.hpp\"\n\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\nusing namespace std;\n\n#line 2 \"fps/formal-power-series.hpp\"\
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
    \n * @docs docs/fps/formal-power-series.md\n */\n#line 9 \"fps/composite-exp.hpp\"\
    \n\n// \u591A\u9805\u5F0F f \u306B exp(cx) \u4EE3\u5165\n// \u6B21\u6570 : mod\
    \ x^{deg} \u307E\u3067\u8A08\u7B97, \u6307\u5B9A\u304C\u306A\u3044\u5834\u5408\
    \ f \u3068\u540C\u3058\u9577\u3055\u8A08\u7B97\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ composite_exp(FormalPowerSeries<mint> f, mint c = 1,\n                     \
    \                 int deg = -1) {\n  using fps = FormalPowerSeries<mint>;\n  assert(c\
    \ != 0);\n  if (deg == -1) deg = f.size();\n\n  if (f.empty()) return {};\n  int\
    \ N = f.size();\n  vector<pair<fps, fps>> fs;\n  for (int i = 0; i < N; i++) fs.emplace_back(fps{f[i]},\
    \ fps{1, -c * i});\n  while (fs.size() > 1u) {\n    vector<pair<fps, fps>> nx;\n\
    \    for (int i = 0; i + 1 < (int)fs.size(); i += 2) {\n      pair<fps, fps>&\
    \ f0 = fs[i];\n      pair<fps, fps>& f1 = fs[i + 1];\n      fps s = f0.first *\
    \ f1.second + f1.first * f0.second;\n      fps t = f0.second * f1.second;\n  \
    \    nx.emplace_back(s, t);\n    }\n    if (fs.size() % 2) nx.push_back(fs.back());\n\
    \    fs = nx;\n  }\n  fps g = (fs[0].first * fs[0].second.inv(deg)).pre(deg);\n\
    \  mint b = 1;\n  for (int i = 0; i < deg; i++) g[i] *= b, b /= i + 1;\n  return\
    \ g;\n}\n\n// \u5165\u529B f(x) = sum_{0 <= k < N} a_i exp(ckx) \u3092\u6E80\u305F\
    \u3059 g(x) (mod x^N)\n// \u51FA\u529B a(x) = sum_{0 <= k < N} a_i x^i\ntemplate\
    \ <typename mint>\nFormalPowerSeries<mint> inverse_of_composite_exp(FormalPowerSeries<mint>\
    \ f,\n                                                 mint c = 1) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  if (f.empty()) return {};\n  int N = f.size();\n\
    \  mint b = 1;\n  for (int i = 0; i < N; i++) f[i] *= b, b *= i + 1;\n\n  int\
    \ B = 1;\n  while (B < N) B *= 2;\n  vector<fps> mod(2 * B, fps{1});\n  for (int\
    \ i = 0; i < N; i++) mod[B + i] = fps{-c * i, 1};\n  for (int i = B - 1; i; i--)\
    \ mod[i] = mod[2 * i] * mod[2 * i + 1];\n  fps denom = mod[1].rev();\n  fps numer\
    \ = (f * denom).pre(N);\n\n  vector<mint> a(N);\n  auto dfs = [&](auto rc, int\
    \ i, int l, int r, fps g) -> void {\n    if (N <= l) return;\n    if (l + 1 ==\
    \ r) {\n      a[l] = g.eval(0);\n      return;\n    }\n    int m = (l + r) / 2;\n\
    \    rc(rc, i * 2 + 0, l, m, g % mod[i * 2 + 0]);\n    rc(rc, i * 2 + 1, m, r,\
    \ g % mod[i * 2 + 1]);\n  };\n  dfs(dfs, 1, 0, B, numer.rev());\n\n  vector<mint>\
    \ fac(N);\n  fac[0] = 1;\n  for (int i = 1; i < N; i++) fac[i] = fac[i - 1] *\
    \ c * i;\n  for (int i = 0; i < N; i++) {\n    a[i] /= fac[N - 1 - i] * fac[i]\
    \ * ((N - 1 - i) % 2 ? -1 : 1);\n  }\n  return fps{begin(a), end(a)};\n}\n\n/**\n\
    \ * @brief $f(exp(cx))$ \u306E\u8A08\u7B97\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\n#include \"formal-power-series.hpp\"\n\n// \u591A\u9805\
    \u5F0F f \u306B exp(cx) \u4EE3\u5165\n// \u6B21\u6570 : mod x^{deg} \u307E\u3067\
    \u8A08\u7B97, \u6307\u5B9A\u304C\u306A\u3044\u5834\u5408 f \u3068\u540C\u3058\u9577\
    \u3055\u8A08\u7B97\ntemplate <typename mint>\nFormalPowerSeries<mint> composite_exp(FormalPowerSeries<mint>\
    \ f, mint c = 1,\n                                      int deg = -1) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  assert(c != 0);\n  if (deg == -1) deg = f.size();\n\
    \n  if (f.empty()) return {};\n  int N = f.size();\n  vector<pair<fps, fps>> fs;\n\
    \  for (int i = 0; i < N; i++) fs.emplace_back(fps{f[i]}, fps{1, -c * i});\n \
    \ while (fs.size() > 1u) {\n    vector<pair<fps, fps>> nx;\n    for (int i = 0;\
    \ i + 1 < (int)fs.size(); i += 2) {\n      pair<fps, fps>& f0 = fs[i];\n     \
    \ pair<fps, fps>& f1 = fs[i + 1];\n      fps s = f0.first * f1.second + f1.first\
    \ * f0.second;\n      fps t = f0.second * f1.second;\n      nx.emplace_back(s,\
    \ t);\n    }\n    if (fs.size() % 2) nx.push_back(fs.back());\n    fs = nx;\n\
    \  }\n  fps g = (fs[0].first * fs[0].second.inv(deg)).pre(deg);\n  mint b = 1;\n\
    \  for (int i = 0; i < deg; i++) g[i] *= b, b /= i + 1;\n  return g;\n}\n\n//\
    \ \u5165\u529B f(x) = sum_{0 <= k < N} a_i exp(ckx) \u3092\u6E80\u305F\u3059 g(x)\
    \ (mod x^N)\n// \u51FA\u529B a(x) = sum_{0 <= k < N} a_i x^i\ntemplate <typename\
    \ mint>\nFormalPowerSeries<mint> inverse_of_composite_exp(FormalPowerSeries<mint>\
    \ f,\n                                                 mint c = 1) {\n  using\
    \ fps = FormalPowerSeries<mint>;\n  if (f.empty()) return {};\n  int N = f.size();\n\
    \  mint b = 1;\n  for (int i = 0; i < N; i++) f[i] *= b, b *= i + 1;\n\n  int\
    \ B = 1;\n  while (B < N) B *= 2;\n  vector<fps> mod(2 * B, fps{1});\n  for (int\
    \ i = 0; i < N; i++) mod[B + i] = fps{-c * i, 1};\n  for (int i = B - 1; i; i--)\
    \ mod[i] = mod[2 * i] * mod[2 * i + 1];\n  fps denom = mod[1].rev();\n  fps numer\
    \ = (f * denom).pre(N);\n\n  vector<mint> a(N);\n  auto dfs = [&](auto rc, int\
    \ i, int l, int r, fps g) -> void {\n    if (N <= l) return;\n    if (l + 1 ==\
    \ r) {\n      a[l] = g.eval(0);\n      return;\n    }\n    int m = (l + r) / 2;\n\
    \    rc(rc, i * 2 + 0, l, m, g % mod[i * 2 + 0]);\n    rc(rc, i * 2 + 1, m, r,\
    \ g % mod[i * 2 + 1]);\n  };\n  dfs(dfs, 1, 0, B, numer.rev());\n\n  vector<mint>\
    \ fac(N);\n  fac[0] = 1;\n  for (int i = 1; i < N; i++) fac[i] = fac[i - 1] *\
    \ c * i;\n  for (int i = 0; i < N; i++) {\n    a[i] /= fac[N - 1 - i] * fac[i]\
    \ * ((N - 1 - i) % 2 ? -1 : 1);\n  }\n  return fps{begin(a), end(a)};\n}\n\n/**\n\
    \ * @brief $f(exp(cx))$ \u306E\u8A08\u7B97\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/composite-exp.hpp
  requiredBy:
  - fps/stirling-matrix.hpp
  timestamp: '2023-08-31 20:44:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/composite-exp.test.cpp
  - verify/verify-unit-test/stirling-matrix.test.cpp
  - verify/verify-yuki/yuki-1875.test.cpp
documentation_of: fps/composite-exp.hpp
layout: document
redirect_from:
- /library/fps/composite-exp.hpp
- /library/fps/composite-exp.hpp.html
title: "$f(exp(cx))$ \u306E\u8A08\u7B97"
---

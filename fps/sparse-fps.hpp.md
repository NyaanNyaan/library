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
    path: verify/verify-unit-test/fps-sparse.test.cpp
    title: verify/verify-unit-test/fps-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sparse-exp.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sparse-exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sparse-inv.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sparse-inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sparse-log.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sparse-log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sparse-pow.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sparse-pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1939-sparse-pow.test.cpp
    title: verify/verify-yuki/yuki-1939-sparse-pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "sparse \u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u306E\u6F14\
      \u7B97"
    links: []
  bundledCode: "#line 2 \"fps/sparse-fps.hpp\"\n\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\n#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <typename\
    \ mint>\nstruct FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n\
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
    \ */\n#line 8 \"fps/sparse-fps.hpp\"\n\n// g \u304C sparse \u3092\u4EEE\u5B9A\
    , f * g.inv() \u3092\u8A08\u7B97\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ sparse_div(const FormalPowerSeries<mint>& f,\n                             \
    \      const FormalPowerSeries<mint>& g,\n                                   int\
    \ deg = -1) {\n  assert(g.empty() == false && g[0] != mint(0));\n  if (deg ==\
    \ -1) deg = f.size();\n  mint ig0 = g[0].inverse();\n  FormalPowerSeries<mint>\
    \ s = f * ig0;\n  s.resize(deg);\n  vector<pair<int, mint>> gs;\n  for (int i\
    \ = 1; i < (int)g.size(); i++) {\n    if (g[i] != 0) gs.emplace_back(i, g[i] *\
    \ ig0);\n  }\n  for (int i = 0; i < deg; i++) {\n    for (auto& [j, g_j] : gs)\
    \ {\n      if (i + j >= deg) break;\n      s[i + j] -= s[i] * g_j;\n    }\n  }\n\
    \  return s;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint> sparse_inv(const\
    \ FormalPowerSeries<mint>& f,\n                                   int deg = -1)\
    \ {\n  assert(f.empty() == false && f[0] != mint(0));\n  if (deg == -1) deg =\
    \ f.size();\n  vector<pair<int, mint>> fs;\n  for (int i = 1; i < (int)f.size();\
    \ i++) {\n    if (f[i] != 0) fs.emplace_back(i, f[i]);\n  }\n  FormalPowerSeries<mint>\
    \ g(deg);\n  mint if0 = f[0].inverse();\n  if (0 < deg) g[0] = if0;\n  for (int\
    \ k = 1; k < deg; k++) {\n    for (auto& [j, fj] : fs) {\n      if (k < j) break;\n\
    \      g[k] += g[k - j] * fj;\n    }\n    g[k] *= -if0;\n  }\n  return g;\n}\n\
    \ntemplate <typename mint>\nFormalPowerSeries<mint> sparse_log(const FormalPowerSeries<mint>&\
    \ f,\n                                   int deg = -1) {\n  assert(f.empty() ==\
    \ false && f[0] == 1);\n  if (deg == -1) deg = f.size();\n  vector<pair<int, mint>>\
    \ fs;\n  for (int i = 1; i < (int)f.size(); i++) {\n    if (f[i] != 0) fs.emplace_back(i,\
    \ f[i]);\n  }\n\n  int mod = mint::get_mod();\n  static vector<mint> invs{1, 1};\n\
    \  while ((int)invs.size() <= deg) {\n    int i = invs.size();\n    invs.push_back((-invs[mod\
    \ % i]) * (mod / i));\n  }\n\n  FormalPowerSeries<mint> g(deg);\n  for (int k\
    \ = 0; k < deg - 1; k++) {\n    for (auto& [j, fj] : fs) {\n      if (k < j) break;\n\
    \      int i = k - j;\n      g[k + 1] -= g[i + 1] * fj * (i + 1);\n    }\n   \
    \ g[k + 1] *= invs[k + 1];\n    if (k + 1 < (int)f.size()) g[k + 1] += f[k + 1];\n\
    \  }\n  return g;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint> sparse_exp(const\
    \ FormalPowerSeries<mint>& f,\n                                   int deg = -1)\
    \ {\n  assert(f.empty() or f[0] == 0);\n  if (deg == -1) deg = f.size();\n  vector<pair<int,\
    \ mint>> fs;\n  for (int i = 1; i < (int)f.size(); i++) {\n    if (f[i] != 0)\
    \ fs.emplace_back(i, f[i]);\n  }\n\n  int mod = mint::get_mod();\n  static vector<mint>\
    \ invs{1, 1};\n  while ((int)invs.size() <= deg) {\n    int i = invs.size();\n\
    \    invs.push_back((-invs[mod % i]) * (mod / i));\n  }\n\n  FormalPowerSeries<mint>\
    \ g(deg);\n  if (deg) g[0] = 1;\n  for (int k = 0; k < deg - 1; k++) {\n    for\
    \ (auto& [ip1, fip1] : fs) {\n      int i = ip1 - 1;\n      if (k < i) break;\n\
    \      g[k + 1] += fip1 * g[k - i] * (i + 1);\n    }\n    g[k + 1] *= invs[k +\
    \ 1];\n  }\n  return g;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ sparse_pow(const FormalPowerSeries<mint>& f,\n                             \
    \      long long k, int deg = -1) {\n  if (deg == -1) deg = f.size();\n  if (k\
    \ == 0) {\n    FormalPowerSeries<mint> g(deg);\n    if (deg) g[0] = 1;\n    return\
    \ g;\n  }\n  int zero = 0;\n  while (zero != (int)f.size() and f[zero] == 0) zero++;\n\
    \  if (zero == (int)f.size() or __int128_t(zero) * k >= deg) {\n    return FormalPowerSeries<mint>(deg,\
    \ 0);\n  }\n  if (zero != 0) {\n    FormalPowerSeries<mint> suf{begin(f) + zero,\
    \ end(f)};\n    auto g = sparse_pow(suf, k, deg - zero * k);\n    FormalPowerSeries<mint>\
    \ h(zero * k, 0);\n    copy(begin(g), end(g), back_inserter(h));\n    return h;\n\
    \  }\n\n  int mod = mint::get_mod();\n  static vector<mint> invs{1, 1};\n  while\
    \ ((int)invs.size() <= deg) {\n    int i = invs.size();\n    invs.push_back((-invs[mod\
    \ % i]) * (mod / i));\n  }\n\n  vector<pair<int, mint>> fs;\n  for (int i = 1;\
    \ i < (int)f.size(); i++) {\n    if (f[i] != 0) fs.emplace_back(i, f[i]);\n  }\n\
    \n  FormalPowerSeries<mint> g(deg);\n  g[0] = f[0].pow(k);\n  mint denom = f[0].inverse();\n\
    \  k %= mint::get_mod();\n  for (int a = 1; a < deg; a++) {\n    for (auto& [i,\
    \ f_i] : fs) {\n      if (a < i) break;\n      g[a] += f_i * g[a - i] * ((k +\
    \ 1) * i - a);\n    }\n    g[a] *= denom * invs[a];\n  }\n  return g;\n}\n\n/**\n\
    \ * @brief sparse \u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u306E\u6F14\u7B97\
    \n */\n"
  code: "#pragma once\n\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \n#include \"formal-power-series.hpp\"\n\n// g \u304C sparse \u3092\u4EEE\u5B9A\
    , f * g.inv() \u3092\u8A08\u7B97\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ sparse_div(const FormalPowerSeries<mint>& f,\n                             \
    \      const FormalPowerSeries<mint>& g,\n                                   int\
    \ deg = -1) {\n  assert(g.empty() == false && g[0] != mint(0));\n  if (deg ==\
    \ -1) deg = f.size();\n  mint ig0 = g[0].inverse();\n  FormalPowerSeries<mint>\
    \ s = f * ig0;\n  s.resize(deg);\n  vector<pair<int, mint>> gs;\n  for (int i\
    \ = 1; i < (int)g.size(); i++) {\n    if (g[i] != 0) gs.emplace_back(i, g[i] *\
    \ ig0);\n  }\n  for (int i = 0; i < deg; i++) {\n    for (auto& [j, g_j] : gs)\
    \ {\n      if (i + j >= deg) break;\n      s[i + j] -= s[i] * g_j;\n    }\n  }\n\
    \  return s;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint> sparse_inv(const\
    \ FormalPowerSeries<mint>& f,\n                                   int deg = -1)\
    \ {\n  assert(f.empty() == false && f[0] != mint(0));\n  if (deg == -1) deg =\
    \ f.size();\n  vector<pair<int, mint>> fs;\n  for (int i = 1; i < (int)f.size();\
    \ i++) {\n    if (f[i] != 0) fs.emplace_back(i, f[i]);\n  }\n  FormalPowerSeries<mint>\
    \ g(deg);\n  mint if0 = f[0].inverse();\n  if (0 < deg) g[0] = if0;\n  for (int\
    \ k = 1; k < deg; k++) {\n    for (auto& [j, fj] : fs) {\n      if (k < j) break;\n\
    \      g[k] += g[k - j] * fj;\n    }\n    g[k] *= -if0;\n  }\n  return g;\n}\n\
    \ntemplate <typename mint>\nFormalPowerSeries<mint> sparse_log(const FormalPowerSeries<mint>&\
    \ f,\n                                   int deg = -1) {\n  assert(f.empty() ==\
    \ false && f[0] == 1);\n  if (deg == -1) deg = f.size();\n  vector<pair<int, mint>>\
    \ fs;\n  for (int i = 1; i < (int)f.size(); i++) {\n    if (f[i] != 0) fs.emplace_back(i,\
    \ f[i]);\n  }\n\n  int mod = mint::get_mod();\n  static vector<mint> invs{1, 1};\n\
    \  while ((int)invs.size() <= deg) {\n    int i = invs.size();\n    invs.push_back((-invs[mod\
    \ % i]) * (mod / i));\n  }\n\n  FormalPowerSeries<mint> g(deg);\n  for (int k\
    \ = 0; k < deg - 1; k++) {\n    for (auto& [j, fj] : fs) {\n      if (k < j) break;\n\
    \      int i = k - j;\n      g[k + 1] -= g[i + 1] * fj * (i + 1);\n    }\n   \
    \ g[k + 1] *= invs[k + 1];\n    if (k + 1 < (int)f.size()) g[k + 1] += f[k + 1];\n\
    \  }\n  return g;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint> sparse_exp(const\
    \ FormalPowerSeries<mint>& f,\n                                   int deg = -1)\
    \ {\n  assert(f.empty() or f[0] == 0);\n  if (deg == -1) deg = f.size();\n  vector<pair<int,\
    \ mint>> fs;\n  for (int i = 1; i < (int)f.size(); i++) {\n    if (f[i] != 0)\
    \ fs.emplace_back(i, f[i]);\n  }\n\n  int mod = mint::get_mod();\n  static vector<mint>\
    \ invs{1, 1};\n  while ((int)invs.size() <= deg) {\n    int i = invs.size();\n\
    \    invs.push_back((-invs[mod % i]) * (mod / i));\n  }\n\n  FormalPowerSeries<mint>\
    \ g(deg);\n  if (deg) g[0] = 1;\n  for (int k = 0; k < deg - 1; k++) {\n    for\
    \ (auto& [ip1, fip1] : fs) {\n      int i = ip1 - 1;\n      if (k < i) break;\n\
    \      g[k + 1] += fip1 * g[k - i] * (i + 1);\n    }\n    g[k + 1] *= invs[k +\
    \ 1];\n  }\n  return g;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ sparse_pow(const FormalPowerSeries<mint>& f,\n                             \
    \      long long k, int deg = -1) {\n  if (deg == -1) deg = f.size();\n  if (k\
    \ == 0) {\n    FormalPowerSeries<mint> g(deg);\n    if (deg) g[0] = 1;\n    return\
    \ g;\n  }\n  int zero = 0;\n  while (zero != (int)f.size() and f[zero] == 0) zero++;\n\
    \  if (zero == (int)f.size() or __int128_t(zero) * k >= deg) {\n    return FormalPowerSeries<mint>(deg,\
    \ 0);\n  }\n  if (zero != 0) {\n    FormalPowerSeries<mint> suf{begin(f) + zero,\
    \ end(f)};\n    auto g = sparse_pow(suf, k, deg - zero * k);\n    FormalPowerSeries<mint>\
    \ h(zero * k, 0);\n    copy(begin(g), end(g), back_inserter(h));\n    return h;\n\
    \  }\n\n  int mod = mint::get_mod();\n  static vector<mint> invs{1, 1};\n  while\
    \ ((int)invs.size() <= deg) {\n    int i = invs.size();\n    invs.push_back((-invs[mod\
    \ % i]) * (mod / i));\n  }\n\n  vector<pair<int, mint>> fs;\n  for (int i = 1;\
    \ i < (int)f.size(); i++) {\n    if (f[i] != 0) fs.emplace_back(i, f[i]);\n  }\n\
    \n  FormalPowerSeries<mint> g(deg);\n  g[0] = f[0].pow(k);\n  mint denom = f[0].inverse();\n\
    \  k %= mint::get_mod();\n  for (int a = 1; a < deg; a++) {\n    for (auto& [i,\
    \ f_i] : fs) {\n      if (a < i) break;\n      g[a] += f_i * g[a - i] * ((k +\
    \ 1) * i - a);\n    }\n    g[a] *= denom * invs[a];\n  }\n  return g;\n}\n\n/**\n\
    \ * @brief sparse \u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u306E\u6F14\u7B97\
    \n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/sparse-fps.hpp
  requiredBy: []
  timestamp: '2023-08-31 20:44:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-sparse-log.test.cpp
  - verify/verify-yosupo-fps/yosupo-sparse-exp.test.cpp
  - verify/verify-yosupo-fps/yosupo-sparse-pow.test.cpp
  - verify/verify-yosupo-fps/yosupo-sparse-inv.test.cpp
  - verify/verify-yuki/yuki-1939-sparse-pow.test.cpp
  - verify/verify-unit-test/fps-sparse.test.cpp
documentation_of: fps/sparse-fps.hpp
layout: document
redirect_from:
- /library/fps/sparse-fps.hpp
- /library/fps/sparse-fps.hpp.html
title: "sparse \u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u306E\u6F14\u7B97"
---

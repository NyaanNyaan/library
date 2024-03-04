---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/mod-pow.hpp
    title: Mod-Pow ($f(x)^k \mod g(x)$)
  - icon: ':heavy_check_mark:'
    path: fps/polynomial-gcd.hpp
    title: "\u591A\u9805\u5F0FGCD"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-polynomial-root-finding.test.cpp
    title: verify/verify-yosupo-fps/yosupo-polynomial-root-finding.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/root-finding.hpp\"\n\n#include <random>\n#include <vector>\n\
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
    \ */\n#line 2 \"fps/mod-pow.hpp\"\n\n#line 4 \"fps/mod-pow.hpp\"\n\ntemplate <typename\
    \ mint>\nFormalPowerSeries<mint> mod_pow(int64_t k, const FormalPowerSeries<mint>&\
    \ base,\n                                const FormalPowerSeries<mint>& d) {\n\
    \  using fps = FormalPowerSeries<mint>;\n  assert(!d.empty());\n  auto inv = d.rev().inv();\n\
    \  auto quo = [&](const fps& poly) {\n    if (poly.size() < d.size()) return fps{};\n\
    \    int n = poly.size() - d.size() + 1;\n    return (poly.rev().pre(n) * inv.pre(n)).pre(n).rev();\n\
    \  };\n  fps res{1}, b(base);\n  while (k) {\n    if (k & 1) {\n      res *= b;\n\
    \      res -= quo(res) * d;\n      res.shrink();\n    }\n    b *= b;\n    b -=\
    \ quo(b) * d;\n    b.shrink();\n    k >>= 1;\n    assert(b.size() + 1 <= d.size());\n\
    \    assert(res.size() + 1 <= d.size());\n  }\n  return res;\n}\n\n/**\n * @brief\
    \ Mod-Pow ($f(x)^k \\mod g(x)$)\n */\n#line 2 \"fps/polynomial-gcd.hpp\"\n\n#line\
    \ 4 \"fps/polynomial-gcd.hpp\"\n\nnamespace poly_gcd {\n\ntemplate <typename mint>\n\
    using FPS = FormalPowerSeries<mint>;\ntemplate <typename mint>\nusing Arr = pair<FPS<mint>,\
    \ FPS<mint>>;\n\ntemplate <typename mint>\nstruct Mat {\n  using fps = FPS<mint>;\n\
    \  fps a00, a01, a10, a11;\n\n  Mat() = default;\n  Mat(const fps& a00_, const\
    \ fps& a01_, const fps& a10_, const fps& a11_)\n      : a00(a00_), a01(a01_),\
    \ a10(a10_), a11(a11_) {}\n\n  Mat& operator*=(const Mat& r) {\n    fps A00 =\
    \ a00 * r.a00 + a01 * r.a10;\n    fps A01 = a00 * r.a01 + a01 * r.a11;\n    fps\
    \ A10 = a10 * r.a00 + a11 * r.a10;\n    fps A11 = a10 * r.a01 + a11 * r.a11;\n\
    \    A00.shrink();\n    A01.shrink();\n    A10.shrink();\n    A11.shrink();\n\
    \    swap(A00, a00);\n    swap(A01, a01);\n    swap(A10, a10);\n    swap(A11,\
    \ a11);\n    return *this;\n  }\n\n  static Mat I() { return Mat(fps{mint(1)},\
    \ fps(), fps(), fps{mint(1)}); }\n\n  Mat operator*(const Mat& r) const { return\
    \ Mat(*this) *= r; }\n};\n\ntemplate <typename mint>\nArr<mint> operator*(const\
    \ Mat<mint>& m, const Arr<mint>& a) {\n  using fps = FPS<mint>;\n  fps b0 = m.a00\
    \ * a.first + m.a01 * a.second;\n  fps b1 = m.a10 * a.first + m.a11 * a.second;\n\
    \  b0.shrink();\n  b1.shrink();\n  return {b0, b1};\n};\n\ntemplate <typename\
    \ mint>\nvoid InnerNaiveGCD(Mat<mint>& m, Arr<mint>& p) {\n  using fps = FPS<mint>;\n\
    \  fps quo = p.first / p.second;\n  fps rem = p.first - p.second * quo;\n  fps\
    \ b10 = m.a00 - m.a10 * quo;\n  fps b11 = m.a01 - m.a11 * quo;\n  rem.shrink();\n\
    \  b10.shrink();\n  b11.shrink();\n  swap(b10, m.a10);\n  swap(b11, m.a11);\n\
    \  swap(b10, m.a00);\n  swap(b11, m.a01);\n  p = {p.second, rem};\n}\n\ntemplate\
    \ <typename mint>\nMat<mint> InnerHalfGCD(Arr<mint> p) {\n  int n = p.first.size(),\
    \ m = p.second.size();\n  int k = (n + 1) / 2;\n  if (m <= k) return Mat<mint>::I();\n\
    \  Mat<mint> m1 = InnerHalfGCD(make_pair(p.first >> k, p.second >> k));\n  p =\
    \ m1 * p;\n  if ((int)p.second.size() <= k) return m1;\n  InnerNaiveGCD(m1, p);\n\
    \  if ((int)p.second.size() <= k) return m1;\n  int l = (int)p.first.size() -\
    \ 1;\n  int j = 2 * k - l;\n  p.first = p.first >> j;\n  p.second = p.second >>\
    \ j;\n  return InnerHalfGCD(p) * m1;\n}\n\ntemplate <typename mint>\nMat<mint>\
    \ InnerPolyGCD(const FPS<mint>& a, const FPS<mint>& b) {\n  Arr<mint> p{a, b};\n\
    \  p.first.shrink();\n  p.second.shrink();\n  int n = p.first.size(), m = p.second.size();\n\
    \  if (n < m) {\n    Mat<mint> mat = InnerPolyGCD(p.second, p.first);\n    swap(mat.a00,\
    \ mat.a01);\n    swap(mat.a10, mat.a11);\n    return mat;\n  }\n\n  Mat<mint>\
    \ res = Mat<mint>::I();\n  while (1) {\n    Mat<mint> m1 = InnerHalfGCD(p);\n\
    \    p = m1 * p;\n    if (p.second.empty()) return m1 * res;\n    InnerNaiveGCD(m1,\
    \ p);\n    if (p.second.empty()) return m1 * res;\n    res = m1 * res;\n  }\n\
    }\n\n// \u591A\u9805\u5F0F GCD, \u975E\u96F6\u306E\u5834\u5408 monic \u306A\u3082\
    \u306E\u3092\u8FD4\u3059\ntemplate <typename mint>\nFPS<mint> PolyGCD(const FPS<mint>&\
    \ a, const FPS<mint>& b) {\n  Arr<mint> p(a, b);\n  Mat<mint> m = InnerPolyGCD(a,\
    \ b);\n  p = m * p;\n  if (!p.first.empty()) {\n    mint coeff = p.first.back().inverse();\n\
    \    for (auto& x : p.first) x *= coeff;\n  }\n  return p.first;\n}\n\ntemplate\
    \ <typename mint>\npair<int, FPS<mint>> PolyInv(const FPS<mint>& f, const FPS<mint>&\
    \ g) {\n  using fps = FPS<mint>;\n  pair<fps, fps> p(f, g);\n  Mat<mint> m = InnerPolyGCD(f,\
    \ g);\n  fps gcd_ = (m * p).first;\n  if (gcd_.size() != 1) return {false, fps()};\n\
    \  pair<fps, fps> x(fps{mint(1)}, g);\n  return {true, ((m * x).first % g) * gcd_[0].inverse()};\n\
    }\n\n}  // namespace poly_gcd\nusing poly_gcd::PolyGCD;\nusing poly_gcd::PolyInv;\n\
    \n/**\n * @brief \u591A\u9805\u5F0FGCD\n * @docs docs/fps/polynomial-gcd.md\n\
    \ */\n#line 10 \"fps/root-finding.hpp\"\n\ntemplate <typename mint>\nvector<mint>\
    \ root_finding(const FormalPowerSeries<mint>& f) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  long long p = mint::get_mod();\n  vector<mint> ans;\n  if (p == 2) {\n    for\
    \ (int i = 0; i < 2; i++) {\n      if (f.eval(i) == 0) ans.push_back(i);\n   \
    \ }\n    return ans;\n  }\n  vector<fps> fs;\n  fs.push_back(PolyGCD(mod_pow(p,\
    \ fps{0, 1}, f) - fps{0, 1}, f));\n  mt19937_64 rng(58);\n  while (!fs.empty())\
    \ {\n    auto g = fs.back();\n    fs.pop_back();\n    if (g.size() == 2) ans.push_back(-g[0]);\n\
    \    if (g.size() <= 2) continue;\n    fps s = fps{(long long)(rng() % p), 1};\n\
    \    fps t = PolyGCD(mod_pow((p - 1) / 2, s, g) - fps{1}, g);\n    fs.push_back(t);\n\
    \    if (g.size() != t.size()) fs.push_back(g / t);\n  }\n  return ans;\n}\n"
  code: "#pragma once\n\n#include <random>\n#include <vector>\nusing namespace std;\n\
    \n#include \"formal-power-series.hpp\"\n#include \"mod-pow.hpp\"\n#include \"\
    polynomial-gcd.hpp\"\n\ntemplate <typename mint>\nvector<mint> root_finding(const\
    \ FormalPowerSeries<mint>& f) {\n  using fps = FormalPowerSeries<mint>;\n  long\
    \ long p = mint::get_mod();\n  vector<mint> ans;\n  if (p == 2) {\n    for (int\
    \ i = 0; i < 2; i++) {\n      if (f.eval(i) == 0) ans.push_back(i);\n    }\n \
    \   return ans;\n  }\n  vector<fps> fs;\n  fs.push_back(PolyGCD(mod_pow(p, fps{0,\
    \ 1}, f) - fps{0, 1}, f));\n  mt19937_64 rng(58);\n  while (!fs.empty()) {\n \
    \   auto g = fs.back();\n    fs.pop_back();\n    if (g.size() == 2) ans.push_back(-g[0]);\n\
    \    if (g.size() <= 2) continue;\n    fps s = fps{(long long)(rng() % p), 1};\n\
    \    fps t = PolyGCD(mod_pow((p - 1) / 2, s, g) - fps{1}, g);\n    fs.push_back(t);\n\
    \    if (g.size() != t.size()) fs.push_back(g / t);\n  }\n  return ans;\n}\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - fps/mod-pow.hpp
  - fps/polynomial-gcd.hpp
  isVerificationFile: false
  path: fps/root-finding.hpp
  requiredBy: []
  timestamp: '2024-03-04 16:48:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-polynomial-root-finding.test.cpp
documentation_of: fps/root-finding.hpp
layout: document
redirect_from:
- /library/fps/root-finding.hpp
- /library/fps/root-finding.hpp.html
title: fps/root-finding.hpp
---

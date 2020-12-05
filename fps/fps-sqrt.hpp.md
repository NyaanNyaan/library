---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':question:'
    path: modint/arbitrary-prime-modint.hpp
    title: modint/arbitrary-prime-modint.hpp
  - icon: ':question:'
    path: modulo/mod-sqrt.hpp
    title: mod sqrt(Tonelli-Shanks algorithm)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/fps-sqrt.md
    document_title: "\u5E73\u65B9\u6839"
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
    \ / (*this)[i];\n        FPS ret = (((*this * rev) >> i).log() * k).exp() * ((*this)[i].pow(k));\n\
    \        ret = (ret << (i * k)).pre(deg);\n        if ((int)ret.size() < deg)\
    \ ret.resize(deg, mint(0));\n        return ret;\n      }\n    }\n    return FPS(deg,\
    \ mint(0));\n  }\n\n  static void *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const\
    \ FPS &r);\n  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int\
    \ ntt_pr();\n  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n\
    };\ntemplate <typename mint>\nvoid *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\
    \n/**\n * @brief \u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/formal-power-series.md\n */\n#line\
    \ 2 \"modint/arbitrary-prime-modint.hpp\"\n\n\n\nstruct ArbitraryLazyMontgomeryModInt\
    \ {\n  using mint = ArbitraryLazyMontgomeryModInt;\n  using i32 = int32_t;\n \
    \ using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static u32 mod;\n  static\
    \ u32 r;\n  static u32 n2;\n\n  static u32 get_r() {\n    u32 ret = mod;\n   \
    \ for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n\
    \  static void set_mod(u32 m) {\n    assert(m < (1 << 30));\n    assert((m & 1)\
    \ == 1);\n    mod = m;\n    n2 = -u64(m) % m;\n    r = get_r();\n    assert(r\
    \ * mod == 1);\n  }\n\n  u32 a;\n\n  ArbitraryLazyMontgomeryModInt() : a(0) {}\n\
    \  ArbitraryLazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod\
    \ + mod) * n2)){};\n\n  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b)\
    \ * u32(-r)) * mod) >> 32;\n  }\n\n  mint &operator+=(const mint &b) {\n    if\
    \ (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  mint &operator*=(const mint &b) {\n    a = reduce(u64(a)\
    \ * b.a);\n    return *this;\n  }\n\n  mint &operator/=(const mint &b) {\n   \
    \ *this *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const mint\
    \ &b) const { return mint(*this) += b; }\n  mint operator-(const mint &b) const\
    \ { return mint(*this) -= b; }\n  mint operator*(const mint &b) const { return\
    \ mint(*this) *= b; }\n  mint operator/(const mint &b) const { return mint(*this)\
    \ /= b; }\n  bool operator==(const mint &b) const {\n    return (a >= mod ? a\
    \ - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  mint operator-() const { return mint() - mint(*this); }\n\
    \n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n\
    \      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b) {\n  \
    \  return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is, mint\
    \ &b) {\n    int64_t t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModInt(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n\
    \  u32 get() const {\n    u32 ret = reduce(a);\n    return ret >= mod ? ret -\
    \ mod : ret;\n  }\n\n  static u32 get_mod() { return mod; }\n};\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::mod;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::r;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::n2;\n#line 3 \"modulo/mod-sqrt.hpp\"\n\nint64_t\
    \ mod_sqrt(const int64_t &a, const int64_t &p) {\n  assert(0 <= a && a < p);\n\
    \  if (a < 2) return a;\n  using mint = ArbitraryLazyMontgomeryModInt;\n  mint::set_mod(p);\n\
    \  if (mint(a).pow((p - 1) >> 1) != 1) return -1;\n  mint b = 1, one = 1;\n  while\
    \ (b.pow((p - 1) >> 1) == 1) b += one;\n  int64_t m = p - 1, e = 0;\n  while (m\
    \ % 2 == 0) m >>= 1, e += 1;\n  mint x = mint(a).pow((m - 1) >> 1);\n  mint y\
    \ = mint(a) * x * x;\n  x *= a;\n  mint z = mint(b).pow(m);\n  while (y != 1)\
    \ {\n    int64_t j = 0;\n    mint t = y;\n    while (t != one) {\n      j += 1;\n\
    \      t *= t;\n    }\n    z = z.pow(int64_t(1) << (e - j - 1));\n    x *= z;\n\
    \    z *= z;\n    y *= z;\n    e = j;\n  }\n  return x.get();\n}\n\n/**\n * @brief\
    \ mod sqrt(Tonelli-Shanks algorithm)\n * @docs docs/modulo/mod-sqrt.md\n */\n\
    #line 4 \"fps/fps-sqrt.hpp\"\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ sqrt(const FormalPowerSeries<mint> &f, int deg = -1) {\n  if (deg == -1) deg\
    \ = (int)f.size();\n  if ((int)f.size() == 0) return FormalPowerSeries<mint>(deg,\
    \ 0);\n  if (f[0] == mint(0)) {\n    for (int i = 1; i < (int)f.size(); i++) {\n\
    \      if (f[i] != mint(0)) {\n        if (i & 1) return {};\n        if (deg\
    \ - i / 2 <= 0) break;\n        auto ret = sqrt(f >> i, deg - i / 2);\n      \
    \  if (ret.empty()) return {};\n        ret = ret << (i / 2);\n        if ((int)ret.size()\
    \ < deg) ret.resize(deg, mint(0));\n        return ret;\n      }\n    }\n    return\
    \ FormalPowerSeries<mint>(deg, 0);\n  }\n\n  int64_t sqr = mod_sqrt(f[0].get(),\
    \ mint::get_mod());\n  if (sqr == -1) return {};\n  assert(sqr * sqr % mint::get_mod()\
    \ == f[0].get());\n  FormalPowerSeries<mint> ret = {mint(sqr)};\n  mint inv2 =\
    \ mint(2).inverse();\n  for (int i = 1; i < deg; i <<= 1) {\n    ret = (ret +\
    \ f.pre(i << 1) * ret.inv(i << 1)) * inv2;\n  }\n  return ret.pre(deg);\n}\n\n\
    /**\n * @brief \u5E73\u65B9\u6839\n * @docs docs/fps/fps-sqrt.md\n */\n"
  code: "#pragma once\n#include \"../fps/formal-power-series.hpp\"\n#include \"../modulo/mod-sqrt.hpp\"\
    \n\ntemplate <typename mint>\nFormalPowerSeries<mint> sqrt(const FormalPowerSeries<mint>\
    \ &f, int deg = -1) {\n  if (deg == -1) deg = (int)f.size();\n  if ((int)f.size()\
    \ == 0) return FormalPowerSeries<mint>(deg, 0);\n  if (f[0] == mint(0)) {\n  \
    \  for (int i = 1; i < (int)f.size(); i++) {\n      if (f[i] != mint(0)) {\n \
    \       if (i & 1) return {};\n        if (deg - i / 2 <= 0) break;\n        auto\
    \ ret = sqrt(f >> i, deg - i / 2);\n        if (ret.empty()) return {};\n    \
    \    ret = ret << (i / 2);\n        if ((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n        return ret;\n      }\n    }\n    return FormalPowerSeries<mint>(deg,\
    \ 0);\n  }\n\n  int64_t sqr = mod_sqrt(f[0].get(), mint::get_mod());\n  if (sqr\
    \ == -1) return {};\n  assert(sqr * sqr % mint::get_mod() == f[0].get());\n  FormalPowerSeries<mint>\
    \ ret = {mint(sqr)};\n  mint inv2 = mint(2).inverse();\n  for (int i = 1; i <\
    \ deg; i <<= 1) {\n    ret = (ret + f.pre(i << 1) * ret.inv(i << 1)) * inv2;\n\
    \  }\n  return ret.pre(deg);\n}\n\n/**\n * @brief \u5E73\u65B9\u6839\n * @docs\
    \ docs/fps/fps-sqrt.md\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - modulo/mod-sqrt.hpp
  - modint/arbitrary-prime-modint.hpp
  isVerificationFile: false
  path: fps/fps-sqrt.hpp
  requiredBy: []
  timestamp: '2020-12-05 08:16:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
documentation_of: fps/fps-sqrt.hpp
layout: document
redirect_from:
- /library/fps/fps-sqrt.hpp
- /library/fps/fps-sqrt.hpp.html
title: "\u5E73\u65B9\u6839"
---
## fps-平方根

$N$次の形式的冪級数$f(x)$に対して$g(x) \equiv \sqrt{f(x)} \mod x^N$を満たす$g(x)$を$\mathrm{O}(N \log N)$で計算するライブラリ。ここで$\sqrt{f(x)}$は$g^2(x) \equiv f(x) \mod x^N$を満たす形式的冪級数を意味する。

#### 概要

$f$は$t^2=f_0$を満たす$t$が存在する多項式とする。このとき$g \equiv \sqrt{f} \mod x^n$となる$g$を求めたい。

まず、$g \equiv t \mod x$である。次にニュートン法で$g^2 \equiv f$を満たす$g$を求めると、$g=\hat{g} \mod x^k$ のとき 

$$g \equiv \hat{g} - \frac{\hat{g}^2-f}{(\hat{g}^2)'} \mod x^{2k}$$

$$\leftrightarrow g \equiv \frac{1}{2}\left(\hat{g}+\frac{f}{\hat{g}}\right) \mod x^{2k}$$

を得てダブリングで求まる。計算量は$\mathrm{O}(N \log N)$。

#### 使い方

- `sqrt(f, deg)`: FPSである$f$について$\sqrt f$をdeg次の項まで求める。


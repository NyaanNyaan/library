---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yuki/yuki-0963-circular.test.cpp
    title: verify/verify-yuki/yuki-0963-circular.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1080.test.cpp
    title: verify/verify-yuki/yuki-1080.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/fps/fps-circular.md
    document_title: "\u4E09\u89D2\u95A2\u6570"
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
    modint/montgomery-modint.hpp\"\n\n\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt\
    \ {\n  using mint = LazyMontgomeryModInt;\n  using i32 = int32_t;\n  using u32\
    \ = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 get_r() {\n \
    \   u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n  \
    \  return ret;\n  }\n\n  static constexpr u32 r = get_r();\n  static constexpr\
    \ u32 n2 = -u64(mod) % mod;\n  static_assert(r * mod == 1, \"invalid, r * mod\
    \ != 1\");\n  static_assert(mod < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod\
    \ & 1) == 1, \"invalid, mod % 2 == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt()\
    \ : a(0) {}\n  constexpr LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
    \ % mod + mod) * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n  \
    \  return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  constexpr mint &operator-=(const mint &b) {\n    if (i32(a -= b.a) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr\
    \ mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  constexpr mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  constexpr mint operator-(const mint &b) const { return mint(*this) -=\
    \ b; }\n  constexpr mint operator*(const mint &b) const { return mint(*this) *=\
    \ b; }\n  constexpr mint operator/(const mint &b) const { return mint(*this) /=\
    \ b; }\n  constexpr bool operator==(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 4 \"fps/fps-circular.hpp\"\n\ntemplate <typename\
    \ mint>\npair<FormalPowerSeries<mint>, FormalPowerSeries<mint>> circular(\n  \
    \  const FormalPowerSeries<mint> &fre, const FormalPowerSeries<mint> &fim,\n \
    \   int deg = -1) {\n  using fps = FormalPowerSeries<mint>;\n  assert(fre.size()\
    \ == 0 || fre[0] == mint(0));\n  assert(fim.size() == 0 || fim[0] == mint(0));\n\
    \  if (deg == -1) deg = (int)max(fre.size(), fim.size());\n  fps re({mint(1)}),\
    \ im({mint(0)});\n\n  fps::set_fft();\n  if (fps::ntt_ptr == nullptr) {\n    for\
    \ (int i = 1; i < deg; i <<= 1) {\n      fps dre = re.diff();\n      fps dim =\
    \ im.diff();\n      fps fhypot = (re * re + im * im).inv(i << 1);\n      fps ere\
    \ = dre * re + dim * im;\n      fps eim = dim * re - dre * im;\n      fps logre\
    \ = (ere * fhypot).pre((i << 1) - 1).integral();\n      fps logim = (eim * fhypot).pre((i\
    \ << 1) - 1).integral();\n      fps gre = (-logre) + mint(1) - fim.pre(i << 1);\n\
    \      fps gim = (-logim) + fre.pre(i << 1);\n      fps hre = (re * gre - im *\
    \ gim).pre(i << 1);\n      fps him = (re * gim + im * gre).pre(i << 1);\n    \
    \  swap(re, hre);\n      swap(im, him);\n    }\n  } else {\n    for (int i = 1;\
    \ i < deg; i <<= 1) {\n      fps dre = re.diff();\n      fps dim = im.diff();\n\
    \      re.resize(i << 1);\n      im.resize(i << 1);\n      dre.resize(i << 1);\n\
    \      dim.resize(i << 1);\n      re.ntt();\n      im.ntt();\n      dre.ntt();\n\
    \      dim.ntt();\n      fps fhypot(i << 1), ere(i << 1), eim(i << 1);\n     \
    \ for (int j = 0; j < 2 * i; j++) {\n        fhypot[j] = re[j] * re[j] + im[j]\
    \ * im[j];\n        ere[j] = dre[j] * re[j] + dim[j] * im[j];\n        eim[j]\
    \ = dim[j] * re[j] - dre[j] * im[j];\n      }\n      fhypot.intt();\n      fhypot\
    \ = fhypot.inv(i << 1);\n      fhypot.resize(i << 2);\n      fhypot.ntt();\n \
    \     ere.ntt_doubling();\n      eim.ntt_doubling();\n      fps logre(i << 2),\
    \ logim(i << 2);\n      for (int j = 0; j < 4 * i; j++) {\n        logre[j] =\
    \ ere[j] * fhypot[j];\n        logim[j] = eim[j] * fhypot[j];\n      }\n     \
    \ logre.intt();\n      logim.intt();\n      logre = logre.pre((i << 1) - 1).integral();\n\
    \      logim = logim.pre((i << 1) - 1).integral();\n      fps gre = (-logre) +\
    \ mint(1) - fim.pre(i << 1);\n      fps gim = (-logim) + fre.pre(i << 1);\n  \
    \    gre.resize(i << 2);\n      gim.resize(i << 2);\n      gre.ntt();\n      gim.ntt();\n\
    \      re.ntt_doubling();\n      im.ntt_doubling();\n      fps hre(i << 2), him(i\
    \ << 2);\n      for (int j = 0; j < 4 * i; j++) {\n        hre[j] = re[j] * gre[j]\
    \ - im[j] * gim[j];\n        him[j] = re[j] * gim[j] + im[j] * gre[j];\n     \
    \ }\n      hre.intt();\n      him.intt();\n      hre = hre.pre(i << 1);\n    \
    \  him = him.pre(i << 1);\n      swap(re, hre);\n      swap(im, him);\n    }\n\
    \  }\n  return make_pair(re.pre(deg), im.pre(deg));\n}\n\n/**\n * @brief \u4E09\
    \u89D2\u95A2\u6570\n * @docs docs/fps/fps-circular.md\n */\n"
  code: "#pragma once\n#include \"../fps/formal-power-series.hpp\"\n#include \"../modint/montgomery-modint.hpp\"\
    \n\ntemplate <typename mint>\npair<FormalPowerSeries<mint>, FormalPowerSeries<mint>>\
    \ circular(\n    const FormalPowerSeries<mint> &fre, const FormalPowerSeries<mint>\
    \ &fim,\n    int deg = -1) {\n  using fps = FormalPowerSeries<mint>;\n  assert(fre.size()\
    \ == 0 || fre[0] == mint(0));\n  assert(fim.size() == 0 || fim[0] == mint(0));\n\
    \  if (deg == -1) deg = (int)max(fre.size(), fim.size());\n  fps re({mint(1)}),\
    \ im({mint(0)});\n\n  fps::set_fft();\n  if (fps::ntt_ptr == nullptr) {\n    for\
    \ (int i = 1; i < deg; i <<= 1) {\n      fps dre = re.diff();\n      fps dim =\
    \ im.diff();\n      fps fhypot = (re * re + im * im).inv(i << 1);\n      fps ere\
    \ = dre * re + dim * im;\n      fps eim = dim * re - dre * im;\n      fps logre\
    \ = (ere * fhypot).pre((i << 1) - 1).integral();\n      fps logim = (eim * fhypot).pre((i\
    \ << 1) - 1).integral();\n      fps gre = (-logre) + mint(1) - fim.pre(i << 1);\n\
    \      fps gim = (-logim) + fre.pre(i << 1);\n      fps hre = (re * gre - im *\
    \ gim).pre(i << 1);\n      fps him = (re * gim + im * gre).pre(i << 1);\n    \
    \  swap(re, hre);\n      swap(im, him);\n    }\n  } else {\n    for (int i = 1;\
    \ i < deg; i <<= 1) {\n      fps dre = re.diff();\n      fps dim = im.diff();\n\
    \      re.resize(i << 1);\n      im.resize(i << 1);\n      dre.resize(i << 1);\n\
    \      dim.resize(i << 1);\n      re.ntt();\n      im.ntt();\n      dre.ntt();\n\
    \      dim.ntt();\n      fps fhypot(i << 1), ere(i << 1), eim(i << 1);\n     \
    \ for (int j = 0; j < 2 * i; j++) {\n        fhypot[j] = re[j] * re[j] + im[j]\
    \ * im[j];\n        ere[j] = dre[j] * re[j] + dim[j] * im[j];\n        eim[j]\
    \ = dim[j] * re[j] - dre[j] * im[j];\n      }\n      fhypot.intt();\n      fhypot\
    \ = fhypot.inv(i << 1);\n      fhypot.resize(i << 2);\n      fhypot.ntt();\n \
    \     ere.ntt_doubling();\n      eim.ntt_doubling();\n      fps logre(i << 2),\
    \ logim(i << 2);\n      for (int j = 0; j < 4 * i; j++) {\n        logre[j] =\
    \ ere[j] * fhypot[j];\n        logim[j] = eim[j] * fhypot[j];\n      }\n     \
    \ logre.intt();\n      logim.intt();\n      logre = logre.pre((i << 1) - 1).integral();\n\
    \      logim = logim.pre((i << 1) - 1).integral();\n      fps gre = (-logre) +\
    \ mint(1) - fim.pre(i << 1);\n      fps gim = (-logim) + fre.pre(i << 1);\n  \
    \    gre.resize(i << 2);\n      gim.resize(i << 2);\n      gre.ntt();\n      gim.ntt();\n\
    \      re.ntt_doubling();\n      im.ntt_doubling();\n      fps hre(i << 2), him(i\
    \ << 2);\n      for (int j = 0; j < 4 * i; j++) {\n        hre[j] = re[j] * gre[j]\
    \ - im[j] * gim[j];\n        him[j] = re[j] * gim[j] + im[j] * gre[j];\n     \
    \ }\n      hre.intt();\n      him.intt();\n      hre = hre.pre(i << 1);\n    \
    \  him = him.pre(i << 1);\n      swap(re, hre);\n      swap(im, him);\n    }\n\
    \  }\n  return make_pair(re.pre(deg), im.pre(deg));\n}\n\n/**\n * @brief \u4E09\
    \u89D2\u95A2\u6570\n * @docs docs/fps/fps-circular.md\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  - modint/montgomery-modint.hpp
  isVerificationFile: false
  path: fps/fps-circular.hpp
  requiredBy: []
  timestamp: '2022-08-22 22:01:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yuki/yuki-0963-circular.test.cpp
  - verify/verify-yuki/yuki-1080.test.cpp
documentation_of: fps/fps-circular.hpp
layout: document
redirect_from:
- /library/fps/fps-circular.hpp
- /library/fps/fps-circular.hpp.html
title: "\u4E09\u89D2\u95A2\u6570"
---
## fps-三角関数

$N$次の形式的冪級数$f(x)$に対して$g(x) \equiv \cos(f(x)) , h(x) \equiv \sin(f(x)) \mod x^N$を満たす$g(x)$を$\mathrm{O}(N \log N)$で計算するライブラリ。

#### 概要

$g \equiv \cos f, h \equiv \sin f \mod x^n$を求めたい。

これはオイラーの公式$e^{if}=\cos f+i\sin f$を利用すると$\mathrm{exp}$と同様の方法で求まる。

なお、計算は実部と虚部に分けて行う必要がある。例えば掛け算の時は4回乗算して適切に足し合わせる。

#### 使い方

- `circular(fre, fim, deg)` : $Re[f]=fre,Im[f]=fim$であるFPS $f$について$\cos f,\sin f$をdeg次の項まで求める。

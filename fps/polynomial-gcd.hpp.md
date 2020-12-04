---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
    title: verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/fps/polynomial-gcd.md
    document_title: "\u591A\u9805\u5F0FGCD"
    links: []
  bundledCode: "#line 2 \"fps/polynomial-gcd.hpp\"\n\n\n\n#line 2 \"fps/formal-power-series.hpp\"\
    \n\n\n\ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n\
    \  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\n  FPS &operator+=(const\
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
    \ 6 \"fps/polynomial-gcd.hpp\"\n\nnamespace poly_gcd {\n\ntemplate <typename mint>\n\
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
    }\n\ntemplate <typename mint>\nFPS<mint> PolyGCD(const FPS<mint>& a, const FPS<mint>&\
    \ b) {\n  Arr<mint> p(a, b);\n  Mat<mint> m = InnerPolyGCD(a, b);\n  p = m * p;\n\
    \  if (!p.first.empty()) {\n    mint coeff = p.first.back().inverse();\n    for\
    \ (auto& x : p.first) x *= coeff;\n  }\n  return p.first;\n}\n\ntemplate <typename\
    \ mint>\npair<int, FPS<mint>> PolyInv(const FPS<mint>& f, const FPS<mint>& g)\
    \ {\n  using fps = FPS<mint>;\n  pair<fps, fps> p(f, g);\n  Mat<mint> m = InnerPolyGCD(f,\
    \ g);\n  fps gcd_ = (m * p).first;\n  if (gcd_.size() != 1) return {false, fps()};\n\
    \  pair<fps, fps> x(fps{mint(1)}, g);\n  return {true, ((m * x).first % g) * gcd_[0].inverse()};\n\
    }\n\n}  // namespace poly_gcd\nusing poly_gcd::PolyGCD;\nusing poly_gcd::PolyInv;\n\
    \n/**\n * @brief \u591A\u9805\u5F0FGCD\n * @docs docs/fps/polynomial-gcd.md\n\
    \ */\n"
  code: "#pragma once\n\n\n\n#include \"./formal-power-series.hpp\"\n\nnamespace poly_gcd\
    \ {\n\ntemplate <typename mint>\nusing FPS = FormalPowerSeries<mint>;\ntemplate\
    \ <typename mint>\nusing Arr = pair<FPS<mint>, FPS<mint>>;\n\ntemplate <typename\
    \ mint>\nstruct Mat {\n  using fps = FPS<mint>;\n  fps a00, a01, a10, a11;\n\n\
    \  Mat() = default;\n  Mat(const fps& a00_, const fps& a01_, const fps& a10_,\
    \ const fps& a11_)\n      : a00(a00_), a01(a01_), a10(a10_), a11(a11_) {}\n\n\
    \  Mat& operator*=(const Mat& r) {\n    fps A00 = a00 * r.a00 + a01 * r.a10;\n\
    \    fps A01 = a00 * r.a01 + a01 * r.a11;\n    fps A10 = a10 * r.a00 + a11 * r.a10;\n\
    \    fps A11 = a10 * r.a01 + a11 * r.a11;\n    A00.shrink();\n    A01.shrink();\n\
    \    A10.shrink();\n    A11.shrink();\n    swap(A00, a00);\n    swap(A01, a01);\n\
    \    swap(A10, a10);\n    swap(A11, a11);\n    return *this;\n  }\n\n  static\
    \ Mat I() { return Mat(fps{mint(1)}, fps(), fps(), fps{mint(1)}); }\n\n  Mat operator*(const\
    \ Mat& r) const { return Mat(*this) *= r; }\n};\n\ntemplate <typename mint>\n\
    Arr<mint> operator*(const Mat<mint>& m, const Arr<mint>& a) {\n  using fps = FPS<mint>;\n\
    \  fps b0 = m.a00 * a.first + m.a01 * a.second;\n  fps b1 = m.a10 * a.first +\
    \ m.a11 * a.second;\n  b0.shrink();\n  b1.shrink();\n  return {b0, b1};\n};\n\n\
    template <typename mint>\nvoid InnerNaiveGCD(Mat<mint>& m, Arr<mint>& p) {\n \
    \ using fps = FPS<mint>;\n  fps quo = p.first / p.second;\n  fps rem = p.first\
    \ - p.second * quo;\n  fps b10 = m.a00 - m.a10 * quo;\n  fps b11 = m.a01 - m.a11\
    \ * quo;\n  rem.shrink();\n  b10.shrink();\n  b11.shrink();\n  swap(b10, m.a10);\n\
    \  swap(b11, m.a11);\n  swap(b10, m.a00);\n  swap(b11, m.a01);\n  p = {p.second,\
    \ rem};\n}\n\ntemplate <typename mint>\nMat<mint> InnerHalfGCD(Arr<mint> p) {\n\
    \  int n = p.first.size(), m = p.second.size();\n  int k = (n + 1) / 2;\n  if\
    \ (m <= k) return Mat<mint>::I();\n  Mat<mint> m1 = InnerHalfGCD(make_pair(p.first\
    \ >> k, p.second >> k));\n  p = m1 * p;\n  if ((int)p.second.size() <= k) return\
    \ m1;\n  InnerNaiveGCD(m1, p);\n  if ((int)p.second.size() <= k) return m1;\n\
    \  int l = (int)p.first.size() - 1;\n  int j = 2 * k - l;\n  p.first = p.first\
    \ >> j;\n  p.second = p.second >> j;\n  return InnerHalfGCD(p) * m1;\n}\n\ntemplate\
    \ <typename mint>\nMat<mint> InnerPolyGCD(const FPS<mint>& a, const FPS<mint>&\
    \ b) {\n  Arr<mint> p{a, b};\n  p.first.shrink();\n  p.second.shrink();\n  int\
    \ n = p.first.size(), m = p.second.size();\n  if (n < m) {\n    Mat<mint> mat\
    \ = InnerPolyGCD(p.second, p.first);\n    swap(mat.a00, mat.a01);\n    swap(mat.a10,\
    \ mat.a11);\n    return mat;\n  }\n\n  Mat<mint> res = Mat<mint>::I();\n  while\
    \ (1) {\n    Mat<mint> m1 = InnerHalfGCD(p);\n    p = m1 * p;\n    if (p.second.empty())\
    \ return m1 * res;\n    InnerNaiveGCD(m1, p);\n    if (p.second.empty()) return\
    \ m1 * res;\n    res = m1 * res;\n  }\n}\n\ntemplate <typename mint>\nFPS<mint>\
    \ PolyGCD(const FPS<mint>& a, const FPS<mint>& b) {\n  Arr<mint> p(a, b);\n  Mat<mint>\
    \ m = InnerPolyGCD(a, b);\n  p = m * p;\n  if (!p.first.empty()) {\n    mint coeff\
    \ = p.first.back().inverse();\n    for (auto& x : p.first) x *= coeff;\n  }\n\
    \  return p.first;\n}\n\ntemplate <typename mint>\npair<int, FPS<mint>> PolyInv(const\
    \ FPS<mint>& f, const FPS<mint>& g) {\n  using fps = FPS<mint>;\n  pair<fps, fps>\
    \ p(f, g);\n  Mat<mint> m = InnerPolyGCD(f, g);\n  fps gcd_ = (m * p).first;\n\
    \  if (gcd_.size() != 1) return {false, fps()};\n  pair<fps, fps> x(fps{mint(1)},\
    \ g);\n  return {true, ((m * x).first % g) * gcd_[0].inverse()};\n}\n\n}  // namespace\
    \ poly_gcd\nusing poly_gcd::PolyGCD;\nusing poly_gcd::PolyInv;\n\n/**\n * @brief\
    \ \u591A\u9805\u5F0FGCD\n * @docs docs/fps/polynomial-gcd.md\n */\n"
  dependsOn:
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/polynomial-gcd.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
documentation_of: fps/polynomial-gcd.hpp
layout: document
redirect_from:
- /library/fps/polynomial-gcd.hpp
- /library/fps/polynomial-gcd.hpp.html
title: "\u591A\u9805\u5F0FGCD"
---
## 多項式GCD

多項式GCDを$\mathrm{O}(N \log ^ 2 N)$($N$は多項式の次数)で求めるライブラリ。

#### 概要

[参考資料その１](http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf)　[参考資料その２](https://scrapbox.io/37zigen-43465887/half-GCD)

多項式$a(x),b(x)$がある。$h\mid a,h\mid b$が成り立つ任意の多項式$h$に対して$g\mid h$となるような$g$を多項式のGCDとして$\gcd(a,b)$と置く。

$\gcd(a,b)$は通常のgcdと同様にユークリッドの互除法で求まるが、一回の除算につき次数は最低1しか減らないため、愚直に計算すると計算量が$\mathrm{O}(N^2 \log N)$程度になってしまう。そこで高速化のためにHalf-GCD法と呼ばれるアルゴリズムを使用する。

通常のユークリッドの互除法における一回の操作を行列で表すと下のようになる。

$$\left(
    \begin{array}{cc}
      0 & 1  \\
     1 & \mathrm{quo}(a,b) 
    \end{array}
  \right)
  \left(
      \begin{array}{c}
          a \\ 
          b
      \end{array}
  \right)=
  \left(
      \begin{array}{c}
          a - \mathrm{quo}(a,b) \\ 
          b
      \end{array}
  \right)$$
 
 同様に、ユークリッドの互除法全体は次のように表される。

$$
  M_i M_{i-1}\cdots M_2M_1\left(
      \begin{array}{c}
          a \\ 
          b
      \end{array}
  \right)=
  \left(
      \begin{array}{c}
          \gcd(a,b) \\ 
          0
      \end{array}
  \right)$$
  
よって、行列$M_1,M_2,M_3,\ldots,M_i$を求められれば$\gcd(a,b)$が求められることになる。

Half-GCD法とは次に示す性質を生かして、より少ない計算量で行列の列$M$のおよそ前半分を求めるアルゴリズムである。
  
- $a = a_0 + a_1x^k, b=b_0+b_1x^k$とおく。($k < \deg(a))$この時、$(a1,b1)$にユークリッドの互除法を適用したときに得られる行列$L_1,L_2,\dots$は$M_1,M_2\ldots$の先頭部分と一致する。

証明は参考文献を参照のこと。(~~ちゃんと理解していない...直感的な理解としては、多項式の除算のプロセスを考えると商が上位の次に依存しそう。~~)

自分の実装では$\mathrm{HGCD}(N)$を1回実行するのに$\mathrm{HGCD}(\frac{N}{2})$を2回+$N$次の除算1回を呼んでいる。計算量は$\mathrm{T}(N) = 2\mathrm{T}(\frac{N}{2}) + N\log N$を解いて$\mathrm{O}(N \log ^2 N)$となる。

#### inv of polynomials

[inv of polynomials(Library Checker)](https://judge.yosupo.jp/problem/inv_of_polynomials)は多項式GCDのverify用問題である。問題概要は次の通りである。

- 多項式$f(x),g(x)$に対して$f(x)h(x) \equiv 1 \mod g(x)$を満たす$h(x)$を求めよ。(ただし$\deg (h(x)) < \deg g(x)$)

この問題はいわゆる拡張ユークリッド法と同様のアルゴリズムで解くことが出来る。まず、$\gcd(f,g) \neq 1$のとき$fh \equiv 0 \not \equiv 1 \mod \gcd(f,g)$より$h$は解なしとなる。次に$\gcd(f,g) = 1$の時、題意を満たす$h$と$f,g$の関係式は、適当な多項式$s$を用いて次のように表される。

$$(f, g)^T h = (sg+1,gh)^T$$

$f,g$を多項式GCDの関数に代入したときに得られる行列$M$を両辺に掛けると

$$M(f,g)^Th=(1,0)=M(sg+1,gh)^T$$

となり、辺々$\mod g(x)$を取って

$$(1,0)^T h \equiv M(1,0)^T \mod g(x)$$

を得るので、$h \equiv M_{11} \mod g(x)$が従う。

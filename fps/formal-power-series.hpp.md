---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/arbitrary-fps.hpp
    title: fps/arbitrary-fps.hpp
  - icon: ':heavy_check_mark:'
    path: fps/differential-equation.hpp
    title: "\u5E38\u5FAE\u5206\u65B9\u7A0B\u5F0F"
  - icon: ':heavy_check_mark:'
    path: fps/fast-multieval.hpp
    title: "Multipoint Evaluation(\u9AD8\u901F\u5316\u7248)"
  - icon: ':warning:'
    path: fps/fft2d.hpp
    title: fps/fft2d.hpp
  - icon: ':heavy_check_mark:'
    path: fps/find-p-recursive.hpp
    title: "P-recursive\u306E\u9AD8\u901F\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: fps/fps-circular.hpp
    title: "\u4E09\u89D2\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: fps/fps-composition-fast.hpp
    title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N^2)$ )"
  - icon: ':heavy_check_mark:'
    path: fps/fps-composition.hpp
    title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}\\left((N \\log N)^{\\frac{3}{2}}\\\
      right)$ )"
  - icon: ':heavy_check_mark:'
    path: fps/fps-famous-series.hpp
    title: "\u6709\u540D\u306A\u6570\u5217"
  - icon: ':heavy_check_mark:'
    path: fps/fps-sqrt.hpp
    title: "\u5E73\u65B9\u6839"
  - icon: ':warning:'
    path: fps/inversion-formula.hpp
    title: fps/inversion-formula.hpp
  - icon: ':heavy_check_mark:'
    path: fps/kitamasa.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: fps/mod-pow.hpp
    title: Mod-Pow ($f(x)^k \mod g(x)$)
  - icon: ':heavy_check_mark:'
    path: fps/multipoint-evaluation.hpp
    title: Multipoint Evaluation
  - icon: ':heavy_check_mark:'
    path: fps/nth-term.hpp
    title: "\u7DDA\u5F62\u56DE\u5E30\u6570\u5217\u306E\u9AD8\u901F\u8A08\u7B97(Berlekamp-Massey/Bostan-Mori)"
  - icon: ':heavy_check_mark:'
    path: fps/ntt-friendly-fps.hpp
    title: "NTT mod\u7528FPS\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/polynomial-gcd.hpp
    title: "\u591A\u9805\u5F0FGCD"
  - icon: ':heavy_check_mark:'
    path: fps/polynomial-interpolation.hpp
    title: fps/polynomial-interpolation.hpp
  - icon: ':heavy_check_mark:'
    path: fps/sample-point-shift.hpp
    title: fps/sample-point-shift.hpp
  - icon: ':heavy_check_mark:'
    path: fps/taylor-shift.hpp
    title: "\u5E73\u884C\u79FB\u52D5"
  - icon: ':heavy_check_mark:'
    path: fps/utility.hpp
    title: fps/utility.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/black-box-linear-algebra.hpp
    title: Black Box Linear Algebra
  - icon: ':heavy_check_mark:'
    path: matrix/matrix-tree.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406(\u30E9\u30D7\u30E9\u30B7\u30A2\u30F3\u884C\
      \u5217)"
  - icon: ':heavy_check_mark:'
    path: matrix/polynomial-matrix-determinant.hpp
    title: "\u591A\u9805\u5F0F\u884C\u5217\u306E\u884C\u5217\u5F0F"
  - icon: ':heavy_check_mark:'
    path: matrix/polynomial-matrix-prefix-prod.hpp
    title: "\u591A\u9805\u5F0F\u884C\u5217\u306Eprefix product"
  - icon: ':heavy_check_mark:'
    path: modulo/factorial.hpp
    title: "\u968E\u4E57 $\\mod p$"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/multieval.test.cpp
    title: verify/verify-unit-test/multieval.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
    title: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/p-recursive.test.cpp
    title: verify/verify-unit-test/p-recursive.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/polynomial-matrix-prod.test.cpp
    title: verify/verify-unit-test/polynomial-matrix-prod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
    title: verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-composition.test.cpp
    title: verify/verify-yosupo-fps/yosupo-composition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-exp-arb.test.cpp
    title: verify/verify-yosupo-fps/yosupo-exp-arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-exp.test.cpp
    title: verify/verify-yosupo-fps/yosupo-exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
    title: verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-inv-arb.test.cpp
    title: verify/verify-yosupo-fps/yosupo-inv-arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
    title: verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-inv.test.cpp
    title: verify/verify-yosupo-fps/yosupo-inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-log-arb.test.cpp
    title: verify/verify-yosupo-fps/yosupo-log-arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-log.test.cpp
    title: verify/verify-yosupo-fps/yosupo-log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
    title: verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-multieval.test.cpp
    title: verify/verify-yosupo-fps/yosupo-multieval.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-pow-arb.test.cpp
    title: verify/verify-yosupo-fps/yosupo-pow-arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-pow.test.cpp
    title: verify/verify-yosupo-fps/yosupo-pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
    title: verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
    title: verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-multiplicative-convolution.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-multiplicative-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0214.test.cpp
    title: verify/verify-yuki/yuki-0214.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0215-nth-term.test.cpp
    title: verify/verify-yuki/yuki-0215-nth-term.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0215.test.cpp
    title: verify/verify-yuki/yuki-0215.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0502.test.cpp
    title: verify/verify-yuki/yuki-0502.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0720.test.cpp
    title: verify/verify-yuki/yuki-0720.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0963-circular.test.cpp
    title: verify/verify-yuki/yuki-0963-circular.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0963.test.cpp
    title: verify/verify-yuki/yuki-0963.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1080.test.cpp
    title: verify/verify-yuki/yuki-1080.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1112-sparse.test.cpp
    title: verify/verify-yuki/yuki-1112-sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1112.test.cpp
    title: verify/verify-yuki/yuki-1112.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1145.test.cpp
    title: verify/verify-yuki/yuki-1145.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1303.test.cpp
    title: verify/verify-yuki/yuki-1303.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/formal-power-series.md
    document_title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\
      \u30A4\u30D6\u30E9\u30EA"
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
    \ @docs docs/fps/formal-power-series.md\n */\n"
  code: "#pragma once\n\ntemplate <typename mint>\nstruct FormalPowerSeries : vector<mint>\
    \ {\n  using vector<mint>::vector;\n  using FPS = FormalPowerSeries;\n\n  FPS\
    \ &operator+=(const FPS &r) {\n    if (r.size() > this->size()) this->resize(r.size());\n\
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
    \ / (*this)[i];\n        FPS ret =\n            (((*this * rev) >> i).log(deg)\
    \ * k).exp(deg) * ((*this)[i].pow(k));\n        ret = (ret << (i * k)).pre(deg);\n\
    \        if ((int)ret.size() < deg) ret.resize(deg, mint(0));\n        return\
    \ ret;\n      }\n    }\n    return FPS(deg, mint(0));\n  }\n\n  static void *ntt_ptr;\n\
    \  static void set_fft();\n  FPS &operator*=(const FPS &r);\n  void ntt();\n \
    \ void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n  FPS inv(int\
    \ deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate <typename mint>\n\
    void *FormalPowerSeries<mint>::ntt_ptr = nullptr;\n\n/**\n * @brief \u591A\u9805\
    \u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n *\
    \ @docs docs/fps/formal-power-series.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/formal-power-series.hpp
  requiredBy:
  - fps/ntt-friendly-fps.hpp
  - fps/fps-sqrt.hpp
  - fps/differential-equation.hpp
  - fps/taylor-shift.hpp
  - fps/kitamasa.hpp
  - fps/fast-multieval.hpp
  - fps/fps-famous-series.hpp
  - fps/fps-composition-fast.hpp
  - fps/polynomial-interpolation.hpp
  - fps/polynomial-gcd.hpp
  - fps/mod-pow.hpp
  - fps/fft2d.hpp
  - fps/utility.hpp
  - fps/nth-term.hpp
  - fps/fps-circular.hpp
  - fps/fps-composition.hpp
  - fps/multipoint-evaluation.hpp
  - fps/sample-point-shift.hpp
  - fps/arbitrary-fps.hpp
  - fps/inversion-formula.hpp
  - fps/find-p-recursive.hpp
  - modulo/factorial.hpp
  - matrix/black-box-linear-algebra.hpp
  - matrix/polynomial-matrix-prefix-prod.hpp
  - matrix/matrix-tree.hpp
  - matrix/polynomial-matrix-determinant.hpp
  timestamp: '2021-01-31 00:21:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0502.test.cpp
  - verify/verify-yuki/yuki-1112-sparse.test.cpp
  - verify/verify-yuki/yuki-1145.test.cpp
  - verify/verify-yuki/yuki-1303.test.cpp
  - verify/verify-yuki/yuki-0214.test.cpp
  - verify/verify-yuki/yuki-1080.test.cpp
  - verify/verify-yuki/yuki-0963-circular.test.cpp
  - verify/verify-yuki/yuki-0720.test.cpp
  - verify/verify-yuki/yuki-0963.test.cpp
  - verify/verify-yuki/yuki-0215.test.cpp
  - verify/verify-yuki/yuki-0215-nth-term.test.cpp
  - verify/verify-yuki/yuki-1112.test.cpp
  - verify/verify-unit-test/polynomial-matrix-prod.test.cpp
  - verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - verify/verify-unit-test/p-recursive.test.cpp
  - verify/verify-unit-test/multieval.test.cpp
  - verify/verify-yosupo-ntt/yosupo-multiplicative-convolution.test.cpp
  - verify/verify-yosupo-fps/yosupo-log.test.cpp
  - verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
  - verify/verify-yosupo-fps/yosupo-pow-arb.test.cpp
  - verify/verify-yosupo-fps/yosupo-exp.test.cpp
  - verify/verify-yosupo-fps/yosupo-composition.test.cpp
  - verify/verify-yosupo-fps/yosupo-inv.test.cpp
  - verify/verify-yosupo-fps/yosupo-exp-arb.test.cpp
  - verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
  - verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
  - verify/verify-yosupo-fps/yosupo-multieval.test.cpp
  - verify/verify-yosupo-fps/yosupo-interpolation.test.cpp
  - verify/verify-yosupo-fps/yosupo-taylor-shift.test.cpp
  - verify/verify-yosupo-fps/yosupo-inv-of-polynomials.test.cpp
  - verify/verify-yosupo-fps/yosupo-log-arb.test.cpp
  - verify/verify-yosupo-fps/yosupo-inv-arb.test.cpp
  - verify/verify-yosupo-fps/yosupo-stirling-1st.test.cpp
  - verify/verify-yosupo-fps/yosupo-pow.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
documentation_of: fps/formal-power-series.hpp
layout: document
redirect_from:
- /library/fps/formal-power-series.hpp
- /library/fps/formal-power-series.hpp.html
title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\
  \u30EA"
---
# 形式的冪級数
多項式/形式的冪級数の基本操作を行うライブラリ。

次の3つのファイルから成り、modが$998244353$の時は1番目と2番目を、$1e9+7$の時は1番目と3番目をincludeして使用する。

- `formal-power-series.hpp` $\cdots$ 共通部分のみ実装したもの。
- `ntt-friendly-fps.hpp` $\cdots$ NTT素数mod用の高速な実装を行ったもの。
- `arbitrary-fps.hpp` $\cdots$ 任意mod畳み込み用の実装を行ったもの。

実装の一部は[うしさんのライブラリ](https://ei1333.github.io/library/library/math/fps/formal-power-series.cpp.html)を大きく参考にしました。感謝…

### 加算・減算

$\mathrm{O}(N)$

### 乗算

$h(x)=f(x)g(x)$となる$h(x)$を求める。これはFFT/NTT(FMT)で求められる。$\mathrm{O}(N \log N)$

### 除算

(注：この項に書かれている除算は多項式としての除算である。)

$f(x) = g(x)q(x) + r(x)$となる多項式$q,r$を求めたい。($f$は$n-1$次、$g$は$m-1$次($n>m$),$q$は$n-m$次とする。)ここで、

$$f^R := f(\frac{1}{x})\cdot x^{n-1}$$

のようにおくと$f^R$は多項式になる。最初の式を$x \leftarrow \frac{1}{x}$に置き換えると、

$$f(\frac{1}{x})  = g(\frac{1}{x})q(\frac{1}{x})+r(\frac{1}{x})$$

両辺に$x^{n-1}$を掛けると

$$f(\frac{1}{x}) x^{n-1} = g(\frac{1}{x})x^{m-1}\cdot q(\frac{1}{x})x^{n-m}+r(\frac{1}{x})x^{m-2} \cdot x^{n-m+1}$$

$$\leftrightarrow f^R = g^R q^R + r^R x^{n-m+1}$$

$$\rightarrow f^R \equiv g^R q^R \mod x^{n-m+1}$$

を得る。$q^R$は$n-m$次なので$\mod x^{n-m+1}$を利用して

$$\frac{f^R}{g^R} \equiv q^R \mod x^{n-m+1}$$

となるので、ここから$q$と$r$を計算できる。(逆元の出し方は後述)

### 微分・積分

$\mathrm{O}(N)$

### ダブリング

$f \mod x^n$を求めたい時に、$f \equiv f_0 \mod x$から始めて精度を倍々にして求める手法のことをダブリングと呼ぶ。

具体的には、$\hat{f} \equiv f \mod x^k$から$f \mod x^{2k}$を

$$(f - \hat{f})^2 \equiv 0 \mod x^{2k}$$

を利用して計算する。これを利用して逆元を求める。

### 逆元

$fg\equiv 1 \mod x^n$となる$f$の逆元$g$をダブリングで求めたい。

まず$g \equiv f_0^{-1} \mod x$である。次に、$g \equiv \hat{g} \mod x^k$が分かっているとき$g \mod x^{2k}$を出す。

$$(g-\hat{g})^2\equiv g^2-2g\hat{g}+\hat{g}^2\equiv0 \mod x^{2k}$$

両辺に$f$を掛けると

$$fg^2-2fg\hat{g}+f\hat{g}^2\equiv0 \mod x^{2k}$$

$fg \equiv 1 \mod x^{2k}$を利用して$fg$を消すと

$$g\equiv2\hat{g}-f\hat{g}^2 \mod x^{2k}$$

を得る。計算量は$T(n)=T(n/2)+\mathrm{O}(N \log N)$を解いて$T(n)=\mathrm{O}(N \log N)$となる。

なお、modがNTT素数の場合は実装を工夫することで定数倍が2倍以上軽くなる。

### log

$f_0 = 1$を満たす$f$に対して、$e^f \equiv g \mod x^n$を満たす$g$を$g\equiv\log f \mod x^n$として定義する。この時、$g$は

$$\log f \equiv \int \frac{f'}{f} dx \mod x^n$$

から求まる。(なお、上の式は一見すると不定積分の定数項のズレが心配に見えるが、$g_0 = 0$とおくと$x=0$を代入したとき両辺が等しくなるので問題ない。)

### ニュートン法

数値解析におけるニュートン法とは、$f(x)=0$を満たす$x$の値を、漸化式

$$x_{n+1} = x_{n}-\frac{f(x_n)}{f'(x_n)}$$

を利用した反復計算により真の値を得るアルゴリズムであった。このアルゴリズムを形式的冪級数にも応用する。

$G(g) \equiv f \mod x^n$を満たす形式的冪級数$g$を求めたい。$G(\hat{g}) \equiv f \mod x^n$を満たす$\hat{g}$が求まっている時、$\hat{g}$と$g \mod x^{2n}$の間に成り立つ関係式を考える。

$G(g)$の$g = \hat{g}$におけるテイラー展開の式は

$$G(g) = G(\hat{g}) + G'(\hat{g})(g-\hat{g})+\mathrm{O}((g-\hat{g})^2)$$

となるが、$g - \hat{g} \equiv 0 \mod x$なので形式的冪級数を考えてもよい。辺々$\mod x^{2n}$を取ると、$(g-\hat{g})^2 \equiv 0 \mod x ^{2n}$より

$$G(g) \equiv f \equiv G(\hat{g}) + G'(\hat{g})(g-\hat{g}) \mod x^{2n}$$

であり、これをさらに変形して

$$g \equiv \hat{g} - \frac{G(\hat{g})-f}{G'(\hat{g})} \mod x^{2n}$$

を得る。この式を使って$\mathrm{exp}$や$\mathrm{sqrt}$を計算することが出来る。

### exp

$g \equiv e^f \mod x^n$となる$g$を求める。

$$\log g \equiv f \mod x^n$$

等式が成り立つには$f_0=0$が必要でこの時$g_0=1$。次にニュートン法を使うと、

$$g \equiv \hat{g} - \frac{\log\hat{g}-f}{\log'\hat{g}} \mod x^{2n}$$

$\log' \hat{g}\equiv\frac{1}{\hat{g}}$より

$$g\equiv \hat{g}(1-\log \hat{g}+f) \mod x^{2n}$$

となりダブリングで求まる。$\mathrm{O}(N \log N)$ 

### 累乗

$g \equiv f^k \mod x^n$となる$g$を求めたい。繰り返し自乗法を用いると$\mathrm{O}(N \log k \log N)$で求まるがexpを使うともっと早くなる。

$f$の一番次数の低い項が$a_p x^p \ (p \neq 0)$のときは$\left(\frac{f}{a_p x^p}\right)^k$を計算して最後に$a_p^kx^{kp}$を掛ければよいため、$f$の定数項が$1$である場合のみ考えればよい。このとき$f^k$は$f^k\equiv e^{(\log f)k}$から計算できる。

### 平方根

[fps/fps-sqrt.hpp](https://nyaannyaan.github.io/library/library/fps/fps-sqrt.hpp.html)にて解説。

### 三角関数

[fps/fps-circular.hpp](https://nyaannyaan.github.io/library/library/fps/fps-circular.hpp.html)にて解説。

### 平行移動

[fps/taylor-shift.hpp](https://nyaannyaan.github.io/library/library/fps/taylor-shift.hpp.html)にて解説。

### 階差(imos法)/累積和

(関数は未実装)
数列に対して階差を取る(imos法)、あるいはその逆に累積和を取ることを形式的冪級数の数式的な操作に置き換えると、それぞれ$1-x$を掛ける/割る操作に対応している。計算量はともに$\mathrm{O}(N)$である。

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-composition.test.cpp
    title: verify/verify-yosupo-fps/yosupo-composition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/fps/fps-composition.md
    document_title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}\\left((N \\log N)^{\\\
      frac{3}{2}}\\right)$ )"
    links: []
  bundledCode: "#line 2 \"fps/fps-composition.hpp\"\n\n#line 2 \"modulo/binomial.hpp\"\
    \n\ntemplate <typename T>\nstruct Binomial {\n  vector<T> f, g, h;\n  Binomial(int\
    \ MAX = 0) : f(1, T(1)), g(1, T(1)), h(1, T(1)) {\n    while (MAX >= (int)f.size())\
    \ extend();\n  }\n\n  void extend() {\n    int n = f.size();\n    int m = n *\
    \ 2;\n    f.resize(m);\n    g.resize(m);\n    h.resize(m);\n    for (int i = n;\
    \ i < m; i++) f[i] = f[i - 1] * T(i);\n    g[m - 1] = f[m - 1].inverse();\n  \
    \  h[m - 1] = g[m - 1] * f[m - 2];\n    for (int i = m - 2; i >= n; i--) {\n \
    \     g[i] = g[i + 1] * T(i + 1);\n      h[i] = g[i] * f[i - 1];\n    }\n  }\n\
    \n  T fac(int i) {\n    if (i < 0) return T(0);\n    while (i >= (int)f.size())\
    \ extend();\n    return f[i];\n  }\n\n  T finv(int i) {\n    if (i < 0) return\
    \ T(0);\n    while (i >= (int)g.size()) extend();\n    return g[i];\n  }\n\n \
    \ T inv(int i) {\n    if (i < 0) return -inv(-i);\n    while (i >= (int)h.size())\
    \ extend();\n    return h[i];\n  }\n\n  T C(int n, int r) {\n    if (n < 0 ||\
    \ n < r || r < 0) return T(0);\n    return fac(n) * finv(n - r) * finv(r);\n \
    \ }\n\n  inline T operator()(int n, int r) { return C(n, r); }\n\n  T C_naive(int\
    \ n, int r) {\n    if (n < 0 || n < r || r < 0) return T(0);\n    T ret = T(1);\n\
    \    r = min(r, n - r);\n    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);\n\
    \    return ret;\n  }\n\n  T P(int n, int r) {\n    if (n < 0 || n < r || r <\
    \ 0) return T(0);\n    return fac(n) * finv(n - r);\n  }\n\n  T H(int n, int r)\
    \ {\n    if (n < 0 || r < 0) return T(0);\n    return r == 0 ? 1 : C(n + r - 1,\
    \ r);\n  }\n};\n#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate <typename\
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
    \ @docs docs/fps/formal-power-series.md\n */\n#line 5 \"fps/fps-composition.hpp\"\
    \n\n// find Q(P(x)) mod x ^ min(deg(P), deg(Q))\ntemplate <typename mint>\nFormalPowerSeries<mint>\
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
    \ )\n * @docs docs/fps/fps-composition.md\n */\n"
  code: "#pragma once\n\n#include \"../modulo/binomial.hpp\"\n#include \"./formal-power-series.hpp\"\
    \n\n// find Q(P(x)) mod x ^ min(deg(P), deg(Q))\ntemplate <typename mint>\nFormalPowerSeries<mint>\
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
    \ )\n * @docs docs/fps/fps-composition.md\n */\n"
  dependsOn:
  - modulo/binomial.hpp
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/fps-composition.hpp
  requiredBy: []
  timestamp: '2021-05-10 21:37:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-composition.test.cpp
documentation_of: fps/fps-composition.hpp
layout: document
redirect_from:
- /library/fps/fps-composition.hpp
- /library/fps/fps-composition.hpp.html
title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}\\left((N \\log N)^{\\frac{3}{2}}\\\
  right)$ )"
---

## 関数の合成

形式的冪級数$P(x),Q(x)$(ただし$P_0 = 0$)に対して$Q(P) \mod x^{n}$を$\mathrm{O}(\left(n\log n\right)^{\frac{3}{2}})$で求めるライブラリ。

[出典の論文](http://www.eecs.harvard.edu/~htk/publication/1978-jacm-brent-kung.pdf)

#### 概要

まず、$P$を$P = P_m + P_r,\ \ P_r \equiv 0 \mod x^m$を満たす$P_m,P_r$に分けて考える。($m$は後で値を決める。)この時、テイラー展開の式

$$Q(P)=\sum_{i=0}^\infty\frac{Q^{(i)}(P_m)}{i!}(P-P_m)^i=\sum_{i=0}^\infty\frac{Q^{(i)}(P_m)}{i!}(P_r)^i$$

の前$\lfloor\frac{n}{m}\rfloor$次の項を計算できればよいので($P_r \equiv 0 \mod x$に留意する)、$Q^{(i)}(P),0 \leq i \leq \lfloor\frac{n}{m}\rfloor$を高速に列挙できればよい。

まず、$Q(P(x))\mod x^n$は$\deg(Q) = j$($j$は2冪)とした時

$$Q(P) = Q_1(P) + P^{\frac{j}{2}}\cdot Q_2(P)$$

を利用して再帰的に求めることで$\mathrm{O}(jm\log^2 n)$で計算できる。また、$Q^{(i)}(P_m)$は連鎖律$\frac{d}{dx}Q(P) = \frac{dP} {dx} \cdot \frac{dQ}{dP}$を利用して

$$Q^{(i)}{(P_m)} \equiv \frac{\left(Q^{(i-1)}{(P_m)}\right)'}{P_m'} \mod x^{n-i}$$

より$\mathrm{O}(\lfloor\frac{n}{m}\rfloor n \log n)$で列挙できる。(実装においては、$m \geq 2$かつ$P$の$2$次の係数が$0$の時に$\frac{1}{P_m'}$が定義されないコーナーケースを意識して適切に逆元を取る必要がある。)

最後にテイラー展開の式に基づいて足し合わせる部分も愚直に計算すると$\mathrm{O}(\lfloor\frac{n}{m}\rfloor n \log n)$で計算できる。

以上より$j = n$とすると$\mathrm{O}(nm\log^2 n + \lfloor\frac{n}{m}\rfloor n \log n)$で$Q(P(x))$を計算することが出来た。ここで$m = \sqrt{\frac{n} {\log n}}$とおくと$\mathrm{O}(\left(n\log n\right)^{\frac{3}{2}})$となる。

###### 余談

実装してから思ったが、元の論文には行列積を使用した$O(\sqrt{N}\cdot T(\sqrt{N}))$($T(n)$は行列積のオーダー)のアルゴリズムも載っており、オーダーは実質2乗だがSIMDの利用などにより定数倍高速化が見込める。

$N \leq 8192$とすると、感覚的には解説したアルゴリズムよりも大きさ$100$の行列積$100回$の方が高速に動作する気がする… 

$\rightarrow$実装したら3倍速かった [実装](https://nyaannyaan.github.io/library/library/fps/fps-composition-fast.hpp.html)

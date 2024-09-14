---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: fps/pow-enumerate.hpp
    title: "pow \u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: modulo/binomial.hpp
    title: modulo/binomial.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/composition.test.cpp
    title: verify/verify-unit-test/composition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-compositional-inverse-large.test.cpp
    title: verify/verify-yosupo-fps/yosupo-compositional-inverse-large.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-compositional-inverse.test.cpp
    title: verify/verify-yosupo-fps/yosupo-compositional-inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1939-2.test.cpp
    title: verify/verify-yuki/yuki-1939-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1939.test.cpp
    title: verify/verify-yuki/yuki-1939.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2661.test.cpp
    title: verify/verify-yuki/yuki-2661.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9006\u95A2\u6570"
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
    \n * @docs docs/fps/formal-power-series.md\n */\n#line 2 \"fps/pow-enumerate.hpp\"\
    \n\n#line 5 \"fps/pow-enumerate.hpp\"\nusing namespace std;\n\n#line 8 \"fps/pow-enumerate.hpp\"\
    \n\n// [x^n] f(x)^i g(x) \u3092 i=0,1,...,m \u3067\u5217\u6319\n// n = (f \u306E\
    \u6B21\u6570) - 1\ntemplate <typename mint>\nFormalPowerSeries<mint> pow_enumerate(FormalPowerSeries<mint>\
    \ f,\n                                      FormalPowerSeries<mint> g = {1},\n\
    \                                      int m = -1) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = f.size() - 1, k = 1;\n  g.resize(n + 1);\n  if (m == -1) m = n;\n \
    \ int h = 1;\n  while (h < n + 1) h *= 2;\n  fps P((n + 1) * k), Q((n + 1) * k),\
    \ nP, nQ, buf, buf2;\n  for (int i = 0; i <= n; i++) P[i * k + 0] = g[i];\n  for\
    \ (int i = 0; i <= n; i++) Q[i * k + 0] = -f[i];\n  Q[0] += 1;\n  while (n) {\n\
    \    mint inv2 = mint{2}.inverse();\n    mint w = mint{fps::ntt_pr()}.pow((mint::get_mod()\
    \ - 1) / (2 * k));\n    mint iw = w.inverse();\n\n    buf2.resize(k);\n    auto\
    \ ntt_doubling = [&]() {\n      copy(begin(buf), end(buf), begin(buf2));\n   \
    \   buf2.intt();\n      mint c = 1;\n      for (int i = 0; i < k; i++) buf2[i]\
    \ *= c, c *= w;\n      buf2.ntt();\n      copy(begin(buf2), end(buf2), back_inserter(buf));\n\
    \    };\n\n    nP.clear(), nQ.clear();\n    for (int i = 0; i <= n; i++) {\n \
    \     buf.resize(k);\n      copy(begin(P) + i * k, begin(P) + (i + 1) * k, begin(buf));\n\
    \      ntt_doubling();\n      copy(begin(buf), end(buf), back_inserter(nP));\n\
    \n      buf.resize(k);\n      copy(begin(Q) + i * k, begin(Q) + (i + 1) * k, begin(buf));\n\
    \      if (i == 0) {\n        for (int j = 0; j < k; j++) buf[j] -= 1;\n     \
    \   ntt_doubling();\n        for (int j = 0; j < k; j++) buf[j] += 1;\n      \
    \  for (int j = 0; j < k; j++) buf[k + j] -= 1;\n      } else {\n        ntt_doubling();\n\
    \      }\n      copy(begin(buf), end(buf), back_inserter(nQ));\n    }\n    nP.resize(2\
    \ * h * 2 * k);\n    nQ.resize(2 * h * 2 * k);\n    fps p(2 * h), q(2 * h);\n\n\
    \    w = mint{fps::ntt_pr()}.pow((mint::get_mod() - 1) / (2 * h));\n    iw = w.inverse();\n\
    \    vector<int> btr;\n    if (n % 2) {\n      btr.resize(h);\n      for (int\
    \ i = 0, lg = __builtin_ctz(h); i < h; i++) {\n        btr[i] = (btr[i >> 1] >>\
    \ 1) + ((i & 1) << (lg - 1));\n      }\n    }\n\n    for (int j = 0; j < 2 * k;\
    \ j++) {\n      p.assign(2 * h, 0);\n      q.assign(2 * h, 0);\n      for (int\
    \ i = 0; i < h; i++) {\n        p[i] = nP[i * 2 * k + j], q[i] = nQ[i * 2 * k\
    \ + j];\n      }\n      p.ntt(), q.ntt();\n      for (int i = 0; i < 2 * h; i\
    \ += 2) swap(q[i], q[i + 1]);\n      for (int i = 0; i < 2 * h; i++) p[i] *= q[i];\n\
    \      for (int i = 0; i < h; i++) q[i] = q[i * 2] * q[i * 2 + 1];\n      if (n\
    \ % 2 == 0) {\n        for (int i = 0; i < h; i++) p[i] = (p[i * 2] + p[i * 2\
    \ + 1]) * inv2;\n      } else {\n        mint c = inv2;\n        buf.resize(h);\n\
    \        for (int i : btr) buf[i] = (p[i * 2] - p[i * 2 + 1]) * c, c *= iw;\n\
    \        swap(p, buf);\n      }\n      p.resize(h), q.resize(h);\n      p.intt(),\
    \ q.intt();\n      for (int i = 0; i < h; i++) nP[i * 2 * k + j] = p[i];\n   \
    \   for (int i = 0; i < h; i++) nQ[i * 2 * k + j] = q[i];\n    }\n    nP.resize((n\
    \ / 2 + 1) * 2 * k);\n    nQ.resize((n / 2 + 1) * 2 * k);\n    swap(P, nP), swap(Q,\
    \ nQ);\n    n /= 2, h /= 2, k *= 2;\n  }\n\n  fps S{begin(P), begin(P) + k};\n\
    \  fps T{begin(Q), begin(Q) + k};\n  S.intt(), T.intt(), T[0] -= 1;\n  if (f[0]\
    \ == 0) return S.rev().pre(m + 1);\n  return (S.rev() * (T + (fps{1} << k)).rev().inv(m\
    \ + 1)).pre(m + 1);\n}\n\n/*\n// \u5225\u30D0\u30FC\u30B8\u30E7\u30F3\n// [x^n]\
    \ f(x)^i g(x) \u3092 i=0,1,...,m \u3067\u5217\u6319\n// n = (f \u306E\u6B21\u6570\
    ) - 1\nFormalPowerSeries<mint> pow_enumerate(FormalPowerSeries<mint> f,\n    \
    \                                  FormalPowerSeries<mint> g = {1},\n        \
    \                              int m = -1) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int n = f.size() - 1, k = 1;\n  g.resize(n + 1);\n  if (m == -1) m = n;\n \
    \ int h = 1;\n  while (h < n + 1) h *= 2;\n  fps P(h * k), Q(h * k), nP(4 * h\
    \ * k), nQ(4 * h * k), nR(2 * h * k);\n  for (int i = 0; i <= n; i++) P[i] = g[i],\
    \ Q[i] = -f[i];\n  while (n) {\n    nP.assign(4 * h * k, 0);\n    nQ.assign(4\
    \ * h * k, 0);\n    for (int i = 0; i < k; i++) {\n      copy(begin(P) + i * h,\
    \ begin(P) + i * h + n + 1, begin(nP) + i * 2 * h);\n      copy(begin(Q) + i *\
    \ h, begin(Q) + i * h + n + 1, begin(nQ) + i * 2 * h);\n    }\n    nQ[k * 2 *\
    \ h] += 1;\n    nP.ntt(), nQ.ntt();\n    for (int i = 0; i < 4 * h * k; i += 2)\
    \ swap(nQ[i], nQ[i + 1]);\n    for (int i = 0; i < 4 * h * k; i++) nP[i] *= nQ[i];\n\
    \    for (int i = 0; i < 2 * h * k; i++) nR[i] = nQ[i * 2] * nQ[i * 2 + 1];\n\
    \    nP.intt(), nR.intt();\n    nR[0] -= 1;\n    P.assign(h * k, 0), Q.assign(h\
    \ * k, 0);\n    for (int i = 0; i < 2 * k; i++) {\n      for (int j = 0; j <=\
    \ n / 2; j++) {\n        P[i * h / 2 + j] = nP[i * 2 * h + j * 2 + n % 2];\n \
    \       Q[i * h / 2 + j] = nR[i * h + j];\n      }\n    }\n    n /= 2, h /= 2,\
    \ k *= 2;\n  }\n  fps S{begin(P), begin(P) + k}, T{begin(Q), begin(Q) + k};\n\
    \  T.push_back(1);\n  return (S.rev() * T.rev().inv(m + 1)).pre(m + 1);\n}\n*/\n\
    \n/**\n * @brief pow \u5217\u6319\n */\n#line 10 \"fps/fps-compositional-inverse.hpp\"\
    \n\n// f \u3092\u5165\u529B\u3068\u3057\u3066, f(g(x)) = x \u3092\u6E80\u305F\u3059\
    \ g(x) mod x^{deg} \u3092\u8FD4\u3059\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ compositional_inverse(FormalPowerSeries<mint> f,\n                         \
    \                     int deg = -1) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  assert((int)f.size() >= 2 and f[1] != 0);\n  if (deg == -1) deg = f.size();\n\
    \  if (deg < 2) return fps{0, f[1].inverse()}.pre(deg);\n  int n = deg - 1;\n\
    \  fps h = pow_enumerate(f) * n;\n  for (int k = 1; k <= n; k++) h[k] /= k;\n\
    \  h = h.rev();\n  h *= h[0].inverse();\n  fps g = (h.log() * mint{-n}.inverse()).exp();\n\
    \  g *= f[1].inverse();\n  return (g << 1).pre(deg);\n}\n\n// f(g(x)) = x \u3092\
    \u6E80\u305F\u3059 g(x) mod x^{deg} \u3092\u8FD4\u3059\n// calc_f(g, d) \u306F\
    \ f(g(x)) mod x^d \u3092\u8A08\u7B97\u3059\u308B\u95A2\u6570\ntemplate <typename\
    \ fps>\nfps compositional_inverse(function<fps(fps, int)> calc_f, int deg) {\n\
    \  if (deg <= 2) {\n    fps g = calc_f(fps{0, 1}, 2);\n    assert(g[0] == 0 &&\
    \ g[1] != 0);\n    g[1] = g[1].inverse();\n    return g.pre(deg);\n  }\n  fps\
    \ g = compositional_inverse(calc_f, (deg + 1) / 2);\n  fps fg = calc_f(g, deg\
    \ + 1);\n  fps fdg = (fg.diff() * g.diff().inv(deg)).pre(deg);\n  return (g -\
    \ (fg - fps{0, 1}) * fdg.inv()).pre(deg);\n}\n\n/*\n *  @brief \u9006\u95A2\u6570\
    \n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\nusing namespace\
    \ std;\n\n#include \"../modulo/binomial.hpp\"\n#include \"formal-power-series.hpp\"\
    \n#include \"pow-enumerate.hpp\"\n\n// f \u3092\u5165\u529B\u3068\u3057\u3066\
    , f(g(x)) = x \u3092\u6E80\u305F\u3059 g(x) mod x^{deg} \u3092\u8FD4\u3059\ntemplate\
    \ <typename mint>\nFormalPowerSeries<mint> compositional_inverse(FormalPowerSeries<mint>\
    \ f,\n                                              int deg = -1) {\n  using fps\
    \ = FormalPowerSeries<mint>;\n  assert((int)f.size() >= 2 and f[1] != 0);\n  if\
    \ (deg == -1) deg = f.size();\n  if (deg < 2) return fps{0, f[1].inverse()}.pre(deg);\n\
    \  int n = deg - 1;\n  fps h = pow_enumerate(f) * n;\n  for (int k = 1; k <= n;\
    \ k++) h[k] /= k;\n  h = h.rev();\n  h *= h[0].inverse();\n  fps g = (h.log()\
    \ * mint{-n}.inverse()).exp();\n  g *= f[1].inverse();\n  return (g << 1).pre(deg);\n\
    }\n\n// f(g(x)) = x \u3092\u6E80\u305F\u3059 g(x) mod x^{deg} \u3092\u8FD4\u3059\
    \n// calc_f(g, d) \u306F f(g(x)) mod x^d \u3092\u8A08\u7B97\u3059\u308B\u95A2\u6570\
    \ntemplate <typename fps>\nfps compositional_inverse(function<fps(fps, int)> calc_f,\
    \ int deg) {\n  if (deg <= 2) {\n    fps g = calc_f(fps{0, 1}, 2);\n    assert(g[0]\
    \ == 0 && g[1] != 0);\n    g[1] = g[1].inverse();\n    return g.pre(deg);\n  }\n\
    \  fps g = compositional_inverse(calc_f, (deg + 1) / 2);\n  fps fg = calc_f(g,\
    \ deg + 1);\n  fps fdg = (fg.diff() * g.diff().inv(deg)).pre(deg);\n  return (g\
    \ - (fg - fps{0, 1}) * fdg.inv()).pre(deg);\n}\n\n/*\n *  @brief \u9006\u95A2\u6570\
    \n */\n"
  dependsOn:
  - modulo/binomial.hpp
  - fps/formal-power-series.hpp
  - fps/pow-enumerate.hpp
  isVerificationFile: false
  path: fps/fps-compositional-inverse.hpp
  requiredBy: []
  timestamp: '2024-03-28 20:36:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-compositional-inverse-large.test.cpp
  - verify/verify-yosupo-fps/yosupo-compositional-inverse.test.cpp
  - verify/verify-unit-test/composition.test.cpp
  - verify/verify-yuki/yuki-1939.test.cpp
  - verify/verify-yuki/yuki-2661.test.cpp
  - verify/verify-yuki/yuki-1939-2.test.cpp
documentation_of: fps/fps-compositional-inverse.hpp
layout: document
redirect_from:
- /library/fps/fps-compositional-inverse.hpp
- /library/fps/fps-compositional-inverse.hpp.html
title: "\u9006\u95A2\u6570"
---

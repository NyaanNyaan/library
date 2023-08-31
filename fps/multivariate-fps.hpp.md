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
  - icon: ':heavy_check_mark:'
    path: ntt/multivariate-multiplication.hpp
    title: Multivariate Multiplication
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1783.test.cpp
    title: verify/verify-yuki/yuki-1783.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u591A\u5909\u6570\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\
      \u30D6\u30E9\u30EA"
    links: []
  bundledCode: "#line 2 \"fps/multivariate-fps.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n\n#line 2 \"modulo/binomial.hpp\"\
    \n\n#line 4 \"modulo/binomial.hpp\"\n#include <type_traits>\n#line 6 \"modulo/binomial.hpp\"\
    \nusing namespace std;\n\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306E\
    \ MAX \u306B \u300CC(n, r) \u3084 fac(n) \u3067\u30AF\u30A8\u30EA\u3092\u6295\u3052\
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
    \ 0 ? 1 : C(n + r - 1, r);\n  }\n};\n#line 2 \"ntt/multivariate-multiplication.hpp\"\
    \n\n// \u9577\u3055\u304C\u7B49\u3057\u3044\u5217\u540C\u58EB\u306E\u7573\u307F\
    \u8FBC\u307F\u3057\u304B\u3057\u306A\u3044\ntemplate <typename fps>\nfps multivariate_multiplication(const\
    \ fps& f, const fps& g,\n                                const vector<int>& base)\
    \ {\n  assert(f.size() == g.size());\n  int n = f.size(), s = base.size(), W =\
    \ 1;\n  if (s == 0) return fps{f[0] * g[0]};\n  while (W < 2 * n) W *= 2;\n\n\
    \  vector<int> chi(n);\n  for (int i = 0; i < n; i++) {\n    int x = i;\n    for\
    \ (int j = 0; j < s - 1; j++) chi[i] += (x /= base[j]);\n    chi[i] %= s;\n  }\n\
    \n  vector<fps> F(s, fps(W)), G(s, fps(W));\n  for (int i = 0; i < n; i++) F[chi[i]][i]\
    \ = f[i], G[chi[i]][i] = g[i];\n\n  for (auto& x : F) x.ntt();\n  for (auto& x\
    \ : G) x.ntt();\n  fps a(s);\n  for (int k = 0; k < W; k++) {\n    fill(begin(a),\
    \ end(a), typename fps::value_type());\n    for (int i = 0; i < s; i++)\n    \
    \  for (int j = 0; j < s; j++) {\n        a[i + j - (i + j >= s ? s : 0)] += F[i][k]\
    \ * G[j][k];\n      }\n    for (int i = 0; i < s; i++) F[i][k] = a[i];\n  }\n\
    \  for (auto& x : F) x.intt();\n  fps h(n);\n  for (int i = 0; i < n; i++) h[i]\
    \ = F[chi[i]][i];\n  return h;\n}\n\n/**\n * @brief Multivariate Multiplication\n\
    \ * @docs docs/ntt/multivariate-multiplication.md\n */\n#line 2 \"fps/formal-power-series.hpp\"\
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
    \n * @docs docs/fps/formal-power-series.md\n */\n#line 11 \"fps/multivariate-fps.hpp\"\
    \n\n// FFT mod \u3067\u306A\u3044\u3068\u4F7F\u3048\u306A\u3044\n// f.size() !=\
    \ (base \u306E\u7DCF\u7A4D) \u3067\u3082\u52D5\u304F\u304C, \u4E8C\u9805\u6F14\
    \u7B97\u306F\u9577\u3055\u304C\u7B49\u3057\u3044\u5217\u540C\u58EB\u3057\u304B\
    \u30C0\u30E1\n// \u6DFB\u3048\u5B57\u30A2\u30AF\u30BB\u30B9\u306F operator() \u3092\
    \u4F7F\u3046\ntemplate <typename mint>\nstruct MultivariateFormalPowerSeries {\n\
    \  using mfps = MultivariateFormalPowerSeries<mint>;\n  using fps = FormalPowerSeries<mint>;\n\
    \n  fps f;\n  vector<int> base;\n\n  MultivariateFormalPowerSeries() = default;\n\
    \  MultivariateFormalPowerSeries(const vector<int>& _base) : base(_base) {\n \
    \   int n = 1;\n    for (auto& x : base) n *= x;\n    f.resize(n);\n  }\n  MultivariateFormalPowerSeries(const\
    \ fps& _f, const vector<int>& _base)\n      : f(_f), base(_base) {}\n\n  friend\
    \ ostream& operator<<(ostream& os, const mfps& rhs) {\n    os << \"[ \";\n   \
    \ for (int i = 0; i < (int)rhs.f.size(); i++) {\n      os << rhs.f[i] << (i +\
    \ 1 == (int)rhs.f.size() ? \"\" : \", \");\n    }\n    return os << \" ]\";\n\
    \  }\n\n  long long _id(int) { return 0; }\n  template <typename Head, typename...\
    \ Tail>\n  long long _id(int i, Head&& head, Tail&&... tail) {\n    assert(i <\
    \ (int)base.size() && (int)head < base[i]);\n    return head + _id(i + 1, forward<Tail>(tail)...)\
    \ * base[i];\n  }\n  template <typename... Args>\n  long long id(Args&&... args)\
    \ {\n    return _id(0, forward<Args>(args)...);\n  }\n  template <typename...\
    \ Args>\n  mint& operator()(Args&&... args) {\n    return f[id(forward<Args>(args)...)];\n\
    \  }\n\n  mfps& operator+=(const mfps& rhs) {\n    assert(base == rhs.base &&\
    \ f.size() == rhs.f.size());\n    for (int i = 0; i < (int)f.size(); i++) f[i]\
    \ += rhs.f[i];\n    return *this;\n  }\n  mfps& operator-=(const mfps& rhs) {\n\
    \    assert(base == rhs.base && f.size() == rhs.f.size());\n    for (int i = 0;\
    \ i < (int)f.size(); i++) f[i] -= rhs.f[i];\n    return *this;\n  }\n  mfps& operator*=(const\
    \ mfps& rhs) {\n    assert(base == rhs.base && f.size() == rhs.f.size());\n  \
    \  f = multivariate_multiplication(f, rhs.f, base);\n    return *this;\n  }\n\
    \  mfps& operator/=(const mfps& rhs) {\n    assert(base == rhs.base);\n    assert(f.size()\
    \ == rhs.f.size());\n    return (*this) *= rhs.inv();\n  }\n\n  mfps& operator+=(const\
    \ mint& rhs) {\n    assert(!f.empty());\n    f[0] += rhs;\n    return *this;\n\
    \  }\n  mfps& operator-=(const mint& rhs) {\n    assert(!f.empty());\n    f[0]\
    \ -= rhs;\n    return *this;\n  }\n  mfps& operator*=(const mint& rhs) {\n   \
    \ for (auto& x : f) x *= rhs;\n    return *this;\n  }\n  mfps& operator/=(const\
    \ mint& rhs) {\n    for (auto& x : f) x /= rhs;\n    return *this;\n  }\n\n  mfps\
    \ operator+(const mfps& rhs) const { return mfps{*this} += rhs; }\n  mfps operator-(const\
    \ mfps& rhs) const { return mfps{*this} -= rhs; }\n  mfps operator*(const mfps&\
    \ rhs) const { return mfps{*this} *= rhs; }\n  mfps operator/(const mfps& rhs)\
    \ const { return mfps{*this} /= rhs; }\n\n  mfps operator+(const mint& rhs) const\
    \ { return mfps{*this} += rhs; }\n  mfps operator-(const mint& rhs) const { return\
    \ mfps{*this} -= rhs; }\n  mfps operator*(const mint& rhs) const { return mfps{*this}\
    \ *= rhs; }\n  mfps operator/(const mint& rhs) const { return mfps{*this} /= rhs;\
    \ }\n\n  mfps operator+() const { return mfps{*this}; }\n  mfps operator-() const\
    \ { return mfps{-f, base}; }\n\n  friend bool operator==(const mfps& lhs, const\
    \ mfps& rhs) {\n    return lhs.f == rhs.f && lhs.base == rhs.base;\n  }\n  friend\
    \ bool operator!=(const mfps& lhs, const mfps& rhs) {\n    return lhs.f != rhs.f\
    \ || lhs.base != rhs.base;\n  }\n\n  mfps diff() const {\n    mfps g{*this};\n\
    \    for (int i = 0; i < (int)g.f.size(); i++) g.f[i] *= i;\n    return g;\n \
    \ }\n  mfps integral() const {\n    static Binomial<mint> binom;\n    mfps g{*this};\n\
    \    for (int i = 1; i < (int)g.f.size(); i++) g.f[i] *= binom.inv(i);\n    return\
    \ g;\n  }\n\n  mfps inv() const {\n    assert(f[0] != 0);\n    if (base.empty())\
    \ return mfps{fps{f[0].inverse()}, base};\n    int n = f.size(), s = base.size(),\
    \ W = 1;\n    while (W < 2 * n) W *= 2;\n\n    vector<int> chi(W);\n    for (int\
    \ i = 0; i < W; i++) {\n      int x = i;\n      for (int j = 0; j < s - 1; j++)\
    \ chi[i] += (x /= base[j]);\n      chi[i] %= s;\n    }\n    auto hadamard_prod\
    \ = [&s](vector<fps>& F, vector<fps>& G, vector<fps>& H) {\n      fps a(s);\n\
    \      for (int k = 0; k < (int)F[0].size(); k++) {\n        fill(begin(a), end(a),\
    \ typename fps::value_type());\n        for (int i = 0; i < s; i++)\n        \
    \  for (int j = 0; j < s; j++) {\n            a[i + j - (i + j >= s ? s : 0)]\
    \ += F[i][k] * G[j][k];\n          }\n        for (int i = 0; i < s; i++) H[i][k]\
    \ = a[i];\n      }\n    };\n    fps g(W);\n    g[0] = f[0].inverse();\n    for\
    \ (int d = 1; d < n; d *= 2) {\n      vector<fps> F(s, fps(2 * d)), G(s, fps(2\
    \ * d)), H(s, fps(2 * d));\n      for (int j = 0; j < min((int)f.size(), 2 * d);\
    \ j++) F[chi[j]][j] = f[j];\n      for (int j = 0; j < d; j++) G[chi[j]][j] =\
    \ g[j];\n      for (auto& x : F) x.ntt();\n      for (auto& x : G) x.ntt();\n\
    \      hadamard_prod(F, G, H);\n      for (auto& x : H) x.intt();\n      for (auto&\
    \ x : F) fill(begin(x), end(x), typename fps::value_type());\n      for (int j\
    \ = d; j < 2 * d; j++) F[chi[j]][j] = H[chi[j]][j];\n      for (auto& x : F) x.ntt();\n\
    \      hadamard_prod(F, G, H);\n      for (auto& x : H) x.intt();\n      for (int\
    \ j = d; j < 2 * d; j++) g[j] = -H[chi[j]][j];\n    }\n    mfps res{*this};\n\
    \    res.f = fps{begin(g), begin(g) + n};\n    return res;\n  }\n  mfps log()\
    \ const {\n    assert(!f.empty() && f[0] == 1);\n    return ((*this).diff() /\
    \ *this).integral();\n  }\n  mfps exp() const {\n    assert(!f.empty() && f[0]\
    \ == mint{0});\n    int n = f.size();\n    mfps g{fps{1}, base};\n    for (int\
    \ d = 1; d < n; d *= 2) {\n      int s = min(n, d * 2);\n      g.f.resize(s, mint{0});\n\
    \      g *= mfps{fps{begin(f), begin(f) + s}, base} - g.log() + 1;\n    }\n  \
    \  return g;\n  }\n  mfps pow(long long e) const {\n    assert(!f.empty());\n\
    \    if (f[0] != 0) {\n      mint f0inv = f[0].inverse(), coe = f[0].pow(e);\n\
    \      return (((*this) * f0inv).log() * e).exp() * coe;\n    }\n    int n = f.size();\n\
    \    long long base_sum = 0;\n    for (auto& b : base) base_sum += b - 1;\n  \
    \  if (e > base_sum) return mfps{fps(n), base};\n    mfps res{fps(n), base}, a{*this};\n\
    \    res.f[0] = 1;\n    for (; e; a *= a, e >>= 1) {\n      if (e & 1) res *=\
    \ a;\n    }\n    return res;\n  }\n};\n\n/**\n * @brief \u591A\u5909\u6570\u5F62\
    \u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n */\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    using namespace std;\n\n#include \"../modulo/binomial.hpp\"\n#include \"../ntt/multivariate-multiplication.hpp\"\
    \n#include \"formal-power-series.hpp\"\n\n// FFT mod \u3067\u306A\u3044\u3068\u4F7F\
    \u3048\u306A\u3044\n// f.size() != (base \u306E\u7DCF\u7A4D) \u3067\u3082\u52D5\
    \u304F\u304C, \u4E8C\u9805\u6F14\u7B97\u306F\u9577\u3055\u304C\u7B49\u3057\u3044\
    \u5217\u540C\u58EB\u3057\u304B\u30C0\u30E1\n// \u6DFB\u3048\u5B57\u30A2\u30AF\u30BB\
    \u30B9\u306F operator() \u3092\u4F7F\u3046\ntemplate <typename mint>\nstruct MultivariateFormalPowerSeries\
    \ {\n  using mfps = MultivariateFormalPowerSeries<mint>;\n  using fps = FormalPowerSeries<mint>;\n\
    \n  fps f;\n  vector<int> base;\n\n  MultivariateFormalPowerSeries() = default;\n\
    \  MultivariateFormalPowerSeries(const vector<int>& _base) : base(_base) {\n \
    \   int n = 1;\n    for (auto& x : base) n *= x;\n    f.resize(n);\n  }\n  MultivariateFormalPowerSeries(const\
    \ fps& _f, const vector<int>& _base)\n      : f(_f), base(_base) {}\n\n  friend\
    \ ostream& operator<<(ostream& os, const mfps& rhs) {\n    os << \"[ \";\n   \
    \ for (int i = 0; i < (int)rhs.f.size(); i++) {\n      os << rhs.f[i] << (i +\
    \ 1 == (int)rhs.f.size() ? \"\" : \", \");\n    }\n    return os << \" ]\";\n\
    \  }\n\n  long long _id(int) { return 0; }\n  template <typename Head, typename...\
    \ Tail>\n  long long _id(int i, Head&& head, Tail&&... tail) {\n    assert(i <\
    \ (int)base.size() && (int)head < base[i]);\n    return head + _id(i + 1, forward<Tail>(tail)...)\
    \ * base[i];\n  }\n  template <typename... Args>\n  long long id(Args&&... args)\
    \ {\n    return _id(0, forward<Args>(args)...);\n  }\n  template <typename...\
    \ Args>\n  mint& operator()(Args&&... args) {\n    return f[id(forward<Args>(args)...)];\n\
    \  }\n\n  mfps& operator+=(const mfps& rhs) {\n    assert(base == rhs.base &&\
    \ f.size() == rhs.f.size());\n    for (int i = 0; i < (int)f.size(); i++) f[i]\
    \ += rhs.f[i];\n    return *this;\n  }\n  mfps& operator-=(const mfps& rhs) {\n\
    \    assert(base == rhs.base && f.size() == rhs.f.size());\n    for (int i = 0;\
    \ i < (int)f.size(); i++) f[i] -= rhs.f[i];\n    return *this;\n  }\n  mfps& operator*=(const\
    \ mfps& rhs) {\n    assert(base == rhs.base && f.size() == rhs.f.size());\n  \
    \  f = multivariate_multiplication(f, rhs.f, base);\n    return *this;\n  }\n\
    \  mfps& operator/=(const mfps& rhs) {\n    assert(base == rhs.base);\n    assert(f.size()\
    \ == rhs.f.size());\n    return (*this) *= rhs.inv();\n  }\n\n  mfps& operator+=(const\
    \ mint& rhs) {\n    assert(!f.empty());\n    f[0] += rhs;\n    return *this;\n\
    \  }\n  mfps& operator-=(const mint& rhs) {\n    assert(!f.empty());\n    f[0]\
    \ -= rhs;\n    return *this;\n  }\n  mfps& operator*=(const mint& rhs) {\n   \
    \ for (auto& x : f) x *= rhs;\n    return *this;\n  }\n  mfps& operator/=(const\
    \ mint& rhs) {\n    for (auto& x : f) x /= rhs;\n    return *this;\n  }\n\n  mfps\
    \ operator+(const mfps& rhs) const { return mfps{*this} += rhs; }\n  mfps operator-(const\
    \ mfps& rhs) const { return mfps{*this} -= rhs; }\n  mfps operator*(const mfps&\
    \ rhs) const { return mfps{*this} *= rhs; }\n  mfps operator/(const mfps& rhs)\
    \ const { return mfps{*this} /= rhs; }\n\n  mfps operator+(const mint& rhs) const\
    \ { return mfps{*this} += rhs; }\n  mfps operator-(const mint& rhs) const { return\
    \ mfps{*this} -= rhs; }\n  mfps operator*(const mint& rhs) const { return mfps{*this}\
    \ *= rhs; }\n  mfps operator/(const mint& rhs) const { return mfps{*this} /= rhs;\
    \ }\n\n  mfps operator+() const { return mfps{*this}; }\n  mfps operator-() const\
    \ { return mfps{-f, base}; }\n\n  friend bool operator==(const mfps& lhs, const\
    \ mfps& rhs) {\n    return lhs.f == rhs.f && lhs.base == rhs.base;\n  }\n  friend\
    \ bool operator!=(const mfps& lhs, const mfps& rhs) {\n    return lhs.f != rhs.f\
    \ || lhs.base != rhs.base;\n  }\n\n  mfps diff() const {\n    mfps g{*this};\n\
    \    for (int i = 0; i < (int)g.f.size(); i++) g.f[i] *= i;\n    return g;\n \
    \ }\n  mfps integral() const {\n    static Binomial<mint> binom;\n    mfps g{*this};\n\
    \    for (int i = 1; i < (int)g.f.size(); i++) g.f[i] *= binom.inv(i);\n    return\
    \ g;\n  }\n\n  mfps inv() const {\n    assert(f[0] != 0);\n    if (base.empty())\
    \ return mfps{fps{f[0].inverse()}, base};\n    int n = f.size(), s = base.size(),\
    \ W = 1;\n    while (W < 2 * n) W *= 2;\n\n    vector<int> chi(W);\n    for (int\
    \ i = 0; i < W; i++) {\n      int x = i;\n      for (int j = 0; j < s - 1; j++)\
    \ chi[i] += (x /= base[j]);\n      chi[i] %= s;\n    }\n    auto hadamard_prod\
    \ = [&s](vector<fps>& F, vector<fps>& G, vector<fps>& H) {\n      fps a(s);\n\
    \      for (int k = 0; k < (int)F[0].size(); k++) {\n        fill(begin(a), end(a),\
    \ typename fps::value_type());\n        for (int i = 0; i < s; i++)\n        \
    \  for (int j = 0; j < s; j++) {\n            a[i + j - (i + j >= s ? s : 0)]\
    \ += F[i][k] * G[j][k];\n          }\n        for (int i = 0; i < s; i++) H[i][k]\
    \ = a[i];\n      }\n    };\n    fps g(W);\n    g[0] = f[0].inverse();\n    for\
    \ (int d = 1; d < n; d *= 2) {\n      vector<fps> F(s, fps(2 * d)), G(s, fps(2\
    \ * d)), H(s, fps(2 * d));\n      for (int j = 0; j < min((int)f.size(), 2 * d);\
    \ j++) F[chi[j]][j] = f[j];\n      for (int j = 0; j < d; j++) G[chi[j]][j] =\
    \ g[j];\n      for (auto& x : F) x.ntt();\n      for (auto& x : G) x.ntt();\n\
    \      hadamard_prod(F, G, H);\n      for (auto& x : H) x.intt();\n      for (auto&\
    \ x : F) fill(begin(x), end(x), typename fps::value_type());\n      for (int j\
    \ = d; j < 2 * d; j++) F[chi[j]][j] = H[chi[j]][j];\n      for (auto& x : F) x.ntt();\n\
    \      hadamard_prod(F, G, H);\n      for (auto& x : H) x.intt();\n      for (int\
    \ j = d; j < 2 * d; j++) g[j] = -H[chi[j]][j];\n    }\n    mfps res{*this};\n\
    \    res.f = fps{begin(g), begin(g) + n};\n    return res;\n  }\n  mfps log()\
    \ const {\n    assert(!f.empty() && f[0] == 1);\n    return ((*this).diff() /\
    \ *this).integral();\n  }\n  mfps exp() const {\n    assert(!f.empty() && f[0]\
    \ == mint{0});\n    int n = f.size();\n    mfps g{fps{1}, base};\n    for (int\
    \ d = 1; d < n; d *= 2) {\n      int s = min(n, d * 2);\n      g.f.resize(s, mint{0});\n\
    \      g *= mfps{fps{begin(f), begin(f) + s}, base} - g.log() + 1;\n    }\n  \
    \  return g;\n  }\n  mfps pow(long long e) const {\n    assert(!f.empty());\n\
    \    if (f[0] != 0) {\n      mint f0inv = f[0].inverse(), coe = f[0].pow(e);\n\
    \      return (((*this) * f0inv).log() * e).exp() * coe;\n    }\n    int n = f.size();\n\
    \    long long base_sum = 0;\n    for (auto& b : base) base_sum += b - 1;\n  \
    \  if (e > base_sum) return mfps{fps(n), base};\n    mfps res{fps(n), base}, a{*this};\n\
    \    res.f[0] = 1;\n    for (; e; a *= a, e >>= 1) {\n      if (e & 1) res *=\
    \ a;\n    }\n    return res;\n  }\n};\n\n/**\n * @brief \u591A\u5909\u6570\u5F62\
    \u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\u30EA\n */\n"
  dependsOn:
  - modulo/binomial.hpp
  - ntt/multivariate-multiplication.hpp
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/multivariate-fps.hpp
  requiredBy: []
  timestamp: '2023-08-31 20:44:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1783.test.cpp
documentation_of: fps/multivariate-fps.hpp
layout: document
redirect_from:
- /library/fps/multivariate-fps.hpp
- /library/fps/multivariate-fps.hpp.html
title: "\u591A\u5909\u6570\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\u30E9\
  \u30EA"
---

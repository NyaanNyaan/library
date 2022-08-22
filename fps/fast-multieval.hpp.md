---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: fps/formal-power-series.hpp
    title: "\u591A\u9805\u5F0F/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u30E9\u30A4\u30D6\
      \u30E9\u30EA"
  - icon: ':question:'
    path: fps/ntt-friendly-fps.hpp
    title: "NTT mod\u7528FPS\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':question:'
    path: ntt/ntt.hpp
    title: ntt/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/multieval.test.cpp
    title: verify/verify-unit-test/multieval.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
    title: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
    title: verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Multipoint Evaluation(\u9AD8\u901F\u5316\u7248)"
    links: []
  bundledCode: "#line 2 \"modint/montgomery-modint.hpp\"\n\n\n\ntemplate <uint32_t\
    \ mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i <\
    \ 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32\
    \ r = get_r();\n  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r\
    \ * mod == 1, \"invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"\
    invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2\
    \ == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr\
    \ LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod + mod)\
    \ * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n    return (b +\
    \ u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
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
    \ { return mod; }\n};\n#line 2 \"fps/ntt-friendly-fps.hpp\"\n\n#line 2 \"ntt/ntt.hpp\"\
    \n\ntemplate <typename mint>\nstruct NTT {\n  static constexpr uint32_t get_pr()\
    \ {\n    uint32_t _mod = mint::get_mod();\n    using u64 = uint64_t;\n    u64\
    \ ds[32] = {};\n    int idx = 0;\n    u64 m = _mod - 1;\n    for (u64 i = 2; i\
    \ * i <= m; ++i) {\n      if (m % i == 0) {\n        ds[idx++] = i;\n        while\
    \ (m % i == 0) m /= i;\n      }\n    }\n    if (m != 1) ds[idx++] = m;\n\n   \
    \ uint32_t _pr = 2;\n    while (1) {\n      int flg = 1;\n      for (int i = 0;\
    \ i < idx; ++i) {\n        u64 a = _pr, b = (_mod - 1) / ds[i], r = 1;\n     \
    \   while (b) {\n          if (b & 1) r = r * a % _mod;\n          a = a * a %\
    \ _mod;\n          b >>= 1;\n        }\n        if (r == 1) {\n          flg =\
    \ 0;\n          break;\n        }\n      }\n      if (flg == 1) break;\n     \
    \ ++_pr;\n    }\n    return _pr;\n  };\n\n  static constexpr uint32_t mod = mint::get_mod();\n\
    \  static constexpr uint32_t pr = get_pr();\n  static constexpr int level = __builtin_ctzll(mod\
    \ - 1);\n  mint dw[level], dy[level];\n\n  void setwy(int k) {\n    mint w[level],\
    \ y[level];\n    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n    y[k - 1]\
    \ = w[k - 1].inverse();\n    for (int i = k - 2; i > 0; --i)\n      w[i] = w[i\
    \ + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];\n    dw[1] = w[1], dy[1] = y[1],\
    \ dw[2] = w[2], dy[2] = y[2];\n    for (int i = 3; i < k; ++i) {\n      dw[i]\
    \ = dw[i - 1] * y[i - 2] * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n\
    \    }\n  }\n\n  NTT() { setwy(level); }\n\n  void fft4(vector<mint> &a, int k)\
    \ {\n    if ((int)a.size() <= 1) return;\n    if (k == 1) {\n      mint a1 = a[1];\n\
    \      a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n  \
    \  if (k & 1) {\n      int v = 1 << (k - 1);\n      for (int j = 0; j < v; ++j)\
    \ {\n        mint ajv = a[j + v];\n        a[j + v] = a[j] - ajv;\n        a[j]\
    \ += ajv;\n      }\n    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 << (k\
    \ - 2 - (k & 1));\n    mint one = mint(1);\n    mint imag = dw[1];\n    while\
    \ (v) {\n      // jh = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n\
    \        int j2 = j1 + v;\n        int j3 = j2 + v;\n        for (; j0 < v; ++j0,\
    \ ++j1, ++j2, ++j3) {\n          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 =\
    \ a[j3];\n          mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n          mint t0m2\
    \ = t0 - t2, t1m3 = (t1 - t3) * imag;\n          a[j0] = t0p2 + t1p3, a[j1] =\
    \ t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n        }\n\
    \      }\n      // jh >= 1\n      mint ww = one, xx = one * dw[2], wx = one;\n\
    \      for (int jh = 4; jh < u;) {\n        ww = xx * xx, wx = ww * xx;\n    \
    \    int j0 = jh * v;\n        int je = j0 + v;\n        int j2 = je + v;\n  \
    \      for (; j0 < je; ++j0, ++j2) {\n          mint t0 = a[j0], t1 = a[j0 + v]\
    \ * xx, t2 = a[j2] * ww,\n               t3 = a[j2 + v] * wx;\n          mint\
    \ t0p2 = t0 + t2, t1p3 = t1 + t3;\n          mint t0m2 = t0 - t2, t1m3 = (t1 -\
    \ t3) * imag;\n          a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;\n     \
    \     a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;\n        }\n        xx *=\
    \ dw[__builtin_ctzll((jh += 4))];\n      }\n      u <<= 2;\n      v >>= 2;\n \
    \   }\n  }\n\n  void ifft4(vector<mint> &a, int k) {\n    if ((int)a.size() <=\
    \ 1) return;\n    if (k == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] - a[1];\n\
    \      a[0] = a[0] + a1;\n      return;\n    }\n    int u = 1 << (k - 2);\n  \
    \  int v = 1;\n    mint one = mint(1);\n    mint imag = dy[1];\n    while (u)\
    \ {\n      // jh = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n    \
    \    int j2 = v + v;\n        int j3 = j2 + v;\n        for (; j0 < v; ++j0, ++j1,\
    \ ++j2, ++j3) {\n          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n\
    \          mint t0p1 = t0 + t1, t2p3 = t2 + t3;\n          mint t0m1 = t0 - t1,\
    \ t2m3 = (t2 - t3) * imag;\n          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;\n\
    \          a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;\n        }\n      }\n   \
    \   // jh >= 1\n      mint ww = one, xx = one * dy[2], yy = one;\n      u <<=\
    \ 2;\n      for (int jh = 4; jh < u;) {\n        ww = xx * xx, yy = xx * imag;\n\
    \        int j0 = jh * v;\n        int je = j0 + v;\n        int j2 = je + v;\n\
    \        for (; j0 < je; ++j0, ++j2) {\n          mint t0 = a[j0], t1 = a[j0 +\
    \ v], t2 = a[j2], t3 = a[j2 + v];\n          mint t0p1 = t0 + t1, t2p3 = t2 +\
    \ t3;\n          mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\n        \
    \  a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;\n          a[j0 + v] = t0m1\
    \ + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;\n        }\n        xx *= dy[__builtin_ctzll(jh\
    \ += 4)];\n      }\n      u >>= 4;\n      v <<= 2;\n    }\n    if (k & 1) {\n\
    \      u = 1 << (k - 1);\n      for (int j = 0; j < u; ++j) {\n        mint ajv\
    \ = a[j] - a[j + u];\n        a[j] += a[j + u];\n        a[j + u] = ajv;\n   \
    \   }\n    }\n  }\n\n  void ntt(vector<mint> &a) {\n    if ((int)a.size() <= 1)\
    \ return;\n    fft4(a, __builtin_ctz(a.size()));\n  }\n\n  void intt(vector<mint>\
    \ &a) {\n    if ((int)a.size() <= 1) return;\n    ifft4(a, __builtin_ctz(a.size()));\n\
    \    mint iv = mint(a.size()).inverse();\n    for (auto &x : a) x *= iv;\n  }\n\
    \n  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {\n  \
    \  int l = a.size() + b.size() - 1;\n    if (min<int>(a.size(), b.size()) <= 40)\
    \ {\n      vector<mint> s(l);\n      for (int i = 0; i < (int)a.size(); ++i)\n\
    \        for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n  \
    \    return s;\n    }\n    int k = 2, M = 4;\n    while (M < l) M <<= 1, ++k;\n\
    \    setwy(k);\n    vector<mint> s(M), t(M);\n    for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = a[i];\n    for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];\n\
    \    fft4(s, k);\n    fft4(t, k);\n    for (int i = 0; i < M; ++i) s[i] *= t[i];\n\
    \    ifft4(s, k);\n    s.resize(l);\n    mint invm = mint(M).inverse();\n    for\
    \ (int i = 0; i < l; ++i) s[i] *= invm;\n    return s;\n  }\n\n  void ntt_doubling(vector<mint>\
    \ &a) {\n    int M = (int)a.size();\n    auto b = a;\n    intt(b);\n    mint r\
    \ = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\n    for (int i\
    \ = 0; i < M; i++) b[i] *= r, r *= zeta;\n    ntt(b);\n    copy(begin(b), end(b),\
    \ back_inserter(a));\n  }\n};\n#line 2 \"fps/formal-power-series.hpp\"\n\ntemplate\
    \ <typename mint>\nstruct FormalPowerSeries : vector<mint> {\n  using vector<mint>::vector;\n\
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
    \ @docs docs/fps/formal-power-series.md\n */\n#line 5 \"fps/ntt-friendly-fps.hpp\"\
    \n\ntemplate <typename mint>\nvoid FormalPowerSeries<mint>::set_fft() {\n  if\
    \ (!ntt_ptr) ntt_ptr = new NTT<mint>;\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint>&\
    \ FormalPowerSeries<mint>::operator*=(\n    const FormalPowerSeries<mint>& r)\
    \ {\n  if (this->empty() || r.empty()) {\n    this->clear();\n    return *this;\n\
    \  }\n  set_fft();\n  auto ret = static_cast<NTT<mint>*>(ntt_ptr)->multiply(*this,\
    \ r);\n  return *this = FormalPowerSeries<mint>(ret.begin(), ret.end());\n}\n\n\
    template <typename mint>\nvoid FormalPowerSeries<mint>::ntt() {\n  set_fft();\n\
    \  static_cast<NTT<mint>*>(ntt_ptr)->ntt(*this);\n}\n\ntemplate <typename mint>\n\
    void FormalPowerSeries<mint>::intt() {\n  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->intt(*this);\n\
    }\n\ntemplate <typename mint>\nvoid FormalPowerSeries<mint>::ntt_doubling() {\n\
    \  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->ntt_doubling(*this);\n}\n\n\
    template <typename mint>\nint FormalPowerSeries<mint>::ntt_pr() {\n  set_fft();\n\
    \  return static_cast<NTT<mint>*>(ntt_ptr)->pr;\n}\n\ntemplate <typename mint>\n\
    FormalPowerSeries<mint> FormalPowerSeries<mint>::inv(int deg) const {\n  assert((*this)[0]\
    \ != mint(0));\n  if (deg == -1) deg = (int)this->size();\n  FormalPowerSeries<mint>\
    \ res(deg);\n  res[0] = {mint(1) / (*this)[0]};\n  for (int d = 1; d < deg; d\
    \ <<= 1) {\n    FormalPowerSeries<mint> f(2 * d), g(2 * d);\n    for (int j =\
    \ 0; j < min((int)this->size(), 2 * d); j++) f[j] = (*this)[j];\n    for (int\
    \ j = 0; j < d; j++) g[j] = res[j];\n    f.ntt();\n    g.ntt();\n    for (int\
    \ j = 0; j < 2 * d; j++) f[j] *= g[j];\n    f.intt();\n    for (int j = 0; j <\
    \ d; j++) f[j] = 0;\n    f.ntt();\n    for (int j = 0; j < 2 * d; j++) f[j] *=\
    \ g[j];\n    f.intt();\n    for (int j = d; j < min(2 * d, deg); j++) res[j] =\
    \ -f[j];\n  }\n  return res.pre(deg);\n}\n\ntemplate <typename mint>\nFormalPowerSeries<mint>\
    \ FormalPowerSeries<mint>::exp(int deg) const {\n  using fps = FormalPowerSeries<mint>;\n\
    \  assert((*this).size() == 0 || (*this)[0] == mint(0));\n  if (deg == -1) deg\
    \ = this->size();\n\n  fps inv;\n  inv.reserve(deg + 1);\n  inv.push_back(mint(0));\n\
    \  inv.push_back(mint(1));\n\n  auto inplace_integral = [&](fps& F) -> void {\n\
    \    const int n = (int)F.size();\n    auto mod = mint::get_mod();\n    while\
    \ ((int)inv.size() <= n) {\n      int i = inv.size();\n      inv.push_back((-inv[mod\
    \ % i]) * (mod / i));\n    }\n    F.insert(begin(F), mint(0));\n    for (int i\
    \ = 1; i <= n; i++) F[i] *= inv[i];\n  };\n\n  auto inplace_diff = [](fps& F)\
    \ -> void {\n    if (F.empty()) return;\n    F.erase(begin(F));\n    mint coeff\
    \ = 1, one = 1;\n    for (int i = 0; i < (int)F.size(); i++) {\n      F[i] *=\
    \ coeff;\n      coeff += one;\n    }\n  };\n\n  fps b{1, 1 < (int)this->size()\
    \ ? (*this)[1] : 0}, c{1}, z1, z2{1, 1};\n  for (int m = 2; m < deg; m *= 2) {\n\
    \    auto y = b;\n    y.resize(2 * m);\n    y.ntt();\n    z1 = z2;\n    fps z(m);\n\
    \    for (int i = 0; i < m; ++i) z[i] = y[i] * z1[i];\n    z.intt();\n    fill(begin(z),\
    \ begin(z) + m / 2, mint(0));\n    z.ntt();\n    for (int i = 0; i < m; ++i) z[i]\
    \ *= -z1[i];\n    z.intt();\n    c.insert(end(c), begin(z) + m / 2, end(z));\n\
    \    z2 = c;\n    z2.resize(2 * m);\n    z2.ntt();\n    fps x(begin(*this), begin(*this)\
    \ + min<int>(this->size(), m));\n    x.resize(m);\n    inplace_diff(x);\n    x.push_back(mint(0));\n\
    \    x.ntt();\n    for (int i = 0; i < m; ++i) x[i] *= y[i];\n    x.intt();\n\
    \    x -= b.diff();\n    x.resize(2 * m);\n    for (int i = 0; i < m - 1; ++i)\
    \ x[m + i] = x[i], x[i] = mint(0);\n    x.ntt();\n    for (int i = 0; i < 2 *\
    \ m; ++i) x[i] *= z2[i];\n    x.intt();\n    x.pop_back();\n    inplace_integral(x);\n\
    \    for (int i = m; i < min<int>(this->size(), 2 * m); ++i) x[i] += (*this)[i];\n\
    \    fill(begin(x), begin(x) + m, mint(0));\n    x.ntt();\n    for (int i = 0;\
    \ i < 2 * m; ++i) x[i] *= y[i];\n    x.intt();\n    b.insert(end(b), begin(x)\
    \ + m, end(x));\n  }\n  return fps{begin(b), begin(b) + deg};\n}\n\n/**\n * @brief\
    \ NTT mod\u7528FPS\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/fps/ntt-friendly-fps.md\n\
    \ */\n#line 4 \"fps/fast-multieval.hpp\"\n\ntemplate <typename mint>\nvector<mint>\
    \ FastMultiEval(const FormalPowerSeries<mint> &f,\n                          \
    \ const vector<mint> &xs) {\n  using fps = FormalPowerSeries<mint>;\n  int s =\
    \ xs.size();\n  int N = 1 << (32 - __builtin_clz((int)xs.size() - 1));\n  if(f.empty()\
    \ || xs.empty()) return vector<mint>(s, mint(0));\n  vector<FormalPowerSeries<mint>>\
    \ buf(2 * N);\n  for (int i = 0; i < N; i++) {\n    mint n = mint{i < s ? -xs[i]\
    \ : mint(0)};\n    buf[i + N] = fps{n + 1, n - 1};\n  }\n  for (int i = N - 1;\
    \ i > 0; i--) {\n    fps &g(buf[(i << 1) | 0]), &h(buf[(i << 1) | 1]);\n    int\
    \ n = g.size();\n    int m = n << 1;\n    buf[i].reserve(m);\n    buf[i].resize(n);\n\
    \    for (int j = 0; j < n; j++) buf[i][j] = g[j] * h[j] - mint(1);\n    if (i\
    \ != 1) {\n      buf[i].ntt_doubling();\n      for (int j = 0; j < m; j++) buf[i][j]\
    \ += j < n ? mint(1) : -mint(1);\n    }\n  }\n\n  int fs = f.size();\n  fps root\
    \ = buf[1];\n  root.intt();\n  root.push_back(1);\n  reverse(begin(root), end(root));\n\
    \  root = root.inv(fs).rev() * f;\n  root.erase(begin(root), begin(root) + fs\
    \ - 1);\n  root.resize(N, mint(0));\n\n  vector<mint> ans(s);\n\n  auto calc =\
    \ [&](auto rec, int i, int l, int r, fps g) -> void {\n    if (i >= N) {\n   \
    \   ans[i - N] = g[0];\n      return;\n    }\n    int len = g.size(), m = (l +\
    \ r) >> 1;\n    g.ntt();\n    fps tmp = buf[i * 2 + 1];\n    for (int j = 0; j\
    \ < len; j++) tmp[j] *= g[j];\n    tmp.intt();\n    rec(rec, i * 2 + 0, l, m,\
    \ fps{begin(tmp) + (len >> 1), end(tmp)});\n    if (m >= s) return;\n    tmp =\
    \ buf[i * 2 + 0];\n    for (int j = 0; j < len; j++) tmp[j] *= g[j];\n    tmp.intt();\n\
    \    rec(rec, i * 2 + 1, m, r, fps{begin(tmp) + (len >> 1), end(tmp)});\n  };\n\
    \  calc(calc, 1, 0, N, root);\n  return ans;\n}\n\n/**\n * @brief Multipoint Evaluation(\u9AD8\
    \u901F\u5316\u7248)\n */\n"
  code: "#pragma once\n#include \"../modint/montgomery-modint.hpp\"\n#include \"./ntt-friendly-fps.hpp\"\
    \n\ntemplate <typename mint>\nvector<mint> FastMultiEval(const FormalPowerSeries<mint>\
    \ &f,\n                           const vector<mint> &xs) {\n  using fps = FormalPowerSeries<mint>;\n\
    \  int s = xs.size();\n  int N = 1 << (32 - __builtin_clz((int)xs.size() - 1));\n\
    \  if(f.empty() || xs.empty()) return vector<mint>(s, mint(0));\n  vector<FormalPowerSeries<mint>>\
    \ buf(2 * N);\n  for (int i = 0; i < N; i++) {\n    mint n = mint{i < s ? -xs[i]\
    \ : mint(0)};\n    buf[i + N] = fps{n + 1, n - 1};\n  }\n  for (int i = N - 1;\
    \ i > 0; i--) {\n    fps &g(buf[(i << 1) | 0]), &h(buf[(i << 1) | 1]);\n    int\
    \ n = g.size();\n    int m = n << 1;\n    buf[i].reserve(m);\n    buf[i].resize(n);\n\
    \    for (int j = 0; j < n; j++) buf[i][j] = g[j] * h[j] - mint(1);\n    if (i\
    \ != 1) {\n      buf[i].ntt_doubling();\n      for (int j = 0; j < m; j++) buf[i][j]\
    \ += j < n ? mint(1) : -mint(1);\n    }\n  }\n\n  int fs = f.size();\n  fps root\
    \ = buf[1];\n  root.intt();\n  root.push_back(1);\n  reverse(begin(root), end(root));\n\
    \  root = root.inv(fs).rev() * f;\n  root.erase(begin(root), begin(root) + fs\
    \ - 1);\n  root.resize(N, mint(0));\n\n  vector<mint> ans(s);\n\n  auto calc =\
    \ [&](auto rec, int i, int l, int r, fps g) -> void {\n    if (i >= N) {\n   \
    \   ans[i - N] = g[0];\n      return;\n    }\n    int len = g.size(), m = (l +\
    \ r) >> 1;\n    g.ntt();\n    fps tmp = buf[i * 2 + 1];\n    for (int j = 0; j\
    \ < len; j++) tmp[j] *= g[j];\n    tmp.intt();\n    rec(rec, i * 2 + 0, l, m,\
    \ fps{begin(tmp) + (len >> 1), end(tmp)});\n    if (m >= s) return;\n    tmp =\
    \ buf[i * 2 + 0];\n    for (int j = 0; j < len; j++) tmp[j] *= g[j];\n    tmp.intt();\n\
    \    rec(rec, i * 2 + 1, m, r, fps{begin(tmp) + (len >> 1), end(tmp)});\n  };\n\
    \  calc(calc, 1, 0, N, root);\n  return ans;\n}\n\n/**\n * @brief Multipoint Evaluation(\u9AD8\
    \u901F\u5316\u7248)\n */\n"
  dependsOn:
  - modint/montgomery-modint.hpp
  - fps/ntt-friendly-fps.hpp
  - ntt/ntt.hpp
  - fps/formal-power-series.hpp
  isVerificationFile: false
  path: fps/fast-multieval.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - verify/verify-unit-test/multieval.test.cpp
  - verify/verify-yosupo-fps/yosupo-multieval-fast.test.cpp
documentation_of: fps/fast-multieval.hpp
layout: document
redirect_from:
- /library/fps/fast-multieval.hpp
- /library/fps/fast-multieval.hpp.html
title: "Multipoint Evaluation(\u9AD8\u901F\u5316\u7248)"
---

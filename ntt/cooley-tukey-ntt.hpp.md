---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/primitive-root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/arbitrary-ntt.hpp
    title: ntt/arbitrary-ntt.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/ntt.hpp
    title: ntt/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/rader-ntt.hpp
    title: Rader's FFT Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Cooley-Tukey FFT Algorithm
    links: []
  bundledCode: "#line 2 \"ntt/cooley-tukey-ntt.hpp\"\n\n#line 2 \"ntt/rader-ntt.hpp\"\
    \n\n#line 2 \"math/primitive-root.hpp\"\n\nconstexpr uint32_t PrimitiveRoot(uint32_t\
    \ mod) {\n  using u64 = uint64_t;\n  if (mod == 2) return 1;\n  u64 ds[32] = {};\n\
    \  int idx = 0;\n  u64 m = mod - 1;\n  for (u64 i = 2; i * i <= m; ++i) {\n  \
    \  if (m % i == 0) {\n      ds[idx++] = i;\n      while (m % i == 0) m /= i;\n\
    \    }\n  }\n  if (m != 1) ds[idx++] = m;\n\n  uint32_t pr = 2;\n  while (1) {\n\
    \    int flg = 1;\n    for (int i = 0; i < idx; ++i) {\n      u64 a = pr, b =\
    \ (mod - 1) / ds[i], r = 1;\n      while (b) {\n        if (b & 1) r = r * a %\
    \ mod;\n        a = a * a % mod;\n        b >>= 1;\n      }\n      if (r == 1)\
    \ {\n        flg = 0;\n        break;\n      }\n    }\n    if (flg == 1) break;\n\
    \    ++pr;\n  }\n  return pr;\n}\n\n/**\n * @brief \u539F\u59CB\u6839\n */\n#line\
    \ 2 \"ntt/arbitrary-ntt.hpp\"\n\n#line 2 \"modint/montgomery-modint.hpp\"\n\n\n\
    \ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
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
    \ { return mod; }\n};\n#line 2 \"ntt/ntt.hpp\"\n\ntemplate <typename mint>\nstruct\
    \ NTT {\n  static constexpr uint32_t get_pr() {\n    uint32_t _mod = mint::get_mod();\n\
    \    using u64 = uint64_t;\n    u64 ds[32] = {};\n    int idx = 0;\n    u64 m\
    \ = _mod - 1;\n    for (u64 i = 2; i * i <= m; ++i) {\n      if (m % i == 0) {\n\
    \        ds[idx++] = i;\n        while (m % i == 0) m /= i;\n      }\n    }\n\
    \    if (m != 1) ds[idx++] = m;\n\n    uint32_t _pr = 2;\n    while (1) {\n  \
    \    int flg = 1;\n      for (int i = 0; i < idx; ++i) {\n        u64 a = _pr,\
    \ b = (_mod - 1) / ds[i], r = 1;\n        while (b) {\n          if (b & 1) r\
    \ = r * a % _mod;\n          a = a * a % _mod;\n          b >>= 1;\n        }\n\
    \        if (r == 1) {\n          flg = 0;\n          break;\n        }\n    \
    \  }\n      if (flg == 1) break;\n      ++_pr;\n    }\n    return _pr;\n  };\n\
    \n  static constexpr uint32_t mod = mint::get_mod();\n  static constexpr uint32_t\
    \ pr = get_pr();\n  static constexpr int level = __builtin_ctzll(mod - 1);\n \
    \ mint dw[level], dy[level];\n\n  void setwy(int k) {\n    mint w[level], y[level];\n\
    \    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n    y[k - 1] = w[k - 1].inverse();\n\
    \    for (int i = k - 2; i > 0; --i)\n      w[i] = w[i + 1] * w[i + 1], y[i] =\
    \ y[i + 1] * y[i + 1];\n    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] =\
    \ y[2];\n    for (int i = 3; i < k; ++i) {\n      dw[i] = dw[i - 1] * y[i - 2]\
    \ * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n    }\n  }\n\n  NTT() {\
    \ setwy(level); }\n\n  void fft4(vector<mint> &a, int k) {\n    if ((int)a.size()\
    \ <= 1) return;\n    if (k == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] -\
    \ a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n    if (k & 1) {\n   \
    \   int v = 1 << (k - 1);\n      for (int j = 0; j < v; ++j) {\n        mint ajv\
    \ = a[j + v];\n        a[j + v] = a[j] - ajv;\n        a[j] += ajv;\n      }\n\
    \    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 << (k - 2 - (k & 1));\n\
    \    mint one = mint(1);\n    mint imag = dw[1];\n    while (v) {\n      // jh\
    \ = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n        int j2 = j1\
    \ + v;\n        int j3 = j2 + v;\n        for (; j0 < v; ++j0, ++j1, ++j2, ++j3)\
    \ {\n          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n        \
    \  mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n          mint t0m2 = t0 - t2, t1m3 =\
    \ (t1 - t3) * imag;\n          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;\n   \
    \       a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n        }\n      }\n      //\
    \ jh >= 1\n      mint ww = one, xx = one * dw[2], wx = one;\n      for (int jh\
    \ = 4; jh < u;) {\n        ww = xx * xx, wx = ww * xx;\n        int j0 = jh *\
    \ v;\n        int je = j0 + v;\n        int j2 = je + v;\n        for (; j0 <\
    \ je; ++j0, ++j2) {\n          mint t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2]\
    \ * ww,\n               t3 = a[j2 + v] * wx;\n          mint t0p2 = t0 + t2, t1p3\
    \ = t1 + t3;\n          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;\n      \
    \    a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3,\
    \ a[j2 + v] = t0m2 - t1m3;\n        }\n        xx *= dw[__builtin_ctzll((jh +=\
    \ 4))];\n      }\n      u <<= 2;\n      v >>= 2;\n    }\n  }\n\n  void ifft4(vector<mint>\
    \ &a, int k) {\n    if ((int)a.size() <= 1) return;\n    if (k == 1) {\n     \
    \ mint a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n\
    \    }\n    int u = 1 << (k - 2);\n    int v = 1;\n    mint one = mint(1);\n \
    \   mint imag = dy[1];\n    while (u) {\n      // jh = 0\n      {\n        int\
    \ j0 = 0;\n        int j1 = v;\n        int j2 = v + v;\n        int j3 = j2 +\
    \ v;\n        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {\n          mint t0 = a[j0],\
    \ t1 = a[j1], t2 = a[j2], t3 = a[j3];\n          mint t0p1 = t0 + t1, t2p3 = t2\
    \ + t3;\n          mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;\n          a[j0]\
    \ = t0p1 + t2p3, a[j2] = t0p1 - t2p3;\n          a[j1] = t0m1 + t2m3, a[j3] =\
    \ t0m1 - t2m3;\n        }\n      }\n      // jh >= 1\n      mint ww = one, xx\
    \ = one * dy[2], yy = one;\n      u <<= 2;\n      for (int jh = 4; jh < u;) {\n\
    \        ww = xx * xx, yy = xx * imag;\n        int j0 = jh * v;\n        int\
    \ je = j0 + v;\n        int j2 = je + v;\n        for (; j0 < je; ++j0, ++j2)\
    \ {\n          mint t0 = a[j0], t1 = a[j0 + v], t2 = a[j2], t3 = a[j2 + v];\n\
    \          mint t0p1 = t0 + t1, t2p3 = t2 + t3;\n          mint t0m1 = (t0 - t1)\
    \ * xx, t2m3 = (t2 - t3) * yy;\n          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 -\
    \ t2p3) * ww;\n          a[j0 + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) *\
    \ ww;\n        }\n        xx *= dy[__builtin_ctzll(jh += 4)];\n      }\n     \
    \ u >>= 4;\n      v <<= 2;\n    }\n    if (k & 1) {\n      u = 1 << (k - 1);\n\
    \      for (int j = 0; j < u; ++j) {\n        mint ajv = a[j] - a[j + u];\n  \
    \      a[j] += a[j + u];\n        a[j + u] = ajv;\n      }\n    }\n  }\n\n  void\
    \ ntt(vector<mint> &a) {\n    if ((int)a.size() <= 1) return;\n    fft4(a, __builtin_ctz(a.size()));\n\
    \  }\n\n  void intt(vector<mint> &a) {\n    if ((int)a.size() <= 1) return;\n\
    \    ifft4(a, __builtin_ctz(a.size()));\n    mint iv = mint(a.size()).inverse();\n\
    \    for (auto &x : a) x *= iv;\n  }\n\n  vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n    int l = a.size() + b.size() - 1;\n    if (min<int>(a.size(),\
    \ b.size()) <= 40) {\n      vector<mint> s(l);\n      for (int i = 0; i < (int)a.size();\
    \ ++i)\n        for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n\
    \      return s;\n    }\n    int k = 2, M = 4;\n    while (M < l) M <<= 1, ++k;\n\
    \    setwy(k);\n    vector<mint> s(M), t(M);\n    for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = a[i];\n    for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];\n\
    \    fft4(s, k);\n    fft4(t, k);\n    for (int i = 0; i < M; ++i) s[i] *= t[i];\n\
    \    ifft4(s, k);\n    s.resize(l);\n    mint invm = mint(M).inverse();\n    for\
    \ (int i = 0; i < l; ++i) s[i] *= invm;\n    return s;\n  }\n\n  void ntt_doubling(vector<mint>\
    \ &a) {\n    int M = (int)a.size();\n    auto b = a;\n    intt(b);\n    mint r\
    \ = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\n    for (int i\
    \ = 0; i < M; i++) b[i] *= r, r *= zeta;\n    ntt(b);\n    copy(begin(b), end(b),\
    \ back_inserter(a));\n  }\n};\n#line 5 \"ntt/arbitrary-ntt.hpp\"\n\nnamespace\
    \ ArbitraryNTT {\nusing i64 = int64_t;\nusing u128 = __uint128_t;\nconstexpr int32_t\
    \ m0 = 167772161;\nconstexpr int32_t m1 = 469762049;\nconstexpr int32_t m2 = 754974721;\n\
    using mint0 = LazyMontgomeryModInt<m0>;\nusing mint1 = LazyMontgomeryModInt<m1>;\n\
    using mint2 = LazyMontgomeryModInt<m2>;\nconstexpr int r01 = mint1(m0).inverse().get();\n\
    constexpr int r02 = mint2(m0).inverse().get();\nconstexpr int r12 = mint2(m1).inverse().get();\n\
    constexpr int r02r12 = i64(r02) * r12 % m2;\nconstexpr i64 w1 = m0;\nconstexpr\
    \ i64 w2 = i64(m0) * m1;\n\ntemplate <typename T, typename submint>\nvector<submint>\
    \ mul(const vector<T> &a, const vector<T> &b) {\n  static NTT<submint> ntt;\n\
    \  vector<submint> s(a.size()), t(b.size());\n  for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = i64(a[i] % submint::get_mod());\n  for (int i = 0; i < (int)b.size();\
    \ ++i) t[i] = i64(b[i] % submint::get_mod());\n  return ntt.multiply(s, t);\n\
    }\n\ntemplate <typename T>\nvector<int> multiply(const vector<T> &s, const vector<T>\
    \ &t, int mod) {\n  auto d0 = mul<T, mint0>(s, t);\n  auto d1 = mul<T, mint1>(s,\
    \ t);\n  auto d2 = mul<T, mint2>(s, t);\n  int n = d0.size();\n  vector<int> ret(n);\n\
    \  const int W1 = w1 % mod;\n  const int W2 = w2 % mod;\n  for (int i = 0; i <\
    \ n; i++) {\n    int n1 = d1[i].get(), n2 = d2[i].get(), a = d0[i].get();\n  \
    \  int b = i64(n1 + m1 - a) * r01 % m1;\n    int c = (i64(n2 + m2 - a) * r02r12\
    \ + i64(m2 - b) * r12) % m2;\n    ret[i] = (i64(a) + i64(b) * W1 + i64(c) * W2)\
    \ % mod;\n  }\n  return ret;\n}\n\ntemplate <typename mint>\nvector<mint> multiply(const\
    \ vector<mint> &a, const vector<mint> &b) {\n  if (a.size() == 0 && b.size() ==\
    \ 0) return {};\n  if (min<int>(a.size(), b.size()) < 128) {\n    vector<mint>\
    \ ret(a.size() + b.size() - 1);\n    for (int i = 0; i < (int)a.size(); ++i)\n\
    \      for (int j = 0; j < (int)b.size(); ++j) ret[i + j] += a[i] * b[j];\n  \
    \  return ret;\n  }\n  vector<int> s(a.size()), t(b.size());\n  for (int i = 0;\
    \ i < (int)a.size(); ++i) s[i] = a[i].get();\n  for (int i = 0; i < (int)b.size();\
    \ ++i) t[i] = b[i].get();\n  vector<int> u = multiply<int>(s, t, mint::get_mod());\n\
    \  vector<mint> ret(u.size());\n  for (int i = 0; i < (int)u.size(); ++i) ret[i]\
    \ = mint(u[i]);\n  return ret;\n}\n\ntemplate <typename T>\nvector<u128> multiply_u128(const\
    \ vector<T> &s, const vector<T> &t) {\n  if (s.size() == 0 && t.size() == 0) return\
    \ {};\n  if (min<int>(s.size(), t.size()) < 128) {\n    vector<u128> ret(s.size()\
    \ + t.size() - 1);\n    for (int i = 0; i < (int)s.size(); ++i)\n      for (int\
    \ j = 0; j < (int)t.size(); ++j) ret[i + j] += i64(s[i]) * t[j];\n    return ret;\n\
    \  }\n  auto d0 = mul<T, mint0>(s, t);\n  auto d1 = mul<T, mint1>(s, t);\n  auto\
    \ d2 = mul<T, mint2>(s, t);\n  int n = d0.size();\n  vector<u128> ret(n);\n  for\
    \ (int i = 0; i < n; i++) {\n    i64 n1 = d1[i].get(), n2 = d2[i].get();\n   \
    \ i64 a = d0[i].get();\n    u128 b = (n1 + m1 - a) * r01 % m1;\n    u128 c = ((n2\
    \ + m2 - a) * r02r12 + (m2 - b) * r12) % m2;\n    ret[i] = a + b * w1 + c * w2;\n\
    \  }\n  return ret;\n}\n}  // namespace ArbitraryNTT\n#line 5 \"ntt/rader-ntt.hpp\"\
    \n\ntemplate <typename mint>\nstruct RaderNTT {\n  int p, pr, len;\n  const vector<mint>&\
    \ w;\n  vector<int> prs, iprs;\n  RaderNTT() {}\n  RaderNTT(int _p, int _len,\
    \ const vector<mint>& _w)\n      : p(_p), pr(PrimitiveRoot(p)), len(_len), w(_w)\
    \ {\n    prs.resize(p - 1);\n    iprs.resize(p, -1);\n    for (int i = 0; i <\
    \ p - 1; i++) prs[i] = i ? prs[i - 1] * pr % p : 1;\n    for (int i = 0; i < p\
    \ - 1; i++) iprs[prs[i]] = i;\n  }\n\n  void ntt(vector<mint>& a) {\n    vector<mint>\
    \ s(p - 1), t(p - 1);\n    for (int i = 0; i < p - 1; i++) s[i] = a[prs[i]];\n\
    \    for (int i = 0, ldp = len / p; i < p - 1; i++)\n      t[i] = w[ldp * prs[i\
    \ ? p - 1 - i : 0]];\n    vector<mint> u = ArbitraryNTT::multiply(s, t);\n   \
    \ s.resize(p);\n    fill(begin(s), end(s), a[0]);\n    for (int i = 1; i < p;\
    \ i++) s[0] += a[i];\n    for (int i = 0, y = 0; i < (int)u.size(); i++) {\n \
    \     s[prs[y]] += u[i];\n      if (--y < 0) y += p - 1;\n    }\n    swap(a, s);\n\
    \  }\n};\n\n/**\n * @brief Rader's FFT Algorithm\n */\n#line 4 \"ntt/cooley-tukey-ntt.hpp\"\
    \n\ntemplate <typename mint>\nstruct ArbitraryLengthNTT {\n  using i64 = long\
    \ long;\n\n  int factor(int n) {\n    for (int i = 2; i * i <= n; i++)\n     \
    \ if (n % i == 0) return i;\n    return n;\n  }\n\n  vector<int> divisor(int n)\
    \ {\n    vector<int> ret;\n    for (int i = 2; i * i <= n; i++) {\n      if (n\
    \ % i == 0) {\n        ret.push_back(i);\n        ret.push_back(n / i);\n    \
    \  }\n    }\n    ret.push_back(n);\n    sort(begin(ret), end(ret));\n    ret.erase(unique(begin(ret),\
    \ end(ret)), end(ret));\n    return ret;\n  }\n\n  int len;\n  vector<mint> w;\n\
    \  vector<int> divisors;\n  map<int, RaderNTT<mint> *> rader;\n\n  ArbitraryLengthNTT(int\
    \ len_ = -1) { set_len(len_); }\n\n  void set_len(int len_ = -1) {\n    int mod\
    \ = mint::get_mod();\n    if ((len = len_) == -1) len = mod - 1;\n    if (mod\
    \ >= 3 && len <= 1) len = 2;\n    while ((mod - 1) % len != 0) ++len;\n    mint\
    \ pr = mint(PrimitiveRoot(mod)).pow((mod - 1) / len);\n    w.resize(len + 1);\n\
    \    for (int i = 0; i <= len; i++) w[i] = i ? w[i - 1] * pr : mint(1);\n    divisors\
    \ = divisor(len);\n  }\n\n  void dft(vector<mint> &a) {\n    int N = a.size();\n\
    \    if (N == 2) {\n      mint a01 = a[0] + a[1];\n      a[1] = a[0] - a[1];\n\
    \      a[0] = a01;\n      return;\n    }\n    int d = len / N;\n    vector<mint>\
    \ b(N);\n    for (int i = 0, dk = 0; i < N; i++, dk += d) {\n      for (int j\
    \ = 0, k = 0; j < N; j++) {\n        b[j] += a[i] * w[k];\n        if ((k += dk)\
    \ >= len) k -= len;\n      }\n    }\n    swap(a, b);\n  }\n\n  void ntt_base2(vector<mint>\
    \ &a) {\n    static vector<int> btr;\n    int N = a.size();\n    assert(N % 2\
    \ == 0);\n    if (btr.size() != a.size()) {\n      btr.resize(N);\n      int b\
    \ = __builtin_ctz(N);\n      assert(N == (1 << b));\n      for (int i = 0; i <\
    \ N; i++) {\n        btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (b - 1));\n   \
    \   }\n    }\n    static vector<mint> basis;\n    if (basis.size() < a.size())\
    \ {\n      basis.resize(N);\n      mint b = w[len / N];\n      for (int i = N\
    \ >> 1; i > 0; i >>= 1) {\n        mint c = 1;\n        for (int j = 0; j < i;\
    \ ++j) {\n          basis[i + j] = c;\n          c *= b;\n        }\n        b\
    \ *= b;\n      }\n    }\n    for (int i = 0; i < N; i++)\n      if (i < btr[i])\
    \ swap(a[i], a[btr[i]]);\n    for (int k = 1; k < N; k <<= 1) {\n      for (int\
    \ i = 0; i < N; i += 2 * k) {\n        for (int j = 0; j < k; j++) {\n       \
    \   mint z = a[i + j + k] * basis[j + k];\n          a[i + j + k] = a[i + j] -\
    \ z;\n          a[i + j] = a[i + j] + z;\n        }\n      }\n    }\n  }\n\n \
    \ void pntt(vector<mint> &a) {\n    int P = a.size();\n    if (P <= 64) {\n  \
    \    dft(a);\n      return;\n    }\n    if (rader.find(P) == end(rader)) rader[P]\
    \ = new RaderNTT<mint>(P, len, w);\n    rader[P]->ntt(a);\n  }\n\n  void ntt(vector<mint>\
    \ &a) {\n    assert(len % a.size() == 0);\n    int N = (int)a.size();\n    if\
    \ (N <= 1) return;\n    if (N <= 64) {\n      dft(a);\n      return;\n    }\n\n\
    \    int P = factor(N);\n    if (P == N) {\n      pntt(a);\n      return;\n  \
    \  }\n    if (P == 2) {\n      P = 1 << __builtin_ctz(N);\n      if (N == P) {\n\
    \        ntt_base2(a);\n        return;\n      }\n    }\n\n    int Q = N / P;\n\
    \    vector<mint> t(N), u(P);\n    {\n      vector<mint> s(Q);\n      for (int\
    \ p = 0, lN = len / N, d = 0; p < P; p++, d += lN) {\n        for (int q = 0,\
    \ qP = 0; q < Q; q++, qP += P) s[q] = a[qP + p];\n        ntt(s);\n        for\
    \ (int r = 0, n = 0, pQ = p * Q; r < Q; ++r, n += d) {\n          t[pQ + r] =\
    \ w[n] * s[r];\n        }\n      }\n    }\n    for (int r = 0; r < Q; r++) {\n\
    \      for (int p = 0, pQ = 0; p < P; p++, pQ += Q) u[p] = t[pQ + r];\n      if\
    \ (P <= 64)\n        dft(u);\n      else if (P & 1)\n        pntt(u);\n      else\n\
    \        ntt_base2(u);\n      for (int s = 0, sQ = 0; s < P; s++, sQ += Q) a[sQ\
    \ + r] = u[s];\n    }\n  }\n\n  void intt(vector<mint> &a) {\n    reverse(begin(a)\
    \ + 1, end(a));\n    ntt(a);\n    mint invn = mint(a.size()).inverse();\n    for\
    \ (auto &x : a) x *= invn;\n  }\n\n  vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n    int N = (int)a.size() + (int)b.size() - 1;\n\
    \    assert(N <= len);\n    vector<mint> s(a), t(b);\n    int l = *lower_bound(begin(divisors),\
    \ end(divisors), N);\n    s.resize(l, mint(0));\n    t.resize(l, mint(0));\n \
    \   ntt(s);\n    ntt(t);\n    for (int i = 0; i < l; i++) s[i] *= t[i];\n    intt(s);\n\
    \    s.resize(N);\n    return s;\n  }\n};\n\n/**\n * @brief Cooley-Tukey FFT Algorithm\n\
    \ */\n"
  code: "#pragma once\n\n#include \"rader-ntt.hpp\"\n\ntemplate <typename mint>\n\
    struct ArbitraryLengthNTT {\n  using i64 = long long;\n\n  int factor(int n) {\n\
    \    for (int i = 2; i * i <= n; i++)\n      if (n % i == 0) return i;\n    return\
    \ n;\n  }\n\n  vector<int> divisor(int n) {\n    vector<int> ret;\n    for (int\
    \ i = 2; i * i <= n; i++) {\n      if (n % i == 0) {\n        ret.push_back(i);\n\
    \        ret.push_back(n / i);\n      }\n    }\n    ret.push_back(n);\n    sort(begin(ret),\
    \ end(ret));\n    ret.erase(unique(begin(ret), end(ret)), end(ret));\n    return\
    \ ret;\n  }\n\n  int len;\n  vector<mint> w;\n  vector<int> divisors;\n  map<int,\
    \ RaderNTT<mint> *> rader;\n\n  ArbitraryLengthNTT(int len_ = -1) { set_len(len_);\
    \ }\n\n  void set_len(int len_ = -1) {\n    int mod = mint::get_mod();\n    if\
    \ ((len = len_) == -1) len = mod - 1;\n    if (mod >= 3 && len <= 1) len = 2;\n\
    \    while ((mod - 1) % len != 0) ++len;\n    mint pr = mint(PrimitiveRoot(mod)).pow((mod\
    \ - 1) / len);\n    w.resize(len + 1);\n    for (int i = 0; i <= len; i++) w[i]\
    \ = i ? w[i - 1] * pr : mint(1);\n    divisors = divisor(len);\n  }\n\n  void\
    \ dft(vector<mint> &a) {\n    int N = a.size();\n    if (N == 2) {\n      mint\
    \ a01 = a[0] + a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a01;\n      return;\n\
    \    }\n    int d = len / N;\n    vector<mint> b(N);\n    for (int i = 0, dk =\
    \ 0; i < N; i++, dk += d) {\n      for (int j = 0, k = 0; j < N; j++) {\n    \
    \    b[j] += a[i] * w[k];\n        if ((k += dk) >= len) k -= len;\n      }\n\
    \    }\n    swap(a, b);\n  }\n\n  void ntt_base2(vector<mint> &a) {\n    static\
    \ vector<int> btr;\n    int N = a.size();\n    assert(N % 2 == 0);\n    if (btr.size()\
    \ != a.size()) {\n      btr.resize(N);\n      int b = __builtin_ctz(N);\n    \
    \  assert(N == (1 << b));\n      for (int i = 0; i < N; i++) {\n        btr[i]\
    \ = (btr[i >> 1] >> 1) + ((i & 1) << (b - 1));\n      }\n    }\n    static vector<mint>\
    \ basis;\n    if (basis.size() < a.size()) {\n      basis.resize(N);\n      mint\
    \ b = w[len / N];\n      for (int i = N >> 1; i > 0; i >>= 1) {\n        mint\
    \ c = 1;\n        for (int j = 0; j < i; ++j) {\n          basis[i + j] = c;\n\
    \          c *= b;\n        }\n        b *= b;\n      }\n    }\n    for (int i\
    \ = 0; i < N; i++)\n      if (i < btr[i]) swap(a[i], a[btr[i]]);\n    for (int\
    \ k = 1; k < N; k <<= 1) {\n      for (int i = 0; i < N; i += 2 * k) {\n     \
    \   for (int j = 0; j < k; j++) {\n          mint z = a[i + j + k] * basis[j +\
    \ k];\n          a[i + j + k] = a[i + j] - z;\n          a[i + j] = a[i + j] +\
    \ z;\n        }\n      }\n    }\n  }\n\n  void pntt(vector<mint> &a) {\n    int\
    \ P = a.size();\n    if (P <= 64) {\n      dft(a);\n      return;\n    }\n   \
    \ if (rader.find(P) == end(rader)) rader[P] = new RaderNTT<mint>(P, len, w);\n\
    \    rader[P]->ntt(a);\n  }\n\n  void ntt(vector<mint> &a) {\n    assert(len %\
    \ a.size() == 0);\n    int N = (int)a.size();\n    if (N <= 1) return;\n    if\
    \ (N <= 64) {\n      dft(a);\n      return;\n    }\n\n    int P = factor(N);\n\
    \    if (P == N) {\n      pntt(a);\n      return;\n    }\n    if (P == 2) {\n\
    \      P = 1 << __builtin_ctz(N);\n      if (N == P) {\n        ntt_base2(a);\n\
    \        return;\n      }\n    }\n\n    int Q = N / P;\n    vector<mint> t(N),\
    \ u(P);\n    {\n      vector<mint> s(Q);\n      for (int p = 0, lN = len / N,\
    \ d = 0; p < P; p++, d += lN) {\n        for (int q = 0, qP = 0; q < Q; q++, qP\
    \ += P) s[q] = a[qP + p];\n        ntt(s);\n        for (int r = 0, n = 0, pQ\
    \ = p * Q; r < Q; ++r, n += d) {\n          t[pQ + r] = w[n] * s[r];\n       \
    \ }\n      }\n    }\n    for (int r = 0; r < Q; r++) {\n      for (int p = 0,\
    \ pQ = 0; p < P; p++, pQ += Q) u[p] = t[pQ + r];\n      if (P <= 64)\n       \
    \ dft(u);\n      else if (P & 1)\n        pntt(u);\n      else\n        ntt_base2(u);\n\
    \      for (int s = 0, sQ = 0; s < P; s++, sQ += Q) a[sQ + r] = u[s];\n    }\n\
    \  }\n\n  void intt(vector<mint> &a) {\n    reverse(begin(a) + 1, end(a));\n \
    \   ntt(a);\n    mint invn = mint(a.size()).inverse();\n    for (auto &x : a)\
    \ x *= invn;\n  }\n\n  vector<mint> multiply(const vector<mint> &a, const vector<mint>\
    \ &b) {\n    int N = (int)a.size() + (int)b.size() - 1;\n    assert(N <= len);\n\
    \    vector<mint> s(a), t(b);\n    int l = *lower_bound(begin(divisors), end(divisors),\
    \ N);\n    s.resize(l, mint(0));\n    t.resize(l, mint(0));\n    ntt(s);\n   \
    \ ntt(t);\n    for (int i = 0; i < l; i++) s[i] *= t[i];\n    intt(s);\n    s.resize(N);\n\
    \    return s;\n  }\n};\n\n/**\n * @brief Cooley-Tukey FFT Algorithm\n */\n"
  dependsOn:
  - ntt/rader-ntt.hpp
  - math/primitive-root.hpp
  - ntt/arbitrary-ntt.hpp
  - modint/montgomery-modint.hpp
  - ntt/ntt.hpp
  isVerificationFile: false
  path: ntt/cooley-tukey-ntt.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitrarylengthntt.test.cpp
documentation_of: ntt/cooley-tukey-ntt.hpp
layout: document
redirect_from:
- /library/ntt/cooley-tukey-ntt.hpp
- /library/ntt/cooley-tukey-ntt.hpp.html
title: Cooley-Tukey FFT Algorithm
---

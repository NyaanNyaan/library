---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/arbitrary-ntt.hpp
    title: ntt/arbitrary-ntt.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/ntt.hpp
    title: ntt/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/bigint-gcd.test.cpp
    title: verify/verify-unit-test/bigint-gcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-addition-of-hex.test.cpp
    title: verify/verify-yosupo-math/yosupo-addition-of-hex.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-multiplication-of-hex.test.cpp
    title: verify/verify-yosupo-math/yosupo-multiplication-of-hex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/bigint-binary.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <iostream>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\nusing namespace std;\n\n#line 2 \"ntt/arbitrary-ntt.hpp\"\
    \n\n#line 2 \"modint/montgomery-modint.hpp\"\n\ntemplate <uint32_t mod>\nstruct\
    \ LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n  using i32 =\
    \ int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr\
    \ u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2\
    \ - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32 r = get_r();\n\
    \  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(mod < (1 << 30),\
    \ \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod\
    \ % 2 == 0\");\n  static_assert(r * mod == 1, \"this code has bugs.\");\n\n  u32\
    \ a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
    \ int64_t &b)\n      : a(reduce(u64(b % mod + mod) * n2)){};\n\n  static constexpr\
    \ u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * u32(-r)) * mod) >>\
    \ 32;\n  }\n\n  constexpr mint &operator+=(const mint &b) {\n    if (i32(a +=\
    \ b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  constexpr mint &operator*=(const mint &b) {\n    a =\
    \ reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr mint &operator/=(const\
    \ mint &b) {\n    *this *= b.inverse();\n    return *this;\n  }\n\n  constexpr\
    \ mint operator+(const mint &b) const { return mint(*this) += b; }\n  constexpr\
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  constexpr\
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  constexpr\
    \ mint operator/(const mint &b) const { return mint(*this) /= b; }\n  constexpr\
    \ bool operator==(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n  constexpr mint operator+() const { return mint(*this); }\n\n  constexpr\
    \ mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n\
    \      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  constexpr mint inverse() const {\n    int x = get(), y = mod,\
    \ u = 1, v = 0, t = 0, tmp = 0;\n    while (y > 0) {\n      t = x / y;\n     \
    \ x -= t * y, u -= t * v;\n      tmp = x, x = y, y = tmp;\n      tmp = u, u =\
    \ v, v = tmp;\n    }\n    return mint{u};\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n\n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
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
    \    setwy(k);\n    vector<mint> s(M);\n    for (int i = 0; i < (int)a.size();\
    \ ++i) s[i] = a[i];\n    fft4(s, k);\n    if (a.size() == b.size() && a == b)\
    \ {\n      for (int i = 0; i < M; ++i) s[i] *= s[i];\n    } else {\n      vector<mint>\
    \ t(M);\n      for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];\n      fft4(t,\
    \ k);\n      for (int i = 0; i < M; ++i) s[i] *= t[i];\n    }\n    ifft4(s, k);\n\
    \    s.resize(l);\n    mint invm = mint(M).inverse();\n    for (int i = 0; i <\
    \ l; ++i) s[i] *= invm;\n    return s;\n  }\n\n  void ntt_doubling(vector<mint>\
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
    \ i64 a = d0[i].get();\n    i64 b = (n1 + m1 - a) * r01 % m1;\n    i64 c = ((n2\
    \ + m2 - a) * r02r12 + (m2 - b) * r12) % m2;\n    ret[i] = a + b * w1 + u128(c)\
    \ * w2;\n  }\n  return ret;\n}\n}  // namespace ArbitraryNTT\n#line 12 \"math/bigint-binary.hpp\"\
    \n\nnamespace BinaryBigIntImpl {\n\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing i64 = long long;\n\n// 0 \u306F neg=false, dat={} \u3068\u3057\
    \u3066\u6271\u3046\nstruct BinaryBigInt {\n  using M = BinaryBigInt;\n  bool neg;\n\
    \  vector<u32> dat;\n\n  BinaryBigInt() : neg(false), dat() {}\n\n  BinaryBigInt(bool\
    \ _neg, const vector<u32>& _dat) : neg(_neg), dat(_dat) {}\n\n  BinaryBigInt(const\
    \ string& S, int base) : neg(false) {\n    assert(base == 16);\n    int ie = -1;\n\
    \    if (S[0] == '-') neg = true, ie++;\n    for (int r = S.size() - 1; r > ie;\
    \ r -= 8) {\n      int l = max(r - 8, ie);\n      u32 x = 0;\n      for (int i\
    \ = l + 1; i <= r; i++) {\n        int c = 0;\n        if ('0' <= S[i] and S[i]\
    \ <= '9') {\n          c = S[i] - '0';\n        } else if ('A' <= S[i] and S[i]\
    \ <= 'F') {\n          c = S[i] - 'A' + 10;\n        } else {\n          c = S[i]\
    \ - 'a' + 10;\n        }\n        x = c + (x << 4);\n      }\n      dat.push_back(x);\n\
    \    }\n    _shrink();\n  }\n\n  friend M operator+(const M& lhs, const M& rhs)\
    \ {\n    if (lhs.neg == rhs.neg) return {lhs.neg, _add(lhs.dat, rhs.dat)};\n \
    \   if (_leq(lhs.dat, rhs.dat)) {\n      // |l| <= |r|\n      auto c = _sub(rhs.dat,\
    \ lhs.dat);\n      bool n = _is_zero(c) ? false : rhs.neg;\n      return {n, c};\n\
    \    }\n    auto c = _sub(lhs.dat, rhs.dat);\n    bool n = _is_zero(c) ? false\
    \ : lhs.neg;\n    return {n, c};\n  }\n  friend M operator-(const M& lhs, const\
    \ M& rhs) { return lhs + (-rhs); }\n  friend M operator*(const M& lhs, const M&\
    \ rhs) {\n    auto c = _mul(lhs.dat, rhs.dat);\n    bool n = _is_zero(c) ? false\
    \ : (lhs.neg ^ rhs.neg);\n    return {n, c};\n  }\n\n  M& operator+=(const M&\
    \ rhs) { return (*this) = (*this) + rhs; }\n  M& operator-=(const M& rhs) { return\
    \ (*this) = (*this) - rhs; }\n  M& operator*=(const M& rhs) { return (*this) =\
    \ (*this) * rhs; }\n\n  M operator-() const {\n    if (is_zero()) return *this;\n\
    \    return {!neg, dat};\n  }\n  M operator+() const { return *this; }\n  friend\
    \ M abs(const M& m) { return {false, m.dat}; }\n  bool is_zero() const { return\
    \ _is_zero(dat); }\n\n  friend bool operator==(const M& lhs, const M& rhs) {\n\
    \    return lhs.neg == rhs.neg && lhs.dat == rhs.dat;\n  }\n  friend bool operator!=(const\
    \ M& lhs, const M& rhs) {\n    return lhs.neg != rhs.neg || lhs.dat != rhs.dat;\n\
    \  }\n  friend bool operator<(const M& lhs, const M& rhs) {\n    return lhs ==\
    \ rhs ? false : _neq_lt(lhs, rhs);\n  }\n  friend bool operator<=(const M& lhs,\
    \ const M& rhs) {\n    return lhs == rhs ? true : _neq_lt(lhs, rhs);\n  }\n  friend\
    \ bool operator>(const M& lhs, const M& rhs) {\n    return lhs == rhs ? false\
    \ : _neq_lt(rhs, lhs);\n  }\n  friend bool operator>=(const M& lhs, const M& rhs)\
    \ {\n    return lhs == rhs ? true : _neq_lt(rhs, lhs);\n  }\n\n  // 0 \u306E\u6642\
    \ 0 \u3092\u8FD4\u3059\n  int ctz() const {\n    if (dat.empty()) return 0;\n\
    \    int i = 0;\n    while (dat[i] == 0) i++;\n    return 32 * i + __builtin_ctzll(dat[i]);\n\
    \  }\n  M& operator<<=(int s) {\n    assert(s >= 0);\n    if (dat.empty()) return\
    \ *this;\n    int q = s / 32, r = s % 32;\n    dat.push_back(0);\n    if (r) {\n\
    \      for (int i = (int)dat.size() - 1; i >= 1; i--) {\n        dat[i] = (dat[i]\
    \ << r) | (dat[i - 1] >> (32 - r));\n      }\n      dat[0] <<= r;\n    }\n   \
    \ dat.insert(begin(dat), q, 0);\n    return *this;\n  }\n  M& operator>>=(int\
    \ s) {\n    assert(s >= 0);\n    int q = s / 32, r = s % 32;\n    if ((int)dat.size()\
    \ <= q) {\n      dat.clear();\n      return *this;\n    }\n    dat.erase(begin(dat),\
    \ begin(dat) + q);\n    if (r) {\n      for (int i = 0; i + 1 < (int)dat.size();\
    \ i++) {\n        dat[i] = (dat[i] >> r) | (dat[i + 1] << (32 - r));\n      }\n\
    \      dat.back() >>= r;\n    }\n    _shrink();\n    return *this;\n  }\n\n  friend\
    \ M gcd(M a, M b) {\n    a.neg = b.neg = false;\n    if(a.dat.empty()) return\
    \ b;\n    if(b.dat.empty()) return a;\n    int at = a.ctz(), bt = b.ctz();\n \
    \   a >>= at, b >>= bt;\n    if (a < b) swap(a, b);\n    while (!b.dat.empty())\
    \ {\n      a -= b;\n      a >>= a.ctz();\n      if (a < b) swap(a, b);\n    }\n\
    \    return a <<= min(at, bt);\n  }\n\n  string to_hex() const {\n    if (dat.empty())\
    \ return \"0\";\n    string res;\n    for (int i = 0; i < (int)dat.size(); i++)\
    \ {\n      u32 x = dat[i];\n      for (int j = 0; j < 8; j++) {\n        res.push_back(\"\
    0123456789ABCDEF\"[x & 15]);\n        x >>= 4;\n      }\n    }\n    while (res.back()\
    \ == '0') res.pop_back();\n    reverse(begin(res), end(res));\n    if (neg) res.insert(begin(res),\
    \ '-');\n    return res;\n  }\n\n private:\n  // size\n  int _size() const { return\
    \ dat.size(); }\n  // a == b\n  static bool _eq(const vector<u32>& a, const vector<u32>&\
    \ b) { return a == b; }\n  // a < b\n  static bool _lt(const vector<u32>& a, const\
    \ vector<u32>& b) {\n    if (a.size() != b.size()) return a.size() < b.size();\n\
    \    for (int i = a.size() - 1; i >= 0; i--) {\n      if (a[i] != b[i]) return\
    \ a[i] < b[i];\n    }\n    return false;\n  }\n  // a <= b\n  static bool _leq(const\
    \ vector<u32>& a, const vector<u32>& b) {\n    return _eq(a, b) || _lt(a, b);\n\
    \  }\n  // a < b (s.t. a != b)\n  static bool _neq_lt(const M& lhs, const M& rhs)\
    \ {\n    assert(lhs != rhs);\n    if (lhs.neg != rhs.neg) return lhs.neg;\n  \
    \  bool f = _lt(lhs.dat, rhs.dat);\n    if (f) return !lhs.neg;\n    return lhs.neg;\n\
    \  }\n  // a == 0\n  static bool _is_zero(const vector<u32>& a) { return a.empty();\
    \ }\n  // \u672B\u5C3E 0 \u3092\u524A\u9664\n  static void _shrink(vector<u32>&\
    \ a) {\n    while (a.size() && a.back() == 0) a.pop_back();\n  }\n  // \u672B\u5C3E\
    \ 0 \u3092\u524A\u9664\n  void _shrink() {\n    while (_size() && dat.back() ==\
    \ 0) dat.pop_back();\n  }\n  // a + b\n  static vector<u32> _add(const vector<u32>&\
    \ a, const vector<u32>& b) {\n    vector<u32> c(max(a.size(), b.size()) + 1);\n\
    \    int carry = 0;\n    for (int i = 0; i < (int)c.size(); i++) {\n      u64\
    \ s = carry;\n      carry = 0;\n      if (i < (int)a.size()) s += a[i];\n    \
    \  if (i < (int)b.size()) s += b[i];\n      if (s >= (1uLL << 32)) s -= 1uLL <<\
    \ 32, carry = 1;\n      c[i] = s;\n    }\n    _shrink(c);\n    return c;\n  }\n\
    \  // a - b\n  static vector<u32> _sub(const vector<u32>& a, const vector<u32>&\
    \ b) {\n    assert(_leq(b, a));\n    vector<u32> c{a};\n    i64 borrow = 0;\n\
    \    for (int i = 0; i < (int)a.size(); i++) {\n      if (i < (int)b.size()) borrow\
    \ += b[i];\n      i64 x = c[i] - borrow;\n      borrow = 0;\n      if (x < 0)\
    \ x += 1uLL << 32, borrow = 1;\n      c[i] = x;\n    }\n    assert(borrow == 0);\n\
    \    _shrink(c);\n    return c;\n  }\n  // a * b (fft)\n  static vector<u32> _mul(const\
    \ vector<u32>& a, const vector<u32>& b) {\n    if (a.empty() || b.empty()) return\
    \ {};\n    vector<int> a2(a.size() * 2), b2(b.size() * 2);\n    for (int i = 0;\
    \ i < (int)a.size(); i++) {\n      a2[i * 2 + 0] = a[i] & 65535;\n      a2[i *\
    \ 2 + 1] = a[i] >> 16;\n    }\n    for (int i = 0; i < (int)b.size(); i++) {\n\
    \      b2[i * 2 + 0] = b[i] & 65535;\n      b2[i * 2 + 1] = b[i] >> 16;\n    }\n\
    \    auto m = ArbitraryNTT::multiply_u128(a2, b2);\n    vector<u32> c;\n    c.reserve(a.size()\
    \ + b.size() + 3);\n    __uint128_t x = 0;\n    for (int i = 0;; i += 2) {\n \
    \     if (i >= (int)m.size() && x == 0) break;\n      if (i + 0 < (int)m.size())\
    \ x += m[i + 0];\n      if (i + 1 < (int)m.size()) x += m[i + 1] << 16;\n    \
    \  c.push_back(x & ((1uLL << 32) - 1));\n      x >>= 32;\n    }\n    _shrink(c);\n\
    \    return c;\n  }\n};\n\n}  // namespace BinaryBigIntImpl\n\nusing BinaryBigIntImpl::BinaryBigInt;\n"
  code: "\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <iostream>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \n#include \"../ntt/arbitrary-ntt.hpp\"\n\nnamespace BinaryBigIntImpl {\n\nusing\
    \ u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i64 = long long;\n\
    \n// 0 \u306F neg=false, dat={} \u3068\u3057\u3066\u6271\u3046\nstruct BinaryBigInt\
    \ {\n  using M = BinaryBigInt;\n  bool neg;\n  vector<u32> dat;\n\n  BinaryBigInt()\
    \ : neg(false), dat() {}\n\n  BinaryBigInt(bool _neg, const vector<u32>& _dat)\
    \ : neg(_neg), dat(_dat) {}\n\n  BinaryBigInt(const string& S, int base) : neg(false)\
    \ {\n    assert(base == 16);\n    int ie = -1;\n    if (S[0] == '-') neg = true,\
    \ ie++;\n    for (int r = S.size() - 1; r > ie; r -= 8) {\n      int l = max(r\
    \ - 8, ie);\n      u32 x = 0;\n      for (int i = l + 1; i <= r; i++) {\n    \
    \    int c = 0;\n        if ('0' <= S[i] and S[i] <= '9') {\n          c = S[i]\
    \ - '0';\n        } else if ('A' <= S[i] and S[i] <= 'F') {\n          c = S[i]\
    \ - 'A' + 10;\n        } else {\n          c = S[i] - 'a' + 10;\n        }\n \
    \       x = c + (x << 4);\n      }\n      dat.push_back(x);\n    }\n    _shrink();\n\
    \  }\n\n  friend M operator+(const M& lhs, const M& rhs) {\n    if (lhs.neg ==\
    \ rhs.neg) return {lhs.neg, _add(lhs.dat, rhs.dat)};\n    if (_leq(lhs.dat, rhs.dat))\
    \ {\n      // |l| <= |r|\n      auto c = _sub(rhs.dat, lhs.dat);\n      bool n\
    \ = _is_zero(c) ? false : rhs.neg;\n      return {n, c};\n    }\n    auto c =\
    \ _sub(lhs.dat, rhs.dat);\n    bool n = _is_zero(c) ? false : lhs.neg;\n    return\
    \ {n, c};\n  }\n  friend M operator-(const M& lhs, const M& rhs) { return lhs\
    \ + (-rhs); }\n  friend M operator*(const M& lhs, const M& rhs) {\n    auto c\
    \ = _mul(lhs.dat, rhs.dat);\n    bool n = _is_zero(c) ? false : (lhs.neg ^ rhs.neg);\n\
    \    return {n, c};\n  }\n\n  M& operator+=(const M& rhs) { return (*this) = (*this)\
    \ + rhs; }\n  M& operator-=(const M& rhs) { return (*this) = (*this) - rhs; }\n\
    \  M& operator*=(const M& rhs) { return (*this) = (*this) * rhs; }\n\n  M operator-()\
    \ const {\n    if (is_zero()) return *this;\n    return {!neg, dat};\n  }\n  M\
    \ operator+() const { return *this; }\n  friend M abs(const M& m) { return {false,\
    \ m.dat}; }\n  bool is_zero() const { return _is_zero(dat); }\n\n  friend bool\
    \ operator==(const M& lhs, const M& rhs) {\n    return lhs.neg == rhs.neg && lhs.dat\
    \ == rhs.dat;\n  }\n  friend bool operator!=(const M& lhs, const M& rhs) {\n \
    \   return lhs.neg != rhs.neg || lhs.dat != rhs.dat;\n  }\n  friend bool operator<(const\
    \ M& lhs, const M& rhs) {\n    return lhs == rhs ? false : _neq_lt(lhs, rhs);\n\
    \  }\n  friend bool operator<=(const M& lhs, const M& rhs) {\n    return lhs ==\
    \ rhs ? true : _neq_lt(lhs, rhs);\n  }\n  friend bool operator>(const M& lhs,\
    \ const M& rhs) {\n    return lhs == rhs ? false : _neq_lt(rhs, lhs);\n  }\n \
    \ friend bool operator>=(const M& lhs, const M& rhs) {\n    return lhs == rhs\
    \ ? true : _neq_lt(rhs, lhs);\n  }\n\n  // 0 \u306E\u6642 0 \u3092\u8FD4\u3059\
    \n  int ctz() const {\n    if (dat.empty()) return 0;\n    int i = 0;\n    while\
    \ (dat[i] == 0) i++;\n    return 32 * i + __builtin_ctzll(dat[i]);\n  }\n  M&\
    \ operator<<=(int s) {\n    assert(s >= 0);\n    if (dat.empty()) return *this;\n\
    \    int q = s / 32, r = s % 32;\n    dat.push_back(0);\n    if (r) {\n      for\
    \ (int i = (int)dat.size() - 1; i >= 1; i--) {\n        dat[i] = (dat[i] << r)\
    \ | (dat[i - 1] >> (32 - r));\n      }\n      dat[0] <<= r;\n    }\n    dat.insert(begin(dat),\
    \ q, 0);\n    return *this;\n  }\n  M& operator>>=(int s) {\n    assert(s >= 0);\n\
    \    int q = s / 32, r = s % 32;\n    if ((int)dat.size() <= q) {\n      dat.clear();\n\
    \      return *this;\n    }\n    dat.erase(begin(dat), begin(dat) + q);\n    if\
    \ (r) {\n      for (int i = 0; i + 1 < (int)dat.size(); i++) {\n        dat[i]\
    \ = (dat[i] >> r) | (dat[i + 1] << (32 - r));\n      }\n      dat.back() >>= r;\n\
    \    }\n    _shrink();\n    return *this;\n  }\n\n  friend M gcd(M a, M b) {\n\
    \    a.neg = b.neg = false;\n    if(a.dat.empty()) return b;\n    if(b.dat.empty())\
    \ return a;\n    int at = a.ctz(), bt = b.ctz();\n    a >>= at, b >>= bt;\n  \
    \  if (a < b) swap(a, b);\n    while (!b.dat.empty()) {\n      a -= b;\n     \
    \ a >>= a.ctz();\n      if (a < b) swap(a, b);\n    }\n    return a <<= min(at,\
    \ bt);\n  }\n\n  string to_hex() const {\n    if (dat.empty()) return \"0\";\n\
    \    string res;\n    for (int i = 0; i < (int)dat.size(); i++) {\n      u32 x\
    \ = dat[i];\n      for (int j = 0; j < 8; j++) {\n        res.push_back(\"0123456789ABCDEF\"\
    [x & 15]);\n        x >>= 4;\n      }\n    }\n    while (res.back() == '0') res.pop_back();\n\
    \    reverse(begin(res), end(res));\n    if (neg) res.insert(begin(res), '-');\n\
    \    return res;\n  }\n\n private:\n  // size\n  int _size() const { return dat.size();\
    \ }\n  // a == b\n  static bool _eq(const vector<u32>& a, const vector<u32>& b)\
    \ { return a == b; }\n  // a < b\n  static bool _lt(const vector<u32>& a, const\
    \ vector<u32>& b) {\n    if (a.size() != b.size()) return a.size() < b.size();\n\
    \    for (int i = a.size() - 1; i >= 0; i--) {\n      if (a[i] != b[i]) return\
    \ a[i] < b[i];\n    }\n    return false;\n  }\n  // a <= b\n  static bool _leq(const\
    \ vector<u32>& a, const vector<u32>& b) {\n    return _eq(a, b) || _lt(a, b);\n\
    \  }\n  // a < b (s.t. a != b)\n  static bool _neq_lt(const M& lhs, const M& rhs)\
    \ {\n    assert(lhs != rhs);\n    if (lhs.neg != rhs.neg) return lhs.neg;\n  \
    \  bool f = _lt(lhs.dat, rhs.dat);\n    if (f) return !lhs.neg;\n    return lhs.neg;\n\
    \  }\n  // a == 0\n  static bool _is_zero(const vector<u32>& a) { return a.empty();\
    \ }\n  // \u672B\u5C3E 0 \u3092\u524A\u9664\n  static void _shrink(vector<u32>&\
    \ a) {\n    while (a.size() && a.back() == 0) a.pop_back();\n  }\n  // \u672B\u5C3E\
    \ 0 \u3092\u524A\u9664\n  void _shrink() {\n    while (_size() && dat.back() ==\
    \ 0) dat.pop_back();\n  }\n  // a + b\n  static vector<u32> _add(const vector<u32>&\
    \ a, const vector<u32>& b) {\n    vector<u32> c(max(a.size(), b.size()) + 1);\n\
    \    int carry = 0;\n    for (int i = 0; i < (int)c.size(); i++) {\n      u64\
    \ s = carry;\n      carry = 0;\n      if (i < (int)a.size()) s += a[i];\n    \
    \  if (i < (int)b.size()) s += b[i];\n      if (s >= (1uLL << 32)) s -= 1uLL <<\
    \ 32, carry = 1;\n      c[i] = s;\n    }\n    _shrink(c);\n    return c;\n  }\n\
    \  // a - b\n  static vector<u32> _sub(const vector<u32>& a, const vector<u32>&\
    \ b) {\n    assert(_leq(b, a));\n    vector<u32> c{a};\n    i64 borrow = 0;\n\
    \    for (int i = 0; i < (int)a.size(); i++) {\n      if (i < (int)b.size()) borrow\
    \ += b[i];\n      i64 x = c[i] - borrow;\n      borrow = 0;\n      if (x < 0)\
    \ x += 1uLL << 32, borrow = 1;\n      c[i] = x;\n    }\n    assert(borrow == 0);\n\
    \    _shrink(c);\n    return c;\n  }\n  // a * b (fft)\n  static vector<u32> _mul(const\
    \ vector<u32>& a, const vector<u32>& b) {\n    if (a.empty() || b.empty()) return\
    \ {};\n    vector<int> a2(a.size() * 2), b2(b.size() * 2);\n    for (int i = 0;\
    \ i < (int)a.size(); i++) {\n      a2[i * 2 + 0] = a[i] & 65535;\n      a2[i *\
    \ 2 + 1] = a[i] >> 16;\n    }\n    for (int i = 0; i < (int)b.size(); i++) {\n\
    \      b2[i * 2 + 0] = b[i] & 65535;\n      b2[i * 2 + 1] = b[i] >> 16;\n    }\n\
    \    auto m = ArbitraryNTT::multiply_u128(a2, b2);\n    vector<u32> c;\n    c.reserve(a.size()\
    \ + b.size() + 3);\n    __uint128_t x = 0;\n    for (int i = 0;; i += 2) {\n \
    \     if (i >= (int)m.size() && x == 0) break;\n      if (i + 0 < (int)m.size())\
    \ x += m[i + 0];\n      if (i + 1 < (int)m.size()) x += m[i + 1] << 16;\n    \
    \  c.push_back(x & ((1uLL << 32) - 1));\n      x >>= 32;\n    }\n    _shrink(c);\n\
    \    return c;\n  }\n};\n\n}  // namespace BinaryBigIntImpl\n\nusing BinaryBigIntImpl::BinaryBigInt;\n"
  dependsOn:
  - ntt/arbitrary-ntt.hpp
  - modint/montgomery-modint.hpp
  - ntt/ntt.hpp
  isVerificationFile: false
  path: math/bigint-binary.hpp
  requiredBy: []
  timestamp: '2024-08-10 13:03:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-multiplication-of-hex.test.cpp
  - verify/verify-yosupo-math/yosupo-addition-of-hex.test.cpp
  - verify/verify-unit-test/bigint-gcd.test.cpp
documentation_of: math/bigint-binary.hpp
layout: document
redirect_from:
- /library/math/bigint-binary.hpp
- /library/math/bigint-binary.hpp.html
title: math/bigint-binary.hpp
---

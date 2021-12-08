---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/arbitrary-prime-modint.hpp
    title: modint/arbitrary-prime-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/mod-sqrt.hpp
    title: mod sqrt(Tonelli-Shanks algorithm)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulo/quadratic-equation.hpp\"\n\n#line 2 \"modint/arbitrary-prime-modint.hpp\"\
    \n\n\n\nstruct ArbitraryLazyMontgomeryModInt {\n  using mint = ArbitraryLazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static u32 mod;\n  static u32 r;\n  static u32 n2;\n\n  static u32 get_r()\
    \ {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n\
    \    return ret;\n  }\n\n  static void set_mod(u32 m) {\n    assert(m < (1 <<\
    \ 30));\n    assert((m & 1) == 1);\n    mod = m;\n    n2 = -u64(m) % m;\n    r\
    \ = get_r();\n    assert(r * mod == 1);\n  }\n\n  u32 a;\n\n  ArbitraryLazyMontgomeryModInt()\
    \ : a(0) {}\n  ArbitraryLazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
    \ % mod + mod) * n2)){};\n\n  static u32 reduce(const u64 &b) {\n    return (b\
    \ + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  mint &operator+=(const mint\
    \ &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  mint &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2\
    \ * mod;\n    return *this;\n  }\n\n  mint &operator*=(const mint &b) {\n    a\
    \ = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint &operator/=(const\
    \ mint &b) {\n    *this *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const\
    \ mint &b) const { return mint(*this) += b; }\n  mint operator-(const mint &b)\
    \ const { return mint(*this) -= b; }\n  mint operator*(const mint &b) const {\
    \ return mint(*this) *= b; }\n  mint operator/(const mint &b) const { return mint(*this)\
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
    \  if (a < 2) return a;\n  using Mint = ArbitraryLazyMontgomeryModInt;\n  Mint::set_mod(p);\n\
    \  if (Mint(a).pow((p - 1) >> 1) != 1) return -1;\n  Mint b = 1, one = 1;\n  while\
    \ (b.pow((p - 1) >> 1) == 1) b += one;\n  int64_t m = p - 1, e = 0;\n  while (m\
    \ % 2 == 0) m >>= 1, e += 1;\n  Mint x = Mint(a).pow((m - 1) >> 1);\n  Mint y\
    \ = Mint(a) * x * x;\n  x *= a;\n  Mint z = Mint(b).pow(m);\n  while (y != 1)\
    \ {\n    int64_t j = 0;\n    Mint t = y;\n    while (t != one) {\n      j += 1;\n\
    \      t *= t;\n    }\n    z = z.pow(int64_t(1) << (e - j - 1));\n    x *= z;\n\
    \    z *= z;\n    y *= z;\n    e = j;\n  }\n  return x.get();\n}\n\n/**\n * @brief\
    \ mod sqrt(Tonelli-Shanks algorithm)\n * @docs docs/modulo/mod-sqrt.md\n */\n\
    #line 4 \"modulo/quadratic-equation.hpp\"\n\ntemplate <typename mint>\nvector<mint>\
    \ QuadraticEquation(mint a, mint b, mint c) {\n  assert(mint::get_mod() % 2 !=\
    \ 0);\n  if (a == mint()) {\n    if(b == mint()) {\n      assert(c != mint());\n\
    \      return {};\n    }\n    return vector<mint>{-c * b.inverse()};\n  }\n  mint\
    \ ia = a.inverse(), inv2 = mint(2).inverse();\n  b *= ia, c *= ia;\n  auto D =\
    \ mod_sqrt(((b * inv2).pow(2) - c).get(), mint::get_mod());\n  if(D == -1) return\
    \ {};\n  if(D <= 1) return vector<mint>{-b * inv2 + D};\n  return vector<mint>{-b\
    \ * inv2 + D, -b * inv2 - D};\n}\n"
  code: "#pragma once\n\n#include \"mod-sqrt.hpp\"\n\ntemplate <typename mint>\nvector<mint>\
    \ QuadraticEquation(mint a, mint b, mint c) {\n  assert(mint::get_mod() % 2 !=\
    \ 0);\n  if (a == mint()) {\n    if(b == mint()) {\n      assert(c != mint());\n\
    \      return {};\n    }\n    return vector<mint>{-c * b.inverse()};\n  }\n  mint\
    \ ia = a.inverse(), inv2 = mint(2).inverse();\n  b *= ia, c *= ia;\n  auto D =\
    \ mod_sqrt(((b * inv2).pow(2) - c).get(), mint::get_mod());\n  if(D == -1) return\
    \ {};\n  if(D <= 1) return vector<mint>{-b * inv2 + D};\n  return vector<mint>{-b\
    \ * inv2 + D, -b * inv2 - D};\n}\n"
  dependsOn:
  - modulo/mod-sqrt.hpp
  - modint/arbitrary-prime-modint.hpp
  isVerificationFile: false
  path: modulo/quadratic-equation.hpp
  requiredBy: []
  timestamp: '2021-03-03 00:28:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modulo/quadratic-equation.hpp
layout: document
redirect_from:
- /library/modulo/quadratic-equation.hpp
- /library/modulo/quadratic-equation.hpp.html
title: modulo/quadratic-equation.hpp
---

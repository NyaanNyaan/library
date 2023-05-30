---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-montgomery-modint.hpp
    title: modint/arbitrary-montgomery-modint.hpp
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
  bundledCode: "#line 2 \"modulo/quadratic-equation.hpp\"\n\n#line 2 \"modint/arbitrary-montgomery-modint.hpp\"\
    \n\n#include <iostream>\nusing namespace std;\n\ntemplate <typename Int, typename\
    \ UInt, typename Long, typename ULong, int id>\nstruct ArbitraryLazyMontgomeryModIntBase\
    \ {\n  using mint = ArbitraryLazyMontgomeryModIntBase;\n\n  inline static UInt\
    \ mod;\n  inline static UInt r;\n  inline static UInt n2;\n  static constexpr\
    \ int bit_length = sizeof(UInt) * 8;\n\n  static UInt get_r() {\n    UInt ret\
    \ = mod;\n    while (mod * ret != 1) ret *= UInt(2) - mod * ret;\n    return ret;\n\
    \  }\n  static void set_mod(UInt m) {\n    assert(m < (UInt(1u) << (bit_length\
    \ - 2)));\n    assert((m & 1) == 1);\n    mod = m, n2 = -ULong(m) % m, r = get_r();\n\
    \  }\n  UInt a;\n\n  ArbitraryLazyMontgomeryModIntBase() : a(0) {}\n  ArbitraryLazyMontgomeryModIntBase(const\
    \ Long &b)\n      : a(reduce(ULong(b % mod + mod) * n2)){};\n\n  static UInt reduce(const\
    \ ULong &b) {\n    return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;\n\
    \  }\n\n  mint &operator+=(const mint &b) {\n    if (Int(a += b.a - 2 * mod) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n  mint &operator-=(const mint &b)\
    \ {\n    if (Int(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n  mint\
    \ &operator*=(const mint &b) {\n    a = reduce(ULong(a) * b.a);\n    return *this;\n\
    \  }\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return\
    \ *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n \
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n\n  bool operator==(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const\
    \ { return mint(0) - mint(*this); }\n  mint operator+() const { return mint(*this);\
    \ }\n\n  mint pow(ULong n) const {\n    mint ret(1), mul(*this);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n  \
    \  return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    Long t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModIntBase(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const {\n    Int x = get(), y = get_mod(),\
    \ u = 1, v = 0;\n    while (y > 0) {\n      Int t = x / y;\n      swap(x -= t\
    \ * y, y);\n      swap(u -= t * v, v);\n    }\n    return mint{u};\n  }\n\n  UInt\
    \ get() const {\n    UInt ret = reduce(a);\n    return ret >= mod ? ret - mod\
    \ : ret;\n  }\n\n  static UInt get_mod() { return mod; }\n};\n\n// id \u306B\u9069\
    \u5F53\u306A\u4E71\u6570\u3092\u5272\u308A\u5F53\u3066\u3066\u4F7F\u3046\ntemplate\
    \ <int id>\nusing ArbitraryLazyMontgomeryModInt =\n    ArbitraryLazyMontgomeryModIntBase<int,\
    \ unsigned int, long long,\n                                      unsigned long\
    \ long, id>;\ntemplate <int id>\nusing ArbitraryLazyMontgomeryModInt64bit =\n\
    \    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,\n\
    \                                      __uint128_t, id>;\n#line 3 \"modulo/mod-sqrt.hpp\"\
    \n\nint64_t mod_sqrt(const int64_t &a, const int64_t &p) {\n  assert(0 <= a &&\
    \ a < p);\n  if (a < 2) return a;\n  using Mint = ArbitraryLazyMontgomeryModInt<409075245>;\n\
    \  Mint::set_mod(p);\n  if (Mint(a).pow((p - 1) >> 1) != 1) return -1;\n  Mint\
    \ b = 1, one = 1;\n  while (b.pow((p - 1) >> 1) == 1) b += one;\n  int64_t m =\
    \ p - 1, e = 0;\n  while (m % 2 == 0) m >>= 1, e += 1;\n  Mint x = Mint(a).pow((m\
    \ - 1) >> 1);\n  Mint y = Mint(a) * x * x;\n  x *= a;\n  Mint z = Mint(b).pow(m);\n\
    \  while (y != 1) {\n    int64_t j = 0;\n    Mint t = y;\n    while (t != one)\
    \ {\n      j += 1;\n      t *= t;\n    }\n    z = z.pow(int64_t(1) << (e - j -\
    \ 1));\n    x *= z;\n    z *= z;\n    y *= z;\n    e = j;\n  }\n  return x.get();\n\
    }\n\n/**\n * @brief mod sqrt(Tonelli-Shanks algorithm)\n * @docs docs/modulo/mod-sqrt.md\n\
    \ */\n#line 4 \"modulo/quadratic-equation.hpp\"\n\ntemplate <typename mint>\n\
    vector<mint> QuadraticEquation(mint a, mint b, mint c) {\n  assert(mint::get_mod()\
    \ % 2 != 0);\n  if (a == mint()) {\n    if(b == mint()) {\n      assert(c != mint());\n\
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
  - modint/arbitrary-montgomery-modint.hpp
  isVerificationFile: false
  path: modulo/quadratic-equation.hpp
  requiredBy: []
  timestamp: '2023-05-29 20:16:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modulo/quadratic-equation.hpp
layout: document
redirect_from:
- /library/modulo/quadratic-equation.hpp
- /library/modulo/quadratic-equation.hpp.html
title: modulo/quadratic-equation.hpp
---

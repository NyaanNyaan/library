---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/modint-cpp11.hpp\"\n\nnamespace modint998244353 {\n\
    using i32 = int32_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nconstexpr\
    \ u32 mod = 998244353;\nconstexpr u32 r = 3296722945u;\nconstexpr u32 n2 = 932051910;\n\
    static_assert(r * mod == 1, \"invalid, r * mod != 1\");\nstatic_assert(mod < (1\
    \ << 30), \"invalid, mod >= 2 ^ 30\");\nstatic_assert((mod & 1) == 1, \"invalid,\
    \ mod % 2 == 0\");\n\nstruct MontgomeryModInt998244353 {\n  using mint = MontgomeryModInt998244353;\n\
    \n  u32 a;\n\n  MontgomeryModInt998244353() : a(0) {}\n  MontgomeryModInt998244353(const\
    \ int64_t &b)\n      : a(reduce(u64(b % mod + mod) * n2)){};\n\n  static u32 reduce(const\
    \ u64 &b) {\n    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  mint\
    \ &operator+=(const mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 *\
    \ mod;\n    return *this;\n  }\n\n  mint &operator-=(const mint &b) {\n    if\
    \ (i32(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint\
    \ &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  mint operator+(const mint &b) const { return mint(*this) += b; }\n \
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  mint operator*(const\
    \ mint &b) const { return mint(*this) *= b; }\n  mint operator/(const mint &b)\
    \ const { return mint(*this) /= b; }\n  bool operator==(const mint &b) const {\n\
    \    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n\
    \  bool operator!=(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const { return mint()\
    \ - mint(*this); }\n\n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n\n  mint inverse() const { return pow(mod\
    \ - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b) {\n    return\
    \ os << b.get();\n  }\n\n  friend istream &operator>>(istream &is, mint &b) {\n\
    \    int64_t t;\n    is >> t;\n    b = mint(t);\n    return (is);\n  }\n\n  u32\
    \ get() const {\n    u32 ret = reduce(a);\n    return ret >= mod ? ret - mod :\
    \ ret;\n  }\n\n  static constexpr u32 get_mod() { return mod; }\n};\n\n}  // namespace\
    \ modint998244353\nusing modint998244353::MontgomeryModInt998244353;\n"
  code: "#pragma once\n\nnamespace modint998244353 {\nusing i32 = int32_t;\nusing\
    \ u32 = uint32_t;\nusing u64 = uint64_t;\nconstexpr u32 mod = 998244353;\nconstexpr\
    \ u32 r = 3296722945u;\nconstexpr u32 n2 = 932051910;\nstatic_assert(r * mod ==\
    \ 1, \"invalid, r * mod != 1\");\nstatic_assert(mod < (1 << 30), \"invalid, mod\
    \ >= 2 ^ 30\");\nstatic_assert((mod & 1) == 1, \"invalid, mod % 2 == 0\");\n\n\
    struct MontgomeryModInt998244353 {\n  using mint = MontgomeryModInt998244353;\n\
    \n  u32 a;\n\n  MontgomeryModInt998244353() : a(0) {}\n  MontgomeryModInt998244353(const\
    \ int64_t &b)\n      : a(reduce(u64(b % mod + mod) * n2)){};\n\n  static u32 reduce(const\
    \ u64 &b) {\n    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  mint\
    \ &operator+=(const mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 *\
    \ mod;\n    return *this;\n  }\n\n  mint &operator-=(const mint &b) {\n    if\
    \ (i32(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint\
    \ &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  mint operator+(const mint &b) const { return mint(*this) += b; }\n \
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  mint operator*(const\
    \ mint &b) const { return mint(*this) *= b; }\n  mint operator/(const mint &b)\
    \ const { return mint(*this) /= b; }\n  bool operator==(const mint &b) const {\n\
    \    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n\
    \  bool operator!=(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const { return mint()\
    \ - mint(*this); }\n\n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n\n  mint inverse() const { return pow(mod\
    \ - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b) {\n    return\
    \ os << b.get();\n  }\n\n  friend istream &operator>>(istream &is, mint &b) {\n\
    \    int64_t t;\n    is >> t;\n    b = mint(t);\n    return (is);\n  }\n\n  u32\
    \ get() const {\n    u32 ret = reduce(a);\n    return ret >= mod ? ret - mod :\
    \ ret;\n  }\n\n  static constexpr u32 get_mod() { return mod; }\n};\n\n}  // namespace\
    \ modint998244353\nusing modint998244353::MontgomeryModInt998244353;"
  dependsOn: []
  isVerificationFile: false
  path: modint/modint-cpp11.hpp
  requiredBy: []
  timestamp: '2021-03-04 10:35:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modint/modint-cpp11.hpp
layout: document
redirect_from:
- /library/modint/modint-cpp11.hpp
- /library/modint/modint-cpp11.hpp.html
title: modint/modint-cpp11.hpp
---

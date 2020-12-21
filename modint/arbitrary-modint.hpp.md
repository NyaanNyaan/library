---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/arbitrary-modint.hpp\"\n\n\n\nstruct ArbitraryModInt\
    \ {\n  int x;\n\n  ArbitraryModInt() : x(0) {}\n\n  ArbitraryModInt(int64_t y)\n\
    \      : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod())\
    \ {\n  }\n\n  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {\n    if\
    \ ((x += p.x) >= get_mod()) x -= get_mod();\n    return *this;\n  }\n\n  ArbitraryModInt\
    \ &operator-=(const ArbitraryModInt &p) {\n    if ((x += get_mod() - p.x) >= get_mod())\
    \ x -= get_mod();\n    return *this;\n  }\n\n  ArbitraryModInt &operator*=(const\
    \ ArbitraryModInt &p) {\n    unsigned long long a = (unsigned long long)x * p.x;\n\
    \    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;\n    asm(\"divl\
    \ %4; \\n\\t\" : \"=a\"(d), \"=d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n\
    \    x = m;\n    return *this;\n  }\n\n  ArbitraryModInt &operator/=(const ArbitraryModInt\
    \ &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n\n  ArbitraryModInt\
    \ operator-() const { return ArbitraryModInt(-x); }\n\n  ArbitraryModInt operator+(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n\n\
    \  ArbitraryModInt operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ -= p;\n  }\n\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) *= p;\n  }\n\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) /= p;\n  }\n\n\
    \  bool operator==(const ArbitraryModInt &p) const { return x == p.x; }\n\n  bool\
    \ operator!=(const ArbitraryModInt &p) const { return x != p.x; }\n\n  ArbitraryModInt\
    \ inverse() const {\n    int a = x, b = get_mod(), u = 1, v = 0, t;\n    while\
    \ (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t *\
    \ v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n\n  ArbitraryModInt pow(int64_t\
    \ n) const {\n    ArbitraryModInt ret(1), mul(x);\n    while (n > 0) {\n     \
    \ if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const ArbitraryModInt\
    \ &p) {\n    return os << p.x;\n  }\n\n  friend istream &operator>>(istream &is,\
    \ ArbitraryModInt &a) {\n    int64_t t;\n    is >> t;\n    a = ArbitraryModInt(t);\n\
    \    return (is);\n  }\n\n  int get() const { return x; }\n\n  static int &get_mod()\
    \ {\n    static int mod = 0;\n    return mod;\n  }\n\n  static void set_mod(int\
    \ md) { get_mod() = md; }\n};\n"
  code: "#pragma once\n\n\n\nstruct ArbitraryModInt {\n  int x;\n\n  ArbitraryModInt()\
    \ : x(0) {}\n\n  ArbitraryModInt(int64_t y)\n      : x(y >= 0 ? y % get_mod()\
    \ : (get_mod() - (-y) % get_mod()) % get_mod()) {\n  }\n\n  ArbitraryModInt &operator+=(const\
    \ ArbitraryModInt &p) {\n    if ((x += p.x) >= get_mod()) x -= get_mod();\n  \
    \  return *this;\n  }\n\n  ArbitraryModInt &operator-=(const ArbitraryModInt &p)\
    \ {\n    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();\n    return\
    \ *this;\n  }\n\n  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {\n \
    \   unsigned long long a = (unsigned long long)x * p.x;\n    unsigned xh = (unsigned)(a\
    \ >> 32), xl = (unsigned)a, d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"\
    =d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n    x = m;\n    return *this;\n\
    \  }\n\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n\n  ArbitraryModInt operator-() const\
    \ { return ArbitraryModInt(-x); }\n\n  ArbitraryModInt operator+(const ArbitraryModInt\
    \ &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n\n  ArbitraryModInt\
    \ operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ -= p;\n  }\n\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) *= p;\n  }\n\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) /= p;\n  }\n\n\
    \  bool operator==(const ArbitraryModInt &p) const { return x == p.x; }\n\n  bool\
    \ operator!=(const ArbitraryModInt &p) const { return x != p.x; }\n\n  ArbitraryModInt\
    \ inverse() const {\n    int a = x, b = get_mod(), u = 1, v = 0, t;\n    while\
    \ (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n      swap(u -= t *\
    \ v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n\n  ArbitraryModInt pow(int64_t\
    \ n) const {\n    ArbitraryModInt ret(1), mul(x);\n    while (n > 0) {\n     \
    \ if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const ArbitraryModInt\
    \ &p) {\n    return os << p.x;\n  }\n\n  friend istream &operator>>(istream &is,\
    \ ArbitraryModInt &a) {\n    int64_t t;\n    is >> t;\n    a = ArbitraryModInt(t);\n\
    \    return (is);\n  }\n\n  int get() const { return x; }\n\n  static int &get_mod()\
    \ {\n    static int mod = 0;\n    return mod;\n  }\n\n  static void set_mod(int\
    \ md) { get_mod() = md; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: modint/arbitrary-modint.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp
documentation_of: modint/arbitrary-modint.hpp
layout: document
redirect_from:
- /library/modint/arbitrary-modint.hpp
- /library/modint/arbitrary-modint.hpp.html
title: modint/arbitrary-modint.hpp
---

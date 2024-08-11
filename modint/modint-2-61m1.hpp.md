---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/modint-2-61m1.test.cpp
    title: verify/verify-unit-test/modint-2-61m1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/modint-2-61m1.hpp\"\n\n#include <cassert>\n#include\
    \ <ostream>\nusing namespace std;\n\nstruct modint_2_61m1 {\n  using M = modint_2_61m1;\n\
    \  using u64 = unsigned long long;\n  using u128 = __uint128_t;\n\n  static constexpr\
    \ u64 mod = (1uLL << 61) - 1;\n  u64 x;\n\n  static constexpr u64 modulo(u128\
    \ y) {\n    u64 val = (y >> 61) + (y & mod);\n    return val >= mod ? val - mod\
    \ : val;\n  }\n\n  modint_2_61m1() : x(0) {}\n  modint_2_61m1(long long _x) {\n\
    \    long long y = _x % (long long)mod;\n    if (y < 0) y += mod;\n    x = y;\n\
    \  }\n\n  static M raw(u64 y) {\n    M res;\n    res.x = y;\n    return res;\n\
    \  }\n  u64 get() const { return x; }\n  static u64 get_mod() { return mod; }\n\
    \n  friend M operator+(const M& l, const M& r) {\n    u64 y = l.x + r.x;\n   \
    \ if (y >= mod) y -= mod;\n    return raw(y);\n  }\n  friend M operator-(const\
    \ M& l, const M& r) {\n    u64 y = l.x - r.x;\n    if (y >= mod) y += mod;\n \
    \   return raw(y);\n  }\n  friend M operator*(const M& l, const M& r) {\n    return\
    \ raw(modulo(u128(l.x) * r.x));\n  }\n  friend M operator/(const M& l, const M&\
    \ r) { return l * r.inverse(); }\n\n  M& operator+=(const M& r) { return *this\
    \ = *this + r; }\n  M& operator-=(const M& r) { return *this = *this - r; }\n\
    \  M& operator*=(const M& r) { return *this = *this * r; }\n  M& operator/=(const\
    \ M& r) { return *this = *this / r; }\n  M operator-() const { return raw(x ?\
    \ mod - x : u64{0}); }\n  M operator+() const { return *this; }\n\n  M pow(u64\
    \ e) const {\n    M res{1}, a{*this};\n    while (e) {\n      if (e & 1) res =\
    \ res * a;\n      a = a * a;\n      e >>= 1;\n    }\n    return res;\n  }\n  M\
    \ inverse() const {\n    assert(x != 0);\n    return this->pow(mod - 2);\n  }\n\
    \n  friend bool operator==(const M& l, const M& r) { return l.x == r.x; }\n  friend\
    \ bool operator!=(const M& l, const M& r) { return l.x != r.x; }\n  friend ostream&\
    \ operator<<(ostream& os, const M& r) { return os << r.x; }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <ostream>\nusing namespace std;\n\
    \nstruct modint_2_61m1 {\n  using M = modint_2_61m1;\n  using u64 = unsigned long\
    \ long;\n  using u128 = __uint128_t;\n\n  static constexpr u64 mod = (1uLL <<\
    \ 61) - 1;\n  u64 x;\n\n  static constexpr u64 modulo(u128 y) {\n    u64 val =\
    \ (y >> 61) + (y & mod);\n    return val >= mod ? val - mod : val;\n  }\n\n  modint_2_61m1()\
    \ : x(0) {}\n  modint_2_61m1(long long _x) {\n    long long y = _x % (long long)mod;\n\
    \    if (y < 0) y += mod;\n    x = y;\n  }\n\n  static M raw(u64 y) {\n    M res;\n\
    \    res.x = y;\n    return res;\n  }\n  u64 get() const { return x; }\n  static\
    \ u64 get_mod() { return mod; }\n\n  friend M operator+(const M& l, const M& r)\
    \ {\n    u64 y = l.x + r.x;\n    if (y >= mod) y -= mod;\n    return raw(y);\n\
    \  }\n  friend M operator-(const M& l, const M& r) {\n    u64 y = l.x - r.x;\n\
    \    if (y >= mod) y += mod;\n    return raw(y);\n  }\n  friend M operator*(const\
    \ M& l, const M& r) {\n    return raw(modulo(u128(l.x) * r.x));\n  }\n  friend\
    \ M operator/(const M& l, const M& r) { return l * r.inverse(); }\n\n  M& operator+=(const\
    \ M& r) { return *this = *this + r; }\n  M& operator-=(const M& r) { return *this\
    \ = *this - r; }\n  M& operator*=(const M& r) { return *this = *this * r; }\n\
    \  M& operator/=(const M& r) { return *this = *this / r; }\n  M operator-() const\
    \ { return raw(x ? mod - x : u64{0}); }\n  M operator+() const { return *this;\
    \ }\n\n  M pow(u64 e) const {\n    M res{1}, a{*this};\n    while (e) {\n    \
    \  if (e & 1) res = res * a;\n      a = a * a;\n      e >>= 1;\n    }\n    return\
    \ res;\n  }\n  M inverse() const {\n    assert(x != 0);\n    return this->pow(mod\
    \ - 2);\n  }\n\n  friend bool operator==(const M& l, const M& r) { return l.x\
    \ == r.x; }\n  friend bool operator!=(const M& l, const M& r) { return l.x !=\
    \ r.x; }\n  friend ostream& operator<<(ostream& os, const M& r) { return os <<\
    \ r.x; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/modint-2-61m1.hpp
  requiredBy: []
  timestamp: '2024-08-10 13:03:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/modint-2-61m1.test.cpp
documentation_of: modint/modint-2-61m1.hpp
layout: document
redirect_from:
- /library/modint/modint-2-61m1.hpp
- /library/modint/modint-2-61m1.hpp.html
title: modint/modint-2-61m1.hpp
---

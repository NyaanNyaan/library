---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2883.test.cpp
    title: verify/verify-yuki/yuki-2883.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/adjunction-modint.hpp\"\n\n// a + b sqrt(B)\ntemplate\
    \ <typename mint, long long B>\nstruct Adjunction {\n  using A = Adjunction;\n\
    \  mint a, b;\n  Adjunction(mint _a = 0, mint _b = 0) : a(_a), b(_b) {}\n  Adjunction(long\
    \ long x) : a(x), b(0) {}\n  friend A operator+(const A& l, const A& r) { return\
    \ {l.a + r.a, l.b + r.b}; }\n  friend A operator-(const A& l, const A& r) { return\
    \ {l.a - r.a, l.b - r.b}; }\n  friend A operator*(const A& l, const A& r) {\n\
    \    return {l.a * r.a + l.b * r.b * B, l.a * r.b + l.b * r.a};\n  }\n  friend\
    \ A operator/(const A& l, const A& r) { return l * r.inverse(); }\n\n  A& operator+=(const\
    \ A& r) { return (*this) = (*this) + r; }\n  A& operator-=(const A& r) { return\
    \ (*this) = (*this) - r; }\n  A& operator*=(const A& r) { return (*this) = (*this)\
    \ * r; }\n  A& operator/=(const A& r) { return (*this) = (*this) / r; }\n  A operator-()\
    \ const { return {-a, -b}; }\n  A operator+() const { return *this; }\n\n  A inverse()\
    \ const {\n    mint c = (a * a - b * b * B).inverse();\n    return {a * c, -b\
    \ * c};\n  }\n  A pow(__int128_t e) const {\n    A res{1}, c{*this};\n    while\
    \ (e) {\n      if (e & 1) res = res * c;\n      c *= c;\n      e >>= 1;\n    }\n\
    \    return res;\n  }\n\n  bool operator==(const A& r) const { return a == r.a\
    \ && b == r.b; }\n  bool operator!=(const A& r) const { return a != r.a || b !=\
    \ r.b; }\n  friend ostream& operator<<(ostream& os, const A& rhs) {\n    return\
    \ os << rhs.a << \" \" << rhs.b;\n  }\n};\n"
  code: "#pragma once\n\n// a + b sqrt(B)\ntemplate <typename mint, long long B>\n\
    struct Adjunction {\n  using A = Adjunction;\n  mint a, b;\n  Adjunction(mint\
    \ _a = 0, mint _b = 0) : a(_a), b(_b) {}\n  Adjunction(long long x) : a(x), b(0)\
    \ {}\n  friend A operator+(const A& l, const A& r) { return {l.a + r.a, l.b +\
    \ r.b}; }\n  friend A operator-(const A& l, const A& r) { return {l.a - r.a, l.b\
    \ - r.b}; }\n  friend A operator*(const A& l, const A& r) {\n    return {l.a *\
    \ r.a + l.b * r.b * B, l.a * r.b + l.b * r.a};\n  }\n  friend A operator/(const\
    \ A& l, const A& r) { return l * r.inverse(); }\n\n  A& operator+=(const A& r)\
    \ { return (*this) = (*this) + r; }\n  A& operator-=(const A& r) { return (*this)\
    \ = (*this) - r; }\n  A& operator*=(const A& r) { return (*this) = (*this) * r;\
    \ }\n  A& operator/=(const A& r) { return (*this) = (*this) / r; }\n  A operator-()\
    \ const { return {-a, -b}; }\n  A operator+() const { return *this; }\n\n  A inverse()\
    \ const {\n    mint c = (a * a - b * b * B).inverse();\n    return {a * c, -b\
    \ * c};\n  }\n  A pow(__int128_t e) const {\n    A res{1}, c{*this};\n    while\
    \ (e) {\n      if (e & 1) res = res * c;\n      c *= c;\n      e >>= 1;\n    }\n\
    \    return res;\n  }\n\n  bool operator==(const A& r) const { return a == r.a\
    \ && b == r.b; }\n  bool operator!=(const A& r) const { return a != r.a || b !=\
    \ r.b; }\n  friend ostream& operator<<(ostream& os, const A& rhs) {\n    return\
    \ os << rhs.a << \" \" << rhs.b;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/adjunction-modint.hpp
  requiredBy: []
  timestamp: '2024-09-14 20:40:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-2883.test.cpp
documentation_of: modint/adjunction-modint.hpp
layout: document
redirect_from:
- /library/modint/adjunction-modint.hpp
- /library/modint/adjunction-modint.hpp.html
title: modint/adjunction-modint.hpp
---

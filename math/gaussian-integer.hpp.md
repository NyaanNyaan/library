---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/two-square.hpp
    title: math/two-square.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/enumerate-convex.test.cpp
    title: verify/verify-unit-test/enumerate-convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-gcd-of-gaussian-integer.test.cpp
    title: verify/verify-yosupo-math/yosupo-gcd-of-gaussian-integer.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-two-square-sum.test.cpp
    title: verify/verify-yosupo-math/yosupo-two-square-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/gaussian-integer.hpp\"\n\n// x + yi\ntemplate <typename\
    \ T>\nstruct Gaussian_Integer {\n  T x, y;\n  using G = Gaussian_Integer;\n\n\
    \  Gaussian_Integer(T _x = 0, T _y = 0) : x(_x), y(_y) {}\n  Gaussian_Integer(const\
    \ pair<T, T>& p) : x(p.fi), y(p.se) {}\n\n  T norm() const { return x * x + y\
    \ * y; }\n  G conj() const { return G{x, -y}; }\n\n  G operator+(const G& r) const\
    \ { return G{x + r.x, y + r.y}; }\n  G operator-(const G& r) const { return G{x\
    \ - r.x, y - r.y}; }\n  G operator*(const G& r) const {\n    return G{x * r.x\
    \ - y * r.y, x * r.y + y * r.x};\n  }\n  G operator/(const G& r) const {\n   \
    \ G g = G{*this} * r.conj();\n    T n = r.norm();\n    g.x += n / 2, g.y += n\
    \ / 2;\n    return G{g.x / n - (g.x % n < 0), g.y / n - (g.y % n < 0)};\n  }\n\
    \  G operator%(const G& r) const { return G{*this} - G{*this} / r * r; }\n\n \
    \ G& operator+=(const G& r) { return *this = G{*this} + r; }\n  G& operator-=(const\
    \ G& r) { return *this = G{*this} - r; }\n  G& operator*=(const G& r) { return\
    \ *this = G{*this} * r; }\n  G& operator/=(const G& r) { return *this = G{*this}\
    \ / r; }\n  G& operator%=(const G& r) { return *this = G{*this} % r; }\n  G operator-()\
    \ const { return G{-x, -y}; }\n  G operator+() const { return G{*this}; }\n  bool\
    \ operator==(const G& g) const { return x == g.x && y == g.y; }\n  bool operator!=(const\
    \ G& g) const { return x != g.x || y != g.y; }\n\n  G pow(__int128_t e) const\
    \ {\n    G res{1}, a{*this};\n    while (e) {\n      if (e & 1) res *= a;\n  \
    \    a *= a, e >>= 1;\n    }\n    return res;\n  }\n\n  friend G gcd(G a, G b)\
    \ {\n    while (b != G{0, 0}) {\n      trc(a, b, a / b, a % b);\n      swap(a\
    \ %= b, b);\n    }\n    return a;\n  }\n  friend ostream& operator<<(ostream&\
    \ os, const G& rhs) {\n    return os << rhs.x << \" \" << rhs.y;\n  }\n};\n"
  code: "#pragma once\n\n// x + yi\ntemplate <typename T>\nstruct Gaussian_Integer\
    \ {\n  T x, y;\n  using G = Gaussian_Integer;\n\n  Gaussian_Integer(T _x = 0,\
    \ T _y = 0) : x(_x), y(_y) {}\n  Gaussian_Integer(const pair<T, T>& p) : x(p.fi),\
    \ y(p.se) {}\n\n  T norm() const { return x * x + y * y; }\n  G conj() const {\
    \ return G{x, -y}; }\n\n  G operator+(const G& r) const { return G{x + r.x, y\
    \ + r.y}; }\n  G operator-(const G& r) const { return G{x - r.x, y - r.y}; }\n\
    \  G operator*(const G& r) const {\n    return G{x * r.x - y * r.y, x * r.y +\
    \ y * r.x};\n  }\n  G operator/(const G& r) const {\n    G g = G{*this} * r.conj();\n\
    \    T n = r.norm();\n    g.x += n / 2, g.y += n / 2;\n    return G{g.x / n -\
    \ (g.x % n < 0), g.y / n - (g.y % n < 0)};\n  }\n  G operator%(const G& r) const\
    \ { return G{*this} - G{*this} / r * r; }\n\n  G& operator+=(const G& r) { return\
    \ *this = G{*this} + r; }\n  G& operator-=(const G& r) { return *this = G{*this}\
    \ - r; }\n  G& operator*=(const G& r) { return *this = G{*this} * r; }\n  G& operator/=(const\
    \ G& r) { return *this = G{*this} / r; }\n  G& operator%=(const G& r) { return\
    \ *this = G{*this} % r; }\n  G operator-() const { return G{-x, -y}; }\n  G operator+()\
    \ const { return G{*this}; }\n  bool operator==(const G& g) const { return x ==\
    \ g.x && y == g.y; }\n  bool operator!=(const G& g) const { return x != g.x ||\
    \ y != g.y; }\n\n  G pow(__int128_t e) const {\n    G res{1}, a{*this};\n    while\
    \ (e) {\n      if (e & 1) res *= a;\n      a *= a, e >>= 1;\n    }\n    return\
    \ res;\n  }\n\n  friend G gcd(G a, G b) {\n    while (b != G{0, 0}) {\n      trc(a,\
    \ b, a / b, a % b);\n      swap(a %= b, b);\n    }\n    return a;\n  }\n  friend\
    \ ostream& operator<<(ostream& os, const G& rhs) {\n    return os << rhs.x <<\
    \ \" \" << rhs.y;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/gaussian-integer.hpp
  requiredBy:
  - math/two-square.hpp
  timestamp: '2024-09-14 20:40:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/enumerate-convex.test.cpp
  - verify/verify-yosupo-math/yosupo-gcd-of-gaussian-integer.test.cpp
  - verify/verify-yosupo-math/yosupo-two-square-sum.test.cpp
documentation_of: math/gaussian-integer.hpp
layout: document
redirect_from:
- /library/math/gaussian-integer.hpp
- /library/math/gaussian-integer.hpp.html
title: math/gaussian-integer.hpp
---

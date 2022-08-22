---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1145-frac.test.cpp
    title: verify/verify-yuki/yuki-1145-frac.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps/fps-fraction.hpp\"\n\ntemplate <typename fps>\nstruct\
    \ fps_fraction {\n  using frac = fps_fraction;\n  using mint = typename fps::value_type;\n\
    \n  fps p, q;\n  fps_fraction(const fps& numerator = fps{0}, const fps& denominator\
    \ = fps{1})\n      : p(numerator), q(denominator) {}\n\n  friend frac operator+(const\
    \ frac& l, const frac& r) {\n    return frac{l.p * r.q + r.p * l.q, l.q * r.q};\n\
    \  }\n  friend frac operator-(const frac& l, const frac& r) {\n    return frac{l.p\
    \ * r.q - r.p * l.q, l.q * r.q};\n  }\n  friend frac operator*(const frac& l,\
    \ const frac& r) {\n    return frac{l.p * r.p, l.q * r.q};\n  }\n  friend frac\
    \ operator/(const frac& l, const frac& r) {\n    return frac{l.p * r.q, l.q *\
    \ r.p};\n  }\n\n  frac& operator+=(const mint& r) {\n    (*this).p += (*this).q\
    \ * r;\n    return *this;\n  }\n  frac& operator-=(const mint& r) {\n    (*this).p\
    \ -= (*this).q * r;\n    return *this;\n  }\n  frac& operator*=(const mint& r)\
    \ {\n    (*this).p *= r;\n    return *this;\n  }\n\n  frac operator+(const mint&\
    \ r) { return frac{*this} += r; }\n  frac operator-(const mint& r) { return frac{*this}\
    \ -= r; }\n  frac operator*(const mint& r) { return frac{*this} *= r; }\n  frac\
    \ operator/(const mint& r) { return frac{*this} /= r; }\n  frac& operator+=(const\
    \ frac& r) { return *this = (*this) + r; }\n  frac& operator-=(const frac& r)\
    \ { return *this = (*this) - r; }\n  frac& operator*=(const frac& r) { return\
    \ *this = (*this) * r; }\n  frac operator-() const { return frac{-p, q}; }\n \
    \ frac inverse() const { return frac{q, p}; };\n\n  void shrink() { p.shrink(),\
    \ q.shrink(); }\n  friend bool operator==(const frac& l, const frac& r) {\n  \
    \  return l.p == r.p && l.q == r.q;\n  }\n  friend bool operator!=(const frac&\
    \ l, const frac& r) {\n    return l.p != r.p || l.q != r.q;\n  }\n  friend ostream&\
    \ operator<<(ostream& os, const frac& r) {\n    os << \"[ \" << r.p << \", \"\
    \ << r.q << \" ]\";\n    return os;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename fps>\nstruct fps_fraction {\n  using frac\
    \ = fps_fraction;\n  using mint = typename fps::value_type;\n\n  fps p, q;\n \
    \ fps_fraction(const fps& numerator = fps{0}, const fps& denominator = fps{1})\n\
    \      : p(numerator), q(denominator) {}\n\n  friend frac operator+(const frac&\
    \ l, const frac& r) {\n    return frac{l.p * r.q + r.p * l.q, l.q * r.q};\n  }\n\
    \  friend frac operator-(const frac& l, const frac& r) {\n    return frac{l.p\
    \ * r.q - r.p * l.q, l.q * r.q};\n  }\n  friend frac operator*(const frac& l,\
    \ const frac& r) {\n    return frac{l.p * r.p, l.q * r.q};\n  }\n  friend frac\
    \ operator/(const frac& l, const frac& r) {\n    return frac{l.p * r.q, l.q *\
    \ r.p};\n  }\n\n  frac& operator+=(const mint& r) {\n    (*this).p += (*this).q\
    \ * r;\n    return *this;\n  }\n  frac& operator-=(const mint& r) {\n    (*this).p\
    \ -= (*this).q * r;\n    return *this;\n  }\n  frac& operator*=(const mint& r)\
    \ {\n    (*this).p *= r;\n    return *this;\n  }\n\n  frac operator+(const mint&\
    \ r) { return frac{*this} += r; }\n  frac operator-(const mint& r) { return frac{*this}\
    \ -= r; }\n  frac operator*(const mint& r) { return frac{*this} *= r; }\n  frac\
    \ operator/(const mint& r) { return frac{*this} /= r; }\n  frac& operator+=(const\
    \ frac& r) { return *this = (*this) + r; }\n  frac& operator-=(const frac& r)\
    \ { return *this = (*this) - r; }\n  frac& operator*=(const frac& r) { return\
    \ *this = (*this) * r; }\n  frac operator-() const { return frac{-p, q}; }\n \
    \ frac inverse() const { return frac{q, p}; };\n\n  void shrink() { p.shrink(),\
    \ q.shrink(); }\n  friend bool operator==(const frac& l, const frac& r) {\n  \
    \  return l.p == r.p && l.q == r.q;\n  }\n  friend bool operator!=(const frac&\
    \ l, const frac& r) {\n    return l.p != r.p || l.q != r.q;\n  }\n  friend ostream&\
    \ operator<<(ostream& os, const frac& r) {\n    os << \"[ \" << r.p << \", \"\
    \ << r.q << \" ]\";\n    return os;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: fps/fps-fraction.hpp
  requiredBy: []
  timestamp: '2021-05-29 08:05:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yuki/yuki-1145-frac.test.cpp
documentation_of: fps/fps-fraction.hpp
layout: document
redirect_from:
- /library/fps/fps-fraction.hpp
- /library/fps/fps-fraction.hpp.html
title: fps/fps-fraction.hpp
---

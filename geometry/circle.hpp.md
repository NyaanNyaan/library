---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry-base.hpp
    title: geometry/geometry-base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/circle.hpp\"\n\n#line 2 \"geometry/geometry-base.hpp\"\
    \n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <complex>\n\
    #include <iostream>\n#include <vector>\nusing namespace std;\n\nusing Real = long\
    \ double;\nconstexpr Real EPS = 1e-10;\nconstexpr Real pi = 3.141592653589793238462643383279L;\n\
    bool equals(Real a, Real b) { return fabs(b - a) < EPS; }\nint sign(Real a) {\
    \ return equals(a, 0) ? 0 : a > 0 ? 1 : -1; }\n\ntemplate <typename R>\nstruct\
    \ PointBase {\n  using P = PointBase;\n  R x, y;\n  PointBase() : x(0), y(0) {}\n\
    \  PointBase(R _x, R _y) : x(_x), y(_y) {}\n  template <typename T, typename U>\n\
    \  PointBase(const pair<T, U>& p) : x(p.first), y(p.second) {}\n\n  P operator+(const\
    \ P& r) const { return {x + r.x, y + r.y}; }\n  P operator-(const P& r) const\
    \ { return {x - r.x, y - r.y}; }\n  P operator*(R r) const { return {x * r, y\
    \ * r}; }\n  P operator/(R r) const { return {x / r, y / r}; }\n\n  P& operator+=(const\
    \ P& r) { return (*this) = (*this) + r; }\n  P& operator-=(const P& r) { return\
    \ (*this) = (*this) - r; }\n  P& operator*=(R r) { return (*this) = (*this) *\
    \ r; }\n  P& operator/=(R r) { return (*this) = (*this) / r; }\n\n  bool operator<(const\
    \ P& r) const { return x != r.x ? x < r.x : y < r.y; }\n  bool operator==(const\
    \ P& r) const { return x == r.x and y == r.y; }\n  bool operator!=(const P& r)\
    \ const { return !((*this) == r); }\n\n  P rotate(R rad) const {\n    return {x\
    \ * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)};\n  }\n\n  R real()\
    \ const { return x; }\n  R imag() const { return y; }\n  friend R real(const P&\
    \ p) { return p.x; }\n  friend R imag(const P& p) { return p.y; }\n  friend R\
    \ dot(const P& l, const P& r) { return l.x * r.x + l.y * r.y; }\n  friend R cross(const\
    \ P& l, const P& r) { return l.x * r.y - l.y * r.x; }\n  friend R abs(const P&\
    \ p) { return sqrt(p.x * p.x + p.y * p.y); }\n  friend R norm(const P& p) { return\
    \ p.x * p.x + p.y * p.y; }\n  friend R arg(const P& p) { return atan2(p.y, p.x);\
    \ }\n\n  friend istream& operator>>(istream& is, P& p) {\n    R a, b;\n    is\
    \ >> a >> b;\n    p = P{a, b};\n    return is;\n  }\n  friend ostream& operator<<(ostream&\
    \ os, const P& p) {\n    return os << p.x << \" \" << p.y;\n  }\n};\nusing Point\
    \ = PointBase<Real>;\nusing Points = vector<Point>;\n\n// ccw, \u70B9\u306E\u9032\
    \u884C\u65B9\u5411\nint ccw(const Point& a, const Point& b, const Point& c) {\n\
    \  Point x = b - a, y = c - a;\n  if (cross(x, y) > EPS) return +1;          \
    \       // \u53CD\u6642\u8A08\u56DE\u308A\n  if (cross(x, y) < -EPS) return -1;\
    \                // \u6642\u8A08\u56DE\u308A\n  if (min(norm(x), norm(y)) < EPS\
    \ * EPS) return 0;  // c=a \u307E\u305F\u306F c=b\n  if (dot(x, y) < EPS) return\
    \ +2;                   // c-a-b \u306E\u9806\u3067\u4E00\u76F4\u7DDA\n  if (norm(x)\
    \ < norm(y)) return -2;                 // a-b-c \u306E\u9806\u3067\u4E00\u76F4\
    \u7DDA\n  return 0;                                         // a-c-b \u306E\u9806\
    \u3067\u4E00\u76F4\u7DDA\n}\n#line 4 \"geometry/circle.hpp\"\n\nstruct Circle\
    \ {\n  Point p;\n  Real r;\n\n  Circle() = default;\n  Circle(Point _p, Real _r)\
    \ : p(_p), r(_r) {}\n};\n\nusing Circles = vector<Circle>;\n\nint intersect(Circle\
    \ c1, Circle c2) {\n  if (c1.r < c2.r) swap(c1, c2);\n  Real d = abs(c1.p - c2.p);\n\
    \  if (c1.r + c2.r < d) return 4;\n  if (equals(c1.r + c2.r, d)) return 3;\n \
    \ if (c1.r - c2.r < d) return 2;\n  if (equals(c1.r - c2.r, d)) return 1;\n  return\
    \ 0;\n}\n\npair<Point, Point> crosspoint(const Circle& c1, const Circle& c2) {\n\
    \  Real d = abs(c1.p - c2.p);\n  Real x = (c1.r * c1.r + d * d - c2.r * c2.r)\
    \ / (2 * c1.r * d);\n  if (abs(x) > 1) x = (x > 0 ? 1.0 : -1.0);\n  Real a = acos(x);\n\
    \  Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());\n  Point\
    \ p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);\n  Point p2 = c1.p\
    \ + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);\n  return {p1, p2};\n}\n"
  code: "#pragma once\n\n#include \"geometry-base.hpp\"\n\nstruct Circle {\n  Point\
    \ p;\n  Real r;\n\n  Circle() = default;\n  Circle(Point _p, Real _r) : p(_p),\
    \ r(_r) {}\n};\n\nusing Circles = vector<Circle>;\n\nint intersect(Circle c1,\
    \ Circle c2) {\n  if (c1.r < c2.r) swap(c1, c2);\n  Real d = abs(c1.p - c2.p);\n\
    \  if (c1.r + c2.r < d) return 4;\n  if (equals(c1.r + c2.r, d)) return 3;\n \
    \ if (c1.r - c2.r < d) return 2;\n  if (equals(c1.r - c2.r, d)) return 1;\n  return\
    \ 0;\n}\n\npair<Point, Point> crosspoint(const Circle& c1, const Circle& c2) {\n\
    \  Real d = abs(c1.p - c2.p);\n  Real x = (c1.r * c1.r + d * d - c2.r * c2.r)\
    \ / (2 * c1.r * d);\n  if (abs(x) > 1) x = (x > 0 ? 1.0 : -1.0);\n  Real a = acos(x);\n\
    \  Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());\n  Point\
    \ p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);\n  Point p2 = c1.p\
    \ + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);\n  return {p1, p2};\n}\n"
  dependsOn:
  - geometry/geometry-base.hpp
  isVerificationFile: false
  path: geometry/circle.hpp
  requiredBy: []
  timestamp: '2023-12-29 22:15:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/circle.hpp
layout: document
redirect_from:
- /library/geometry/circle.hpp
- /library/geometry/circle.hpp.html
title: geometry/circle.hpp
---

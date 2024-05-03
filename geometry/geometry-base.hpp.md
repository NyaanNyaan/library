---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-1-a.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-1-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-1-b.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-1-c.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-1-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-2-a.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-2-b.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-2-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-2-c.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-2-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-3-a.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-3-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-3-b.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-3-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-3-c.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-4-a.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-4-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-4-b.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-4-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-4-c.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-4-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-0412.test.cpp
    title: verify/verify-aoj-other/aoj-0412.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/geometry.test.cpp
    title: verify/verify-unit-test/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-other/yosupo-static-convex-hull.test.cpp
    title: verify/verify-yosupo-other/yosupo-static-convex-hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/geometry-base.hpp\"\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n#include\
    \ <vector>\nusing namespace std;\n\nusing Real = long double;\nconstexpr Real\
    \ EPS = 1e-10;\nconstexpr Real pi = 3.141592653589793238462643383279L;\nbool equals(Real\
    \ a, Real b) { return fabs(b - a) < EPS; }\nint sign(Real a) { return equals(a,\
    \ 0) ? 0 : a > 0 ? 1 : -1; }\n\ntemplate <typename R>\nstruct PointBase {\n  using\
    \ P = PointBase;\n  R x, y;\n  PointBase() : x(0), y(0) {}\n  PointBase(R _x,\
    \ R _y) : x(_x), y(_y) {}\n  template <typename T, typename U>\n  PointBase(const\
    \ pair<T, U>& p) : x(p.first), y(p.second) {}\n\n  P operator+(const P& r) const\
    \ { return {x + r.x, y + r.y}; }\n  P operator-(const P& r) const { return {x\
    \ - r.x, y - r.y}; }\n  P operator*(R r) const { return {x * r, y * r}; }\n  P\
    \ operator/(R r) const { return {x / r, y / r}; }\n\n  P& operator+=(const P&\
    \ r) { return (*this) = (*this) + r; }\n  P& operator-=(const P& r) { return (*this)\
    \ = (*this) - r; }\n  P& operator*=(R r) { return (*this) = (*this) * r; }\n \
    \ P& operator/=(R r) { return (*this) = (*this) / r; }\n\n  bool operator<(const\
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
    \u3067\u4E00\u76F4\u7DDA\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <complex>\n#include <iostream>\n#include <vector>\nusing namespace std;\n\
    \nusing Real = long double;\nconstexpr Real EPS = 1e-10;\nconstexpr Real pi =\
    \ 3.141592653589793238462643383279L;\nbool equals(Real a, Real b) { return fabs(b\
    \ - a) < EPS; }\nint sign(Real a) { return equals(a, 0) ? 0 : a > 0 ? 1 : -1;\
    \ }\n\ntemplate <typename R>\nstruct PointBase {\n  using P = PointBase;\n  R\
    \ x, y;\n  PointBase() : x(0), y(0) {}\n  PointBase(R _x, R _y) : x(_x), y(_y)\
    \ {}\n  template <typename T, typename U>\n  PointBase(const pair<T, U>& p) :\
    \ x(p.first), y(p.second) {}\n\n  P operator+(const P& r) const { return {x +\
    \ r.x, y + r.y}; }\n  P operator-(const P& r) const { return {x - r.x, y - r.y};\
    \ }\n  P operator*(R r) const { return {x * r, y * r}; }\n  P operator/(R r) const\
    \ { return {x / r, y / r}; }\n\n  P& operator+=(const P& r) { return (*this) =\
    \ (*this) + r; }\n  P& operator-=(const P& r) { return (*this) = (*this) - r;\
    \ }\n  P& operator*=(R r) { return (*this) = (*this) * r; }\n  P& operator/=(R\
    \ r) { return (*this) = (*this) / r; }\n\n  bool operator<(const P& r) const {\
    \ return x != r.x ? x < r.x : y < r.y; }\n  bool operator==(const P& r) const\
    \ { return x == r.x and y == r.y; }\n  bool operator!=(const P& r) const { return\
    \ !((*this) == r); }\n\n  P rotate(R rad) const {\n    return {x * cos(rad) -\
    \ y * sin(rad), x * sin(rad) + y * cos(rad)};\n  }\n\n  R real() const { return\
    \ x; }\n  R imag() const { return y; }\n  friend R real(const P& p) { return p.x;\
    \ }\n  friend R imag(const P& p) { return p.y; }\n  friend R dot(const P& l, const\
    \ P& r) { return l.x * r.x + l.y * r.y; }\n  friend R cross(const P& l, const\
    \ P& r) { return l.x * r.y - l.y * r.x; }\n  friend R abs(const P& p) { return\
    \ sqrt(p.x * p.x + p.y * p.y); }\n  friend R norm(const P& p) { return p.x * p.x\
    \ + p.y * p.y; }\n  friend R arg(const P& p) { return atan2(p.y, p.x); }\n\n \
    \ friend istream& operator>>(istream& is, P& p) {\n    R a, b;\n    is >> a >>\
    \ b;\n    p = P{a, b};\n    return is;\n  }\n  friend ostream& operator<<(ostream&\
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
    \u3067\u4E00\u76F4\u7DDA\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry-base.hpp
  requiredBy:
  - geometry/segment.hpp
  - geometry/line.hpp
  - geometry/circle.hpp
  - geometry/polygon.hpp
  timestamp: '2023-12-29 22:15:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-0412.test.cpp
  - verify/verify-yosupo-other/yosupo-static-convex-hull.test.cpp
  - verify/verify-unit-test/geometry.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-3-c.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-2-a.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-4-c.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-3-a.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-2-c.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-1-a.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-3-b.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-1-b.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-2-b.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-1-c.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-4-b.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-4-a.test.cpp
documentation_of: geometry/geometry-base.hpp
layout: document
redirect_from:
- /library/geometry/geometry-base.hpp
- /library/geometry/geometry-base.hpp.html
title: geometry/geometry-base.hpp
---

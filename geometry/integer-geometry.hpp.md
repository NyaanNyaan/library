---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-other/yosupo-argument-sort.test.cpp
    title: verify/verify-yosupo-other/yosupo-argument-sort.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/integer-geometry.hpp\"\n\nstruct Point {\n  using\
    \ T = long long;\n  T x, y;\n  Point() : x(0), y(0) {}\n  Point(T x_, T y_) :\
    \ x(x_), y(y_) {}\n\n  Point &operator+=(const Point &p) {\n    this->x += p.x;\n\
    \    this->y += p.y;\n    return *this;\n  }\n\n  Point &operator-=(const Point\
    \ &p) {\n    this->x -= p.x;\n    this->y -= p.y;\n    return *this;\n  }\n\n\
    \  int pos() const {\n    if (y < 0) return -1;\n    if (y == 0 && 0 <= x) return\
    \ 0;\n    return 1;\n  }\n\n  Point operator+(const Point &p) const { return Point(*this)\
    \ += p; }\n  Point operator-(const Point &p) const { return Point(*this) -= p;\
    \ }\n  Point operator-() const { return Point(-this->x, -this->y); }\n  bool operator==(const\
    \ Point &p) const { return x == p.x && y == p.y; }\n  bool operator!=(const Point\
    \ &p) const { return x != p.x || y != p.y; }\n  bool operator<(const Point &p)\
    \ const { return x == p.x ? y < p.y : x < p.x; }\n\n  friend istream &operator>>(istream\
    \ &is, Point &p) {\n    cin >> p.x >> p.y;\n    return is;\n  }\n\n  friend ostream\
    \ &operator<<(ostream &os, const Point &p) {\n    os << p.x << \" \" << p.y;\n\
    \    return os;\n  }\n};\nusing Points = vector<Point>;\n\nPoint::T dot(const\
    \ Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }\nPoint::T cross(const\
    \ Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }\n\n// sort by argument\
    \ (-Pi ~ Pi)\nvoid ArgumentSort(Points &v) {\n  sort(begin(v), end(v), [](Point\
    \ a, Point b) {\n    if (a.pos() != b.pos()) return a.pos() < b.pos();\n    return\
    \ cross(a, b) > 0;\n  });\n}\n\n// 1 ... counterclockwise / 0 straight / -1 clockwise\n\
    int ccw(const Point &a, const Point &b, const Point &c) {\n  Point::T t = cross(b\
    \ - a, c - a);\n  return t < 0 ? -1 : t == 0 ? 0 : 1;\n}\n\n// v must have sorted\
    \ by x-coordinate\nPoints LowerHull(const Points &ps) {\n  int N = (int)ps.size();\n\
    \  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);\n  if (N <=\
    \ 2) return ps;\n  Points convex(N);\n  int k = 0;\n  for (int i = 0; i < N; convex[k++]\
    \ = ps[i++]) {\n    while (k >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i])\
    \ <= 0) --k;\n  }\n  convex.resize(k);\n  return convex;\n}\n\nPoints UpperHull(const\
    \ Points &ps) {\n  int N = (int)ps.size();\n  for (int i = 0; i < N - 1; i++)\
    \ assert(ps[i].x <= ps[i + 1].x);\n  if (N <= 2) return ps;\n  Points convex(N);\n\
    \  int k = 0;\n  for (int i = 0; i < N; convex[k++] = ps[i++]) {\n    while (k\
    \ >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i]) >= 0) --k;\n  }\n  convex.resize(k);\n\
    \  return convex;\n}\n\nPoints ConvexHull(const Points &ps) {\n  int N = (int)ps.size();\n\
    \  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);\n  if (N <=\
    \ 2) return ps;\n  Points convex(2 * N);\n  int k = 0;\n  for (int i = 0; i <\
    \ N; convex[k++] = ps[i++]) {\n    while (k >= 2 && ccw(convex[k - 2], convex[k\
    \ - 1], ps[i]) <= 0) --k;\n  }\n  for (int i = N - 2, t = k + 1; i >= 0; convex[k++]\
    \ = ps[i--]) {\n    while (k >= t && ccw(convex[k - 2], convex[k - 1], ps[i])\
    \ <= 0) --k;\n  }\n  convex.resize(k - 1);\n  return convex;\n}\n"
  code: "#pragma once\n\nstruct Point {\n  using T = long long;\n  T x, y;\n  Point()\
    \ : x(0), y(0) {}\n  Point(T x_, T y_) : x(x_), y(y_) {}\n\n  Point &operator+=(const\
    \ Point &p) {\n    this->x += p.x;\n    this->y += p.y;\n    return *this;\n \
    \ }\n\n  Point &operator-=(const Point &p) {\n    this->x -= p.x;\n    this->y\
    \ -= p.y;\n    return *this;\n  }\n\n  int pos() const {\n    if (y < 0) return\
    \ -1;\n    if (y == 0 && 0 <= x) return 0;\n    return 1;\n  }\n\n  Point operator+(const\
    \ Point &p) const { return Point(*this) += p; }\n  Point operator-(const Point\
    \ &p) const { return Point(*this) -= p; }\n  Point operator-() const { return\
    \ Point(-this->x, -this->y); }\n  bool operator==(const Point &p) const { return\
    \ x == p.x && y == p.y; }\n  bool operator!=(const Point &p) const { return x\
    \ != p.x || y != p.y; }\n  bool operator<(const Point &p) const { return x ==\
    \ p.x ? y < p.y : x < p.x; }\n\n  friend istream &operator>>(istream &is, Point\
    \ &p) {\n    cin >> p.x >> p.y;\n    return is;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const Point &p) {\n    os << p.x << \" \" << p.y;\n    return os;\n  }\n\
    };\nusing Points = vector<Point>;\n\nPoint::T dot(const Point &a, const Point\
    \ &b) { return a.x * b.x + a.y * b.y; }\nPoint::T cross(const Point &a, const\
    \ Point &b) { return a.x * b.y - a.y * b.x; }\n\n// sort by argument (-Pi ~ Pi)\n\
    void ArgumentSort(Points &v) {\n  sort(begin(v), end(v), [](Point a, Point b)\
    \ {\n    if (a.pos() != b.pos()) return a.pos() < b.pos();\n    return cross(a,\
    \ b) > 0;\n  });\n}\n\n// 1 ... counterclockwise / 0 straight / -1 clockwise\n\
    int ccw(const Point &a, const Point &b, const Point &c) {\n  Point::T t = cross(b\
    \ - a, c - a);\n  return t < 0 ? -1 : t == 0 ? 0 : 1;\n}\n\n// v must have sorted\
    \ by x-coordinate\nPoints LowerHull(const Points &ps) {\n  int N = (int)ps.size();\n\
    \  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);\n  if (N <=\
    \ 2) return ps;\n  Points convex(N);\n  int k = 0;\n  for (int i = 0; i < N; convex[k++]\
    \ = ps[i++]) {\n    while (k >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i])\
    \ <= 0) --k;\n  }\n  convex.resize(k);\n  return convex;\n}\n\nPoints UpperHull(const\
    \ Points &ps) {\n  int N = (int)ps.size();\n  for (int i = 0; i < N - 1; i++)\
    \ assert(ps[i].x <= ps[i + 1].x);\n  if (N <= 2) return ps;\n  Points convex(N);\n\
    \  int k = 0;\n  for (int i = 0; i < N; convex[k++] = ps[i++]) {\n    while (k\
    \ >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i]) >= 0) --k;\n  }\n  convex.resize(k);\n\
    \  return convex;\n}\n\nPoints ConvexHull(const Points &ps) {\n  int N = (int)ps.size();\n\
    \  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);\n  if (N <=\
    \ 2) return ps;\n  Points convex(2 * N);\n  int k = 0;\n  for (int i = 0; i <\
    \ N; convex[k++] = ps[i++]) {\n    while (k >= 2 && ccw(convex[k - 2], convex[k\
    \ - 1], ps[i]) <= 0) --k;\n  }\n  for (int i = N - 2, t = k + 1; i >= 0; convex[k++]\
    \ = ps[i--]) {\n    while (k >= t && ccw(convex[k - 2], convex[k - 1], ps[i])\
    \ <= 0) --k;\n  }\n  convex.resize(k - 1);\n  return convex;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/integer-geometry.hpp
  requiredBy: []
  timestamp: '2020-12-05 15:21:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-other/yosupo-argument-sort.test.cpp
documentation_of: geometry/integer-geometry.hpp
layout: document
redirect_from:
- /library/geometry/integer-geometry.hpp
- /library/geometry/integer-geometry.hpp.html
title: geometry/integer-geometry.hpp
---

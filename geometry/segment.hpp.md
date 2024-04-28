---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry-base.hpp
    title: geometry/geometry-base.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-2-b.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-2-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp
    title: verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/segment.hpp\"\n\n#line 2 \"geometry/geometry-base.hpp\"\
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
    \u3067\u4E00\u76F4\u7DDA\n}\n#line 4 \"geometry/segment.hpp\"\n//\n#line 2 \"\
    geometry/line.hpp\"\n\n#line 2 \"geometry/polygon.hpp\"\n\n#line 4 \"geometry/polygon.hpp\"\
    \n\nusing Polygon = vector<Point>;\n\n// \u591A\u89D2\u5F62\u306E\u5185\u90E8\u306B\
    \u70B9\u304C\u3042\u308B\u304B\uFF1F\n// OUT : 0, ON : 1, IN : 2\nint contains_polygon(const\
    \ Polygon &Q, const Point &p) {\n  bool in = false;\n  for (int i = 0; i < (int)Q.size();\
    \ i++) {\n    Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;\n    if (imag(a)\
    \ > imag(b)) swap(a, b);\n    if (sign(imag(a)) <= 0 && 0 < sign(imag(b)) && sign(cross(a,\
    \ b)) < 0)\n      in = !in;\n    if (equals(cross(a, b), 0) && sign(dot(a, b))\
    \ <= 0) return 1;\n  }\n  return in ? 2 : 0;\n}\n\n// \u591A\u89D2\u5F62\u306E\
    \u9762\u7A4D\nReal area(const Polygon &p) {\n  Real A = 0;\n  for (int i = 0;\
    \ i < (int)p.size(); ++i) {\n    A += cross(p[i], p[(i + 1) % p.size()]);\n  }\n\
    \  return A * 0.5;\n}\n\n// \u9802\u70B9\u96C6\u5408\u304B\u3089\u51F8\u5305\u3092\
    \u751F\u6210\n// boundary : \u5468\u4E0A\u306E\u70B9\u3082\u5217\u6319\u3059\u308B\
    \u5834\u5408 true\ntemplate <bool boundary = false>\nPolygon convex_hull(vector<Point>\
    \ ps) {\n  int n = (int)ps.size(), k = 0;\n  if (n <= 2) return ps;\n  sort(ps.begin(),\
    \ ps.end());\n  vector<Point> ch(2 * n);\n  // \u53CD\u6642\u8A08\u5468\u308A\n\
    \  Real th = boundary ? -EPS : +EPS;\n  for (int i = 0; i < n; ch[k++] = ps[i++])\
    \ {\n    while (k >= 2 && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < th)\
    \ --k;\n  }\n  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) {\n \
    \   while (k >= t && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < th) --k;\n\
    \  }\n  ch.resize(k - 1);\n  return ch;\n}\n\n// \u51F8\u5305\u306E\u5185\u90E8\
    \u306B\u70B9\u304C\u3042\u308B\u304B\uFF1F\n// OUT : 0, ON : 1, IN : 2\nint contains_convex(const\
    \ Polygon &C, const Point &p) {\n  int N = C.size();\n  auto b1 = cross(C[1] -\
    \ C[0], p - C[0]);\n  auto b2 = cross(C[N - 1] - C[0], p - C[0]);\n  if (b1 <\
    \ -EPS or b2 > EPS) return 0;\n  int L = 1, R = N - 1;\n  while (L + 1 < R) {\n\
    \    int M = (L + R) / 2;\n    (cross(p - C[0], C[M] - C[0]) >= 0 ? R : L) = M;\n\
    \  }\n  auto v = cross(C[L] - p, C[R] - p);\n  if (equals(v, 0)) {\n    return\
    \ 1;\n  } else if (v > 0) {\n    return equals(b1, 0) or equals(b2, 0) ? 1 : 2;\n\
    \  } else {\n    return 0;\n  }\n}\n\n// \u51F8\u5305\u304C\u4E0E\u3048\u3089\u308C\
    \u308B\u306E\u3067\u6700\u9060\u70B9\u5BFE\u3092\u8FD4\u3059\n// \u8FD4\u308A\u5024\
    \uFF1A\u9802\u70B9\u756A\u53F7\u306E\u30DA\u30A2\npair<int, int> convex_polygon_diameter(const\
    \ Polygon &p) {\n  int N = (int)p.size();\n  int is = 0, js = 0;\n  for (int i\
    \ = 1; i < N; i++) {\n    if (imag(p[i]) > imag(p[is])) is = i;\n    if (imag(p[i])\
    \ < imag(p[js])) js = i;\n  }\n  Real maxdis = norm(p[is] - p[js]);\n\n  int maxi,\
    \ maxj, i, j;\n  i = maxi = is;\n  j = maxj = js;\n  do {\n    if (cross(p[(i\
    \ + 1) % N] - p[i], p[(j + 1) % N] - p[j]) >= 0) {\n      j = (j + 1) % N;\n \
    \   } else {\n      i = (i + 1) % N;\n    }\n    if (norm(p[i] - p[j]) > maxdis)\
    \ {\n      maxdis = norm(p[i] - p[j]);\n      maxi = i;\n      maxj = j;\n   \
    \ }\n  } while (i != is || j != js);\n  return minmax(maxi, maxj);\n}\n#line 5\
    \ \"geometry/line.hpp\"\n\nstruct Line {\n  Point a, b;\n\n  Line() = default;\n\
    \  Line(const Point &_a, const Point &_b) : a(_a), b(_b) {}\n  // Ax+By=C\n  Line(const\
    \ Real &A, const Real &B, const Real &C) {\n    if (equals(A, 0)) {\n      assert(!equals(B,\
    \ 0));\n      a = Point(0, C / B);\n      b = Point(1, C / B);\n    } else if\
    \ (equals(B, 0)) {\n      a = Point(C / A, 0);\n      b = Point(C / A, 1);\n \
    \   } else if (equals(C, 0)) {\n      a = Point(0, C / B);\n      b = Point(1,\
    \ (C - A) / B);\n    } else {\n      a = Point(0, C / B);\n      b = Point(C /\
    \ A, 0);\n    }\n  }\n  friend ostream &operator<<(ostream &os, const Line &l)\
    \ {\n    return os << l.a << \" to \" << l.b;\n  }\n  friend istream &operator>>(istream\
    \ &is, Line &l) { return is >> l.a >> l.b; }\n};\nusing Lines = vector<Line>;\n\
    \nbool is_parallel(const Line &a, const Line &b) {\n  return equals(cross(a.b\
    \ - a.a, b.b - b.a), 0);\n}\nbool is_orthogonal(const Line &a, const Line &b)\
    \ {\n  return equals(dot(a.a - a.b, b.a - b.b), 0);\n}\nPoint cross_point_ll(const\
    \ Line &l, const Line &m) {\n  Real A = cross(l.b - l.a, m.b - m.a);\n  Real B\
    \ = cross(l.b - l.a, l.b - m.a);\n  if (equals(abs(A), 0) && equals(abs(B), 0))\
    \ return m.a;\n  return m.a + (m.b - m.a) * B / A;\n}\nbool is_intersect_ll(const\
    \ Line &l, const Line &m) {\n  Real A = cross(l.b - l.a, m.b - m.a);\n  Real B\
    \ = cross(l.b - l.a, l.b - m.a);\n  if (equals(abs(A), 0) && equals(abs(B), 0))\
    \ return true;\n  return !is_parallel(l, m);\n}\n\n// \u76F4\u7DDA\u306B\u9802\
    \u70B9\u304B\u3089\u5782\u7DDA\u3092\u4E0B\u308D\u3057\u305F\u6642\u306E\u4EA4\
    \u70B9\nPoint projection(const Line &l, const Point &p) {\n  Real t = dot(p -\
    \ l.a, l.a - l.b) / norm(l.a - l.b);\n  return l.a + (l.a - l.b) * t;\n}\n\n//\
    \ \u51F8\u5305\u3092\u76F4\u7DDA\u3067\u5207\u3063\u305F\u6642\u306E\u7247\u65B9\
    \ (\u76F4\u7DDA a->b \u306E\u9032\u884C\u65B9\u5411\u5DE6\u5074) \u3092\u8FD4\u3059\
    \nPolygon convex_polygon_cut(const Polygon &U, const Line &l) {\n  Polygon ret;\n\
    \  for (int i = 0; i < (int)U.size(); i++) {\n    const Point &now = U[i];\n \
    \   const Point &nxt = U[(i + 1) % U.size()];\n    auto cf = cross(l.a - now,\
    \ l.b - now);\n    auto cs = cross(l.a - nxt, l.b - nxt);\n    if (sign(cf) >=\
    \ 0) {\n      ret.emplace_back(now);\n    }\n    if (sign(cf) * sign(cs) < 0)\
    \ {\n      ret.emplace_back(cross_point_ll(Line(now, nxt), l));\n    }\n  }\n\
    \  return ret;\n}\n#line 6 \"geometry/segment.hpp\"\n\nstruct Segment : Line {\n\
    \  Segment() = default;\n  using Line::Line;\n};\n\nusing Segments = vector<Segment>;\n\
    \nbool is_intersect_sp(const Segment &s, const Point &p) {\n  return ccw(s.a,\
    \ s.b, p) == 0;\n}\nbool is_intersect_ss(const Segment &s, const Segment &t) {\n\
    \  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&\n         ccw(t.a, t.b,\
    \ s.a) * ccw(t.a, t.b, s.b) <= 0;\n}\n\nReal distance_sp(const Segment &s, const\
    \ Point &p) {\n  Point r = projection(s, p);\n  if (is_intersect_sp(s, r)) return\
    \ abs(r - p);\n  return min(abs(s.a - p), abs(s.b - p));\n}\nReal distance_ss(const\
    \ Segment &a, const Segment &b) {\n  if (is_intersect_ss(a, b)) return 0;\n  return\
    \ min({distance_sp(a, b.a), distance_sp(a, b.b), distance_sp(b, a.a),\n      \
    \        distance_sp(b, a.b)});\n}\n"
  code: "#pragma once\n\n#include \"geometry-base.hpp\"\n//\n#include \"line.hpp\"\
    \n\nstruct Segment : Line {\n  Segment() = default;\n  using Line::Line;\n};\n\
    \nusing Segments = vector<Segment>;\n\nbool is_intersect_sp(const Segment &s,\
    \ const Point &p) {\n  return ccw(s.a, s.b, p) == 0;\n}\nbool is_intersect_ss(const\
    \ Segment &s, const Segment &t) {\n  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b,\
    \ t.b) <= 0 &&\n         ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n}\n\n\
    Real distance_sp(const Segment &s, const Point &p) {\n  Point r = projection(s,\
    \ p);\n  if (is_intersect_sp(s, r)) return abs(r - p);\n  return min(abs(s.a -\
    \ p), abs(s.b - p));\n}\nReal distance_ss(const Segment &a, const Segment &b)\
    \ {\n  if (is_intersect_ss(a, b)) return 0;\n  return min({distance_sp(a, b.a),\
    \ distance_sp(a, b.b), distance_sp(b, a.a),\n              distance_sp(b, a.b)});\n\
    }\n"
  dependsOn:
  - geometry/geometry-base.hpp
  - geometry/line.hpp
  - geometry/polygon.hpp
  isVerificationFile: false
  path: geometry/segment.hpp
  requiredBy: []
  timestamp: '2024-04-28 09:13:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-cgl/aoj-cgl-2-b.test.cpp
  - verify/verify-aoj-cgl/aoj-cgl-2-d.test.cpp
documentation_of: geometry/segment.hpp
layout: document
redirect_from:
- /library/geometry/segment.hpp
- /library/geometry/segment.hpp.html
title: geometry/segment.hpp
---

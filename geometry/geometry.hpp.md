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
  bundledCode: "#line 2 \"geometry/geometry.hpp\"\n\n\n\nusing Real = long double;\n\
    using Point = complex<Real>;\nusing Points = vector<Point>;\nconstexpr Real EPS\
    \ = 1e-8;  // \u554F\u984C\u306B\u3088\u3063\u3066\u5909\u3048\u308B\uFF01\nconstexpr\
    \ Real pi = 3.141592653589793238462643383279L;\nistream &operator>>(istream &is,\
    \ Point &p) {\n  Real a, b;\n  is >> a >> b;\n  p = Point(a, b);\n  return is;\n\
    }\nostream &operator<<(ostream &os, Point &p) {\n  return os << real(p) << \"\
    \ \" << imag(p);\n}\ninline bool eq(Real a, Real b) { return fabs(b - a) < EPS;\
    \ }\n\nPoint operator*(const Point &p, const Real &d) {\n  return Point(real(p)\
    \ * d, imag(p) * d);\n}\n\nnamespace std {\nbool operator<(const Point &a, const\
    \ Point &b) {\n  return a.real() != b.real() ? a.real() < b.real() : a.imag()\
    \ < b.imag();\n}\n}  // namespace std\n\nReal cross(const Point &a, const Point\
    \ &b) {\n  return real(a) * imag(b) - imag(a) * real(b);\n}\nReal dot(const Point\
    \ &a, const Point &b) {\n  return real(a) * real(b) + imag(a) * imag(b);\n}\n\n\
    // ccw \u70B9\u306E\u9032\u884C\u65B9\u5411\nint ccw(const Point &a, Point b,\
    \ Point c) {\n  b = b - a, c = c - a;\n  if (cross(b, c) > EPS) return +1;   //\
    \ \u53CD\u6642\u8A08\u56DE\u308A\n  if (cross(b, c) < -EPS) return -1;  // \u6642\
    \u8A08\u56DE\u308A\n  if (dot(b, c) < 0) return +2;       // c-a-b\u306E\u9806\
    \u3067\u4E00\u76F4\u7DDA\n  if (norm(b) < norm(c)) return -2;   // a-b-c\u306E\
    \u9806\u3067\u4E00\u76F4\u7DDA\n  return 0;                           // a-c-b\u306E\
    \u9806\u3067\u4E00\u76F4\u7DDA\n}\n\n// a-b\u30D9\u30AF\u30C8\u30EB\u3068b-c\u30D9\
    \u30AF\u30C8\u30EB\u306E\u306A\u3059\u89D2\u5EA6\u306E\u3046\u3061\u5C0F\u3055\
    \u3044\u65B9\u3092\u8FD4\u3059\n// (\u30D9\u30AF\u30C8\u30EB\u540C\u58EB\u306E\
    \u306A\u3059\u89D2\u3001\u3059\u306A\u308F\u3061\u5E7E\u4F55\u3067\u3044\u3046\
    \u3068\u3053\u308D\u306E\u300C\u5916\u89D2\u300D\u3067\u3042\u308B\u3053\u3068\
    \u306B\u6CE8\u610F\uFF01)\n// rem. \u51F8\u5305\u306B\u5BFE\u3057\u3066\u53CD\u6642\
    \u8A08\u56DE\u308A\u306B\u3053\u306E\u95A2\u6570\u3092\u9069\u7528\u3059\u308B\
    \u3068\u3001\n// \u51F8\u5305\u306E\u5927\u304D\u3055\u306B\u304B\u304B\u308F\u3089\
    \u305A\u548C\u304C360\u5EA6\u306B\u306A\u308B(\u3044\u308F\u3086\u308B\u5916\u89D2\
    \u306E\u548C)(AGC021-B)\nReal get_angle(const Point &a, const Point &b, const\
    \ Point &c) {\n  const Point v(b - a), w(c - b);\n  Real alpha = atan2(v.imag(),\
    \ v.real()), beta = atan2(w.imag(), w.real());\n  if (alpha > beta) swap(alpha,\
    \ beta);\n  Real theta = (beta - alpha);\n  return min(theta, 2 * acos(-1) - theta);\n\
    }\n\n//\u3000\u53CD\u6642\u8A08\u56DE\u308A\u3067\u3042\u308B\u81EA\u5DF1\u4EA4\
    \u5DEE\u306E\u306A\u3044\u591A\u89D2\u5F62\u306Eclass\nusing Polygon = vector<Point>;\n\
    \n// \u51F8\u5305\nPolygon convex_hull(vector<Point> ps) {\n  int n = (int)ps.size(),\
    \ k = 0;\n  if (n <= 2) return ps;\n  sort(ps.begin(), ps.end());\n  vector<Point>\
    \ ch(2 * n);\n  // \u53CD\u6642\u8A08\u5468\u308A\u306B\u51F8\u5305\u3092\u69CB\
    \u7BC9\u3057\u3066\u3044\u304F\n  for (int i = 0; i < n; ch[k++] = ps[i++]) {\n\
    \    // \u6761\u4EF6\u5206\u5C90\u5185\u306Fwhile(k >= 2 && ccw(ch[k-2],ch[k-1],ps[i])\
    \ != 1)\u3068\u7B49\u4FA1\n    while (k >= 2 && cross(ch[k - 1] - ch[k - 2], ps[i]\
    \ - ch[k - 1]) < EPS) --k;\n  }\n  for (int i = n - 2, t = k + 1; i >= 0; ch[k++]\
    \ = ps[i--]) {\n    while (k >= t && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k\
    \ - 1]) < EPS) --k;\n  }\n  ch.resize(k - 1);\n  return ch;\n}\n\n// \u591A\u89D2\
    \u5F62\u306E\u9762\u7A4D\nReal area(const Polygon &p) {\n  Real A = 0;\n  for\
    \ (int i = 0; i < (int)p.size(); ++i) {\n    A += cross(p[i], p[(i + 1) % p.size()]);\n\
    \  }\n  return A * 0.5;\n}\n\nstruct Circle {\n  Point p;\n  Real r;\n\n  Circle()\
    \ = default;\n  Circle(Point p, Real r) : p(p), r(r) {}\n};\n\nusing Circles =\
    \ vector<Circle>;\n\nint intersect(Circle c1, Circle c2) {\n  if (c1.r < c2.r)\
    \ swap(c1, c2);\n  Real d = abs(c1.p - c2.p);\n  if (c1.r + c2.r < d) return 4;\n\
    \  if (eq(c1.r + c2.r, d)) return 3;\n  if (c1.r - c2.r < d) return 2;\n  if (eq(c1.r\
    \ - c2.r, d)) return 1;\n  return 0;\n}\n\npair<Point, Point> crosspoint(const\
    \ Circle &c1, const Circle &c2) {\n  Real d = abs(c1.p - c2.p);\n  Real x = (c1.r\
    \ * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d);\n  if (abs(x) > 1) x = (x >\
    \ 0 ? 1.0 : -1.0);\n  Real a = acos(x);\n  Real t = atan2(c2.p.imag() - c1.p.imag(),\
    \ c2.p.real() - c1.p.real());\n  Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t\
    \ + a) * c1.r);\n  Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);\n\
    \  return {p1, p2};\n}\n"
  code: "#pragma once\n\n\n\nusing Real = long double;\nusing Point = complex<Real>;\n\
    using Points = vector<Point>;\nconstexpr Real EPS = 1e-8;  // \u554F\u984C\u306B\
    \u3088\u3063\u3066\u5909\u3048\u308B\uFF01\nconstexpr Real pi = 3.141592653589793238462643383279L;\n\
    istream &operator>>(istream &is, Point &p) {\n  Real a, b;\n  is >> a >> b;\n\
    \  p = Point(a, b);\n  return is;\n}\nostream &operator<<(ostream &os, Point &p)\
    \ {\n  return os << real(p) << \" \" << imag(p);\n}\ninline bool eq(Real a, Real\
    \ b) { return fabs(b - a) < EPS; }\n\nPoint operator*(const Point &p, const Real\
    \ &d) {\n  return Point(real(p) * d, imag(p) * d);\n}\n\nnamespace std {\nbool\
    \ operator<(const Point &a, const Point &b) {\n  return a.real() != b.real() ?\
    \ a.real() < b.real() : a.imag() < b.imag();\n}\n}  // namespace std\n\nReal cross(const\
    \ Point &a, const Point &b) {\n  return real(a) * imag(b) - imag(a) * real(b);\n\
    }\nReal dot(const Point &a, const Point &b) {\n  return real(a) * real(b) + imag(a)\
    \ * imag(b);\n}\n\n// ccw \u70B9\u306E\u9032\u884C\u65B9\u5411\nint ccw(const\
    \ Point &a, Point b, Point c) {\n  b = b - a, c = c - a;\n  if (cross(b, c) >\
    \ EPS) return +1;   // \u53CD\u6642\u8A08\u56DE\u308A\n  if (cross(b, c) < -EPS)\
    \ return -1;  // \u6642\u8A08\u56DE\u308A\n  if (dot(b, c) < 0) return +2;   \
    \    // c-a-b\u306E\u9806\u3067\u4E00\u76F4\u7DDA\n  if (norm(b) < norm(c)) return\
    \ -2;   // a-b-c\u306E\u9806\u3067\u4E00\u76F4\u7DDA\n  return 0;            \
    \               // a-c-b\u306E\u9806\u3067\u4E00\u76F4\u7DDA\n}\n\n// a-b\u30D9\
    \u30AF\u30C8\u30EB\u3068b-c\u30D9\u30AF\u30C8\u30EB\u306E\u306A\u3059\u89D2\u5EA6\
    \u306E\u3046\u3061\u5C0F\u3055\u3044\u65B9\u3092\u8FD4\u3059\n// (\u30D9\u30AF\
    \u30C8\u30EB\u540C\u58EB\u306E\u306A\u3059\u89D2\u3001\u3059\u306A\u308F\u3061\
    \u5E7E\u4F55\u3067\u3044\u3046\u3068\u3053\u308D\u306E\u300C\u5916\u89D2\u300D\
    \u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\uFF01)\n// rem. \u51F8\u5305\u306B\
    \u5BFE\u3057\u3066\u53CD\u6642\u8A08\u56DE\u308A\u306B\u3053\u306E\u95A2\u6570\
    \u3092\u9069\u7528\u3059\u308B\u3068\u3001\n// \u51F8\u5305\u306E\u5927\u304D\u3055\
    \u306B\u304B\u304B\u308F\u3089\u305A\u548C\u304C360\u5EA6\u306B\u306A\u308B(\u3044\
    \u308F\u3086\u308B\u5916\u89D2\u306E\u548C)(AGC021-B)\nReal get_angle(const Point\
    \ &a, const Point &b, const Point &c) {\n  const Point v(b - a), w(c - b);\n \
    \ Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());\n\
    \  if (alpha > beta) swap(alpha, beta);\n  Real theta = (beta - alpha);\n  return\
    \ min(theta, 2 * acos(-1) - theta);\n}\n\n//\u3000\u53CD\u6642\u8A08\u56DE\u308A\
    \u3067\u3042\u308B\u81EA\u5DF1\u4EA4\u5DEE\u306E\u306A\u3044\u591A\u89D2\u5F62\
    \u306Eclass\nusing Polygon = vector<Point>;\n\n// \u51F8\u5305\nPolygon convex_hull(vector<Point>\
    \ ps) {\n  int n = (int)ps.size(), k = 0;\n  if (n <= 2) return ps;\n  sort(ps.begin(),\
    \ ps.end());\n  vector<Point> ch(2 * n);\n  // \u53CD\u6642\u8A08\u5468\u308A\u306B\
    \u51F8\u5305\u3092\u69CB\u7BC9\u3057\u3066\u3044\u304F\n  for (int i = 0; i <\
    \ n; ch[k++] = ps[i++]) {\n    // \u6761\u4EF6\u5206\u5C90\u5185\u306Fwhile(k\
    \ >= 2 && ccw(ch[k-2],ch[k-1],ps[i]) != 1)\u3068\u7B49\u4FA1\n    while (k >=\
    \ 2 && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < EPS) --k;\n  }\n  for\
    \ (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) {\n    while (k >= t &&\
    \ cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < EPS) --k;\n  }\n  ch.resize(k\
    \ - 1);\n  return ch;\n}\n\n// \u591A\u89D2\u5F62\u306E\u9762\u7A4D\nReal area(const\
    \ Polygon &p) {\n  Real A = 0;\n  for (int i = 0; i < (int)p.size(); ++i) {\n\
    \    A += cross(p[i], p[(i + 1) % p.size()]);\n  }\n  return A * 0.5;\n}\n\nstruct\
    \ Circle {\n  Point p;\n  Real r;\n\n  Circle() = default;\n  Circle(Point p,\
    \ Real r) : p(p), r(r) {}\n};\n\nusing Circles = vector<Circle>;\n\nint intersect(Circle\
    \ c1, Circle c2) {\n  if (c1.r < c2.r) swap(c1, c2);\n  Real d = abs(c1.p - c2.p);\n\
    \  if (c1.r + c2.r < d) return 4;\n  if (eq(c1.r + c2.r, d)) return 3;\n  if (c1.r\
    \ - c2.r < d) return 2;\n  if (eq(c1.r - c2.r, d)) return 1;\n  return 0;\n}\n\
    \npair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {\n  Real\
    \ d = abs(c1.p - c2.p);\n  Real x = (c1.r * c1.r + d * d - c2.r * c2.r) / (2 *\
    \ c1.r * d);\n  if (abs(x) > 1) x = (x > 0 ? 1.0 : -1.0);\n  Real a = acos(x);\n\
    \  Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());\n  Point\
    \ p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);\n  Point p2 = c1.p\
    \ + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);\n  return {p1, p2};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry.hpp
layout: document
redirect_from:
- /library/geometry/geometry.hpp
- /library/geometry/geometry.hpp.html
title: geometry/geometry.hpp
---

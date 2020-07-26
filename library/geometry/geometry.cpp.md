---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: geometry/geometry.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed7daeb157cd9b31e53896ad3c771a26">geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/geometry/geometry.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-24 20:19:03+09:00




## Depends on

* :question: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

using Real = long double;
using Point = complex<Real>;
using Points = vector<Point>;
constexpr Real EPS = 1e-8;  // 問題によって変える！
constexpr Real pi = 3.141592653589793238462643383279L;
istream &operator>>(istream &is, Point &p) {
  Real a, b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}
ostream &operator<<(ostream &os, Point &p) {
  return os << real(p) << " " << imag(p);
}
inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

Point operator*(const Point &p, const Real &d) {
  return Point(real(p) * d, imag(p) * d);
}

namespace std {
bool operator<(const Point &a, const Point &b) {
  return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
}
}  // namespace std

Real cross(const Point &a, const Point &b) {
  return real(a) * imag(b) - imag(a) * real(b);
}
Real dot(const Point &a, const Point &b) {
  return real(a) * real(b) + imag(a) * imag(b);
}

// ccw 点の進行方向
int ccw(const Point &a, Point b, Point c) {
  b = b - a, c = c - a;
  if (cross(b, c) > EPS) return +1;   // 反時計回り
  if (cross(b, c) < -EPS) return -1;  // 時計回り
  if (dot(b, c) < 0) return +2;       // c-a-bの順で一直線
  if (norm(b) < norm(c)) return -2;   // a-b-cの順で一直線
  return 0;                           // a-c-bの順で一直線
}

// a-bベクトルとb-cベクトルのなす角度のうち小さい方を返す
// (ベクトル同士のなす角、すなわち幾何でいうところの「外角」であることに注意！)
// rem. 凸包に対して反時計回りにこの関数を適用すると、
// 凸包の大きさにかかわらず和が360度になる(いわゆる外角の和)(AGC021-B)
Real get_angle(const Point &a, const Point &b, const Point &c) {
  const Point v(b - a), w(c - b);
  Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
  if (alpha > beta) swap(alpha, beta);
  Real theta = (beta - alpha);
  return min(theta, 2 * acos(-1) - theta);
}

//　反時計回りである自己交差のない多角形のclass
using Polygon = vector<Point>;

// 凸包
Polygon convex_hull(vector<Point> ps) {
  int n = (int)ps.size(), k = 0;
  if (n <= 2) return ps;
  sort(ps.begin(), ps.end());
  vector<Point> ch(2 * n);
  // 反時計周りに凸包を構築していく
  for (int i = 0; i < n; ch[k++] = ps[i++]) {
    // 条件分岐内はwhile(k >= 2 && ccw(ch[k-2],ch[k-1],ps[i]) != 1)と等価
    while (k >= 2 && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < EPS) --k;
  }
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) {
    while (k >= t && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < EPS) --k;
  }
  ch.resize(k - 1);
  return ch;
}

// 多角形の面積
Real area(const Polygon &p) {
  Real A = 0;
  for (int i = 0; i < (int)p.size(); ++i) {
    A += cross(p[i], p[(i + 1) % p.size()]);
  }
  return A * 0.5;
}

struct Circle {
  Point p;
  Real r;

  Circle() = default;
  Circle(Point p, Real r) : p(p), r(r) {}
};

using Circles = vector<Circle>;

int intersect(Circle c1, Circle c2) {
  if (c1.r < c2.r) swap(c1, c2);
  Real d = abs(c1.p - c2.p);
  if (c1.r + c2.r < d) return 4;
  if (eq(c1.r + c2.r, d)) return 3;
  if (c1.r - c2.r < d) return 2;
  if (eq(c1.r - c2.r, d)) return 1;
  return 0;
}

pair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {
  Real d = abs(c1.p - c2.p);
  Real x = (c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d);
  if (abs(x) > 1) x = (x > 0 ? 1.0 : -1.0);
  Real a = acos(x);
  Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
  Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
  Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
  return {p1, p2};
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/geometry.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


#pragma once

#include "geometry-base.hpp"
#include "polygon.hpp"

struct Line {
  Point a, b;

  Line() = default;
  Line(const Point &_a, const Point &_b) : a(_a), b(_b) {}
  // Ax+By=C
  Line(const Real &A, const Real &B, const Real &C) {
    if (equals(A, 0)) {
      assert(!equals(B, 0));
      a = Point(0, C / B);
      b = Point(1, C / B);
    } else if (equals(B, 0)) {
      a = Point(C / A, 0);
      b = Point(C / A, 1);
    } else if (equals(C, 0)) {
      a = Point(0, C / B);
      b = Point(1, (C - A) / B);
    } else {
      a = Point(0, C / B);
      b = Point(C / A, 0);
    }
  }
  friend ostream &operator<<(ostream &os, const Line &l) {
    return os << l.a << " to " << l.b;
  }
  friend istream &operator>>(istream &is, Line &l) { return is >> l.a >> l.b; }
};
using Lines = vector<Line>;

bool is_parallel(const Line &a, const Line &b) {
  return equals(cross(a.b - a.a, b.b - b.a), 0);
}
bool is_orthogonal(const Line &a, const Line &b) {
  return equals(dot(a.a - a.b, b.a - b.b), 0);
}
Point cross_point_ll(const Line &l, const Line &m) {
  Real A = cross(l.b - l.a, m.b - m.a);
  Real B = cross(l.b - l.a, l.b - m.a);
  if (equals(abs(A), 0) && equals(abs(B), 0)) return m.a;
  return m.a + (m.b - m.a) * B / A;
}
bool is_intersect_ll(const Line &l, const Line &m) {
  Real A = cross(l.b - l.a, m.b - m.a);
  Real B = cross(l.b - l.a, l.b - m.a);
  if (equals(abs(A), 0) && equals(abs(B), 0)) return true;
  return !is_parallel(l, m);
}

// 直線に頂点から垂線を下ろした時の交点
Point projection(const Line &l, const Point &p) {
  Real t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + (l.a - l.b) * t;
}

// 凸包を直線で切った時の片方 (直線 a->b の進行方向左側) を返す
Polygon convex_polygon_cut(const Polygon &U, const Line &l) {
  Polygon ret;
  for (int i = 0; i < (int)U.size(); i++) {
    const Point &now = U[i];
    const Point &nxt = U[(i + 1) % U.size()];
    auto cf = cross(l.a - now, l.b - now);
    auto cs = cross(l.a - nxt, l.b - nxt);
    if (sign(cf) >= 0) {
      ret.emplace_back(now);
    }
    if (sign(cf) * sign(cs) < 0) {
      ret.emplace_back(cross_point_ll(Line(now, nxt), l));
    }
  }
  return ret;
}

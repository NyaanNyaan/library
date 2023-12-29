#pragma once

#include "geometry-base.hpp"

struct Circle {
  Point p;
  Real r;

  Circle() = default;
  Circle(Point _p, Real _r) : p(_p), r(_r) {}
};

using Circles = vector<Circle>;

int intersect(Circle c1, Circle c2) {
  if (c1.r < c2.r) swap(c1, c2);
  Real d = abs(c1.p - c2.p);
  if (c1.r + c2.r < d) return 4;
  if (equals(c1.r + c2.r, d)) return 3;
  if (c1.r - c2.r < d) return 2;
  if (equals(c1.r - c2.r, d)) return 1;
  return 0;
}

pair<Point, Point> crosspoint(const Circle& c1, const Circle& c2) {
  Real d = abs(c1.p - c2.p);
  Real x = (c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d);
  if (abs(x) > 1) x = (x > 0 ? 1.0 : -1.0);
  Real a = acos(x);
  Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
  Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
  Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
  return {p1, p2};
}

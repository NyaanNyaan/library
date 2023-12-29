#pragma once

#include "geometry-base.hpp"
//
#include "line.hpp"

struct Segment : Line {
  Segment() = default;
  using Line::Line;
};

using Segments = vector<Segment>;

bool is_intersect_sp(const Segment &s, const Point &p) {
  return ccw(s.a, s.b, p) == 0;
}
bool is_intersect_ss(const Segment &s, const Segment &t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
         ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

Real distance_sp(const Segment &s, const Point &p) {
  Point r = projection(s, p);
  if (is_intersect_sp(s, r)) return abs(r - p);
  return min(abs(s.a - p), abs(s.b - p));
}
Real distance_ss(const Segment &a, const Segment &b) {
  if (is_intersect_ss(a, b)) return 0;
  return min({distance_sp(a, b.a), distance_sp(a, b.b), distance_sp(b, a.a),
              distance_sp(b, a.b)});
}

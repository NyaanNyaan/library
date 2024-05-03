#pragma once

struct Point {
  using T = __int128_t;
  T x, y;
  Point() : x(0), y(0) {}
  Point(T x_, T y_) : x(x_), y(y_) {}

  Point &operator+=(const Point &p) {
    this->x += p.x;
    this->y += p.y;
    return *this;
  }

  Point &operator-=(const Point &p) {
    this->x -= p.x;
    this->y -= p.y;
    return *this;
  }

  int pos() const {
    if (y < 0) return -1;
    if (y == 0 && 0 <= x) return 0;
    return 1;
  }

  Point operator+(const Point &p) const { return Point(*this) += p; }
  Point operator-(const Point &p) const { return Point(*this) -= p; }
  Point operator-() const { return Point(-this->x, -this->y); }
  bool operator==(const Point &p) const { return x == p.x && y == p.y; }
  bool operator!=(const Point &p) const { return x != p.x || y != p.y; }
  bool operator<(const Point &p) const { return x == p.x ? y < p.y : x < p.x; }

  friend istream &operator>>(istream &is, Point &p) {
    long long x, y;
    is >> x >> y;
    p.x = x, p.y = y;
    return is;
  }

  friend ostream &operator<<(ostream &os, const Point &p) {
    os << (long long)(p.x) << " " << (long long)(p.y);
    return os;
  }
};
using Points = vector<Point>;

Point::T dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
Point::T cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

// sort by argument (-Pi ~ Pi)
void ArgumentSort(Points &v) {
  sort(begin(v), end(v), [](Point a, Point b) {
    if (a.pos() != b.pos()) return a.pos() < b.pos();
    return cross(a, b) > 0;
  });
}

// 1 ... counterclockwise / 0 straight / -1 clockwise
int ccw(const Point &a, const Point &b, const Point &c) {
  Point::T t = cross(b - a, c - a);
  return t < 0 ? -1 : t == 0 ? 0 : 1;
}

// v must have sorted by x-coordinate
Points LowerHull(const Points &ps) {
  int N = (int)ps.size();
  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);
  if (N <= 2) return ps;
  Points convex(N);
  int k = 0;
  for (int i = 0; i < N; convex[k++] = ps[i++]) {
    while (k >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i]) <= 0) --k;
  }
  convex.resize(k);
  return convex;
}

Points UpperHull(const Points &ps) {
  int N = (int)ps.size();
  for (int i = 0; i < N - 1; i++) assert(ps[i].x <= ps[i + 1].x);
  if (N <= 2) return ps;
  Points convex(N);
  int k = 0;
  for (int i = 0; i < N; convex[k++] = ps[i++]) {
    while (k >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i]) >= 0) --k;
  }
  convex.resize(k);
  return convex;
}

Points ConvexHull(Points ps) {
  sort(begin(ps), end(ps));
  ps.erase(unique(begin(ps), end(ps)), end(ps));
  int N = ps.size();
  if (N <= 2) return ps;
  Points convex(2 * N);
  int k = 0;
  for (int i = 0; i < N; convex[k++] = ps[i++]) {
    while (k >= 2 && ccw(convex[k - 2], convex[k - 1], ps[i]) <= 0) --k;
  }
  for (int i = N - 2, t = k + 1; i >= 0; convex[k++] = ps[i--]) {
    while (k >= t && ccw(convex[k - 2], convex[k - 1], ps[i]) <= 0) --k;
  }
  convex.resize(k - 1);
  return convex;
}

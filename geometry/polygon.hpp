#pragma once

#include "geometry-base.hpp"

using Polygon = vector<Point>;

// 多角形の内部に点があるか？
// OUT : 0, ON : 1, IN : 2
int contains_polygon(const Polygon &Q, const Point &p) {
  bool in = false;
  for (int i = 0; i < (int)Q.size(); i++) {
    Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
    if (imag(a) > imag(b)) swap(a, b);
    if (sign(imag(a)) <= 0 && 0 < sign(imag(b)) && sign(cross(a, b)) < 0)
      in = !in;
    if (equals(cross(a, b), 0) && sign(dot(a, b)) <= 0) return 1;
  }
  return in ? 2 : 0;
}

// 多角形の面積
Real area(const Polygon &p) {
  Real A = 0;
  for (int i = 0; i < (int)p.size(); ++i) {
    A += cross(p[i], p[(i + 1) % p.size()]);
  }
  return A * 0.5;
}

// 頂点集合から凸包を生成
// boundary : 周上の点も列挙する場合 true
template <bool boundary = false>
Polygon convex_hull(vector<Point> ps) {
  int n = (int)ps.size(), k = 0;
  if (n <= 2) return ps;
  sort(ps.begin(), ps.end());
  vector<Point> ch(2 * n);
  // 反時計周り
  Real th = boundary ? -EPS : +EPS;
  for (int i = 0; i < n; ch[k++] = ps[i++]) {
    while (k >= 2 && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < th) --k;
  }
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--]) {
    while (k >= t && cross(ch[k - 1] - ch[k - 2], ps[i] - ch[k - 1]) < th) --k;
  }
  ch.resize(k - 1);
  return ch;
}

// 凸包が与えられるので最遠点対を返す
// 返り値：頂点番号のペア
pair<int, int> convex_polygon_diameter(const Polygon &p) {
  int N = (int)p.size();
  int is = 0, js = 0;
  for (int i = 1; i < N; i++) {
    if (imag(p[i]) > imag(p[is])) is = i;
    if (imag(p[i]) < imag(p[js])) js = i;
  }
  Real maxdis = norm(p[is] - p[js]);

  int maxi, maxj, i, j;
  i = maxi = is;
  j = maxj = js;
  do {
    if (cross(p[(i + 1) % N] - p[i], p[(j + 1) % N] - p[j]) >= 0) {
      j = (j + 1) % N;
    } else {
      i = (i + 1) % N;
    }
    if (norm(p[i] - p[j]) > maxdis) {
      maxdis = norm(p[i] - p[j]);
      maxi = i;
      maxj = j;
    }
  } while (i != is || j != js);
  return minmax(maxi, maxj);
}
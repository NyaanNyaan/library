#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 0.000001
//
#include "../../template/template.hpp"
//
#include "../../geometry/polygon.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  Polygon p(N);
  in(p);
  auto [i, j] = convex_polygon_diameter(p);
  out(abs(p[i] - p[j]));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

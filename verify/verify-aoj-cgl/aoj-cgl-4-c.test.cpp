#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR 0.00001
//
#include "../../template/template.hpp"
//
#include "../../geometry/line.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  Polygon p(N);
  in(p);

  ini(Q);
  while (Q--) {
    Line l;
    in(l);
    out(area(convex_polygon_cut(p, l)));
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

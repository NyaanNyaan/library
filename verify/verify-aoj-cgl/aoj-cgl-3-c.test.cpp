#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"
//
#include "../../template/template.hpp"
//
#include "../../geometry/polygon.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  Polygon p(N);
  in(p);

  ini(Q);
  while (Q--) {
    Point q;
    in(q);
    out(contains_polygon(p, q));
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

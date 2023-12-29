#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0412"
//
#include "../../template/template.hpp"
//
#include "../../geometry/polygon.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  Polygon c(N);
  in(c);

  ini(Q);
  while (Q--) {
    Point p;
    in(p);
    p.x -= p.x / 10000;
    p.y -= p.y / 10000;
    out(contains_convex(c, p) ? 1 : 0);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

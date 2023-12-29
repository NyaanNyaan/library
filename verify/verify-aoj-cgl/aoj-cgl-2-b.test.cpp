#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"
//
#include "../../template/template.hpp"
//
#include "../../geometry/segment.hpp"
using namespace Nyaan;

void q() {
  ini(Q);
  while (Q--) {
    Point p0, p1, p2, p3;
    in(p0, p1, p2, p3);
    Segment s1{p0, p1}, s2{p2, p3};
    out(is_intersect_ss(s1, s2) ? 1 : 0);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

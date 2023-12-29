#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"
//
#include "../../template/template.hpp"
//
#include "../../geometry/line.hpp"
using namespace Nyaan;

void q() {
  ini(Q);
  while (Q--) {
    Point p0, p1, p2, p3;
    in(p0, p1, p2, p3);
    Line s1{p0, p1}, s2{p2, p3};
    if (is_parallel(s1, s2)) {
      out(2);
    } else if (is_orthogonal(s1, s2)) {
      out(1);
    } else {
      out(0);
    }
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

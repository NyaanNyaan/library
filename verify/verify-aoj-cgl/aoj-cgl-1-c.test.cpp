#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"
//
#include "../../template/template.hpp"
//
#include "../../geometry/geometry-base.hpp"
using namespace Nyaan;

void q() {
  Point p0, p1;
  cin >> p0 >> p1;
  ini(Q);
  while (Q--) {
    Point p2;
    cin >> p2;
    int c = ccw(p0, p1, p2);
    if (c == +1) {
      out("COUNTER_CLOCKWISE");
    } else if (c == -1) {
      out("CLOCKWISE");
    } else if (p0 != p2 and c == +2) {
      out("ONLINE_BACK");
    } else if (c == -2) {
      out("ONLINE_FRONT");
    } else {
      out("ON_SEGMENT");
    }
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

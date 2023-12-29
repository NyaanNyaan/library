#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR 0.00000001
//
#include "../../template/template.hpp"
//
#include "../../geometry/line.hpp"
using namespace Nyaan;

void q() {
  Point p1, p2;
  cin >> p1 >> p2;

  Line l{p1, p2};
  ini(Q);
  while (Q--) {
    Point p;
    in(p);
    out(projection(l, p) * 2 - p);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

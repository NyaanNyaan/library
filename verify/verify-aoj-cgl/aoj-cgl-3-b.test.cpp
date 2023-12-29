#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"
//
#include "../../template/template.hpp"
//
#include "../../geometry/polygon.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  Polygon p(N);
  in(p);
  rep(i, N) {
    if (ccw(p[(i - 1 + N) % N], p[i], p[(i + 1) % N]) == -1) die(0);
  }
  out(1);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

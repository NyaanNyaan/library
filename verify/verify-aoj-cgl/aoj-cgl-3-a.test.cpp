#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
//
#include "../../template/template.hpp"
//
#include "../../geometry/polygon.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  Polygon p(N);
  in(p);
  cout << setprecision(1);
  out(area(p));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
//
#include "../../template/template.hpp"
//
#include "../../geometry/polygon.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  Polygon p(N);
  in(p);
  auto c = convex_hull<true>(p);
  {
    auto it = min_element(all(c), [&](Point p0, Point p1) {
      return make_pair(p0.y, p0.x) < make_pair(p1.y, p1.x);
    });
    rotate(begin(c), it, end(c));
  }
  cout << setprecision(0);
  out(sz(c));
  each(x, c) out(x);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

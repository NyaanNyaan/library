#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"
//
#include "../../template/template.hpp"
//
#include "../../geometry/polygon.hpp"
using namespace Nyaan;

void q() {
  ini(N);
  V<Point> ps(N);
  in(ps);
  auto cv = convex_hull(ps);
  out(sz(cv));
  each2(x, y, cv) out(ll(x), ll(y));
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}

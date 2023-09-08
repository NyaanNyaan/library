#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"
//
#include "../../template/template.hpp"
//
#include "../../data-structure-2d/2d-segment-tree.hpp"
//
using namespace Nyaan;

void q() {
  int MAX = TEN(3) + 3;
  SegmentTree2D seg(
      MAX, MAX, [](int a, int b) { return a + b; }, 0);

  ini(N);
  rep(i, N) {
    ini(a, b, c, d);
    seg.update(a, b, seg.get(a, b) + 1);
    seg.update(a, d, seg.get(a, d) - 1);
    seg.update(c, b, seg.get(c, b) - 1);
    seg.update(c, d, seg.get(c, d) + 1);
  }
  int ans = 0;
  rep(i, MAX) rep(j, MAX) amax(ans, seg.query(0, 0, i + 1, j + 1));
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

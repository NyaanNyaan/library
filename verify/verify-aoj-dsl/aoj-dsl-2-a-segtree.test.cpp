#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "../../template/template.hpp"
#include "../../segment-tree/segment-tree.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, Q);
  int unit = (1LL << 31) - 1;
  auto f = [](int a, int b) { return min(a, b); };
  SegmentTree<int, decltype(f)> seg(N, f, unit);
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(i, a);
      seg.update(i, a);
    } else {
      ini(x, y);
      y++;
      out(seg.query(x, y));
    }
  }
}
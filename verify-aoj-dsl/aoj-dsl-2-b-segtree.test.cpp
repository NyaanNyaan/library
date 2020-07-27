#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../competitive-template.hpp"
#include "../segment-tree/segment-tree.hpp"

void solve() {
  ini(N, Q);
  auto f = [](int a, int b) { return a + b; };
  SegmentTree<int, decltype(f)> seg(N, f, 0);
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(i, a);
      i--;
      seg.add(i, a);
    } else {
      ini(x, y);
      x--;
      out(seg.query(x, y));
    }
  }
}
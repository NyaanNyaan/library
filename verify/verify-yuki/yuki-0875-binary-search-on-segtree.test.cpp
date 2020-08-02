#define PROBLEM "https://yukicoder.me/problems/no/875"

#include "../../competitive-template.hpp"
#include "../../segment-tree/segment-tree.hpp"

void solve() {
  ini(N, Q);
  vi a(N);
  in(a);
  auto f = [](int a, int b) { return min(a, b); };
  SegmentTree<int, decltype(f)> seg(a, f, inf);
  rep(_, Q) {
    ini(c, l, r);
    if (c == 1) {
      l--, r--;
      int vl = seg[l];
      seg.update(l, seg[r]);
      seg.update(r, vl);
    } else {
      l--;
      int mn = seg.query(l, r);
      int a1 = seg.find_first(l, [&](int n) { return n <= mn; });
      int a2 = seg.find_last(r, [&](int n) { return n <= mn; });
      assert(a1 == a2);
      out(a1 + 1);
    }
  }
}
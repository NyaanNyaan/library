#define PROBLEM "https://yukicoder.me/problems/no/875"

#include "../../template/template.hpp"
//
#include "../../segment-tree/segment-tree.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ini(N, Q);
  vi a(N);
  in(a);
  auto f = [](int s, int t) { return min(s, t); };
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
      int a1 = seg.max_right(l, [&](int n) { return n > mn; });
      int a2 = seg.min_left(r, [&](int n) { return n > mn; });
      a2--;
      assert(a1 == a2);
      out(a1 + 1);
    }
  }
}
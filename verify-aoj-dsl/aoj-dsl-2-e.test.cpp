#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "../competitive-template.cpp"
#include "../segment-tree/range-add-range-sum-lazyseg.cpp"

void solve() {
  ini(N, Q);
  int I = 0;
  AddSum_LazySegmentTree<int> seg(vi(N, I));
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(s, t, x);
      s--;
      seg.update(s, t, x);
    } else {
      ini(i);
      i--;
      out(seg.query(i, i + 1));
    }
  }
}
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include "../competitive-template.cpp"
#include "../segment-tree/range-update-range-sum-lazyseg.cpp"

void solve() {
  ini(N, Q);
  UpdateSum_LazySegmentTree<ll, infLL> seg{vl(N)};
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(s, t, x);
      t++;
      seg.update(s, t, x);
    } else {
      ini(s, t);
      t++;
      out(seg.query(s, t));
    }
  }
}
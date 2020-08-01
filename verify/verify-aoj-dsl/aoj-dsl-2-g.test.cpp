#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../competitive-template.hpp"
#include "../../segment-tree/range-add-range-sum-lazyseg.hpp"

void solve() {
  ini(N, Q);
  AddSum_LazySegmentTree<ll> seg({vl(N)});
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(s, t, x);
      s--;
      seg.update(s, t, x);
    } else {
      ini(s, t);
      s--;
      out(seg.query(s, t));
    }
  }
}
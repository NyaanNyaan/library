#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "../../template/template.hpp"
#include "../../segment-tree/range-update-range-max-lazyseg.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, Q);
  constexpr int I = (1LL << 31) - 1;
  UpdateMax_LazySegmentTree<int, -I> seg(vi(N, -I));
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(s, t, x);
      t++;
      seg.update(s, t, -x);
    } else {
      ini(s, t);
      t++;
      out(-seg.query(s, t));
    }
  }
}
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

#include "../../template/template.hpp"
#include "../../segment-tree/range-add-range-min-lazyseg.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, Q);
  AddMin_LazySegmentTree<int, inf> seg{vi(N)};
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
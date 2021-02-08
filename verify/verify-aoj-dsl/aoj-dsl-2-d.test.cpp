#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include "../../template/template.hpp"
//
#include "../../segment-tree/lazy-segment-tree-utility.hpp"

using namespace Nyaan; 
void Nyaan::solve() {
  ini(N, Q);
  int I = (1LL << 31) - 1;
  UpdateSum_LazySegmentTree<ll, infLL> seg{vl(N, I)};
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(s, t, x);
      t++;
      seg.update(s, t, x);
    } else {
      ini(i);
      out(seg.query(i, i + 1));
    }
  }
}
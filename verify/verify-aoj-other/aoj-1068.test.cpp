#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"
//
#include "../../template/template.hpp"
//
#include "../../data-structure-2d/2d-segment-tree.hpp"
#include "../../misc/rng.hpp"
using namespace Nyaan;

void q() {
  inl(R, C, Q);
  if (R == 0) exit(0);
  vvi A(R, vi(C));
  in(A);
  SegmentTree2D seg(
      R, C, [](int a, int b) { return min(a, b); }, int(PW(31) - 1));

  // set, update 両方 verify する苦肉の策
  if (rng() & 1) {
    rep(i, R) rep(j, C) seg.set(i, j, A[i][j]);
    seg.build();
  } else {
    rep(i, R) rep(j, C) seg.update(i, j, A[i][j]);
  }

  rep(_, Q) {
    inl(r1, c1, r2, c2);
    out(seg.query(r1, c1, r2 + 1, c2 + 1));
  }
}

void Nyaan::solve() {
  while (1) q();
}

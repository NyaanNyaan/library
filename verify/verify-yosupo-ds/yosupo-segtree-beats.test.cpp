#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/segment-tree-beats.hpp"
#include "../../misc/fastio.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  i64 N, Q;
  rd(N, Q);
  vector<i64> init(N);
  for (int i = 0; i < N; i++) rd(init[i]);
  AngelBeats seg(init);
  while (Q--) {
    i64 q;
    rd(q);
    if (q == 0) {
      i64 l, r, b;
      rd(l, r, b);
      seg.range_chmin(l, r, b);
    } else if (q == 1) {
      i64 l, r, b;
      rd(l, r, b);
      seg.range_chmax(l, r, b);
    } else if (q == 2) {
      i64 l, r, b;
      rd(l, r, b);
      seg.range_add(l, r, b);
    } else {
      i64 l, r;
      rd(l, r);
      wtn(seg.range_sum(l, r));
    }
  }
}

#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/segment-tree.hpp"
using namespace Nyaan;

void Nyaan::solve() {
  inl(N, Q);
  ins(S);
  using i8 = char;
  SegmentTree seg(
      V<i8>(N), [](i8 a, i8 b) { return a | b; }, i8{0});
  rep(i, N) if (S[i] == '1') seg.set(i, 1);
  seg.build();
  while (Q--) {
    inl(c, k);
    if (c == 0) {
      seg.update(k, 1);
    } else if (c == 1) {
      seg.update(k, 0);
    } else if (c == 2) {
      out(int(seg[k]));
    } else if (c == 3) {
      int ans = seg.max_right(k, [](i8 b) { return !b; });
      if (ans == N) ans = -1;
      out(ans);
    } else if (c == 4) {
      int ans = seg.min_left(k + 1, [](i8 b) { return !b; });
      --ans;
      out(ans);
    }
  }
}
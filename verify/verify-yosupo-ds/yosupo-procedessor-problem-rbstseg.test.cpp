#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/rbst-segment-tree.hpp"
//
using namespace Nyaan;

bool f(bool a, bool b) { return a | b; }
bool ti() { return false; }
using Seg = RBSTSegmentTree<ll, bool, f, ti>;

void Nyaan::solve() {
  inl(N, Q);
  string T;
  in(T);

  vector<bool> v(N);
  rep(i, N) v[i] = T[i] == '1';

  Seg seg{v};
  while (Q--) {
    ini(cmd, k);
    if (cmd == 0) {
      seg.set_val(k, true);
    } else if (cmd == 1) {
      seg.set_val(k, false);
    } else if (cmd == 2) {
      out(seg.get_val(k));
    } else if (cmd == 3) {
      int r = seg.max_right(
          k, [](bool b) { return !b; }, N);
      int r2 = seg.max_right_inclusive(
          k, [](bool b) { return !b; }, k - 1);
      if (r2 + 1 != r) exit(1);
      if (r == N) r = -1;
      out(r);
    } else if (cmd == 4) {
      int l = seg.min_left_exclusive(
          k + 1, [](bool b) { return !b; }, -1);
      int l2 = seg.min_left(
          k + 1, [](bool b) { return !b; }, k + 1);
      if (l + 1 != l2) exit(1);
      out(l);
    }
  }
}

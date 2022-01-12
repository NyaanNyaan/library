#define PROBLEM "https://yukicoder.me/problems/no/1786"

#include "../../template/template.hpp"
//
#include "../../segment-tree/rbst-segment-tree.hpp"
//
using namespace Nyaan;

int f(int a, int b) { return max(a, b); }
int g(int a, int b) { return a + b; }
int ti() { return -inf; }
int ei() { return 0; }
using Seg = RBSTLazySegmentTree<ll, int, int, f, g, g, ti, ei>;

void Nyaan::solve() {
  inl(N);
  int pre = 0;
  Seg seg;
  rep(i, N) {
    inl(A);
    A ^= pre;
    int mx = seg.fold(A, infLL);
    int sc = max(0, mx + 1);
    seg.apply(0, A, 1);
    seg.apply(A, infLL, -1);
    seg.set_val(A, sc);
    ll ans = seg.min_left_exclusive(
        infLL, [](int x) { return x < 0; }, -infLL);
    out(ans);
    pre = ans;
  }
}

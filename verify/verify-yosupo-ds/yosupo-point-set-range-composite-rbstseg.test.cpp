#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
//
#include "../../template/template.hpp"
//
#include "../../math/affine-transformation.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../segment-tree/rbst-segment-tree.hpp"
//
using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;
using A = Affine<mint>;

A f(A a, A b) { return a * b; }
A ti() { return A{}; }
using Seg = RBSTSegmentTree<int, A, f, ti>;

void Nyaan::solve() {
  inl(N, Q);
  V<A> a(N);
  rep(i, N) {
    inl(c, d);
    a[i] = {c, d};
  }
  Seg seg{a};
  rep(_, Q) {
    inl(cmd);
    if (cmd == 0) {
      inl(p, c, d);
      seg.set_val(p, {c, d});
    } else {
      inl(l, r, x);
      out(seg.fold(l, r)(x));
    }
  }
}

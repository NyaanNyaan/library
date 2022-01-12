#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../template/template.hpp"
//
#include "../../segment-tree/rbst-segment-tree.hpp"
//
#include "../../math/affine-transformation.hpp"
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
using T = pair<mint, mint>;
using E = Affine<mint>;
T f(T a, T b) { return T(a.first + b.first, a.second + b.second); }
T g(T a, E b) { return T(a.first * b.a + a.second * b.b, a.second); }
E h(E a, E b) { return a * b; };
T ti() { return T{}; }
E ei() { return E{}; }
using Seg = RBSTLazySegmentTree<ll, T, E, f, g, h, ti, ei>;

void Nyaan::solve() {
  inl(N, Q);
  vl A(N);
  in(A);

  V<T> init(N);
  rep(i, N) init[i] = {A[i], 1};
  Seg seg{init};

  while (Q--) {
    inl(cmd);
    if (cmd == 0) {
      inl(l, r, b, c);
      seg.apply(l, r, {b, c});
    } else {
      inl(l, r);
      out(seg.fold(l, r).first);
    }
  }
}

#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../template/template.hpp"
//
#include "../../math/affine-transformation.hpp"
#include "../../modint/montgomery-modint.hpp"
//
#include "../../segment-tree/dynamic-segment-tree.hpp"

using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;
using T = pair<mint, mint>;
using E = Affine<mint>;
T f(T a, T b) { return T(a.first + b.first, a.second + b.second); }
T g(T a, E b) { return T(a.first * b.a + a.second * b.b, a.second); }
E h(E a, E b) { return a * b; };
T ti() { return T{}; }
E ei() { return E{}; }
using Trie = DynamicLazySegmentTree<T, E, f, g, h, ti, ei>;

void Nyaan::solve() {
  inl(N, Q);
  Trie t(N);
  rep(i, N) {
    inl(a);
    t.set_val(i, {a, 1});
  }
  while (Q--) {
    inl(cmd);
    if (cmd == 0) {
      inl(l, r, b, c);
      t.apply(l, r, {b, c});
    } else {
      inl(l, r);
      out(t.fold(l, r).first);
    }
  }
}

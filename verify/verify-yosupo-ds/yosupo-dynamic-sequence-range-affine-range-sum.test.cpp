#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include "../../template/template.hpp"
//
#include "../../rbst/lazy-reversible-rbst.hpp"
//
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
#include "../../math/affine-transformation.hpp"
#include "../../misc/fastio.hpp"

using T = pair<mint, mint>;
using E = Affine<mint>;
T f(T a, T b) { return T(a.first + b.first, a.second + b.second); }
T g(T a, E b) { return T(b.a * a.first + b.b * a.second, a.second); }
E h(E a, E b) { return a * b; }
T ts(T a) { return a; }

using namespace Nyaan;
void Nyaan::solve() {
  int N, Q;
  rd(N, Q);

  V<T> a(N);
  each(i, a) {
    int n;
    rd(n);
    i = mkp(n, 1);
  }

  LazyReversibleRBST<T, E, f, g, h, ts> rbst;
  auto root = rbst.build(a);

  while (Q--) {
    int cmd;
    rd(cmd);
    if (cmd == 0) {
      int i, x;
      rd(i, x);
      rbst.insert(root, i, T(x, 1));
    } else if (cmd == 1) {
      int i;
      rd(i);
      rbst.erase(root, i);
    } else if (cmd == 2) {
      int l, r;
      rd(l, r);
      rbst.reverse(root, l, r);
    } else if (cmd == 3) {
      int l, r, b, c;
      rd(l, r, b, c);
      rbst.apply(root, l, r, E(b, c));
    } else {
      int l, r;
      rd(l, r);
      wtn(rbst.fold(root, l, r).first.get());
    }
  }
}

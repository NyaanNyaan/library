#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
#include "../../math/affine-transformation.hpp"
#include "../../misc/fastio.hpp"
//
#include "../../lct/link-cut-tree-lazy.hpp"
//

using T = pair<mint, mint>;
using E = Affine<mint>;
T f(T a, T b) { return T(a.first + b.first, a.second + b.second); }
T g(T a, E b) { return T(a.first * b.a + a.second * b.b, a.second); }
E h(E a, E b) { return a * b; };
T ts(T a) { return a; }

using namespace Nyaan;
void Nyaan::solve() {
  int N, Q;
  rd(N, Q);

  using LCT = LazyLinkCutTree<T, E, f, g, h, ts>;
  LCT lct;

  vector<LCT::Ptr> vs(N);
  rep(i, N) {
    int a;
    rd(a);
    vs[i] = lct.my_new(T(a, 1));
  }

  for (int i = 1; i < N; i++) lct.link(vs[i - 1], vs[i]);

  while (Q--) {
    int cmd;
    rd(cmd);
    if (cmd == 0) {
      int l, r, b, c;
      rd(l, r, b, c);
      lct.apply(vs[l], vs[r - 1], E(b, c));
    } else {
      int l, r;
      rd(l, r);
      T fold = lct.fold(vs[l], vs[r - 1]);
      wtn(fold.first.get());
    }
  }
}

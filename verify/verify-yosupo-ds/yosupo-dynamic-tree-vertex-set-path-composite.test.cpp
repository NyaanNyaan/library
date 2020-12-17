#define PROBLEM "https://old.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
#include "../../math/affine-transformation.hpp"
#include "../../misc/fastio.hpp"
//
#include "../../lct/link-cut-base.hpp"
#include "../../lct/splay-reversible.hpp"
//
using Af = Affine<mint>;
using T = pair<Af, Af>;
T f(T a, T b) { return T(a.first * b.first, b.second * a.second); }
T ts(T a) { return T(a.second, a.first); }

using namespace Nyaan;
void Nyaan::solve() {
  int N, Q;
  rd(N, Q);

  using Splay = ReversibleSplayTree<T, f, ts>;
  using LCT = LinkCutTree<Splay>;
  LCT lct;

  vector<LCT::Ptr> vs(N);
  rep(i, N) {
    int a, b;
    rd(a, b);
    vs[i] = lct.my_new(T(Af(a, b), Af(a, b)));
  }

  for (int i = 1; i < N; i++) {
    int a, b;
    rd(a, b);
    lct.evert(vs[a]);
    lct.link(vs[a], vs[b]);
  }
  while (Q--) {
    int cmd;
    rd(cmd);
    if (cmd == 0) {
      int U, V, W, X;
      rd(U, V, W, X);
      lct.evert(vs[U]);
      lct.cut(vs[V]);
      lct.evert(vs[W]);
      lct.link(vs[W], vs[X]);
    } else if (cmd == 1) {
      int P, a, b;
      rd(P, a, b);
      lct.expose(vs[P]);
      vs[P]->key = T(Af(a, b), Af(a, b));
      lct.update(vs[P]);
    } else {
      int U, V, X;
      rd(U, V, X);
      lct.evert(vs[U]);
      lct.expose(vs[V]);
      auto ret = vs[V]->sum.first;
      wtn(ret(X).get());
    }
  }
}

#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
#include "../../math/affine-transformation.hpp"
#include "../../misc/fastio.hpp"
//
#include "../../lct/link-cut-tree.hpp"
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

  using LCT = LinkCutTree<T, f, ts>;
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
    lct.link(vs[a], vs[b]);
  }
  while (Q--) {
    int cmd;
    rd(cmd);
    if (cmd == 0) {
      int U, V, W, X;
      rd(U, V, W, X);
      lct.cut(vs[U], vs[V]);
      lct.link(vs[W], vs[X]);
    } else if (cmd == 1) {
      int P, a, b;
      rd(P, a, b);
      lct.set_key(vs[P], T(Af(a, b), Af(a, b)));
    } else {
      int U, V, X;
      rd(U, V, X);
      T fold = lct.fold(vs[U], vs[V]);
      wtn(fold.first(X).get());
    }
  }
}

#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

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

using T = long long;
T f(T a, T b) { return a + b; }
T ts(T a) { return a; }

using namespace Nyaan;
void Nyaan::solve() {
  int N, Q;
  rd(N, Q);

  using Splay = ReversibleSplayTree<T, f, ts>;
  using LCT = LinkCutTree<Splay>;
  LCT lct;

  vector<LCT::Ptr> vs(N);
  rep(i, N) {
    int a;
    rd(a);
    vs[i] = lct.my_new(a);
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
      int u, v, w, x;
      rd(u, v, w, x);
      lct.cut(vs[u], vs[v]);
      lct.link(vs[w], vs[x]);
    } else if (cmd == 1) {
      int u, x;
      rd(u, x);
      lct.vertex_set(vs[u], lct.vertex_get(vs[u]) + x);
    } else {
      int u, v;
      rd(u, v);
      T fold = lct.fold(vs[u], vs[v]);
      wtn(fold);
    }
  }
}

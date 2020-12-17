#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum"

#include "../../template/template.hpp"
//
#include "../../lct/link-cut-tree-subtree.hpp"

using namespace Nyaan;

using T = ll;
T f(ll a, ll b) { return a + b; }
T finv(ll a, ll b) { return a - b; }

#include "../../misc/fastio.hpp"
void Nyaan::solve() {
  using LCT = LinkCutTreeSubtreeQuery<T, f, finv>;
  LCT lct;

  int N, Q;
  rd(N, Q);

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
      int v, p;
      rd(v, p);
      lct.evert(vs[p]);
      wtn(lct.subtree(vs[v]));
    }
  }
}

#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum"

#include "../../template/template.hpp"
//
#include "../../lct/link-cut-tree-subtree-add.hpp"

using namespace Nyaan;
ll add(ll a, ll b) { return a + b; }
ll sub(ll a, ll b) { return a - b; }
ll mul(ll a, ll b) { return a * b; }

#include "../../misc/fastio.hpp"
void Nyaan::solve() {
  using LCT = LinkCutTreeSubtreeQuery<ll, add, sub, mul>;
  LCT lct;

  int N, Q;
  rd(N, Q);

  vector<LCT::Ptr> vs(N);
  rep(i, N) {
    int a;
    rd(a);
    vs[i] = new LCT::Node(a);
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
      int v, p, x;
      rd(v, p, x);
      lct.evert(vs[p]);
      lct.subtree_add(vs[v], x);
    } else {
      int v, p;
      rd(v, p);
      lct.evert(vs[p]);
      wtn(lct.subtree_sum(vs[v]));
    }
  }
}

#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"

#include "../../template/template.hpp"
//
#include "../../graph/offline-dynamic-connectivity.hpp"
#include "../../lct/link-cut-tree-subtree.hpp"

using namespace Nyaan;

ll add(ll a, ll b) { return a + b; }
ll sub(ll a, ll b) { return a - b; }

void Nyaan::solve() {
  ini(N, Q);
  vl a(N);
  in(a);
  vl cmd(Q), X(Q), Y(Q);
  rep(i, Q) {
    in(cmd[i], X[i]);
    if (cmd[i] != 3) in(Y[i]);
  }

  using LCT = LinkCutTreeSubtreeQuery<ll, add, sub>;
  LCT lct;
  vector<LCT::Node*> vs(N);
  rep(i, N) vs[i] = new LCT::Node(a[i]);

  OffLineDynamicConnectivity dc(N, Q);
  rep(i, Q) {
    if (cmd[i] == 0) dc.add_edge(i, X[i], Y[i]);
    if (cmd[i] == 1) dc.del_edge(i, X[i], Y[i]);
  }
  dc.build();
  vl ans;
  auto add = [&](int u, int v) { lct.link(vs[u], vs[v]); };
  auto del = [&](int u, int v) { lct.cut(vs[u], vs[v]); };
  auto query = [&](int i) {
    if (cmd[i] == 2) {
      ll k = lct.get_key(vs[X[i]]);
      lct.set_key(vs[X[i]], k + Y[i]);
    } else if (cmd[i] == 3) {
      lct.evert(vs[X[i]]);
      ans.emplace_back(lct.subtree(vs[X[i]]));
    }
  };

  dc.run(add, del, query);
  each(x, ans) out(x);
}

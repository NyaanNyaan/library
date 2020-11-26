#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../competitive-template.hpp"
#include "../../data-structure/binary-indexed-tree.hpp"
#include "../../graph/static-graph.hpp"
#include "../../misc/fastio.hpp"
#include "../../tree/dsu-on-tree.hpp"

void solve() {
  int N, Q;
  rd(N, Q);
  vector<int> a(N);
  rep(i, N) rd(a[i]);

  StaticGraph<void> g(N, N - 1);
  rep1(i, N - 1) {
    int p;
    rd(p);
    g.add_edge(p, i);
  }

  V<V<pair<int, int>>> upd(N);
  V<V<int>> que(N);

  rep(i, N) upd[i].emplace_back(0, a[i]);
  rep1(i, Q) {
    int c, u;
    rd(c, u);
    if (c == 0) {
      int x;
      rd(x);
      upd[u].emplace_back(i, x);
    } else {
      que[u].push_back(i);
    }
  }

  BinaryIndexedTree<ll> bit(Q + 1);
  vl ans(Q + 1, infLL);

  // reflect data of node i
  auto update = [&](int i) {
    for (auto&& [j, x] : upd[i]) bit.add(j, x);
  };
  // answer queries of subtree i
  auto query = [&](int i) {
    for (auto&& j : que[i]) ans[j] = bit.sum(j);
  };
  // below two function are called if all data must be deleted
  // delete data of node i (if necesarry)
  auto clear = [&](int i) {
    for (auto&& [j, x] : upd[i]) bit.add(j, -x);
  };
  // delete data related to all (if necesarry)
  auto reset = [&]() {

  };

  DSUonTree<decltype(g)> dsu(g);
  dsu.run(update, query, clear, reset);
  each(x, ans) if (x != infLL) wtn(x);
}

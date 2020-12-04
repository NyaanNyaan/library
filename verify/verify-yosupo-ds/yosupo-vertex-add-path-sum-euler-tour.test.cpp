#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../template/template.hpp"
#include "../../data-structure/binary-indexed-tree.hpp"
#include "../../graph/static-graph.hpp"
#include "../../misc/fastio.hpp"
#include "../../misc/rng.hpp"
#include "../../tree/euler-tour.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int N, Q;
  rd(N, Q);
  vector<int> a(N);
  rep(i, N) rd(a[i]);

  StaticGraph<void> g(N, 2 * N - 2);
  rep(i, N - 1) {
    int u, v;
    rd(u, v);
    g.add_edge(u, v);
    g.add_edge(v, u);
  }

  EulerTour<decltype(g)> et(g, randint(0, N));
  BinaryIndexedTree<ll> bit(et.size());

  rep(i, N) {
    auto&& [d, u] = et.idx(i);
    bit.add(d, a[i]);
    bit.add(u, -a[i]);
  }
  rep(i, Q) {
    int c, x, y;
    rd(c, x, y);
    if (c == 0) {
      auto&& [d, u] = et.idx(x);
      bit.add(d, y);
      bit.add(u, -y);
    } else {
      ll ans = 0;
      auto f = [&](int u, int v) { ans += bit.sum(u, v - 1); };
      et.node_query(x, y, f);
      wtn(ans);
    }
  }
}

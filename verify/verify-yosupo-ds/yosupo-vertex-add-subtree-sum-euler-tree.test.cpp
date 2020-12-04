#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../template/template.hpp"
#include "../../data-structure/binary-indexed-tree.hpp"
#include "../../graph/static-graph.hpp"
#include "../../misc/fastio.hpp"
#include "../../tree/euler-tour.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int N, Q;
  rd(N, Q);
  vector<int> a(N);
  rep(i, N) rd(a[i]);

  vvi g(N);
  rep1(i, N - 1) {
    int p;
    rd(p);
    g[p].push_back(i);
  }

  EulerTour<decltype(g)> et(g);
  BinaryIndexedTree<ll> bit(et.size());

  rep(i, N) {
    auto&& [d, u] = et.idx(i);
    bit.add(d, a[i]);
  }
  rep(i, Q) {
    int c;
    rd(c);
    if (c == 0) {
      int x, y;
      rd(x, y);
      auto&& [d, u] = et.idx(x);
      bit.add(d, y);
    } else {
      int x;
      rd(x);
      ll ans = 0;
      auto f = [&](int u, int v) { ans += bit.sum(u, v - 1); };
      et.subtree_query(x, f);
      wtn(ans);
    }
  }
}

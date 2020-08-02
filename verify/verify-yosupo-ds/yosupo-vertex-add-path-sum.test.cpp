#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../competitive-template.hpp"
#include "../../segment-tree/segment-tree.hpp"
#include "../../tree/heavy-light-decomposition.hpp"

void solve() {
  ini(N, Q);
  vl a(N);
  in(a);
  auto g = graph(N, N - 1, false, false);

  HeavyLightDecomposition<vvi> hld(g);
  auto f = [](ll a, ll b) { return a + b; };
  SegmentTree<ll, decltype(f)> seg(N, f, 0);
  rep(i, N) { seg.set(hld.in[i], a[i]); }
  seg.build();

  ll ans = 0;
  auto que = [&](int u, int v) { ans += seg.query(u, v); };

  rep(_, Q) {
    ini(cmd, u, v);
    if (cmd) {
      ans = 0;
      hld.node_query(u, v, que);
      out(ans);
    } else {
      seg.add(hld.in[u], v);
    }
  }
}
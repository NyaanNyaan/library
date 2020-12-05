#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../template/template.hpp"
#include "../../segment-tree/segment-tree.hpp"
#include "../../tree/heavy-light-decomposition.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, Q);
  vl a(N);
  in(a);
  vvi g(N);
  rep1(u, N - 1) {
    ini(v);
    g[u].push_back(v);
    g[v].push_back(u);
  }

  HeavyLightDecomposition<vvi> hld(g);
  auto f = [](ll a, ll b) { return a + b; };
  SegmentTree<ll, decltype(f)> seg(N, f, 0);
  rep(i, N) { seg.set(hld.idx(i).first, a[i]); }
  seg.build();

  ll ans = 0;
  auto que = [&](int u, int v) { ans += seg.query(u, v); };

  rep(_, Q) {
    ini(cmd);
    if (cmd) {
      ini(u);
      ans = 0;
      hld.subtree_query(u, true, que);
      out(ans);
    } else {
      inl(k, x);
      seg.add(hld.idx(k).first, x);
    }
  }
}
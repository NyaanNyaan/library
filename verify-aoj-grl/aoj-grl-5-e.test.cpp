#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"

#include "../competitive-template.hpp"
#include "../segment-tree/range-add-range-sum-lazyseg.hpp"
#include "../segment-tree/segment-tree.hpp"
#include "../tree/heavy-light-decomposition.hpp"

void solve() {
  ini(N);
  vvi g(N);
  rep(i, N) {
    ini(n);
    g[i].resize(n);
    in(g[i]);
  }

  HeavyLightDecomposition<vvi> hld(g);
  AddSum_LazySegmentTree<ll> seg(vl(N, 0));
  ll W = 0;
  auto add = [&](int u, int v) { seg.update(u, v, W); };
  ll ans = 0;
  auto query = [&](int u, int v) { ans += seg.query(u, v); };

  ini(Q);
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      inl(v, w);
      W = w;
      hld.edge_query(0, v, add);
    } else {
      ini(v);
      ans = 0;
      hld.edge_query(0, v, query);
      out(ans);
    }
  }
}
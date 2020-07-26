#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include "../competitive-template.cpp"
#include "../segment-tree/segment-tree.cpp"
#include "../tree/heavy-light-decomposition.cpp"
void solve() {
  ini(N);
  vvi g(N);
  rep(i, N) {
    ini(n);
    g[i].resize(n);
    in(g[i]);
  }

  HeavyLightDecomposition<vvi> hld(g);
  auto f = [](int a, int b) { return a + b; };
  SegmentTree<int, decltype(f)> seg(N, f, 0);
  int ans = 0;
  auto q = [&](int u, int v) { ans += seg.query(u, v); };

  ini(Q);
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(v, w);
      seg.add(hld.in[v], w);
    } else {
      ini(v);
      ans = 0;
      hld.edge_query(0, v, q);
      out(ans);
    }
  }
}
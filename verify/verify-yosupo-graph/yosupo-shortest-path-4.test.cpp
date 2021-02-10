#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../template/template.hpp"
//
#include "../../shortest-path/dijkstra-skew-heap.hpp"
//
#include "../../misc/fastio.hpp"

void Nyaan::solve() {
  int N, M, s, t;
  rd(N, M, s, t);

  StaticGraph<ll> g(N, M);
  rep(i, M) {
    int a, b, c;
    rd(a, b, c);
    g.add_edge(a, b, c);
  }

  auto d = dijkstra_restore(g, s);

  if (d[t].first == -1) {
    wtn(-1);
    return;
  }
  vi ans;
  for (int r = t; r != s; r = d[r].second) ans.push_back(r);
  ans.push_back(s);
  wt(d[t].first, ' ', sz(ans) - 1, '\n');
  repr(i, sz(ans) - 1) wt(ans[i + 1], ' ', ans[i], '\n');
}
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
//
#include "../../template/template.hpp"
//
#include "../../graph/graph-utility.hpp"
//
#include "../../shortest-path/dijkstra-abstruct.hpp"
using namespace Nyaan;

void q() {
  inl(N, M, S, T);
  auto g = wgraph<ll>(N, M, true, false);

  auto res = dijkstra_abstruct<int, ll>(
      [&](int c, ll cd, auto add) { each(e, g[c]) add(e.to, cd + e.cost); }, S,
      T);
  if (!res.reachable) die(-1);
  out(res.dist, sz(res.path) - 1);
  rep(i, sz(res.path) - 1) out(res.path[i], res.path[i + 1]);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

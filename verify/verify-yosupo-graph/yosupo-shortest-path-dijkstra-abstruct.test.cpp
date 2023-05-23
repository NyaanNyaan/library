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

  auto d = dijkstra_abstruct<int, ll>(
      [&](int c, ll cd, auto add) { each(e, g[c]) add(e.to, cd + e.cost); }, S,
      T);
  if (d.count(T) == 0) die(-1);
  vi path;
  for (int x = T; x != S; x = d[x].second) path.push_back(x);
  path.push_back(S);
  reverse(all(path));

  out(d[T].first, sz(path) - 1);
  rep(i, sz(path) - 1) out(path[i], path[i + 1]);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../template/template.hpp"
#include "../../graph/graph-utility.hpp"
#include "../../shortest-path/dijkstra.hpp"
#include "../../shortest-path/restore-shortest-path.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, M, S, T);
  auto g = wgraph<ll>(N, M, true, false);
  auto d = dijkstra<ll>(g, S);
  if (d[T] == -1) die(-1);
  auto p = restore_shortest_path<ll>(g, d, S, T);
  out(d[T], sz(p) - 1);
  rep(i, sz(p) - 1) out(p[i], p[i + 1]);
}
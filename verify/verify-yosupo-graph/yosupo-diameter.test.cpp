#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../template/template.hpp"
#include "../../graph/graph-utility.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N);
  auto g = wgraph<ll>(N, N - 1, false, false);
  auto diam = Diameter<ll>(g);
  auto path = Path(g, diam.first.first, diam.first.second);
  out(diam.second, path.size());
  out(path);
}
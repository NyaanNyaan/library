#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../competitive-template.cpp"
#include "../graph/graph-utility.cpp"

void solve() {
  ini(N);
  auto g = wgraph<ll>(N, N - 1, false, false);
  auto diam = Diameter<ll>(g);
  auto path = Path(g, diam.first.first, diam.first.second);
  out(diam.second, path.size());
  out(path);
}
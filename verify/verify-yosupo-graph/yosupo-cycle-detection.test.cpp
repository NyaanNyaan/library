#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "../../template/template.hpp"
//
#include "../../graph/cycle-detection.hpp"
#include "../../graph/graph-template.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ini(N, M);
  vvi g(N);
  auto idx = [&](pl p) { return (p.first << 20) + p.second; };
  map<ll, vector<int>> m;
  rep(_, M) {
    ini(u, v);
    m[idx(pl(u, v))].push_back(_);
    g[u].push_back(v);
  }
  auto cycle = CycleDetection<vvi>(g);
  if (cycle.empty()) die(-1);
  out(sz(cycle));
  each(p, cycle) {
    auto& v = m[idx(pl(p.first, p.second))];
    out(v.back());
    v.pop_back();
  }
}

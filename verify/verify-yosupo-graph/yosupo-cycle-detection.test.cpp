#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "../../competitive-template.hpp"
#include "../../graph/cycle-detection.hpp"
#include "../../graph/graph-template.hpp"

void solve() {
  ini(N, M);
  vvi g(N);
  auto idx = [&](pair<ll, ll> p) { return (p.first << 20) + p.second; };
  map<ll, vector<int>> m;
  rep(_, M) {
    ini(u, v);
    m[idx(P(u, v))].pb(_);
    g[u].pb(v);
  }
  auto cycle = CycleDetection<vvi>(g);
  if (cycle.empty()) die(-1);
  trc(cycle);
  out(sz(cycle));
  each(p, cycle) {
    auto& v = m[idx(P(p.first, p.second))];
    out(v.back());
    v.pop_back();
  }
}

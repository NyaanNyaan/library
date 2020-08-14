#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "../../competitive-template.hpp"
#include "../../graph/cycle-detection.hpp"
#include "../../graph/graph-template.hpp"

template <typename G>
vector<pair<int, int>> CycleDetection(const G& g, bool directed = true) {
  vector<int> pidx(g.size(), -1), vis(g.size(), 0);

  vector<pair<int, int>> cycle;
  int finish = 0;
  auto dfs = [&](auto rec, int cur, int pval, int par) -> int {
    pidx[cur] = pval;
    vis[cur] = 1;
    for (auto& dst : g[cur]) {
      if (finish) return -1;
      if (!directed && dst == par) continue;
      if (pidx[dst] == pidx[cur]) {
        cycle.emplace_back(cur, dst);
        return dst;
      }
      if (vis[dst]) continue;
      int nx = rec(rec, dst, pval, cur);
      trc(cur, dst, nx);
      if (nx != -1) {
        cycle.emplace_back(cur, dst);
        if (cur == nx) {
          finish = 1;
          return -1;
        }
        return nx;
      }
    }
    pidx[cur] = -1;
    return -1;
  };

  for (int i = 0; i < (int)g.size(); i++) {
    if (vis[i]) continue;
    dfs(dfs, i, i, -1);

    if (finish) {
      reverse(begin(cycle), end(cycle));
      return cycle;
    }
  }
  return vector<pair<int, int>>{};
}

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

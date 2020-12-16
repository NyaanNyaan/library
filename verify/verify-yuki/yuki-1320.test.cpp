#define PROBLEM "https://yukicoder.me/problems/no/1320"

#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../graph/graph-template.hpp"
#include "../../shortest-path/dijkstra-fast.hpp"

void Nyaan::solve() {
  ini(t, n, m);
  Edges<ll> es;
  rep(i, m) {
    inl(u, v, w);
    --u, --v;
    es.emplace_back(u, v, w);
  }

  ll ans = infLL;
  rep(id, m) {
    StaticGraph<ll> g(n, (m - 1) * (1 + !t));
    rep(j, m) {
      if (id == j) continue;
      ll u = es[j].src, v = es[j].to, w = es[j].cost;
      g.add_edge(u, v, w);
      if (!t) g.add_edge(v, u, w);
    }
    int i = es[id].to, j = es[id].src, k = es[id].cost;
    auto d = dijkstra_point(g, i, j);
    if (~d) amin(ans, k + d);
  }

  out(ans == infLL ? -1 : ans);
}

#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"

#include "../../template/template.hpp"
//
#include "../../graph/minimum-cost-arborescence.hpp"
//
using namespace Nyaan;

void Nyaan::solve() {
  ini(n, m, r);
  Edges<ll> es;
  while (m--) {
    inl(u, v, c);
    es.emplace_back(u, v, c);
  }
  auto res = MinimumCostArborescence(n, r, es);

  ll cost = 0;
  vi ans(n, -1);
  ans[r] = r;

  each(e, res) {
    cost += e.cost;
    ans[e.to] = e.src;
  }

  out(cost);
  out(ans);
}

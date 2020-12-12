#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../atcoder/maxflow.hpp"
#include "../../template/template.hpp"
#include "../../flow/flow-on-bipartite-graph.hpp"
#include "../../misc/fastio.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int L, R, M;
  rd(L, R, M);
  BipartiteGraph graph(L, R);
  rep(i, M) {
    int u, v;
    rd(u, v);
    graph.add_edge(u, v);
  }
  wtn(graph.flow());
  for (auto &e : graph.MaximumMatching()) {
    wt(e.first, ' ', e.second, '\n');
  }
}
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../atcoder/maxflow.hpp"
#include "../../competitive-template.hpp"
#include "../../flow/flow-on-bipartite-graph.hpp"
#include "../../misc/fastio.hpp"

void solve() {
  int L, R, M;
  rd(L, R, M);
  BipartiteGraph::Matching<int> graph(L, R);
  rep(i, M) {
    int u, v;
    rd(u, v);
    graph.add_edge(u, v);
  }
  wtn(graph.flow());
  auto es = graph.edges();
  for (auto &e : es) {
    wt(e.first, ' ', e.second, '\n');
  }
}
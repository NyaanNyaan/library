#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include "../../competitive-template.hpp"
#include "../../graph/strongly-connected-components.hpp"

void solve() {
  ini(N, M);
  auto g = graph(N, M, true, false);
  StronglyConnectedComponents<vvi> scc(g);
  ini(Q);
  rep(_, Q) {
    ini(u, v);
    out(scc[u] == scc[v]);
  }
}
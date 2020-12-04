#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include "../../template/template.hpp"
#include "../../graph/strongly-connected-components.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, M);
  auto g = graph(N, M, true, false);
  StronglyConnectedComponents<vvi> scc(g);
  ini(Q);
  rep(_, Q) {
    ini(u, v);
    out(scc[u] == scc[v]);
  }
}
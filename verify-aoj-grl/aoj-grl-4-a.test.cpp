#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include "../competitive-template.cpp"
#include "../graph/topological-sort.cpp"

void solve() {
  ini(N, M);
  auto g = graph(N, M, true, false);
  auto topo = TopologicalSort<vvi>(g);
  out(topo.size() == 0);
}
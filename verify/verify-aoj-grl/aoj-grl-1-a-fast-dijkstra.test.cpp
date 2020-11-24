#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../competitive-template.hpp"
#include "../../shortest-path/dijkstra-fast.hpp"

DijkstraGraph<int, 100000, 500000> g;
void solve() {
  ini(N, E, S);
  rep(i, E) {
    ini(s, t, d);
    g.add_edge(s, t, d);
  }
  auto d = g.dijkstra(S);
  d.resize(N);
  each(x, d) {
    if (x == -1)
      out("INF");
    else
      out(x);
  }
}

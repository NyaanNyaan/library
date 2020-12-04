#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../template/template.hpp"
#include "../../shortest-path/dijkstra.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, E, S);
  auto g = wgraph<int>(N, E, true, false);
  auto d = dijkstra<int>(g, S);
  each(x, d) {
    if (x == -1)
      out("INF");
    else
      out(x);
  }
}
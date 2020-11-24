#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include "../../competitive-template.hpp"
#include "../../shortest-path/dijkstra-radix-heap.hpp"

void solve() {
  ini(N, E, S);
  auto g = wgraph<int>(N, E, true, false);
  auto d = dijkstra_radix_heap<int>(g, S);
  each(x, d) {
    if (x == -1)
      out("INF");
    else
      out(x);
  }
}

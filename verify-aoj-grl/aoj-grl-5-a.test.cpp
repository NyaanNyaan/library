#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../competitive-template.hpp"
#include "../graph/graph-utility.hpp"

void solve() {
  ini(N);
  auto g = wgraph<int>(N, N-1, false, false);
  auto diam = Diameter<int>(g);
  out(diam.second);
}
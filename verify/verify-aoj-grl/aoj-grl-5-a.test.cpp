#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../../template/template.hpp"
#include "../../graph/graph-utility.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N);
  auto g = wgraph<int>(N, N-1, false, false);
  auto diam = Diameter<int>(g);
  out(diam.second);
}
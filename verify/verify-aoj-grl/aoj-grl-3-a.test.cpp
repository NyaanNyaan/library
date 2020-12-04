#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include "../../template/template.hpp"
#include "../../graph/lowlink.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, E);
  auto g = graph(N, E, false, false);
  LowLink<vvi> lowlink(g);
  sort(all(lowlink.articulation));
  each(x, lowlink.articulation) out(x);
}

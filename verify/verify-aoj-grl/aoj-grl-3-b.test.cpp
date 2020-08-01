#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include "../../competitive-template.hpp"
#include "../../graph/lowlink.hpp"

void solve() {
  ini(N, E);
  auto g = graph(N, E, false, false);
  LowLink<vvi> lowlink(g);
  each(p, lowlink.bridge) if (p.first > p.second) swap(p.first, p.second);
  sort(all(lowlink.bridge));
  each(p, lowlink.bridge) out(p);
}
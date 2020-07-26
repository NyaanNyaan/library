#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include "../competitive-template.cpp"
#include "../shortest-path/bellman-ford.cpp"

void solve() {
  ini(N, E, S);
  auto es = esgraph<int>(N, E, true, false);
  auto d = bellman_ford<int>(N, es, S);
  if (!sz(d)) die("NEGATIVE CYCLE");
  each(x, d) {
    if (x > TEN(9))
      out("INF");
    else
      out(x);
  }
}
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include "../../competitive-template.hpp"
#include "../../shortest-path/warshall-floyd.hpp"

void solve() {
  ini(N, E);
  auto d = adjgraph<ll>(N, E, infLL, true, true, false);
  warshall_floyd(d);
  rep(i, N) if (d[i][i] < 0) die("NEGATIVE CYCLE");
  rep(i, N) rep(j, N) {
    if (d[i][j] > TEN(10))
      cout << "INF";
    else
      cout << d[i][j];
    cout << (j == N - 1 ? "\n" : " ");
  }
}
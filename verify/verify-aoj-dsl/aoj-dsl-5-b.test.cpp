#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include "../../competitive-template.hpp"
#include "../../data-structure/2d-cumulative-sum.hpp"

void solve() {
  ini(N);
  int L = 1000;
  CumulativeSum2D<int> ruiseki(L, L);
  rep(i, N) {
    ini(x1, y1, x2, y2);
    ruiseki.imos(x1, y1, x2 , y2, 1);
  }
  ruiseki.build();
  int ans = 0;
  rep(i, L) rep(j, L) { amax(ans, ruiseki.data[i + 1][j + 1]); }
  out(ans);
}
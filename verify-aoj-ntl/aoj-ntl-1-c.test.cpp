#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include "../competitive-template.hpp"
#include "../math/elementary-function.hpp"

void solve() {
  ini(N);
  ll ans = 1;
  rep(i, N) {
    ini(n);
    ans = lcm(ans, n);
  }
  out(ans);
}
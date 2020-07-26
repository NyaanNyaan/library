#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include "../competitive-template.cpp"
#include "../math/elementary-function.cpp"

void solve() {
  ini(N);
  ll ans = 1;
  rep(i, N) {
    ini(n);
    ans = lcm(ans, n);
  }
  out(ans);
}
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include "../../template/template.hpp"
#include "../../math/elementary-function.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N);
  ll ans = 1;
  rep(i, N) {
    ini(n);
    ans = lcm(ans, n);
  }
  out(ans);
}
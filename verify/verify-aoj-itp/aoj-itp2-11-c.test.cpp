#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_C"
#include "../../template/template.hpp"
#include "../../set-function/enumerate-set.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(n);
  int b = 0;
  ini(k);
  rep(i, k) {
    ini(x);
    b |= 1 << x;
  }
  auto ss = enumerate_subset(b);
  reverse(all(ss));
  each(c, ss) {
    cout << c << ":";
    rep(i, n) if ((c >> i) & 1) cout << " " << i;
    cout << "\n";
  }
}

#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_B"
#include "../../competitive-template.hpp"
#include "../../set-function/enumerate-set.hpp"

void solve() {
  ini(n);
  int b = 0;
  ini(k);
  rep(i, k) {
    ini(x);
    b |= 1 << x;
  }
  each(c, enumerate_superset(b, n)) {
    cout << c << ":";
    rep(i, n) if ((c >> i) & 1) cout << " " << i;
    cout << "\n";
  }
}

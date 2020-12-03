#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"

#include "../../competitive-template.hpp"
#include "../../string/rolling-hash-2d.hpp"

void solve() {
  ini(H, W);
  vs S(H);
  in(S);
  roriha2d rori(S);

  ini(h, w);
  vs T(h);
  in(T);

  auto th = roriha2d::get_hash(T);
  rep(i, H - h + 1) rep(j, W - w + 1) {
    auto sh = rori.get(i, j, i + h, j + w);
    if (sh == th) out(i, j);
  }
}

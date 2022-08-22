#define PROBLEM "https://yukicoder.me/problems/no/2012"

#include "../../template/template.hpp"
//
#include "../../data-structure/line-container-2d.hpp"
#include "../../data-structure/line-container.hpp"

using namespace Nyaan;

void q() {
  LineContainer2D lc;
  ini(N);
  ll ans = -inf;
  rep(i, N) {
    ini(X, Y);
    lc.add(X, Y);
    amax(ans, lc.max_ll(Y, -X));
    amax(ans, -lc.min_ll(Y, -X));
  }
  out(ans);
}

void Nyaan::solve() {
  int T = 1;
  // in(T);
  while (T--) q();
}

#define PROBLEM "https://yukicoder.me/problems/no/3024"

#include "../../template/template.hpp"
//
#include "../../math/rational.hpp"
#include "../../set-function/enumerate-set.hpp"
using namespace Nyaan;

void q() {
  inl(N);
  vl a(N);
  in(a);

  VV<Rational> dp(PW(N));
  rep(i, N) dp[PW(i)].push_back(a[i]);
  rep(i, PW(N)) {
    if (popcnt(i) <= 1) continue;
    each(j, enumerate_subset(i)) {
      each(x, dp[i - j]) {
        each(y, dp[j]) {
          if (x == y) die("YES");
          if (i != MSK(N)) {
            dp[i].push_back(x + y);
            dp[i].push_back(x - y);
            dp[i].push_back(x * y);
            dp[i].push_back(x / y);
          }
        }
      }
    }
    dp[i] = mkuni(dp[i]);
  }
  out("NO");
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

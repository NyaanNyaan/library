#define PROBLEM "https://yukicoder.me/problems/no/215"

#include "../../template/template.hpp"
//
#include "../../fps/arbitrary-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;

#include "../../fps/nth-term.hpp"

using namespace Nyaan; void Nyaan::solve() {
  inl(N, P, C);
  vl s{2, 3, 5, 7, 11, 13};
  vl t{4, 6, 8, 9, 10, 12};

  auto calc = [](vl d, ll n) -> fps {
    ll mx = d.back() * n;
    vvm dp(n + 2, vm(mx + 20));
    dp[0][0] = 1;
    each(x, d) rep(i, n) rep(j, mx) dp[i + 1][j + x] += dp[i][j];
    return fps{begin(dp[n]), end(dp[n])};
  };

  fps f1 = calc(s, P);
  fps f2 = calc(t, C);
  fps f = f1 * f2;
  f.shrink();

  int d = sz(f) + 10;

  vm a(d * 2);
  vm dp(d * 3 + 10);
  dp[0] = 1;
  rep(i, 2 * d) {
    reg(j, i, sz(dp)) a[i] += dp[j];
    rep(j, sz(f)) dp[i + j] += dp[i] * f[j];
  }
  a.erase(begin(a));
  out(nth_term(N - 1, a));
}

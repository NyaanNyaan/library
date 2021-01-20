#define PROBLEM "https://yukicoder.me/problems/no/214"
#include "../../template/template.hpp"
//
#include "../../fps/arbitrary-fps.hpp"
#include "../../fps/kitamasa.hpp"
#include "../../modint/montgomery-modint.hpp"

using mint = LazyMontgomeryModInt<1000000007>;
using fps = FormalPowerSeries<mint>;

mint dp[310][5050];
mint ep[310][5050];

using namespace Nyaan; void Nyaan::solve() {
  inl(N, P, C);
  vl s{2, 3, 5, 7, 11, 13};
  vl t{4, 6, 8, 9, 10, 12};

  dp[0][0] = 1;
  each(x, s) {
    rep(i, P + 1) rep(j, 5010) ep[i][j] = mint();
    rep(i, P + 1) rep(j, 5050) {
      if (dp[i][j] == 0) continue;
      for (int k = i, l = j; k <= P; k++, l += x) {
        ep[k][l] += dp[i][j];
      }
    }
    swap(dp, ep);
  }
  fps f(5010);
  rep(i, 5000) f[i] = dp[P][i];

  rep(i, C + 1) rep(j, 5010) dp[i][j] = mint();
  dp[0][0] = 1;
  each(x, t) {
    rep(i, C + 1) rep(j, 5010) ep[i][j] = mint();
    rep(i, C + 1) rep(j, 5050) {
      if (dp[i][j] == 0) continue;
      for (int k = i, l = j; k <= C; k++, l += x) {
        ep[k][l] += dp[i][j];
      }
    }
    swap(dp, ep);
  }
  fps g(5010);
  rep(i, 5000) g[i] = dp[C][i];

  f.shrink();
  g.shrink();
  f = f * g;
  f.shrink();
  g = f.rev();
  rep1(i, sz(g) - 1) g[i] += g[i - 1];
  g = g.rev();

  f[0] = 1;
  rep1(i, sz(f) - 1) f[i] = -f[i];
  g[0] = 0;
  mint ans1 = LinearRecurrence(N, f, g);
  g %= f;
  mint ans2 = LinearRecurrence(N, f, g);
  assert(ans1 == ans2);
  out(ans1);
}
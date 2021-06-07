#define PROBLEM "https://yukicoder.me/problems/no/1533"
//
#include "../../template/template.hpp"
//
#include "../../fps/find-p-recursive.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"

using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;
Binomial<mint> C;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;

mint naive(ll N, ll M, ll K) {
  vm ret(N + 1);
  vm dp(N * M * 2 + 100);
  int st = N * M + 10;
  dp[st] = 1;
  vi nxt;
  reg(i, -M, M + 1) if (abs(i) != K) nxt.push_back(i);
  vm nx(sz(dp));
  rep1(t, N) {
    fill(begin(nx) + st - N * M, begin(nx) + st + N * M + 1, mint(0));
    reg(i, st - N * M, st + N * M + 1) each(di, nxt) nx[i + di] += dp[i];
    swap(dp, nx);
    ret[t] = dp[st];
  }
  mint ans = 0;
  mint L = sz(nxt);
  rep1(t, N) {
    mint x = L.pow(t) - ret[t];
    x /= 2;
    ans += x * (L.pow(N - t)) * (N + 1 - t);
  }
  return ans;
}

void Nyaan::solve() {
  inl(N, M, K);

  vm a(100);
  rep(i, 100) a[i] = naive(i + 1, M, K);

  out(kth_term_of_p_recursive(a, N - 1));
}

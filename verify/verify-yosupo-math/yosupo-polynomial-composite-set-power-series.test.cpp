#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_composite_set_power_series"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
//
#include "../../set-function/egf-composite-set-power-series.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;
using namespace Nyaan;

void q() {
  int M, N, x;
  rd(M, N);
  fps a(M), b(1 << N);
  rep(i, M) rd(x), a[i] = x;
  rep(i, 1 << N) rd(x), b[i] = x;
  auto c = egf_composite_set_power_series<mint, 20>(N, a, b);
  rep(i, 1 << N) wt(c[i].get(), ' ');
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

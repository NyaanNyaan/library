#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
//
#include "../../ntt/relaxed-convolution.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"

using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;

using namespace Nyaan;

void q() {
  int N, x;
  rd(N);
  fps f(N);
  rep(i, N) rd(x), f[i] = x;

  RelaxedConvolution<fps> conv(N);
  fps g(N);

  // g = exp(f)
  // -> \int gf' dx = g
  g[0] = 1;
  rep(i, N - 1) {
    g[i + 1] = conv.get(g[i], f[i + 1] * (i + 1)) * C.inv(i + 1);
  }
  rep(i, N) wt(g[i].get()), wt(' ');
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

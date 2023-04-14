#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
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
// #include "fps/arbitrary-fps.hpp"
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;

void q() {
  int N, x;
  rd(N);
  fps f(N);
  rep(i, N) rd(x), f[i] = x;

  RelaxedConvolution<fps> conv(N);
  fps g(N);

  // g = 1 / f
  // fg = 1
  // i 次の係数を見る
  // f_0 g_i + (i ? f_i g_0 : 0) + [x^i] (rest) = (i ? 0 : 1)

  // さすがに例外処理した方が書きやすそう
  // i=0
  mint inv_f0 = f[0].inverse();
  g[0] = inv_f0;
  conv.get(f[0], g[0]);

  rep1(i, N - 1) {
    // f_0 g_i = -([x^i] rest) - f_i g_0
    g[i] = (-conv.c[i] - f[i] * g[0]) * inv_f0;
    conv.get(f[i], g[i]);
  }

  rep(i, N) wt(g[i].get()), wt(' ');
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

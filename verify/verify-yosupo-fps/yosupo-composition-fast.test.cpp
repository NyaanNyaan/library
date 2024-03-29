#define PROBLEM \
  "https://judge.yosupo.jp/problem/composition_of_formal_power_series"

#include "../../template/template.hpp"
#include "../../fps/formal-power-series.hpp"
#include "../../fps/fps-composition-fast-old.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"

using namespace Nyaan; void Nyaan::solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  using fps = FormalPowerSeries<mint>;
  int N;
  rd(N);
  fps f(N), g(N);
  for (int i = 0; i < N; i++) {
    int n;
    rd(n);
    f[i] = n;
  }
  for (int i = 0; i < N; i++) {
    int n;
    rd(n);
    g[i] = n;
  }
  fps R = Composition(g, f);
  for (int i = 0; i < (int)R.size(); i++) {
    if (i) wt(' ');
    wt(R[i].get());
  }
  wt('\n');
}
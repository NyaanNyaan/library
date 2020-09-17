#define PROBLEM \
  "https://judge.yosupo.jp/problem/composition_of_formal_power_series"

#include "../../competitive-template.hpp"
#include "../../fps/formal-power-series.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"

void solve() {
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
  fps R = {mint(0)}, e = {mint(1)};
  for (int i = 0; i < N; i++) {
    R += e * f[i];
    e *= g;
  }
  R.resize(N);
  for (int i = 0; i < (int)R.size(); i++) {
    if (i) wt(' ');
    wt(R[i].get());
  }
  wt('\n');
}
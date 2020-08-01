#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include "../../competitive-template.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../fps/arbitrary-fps.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;

void solve() {
  ini(N);
  fps a(N);
  in(a);
  out(a.exp());
}
#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include "../competitive-template.hpp"
#include "../modint/montgomery-modint.hpp"
#include "../fps/ntt-friendly-fps.hpp"
#include "../fps/sqrt.hpp"

void solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  using fps = FormalPowerSeries<mint>;
  ini(N);
  fps f(N);
  in(f);
  auto g = sqrt(f);
  if(g.empty()) out(-1);
  else out(g);
}
#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../../template/template.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;

using namespace Nyaan; void Nyaan::solve() {
  inl(N,M);
  fps a(N);
  in(a);
  out(a.pow(M));
}
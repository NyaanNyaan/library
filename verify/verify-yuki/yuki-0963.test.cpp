#define PROBLEM "https://yukicoder.me/problems/no/963"

#include "../../template/template.hpp"
//
#include "../../fps/differential-equation.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"

using mint = LazyMontgomeryModInt<1012924417>;
using vm = vector<mint>;
using fps = FormalPowerSeries<mint>;

using namespace Nyaan; void Nyaan::solve() {
  ini(N);
  auto g = [](const fps &f, int deg) {
    return ((f * f + 1) * mint(2).inverse()).pre(deg);
  };
  auto gp = [](const fps &f, int deg) { return f.pre(deg); };
  auto f = DifferentialEquation<mint>(g, gp, 1, N + 1);
  rep1(i, N) f[N] *= i;
  out(f[N] * 2);
}
#define PROBLEM "https://yukicoder.me/problems/no/1080"

#include "../../template/template.hpp"
//
#include "../../fps/arbitrary-fps.hpp"
#include "../../fps/fps-circular.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"

using namespace Nyaan; void Nyaan::solve() {
  using mint = LazyMontgomeryModInt<1000000009>;
  using fps = FormalPowerSeries<mint>;
  Binomial<mint> C(1001001);
  ini(K);
  fps f = (fps{1, 1} * (fps{1, -3, 3, -1}.inv(K + 1))).pre(K + 1) - 1;
  auto [cos, sin] = circular(f, fps(), K + 1);
  fps g = (cos + sin) * C.fac(K);
  rep1(i, K) out(g[i]);
}
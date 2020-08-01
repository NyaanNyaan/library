#define PROBLEM "https://yukicoder.me/problems/no/963"

#include "../../competitive-template.hpp"
#include "../../fps/fps-circular.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"

void solve() {
  using mint = LazyMontgomeryModInt<1012924417>;
  using fps = FormalPowerSeries<mint>;
  Binomial<mint> C(1001001);
  ini(N);
  auto [cos, sin] = circular(fps{0, 1}, fps(), N + 1);
  out(((sin + 1) * cos.inv(N + 1))[N] * 2 * C.fac(N));
}
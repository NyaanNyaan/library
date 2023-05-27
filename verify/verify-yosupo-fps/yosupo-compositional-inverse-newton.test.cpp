#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-composition.hpp"
#include "../../fps/newton-method.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
// #include "fps/arbitrary-fps.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;
//
using namespace Nyaan;

void q() {
  inl(N);
  fps f(N);
  in(f);
  fps fd = f.diff();
  auto g = newton_method<fps>(
      [&](fps a, int deg) -> pair<fps, fps> {
        fps fa = Composition(a, f, C, deg) - fps{0, 1};
        fps fda = Composition(a, fd, C, deg);
        return {fa, fda};
      },
      fps{0}, N);
  out(g);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
//
#include "../../template/template.hpp"
//
#include "../../fps/newton-method.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;
using namespace Nyaan;

void q() {
  inl(N);
  fps f(N);
  in(f);

  fps g0 = f.exp(3);
  // exp(f) = g
  // log g = f
  // H(g) = log g - f = 0
  // H'(g) = 1/g
  auto ans = newton_method<fps>(
      [&](fps g, int deg) {
        fps s = g.log(deg) - f;
        fps t = g.inv(deg);
        return make_pair(s, t);
      },
      g0, N);
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

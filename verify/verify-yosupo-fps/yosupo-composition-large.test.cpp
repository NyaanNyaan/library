#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series_large"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-composition.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
// #include "fps/arbitrary-fps.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;
using namespace Nyaan;

void q() {
  inl(N);
  fps g(N), f(N);
  in(g, f);
  out(composite(f, g));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

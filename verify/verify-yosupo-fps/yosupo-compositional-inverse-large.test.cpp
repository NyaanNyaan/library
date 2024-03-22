#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-compositional-inverse.hpp"
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
  fps f(N);
  in(f);
  auto g = compositional_inverse(f);
  out(g);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-compositional-inverse.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;
using namespace Nyaan;

void q() {
  inl(N);
  fps f(N);
  in(f);
  out(compositional_inverse(f));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

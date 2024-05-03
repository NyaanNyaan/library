#define PROBLEM "https://judge.yosupo.jp/problem/mul_modp_convolution"
//
#include "../../template/template.hpp"
//
#include "../../ntt/multiplicative-convolution-mod-p.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;

using namespace Nyaan;

void q() {
  ini(p);
  fps a(p), b(p);
  in(a, b);
  out(multiplicative_convolution_mod_p(a, b, p));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
//
#include "../../template/template.hpp"
//
#include "../../fps/fast-interpolate.hpp"
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
  ini(N);
  vm x(N), y(N);
  in(x, y);
  SubproductTree st{x};
  out(st.interpolate(y));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

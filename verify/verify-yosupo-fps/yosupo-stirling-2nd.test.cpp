#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-famous-series.hpp"
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
using namespace Nyaan;

void q() {
  ini(N);
  auto s2 = Stirling2nd(N, C);
  out(s2);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

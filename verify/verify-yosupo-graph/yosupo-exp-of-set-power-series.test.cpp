#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_set_power_series"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
#include "../../set-function/exp-of-set-power-series.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;

using namespace Nyaan;

void q() {
  int N, x;
  rd(N);
  vm b(1 << N);
  rep(i, 1 << N) rd(x), b[i] = x;
  auto c = exp_of_set_power_series<mint, 20>(N, b);
  rep(i, 1 << N) wt(c[i].get(), ' ');
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

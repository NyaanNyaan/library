#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse"
//
#include "../../template/template.hpp"
//
#include "../../fps/sparse-fps.hpp"
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
  inl(N, K);
  fps f(N);
  rep(_, K) {
    ini(i, a);
    f[i] = a;
  }
  out(sparse_inv(f));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

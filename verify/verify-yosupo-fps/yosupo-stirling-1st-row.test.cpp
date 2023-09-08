#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-famous-series.hpp"
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
using namespace Nyaan;

void q() {
  ini(N, K);
  auto f = Stirling1stRow<mint>(K, N, C);
  for (int i = K; i <= N; i++) {
    cout << (f[i] * (i % 2 != K % 2 ? -1 : 1)) << " ";
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

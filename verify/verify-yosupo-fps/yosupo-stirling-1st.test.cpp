#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"

#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
#include "../../template/template.hpp"
using mint = LazyMontgomeryModInt<998244353>;
Binomial<mint> C;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;
// 
#include "../../fps/fps-famous-series.hpp"
using namespace Nyaan;

void Nyaan::solve() {
  ini(n);
  auto s1 = Stirling1st<mint>(n, C);
  for(int i = n - 1; i>=0; i-=2) s1[i]=-s1[i];
  out(s1);
}

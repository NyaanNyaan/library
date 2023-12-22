#define PROBLEM "https://judge.yosupo.jp/problem/factorial"
//
#include "../../template/template.hpp"
//
#include "../../fps/find-p-recursive.hpp"
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
  inl(N);
  vm f(10);
  rep(i, 10) f[i] = C.fac(i);
  out(kth_term_of_p_recursive(f, N));
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}

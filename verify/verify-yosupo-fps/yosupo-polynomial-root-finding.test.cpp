#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_root_finding"
//
#include "../../template/template.hpp"
//
#include "../../fps/root-finding.hpp"
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

void q() {
  inl(N);
  fps f(N + 1);
  in(f);
  auto ans = root_finding(f);
  out(sz(ans));
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

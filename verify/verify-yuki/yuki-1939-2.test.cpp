#define PROBLEM "https://yukicoder.me/problems/no/1939"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-compositional-inverse.hpp"
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
  inl(N, M);
  vl L(M);
  in(L);

  fps F(N + 2);
  F[0] = 1;
  each(n, L) F[n] = 1;
  F = (fps{0, 1} * F.inv()).pre(N + 2);
  auto f = compositional_inverse(F);
  out(f[N + 1]);
}
void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

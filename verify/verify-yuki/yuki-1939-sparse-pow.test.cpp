#define PROBLEM "https://yukicoder.me/problems/no/1939"
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
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;
//
using namespace Nyaan;

void q() {
  inl(N, M);
  vl L(M);
  in(L);
  fps g(N + 1);
  g[0] = 1;
  each(n, L) g[n] = 1;
  out(sparse_pow(g, N + 1)[N] / (N + 1));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

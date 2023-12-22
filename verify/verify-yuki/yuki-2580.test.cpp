#define PROBLEM "https://yukicoder.me/problems/no/2580"
//
#include "../../template/template.hpp"
//
#include "../../math/bigint.hpp"
//
#include "../../fps/fualhuber.hpp"
#include "../../fps/taylor-shift.hpp"
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

fps select(int r, int a, fps f) {
  int N = sz(f);
  f = TaylorShift<mint>(f, r, C);
  rep(i, N) f[i] *= mint{a}.pow(i);
  return f;
}
void q() {
  inl(N);
  vl A(N - 1);
  in(A);
  bigint M;
  in(M);
  fps f{1};
  each(a, A) {
    auto [q, r] = divmod(M, a);
    f = select(r.to_ll(), a, f);
    f = fualhuber(f, C);
    M = q;
  }
  out(f.eval((M % 998244353).to_ll()));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

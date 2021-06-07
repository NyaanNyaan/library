#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;
Binomial<mint> C;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;

void Nyaan::solve() {
  int N, M;
  rd(N, M);
  fps f(N), g(M);
  unsigned b;
  each(x, f) rd(b), x = b;
  each(x, g) rd(b), x = b;

  auto q = f / g;
  auto r = f % g;

  wt(sz(q), ' ', sz(r), '\n');
  for (int i = 0; i < sz(q); i++) {
    wt(q[i].get());
    wt(i == sz(q) - 1 ? '\n' : ' ');
  }
  for (int i = 0; i < sz(r); i++) {
    wt(r[i].get());
    wt(i == sz(r) - 1 ? '\n' : ' ');
  }
}

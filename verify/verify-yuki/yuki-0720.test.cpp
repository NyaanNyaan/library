#define PROBLEM "https://yukicoder.me/problems/no/720"

#include "../../template/template.hpp"

using namespace Nyaan;

#include "../../fps/mod-pow.hpp"
//
#include "../../fps/arbitrary-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
using mint = LazyMontgomeryModInt<1000000007>;
Binomial<mint> C;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;

void Nyaan::solve() {
  inl(n, m);
  fps Q{-1, -1, 1};
  fps f = mod_pow<mint>(m, {0, 1}, Q);
  fps a;
  ll r = 0;
  for (int b = msb(n); b >= 0; --b) {
    if (b != msb(n)) {
      fps ad = mod_pow(r, f, Q);
      a += a * ad % Q;
      r *= 2;
    }
    if (gbit(n, b)) a += mod_pow(++r, f, Q);
  }
  a.resize(2);
  out(a[1]);
}

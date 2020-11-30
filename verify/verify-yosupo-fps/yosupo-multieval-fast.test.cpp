#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
using mint = LazyMontgomeryModInt<998244353>;
// #include "fps/arbitrary-fps.hpp"
// using mint = LazyMontgomeryModInt<1000000007>;
Binomial<mint> C;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;
#include "../../fps/fast-multieval.hpp"
//

using namespace Nyaan;
void Nyaan::solve() {
  ini(n, m);
  fps a(n);
  in(a);
  vm xs(m);
  in(xs);
  out(FastMultiEval(a, xs));
}

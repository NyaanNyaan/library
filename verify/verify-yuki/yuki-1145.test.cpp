#define PROBLEM "https://yukicoder.me/problems/no/1145"

#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../fps/utility.hpp"

constexpr int MOD9 = 998244353;
using mint = LazyMontgomeryModInt<MOD9>;
using fps = FormalPowerSeries<mint>;

using namespace Nyaan; void Nyaan::solve() {
  ini(N, M);
  fps a(N);
  in(a);
  V<fps> v;
  each(x, a) v.emplace_back(fps{1, -x});
  fps q = Pi(v);
  fps p = q.diff();
  fps f = -p * q.inv(M + 1);
  f.resize(M);
  out(f);
}
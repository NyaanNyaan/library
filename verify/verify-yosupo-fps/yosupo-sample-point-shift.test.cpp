#define PROBLEM \
  "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"
//
#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
#include "../../fps/sample-point-shift.hpp"

using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;

void Nyaan::solve() {
  inl(N, M, c);
  fps f(N);
  in(f);
  fps g = SamplePointShift<mint>(f, c, M);
  out(g);
}
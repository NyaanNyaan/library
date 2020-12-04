#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "../../template/template.hpp"
#include "../../fps/formal-power-series.hpp"
#include "../../fps/multipoint-evaluation.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"

using namespace Nyaan; void Nyaan::solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  using fps = FormalPowerSeries<mint>;
  ini(N, M);
  fps f(N);
  vector<mint> xs(M);
  in(f, xs);
  out(MultipointEvaluation(f, xs));
}
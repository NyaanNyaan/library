#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"

#include "../../template/template.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
#include "../../fps/lagrange-interpolation-point.hpp"
#include "../../fps/sum-of-exponential-times-poly.hpp"

using namespace Nyaan; void Nyaan::solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  Binomial<mint> C(10001000);
  long long r, d;
  rd(r, d);
  wtn(sum_of_exp_limit2<mint>(d, r, C).get());
}
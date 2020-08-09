#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "../../competitive-template.hpp"
#include "../../fps/multipoint-evaluation.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../fps/polynomial-interpolation.hpp"

void solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  using fps = FormalPowerSeries<mint>;
  int N;
  cin >> N;
  fps xs(N), ys(N);
  cin >> xs >> ys;
  cout << PolynomialInterpolation<mint>(xs, ys) << endl;
}
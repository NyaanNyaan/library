#define PROBLEM "https://judge.yosupo.jp/problem/multivariate_convolution"
//
#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
//
#include "../../ntt/multivariate-multiplication.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;
//
using namespace Nyaan;
void Nyaan::solve() {
  // verify();
  int K, N = 1;
  rd(K);
  vector<int> base(K);
  for (auto& x : base) rd(x), N *= x;
  fps a(N), b(N);
  int n;
  rep(i, N) rd(n), a[i] = n;
  rep(i, N) rd(n), b[i] = n;
  auto c = multivariate_multiplication(a, b, base);
  rep(i, N) {
    if (i) wt(' ');
    wt(c[i].get());
  }
  wt('\n');
}
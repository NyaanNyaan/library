#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../multiplicative-function/divisor-multiple-transform.hpp"

using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;

void Nyaan::solve() {
  int N, x;
  rd(N);
  vm a(N + 1), b(N + 1);
  rep1(i, N) rd(x), a[i] = x;
  rep1(i, N) rd(x), b[i] = x;
  divisor_transform::zeta_transform(a);
  divisor_transform::zeta_transform(b);
  rep1(i, N) a[i] *= b[i];
  divisor_transform::mobius_transform(a);
  rep1(i, N) wt(a[i].get()), wt(" \n"[i == N]);
}

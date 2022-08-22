#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../multiplicative-function/gcd-convolution.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;

void Nyaan::solve() {
  int N, x;
  rd(N);
  vm a(N + 1), b(N + 1);
  rep1(i, N) rd(x), a[i] = x;
  rep1(i, N) rd(x), b[i] = x;
  auto c = gcd_convolution(a, b);
  rep1(i, N) wt(c[i].get()), wt(" \n"[i == N]);
}

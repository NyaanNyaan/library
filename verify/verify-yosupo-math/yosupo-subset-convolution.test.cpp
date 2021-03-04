#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "../../template/template.hpp"
#include "../../set-function/subset-convolution.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int N;
  rd(N);
  using mint = LazyMontgomeryModInt<998244353>;
  using vm = V<mint>;
  vm a(1 << N), b(1 << N);
  int n;
  rep(i, 1 << N) {
    rd(n);
    a[i] = n;
  }
  rep(i, 1 << N) {
    rd(n);
    b[i] = n;
  }
  SubsetConvolution<mint,20> sc;
  auto c = sc.multiply(a, b);
  rep(i, 1 << N) {
    if (i) wt(' ');
    wt(c[i].get());
  }
  wt('\n');
}
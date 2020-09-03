#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "../../competitive-template.hpp"
#include "../../math/subset-convolution.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"

void solve() {
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
  auto c = subset_convolution(a, b);
  rep(i, 1 << N) {
    if (i) wt(' ');
    wt(c[i].get());
  }
  wt('\n');
}
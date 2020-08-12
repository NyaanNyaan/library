#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "../../competitive-template.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../fps/berlekamp-massey.hpp"
#include "misc/fastio.hpp"

void solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  int N;
  rd(N);
  V<mint> a(N);
  for (int i = 0; i < N; i++) {
    int n;
    rd(n);
    a[i] = n;
  }
  auto b = BerlekampMassey<mint>(a);
  wtn(b.size() - 1);
  for (int i = 1; i < (int)b.size(); i++) {
    if (i != 1) wt(' ');
    wt((-b[i]).get());
  }
  wt('\n');
}

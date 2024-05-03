#define PROBLEM "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"
//
#include "../../template/template.hpp"
//
#include "../../data-structure-2d/rectangle-add-rectangle-sum.hpp"
//
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;

using namespace Nyaan;

void q() {
  inl(N, Q);
  RectangleAddRectangleSum<int, mint> rr;
  rep(i, N) {
    ini(l, d, r, u, w);
    rr.add_rectangle(l, r, d, u, w);
  }
  rep(i, Q) {
    ini(l, d, r, u);
    rr.add_query(l, r, d, u);
  }
  auto ans = rr.solve();
  each(x, ans) out(x);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

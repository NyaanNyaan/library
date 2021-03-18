#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
//
#include "../../template/template.hpp"
//
#include "../../matrix/gauss-elimination.hpp"
#include "../../matrix/linear-equation.hpp"
//
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"

using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;

void Nyaan::solve() {
  int N, M;
  rd(N);
  rd(M);
  V<V<mint>> A(N, V<mint>(M));
  int buf;
  rep(i, N) rep(j, M) {
    rd(buf);
    A[i][j] = buf;
  }
  V<mint> B(N);
  rep(i, N) {
    rd(buf);
    B[i] = buf;
  }
  auto v = LinearEquation<mint>(A, B);
  wt(sz(v) - 1);
  wt('\n');
  each(x, v) {
    rep(i, sz(x)) {
      if (i) wt(' ');
      wt(x[i].get());
    }
    wt('\n');
  }
}

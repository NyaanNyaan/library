#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/gauss-elimination-fast.hpp"

using mint = LazyMontgomeryModInt<998244353>;

using namespace Nyaan;
void Nyaan::solve() {
  ini(N, M);
  V<V<mint>> A(N, V<mint>(M));
  in(A);
  V<mint> B(N);
  in(B);
  auto v = LinearEquation<mint>(A, B);
  out(sz(v) - 1);
  each(x, v) out(x);
}
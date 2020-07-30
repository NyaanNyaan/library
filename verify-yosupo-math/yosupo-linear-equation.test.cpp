#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../competitive-template.hpp"
#include "../modint/montgomery-modint.hpp"
#include "../modulo/gauss-elimination.hpp"

using mint = LazyMontgomeryModInt<998244353>;

void solve() {
  ini(N, M);
  V<V<mint>> A(N, V<mint>(M));
  in(A);
  V<mint> B(N);
  in(B);
  auto v = LinearEquation<mint>(A, B);
  out(sz(v) - 1);
  each(x, v) out(x);
}
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../competitive-template.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/gauss-elimination.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
void solve() {
  ini(N);
  V<vm> a(N,vm(N));
  in(a);
  out(Gauss::determinant(a));
}
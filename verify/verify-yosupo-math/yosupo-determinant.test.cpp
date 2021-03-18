#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../template/template.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/gauss-elimination-fast.hpp"

using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using namespace Nyaan; void Nyaan::solve() {
  ini(N);
  V<vm> a(N,vm(N));
  in(a);
  out(Gauss::determinant(a));
}
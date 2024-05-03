#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
//
#include "../../template/template.hpp"
//
#include "../../matrix/matrix.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;

using namespace Nyaan;

void q() {
  inl(N, K);
  Matrix<mint> m(N);
  rep(i, N) rep(j, N) in(m[i][j]);
  m = m ^ K;
  rep(i, N) out(m[i]);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

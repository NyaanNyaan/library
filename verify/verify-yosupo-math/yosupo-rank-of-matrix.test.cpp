#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"
//
#include "../../template/template.hpp"
//
#include "../../matrix/gauss-elimination.hpp"
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
  ini(N, M);
  vvm m(N, vm(M));
  in(m);
  if (N > M) {
    vvm m2(M, vm(N));
    rep(i, N) rep(j, M) m2[j][i] = m[i][j];
    m = m2;
  }
  int rank = GaussElimination(m).fi;
  out(rank);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

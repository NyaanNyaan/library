#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial-table.hpp"
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
  int N = 1000;
  auto D = binomial_table<mint>(N);
  rep(i, N) rep(j, N) assert(C(i, j) == D[i][j]);
  trc2("OK");

  {
    ini(a, b);
    out(a + b);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"
//
#include "../../template/template.hpp"
//
#include "../../string/number-of-subsequences.hpp"
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

void q() {
  ini(N);
  vi A(N);
  in(A);
  out(number_of_subsequences<vi, mint>(A).get());
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

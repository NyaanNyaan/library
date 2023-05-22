#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
//
#include "../../template/template.hpp"
//
#include "../../modint/arbitrary-modint.hpp"
#include "../../modulo/binomial.hpp"
using namespace Nyaan;

void q() {
  using mint = ArbitraryModInt;
  int T, m;
  in(T, m);
  mint::set_mod(m);
  Binomial<mint> C(TEN(7) + 10);
  while (T--) {
    int n, k;
    in(n, k);
    out(C(n, k).get());
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

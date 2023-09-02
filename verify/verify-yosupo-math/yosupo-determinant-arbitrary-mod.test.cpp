#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_arbitrary_mod"
//
#include "../../template/template.hpp"
//
#include "../../matrix/determinant-arbitrary-mod.hpp"
//
#include "../../modint/arbitrary-modint.hpp"
using mint = ArbitraryModInt;
using namespace Nyaan;

void q() {
  inl(N, mod);
  mint::set_mod(mod);
  vector a(N, vector(N, mint{}));
  in(a);
  out(determinant_arbitrary_mod(a));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

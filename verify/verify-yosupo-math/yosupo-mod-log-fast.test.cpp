#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_fixed_mod"
//
#include "../../template/template.hpp"
//
#include "../../modint/arbitrary-modint.hpp"
#include "../../modulo/mod-log-fast.hpp"

using namespace Nyaan;

using mint = ArbitraryModInt;

void q() {
  ini(p, g, Q);
  mint::set_mod(p);
  FastBSGS bsgs(mint{g}, int(ceil(sqrt(1LL * p * Q))), p - 1);
  rep(q, Q) {
    ini(x);
    out(bsgs.find(x));
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
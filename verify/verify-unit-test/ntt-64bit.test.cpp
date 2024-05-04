#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
#include "../../modint/arbitrary-montgomery-modint.hpp"
#include "../../ntt/ntt-64bit.hpp"
#include "../../prime/miller-rabin.hpp"
using namespace Nyaan;

void q() {
  ll p = 2563674087880654849;
  assert(is_prime(p));
  using mint = ArbitraryLazyMontgomeryModInt64bit<20240504>;
  mint::set_mod(p);
  NTT_64bit<mint> ntt;
  rep(t, 100) {
    int N = rng(1, 1000);
    int M = rng(1, 1000);
    vector<mint> a(N), b(M);
    each(x, a) x = rng();
    each(x, b) x = rng();
    auto c = ntt.multiply(a, b);
    vector<mint> d(N + M - 1);
    rep(i, N) rep(j, M) d[i + j] += a[i] * b[j];
    assert(c == d);
  }
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

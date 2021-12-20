#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
//
#include "../../template/template.hpp"
//
using namespace Nyaan;

#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
#include "../../multiplicative-function/sum-of-multiplicative-function.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;

mint f(ll p, ll c) {
  ll res = 1;
  while (--c) res = res * p;
  return res * (p - 1);
}

void Nyaan::solve() {
  inl(N);
  mf_prefix_sum<mint, f> mf(N);
  auto h1 = mf.prime_sum_table();
  auto h0 = mf.pi_table();
  rep(i, sz(h1)) h1[i] -= h0[i];
  out(mf.run(h1));
}

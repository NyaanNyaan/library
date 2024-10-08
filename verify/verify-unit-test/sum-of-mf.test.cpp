#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../multiplicative-function/mf-famous-series.hpp"
#include "../../multiplicative-function/sum-of-multiplicative-function.hpp"
#include "../../multiplicative-function/sum-of-totient.hpp"
//
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;

using namespace Nyaan;

mint f(ll p, ll c) {
  ll res = 1;
  while (--c) res *= p;
  return res * (p - 1);
}

void Nyaan::solve() {
  int N = 1000;
  auto tot = totient<mint>(N);

  rep(i, N) tot[i + 1] += tot[i];
  rep1(i, N) {
    assert(tot[i] == sum_of_totient<mint>(i));
    mf_prefix_sum<mint, f> mf(i);
    auto h1 = mf.prime_sum_table();
    auto h0 = mf.pi_table();
    assert(sz(h1) == sz(h0));
    rep(j, sz(h1)) h1[j] -= h0[j];

    auto g = mf.min_25_sieve(h1);
    rep1(j, mf.s - mf.sq - 1) assert(g[j] == tot[i / j]);
    rep1(j, mf.sq) assert(g[mf.s - j] == tot[j]);

    mint ans = mf.run(h1);
    assert(tot[i] == ans);
  }
  trc2("OK");

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

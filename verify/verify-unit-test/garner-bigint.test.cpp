#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/garner-bigint.hpp"
//
#include "../../modint/arbitrary-modint.hpp"
#include "../../prime/fast-factorize.hpp"

using namespace Nyaan;
using mint = ArbitraryModInt;

// n^e
bigint pow1(ll n, int e) {
  assert(1 <= n);
  if (e == 0) return 1;
  bigint half = pow1(n, e / 2);
  bigint res = half * half;
  if (e & 1) res *= n;
  return res;
}
bigint pow2(ll n, int e) {
  assert(1 <= n);
  int pnum = int(log10(n) * double(e) / 9.0) + 2;
  vector<long long> ps, as;
  for (int p = 1000000007; sz(ps) < pnum; p += 2) {
    if (is_prime(p)) ps.push_back(p);
  }
  for (auto& p : ps) {
    mint::set_mod(p);
    as.push_back(mint{n}.pow(e).get());
  }
  return garner_bigint(as, ps);
}

void Nyaan::solve() {
  rep1(n, 50) rep(e, 50) {
    bigint ans1 = pow1(n, e);
    bigint ans2 = pow2(n, e);
    if (ans1 != ans2) {
      trc(n, e, ans1, ans2);
    }
    assert(ans1 == ans2);
  }
  cerr << "OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

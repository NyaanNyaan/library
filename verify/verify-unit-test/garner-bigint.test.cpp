#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/garner-bigint.hpp"
//
#include "../../modint/arbitrary-modint.hpp"
//
#include "../../prime/fast-factorize.hpp"
#include "../../prime/prime-enumerate.hpp"
//
#include "../../misc/all.hpp"

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
  int pnum = int(log10(n) * double(e) / 8.8) + 2;
  vector<int> ps, as;
  for (int p = 1000000007; sz(ps) < pnum; p += 2) {
    if (is_prime(p)) ps.push_back(p);
  }
  for (auto& p : ps) {
    mint::set_mod(p);
    as.push_back(mint{n}.pow(e).get());
  }
  auto ans1 = GarnerImpl::garner_naive(as, ps).first;
  auto ans2 = GarnerImpl::garner_dc(as, ps).first;
  assert(ans1 == ans2);
  return ans1;
}

void Nyaan::solve() {
  {
    auto ps = prime_enumerate(1000);
    for (int n = 1; n <= sz(ps); n++) {
      vector<int> rem, mod;
      for (int i = 0; i < n; i++) {
        rem.push_back(rng(0, ps[i] - 1));
        mod.push_back(ps[i]);
      }
      trc(rem, mod);
      auto ans1 = GarnerImpl::garner_naive(rem, mod);
      trc(ans1);
      auto ans2 = GarnerImpl::garner_dc(rem, mod);
      trc(ans2);
      if (ans1 != ans2) exit(1);
    }
  }
  rep1(n, 100) rep(e, 100) {
    bigint ans1 = pow1(n, e);
    bigint ans2 = pow2(n, e);
    if (ans1 != ans2) {
      trc(n, e, ans1, ans2);
    }
    assert(ans1 == ans2);
  }

  /**
  {
    int nmax = 1 << 15;
    vector<int> ps;
    for (int p = TEN(9); sz(ps) < nmax; p--) {
      if (is_prime(p)) ps.push_back(p);
    }
    for (int n = 1; n <= nmax; n *= 2) {
      vector<int> rem, mod;
      for (int i = 0; i < n; i++) {
        rem.push_back(rng(0, ps[i] - 1));
        mod.push_back(ps[i]);
      }
      trc(rem, mod);
      Timer timer;

      timer.reset();
      auto ans1 = GarnerImpl::garner_naive(rem, mod);
      int t1 = timer.elapsed();

      timer.reset();
      auto ans2 = GarnerImpl::garner_dc(rem, mod);
      int t2 = timer.elapsed();

      if (ans1 != ans2) exit(1);
      cerr << "n : " << n << ", ";
      cerr << "naive : " << t1 << " ms , ";
      cerr << "dc : " << t2 << " ms" << endl;
    }
  }
  //*/
  cerr << "OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

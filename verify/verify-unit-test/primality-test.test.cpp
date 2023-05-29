#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../prime/miller-rabin.hpp"
#include "../../prime/prime-sieve.hpp"
//
#include "../../misc/rng.hpp"
//
using namespace Nyaan;

void test_small() {
  using mint64 = ArbitraryLazyMontgomeryModInt64bit<123456789>;

  auto sieve = prime_sieve(2e6);
  rep(n, sz(sieve)) {
    int f1 = sieve[n];
    int f2 = is_prime(n);
    int f3 = fast_factorize::miller_rabin<mint64>(n, {2, 7, 61});
    int f4 = fast_factorize::miller_rabin_u64(n);
    assert(f1 == f2 && f2 == f3 && f3 == f4);
  }
}

void test_large() {
  auto get_prime = [&](ll upper) -> ll {
    if (upper <= 2) return 2LL;
    ll lower = 0.5 * upper;
    while (true) {
      ll p = rng(lower, upper) | 1;
      if (is_prime(p)) return p;
    }
  };
  rep(t, 100000) {
    u64 n = rng(0, (1uLL << 62) - 1);
    int f1 = is_prime(n);
    int f2 = fast_factorize::miller_rabin_u64(n);
    assert(f1 == f2);
  }
  rep(t, 10000) {
    ll p = get_prime(pow(2.0, 31.0 + rnd() * 31.0));
    ll q = get_prime((1uLL << 62) / p);
    ll n = p * q;
    int f1 = is_prime(n);
    int f2 = fast_factorize::miller_rabin_u64(n);
    assert(f1 == f2);
  }
}

void q() {
  test_small();
  test_large();

  cerr << "OK" << endl;
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

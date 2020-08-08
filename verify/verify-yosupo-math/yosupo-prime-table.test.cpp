#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../competitive-template.hpp"
#include "../../math/prime-table.hpp"
#include "../../misc/fastio.hpp"

void solve() {
  int N, A, B;
  rd(N, A, B);
  auto sieve = PrimeTable(N);
  int x = (sz(sieve) + A - B - 1) / A;
  wt(sz(sieve));
  wt(' ');
  wt(x);
  wt('\n');
  rep(i, x) {
    if (i) wt(' ');
    wt(sieve[i * A + B]);
  }
  wt('\n');
}
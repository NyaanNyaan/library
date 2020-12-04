#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include "../../template/template.hpp"
#include "../../prime/prime-enumerate.hpp"
#include "../../misc/fastio.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int N, A, B;
  rd(N, A, B);
  auto sieve = prime_enumerate(N);
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
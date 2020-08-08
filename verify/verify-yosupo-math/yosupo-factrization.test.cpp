#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "../../competitive-template.hpp"
#include "../../math/prime-factor.hpp"
#include "../../misc/fastio.hpp"

void solve() {
  int Q;
  rd(Q);
  rep(_, Q) {
    int64_t n;
    rd(n);
    auto prime = prime_factor(n);
    sort(all(prime));
    wt(sz(prime));
    rep(i, sz(prime)) {
      wt(' ');
      wt(prime[i]);
    }
    wt('\n');
  }
}
#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "../../competitive-template.hpp"
#include "../../misc/fastio.hpp"
#include "../../modulo/mod-log.hpp"

void solve() {
  int T;
  rd(T);
  rep(_, T) {
    ll x, y, m;
    rd(x, y, m);
    wt(mod_log(x, y, m));
    wt('\n');
  }
}
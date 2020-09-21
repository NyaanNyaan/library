#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../competitive-template.hpp"
#include "../../data-structure/hash-map-variable-length.hpp"
#include "../../misc/fastio.hpp"

HashMap<ll, ll> m;

void solve() {
  int Q;
  ll c, k, v;
  rd(Q);
  rep(_, Q) {
    rd(c);
    if (c) {
      rd(k);
      wtn(m[k]);
    } else {
      rd(k, v);
      m[k] = v;
    }
  }
}

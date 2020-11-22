#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../competitive-template.hpp"
#include "../../hashmap/hashmap.hpp"
#include "../../misc/fastio.hpp"

void solve() {
  HashMap<uint64_t, uint64_t> m;
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

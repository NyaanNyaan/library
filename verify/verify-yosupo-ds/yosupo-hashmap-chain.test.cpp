#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../template/template.hpp"
#include "../../hashmap/hashmap-chain.hpp"
#include "../../misc/fastio.hpp"

using namespace Nyaan; void Nyaan::solve() {
  HashMap<ll, ll, 1 << 20> m;
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

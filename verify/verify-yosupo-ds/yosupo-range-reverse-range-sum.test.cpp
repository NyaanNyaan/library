#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"
//
#include "../../template/template.hpp"
//
#include "../../lct/splay-reversible.hpp"

using namespace Nyaan;
ll f(ll a, ll b) { return a + b; }
ll ts(ll a) { return a; }

using Splay = ReversibleSplayTree<ll, f, ts>;

void q() {
  inl(N, Q);
  vl a(N);
  in(a);
  Splay splay;
  auto root = splay.build(a);
  rep(i, Q) {
    ini(cmd, l, r);
    if (cmd == 0) {
      splay.reverse(root, l, r);
    } else {
      out(splay.fold(root, l, r));
    }
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

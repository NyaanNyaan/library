#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../template/template.hpp"
//
#include "../../segment-tree/dynamic-segment-tree.hpp"

using namespace Nyaan;

ll f(ll a, ll b) { return a + b; }
ll ti() { return 0; }
using Trie = DynamicSegmentTree<ll, f, ti>;

void Nyaan::solve() {
  inl(N, Q);
  Trie t(N);
  vl a(N);
  in(a);
  rep(i, N) t.set_val(i, a[i]);
  while (Q--) {
    ini(cmd);
    if (cmd == 0) {
      inl(p, x);
      ll y = t.get_val(p);
      t.set_val(p, x + y);
    } else {
      inl(l, r);
      out(t.fold(l, r));
    }
  }
}
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../competitive-template.hpp"
#include "../../data-structure-2d/abstract-range-tree.hpp"
#include "../../data-structure/binary-indexed-tree.hpp"
#include "../../misc/compress.hpp"
#include "../../misc/fastio.hpp"

void solve() {
  using BIT = BinaryIndexedTree<ll>;
  auto nw = [](int n) { return new BIT(n); };
  auto add = [](BIT& bit, int i, ll a) { bit.add(i, a); };
  auto sum = [](BIT& bit, int i, int j) {
    return bit.sum(j - 1) - bit.sum(i - 1);
  };
  auto mrg = [](ll a, ll b) { return a + b; };

  RangeTree<BIT, int, ll> rtree(nw, add, sum, mrg, 0);

  int N, Q;
  rd(N, Q);
  vector<int> X(N), Y(N), W(N), c(Q), s(Q), t(Q), u(Q), v(Q);
  rep(i, N) {
    rd(X[i], Y[i], W[i]);
    rtree.add_point(X[i], Y[i]);
  }
  rep(i, Q) {
    rd(c[i], s[i], t[i], u[i]);
    if (c[i])
      rd(v[i]);
    else
      rtree.add_point(s[i], t[i]);
  }

  rtree.build();
  rep(i, N) { rtree.add(X[i], Y[i], W[i]); }
  rep(i, Q) {
    if (c[i]) {
      out(rtree.sum(s[i], t[i], u[i], v[i]));
    } else
      rtree.add(s[i], t[i], u[i]);
  }
}
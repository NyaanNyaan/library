#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../template/template.hpp"
#include "../../data-structure-2d/fenwick-tree-on-range-tree.hpp"
#include "../../misc/compress.hpp"
#include "../../misc/fastio.hpp"
using namespace Nyaan; void Nyaan::solve() {
  FenwickRangeTree<int, ll> bit;

  int N, Q;
  rd(N, Q);
  vector<int> X(N), Y(N), W(N), c(Q), s(Q), t(Q), u(Q), v(Q);
  rep(i, N) {
    rd(X[i], Y[i], W[i]);
    bit.add_point(X[i], Y[i]);
  }
  rep(i, Q) {
    rd(c[i], s[i], t[i], u[i]);
    if (c[i])
      rd(v[i]);
    else
      bit.add_point(s[i], t[i]);
  }

  bit.build();
  rep(i, N) { bit.add(X[i], Y[i], W[i]); }
  rep(i, Q) {
    if (c[i]) {
      out(bit.sum(s[i], t[i], u[i], v[i]));
    } else
      bit.add(s[i], t[i], u[i]);
  }
}
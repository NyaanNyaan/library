#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../segment-tree/lazy-segment-tree-utility.hpp"
using mint = LazyMontgomeryModInt<998244353>;

using Pair = pair<mint, mint>;
Pair f(Pair a, Pair b) { return Pair{a.first + b.first, a.second + b.second}; };
Pair g(Pair a, Pair b) {
  return Pair{a.first * b.first + a.second * b.second, a.second};
};
Pair h(Pair a, Pair b) {
  return Pair{a.first * b.first, a.second * b.first + b.second};
};
Pair ti() { return {0, 0}; }
Pair ei() { return {1, 0}; }

using namespace Nyaan;
void Nyaan::solve() {
  ini(N, Q);
  V<Pair> a(N, {0, 1});
  rep(i, N) in(a[i].first);
  LazySegmentTree<Pair, Pair, f, g, h, ti, ei> seg(a);

  rep(_, Q) {
    ini(cmd);
    if (!cmd) {
      inl(l, r, b, c);
      seg.update(l, r, {b, c});
    } else {
      inl(l, r);
      out(seg.query(l, r).first);
    }
  }
}
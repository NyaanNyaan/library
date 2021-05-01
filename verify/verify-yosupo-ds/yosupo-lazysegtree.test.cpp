#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../template/template.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../segment-tree/lazy-segment-tree.hpp"

using mint = LazyMontgomeryModInt<998244353>;

using namespace Nyaan; void Nyaan::solve() {
  using P = pair<mint, mint>;
  auto f = [](P a, P b) { return P{a.first + b.first, a.second + b.second}; };
  auto g = [](P a, P b) {
    return P{a.first * b.first + a.second * b.second, a.second};
  };
  auto h = [](P a, P b) {
    return P{a.first * b.first, a.second * b.first + b.second};
  };
  P ti = {0, 0};
  P ei = {1, 0};
  ini(N, Q);
  V<P> a(N, {0, 1});
  rep(i, N) in(a[i].first);

  LazySegmentTree<P, P, decltype(f), decltype(g), decltype(h)> seg(a, f, g, h, ti, ei);

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
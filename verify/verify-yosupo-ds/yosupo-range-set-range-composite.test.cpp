#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"
//
#include "../../template/template.hpp"
//
#include "../../math/affine-transformation.hpp"
#include "../../segment-tree/lazy-segment-tree.hpp"
//
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;

using namespace Nyaan;

void q() {
  ini(N, Q);

  using A = Affine<mint>;
  using D = pair<A, int>;

  D ti = make_pair(A{1, 0}, 0);
  A ei{0, 0};
  auto f = [](const D& a, const D& b) -> D {
    return make_pair(b.fi(a.fi), a.se + b.se);
  };
  auto g = [](const D& a, const A& b) -> D {
    return make_pair(Power(b, a.se, A{1, 0}), a.se);
  };
  auto h = [](const A&, const A& b) { return b; };

  V<D> v(N, make_pair(ei, 1));
  rep(i, N) in(v[i].fi.a, v[i].fi.b);

  LazySegmentTree seg(v, f, g, h, ti, ei);

  rep(i, Q) {
    ini(cmd);
    if (cmd == 0) {
      ini(l, r, c, d);
      seg.update(l, r, A{c, d});
    } else {
      ini(l, r, x);
      auto a = seg.query(l, r);
      out(a.fi(x));
    }
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

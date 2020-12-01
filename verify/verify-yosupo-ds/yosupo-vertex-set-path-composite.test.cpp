#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
#include "../../modulo/binomial.hpp"
Binomial<mint> C;

#include "../../graph/graph-template.hpp"
#include "../../math/affine-transformation.hpp"
#include "../../segment-tree/segment-tree.hpp"
#include "../../tree/heavy-light-decomposition.hpp"
//
#include "../../template/template.hpp"
using namespace Nyaan;

void Nyaan::solve() {
  ini(n, q);
  vm a(n), b(n);
  in2(a, b);
  auto g = graph(n, n - 1, false, false);

  HeavyLightDecomposition<vvi> hld(g);

  using af = Affine<mint>;
  auto m1 = [](af a_, af b_) { return a_ * b_; };
  auto m2 = [](af a_, af b_) { return b_ * a_; };
  SegmentTree<af, decltype(m1)> seg1(n, m1, af());
  SegmentTree<af, decltype(m2)> seg2(n, m2, af());

  rep(i, n) {
    int j = hld.idx(i).first;
    trc(j);
    seg1.set(j, af(a[i], b[i]));
    seg2.set(j, af(a[i], b[i]));
  }
  seg1.build(), seg2.build();

  rep(_, q) {
    ini(cmd, x, y, z);
    if (cmd == 0) {
      seg1.update(hld.idx(x).first, af(y, z));
      seg2.update(hld.idx(x).first, af(y, z));
    } else {
      mint ans = z;
      auto f = [&](int l, int r) {
        if (l <= r)
          ans = seg1.query(l, r)(ans);
        else
          ans = seg2.query(r, l)(ans);
      };
      hld.path_noncommutative_query(x, y, true, f);
      out(ans);
    }
  }
}

#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../template/template.hpp"
#include "../../data-structure/hash-map-variable-length.hpp"
#include "../../data-structure-2d/dynamic-binary-indexed-tree-2d.hpp"
#include "../../misc/compress.hpp"
#include "../../misc/fastio.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int N, Q;
  rd(N, Q);
  vector<int> X(N), Y(N), W(N), c(Q), s(Q), t(Q), u(Q), v(Q);
  rep(i, N) rd(X[i], Y[i], W[i]);
  rep(i, Q) {
    rd(c[i], s[i], t[i], u[i]);
    if (c[i]) rd(v[i]);
  }

  vi xs{-1, inf}, ys{-1, inf};
  each(x, X) xs.push_back(x);
  each(y, Y) ys.push_back(y);
  rep(i, Q) {
    if (!c[i]) {
      xs.push_back(s[i]);
      ys.push_back(t[i]);
    }
  }

  auto zipx = compress<int>(xs);
  auto zipy = compress<int>(ys);

  DynamicFenwickTree2D<ll> seg(zipx.size(), zipy.size());
  rep(i, N) seg.add(zipx.get(X[i]), zipy.get(Y[i]), W[i]);

  rep(i, Q) {
    if (c[i]) {
      int nl = zipx.get(s[i]);
      int ml = zipy.get(t[i]);
      int nr = zipx.get(u[i]);
      int mr = zipy.get(v[i]);
      out(seg.sum(nl, ml, nr, mr));
    } else
      seg.add(zipx.get(s[i]), zipy.get(t[i]), u[i]);
  }
}

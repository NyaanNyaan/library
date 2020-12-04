#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../../template/template.hpp"
#include "../../segment-tree/li-chao-tree.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, Q);
  vl a(N), b(N);
  in2(a, b);
  vl c(Q), d(Q), e(Q);
  vl xs;
  rep(i, Q) {
    in(c[i]);
    if (c[i])
      in(d[i]), xs.push_back(d[i]);
    else
      in(d[i], e[i]);
  }
  xs.push_back(-inf);
  xs.push_back(inf);

  LiChaoTree<ll, infLL> lichao(xs);
  rep(_, N) lichao.update(a[_], b[_]);

  rep(i, Q) {
    if (c[i]) {
      out(lichao.query(d[i]));
    } else {
      lichao.update(d[i], e[i]);
    }
  }
}
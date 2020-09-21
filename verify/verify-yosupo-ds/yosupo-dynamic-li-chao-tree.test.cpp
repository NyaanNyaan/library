#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "../../competitive-template.hpp"
#include "../../segment-tree/dynamic-li-chao-tree.hpp"

void solve() {
  ini(N, Q);
  DynamicLiChaoTree<ll, infLL> lichao(-1001001001, 1001001001);
  rep(i, N) {
    inl(l, r, a, b);
    lichao.update_line_segment(a, b, l, r - 1);
  }
  rep(i, Q) {
    inl(c);
    if (c == 0) {
      inl(l, r, a, b);
      lichao.update_line_segment(a, b, l, r - 1);
    } else {
      ini(x);
      ll ans = lichao.query(x);
      if (ans >= infLL)
        out("INFINITY");
      else
        out(ans);
    }
  }
}
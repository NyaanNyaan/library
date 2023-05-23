#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3086"
//
#include "../../template/template.hpp"
//
#include "../../dp/monge-shortest-path.hpp"
//
#include "../../segment-tree/segment-tree.hpp"
using namespace Nyaan;

void q() {
  inl(N, L);
  vl d(N);
  in(d);
  each(x, d) x = -x;
  SegmentTree seg(
      d, [](ll a, ll b) { return min(a, b); }, infLL);
  auto ans = monge_shortest_path<ll>(N, [&](int l, int r) -> ll {
    if (r - l < L) return infLL;
    return seg.query(l, r);
  });
  out(-ans[N]);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

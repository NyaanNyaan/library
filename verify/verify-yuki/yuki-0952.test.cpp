#define PROBLEM "https://yukicoder.me/problems/no/952"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
#include "../../misc/timer.hpp"
//
#include "../../dp/monge-d-edge-shortest-path-enumerate.hpp"
//
#include "../../dp/monge-d-edge-shortest-path.hpp"
using namespace Nyaan;

void q() {
  Timer timer;
  inl(N);
  vl a(N);
  in(a);

  vl r = mkrui(a);
  // 0 -> N+1 へのパス
  // i -> j の値 : (sum_{k=i...j-2} a_k)^2
  auto cost = [&](int i, int j) -> ll {
    assert(i < j);
    if (i + 1 == j) return 0;
    return (r[j - 1] - r[i]) * (r[j - 1] - r[i]);
  };
  auto ans = enumerate_monge_d_edge_shortest_path(N + 1, cost);
  rep1(d, N) out(ans[N + 1 - d]);
  trc(ans);

  // verify 用, 何点か調べる
  {
    vi ds;
    rep1(i, N + 1) ds.push_back(i);
    randshf(ds);
    each(d, ds) {
      if (timer.elapsed() > 1900) break;
      ll ans2 = monge_d_edge_shortest_path(N + 1, d, TEN(18), cost);
      assert(ans2 == ans[d]);
    }
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

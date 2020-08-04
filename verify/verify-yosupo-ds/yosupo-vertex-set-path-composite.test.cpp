#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../../competitive-template.hpp"
#include "../../graph/graph-utility.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../segment-tree/segment-tree.hpp"
#include "../../tree/heavy-light-decomposition.hpp"

void solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  int N, Q;
  rd(N);
  rd(Q);
  V<mint> a(N), b(N);
  for (int i = 0; i < N; i++) {
    int buf;
    rd(buf);
    a[i] = buf;
    rd(buf);
    b[i] = buf;
  }
  vvi g(N);
  rep(_, N - 1) {
    int u, v;
    rd(u);
    rd(v);
    g[u].pb(v);
    g[v].pb(u);
  }
  HeavyLightDecomposition<vvi> hld(g);

  using P = pair<mint, mint>;
  auto mul = [](P a, P b) {
    return P{a.first * b.first, a.second * b.first + b.second};
  };
  auto fl = [&mul](P a, P b) { return mul(a, b); };
  auto fr = [&mul](P a, P b) { return mul(b, a); };
  SegmentTree<P, decltype(fl)> segl(N, fl, P{1, 0});
  SegmentTree<P, decltype(fr)> segr(N, fr, P{1, 0});
  rep(i, N) {
    segl.set(hld.in[i], P{a[i], b[i]});
    segr.set(hld.in[i], P{a[i], b[i]});
  }
  segl.build();
  segr.build();

  rep(_, Q) {
    int cmd, x, y, z;
    rd(cmd);
    rd(x);
    rd(y);
    rd(z);
    if (!cmd) {
      segl.update(hld.in[x], P{y, z});
      segr.update(hld.in[x], P{y, z});
    } else {
      P L{1, 0}, R{1, 0};
      auto f = [&](int u, int v, int le) {
        if (le) {
          if (u < v)
            L = mul(L, segl.query(u, v));
          else
            L = mul(L, segr.query(v, u));
        } else {
          if (u < v)
            R = mul(segl.query(u, v), R);
          else
            R = mul(segr.query(v, u), R);
        }
      };
      hld.uncommutable_node_query(x, y, f);
      P res = mul(L, R);
      wt((res.first * z + res.second).get());
      wt('\n');
    }
  }
}
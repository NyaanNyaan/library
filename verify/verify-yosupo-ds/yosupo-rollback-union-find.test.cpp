#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../../template/template.hpp"
#include "../../data-structure/rollback-union-find.hpp"
#include "../../misc/fastio.hpp"

using namespace Nyaan; void Nyaan::solve() {
  int N, Q;
  rd(N, Q);
  vi ans(Q + 1, -1);
  using A = array<int, 4>;
  V<V<A>> g(Q + 1);
  rep1(i, Q) {
    int t, k, u, v;
    rd(t, k, u, v);
    ++k;
    g[k].push_back({{t, int(i), u, v}});
  }
  RollbackUnionFind uf(N);
  auto dfs = [&](auto rc, const A& a, int d = 0) -> void {
    if (a[0] == 1) {
      ans[a[1]] = uf.same(a[2], a[3]);
    } else {
      if (a[0] == 0) uf.unite(a[2], a[3]);
      for (auto& a : g[a[1]]) rc(rc, a, d + 1);
      if (a[0] == 0) uf.undo();
    }
  };
  dfs(dfs, {{-1, 0, -1, 0}});
  each(x, ans) if (x != -1) wtn(x);
}
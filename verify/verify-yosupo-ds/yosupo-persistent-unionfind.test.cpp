#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../../competitive-template.hpp"
#include "../../data-structure/persistent-union-find.hpp"

void solve() {
  ini(N, Q);
  PersistentUnionFind uf(N);
  V<decltype(uf)::Node *> roots(Q + 1, nullptr);
  roots[0] = uf.get_root();

  rep(i, Q) {
    ini(t, k, u, v);
    if (t) {
      auto r = roots[k + 1];
      out(uf.same(u, v, r));
    } else {
      auto r = roots[k + 1];
      uf.unite(u, v, r);
      roots[i + 1] = uf.get_root();
    }
  }
}
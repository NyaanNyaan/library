#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2821"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/union-find.hpp"
#include "../../graph/graph-template.hpp"
#include "../../tree/tree-hash.hpp"
using namespace Nyaan;

void q() {
  ini(N1, M1);
  auto g1 = graph(N1, M1);
  ini(N2);
  auto g2 = graph(N2);

  auto th = tree_hash(g2);

  UnionFind uf(N1);
  rep(i, N1) each(j, g1[i]) uf.unite(i, j);
  ll ans = 0;
  rep(i, N1) {
    if (uf.find(i) != i) continue;
    vvi h(uf.size(i));

    int buf = 0;
    unordered_map<int, int> mp;
    auto dfs = [&](auto rc, int c, int p) -> void {
      mp[c] = buf++;
      each(d, g1[c]) {
        if (d == p) continue;
        rc(rc, d, c);
        h[mp[c]].push_back(mp[d]);
        h[mp[d]].push_back(mp[c]);
      }
    };
    dfs(dfs, i, -1);

    auto th2 = tree_hash(h);
    ans += th == th2;
  }
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

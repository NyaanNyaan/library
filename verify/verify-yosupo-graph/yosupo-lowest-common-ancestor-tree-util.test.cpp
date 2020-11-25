#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../competitive-template.hpp"
#include "../../misc/fastio.hpp"
#include "../../tree/tree-path.hpp"

void solve() {
  int N, Q;
  rd(N, Q);
  vvi g(N);
  rep1(i, N - 1) {
    int p;
    rd(p);
    g[p].push_back(i);
  }
  Tree<vvi> tree(g);
  rep(i, Q) {
    int u, v;
    rd(u, v);
    wtn(tree.lca(u, v));
  }
}

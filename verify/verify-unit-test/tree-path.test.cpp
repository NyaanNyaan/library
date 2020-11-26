#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../competitive-template.hpp"
#include "../../misc/rng.hpp"
#include "../../tree/tree-query.hpp"

void test(vvi& g) {
  cerr << g.size() << endl;
  Tree<vvi> tree(g);
  int N = sz(g);
  rep(i, N) rep(j, N) {
    vi p1 = tree.path(i, j);
    vi p2{int(i)};
    for (int k = i; k != j;) {
      p2.push_back(k = tree.nxt(k, j));
    }
    assert(p1 == p2);
    int l = i, ld = tree.depth(i);
    each(x, p1) if (amin(ld, tree.depth(x))) l = x;
    assert(l == tree.lca(i, j));
  }
}

void solve() {
  for (int N : vi{2, 3, 4, 5, 10, 100, 300}) {
    vvi g(N);
    rep1(i, N - 1) g[randint(0, i)].push_back(i);
    test(g);
  }

  for (int N : vi{2, 3, 4, 5, 10, 100, 200}) {
    vvi g(N);
    rep1(i, N - 1) g[i - 1].push_back(i);
    test(g);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/parallel-union-find.hpp"
#include "../../data-structure/union-find.hpp"
#include "../../misc/rng.hpp"
using namespace Nyaan;

void test() {
  rep(t, 1000) {
    int N = rng(1, 50);
    UnionFind uf(N);
    ParallelUnionFind puf(N);

    rep(u, 100) {
      int len = rng(0, N);
      int l = rng(0, N - len);
      int r = rng(0, N - len);
      rep(i, len) uf.unite(l + i, r + i);
      puf.unite(l, l + len, r, r + len);
      rep(i, N) rep(j, i) assert(uf.same(i, j) == puf.same(i, j));
    }
  }
  trc2("OK");
}

void q() {
  test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

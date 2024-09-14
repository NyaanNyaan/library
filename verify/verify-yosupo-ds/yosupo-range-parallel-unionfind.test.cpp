#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/parallel-union-find.hpp"
//
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;

using namespace Nyaan;

void q() {
  ini(N, Q);
  vm X(N);
  in(X);

  ParallelUnionFind uf(N);
  mint ans = 0;
  rep(i, Q) {
    inl(k, a, b);
    uf.unite(a, a + k, b, b + k, [&](int x, int y) {
      ans += X[x] * X[y];
      X[x] += X[y];
    });
    out(ans);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
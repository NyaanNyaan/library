#define PROBLEM "https://yukicoder.me/problems/no/1170"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/divide-interval.hpp"
#include "../../data-structure/union-find.hpp"
using namespace Nyaan;

void q() {
  inl(N, a, b);
  vl X(N);
  in(X);

  DivideInterval d(N);
  int B = d.B;
  UnionFind uf(2 * B);
  vi num(2 * B);
  rep(i, N) num[B + i] = 1;

  auto f = [&](int x, int y) { num[x] += num[y]; };
  auto rec = [&](auto r, int c) -> void {
    if (B <= c) return;
    rep(t, 2) {
      if (!uf.same(c, c * 2 + t)) {
        uf.unite(c, c * 2 + t, f);
        r(r, c * 2 + t);
      }
    }
  };
  rep(i, N) {
    int l = lb(X, X[i] + a);
    int r = lb(X, X[i] + b + 1);
    d.apply(l, r, [&](int j) {
      uf.unite(i + B, j, f);
      rec(rec, j);
    });
  }
  rep(i, N) out(num[uf.find(B + i)]);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

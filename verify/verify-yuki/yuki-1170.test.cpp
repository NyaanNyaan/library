#define PROBLEM "https://yukicoder.me/problems/no/1170"

#include "../../template/template.hpp"
//
#include "../../data-structure/range-union-find.hpp"

using namespace Nyaan; void Nyaan::solve() {
  inl(N, A, B);
  vl x(N);
  in(x);
  RangeUnionFind uf(N);
  rep(i, N) {
    int l = lb(x, x[i] + A);
    int r = lb(x, x[i] + B + 1);
    uf.range_unite(l, r);
  }
  rep(i, N) {
    int l = lb(x, x[i] + A);
    int r = lb(x, x[i] + B + 1);
    if (l != r) uf.unite(l, i);
  }
  rep(i, N) out(uf.size(i));
}
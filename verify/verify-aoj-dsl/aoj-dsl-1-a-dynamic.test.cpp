#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include "../../template/template.hpp"
#include "../../data-structure/dynamic-union-find.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ini(N, Q);
  DynamicUnionFind uf;
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(x, y);
      uf.unite(x, y);
    } else {
      ini(x,y);
      out(uf.same(x,y));
    }
  }
}
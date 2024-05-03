#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/union-find.hpp"
#include "../../graph/functional-graph.hpp"
#include "../../graph/graph-template.hpp"

using namespace Nyaan;

void q() {
  ini(N);
  auto g = graph(N, N);
  FunctionalGraph fg{N, g};
  UnionFind uf(N);
  auto loops = fg.get_loops();
  each(loop, loops) {
    int x = loop[0];
    each(y, loop) uf.unite(x, y);
  }
  ini(Q);
  while (Q--) {
    ini(a, b);
    --a, --b;
    out(uf.same(a, b) ? 2 : 1);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

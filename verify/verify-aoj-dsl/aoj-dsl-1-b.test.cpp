#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include "../../template/template.hpp"
#include "../../data-structure/union-find-with-potential.hpp"

using namespace Nyaan; void Nyaan::solve() {
  ini(N, Q);
  UnionFindWithPotential<int> uf(N);
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(x, y, z);
      uf.merge(y, x, z);
    } else {
      ini(x, y);
      if (!uf.same(x, y))
        out("?");
      else
        out(uf.diff(y, x));
    }
  }
}
#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include "../../competitive-template.hpp"
#include "../../data-structure-2d/2d-binary-indexed-tree.hpp"

void solve() {
  ini(N);
  int L = 1000;
  BinaryIndexedTree2D<int> bit(L + 1, L + 1);
  rep(i, N) {
    ini(x1, y1, x2, y2);
    bit.imos(x1, y1, x2 - 1, y2 - 1, 1);
  }
  int ans = 0;
  rep(i, L) rep(j, L) { amax(ans, bit.sum(i, j)); }
  out(ans);
}
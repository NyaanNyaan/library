#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include "../../competitive-template.hpp"
#include "../../data-structure/binary-indexed-tree.hpp"

void solve() {
  ini(N, Q);
  BinaryIndexedTree<int> bit(N);
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(s, t, x);
      s--, t--;
      bit.imos(s, t, x);
    } else {
      ini(i);
      i--;
      out(bit.sum(i));
    }
  }
}
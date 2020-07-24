#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../competitive-template.cpp"
#include "../data-structure/binary-indexed-tree.cpp"

void solve() {
  ini(N, Q);
  BinaryIndexedTree<int> bit(N);
  rep(_, Q) {
    ini(c);
    if (c == 0) {
      ini(i, a);
      i--;
      bit.add(i, a);
    } else {
      ini(x, y);
      x--, y--;
      out(bit.sum(x, y));
    }
  }
}
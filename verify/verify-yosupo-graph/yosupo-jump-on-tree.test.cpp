#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
//
#include "../../template/template.hpp"
//
#include "../../graph/graph-template.hpp"
//
#include "../../tree/tree-query.hpp"
using namespace Nyaan;

void q() {
  inl(N, Q);
  auto g = graph(N, N - 1, false, false);
  Tree tree{g};
  rep(_, Q) {
    ini(s, t, i);
    out(tree.jump(s, t, i));
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

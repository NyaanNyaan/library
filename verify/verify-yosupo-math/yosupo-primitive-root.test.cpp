#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
//
#include "../../template/template.hpp"
//
#include "../../math/primitive-root-ll.hpp"

using namespace Nyaan;

void q() {
  ini(Q);
  while (Q--) {
    inl(p);
    out(primitive_root_ll(p));
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

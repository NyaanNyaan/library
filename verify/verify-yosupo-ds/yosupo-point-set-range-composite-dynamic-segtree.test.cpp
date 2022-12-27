#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
//
#include "../../template/template.hpp"
//
#include "../../math/affine-transformation.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../segment-tree/dynamic-segment-tree.hpp"
using namespace Nyaan;

using A = Affine<LazyMontgomeryModInt<998244353>>;

A f(A a, A b) { return a * b; }
A ti() { return A{}; }
using Trie = DynamicSegmentTree<A, f, ti>;

void Nyaan::solve() {
  inl(N, Q);
  Trie trie(N);
  rep(i, N) {
    inl(c, d);
    trie.set_val(i, {c, d});
  }
  rep(_, Q) {
    inl(cmd);
    if (cmd == 0) {
      inl(p, c, d);
      trie.set_val(p, {c, d});
    } else {
      inl(l, r, x);
      out(trie.fold(l, r)(x));
    }
  }
}

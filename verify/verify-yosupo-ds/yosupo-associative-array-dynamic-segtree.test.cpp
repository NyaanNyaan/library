#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/dynamic-segment-tree.hpp"

using namespace Nyaan;

ll f(ll, ll) { return -1; }
ll ti() { return 0; }
using Trie = DynamicSegmentTree<ll, f, ti>;

void Nyaan::solve() {
  inl(Q);
  Trie t(TEN(18) + 10);
  while (Q--) {
    ini(cmd);
    if (cmd == 0) {
      inl(k, v);
      t.set_val(k, v);
    } else {
      inl(k);
      out(t.get_val(k));
    }
  }
}

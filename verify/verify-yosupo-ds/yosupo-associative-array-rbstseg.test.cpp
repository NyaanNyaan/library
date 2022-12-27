#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
//
#include "../../template/template.hpp"
//
#include "../../segment-tree/rbst-segment-tree.hpp"
//
using namespace Nyaan;

ll f(ll, ll) { return 0; }
ll ti() { return 0; }
using Seg = RBSTSegmentTree<ll, ll, f, ti>;

void Nyaan::solve() {
  Seg seg;
  inl(Q);
  while (Q--) {
    ini(cmd);
    if (cmd == 0) {
      inl(k, v);
      seg.set_val(k, v);
    } else {
      inl(k);
      out(seg.get_val(k));
    }
  }
}

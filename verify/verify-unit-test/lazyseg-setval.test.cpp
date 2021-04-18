#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
#include "../../segment-tree/lazy-segment-tree-utility.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  int N = 100000;
  int Q = 1000000;
  vl init(N);
  AddSum_LazySegmentTree<ll> seg(init);

  rep(i, Q) {
    if (rng() & 1) {
      int l, r;
      l = randint(0, N);
      r = randint(0, N);
      if (l > r) swap(l, r);
      r++;
      seg.update(l, r, randint(0, TEN(6)));
    } else {
      int x = randint(0, N);
      ll v = seg.get_val(x);
      ll w = seg.query(x, x + 1);
      assert(v == w);
    }
  }

  {
    ini(a, b);
    out(a + b);
  }
}
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
#include "../../segment-tree/lazy-segment-tree.hpp"

using namespace Nyaan;

auto f = [](pl a, pl b) { return pl(a.first + b.first, a.second + b.second); };
auto g = [](pl a, ll b) { return pl(a.first + a.second * b, b); };
auto h = [](ll a, ll b) { return a + b; };
pl ti{0, 0};
ll ei{0};

using namespace Nyaan;

void Nyaan::solve() {
  int N = 100000;
  int Q = 1000000;
  vl init(N);
  LazySegmentTree<pl, ll, decltype(f), decltype(g), decltype(h)> seg(
      vp(N), f, g, h, ti, ei);

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
      ll v = seg.get_val(x).first;
      ll w = seg.query(x, x + 1).first;
      assert(v == w);
    }
  }

  {
    ini(a, b);
    out(a + b);
  }
}
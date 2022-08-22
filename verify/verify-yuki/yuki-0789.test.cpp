#define PROBLEM "https://yukicoder.me/problems/no/789"

#include "../../segment-tree/dynamic-segment-tree.hpp"
#include "../../template/template.hpp"

using namespace Nyaan;
ll f(ll a, ll b) { return a + b; }
ll ti() { return 0; }

void Nyaan::solve() {
  ini(N);
  auto f = [](ll a, ll b) { return a + b; };
  DynamicSegmentTree<ll, f, ti> seg(inf);
  ll ans = 0;
  rep(_, N) {
    inl(c, x, y);
    if (c == 0) {
      seg.set_val(x, seg.get_val(x) + y);
    } else {
      ans += seg.fold(x, y + 1);
    }
  }
  out(ans);
}

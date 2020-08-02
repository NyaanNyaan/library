#define PROBLEM "https://yukicoder.me/problems/no/789"

#include "../../competitive-template.hpp"
#include "../../segment-tree/dynamic-segment-tree.hpp"

void solve() {
  ini(N);
  auto f = [](ll a, ll b) { return a + b; };
  DynamicSegmentTree<ll, decltype(f)> seg(-100, inf, f, 0);

  ll ans = 0;
  rep(_, N) {
    inl(c, x, y);
    if (c == 0) {
      seg.add(x, y);
    } else {
      ans += seg.query(x, y + 1);
    }
  }
  out(ans);
}

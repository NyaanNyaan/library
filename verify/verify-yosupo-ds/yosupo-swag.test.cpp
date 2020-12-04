#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../../template/template.hpp"
#include "../../data-structure/slide-window-aggregation.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"

using namespace Nyaan; void Nyaan::solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  using p = pair<mint, mint>;
  auto f = [](const p &a, const p &b) {
    return p{a.first * b.first, a.second * b.first + b.second};
  };
  SlideWindowAggregation<p, decltype(f)> swag(f, p{1, 0});
  int Q;
  rd(Q);
  rep(_, Q) {
    int cmd;
    rd(cmd);
    if (cmd == 0) {
      int a, b;
      rd(a, b);
      swag.push(p{a, b});
    } else if (cmd == 1) {
      swag.pop();
    } else {
      int x;
      rd(x);
      p q = swag.query();
      wtn((q.first * x + q.second).get());
    }
  }
}
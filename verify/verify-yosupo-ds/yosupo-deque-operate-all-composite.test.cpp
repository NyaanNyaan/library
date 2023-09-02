#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"
//
#include "../../template/template.hpp"
//
#include "../../data-structure/slide-window-aggregation-deque.hpp"
#include "../../math/affine-transformation.hpp"
//
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
using namespace Nyaan;

void q() {
  using A = Affine<mint>;

  SlideWindowAggregationDeque swag([](const A &l, const A &r) { return l * r; },
                                   A{});
  deque<A> dq;

  ini(Q);
  while (Q--) {
    ini(cmd);
    if (cmd == 0) {
      ini(a, b);
      swag.push_front({a, b});
      dq.push_front({a, b});
    } else if (cmd == 1) {
      ini(a, b);
      swag.push_back({a, b});
      dq.push_back({a, b});
    } else if (cmd == 2) {
      if (dq.front() != swag.front()) exit(1);
      swag.pop_front();
      dq.pop_front();
    } else if (cmd == 3) {
      if (dq.back() != swag.back()) exit(1);
      swag.pop_back();
      dq.pop_back();
    } else {
      ini(x);
      out(swag.query()(x));
    }
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

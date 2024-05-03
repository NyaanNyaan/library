#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation"
//
#include "../../template/template.hpp"
//
#include "../../math/stern-brocot-tree-binary-search.hpp"
using namespace Nyaan;

void q() {
  ini(N, x, y);
  ll z = gcd(x, y);
  x /= z, y /= z;
  if (max(x, y) <= N) die(x, y, x, y);
  auto [lo, up] = binary_search_on_stern_brocot_tree<ll>(
      [&](pair<ll, ll> ab) {
        auto [a, b] = ab;
        return a * y >= b * x;
      },
      N);
  die(lo.fi, lo.se, up.fi, up.se);
}

void Nyaan::solve() {
  int t = 1;
  in(t);
  while (t--) q();
}

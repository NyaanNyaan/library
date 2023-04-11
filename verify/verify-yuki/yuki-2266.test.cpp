#define PROBLEM "https://yukicoder.me/problems/no/2266"

#include "../../template/template.hpp"
//
#include "../../atcoder/math.hpp"
//
#include "../../math/rational.hpp"
#include "../../math/stern-brocot-tree.hpp"
//
#include "../../multiplicative-function/enumerate-sum-of-multiplicative-function.hpp"
using namespace Nyaan;

// k 番目に小さい
pl calc(ll N, ll K) {
  auto sg = [](int n) -> int { return n; };
  auto sh = [](int) -> int { return 1; };
  enumerate_mf_prefix_sum<int, decltype(sg), decltype(sh)> moe(N, sg, sh);

  auto cnt = [&](Rational f) -> ll {
    ll s = 0;
    enumerate_quotient(N, [&](ll q, ll l, ll r) {
      ll x = 0;
      x += atcoder::floor_sum(r + 1, f.y, f.x, 0);
      x -= atcoder::floor_sum(l + 1, f.y, f.x, 0);
      s += x * moe(q);
    });
    return s;
  };
  auto judge = [&](Rational f) -> bool { return cnt(f) >= K; };
  auto ans = binary_search_on_stern_brocot_tree(judge, N);
  return {ans.x, ans.y};
}

void q() {
  inl(N, K);
  auto g = [](ll n) -> ll { return n; };
  auto h = [](ll n) -> ll { return n * (n + 1) / 2; };
  enumerate_mf_prefix_sum<ll, decltype(g), decltype(h)> tot(N, g, h);

  ll s = tot(N) - 1;
  trc(s);
  ll p = -1, q = -1;
  if (K <= s) {
    tie(p, q) = calc(N, K);
  } else if (K == s + 1) {
    p = q = 1;
  } else if (K <= s * 2 + 1) {
    tie(q, p) = calc(N, 2 * s + 1 - (K - 1));
  } else {
    // do nothing
  }
  if (p == -1) {
    out(-1);
  } else {
    cout << p << "/" << q << "\n";
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

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
  
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

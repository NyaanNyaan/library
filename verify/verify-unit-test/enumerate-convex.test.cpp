#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../math/enumerate-convex.hpp"
#include "../../math/isqrt.hpp"
#include "../../math/two-square.hpp"
#include "../../misc/rng.hpp"
//
using namespace Nyaan;

vector<pair<long long, long long>> calc(ll N) {
  ll m = isqrt(N);
  // (0, m) を中心とする半径 sqrt(N) の円
  auto inside = [&](ll x, ll y) {
    return y >= m or x * x + (y - m) * (y - m) <= N;
  };
  auto candicate = [&](ll x, ll y, ll c, ll d) {
    // (x + sc)^2 + (y - m + sd)^2 <= N
    ll A = c * c + d * d;
    ll B = 2 * c * x + 2 * d * (y - m);
    // A s^2 + B s + const <= 0
    ll num = -B, den = 2 * A;
    ll quo = num / den, rem = num % den;
    if (rem < 0) quo--, rem += den;
    if (2 * rem > den) quo++, rem -= den;
    return quo;
  };

  auto ans = enumerate_convex<ll>(0, 0, m, inside, candicate);
  vector<pair<long long, long long>> res;
  each2(x, y, ans) if (x * x + (y - m) * (y - m) == N) {
    res.emplace_back(x, m - y);
  }
  sort(begin(res), end(res));
  return res;
}

void check(long long N) {
  auto ac = two_square(N);
  auto ad = calc(N);
  assert(ac == ad);
}

void q() {
  rep1(N, 1000) check(N);
  rep(t, 100) check(rng(1001, TEN(9)));
  check(TEN(18));

  trc2("OK");
  inl(a, b);
  out(a + b);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

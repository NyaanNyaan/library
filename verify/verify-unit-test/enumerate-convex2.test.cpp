#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/timer.hpp"
//
#include "../../math/enumerate-convex.hpp"
//
using namespace Nyaan;

// sum [x=0...(p-1)/2] floor((x^2 + r) / p) mod 2^{64}
ll calc(i128 p, i128 r) {
  assert(0 <= r);
  // y >= (x^2 + r + 1) / p に含まれる頂点を列挙
  r++;
  auto inside = [&](ll x, ll y) { return i128(p) * y >= i128(x) * x + r; };
  auto candicate = [&p](ll x, ll, ll c, ll d) -> ll {
    // p (y + k d) >= (x + k c)^2 + r
    // c^2 k^2 - (p d - 2 x c) k + (const) <= 0
    double numer = double(p) * d - 2.0 * x * c;
    double denom = 2.0 * c * c;
    return ll(numer / denom + 0.5);
  };
  auto ps = enumerate_convex<ll>(0, 1, (p - 1) / 2, inside, candicate);
  auto [xmax, ymax] = ps.back();
  ll res = (xmax + 1) * ymax - 1;
  rep(i, sz(ps) - 1) {
    auto [a, b] = ps[i];
    auto [c, d] = ps[i + 1];
    ll x = c - a, y = d - b;
    ll S2 = x * y;
    ll on_edge = x + y + gcd(x, y);
    ll in_edge = (S2 + 2 - on_edge) / 2;
    ll cur = on_edge + in_edge - 1;
    cur += (ymax - d) * (c - a);
    res -= cur;
  }
  return res;
}

i128 naive(i128 p, i128 r) {
  /*
  vector<long long> v;
  rep(x, (p - 1) / 2 + 1) v.push_back((x * x + r) / p);
  trc(v);
  return Sum(v);
  */
  ll res = 0;
  rep(x, (p - 1) / 2 + 1) res += (x * x + r) / p;
  return res;
}

void test() {
  reg(p, 3, 1000) rep(r, p) {
    ll an = naive(p, r);
    ll ac = calc(p, r);
    assert(an == ac);
  }
  trc2("OK");
}

void q() {
  // https://contest.ucup.ac/contest/1460/problem/6188
  test();

  if (0) {
    inl(p, l, r);
    ll upper = calc(p, p - l);
    ll lower = calc(p, p - (r + 1));
    out(upper - lower);
  }

  if (1) {
    inl(a, b);
    out(a + b);
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

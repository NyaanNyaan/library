#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
//
#include "../../math-fast/gcd.hpp"
//
#include "../../atcoder/internal_math.hpp"
#include "../../atcoder/math.hpp"
//
#include "../../internal/internal-math.hpp"
//

using namespace Nyaan;

void test_safe_mod() {
  auto check = [&](ll a, ll p) {
    ll m1 = internal::safe_mod(a, p);
    ll m2 = atcoder::internal::safe_mod(a, p);
    assert(m1 == m2 && "safe_mod");
  };

  reg(a, -100, 100) reg(p, 1, 100) check(a, p);
  ll M = (1uLL << 62) - 1;
  check(M, 1), check(-M, 1);
  check(M, M), check(-M, M);
  rep(t, TEN(5)) {
    ll a = rng(-M, M);
    ll p = rng(+1, M);
    check(a, p);
  }
}

void test_inv_gcd() {
  auto check = [&](ll a, ll b) {
    auto p1 = internal::inv_gcd(a, b);
    auto p2 = atcoder::internal::inv_gcd(a, b);
    assert(p1 == p2 && "inv_gcd");
  };

  reg(a, -100, 100) reg(b, 1, 100) check(a, b);
  ll M = (1uLL << 62) - 1;
  check(M, 1), check(-M, 1);
  check(M, M), check(-M, M);
  rep(t, TEN(5)) {
    ll a = rng(-M, M);
    ll p = rng(+1, M);
    check(a, p);
  }
}

void test_inv() {
  auto check = [&](ll a, ll p) -> void {
    if (gcd(a, p) != 1) return;
    ll b1 = internal::inv(a, p);
    ll b2 = atcoder::inv_mod(a, p);
    if (b1 != b2) trc2(a, p, b1, b2);
    assert(b1 == b2 && "inv");
  };
  reg(a, -100, 100) reg(b, 1, 100) check(a, b);
  ll M = (1uLL << 62) - 1;
  check(M, 1), check(-M, 1);
  check(M, M), check(-M, M);
  rep(t, TEN(5)) {
    ll p = rng(+1, M);
    ll a = p;
    while (gcd(a, p) != 1) a = rng(-M, M);
    check(a, p);
  }
}

void test_modpow() {
  auto check = [&](ll x, ll e, ll p) -> void {
    assert(p < (1LL << 30));
    ll b1 = internal::modpow<int, ll>(x % p, e, p);
    ll b2 = atcoder::pow_mod(x, e, p);
    if (b1 != b2) trc2(x, e, p, b1, b2);
    assert(b1 == b2 && "modpow");
  };

  rep(e, 30) rep1(p, 30) {
    rep(x, 30) check(x, e, p);
    rep(t, 10) check(rng(-TEN(18), TEN(18)), e, p);
  }
  ll M = (1uLL << 30) - 1;
  rep(t, 100000) {
    ll a = rng(-M, M);
    ll e = rng(0, M);
    ll p = rng(1, M);
    check(a, e, p);
  }
}

void test_crt() {
  ll cnt0 = 0;
  auto check = [&](vl a, vl p) -> void {
    auto b1 = internal::crt(a, p);
    auto b2 = atcoder::crt(a, p);
    if (b1 != b2) trc2(a, p, b1, b2);
    assert(b1 == b2 && "crt");
    rep(i, sz(a)) a[i] = internal::safe_mod(a[i], p[i]);
    auto b3 = internal::crt(a, p);
    auto b4 = atcoder::crt(a, p);
    assert(b1 == b3 && "crt");
    assert(b2 == b4 && "crt");
    cnt0 += b1 == pl{0, 0};
  };

  int tnum = 300000;
  ll M = (1uLL << 62) - 1;

  rep(t, tnum) {
    double th = 30.0 + rnd() * 28.0;
    V<ll> rem, mod;
    while (true) {
      rem.clear();
      mod.clear();
      i128 g = 1;
      set<int> st;
      while (true) {
        ll m = pow(2.0, 0.0 + rnd() * th);
        if (st.count(m)) continue;
        st.insert(m);
        i128 nxt = g / binary_gcd128(g, m) * m;
        if (nxt >= 1e18) break;
        g = nxt;
        ll r = rng(-M, M);
        rem.push_back(r);
        mod.push_back(m);
      }
      if (rem.size() >= 2u) break;
    }
    check(rem, mod);
  }
  assert(cnt0 <= tnum * 0.8);
}

void Nyaan::solve() {
  test_safe_mod();
  test_inv_gcd();
  test_inv();
  test_modpow();
  test_crt();

  cerr << "OK" << endl;
  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

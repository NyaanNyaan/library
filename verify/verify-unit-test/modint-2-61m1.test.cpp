#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../modint/modint-2-61m1.hpp"
//
#include "../../misc/rng.hpp"
using namespace Nyaan;

using mint = modint_2_61m1;
constexpr ll mod = (1ll << 61) - 1;
void check(ll a, ll b) {
  mint A{a}, B{b};
  {
    ll c = a + b;
    c %= mod, c += mod, c %= mod;
    assert((ll)((A + B).get()) == c);
  }
  {
    ll c = a - b;
    c %= mod, c += mod, c %= mod;
    assert((ll)((A - B).get()) == c);
  }
  {
    i128 c = i128(a) * b;
    c %= mod, c += mod, c %= mod;
    assert((A * B).get() == u64(c));
  }
  if (b % mod != 0) {
    mint C = (A / B).get();
    assert(C * B == A);
  }
  {
    ll c = -a;
    c %= mod, c += mod, c %= mod;
    assert(ll((-A).get()) == c);
  }
  {
    ll e = rng(1, TEN(9));
    ll x = Power<i128>(a, e, 1LL, [](i128& z) { z %= ll(mod); });
    assert(A.pow(e) == mint{x});
  }
}

void q() {
  reg(s, -10, 10) reg(t, -10, 10) {
    check(s, t);
    check(mod - s, t);
    check(s, mod - t);
    check(mod - s, mod - t);
  }
  rep(t, TEN(6)) {
    ll a = rng(-mod, mod);
    ll b = rng(-mod, mod);
    check(a, b);
  }
  trc2("OK");

  {
    int a, b;
    cin >> a >> b;
    cout << a + b << "\n";
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

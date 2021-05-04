#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
#include "../../ntt/real-fft.hpp"

using namespace Nyaan;

vl naive(vi a, vi b) {
  int n = sz(a), m = sz(b);
  vl c(n + m - 1);
  rep(i, n) rep(j, m) { c[i + j] += 1LL * a[i] * b[j]; }
  return c;
}

vi naive_mod(vi a, vi b, int mod) {
  int n = sz(a), m = sz(b);
  vi c(n + m - 1);
  rep(i, n) rep(j, m) {
    ll x = c[i + j] + 1LL * a[i] * b[j];
    c[i + j] = x % mod;
  }
  return c;
}

void is_same_negative(vi a, vi b) {
  auto c1 = ArbitraryModConvolution::CooleyTukey::multiply(a, b);
  auto c2 = naive(a, b);
  if (c1 != c2) {
    out(sz(a), sz(b));
    rep(i, sz(c1)) {
      if (c1[i] != c2[i]) out(i, c1[i], c2[i]);
    }
    exit(1);
  }
}

void is_same_mod(vi a, vi b) {
  auto c1 = ArbitraryModConvolution::CooleyTukey::karatsuba<TEN(9) + 7>(a, b);
  auto c2 = naive_mod(a, b, TEN(9) + 7);
  if (c1 != c2) {
    out(a);
    out(b);
    out(c1);
    out(c2);
    exit(1);
  }
}

void test() {
  // negative
  rep(loop, 100) {
    vi a(randint(1, TEN(3)));
    vi b(randint(1, TEN(3)));
    each(x, a) x = randint(-TEN(5), TEN(5));
    each(x, b) x = randint(-TEN(5), TEN(5));
    is_same_negative(a, b);
  }
  // mod
  rep(loop, 100) {
    vi a(randint(1, 100));
    vi b(randint(1, 100));
    each(x, a) x = randint(0, TEN(9) + 7);
    each(x, b) x = randint(0, TEN(9) + 7);
    is_same_mod(a, b);
  }
}

void Nyaan::solve() {
  test();

  int a, b;
  cin >> a >> b;
  cout << (a + b) << endl;
}
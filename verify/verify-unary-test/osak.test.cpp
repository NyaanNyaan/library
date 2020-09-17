#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../competitive-template.hpp"
#include "../../prime/fast-factorize.hpp"
#include "../../prime/osak.hpp"

unsigned long long rng2() {
  static unsigned long long x_ =
      chrono::duration_cast<chrono::nanoseconds>(
          chrono::high_resolution_clock::now().time_since_epoch())
          .count();
  x_ = x_ ^ (x_ << 7);
  return x_ = x_ ^ (x_ >> 9);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << (a + b) << '\n';

  rep(i, 100000) {
    auto f1 = osak<10000000>(i);
    auto f2 = factorize(i);
    auto end = [&]() {
      out(f1);
      out(f2);
      exit(1);
    };
    if (sz(f1) != sz(f2)) end();
    rep(i, sz(f1)) if (f1[i] != (int)f2[i]) end();
  }
  rep(i, 500000) {
    int n = rng2() & ((1 << 23) - 1);
    auto f1 = osak<10000000>(n);
    auto f2 = factorize(n);
    auto end = [&]() {
      out(f1);
      out(f2);
      exit(1);
    };
    if (sz(f1) != sz(f2)) end();
    rep(i, sz(f1)) if (f1[i] != (int)f2[i]) end();
  }
}
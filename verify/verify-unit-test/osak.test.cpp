#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
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

constexpr int MX = 10000000;

using namespace Nyaan;
void Nyaan::solve() {
  auto end = [](auto x, auto y) {
    out(x);
    out(y);
    exit(1);
  };
  rep(i, 100000) {
    auto f1 = osak<MX>(i);
    auto f2 = factorize(i);
    if (f1.size() != f2.size()) end(f1, f2);
    rep(i, sz(f1)) if (f1[i] != (int)f2[i]) end(f1, f2);

    auto d1 = osak_divisors<MX>(i);
    auto d2 = divisors(i);
    if (d1.size() != d2.size()) end(d1, d2);
    rep(i, sz(d1)) if (d1[i] != (int)d2[i]) end(d1, d2);
  }

  rep(_, 200000) {
    int i = rng2() & ((1 << 23) - 1);
    auto f1 = osak<MX>(i);
    auto f2 = factorize(i);
    if (f1.size() != f2.size()) end(f1, f2);
    rep(i, sz(f1)) if (f1[i] != (int)f2[i]) end(f1, f2);

    auto d1 = osak_divisors<MX>(i);
    auto d2 = divisors(i);
    if (d1.size() != d2.size()) end(d1, d2);
    rep(i, sz(d1)) if (d1[i] != (int)d2[i]) end(d1, d2);
  }

  int a, b;
  cin >> a >> b;
  cout << (a + b) << '\n';
}
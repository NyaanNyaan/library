#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../math/gray-code.hpp"
#include "../../math/inv-mod.hpp"
#include "../../math/isqrt.hpp"
#include "../../math/floor-sum.hpp"
#include "../../misc/rng.hpp"
using namespace Nyaan;

void gray_code_test() {
  for (int i = 0; i < 20; i++) {
    auto g = gray_code(i);
    int s = (int)g.size();
    for (int j = 0; j < s; j++) {
      int d = g[j] ^ g[j ? j - 1 : s - 1];
      assert(d == (d & -d));
    }
  }
}

// count x : ax + b mod m < yr, 0 <= x < xr
void mod_affine_range_counting_test() {
  int M = 100000;
  rep(_, 100) {
    int a = randint(0, M);
    int b = randint(0, M);
    int m = randint(1, M + 1);
    int xr = randint(100, 100 + M + 1);
    int yr = randint(0, m + 1);
    int a1 = mod_affine_range_counting<long long>(a, b, m, xr, yr);
    int a2 = 0;
    rep(x, xr) {
      int X = (a * x + b) % m;
      a2 += X < yr;
    }
    assert(a1 == a2);
  }
}

void isqrt_test() {
  auto check = [&](long long x) -> void {
    ll y = isqrt(x);
    assert(y * y <= x);
    assert(x < (y + 1) * (y + 1));
  };

  rep(i, TEN(4)) check(i);
  rep(_, 100) {
    ll x = rng(100, 2e9);
    x = x * x;
    reg(i, x - 50, x + 50) check(i);
  }
}

void inv_mod_test() {
  rep1(mod, 100) {
    rep(a, mod * 10) {
      if (gcd(a, mod) != 1) continue;
      int b = inv_mod(a, mod);
      assert(a * b % mod == 1 % mod);
    }
  }

  rep(_, 1000) {
    ll mod = rng(2, TEN(18));
    ll x = 0;
    do {
      x = rng(1, mod - 1);
    } while (gcd(mod, x) != 1);
    ll y = inv_mod(x, mod);
    assert(i128(x) * y % mod == 1);
  }
}

void Nyaan::solve() {
  gray_code_test();
  cerr << "OK gray code" << endl;
  mod_affine_range_counting_test();
  cerr << "OK mod affine" << endl;
  isqrt_test();
  cerr << "OK isqrt" << endl;
  inv_mod_test();
  cerr << "OK inv mod" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
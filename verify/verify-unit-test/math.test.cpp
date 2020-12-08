#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../math/gray-code.hpp"
#include "../../math/sum-of-floor.hpp"
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

void Nyaan::solve() {
  gray_code_test();
  mod_affine_range_counting_test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}
#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
#include "../../modint/arbitrary-modint.hpp"
using namespace Nyaan;

using mint = ArbitraryModInt;

void test(int m) {
  mint::set_mod(m);
  mint x = 1;
  int y = 1;
  rep(loop, TEN(3)) {
    int z = randint(0, 2 * TEN(9));
    if (rng() & 1) z = -z;
    x *= z;
    y = 1LL * y * z % m;
    if (y < 0) y += m;
    assert(x.x == y);
  }
}

void Nyaan::solve() {
  test(1);
  test(2);
  test(3);
  test(998244353);
  test(1000000007);
  test(2 * TEN(9));
  rep(i, TEN(5)) test(randint(1, 2 * TEN(9) + 1));
  cerr << "OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

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

  Barrett barrett(m);

  // m!=1 で正しく動作するはず
  if (m != 1) {
    rep(loop, TEN(3)) {
      u64 i = rng();
      auto [quo, rem] = barrett.quorem(i);
      assert(quo == barrett.quo(i));
      assert(rem == barrett.rem(i));
      i64 quo2 = i / m;
      i64 rem2 = i % m;
      assert(quo == quo2);
      assert(rem == rem2);
    }
  }

  rep(loop, TEN(3)) {
    int p = randint(0, m);
    long long e = randint(0, 10);
    mint r1 = mint{p}.pow(e);
    int r2 = barrett.pow(p, e);
    /*
    if (r1.get() != r2) {
      cerr << p << " " << e << " " << m << endl;
      cerr << r1 << " " << r2 << endl;
    }
    */
    assert(r1.get() == r2);
  }
}

void Nyaan::solve() {
  int mod_max = (1LL << 30) - 1;
  rep1(m, 10) test(m);
  test(998244353);
  test(1000000007);
  rep(t, 10) test(mod_max - t);
  rep(i, TEN(4)) test(randint(1, mod_max + 1));
  cerr << "OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

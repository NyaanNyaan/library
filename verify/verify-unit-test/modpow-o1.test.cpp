#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../modulo/modpow-o1.hpp"
//
#include "../../modint/arbitrary-modint.hpp"
#include "../../prime/miller-rabin.hpp"
//
#include "../../misc/rng.hpp"
#include "../../misc/timer.hpp"

using namespace Nyaan;

void test() {
  using mint = ArbitraryModInt;

  vector<int> mods;
  rep1(p, 1024) if (is_prime(p)) mods.push_back(p);
  for (int x = 1024; x < PW(24); x *= 2) {
    rep(_, 20) {
      int p = 1;
      while (!is_prime(p)) p = rng(x, 2 * x);
      mods.push_back(p);
    }
  }
  mods.push_back(10007);
  // mods.push_back(100000007);
  // mods.push_back(998244353);
  // mods.push_back(1000000007);
  // mods.push_back(1000000009);

  for (int mod : mods) {
    assert(is_prime(mod));
    mint::set_mod(mod);
    Timer timer;
    Modulo_O1<mint> o1;
    trc2(mod, timer());
    {
      for (int i = 1; i < mod; i++) {
        mint j = o1.inv(i);
        if (j * i != 1) {
          int a = i;
          auto [y, z] = o1.info[a >> 10];
          z += (a & 1023) * y;
          trc2(mod, i, j, j * i, y, z);
          exit(1);
        }
      }
    }
    {
      int proot = o1.proot;
      mint x = 1;
      for (int i = 0; i < mod - 1; i++) {
        int lg = o1.log(x);
        assert(lg == i);
        x *= proot;
      }
    }
    {
      rep(_, mod < 1024 ? TEN(5) : mod < PW(24) ? TEN(6) : TEN(7)) {
        mint a = rng(0, 9) ? 0 : rng(0, mod - 1);
        ll e = rng(0, 9) ? 0 : rng(1, 4 * TEN(18));
        if (o1.pow(a, e) != a.pow(e)) {
          trc2(mod, a, e, o1.pow(a, e), a.pow(e));
          exit(1);
        }
      }
    }
  }
  trc2("OK");
}

void q() { 
  test();
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../atcoder/internal_math.hpp"
#include "../../misc/rng.hpp"
#include "../../modint/arbitrary-modint.hpp"
using namespace Nyaan;

void test(int mod, int testcases) {
  assert(0 < mod and mod <= (1 << 30) - 1);
  using mint = ArbitraryModInt;
  mint::set_mod(mod);

  rep(t, testcases) {
    int a = randint(0, mod);
    if (rng() % 10 == 0) a = (mod - 1) % mod;
    if (rng() % 10 == 0) a = 0;
    mint A = a;
    assert(A.get() == a);

    int b = randint(0, mod);
    if (rng() % 10 == 0) b = (mod - 1) % mod;
    if (rng() % 10 == 0) b = 0;
    mint B = b;
    assert(B.get() == b);

    int c = (a + b) % mod;
    mint C = A + B;
    assert(C.get() == c);

    int d = (a + mod - b) % mod;
    mint D = A - B;
    assert(D.get() == d);

    int e = (1LL * a * b) % mod;
    mint E = A * B;
    assert(E.get() == e);

    // 逆元 : f * g = 1
    int f, g = -1;
    do {
      f = randint(0, mod);
      auto [gc, invf] = atcoder::internal::inv_gcd(f, mod);
      g = invf;
    } while (1LL * f * g % mod != 1LL % mod);
    mint F = f;
    mint G = F.inverse();
    assert(F.get() == f);
    assert(G.get() == g);
    assert(F * G == 1);

    int h = 1LL * e * g % mod;
    mint H = E / F;
    assert(H.get() == h);

    int i = randint(0, mod);
    if (rng() % 10 == 0) i = (mod - 1) % mod;
    if (rng() % 10 == 0) i = 0;
    long long ex = randint(0, TEN(18));
    if (rng() % 10 == 0) ex = randint(0, 2);
    int j = 1 % mod;
    {
      int i2 = i;
      long long e2 = ex;
      while (e2) {
        if (e2 & 1) j = 1LL * j * i2 % mod;
        i2 = 1LL * i2 * i2 % mod;
        e2 >>= 1;
      }
    }
    mint I = i;
    mint J = I.pow(ex);
    assert(I.get() == i);
    assert(J.get() == j);

    int k = (mod - a) % mod;
    mint K = -A;
    assert(K.get() == k);
  }
}

void Nyaan::solve() {
  int mod_max = (1LL << 30) - 1;
  // 小さい方
  rep1(m, 10) test(m, 10000);
  test(998244353, 10000);
  test(1000000007, 10000);
  rep(t, 10) test(mod_max - t, 10000);
  rep(t, 1000) {
    int mod = randint(1, mod_max + 1);
    test(mod, 1000);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

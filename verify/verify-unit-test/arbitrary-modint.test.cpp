#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../atcoder/internal_math.hpp"
#include "../../misc/rng.hpp"
#include "../../modint/arbitrary-modint.hpp"
#include "../../modint/arbitrary-montgomery-modint.hpp"
using namespace Nyaan;

template <typename mint>
void test(int mod, int testcases) {
  assert(0 < mod and mod <= (1 << 30) - 1);
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

void test_wrapper(int mod, int testcases) {
  using mint1 = ArbitraryModInt;
  using mint2 = ArbitraryLazyMontgomeryModInt<96229631>;

  test<mint1>(mod, testcases);
  if (mod % 2 == 1) test<mint2>(mod, testcases);
}

void test_all() {
  {
    using mint3 = ArbitraryModIntBase<0>;
    using mint5 = ArbitraryModIntBase<1>;
    mint3::set_mod(3);
    mint5::set_mod(5);
    assert(mint3::get_mod() == 3);
    assert(mint5::get_mod() == 5);
  }

  {
    using mint3 = ArbitraryLazyMontgomeryModInt<0>;
    using mint5 = ArbitraryLazyMontgomeryModInt<1>;
    mint3::set_mod(3);
    mint5::set_mod(5);
    assert(mint3::get_mod() == 3);
    assert(mint5::get_mod() == 5);
  }

  int mod_max = (1LL << 30) - 1;
  rep1(m, 10) test_wrapper(m, 10000);
  test_wrapper(998244353, 10000);
  test_wrapper(1000000007, 10000);
  rep(t, 10) { test_wrapper(mod_max - t, 10000); }
  rep(t, 1000) {
    int mod = randint(1, mod_max + 1);
    test_wrapper(mod, 1000);
  }
  cerr << "OK" << endl;
}

void Nyaan::solve() {
  test_all();
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

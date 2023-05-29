#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../atcoder/internal_math.hpp"
#include "../../misc/rng.hpp"
//
#include "../../modint/modint.hpp"
#include "../../modint/montgomery-modint.hpp"
using namespace Nyaan;

template <typename mint>
void test(int testcases) {
  int mod = mint::get_mod();
  assert(0 < mod and mod <= (1 << 30) - 1);

  rep(t, testcases) {
    int a = randint(0, mod);
    if (rng() % 10 == 0) a = (mod - 1) % mod;
    if (rng() % 10 == 0) a = 0;
    mint A = a;
    assert(int(A.get()) == a);

    int b = randint(0, mod);
    if (rng() % 10 == 0) b = (mod - 1) % mod;
    if (rng() % 10 == 0) b = 0;
    mint B = b;
    assert(int(B.get()) == b);

    int c = (a + b) % mod;
    mint C = A + B;
    assert(int(C.get()) == c);

    int d = (a + mod - b) % mod;
    mint D = A - B;
    assert(int(D.get()) == d);

    int e = (1LL * a * b) % mod;
    mint E = A * B;
    assert(int(E.get()) == e);

    // 逆元 : f * g = 1
    int f, g = -1;
    do {
      f = randint(0, mod);
      auto [gc, invf] = atcoder::internal::inv_gcd(f, mod);
      g = invf;
    } while (1LL * f * g % mod != 1LL % mod);
    mint F = f;
    mint G = F.inverse();
    assert(int(F.get()) == f);
    assert(int(G.get()) == g);
    assert(F * G == 1);

    int h = 1LL * e * g % mod;
    mint H = E / F;
    assert(int(H.get()) == h);

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
    assert(int(I.get()) == i);
    assert(int(J.get()) == j);

    // 単項 +, -
    int k = (mod - a) % mod;
    mint K = -A;
    assert(int(K.get()) == k);
    assert(A == +A);
  }
}

template <int mod>
void test_wrapper(int testcases = 10000) {
  if (mod <= 0) return;
  static_assert(mod < (1LL << 30));
  test<ModInt<mod>>(testcases);
  if constexpr (mod % 2 == 1) {
    test<LazyMontgomeryModInt<mod>>(testcases);
  }
}

void Nyaan::solve() {
  constexpr int mod_max = (1LL << 30) - 1;

  test_wrapper<998244353>(1e6);
  test_wrapper<1000000007>(1e6);
  test_wrapper<mod_max - 10000>();

  test_wrapper<1>();
  test_wrapper<2>();
  test_wrapper<3>();
  test_wrapper<4>();
  test_wrapper<5>();
  test_wrapper<6>();
  test_wrapper<7>();
  test_wrapper<8>();
  test_wrapper<9>();
  test_wrapper<10>();
  test_wrapper<11>();
  test_wrapper<101>();
  test_wrapper<1001>();
  test_wrapper<10001>();
  test_wrapper<100001>();
  test_wrapper<1000001>();
  test_wrapper<10000001>();
  test_wrapper<100000001>();

  test_wrapper<454763204>();
  test_wrapper<302343120>();
  test_wrapper<666121844>();
  test_wrapper<180227696>();
  test_wrapper<666012019>();
  test_wrapper<557418622>();
  test_wrapper<728776078>();
  test_wrapper<447813621>();
  test_wrapper<750511963>();
  test_wrapper<726530008>();

  cerr << "OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

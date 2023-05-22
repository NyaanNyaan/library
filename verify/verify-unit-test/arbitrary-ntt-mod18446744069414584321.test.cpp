#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/all.hpp"
#include "../../ntt/arbitrary-ntt-mod18446744069414584321.hpp"
#include "../../ntt/arbitrary-ntt.hpp"
using namespace Nyaan;

void test1() {
  using mint = ModInt18446744069414584321;
  u64 mod = ModInt18446744069414584321::mod;
  auto check = [&](u64 a, u64 b) {
    // add
    assert(a < mod and b < mod);
    mint A{a}, B{b};

    // get
    assert(A.get() == a);
    assert(B.get() == b);

    // operator+
    {
      u64 c = (u128(a) + b) % mod;
      mint C = A + B;
      assert(C.x == c);
    }
    // operator-
    {
      u64 c = (u128(a) - b + mod) % mod;
      mint C = A - B;
      assert(C.x == c);
    }
    // operator*
    {
      u64 c = (u128(a) * b) % mod;
      mint C = A * B;
      assert(C.x == c);
    }
    // operator/, pow, inverse
    if (b != 0) {
      mint C = A / B;
      assert(C.x < mod);
      mint D = C * B;
      if (A != D) trc2(A, B, C, D);
      assert(A == D);
    }
    // 単項 operator-, operator+
    assert(+A == A && +B == B);
    assert(-A + A == 0 && -B + B == 0);
  };

  rep(i, 1000) rep(j, 1000) {
    check(i, j);
    check(mod - 1 - i, j);
    check(i, mod - 1 - j);
    check(mod - 1 - i, mod - 1 - j);
  }
  rep(t, 10000) {
    u64 i = rng() % mod;
    u64 j = rng() % mod;
    check(i, j);
    check(mod - 1 - i, j);
    check(i, mod - 1 - j);
    check(mod - 1 - i, mod - 1 - j);
  }
  rep(t, 1000) {
    u64 i = t;
    rep(u, 100) {
      u64 j = rng() % mod;
      check(i, j);
      check(mod - 1 - i, j);
      check(i, mod - 1 - j);
      check(mod - 1 - i, mod - 1 - j);
    }
  }
  rep(t, 1000) {
    u64 i;
    if (t < 500) {
      i = t + 1;
    } else {
      i = 1LL << rng(10, 20);
      i *= 0.5 + rnd() * 0.5;
    }
    assert(i != 0);
    ll k = mod / i;
    reg(j, max<ll>(0, k - 100), k + 100) {
      check(i, j);
      check(mod - 1 - i, j);
      check(i, mod - 1 - j);
      check(mod - 1 - i, mod - 1 - j);
    }
  }
  rep(t, 200) {
    for (ll i : {257, 65535, 65537}) {
      ll k = mod / i;
      reg(j, max<ll>(0, k - 200), k + 200) {
        check(i, j);
        check(mod - 1 - i, j);
        check(i, mod - 1 - j);
        check(mod - 1 - i, mod - 1 - j);
      }
    }
  }

  rep(t, 100) {
    int N = rng(50, 100);
    int M = rng(50, 100);
    V<mint> a(N), b(M);
    each(x, a) x = rng() % mod;
    each(x, b) x = rng() % mod;
    V<mint> c = ntt18446744069414584321.multiply(a, b);
    V<mint> d(N + M - 1);
    rep(i, N) rep(j, M) d[i + j] += a[i] * b[j];
    rep(i, N + M - 1) assert(c[i] == d[i]);
  }
}

void test2() {
  using mint = ModInt18446744069414584321;
  int N = 500000;
  u64 mod = mint::get_mod();
  assert(mod == mint::mod);

  Timer timer;
  u128 s1 = 0, s2 = 0, t1 = 0, t2 = 0;
  {
    timer.reset();
    V<mint> a(N), b(N);
    rep(i, 10) {
      rep(j, N) a[j] = i + j, b[j] = i + j + 1;
      auto c = ntt18446744069414584321.multiply(a, b);
      for (int j = 0; j < N; j += 1000) s1 += c[j].get();
    }
    t1 = timer.elapsed();
    trc2(s1, t1);
  }
  {
    timer.reset();
    vl a(N), b(N);
    rep(i, 10) {
      rep(j, N) a[j] = i + j, b[j] = i + j + 1;
      auto c = ArbitraryNTT::multiply_u128(a, b);
      for (int j = 0; j < N; j += 1000) s2 += c[j];
    }
    t2 = timer.elapsed();
    trc2(s2, t2);
  }
  assert(s1 == s2);
  double r = 1.0 * t1 / t2;
  trc2("ratio", r);
}

void q() {
  test1();
  cerr << "test1 OK" << endl;
  test2();
  cerr << "test2 OK" << endl;

  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/all.hpp"
//
#include "../../atcoder/modint.hpp"
#include "../../math-fast/inv-o1.hpp"
#include "../../math-fast/inv.hpp"
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;

template <int MOD>
void benchmark() {
  Timer timer;
  constexpr int mod = MOD;
  constexpr fast_modinv<mod> fastinv;
  Inverse_O1<mod> inv_o1;
  using mint = LazyMontgomeryModInt<mod>;

  static_assert(MOD >= 1e7);
  {
    mint ans1 = 0, ans2 = 0, ans3 = 0;
    int M = 1e7;
    constexpr int p = 100007, r = 2;

    timer.reset();
    for (int i = 0, j = 1; i < M; i++, j = j * r % p) {
      ans1 += fastinv(j);
    }
    int t1 = timer.elapsed();

    timer.reset();
    for (int i = 0, j = 1; i < M; i++, j = j * r % p) {
      mint x;
      x.a = mint::reduce(u64(j) * x.n2);
      ans2 += x.inverse();
    }
    int t2 = timer.elapsed();

    timer.reset();
    for (int i = 0, j = 1; i < M; i++, j = j * r % p) {
      ans3 += inv_o1(j);
    }
    int t3 = timer.elapsed();

    assert(ans1 == ans2 && ans2 == ans3);
    trc2("mod =", mod, "small", t1, t2, t3);
    cout.flush();
  }
  {
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    int D = 99;

    timer.reset();
    for (int i = D; i < mod; i += D) ans1 += fastinv(i);
    int t1 = timer.elapsed();

    timer.reset();
    {
      mint j = 0, d = D;
      for (int i = D; i < mod; i += D) {
        ans2 += (j += d).inverse().get();
      }
    }
    int t2 = timer.elapsed();

    timer.reset();
    for (int i = D; i < mod; i += D) ans3 += inv_o1(i);
    int t3 = timer.elapsed();

    assert(ans1 == ans2 && ans2 == ans3);
    trc2("mod =", mod, "large", t1, t2, t3);
    cout.flush();
  }
}

template <int MOD>
void verify() {
  Inverse_O1<MOD> inv;
  for (int x = 1; x < MOD; x++) {
    if (x % TEN(6) == 0) trc2(x);
    int y = inv(x);
    assert(1LL * x * y % MOD == 1);
  }
  trc2(MOD, "OK");
}

void q() {
  benchmark<998244353>();
  // benchmark<1000000007>();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

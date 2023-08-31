#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
#include "../../misc/timer.hpp"
//
#include "../../atcoder/math.hpp"
#include "../../atcoder/modint.hpp"
#include "../../math-fast/inv.hpp"
#include "../../modint/montgomery-modint.hpp"
//

using namespace Nyaan;

template <int MOD>
void test() {
  constexpr int mod = MOD;
  constexpr fast_modinv<mod> fastinv;
  using mint = LazyMontgomeryModInt<mod>;

  constexpr int inv1 = fastinv(1 % mod);
  static_assert(inv1 == 1 % mod);
  constexpr int inv2 = fastinv(2 % mod);
  static_assert(1LL * inv2 * 2 % mod == 1 % mod);
  if constexpr (mod % 3 != 0) {
    constexpr int inv3 = fastinv(3);
    static_assert(1LL * inv3 * 3 % mod == 1 % mod);
  }

  auto check = [&](ll x) {
    assert(1 <= x && x < (1LL << 30));
    if (x >= mod or gcd<int>(x, mod) != 1) return;
    ll af = fastinv(x);
    ll am = mint{x}.inverse().get();
    ll ac = atcoder::inv_mod(x, mod);
    ll prod = x * af % mod;
    if (!(af == am && af == ac && prod == 1 % mod)) {
      trc2(mod, x, af, am, ac, prod);
    }
    assert(af == am && af == ac && prod == 1 % mod);
  };

  rep1(x, TEN(6)) check(x);
  if (mod >= TEN(6)) {
    rep1(t, TEN(6)) check(rng(1, mod - 1));
  }
  trc2("ok", mod);
}

template <int MOD>
void benchmark() {
  Timer timer;
  constexpr int mod = MOD;
  constexpr fast_modinv<mod> fastinv;
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
    atcoder::modint::set_mod(mod);
    for (int i = 0, j = 1; i < M; i++, j = j * r % p) {
      ans3 += atcoder::modint::raw(j).inv().val();
    }
    int t3 = timer.elapsed();

    assert(ans1 == ans2 && ans2 == ans3);
    out("mod =", mod, "small", t1, t2, t3);
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
    atcoder::modint::set_mod(mod);
    for (int i = D; i < mod; i += D) {
      ans3 += atcoder::modint::raw(i).inv().val();
    }
    int t3 = timer.elapsed();

    assert(ans1 == ans2 && ans2 == ans3);
    out("mod =", mod, "large", t1, t2, t3);
    cout.flush();
  }
}

void q() {
  test<1>();
  test<3>();
  test<5>();
  test<7>();
  test<9>();

  test<998244353>();
  test<1000000007>();
  test<1000000009>();

  test<111546435>();
  test<30011 * 30013>();
  test<999999999>();

  // benchmark<998244353>();
  // benchmark<1000000007>();
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

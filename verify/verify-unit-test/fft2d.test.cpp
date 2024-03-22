#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../fps/fft2d.hpp"
#include "../../misc/rng.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
// #include "fps/arbitrary-fps.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;
using namespace Nyaan;

void test() {
  rep(t, 10000) {
    int Ha = rng(0, 20);
    int Hb = rng(0, 20);
    int Wa = rng(0, 20);
    int Wb = rng(0, 20);
    vector<fps> a(Ha, fps(Wa));
    vector<fps> b(Hb, fps(Wb));
    each(v, a) each(x, v) x = rng();

    each(v, b) each(x, v) x = rng();
    auto c1 = multiply2d_naive(a, b);
    auto c2 = multiply2d_partially_naive(a, b);
    auto c3 = multiply2d(a, b);
    assert(c1 == c2);
    assert(c2 == c3);
  }
  trc2("OK1");

  rep(t, 50) {
    int Ha = rng(60, 70);
    int Hb = rng(60, 70);
    int Wa = rng(60, 70);
    int Wb = rng(60, 70);
    vector<fps> a(Ha, fps(Wa));
    vector<fps> b(Hb, fps(Wb));
    each(v, a) each(x, v) x = rng();

    each(v, b) each(x, v) x = rng();
    auto c1 = multiply2d_naive(a, b);
    auto c2 = multiply2d_partially_naive(a, b);
    auto c3 = multiply2d(a, b);
    assert(c1 == c2);
    assert(c2 == c3);
  }
  trc2("OK2");

  rep(t, 200) {
    int Ha = rng(0, 100);
    int Hb = rng(0, 100);
    int Wa = rng(0, 100);
    int Wb = rng(0, 100);
    vector<fps> a(Ha, fps(Wa));
    vector<fps> b(Hb, fps(Wb));
    each(v, a) each(x, v) x = rng();

    each(v, b) each(x, v) x = rng();
    auto c1 = multiply2d_naive(a, b);
    auto c2 = multiply2d_partially_naive(a, b);
    auto c3 = multiply2d(a, b);
    assert(c1 == c2);
    assert(c2 == c3);
  }
  trc2("OK3");
}

void q() {
  test();

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

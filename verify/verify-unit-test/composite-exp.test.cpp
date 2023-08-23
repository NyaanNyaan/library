#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../fps/composite-exp.hpp"
//
#include "../../misc/rng.hpp"
#include "../../misc/timer.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
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
  {
    fps f{1, 1, 1, 1};
    auto g = composite_exp<mint>(f, 2);
    trc(g);
    auto h = inverse_of_composite_exp<mint>(g, 2);
    trc(h);
  }

  rep(t, 50) rep(N, 20) {
    fps f(N);
    each(x, f) x = rng(0, 998244352);
    mint c = t < 10 ? 1 : rng(1, 998244352);
    fps g = composite_exp(f, c);
    fps h = inverse_of_composite_exp(g, c);
    assert(f == h);
  }
  trc2("OK");
  {
    Timer timer;
    int N = 100000;
    fps f(N);
    each(x, f) x = rng(0, 998244352);

    timer.reset();
    fps g = composite_exp(f);
    trc2("exp", timer());

    timer.reset();
    fps h = inverse_of_composite_exp(g);
    trc2("inv", timer());

    assert(f == h);
  }
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

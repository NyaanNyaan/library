#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-composition-old.hpp"
#include "../../fps/fps-composition.hpp"
#include "../../fps/fps-compositional-inverse.hpp"
#include "../../misc/rng.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
// #include "fps/arbitrary-fps.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;
Binomial<mint> C;
using namespace Nyaan;

void q() {
  rep1(N, 200) {
    fps f(N), g(N);
    each(x, f) x = rng();
    each(x, g) x = rng();
    fps h1 = Composition<mint>(f, g, C);
    fps h2 = composition(f, g);
    fps h3;
    {
      fps s{1};
      rep(i, N) h3 += s.pre(N) * g[i], s = (s * f).pre(N);
    }
    assert(h1 == h2 and h2 == h3);

    fps pe = pow_enumerate(f, g);
    rep(i, N) {
      assert(g[N - 1] == pe[i]);
      g = (g * f).pre(N);
    }
  }
  trc2("OK");

  int a, b;
  cin >> a >> b;
  cout << a + b << endl;
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

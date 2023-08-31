#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../fps/sparse-fps.hpp"
//
#include "../../misc/rng.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;
using namespace Nyaan;

void q() {
  const int mod = 998244353;
  rep(N, 30) rep1(deg, 30) {
    // div
    rep1(M, 30) {
      fps f(N), g(M);
      each(x, f) x = rng(0, mod - 1);
      each(x, g) x = rng(0, mod - 1);
      g[0] = rng(1, mod - 1);

      fps s = sparse_div(f, g, deg);
      fps t = (f * g.inv(deg)).pre(deg);
      assert(s == t && "div");
      assert(sz(s) == deg);
    }
    // inv
    if (N) {
      fps f(N);
      each(x, f) x = rng(0, mod - 1);
      f[0] = rng(1, mod - 1);

      fps g = sparse_inv(f, deg);
      fps h = f.inv(deg);
      assert(sz(g) == deg);
      assert(g == h && "inv");
    }

    // log
    if (N) {
      fps f(N);
      each(x, f) x = rng(0, mod - 1);
      f[0] = 1;
      fps g = sparse_log(f, deg);
      fps h = f.log(deg);
      assert(sz(g) == deg);
      assert(g == h && "log");
    }

    // exp
    {
      fps f(N);
      each(x, f) x = rng(0, mod - 1);
      if (N) f[0] = 0;
      fps g = sparse_exp(f, deg);
      fps h = f.exp(deg);
      assert(sz(g) == deg);
      assert(g == h && "exp");
    }

    // pow
    {
      fps f(N);
      each(x, f) x = rng(0, mod - 1);
      rep(i, N) if (rng(0, 1)) f[i] = 0;
      for (ll k : vector<ll>{0, rng(1, TEN(18))}) {
        fps g = sparse_pow(f, k, deg);
        fps h = f.pow(k, deg);
        assert(sz(g) == deg);
        assert(g == h and "pow");
      }
    }
  }

  cerr << "OK" << endl;
  {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

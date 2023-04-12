#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
//
#include "../../ntt/relaxed-convolution.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
// #include "fps/arbitrary-fps.hpp"
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;

using namespace Nyaan;

void q() {
  rep(N, 100) rep(M, 100) {
    fps a(N), b(M);
    each(x, a) x = rng(0, 998244352);
    each(x, b) x = rng(0, 998244352);
    // [0, L) にクエリを投げる
    int ls = max<int>(1, N + M - 1);
    reg(L, ls, ls + 10) {
      RelaxedConvolution<fps> conv(L - 1);
      fps c = a * b;
      c.resize(L);
      rep(i, L) {
        mint s = i < N ? a[i] : 0;
        mint t = i < M ? b[i] : 0;
        mint x = c[i];
        mint y = conv.get(s, t);
        if (x != y) {
          trc(i, s, t, x, y);
        }
        assert(x == y);
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

#define PROBLEM                      \
  "https://judge.yosupo.jp/problem/" \
  "multipoint_evaluation_on_geometric_sequence"
//
#include "../../template/template.hpp"
//
#include "../../misc/rng.hpp"
//
#include "../../ntt/chirp-z.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
// #include "fps/arbitrary-fps.hpp"
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;

void test() {
  rep(N, 50) rep(fdeg, 50) rep(W, 3) rep(A, 3) {
    fps f(fdeg);
    each(x, f) x = rng(0, 998244352);
    fps ys1 = ChirpZ(f, W, N, A);
    fps ys2(N);
    rep(i, N) ys2[i] = f.eval(mint{W}.pow(i) * A);
    if (ys1 != ys2) {
      trc(N, fdeg, W, A);
      trc(f);
      trc(ys1);
      trc(ys2);
    }
    assert(ys1 == ys2);
  }
  cerr << "OK" << endl;
}

void q() {
  test();
  int N, M, A, R, x;
  in(N, M, A, R);
  fps c(N);
  rep(i, N) in(x), c[i] = x;
  auto ps = ChirpZ(c, R, M, A);
  out(ps);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

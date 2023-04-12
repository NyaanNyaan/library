#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
//
#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
//
#include "../../ntt/relaxed-convolution.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
// #include "fps/arbitrary-fps.hpp"
using namespace Nyaan;
using fps = FormalPowerSeries<LazyMontgomeryModInt<998244353>>;

using namespace Nyaan;

void q() {
  int N, M, x;
  rd(N, M);
  fps a(N), b(M);
  rep(i, N) rd(x), a[i] = x;
  rep(i, M) rd(x), b[i] = x;

  RelaxedConvolution<fps> conv(N + M - 2);
  a.resize(N + M - 1), b.resize(N + M - 1);
  rep(i, N + M - 1) {
    wt(conv.get(a[i], b[i]).get());
    wt(' ');
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

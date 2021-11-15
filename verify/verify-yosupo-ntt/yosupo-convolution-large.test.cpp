#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_large"

#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
#include "../../ntt/convolution-large.hpp"

using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;

void Nyaan::solve() {
  int N, M, buf;
  rd(N, M);
  fps a(N), b(M);
  for (auto &x : a) x = (rd(buf), buf);
  for (auto &x : b) x = (rd(buf), buf);
  auto c = convolution_large(a, b);
  rep(i, sz(c)) {
    wt(c[i].get());
    wt(" \n"[i == sz(c) - 1]);
  }
}
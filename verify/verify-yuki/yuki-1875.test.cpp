#define PROBLEM "https://yukicoder.me/problems/no/1875"
//
#include "../../template/template.hpp"
//
#include "../../fps/composite-exp.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
#include "../../fps/fps-fraction.hpp"
#include "../../fps/taylor-shift.hpp"
// #include "fps/arbitrary-fps.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;
using frac = fps_fraction<fps>;
using namespace Nyaan;

void q() {
  inl(N, M);
  vl a(N), b(N), c(N);
  in3(a, b, c);
  V<frac> fs;
  rep(i, N) {
    mint t = mint{a[i]}.inverse() * b[i];
    fs.emplace_back(fps{t * c[i]}, fps{1, t});
  }
  while (sz(fs) > 1) {
    V<frac> nx;
    for (int i = 0; i + 1 < sz(fs); i += 2) nx.push_back(fs[i] + fs[i + 1]);
    if (sz(fs) % 2) nx.push_back(fs.back());
    fs = nx;
  }
  fps f = (fs[0].p * fs[0].q.inv(M + 10)).integral().exp(M + 1);
  mint prod = 1;
  rep(i, N) prod *= mint{a[i]}.pow(c[i]);
  f *= prod;
  f = TaylorShift<mint>(f, -1, C);
  auto g = composite_exp(f);
  rep1(i, M) out(g[i] * C.fac(i));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

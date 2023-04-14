#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
//
#include "../../template/template.hpp"
//
#include "../../fps/newton-method.hpp"
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

void q() {
  inl(N);
  fps f(N);
  in(f);
  auto ans = newton_method<fps>(
      [&](fps g, int deg) {
        fps s = f * g - fps{1};
        fps t = f;
        s.resize(deg);
        t.resize(deg);
        return make_pair(s, t);
      },
      f[0].inverse(), N);
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

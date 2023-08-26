#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-utility.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;
using namespace Nyaan;

void q() {
  inl(N);
  V<fps> fs;
  rep(i, N) {
    ini(d);
    fps f(d + 1);
    in(f);
    fs.push_back(f);
    trc(f);
  }
  out(Pi(fs));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

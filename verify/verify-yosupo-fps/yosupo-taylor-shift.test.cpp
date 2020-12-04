#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "../../template/template.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
#include "../../fps/taylor-shift.hpp"

constexpr int MOD9 = 998244353;
constexpr int MOD1 = 1000000007;
using mint = LazyMontgomeryModInt<MOD9>;
Binomial<mint> C(530000);
using fps = FormalPowerSeries<mint>;

using namespace Nyaan; void Nyaan::solve() {
  int N, c;
  rd(N);
  rd(c);
  fps f(N);
  rep(i, N) {
    int buf;
    rd(buf);
    f[i] = buf;
  }
  fps g = TaylorShift(f, mint(c), C);
  rep(i,N){
    if(i)wt(' ');
    wt(g[i].get());
  }
  wt('\n');
}
#define PROBLEM "https://yukicoder.me/problems/no/1939"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-compositional-inverse.hpp"
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
  inl(N, M);
  vl L(M);
  in(L);

  // (verify 用 に書いたが) NM がデカいと TLE するので場合分け
  if (N * M <= 7e5) {
    // F(x) = x(1 + sum_{n in L} F^n)
    // <-> F(x) / (1 + sum_{n in L} F^n) = x
    // G(x) = x / (1 + sum_{n in L}x^n)
    // とすると G(F(x)) = x
    auto gf = [&](fps f, int deg) -> fps {
      fps num{1};
      each(n, L) num += f.pow(n, deg);
      return (num.inv(deg) * f).pre(deg);
    };
    auto f = compositional_inverse<fps>(gf, N + 2);
    out(f[N + 1]);
  } else {
    fps g(N + 2);
    g[0] = 1;
    each(n, L) g[n] = 1;
    out(g.pow(N + 1)[N] / (N + 1));
  }
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

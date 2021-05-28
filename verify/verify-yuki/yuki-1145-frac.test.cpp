#define PROBLEM "https://yukicoder.me/problems/no/1145"
//
#include "../../template/template.hpp"
//
#include "../../fps/fps-fraction.hpp"
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"

using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;
Binomial<mint> C;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;

using frac = fps_fraction<fps>;

void test() {
  frac f(fps{2, 1}, fps{3, 1});
  frac g(fps{5, 1}, fps{4, 1});

  {
    auto h = f + g;
    h.shrink();
    assert((h.p == fps{23, 14, 2}));
    assert((h.q == fps{12, 7, 1}));
  }

  {
    auto h = f - g;
    h.shrink();
    assert((h.p == fps{-7, -2}));
    assert((h.q == fps{12, 7, 1}));
  }

  {
    auto h = f * g;
    h.shrink();
    assert((h.p == fps{10, 7, 1}));
    assert((h.q == fps{12, 7, 1}));
  }

  {
    auto h = f / g;
    h.shrink();
    assert((h.p == fps{8, 6, 1}));
    assert((h.q == fps{15, 8, 1}));
  }
}
void Nyaan::solve() {
  ini(N, M);
  vi a(N);
  in(a);

  test();

  V<frac> v(N);
  rep(i, N) v[i] = frac{fps{1}, fps{1, -a[i]}};

  auto dd = [&](auto rc, int l, int r) -> frac {
    if (l + 1 == r) return v[l];
    int m = (l + r) / 2;
    auto L = rc(rc, l, m);
    auto R = rc(rc, m, r);
    return L + R;
  };

  auto fr = dd(dd, 0, N);
  fr.p.resize(M + 1);
  auto f = fr.p * fr.q.inv(M + 1);
  out(fps{begin(f) + 1, begin(f) + M + 1});
}
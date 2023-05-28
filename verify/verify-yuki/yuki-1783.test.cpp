#define PROBLEM "https://yukicoder.me/problems/no/1783"
//
#include "../../template/template.hpp"
//
#include "../../fps/multivariate-fps.hpp"
//
#include "../../ntt/multidimensional-ntt.hpp"
//
#include "../../math/primitive-root.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;

constexpr unsigned _mod = 120586241;
using mint = LazyMontgomeryModInt<_mod>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;
using fps = FormalPowerSeries<mint>;
using mfps = MultivariateFormalPowerSeries<mint>;
using namespace Nyaan;

void q() {
  int pr = PrimitiveRoot(_mod);
  vm pr10(110);
  pr10[0] = 1;
  pr10[1] = mint(pr).pow((_mod - 1) / 10);
  rep1(i, 102) pr10[i + 1] = pr10[i] * pr10[1];

  auto dft = [&](vector<mint>& f, bool rev) {
    int n = sz(f);
    vector<mint> F(n);
    rep(i, n) rep(j, n) F[j] += f[i] * pr10[i * j];
    if (rev) reverse(begin(F) + 1, end(F));
    f.swap(F);
  };

  long long n, k, m, t;
  cin >> n >> k >> m >> t;
  vector<int> a(n);
  each(x, a) {
    cin >> x;
    assert(0 <= x and x < TEN(k));
  }

  vector<int> base(k, 10);
  vector<mint> f(TEN(k));
  each(x, a) f[x] += 1;
  MultidimensionalFourierTransform<mint> mntt(base, dft);

  for (int i = k - 1; i >= t; i--) mntt.inner(f, i);
  for (int i = 0, di = TEN(t); i < TEN(k); i += di) {
    mfps g{{begin(f) + i, begin(f) + i + di}, vi(t, 10)};
    g = g.pow(m);
    for (int j = 0; j < di; j++) f[i + j] = g.f[j];
  }
  for (int i = t; i < k; i++) mntt.inner(f, i, true);
  mint coe = mint(10).inverse().pow(k - t);
  each(x, f) cout << x * coe << "\n";
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

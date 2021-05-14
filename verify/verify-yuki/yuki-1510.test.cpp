#define PROBLEM "https://yukicoder.me/problems/no/1510"
//
#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../fps/partial-fraction-decomposition.hpp"
#include "../../modint/montgomery-modint.hpp"

using namespace Nyaan;

using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
using fps = FormalPowerSeries<mint>;

void Nyaan::solve() {
  int N;
  in(N);
  vi a(N);
  for (auto& x : a) in(x);
  map<int, int> mp;
  each(x, a) mp[1LL * x * x % 998244353] = x;

  map<int, int> cnt;
  each(x, a) cnt[x]++;

  V<pair<mint, int>> denom;
  each2(m, d, cnt) { denom.emplace_back(mint(m) * m, d); }

  auto part = PartialFractionDecomposition<mint>(fps{1}, denom);

  vm co(210);
  co[0] = 1;
  for (int i = 1; i <= 202; i++) {
    co[i] = co[i - 1] * (i * 2 - 1) / (i * 2);
  }

  mint ans = 0;
  each2(m, coeff, part) {
    ll A = mp[m.get()];
    for (int d = 1; d <= sz(coeff); d++) {
      ans += coeff[d - 1] * co[d - 1] / (mint(A).pow(2 * d - 1));
    }
  }

  out(ans.get());
}

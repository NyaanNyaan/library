#define PROBLEM "https://yukicoder.me/problems/no/1504"
//
#include "../../template/template.hpp"
//
#include "../../fps/ntt-friendly-fps.hpp"
#include "../../modint/montgomery-modint.hpp"
//
#include "../../fps/dual-fps.hpp"
#include "../../fps/taylor-shift.hpp"
#include "../../modulo/binomial.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using fps = FormalPowerSeries<mint>;
using dual = DualFPS<fps>;

using namespace Nyaan;

void Nyaan::solve() {
  ini(N);
  ins(S);
  Binomial<mint> C;
  vector<dual> dans(22);

  auto dd = [&](auto rc, int l, int r) -> pair<dual, dual> {
    if (l + 1 == r) {
      if (S[l] == 'i') {
        return mkp(dual{fps{1}}, dual{});
      } else {
        return mkp(dual{}, dual{fps{1}});
      }
    }
    int m = (l + r) / 2;
    if ((r - l) > 262144) m = 262144;
    auto L = rc(rc, l, m);
    auto R = rc(rc, m, r);
    auto LfRs = L.fi * R.se;
    int idx = LfRs.f.size() ? __builtin_ctz(LfRs.f.size()) + 1 : 0;
    dans[idx] += LfRs;
    auto f = L.first << (r - m);
    auto g = R.second << (m - l);
    f += R.first;
    g += L.second;
    return mkp(f, g);
  };
  dd(dd, 0, N);
  
  fps ans;
  rep(i, 22) ans += dans[i].get();
  ans.shrink();
  fps Ans = TaylorShift<mint>(ans, 1, C);

  ll bns = 0;
  each(x, Ans) bns ^= x.get();
  out(bns);
}

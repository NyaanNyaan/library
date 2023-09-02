#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"
//
#include "../../math/rational-binomial.hpp"
#include "../../math/rational-fps.hpp"
#include "../../math/rational.hpp"
//
#include "../../math/bigint-rational.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
using mint = LazyMontgomeryModInt<998244353>;
//
#include "../../misc/rng.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  {
    BigRational a{4, 3}, b{2, 3};
    assert(a + b == 2);
    assert(a - b == BigRational(2, 3));
    assert(a * b == BigRational(8, 9));
    assert(a / b == 2);
    assert(a.inverse() == BigRational(3, 4));
    assert(a.pow(3) == BigRational(64, 27));

    assert((a > b) == true);
    assert((a >= b) == true);
    assert((a < b) == false);
    assert((a <= b) == false);
  }

  {
    Binomial_rational<BigRational> C;
    assert(C.fac(3) == 6);
    assert(C.finv(3) == BigRational(1, 6));
    assert(C(4, 2) == 6);
    assert(C(vi{3, 2}) == 10);
  }

  {
    using fps = FormalPowerSeries_rational<BigRational>;
    {
      fps f{1, 2, {3, 2}}, g{{1, 4}, 5};
      fps h{{5, 4}, 7, {3, 2}};
      assert(f + g == h);
      h = fps{{3, 4}, -3, {3, 2}};
      assert(f - g == h);
      assert(f * g % g == fps{});
      assert(f * g % f == fps{});
    }

    {
      fps e{1, 1, {1, 2}, {1, 6}, {1, 24}, {1, 120}};
      fps f = e.pow(TEN(10));
      trc(f);
      rep(i, sz(e)) { assert(e[i] * BigRational{TEN(10)}.pow(i) == f[i]); }
    }
  }

  // mint と挙動の比較
  {
    auto comp = [&](int i, int j, int k, int l) {
      rep(b, 16) {
        int ii = (b >> 0) % 2 ? -i : +i;
        int jj = (b >> 1) % 2 ? -j : +j;
        int kk = (b >> 2) % 2 ? -k : +k;
        int ll = (b >> 3) % 2 ? -l : +l;
        BigRational x{ii, jj}, y{kk, ll};
        mint X = mint{ii} / jj;
        mint Y = mint{kk} / ll;
        assert(X + Y == (x + y).to_mint(998244353).to_ll());
        assert(X - Y == (x - y).to_mint(998244353).to_ll());
        assert(X * Y == (x * y).to_mint(998244353).to_ll());
        if (Y != 0) {
          assert(X / Y == (x / y).to_mint(998244353).to_ll());
        }
      }
    };
    rep(i, 10) rep1(j, 10) rep(k, 10) rep1(l, 10) comp(i, j, k, l);
    rep(t, 1000) {
      ll lower = t % 2 ? 1 : TEN(17);
      ll i = rng(lower, TEN(18));
      ll j = rng(lower, TEN(18));
      ll k = rng(lower, TEN(18));
      ll l = rng(lower, TEN(18));
      comp(i, j, k, l);
    }
  }

  // binom, mint と挙動の比較
  {
    Binomial_rational<BigRational> C1;
    Binomial<mint> C2;
    reg(i, -15, 15) {
      assert(C2.fac(i) == C1.fac(i).to_mint(998244353).to_ll());
      assert(C2.finv(i) == C1.finv(i).to_mint(998244353).to_ll());
      assert(C2.inv(i) == C1.inv(i).to_mint(998244353).to_ll());
      reg(j, -15, 15) assert(C2(i, j) == C1(i, j).to_mint(998244353).to_ll());
    }
  }

  cerr << "OK" << endl;
  {
    int s, t;
    cin >> s >> t;
    cout << s + t << "\n";
  }
}

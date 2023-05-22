#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../template/template.hpp"

//
#include "../../math/rational.hpp"
#include "../../misc/rng.hpp"
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;

namespace mint_binom {

#include "../../modulo/binomial.hpp"

}

using namespace Nyaan;

void Nyaan::solve() {
  Rational a{4, 3}, b{2, 3};

  trc(a + b);
  assert(a + b == 2);
  trc(a - b);
  assert(a - b == Rational(2, 3));
  trc(a * b);
  assert(a * b == Rational(8, 9));
  trc(a / b);
  assert(a / b == 2);
  trc(a.inverse());
  assert(a.inverse() == Rational(3, 4));
  trc(a.pow(3));
  assert(a.pow(3) == Rational(64, 27));

  trc(a > b);
  assert(a > b == true);
  trc(a >= b);
  assert(a >= b == true);
  trc(a < b);
  assert(a < b == false);
  trc(a <= b);
  assert(a <= b == false);

  Binomial<Rational> C;
  assert(C.fac(3) == 6);
  assert(C.finv(3) == Rational(1, 6));
  assert(C(4, 2) == 6);
  assert(C(vi{3, 2}) == 10);

  auto comp = [&](int i, int j, int k, int l) {
    rep(b, 16) {
      int ii = (b >> 0) % 2 ? -i : +i;
      int jj = (b >> 1) % 2 ? -j : +j;
      int kk = (b >> 2) % 2 ? -k : +k;
      int ll = (b >> 3) % 2 ? -l : +l;
      Rational x{ii, jj}, y{kk, ll};
      mint X = mint{ii} / jj;
      mint Y = mint{kk} / ll;
      assert(X + Y == (x + y).to_mint(998244353));
      assert(X - Y == (x - y).to_mint(998244353));
      assert(X * Y == (x * y).to_mint(998244353));
      if (Y != 0) {
        assert(X / Y == (x / y).to_mint(998244353));
      }
    }
  };
  rep(i, 20) rep1(j, 20) rep(k, 20) rep1(l, 20) comp(i, j, k, l);
  rep(t, 10000) {
    int lower = t % 2 ? 1 : 32000;
    ll i = rng(lower, 35000);
    ll j = rng(lower, 35000);
    ll k = rng(lower, 35000);
    ll l = rng(lower, 35000);
    comp(i, j, k, l);
  }

  Binomial<Rational> C1;
  mint_binom::Binomial<mint> C2;
  reg(i, -15, 15) {
    assert(C2.fac(i) == C1.fac(i).to_mint(998244353));
    assert(C2.finv(i) == C1.finv(i).to_mint(998244353));
    assert(C2.inv(i) == C1.inv(i).to_mint(998244353));
    reg(j, -15, 15) assert(C2(i, j) == C1(i, j).to_mint(998244353));
  }
  cerr << "OK" << endl;
  {
    int s, t;
    cin >> s >> t;
    cout << s + t << "\n";
  }
}

#define PROBLEM "https://yukicoder.me/problems/no/896"
//
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;

#include "../../multiplicative-function/divisor-multiple-transform.hpp"
//
#include "../../template/template.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  inl(M, N, mulx, addx, muly, addy, MOD);
  vl count(MOD + 1);
  {
    ll X, Y;
    {
      vl x(M);
      in(x);
      vl y(M);
      in(y);
      rep(i, M) count[x[i]] += y[i];
      X = x[M - 1], Y = y[M - 1];
    }
    for (int i = M; i < N; i++) {
      X = (X * mulx + addx) % MOD;
      Y = (Y * muly + addy) % MOD;
      count[X] += Y;
    }
  }

  { 
    auto ol = count;
    multiple_transform::zeta_transform(count);
    auto nw = count;
    multiple_transform::mobius_transform(nw);
    assert(ol == nw);
  }
  
  {
    ll X, Y;
    ll ans = 0;
    {
      vl x(M);
      in(x);
      vl y(M);
      in(y);
      rep(i, M) {
        X = x[i], Y = y[i];
        ll cur = count[X];
        if (X * Y <= MOD) cur -= count[X * Y];
        out(cur);
        ans ^= cur;
      }
      X = x[M - 1], Y = y[M - 1];
    }
    for (int i = M; i < N; i++) {
      X = (X * mulx + addx + MOD - 1) % MOD + 1;
      Y = (Y * muly + addy + MOD - 1) % MOD + 1;
      ll cur = count[X];
      if (X * Y <= ll(MOD)) cur -= count[X * Y];
      ans ^= cur;
    }
    out(ans);
  }
}

#define PROBLEM "https://yukicoder.me/problems/no/2883"
//
#include "../../template/template.hpp"
//
#include "../../modint/adjunction-modint.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;

using namespace Nyaan;

void q() {
  inl(N, K);
  using A = Adjunction<mint, 5>;
  A a{C.inv(2), +C.inv(2)};
  A b{C.inv(2), -C.inv(2)};
  A ans = 0;
  rep(i, K + 1) {
    A cur = 1;
    cur *= C(K, i) * mint{-1}.pow(i);
    A c = a.pow(K - i) * b.pow(i);
    if (c == A{1, 0}) {
      cur *= c * N;
    } else {
      cur *= c * (c.pow(N) - 1) / (c - 1);
    }
    ans += cur;
  }
  ans *= A{0, 1}.inverse().pow(K);
  out(ans.a);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

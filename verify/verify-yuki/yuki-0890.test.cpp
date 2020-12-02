#define PROBLEM "https://yukicoder.me/problems/no/890"
//
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
#include "../../modulo/binomial.hpp"
Binomial<mint> C;

#include "../../multiplicative-function/divisor-multiple-transform.hpp"
//
#include "../../template/template.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  ini(N, K);

  vi ds;
  rep1(i, N) if (N % i == 0) ds.push_back(i);

  mint ans1, ans2;
  {
    vm a(N + 1);
    each(i, ds) {
      // i個周期 -> N/i個の区間が存在する
      if (K % (N / i) == 0)
        a[i] = C.C(i, K / (N / i));
      else
        a[i] = 0;
    }

    auto ol = a;
    divisor_transform::mobius_transform(a);
    auto nw = a;
    divisor_transform::zeta_transform(nw);
    assert(ol == nw);
    ans1 = C.C(N, K) - a[N];
  }
  {
    map<ll, mint> a;
    each(i, ds) {
      if (K % (N / i) == 0)
        a[i] = C.C(i, K / (N / i));
      else
        a[i] = 0;
    }
    auto ol = a;
    divisor_transform::mobius_transform(a);
    auto nw = a;
    divisor_transform::zeta_transform(nw);
    assert(ol == nw);
    ans2 = C.C(N, K) - a[N];
  }

  if (ans1 != ans2) exit(1);
  out(ans1);
}

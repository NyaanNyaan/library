#define PROBLEM "https://yukicoder.me/problems/no/125"
//
#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
#include "../../modulo/binomial.hpp"
Binomial<mint> C;

#include "../../multiplicative-function/divisor-multiple-transform.hpp"
//

using namespace Nyaan;

void Nyaan::solve() {
  ini(K);
  vi c(K);
  in(c);
  int S = accumulate(all(c), 0LL);

  vi ds;
  for (long long i = 1; i * i <= S; i++) {
    if (S % i == 0) {
      ds.push_back(i);
      if (i * i != S) ds.push_back(S / i);
    }
  }
  sort(all(ds));

  int g = 0;
  each(cc, c) g = __gcd(g, cc);

  mint ans1, ans2;
  {
    vm a(S + 1);
    each(d, ds) {
      int sd = S / d;
      if (g % sd != 0) {
        a[d] = 0;
        continue;
      }
      mint n = 1;
      each(cc, c) n *= C.finv(cc / sd);
      n *= C.fac(d);
      a[d] = n;
    }

    auto b = a;

    divisor_transform::mobius_transform(a);
    each(d, ds) ans1 += a[d] * C.inv(d);

    divisor_transform::zeta_transform(a);
    assert(a == b);
  }

  {
    map<ll, mint> a;
    each(d, ds) {
      int sd = S / d;
      if (g % sd != 0) {
        a[d] = 0;
        continue;
      }
      mint n = 1;
      each(cc, c) n *= C.finv(cc / sd);
      n *= C.fac(d);
      a[d] = n;
    }

    auto b = a;

    divisor_transform::mobius_transform(a);
    each(d, ds) ans2 += a[d] * C.inv(d);

    divisor_transform::zeta_transform(a);
    assert(a == b);
  }

  assert(ans1 == ans2);
  out(ans1);
}

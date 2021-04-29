
#include "../../template/template.hpp"
//
#include "../../modulo/arbitrary-mod-binomial-large.hpp"
//
#include "../../misc/fastio.hpp"

using namespace Nyaan;

void Nyaan::solve() {
  int T, m;
  rd(T, m);
  arbitrary_mod_binomial C(m);
  while (T--) {
    unsigned long long n, k;
    rd(n, k);
    auto ans = C.C(n, k);
    wtn(ans);
  }
}

/*
#include "misc/rng.hpp"
#include "misc/timer.hpp"
using mint = LazyMontgomeryModInt<998244353>;
void verify() {
  Timer timer;
  simd_prime_binomial C(998244353);
  cerr << "time:" << timer.elapsed() << endl;
  mint f = 1, a = 1, one = 1;
  for (int i = 1; i < 998244353; i++) {
    f *= a;
    a += one;
    if (rng() % (1u << 16) == 0) {
      mint f2 = C.fac(i);
      if (f != f2) exit(1);
    }
  }
  out("OK");
  cout.flush();
  exit(0);
}
*/

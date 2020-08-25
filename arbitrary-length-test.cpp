#include "competitive-template.hpp"
#include "misc/fastio.hpp"
#include "ntt/cooley-turkey-ntt.hpp"

#include "modint/arbitrary-modint.hpp"
#include "misc/timer.hpp"

void solve() {
  using mint = ArbitraryModInt;
  Timer timer;
  int p;
  rd(p);
  if (p == 2) {
    int a, b;
    rd(a, b);
    wt(a, ' ', (a - b + p) % p, '\n');
    return;
  }

  mint::set_mod(p);
  V<mint> a(p);
  for (int i = 0; i < p; i++) {
    int n;
    rd(n);
    a[i] = n;
  }
  ArbitraryLengthNTT<mint> ntt;

  V<mint> b(p - 1);
  for (int m = 0; m < p - 1; m++) b[m] = a[ntt.w[p - 1 - m].get()];
  ntt.ntt(b);

  for (auto &x : b) x = -x;
  b.pb(b[0]);
  b[p - 1] = (b[p - 1] + p - (b[0] = a[0]));
  for (int i = 0; i < p; i++) wt(b[i].get(), " \n"[i == p - 1]);
  cerr << timer.elapsed() << endl;
}
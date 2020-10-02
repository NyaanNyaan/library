#define PROBLEM "https://yukicoder.me/problems/no/117"

#include "../../competitive-template.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
using mint = LazyMontgomeryModInt<1000000007>;

void solve() {
  Binomial<mint> C;
  int Q;
  scanf("%d\n", &Q);
  while (Q--) {
    int N, K;
    char c = '!';
    scanf("%c(%d,%d)\n", &c, &N, &K);
    trc(c, N, K);
    if (c == 'C') out(C.C(N, K));
    if (c == 'P') out(C.P(N, K));
    if (c == 'H') out(C.H(N, K));
  }
}
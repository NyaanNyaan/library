#define PROBLEM "https://yukicoder.me/problems/no/1220"

#include "../../competitive-template.hpp"
#include "../../math/float-binomial.hpp"

void solve() {
  FloatBinomial C(200200);
  ini(Q);
  rep(_, Q) {
    ini(n, m, k);
    long double f, s;
    f = logl(m) + C.logC(n, k);
    s = logl(n - k + 1) + logl(m) * k;
    out(f > s ? "Straight" : "Flush");
  }
}
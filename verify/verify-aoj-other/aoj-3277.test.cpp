#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3277"

#include "../../template/template.hpp"
//
#include "../../math/sweep.hpp"
//
using namespace Nyaan;

void q() {
  inl(N);
  vl S(N);
  in(S);
  vvl A(N);
  rep(i, N) {
    A[i].resize(S[i]);
    in(A[i]);
  }
  constexpr int MAX = 60;
  using Ba = Basis<ll, MAX>;
  V<Ba> ot(PW(N));
  u64 ans = 0;
  rep1(i, PW(N) - 1) {
    int t = msb(i);
    if (PW(t) == i) {
      ot[i] = Ba{Ba{A[t]}.orthogonal_complement()};
    } else {
      (ot[i] = ot[i - PW(t)]).merge(ot[PW(t)]);
    }
    trc(i, ot[i], sz(ot[i]));
    ans += (1LL << (MAX - sz(ot[i]))) * (popcnt(i) % 2 ? 1 : -1);
  }
  out(ans);
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}

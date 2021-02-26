#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../template/template.hpp"
//
#include "../../modint/montgomery-modint.hpp"
#include "../../ntt/arbitrary-ntt.hpp"
#include "../../ntt/chirp-z.hpp"

void Nyaan::solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  ini(N, M);
  int S = 1;
  while (S < N + M - 1) S *= 2;
  mint pr = mint(3).pow(998244352 / S);
  vector<mint> a(S), b(S);
  rep(i, N) in(a[i]);
  rep(i, M) in(b[i]);
  auto A = ChirpZ(a, pr);
  auto B = ChirpZ(b, pr);
  rep(i, S) A[i] *= B[i];
  auto c = ChirpZ(A, pr.inverse());
  c.resize(N + M - 1);
  mint invs = mint(S).inverse();
  each(x, c) x *= invs;
  out(c);
}
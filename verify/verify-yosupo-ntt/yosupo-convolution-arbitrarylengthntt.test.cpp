#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../template/template.hpp"
//
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../ntt/cooley-tukey-ntt.hpp"

using namespace Nyaan;
void Nyaan::solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  ArbitraryLengthNTT<mint> ntt(7 * 17 * (1 << 14));
  int N, M, x;
  rd(N, M);
  V<mint> a(N), b(M);
  for (int i = 0; i < N; i++) rd(x), a[i] = x;
  for (int i = 0; i < M; i++) rd(x), b[i] = x;
  auto c = ntt.multiply(a, b);
  for (int i = 0; i < (int)N + M - 1; i++) {
    wt(c[i].get(), (i == (int)N + M - 1 ? '\n' : ' '));
  }
}
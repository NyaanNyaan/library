#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include "../../template/template.hpp"
#include "../../multiplicative-function/sum-of-totient.hpp"
#include "../../modint/montgomery-modint.hpp"

using namespace Nyaan; void Nyaan::solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  long long N;
  in(N);
  out(sum_of_totient<mint>(N));
}

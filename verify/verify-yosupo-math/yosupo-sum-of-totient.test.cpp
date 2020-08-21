#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"

#include "../../competitive-template.hpp"
#include "../../math/sum-of-multiplicative-function.hpp"
#include "../../modint/montgomery-modint.hpp"

void solve() {
  using mint = LazyMontgomeryModInt<998244353>;
  long long N;
  in(N);
  out(sum_of_totient<mint>(N));
}

#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
//
#include "../../template/template.hpp"
//
#include "../../multiplicative-function/enumerate-sum-of-multiplicative-function.hpp"
using namespace Nyaan;

#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;

void q() {
  inl(N);
  auto sg = [&](ll x) -> mint { return x; };
  auto sh = [&](ll x) -> mint { return mint{x} * (x + 1) * C.inv(2); };
  enumerate_mf_prefix_sum<mint, decltype(sg), decltype(sh)> sf(N, sg, sh);
  out(sf(N));
}

void Nyaan::solve() {
  int t = 1;
  // in(t);
  while (t--) q();
}
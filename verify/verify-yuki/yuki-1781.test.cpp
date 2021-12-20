#define PROBLEM "https://yukicoder.me/problems/no/1781"
//
#include "../../template/template.hpp"
//
#include "../../prime/prime-enumerate.hpp"

using namespace Nyaan;

#include "../../modint/montgomery-modint.hpp"
#include "../../modulo/binomial.hpp"
#include "../../multiplicative-function/sum-of-multiplicative-function.hpp"
//
using namespace Nyaan;
using mint = LazyMontgomeryModInt<998244353>;
// using mint = LazyMontgomeryModInt<1000000007>;
using vm = vector<mint>;
using vvm = vector<vm>;
Binomial<mint> C;

vector<mint> cmemo(50);
mint f(ll, ll c) { return cmemo[c + 1]; }
void Nyaan::solve() {
  inl(N, M);
  rep(i, 50) cmemo[i] = mint{i}.pow(N);
  mf_prefix_sum<mint, f> mf(M);
  auto pi = mf.pi_table();
  mint coe = mint{2}.pow(N);
  each(x, pi) x *= coe;
  out(mf.run(pi));
}

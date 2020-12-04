#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../../template/template.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../ntt/ntt.hpp"

constexpr int MOD = 998244353;
using mint = LazyMontgomeryModInt<MOD>;
using vm = vector<mint>;

using namespace Nyaan; void Nyaan::solve() {
  NTT<mint> ntt;
  ini(N, M);
  vm a(N), b(M);
  in(a, b);
  auto c = ntt.multiply(a, b);
  out(c);
}
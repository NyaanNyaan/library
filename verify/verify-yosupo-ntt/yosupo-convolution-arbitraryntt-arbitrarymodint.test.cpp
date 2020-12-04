#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../../template/template.hpp"
#include "../../modint/arbitrary-modint.hpp"
#include "../../ntt/arbitrary-ntt.hpp"

int MOD = 1000000007;
using mint = ArbitraryModInt;
using vm = vector<mint>;

using namespace Nyaan; void Nyaan::solve() {
  mint::set_mod(MOD);
  ini(N, M);
  vm a(N), b(M);
  in(a, b);
  auto c = ArbitraryNTT::multiply(a, b);
  out(c);
}
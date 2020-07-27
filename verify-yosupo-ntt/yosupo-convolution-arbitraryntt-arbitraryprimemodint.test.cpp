#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../competitive-template.hpp"
#include "../modint/arbitrary-prime-modint.hpp"
#include "../ntt/arbitrary-ntt.hpp"

int MOD = 1000000007;
using mint = ArbitraryLazyMontgomeryModInt;
using vm = vector<mint>;

void solve() {
  mint::set_mod(MOD);
  ini(N, M);
  vm a(N), b(M);
  in(a, b);
  auto c = ArbitraryNTT::multiply(a, b);
  out(c);
}
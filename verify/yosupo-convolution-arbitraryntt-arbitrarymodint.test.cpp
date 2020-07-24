#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../competitive-template.cpp"
#include "../modint/arbitrary-modint.cpp"
#include "../ntt/arbitrary-ntt.cpp"

int MOD = 1000000007;
using mint = ArbitraryModInt;
using vm = vector<mint>;

void solve() {
  mint::set_mod(MOD);
  ini(N, M);
  vm a(N), b(M);
  in(a, b);
  auto c = ArbitraryNTT::multiply(a, b);
  out(c);
}
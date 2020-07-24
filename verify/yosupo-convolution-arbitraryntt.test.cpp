#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../competitive-template.cpp"
#include "../modint/montgomery-modint.cpp"
#include "../ntt/arbitrary-ntt.cpp"

constexpr int MOD = 1000000007;
using mint = LazyMontgomeryModInt<MOD>;
using vm = vector<mint>;

void solve() {
  ini(N, M);
  vm a(N), b(M);
  in(a, b);
  auto c = ArbitraryNTT::multiply<MOD>(a, b);
  out(c);
}
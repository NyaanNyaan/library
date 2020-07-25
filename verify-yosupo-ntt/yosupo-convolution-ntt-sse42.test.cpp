#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../competitive-template.cpp"
#include "../modint/montgomery-modint.cpp"
#include "../ntt/ntt-sse42.cpp"

constexpr int MOD = 998244353;
using mint = LazyMontgomeryModInt<MOD>;
using vm = vector<mint>;

void solve() {
  NTT<mint> ntt;
  ini(N, M);
  vm a(N), b(M);
  in(a, b);
  auto c = ntt.multiply(a, b);
  out(c);
}
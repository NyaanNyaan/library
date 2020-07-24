#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../competitive-template.cpp"
#include "../modint/modint.cpp"
#include "../ntt/ntt.cpp"

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;
using vm = vector<mint>;

void solve() {
  NTT<mint> ntt;
  ini(N, M);
  vm a(N), b(M);
  in(a, b);
  auto c = ntt.multiply(a, b);
  out(c);
}
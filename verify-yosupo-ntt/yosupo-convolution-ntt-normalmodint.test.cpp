#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../competitive-template.hpp"
#include "../modint/modint.hpp"
#include "../ntt/ntt.hpp"

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
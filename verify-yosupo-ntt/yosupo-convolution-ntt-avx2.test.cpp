#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../competitive-template.hpp"
#include "../modint/montgomery-modint.hpp"
#include "../ntt/ntt-avx2.hpp"

constexpr int MOD = 998244353;
using mint = LazyMontgomeryModInt<MOD>;
using vm = vector<mint>;

__attribute__((target("avx2"))) void solve() {
  NTT<mint> ntt;
  ini(N, M);
  vm a(N), b(M);
  in(a, b);
  auto c = ntt.multiply(a, b);
  out(c);
}
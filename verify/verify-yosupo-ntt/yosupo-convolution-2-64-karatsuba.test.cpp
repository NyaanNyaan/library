#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_2_64"
//
#include "../../template/template.hpp"
//
#include "../../ntt/karatsuba.hpp"
using namespace Nyaan;

void Nyaan::solve() {
  inl(N, M);
  V<u64> a(N), b(M);
  in(a, b);
  out(karatsuba(a, b));
}

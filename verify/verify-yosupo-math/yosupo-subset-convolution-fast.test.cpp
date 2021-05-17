#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"
//
#include <immintrin.h>
//
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <random>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

#include "../../misc/fastio.hpp"
//
#include "../../math-fast/subset-convolution.hpp"
//
#include "../../modint/montgomery-modint.hpp"

int main() {
  using mint = LazyMontgomeryModInt<998244353>;
  using vm = vector<mint>;
  mmint::set_mod<mint>();

  int N;
  rd(N);
  using vm = vector<mint>;
  vm a(1 << N), b(1 << N);
  unsigned int n;
  for (int i = 0; i < 1 << N; i++) {
    rd(n);
    a[i].a = mint::reduce(uint64_t(n) * mint::n2);
  }
  for (int i = 0; i < 1 << N; i++) {
    rd(n);
    b[i].a = mint::reduce(uint64_t(n) * mint::n2);
  }
  auto c = fast_multiply(a, b);

  for (int i = 0; i < 1 << N; i++) {
    if (i) wt(' ');
    wt(c[i].get());
  }
  wt('\n');
}

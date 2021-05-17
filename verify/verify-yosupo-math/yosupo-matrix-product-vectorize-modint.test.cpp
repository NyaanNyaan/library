#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
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
#include "../../modint/montgomery-modint.hpp"
//
#include "../../math-fast/mat-prod-strassen.hpp"
#include "../../modint/vectorize-modint.hpp"

int main() {
  using mint = LazyMontgomeryModInt<998244353>;
  mmint::set_mod<mint>();

  using namespace fast_mat_prod_impl;

#ifdef PROFILER
  {
    unsigned int* a = reinterpret_cast<unsigned int*>(t);
    unsigned int* b = reinterpret_cast<unsigned int*>(u);
    unsigned int* c = reinterpret_cast<unsigned int*>(s);
    for (int i = 0; i < S; i++) {
      for (int j = 0; j < S; j++) {
        b[i * S + j] = a[i * S + j] = i + j;
      }
    }
    for (int loop = 0; loop < 100; loop++) prod(a, b, c);
    return 0;
  }
#endif

  int N, M, K;
  rd(N, M, K);

  unsigned int* a = reinterpret_cast<unsigned int*>(t);
  unsigned int* b = reinterpret_cast<unsigned int*>(u);
  unsigned int* c = reinterpret_cast<unsigned int*>(s);
  unsigned int x;

  for (int i = 0; i < N; i++) {
    for (int k = 0; k < M; k++) {
      rd(x);
      a[i * S + k] = x;
    }
  }
  for (int k = 0; k < M; k++) {
    for (int j = 0; j < K; j++) {
      rd(x);
      b[k * S + j] = x;
    }
  }

  prod(a, b, c);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      x = c[i * S + j];
      wt(x);
      wt(j == K - 1 ? '\n' : ' ');
    }
  }
}

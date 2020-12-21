#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <immintrin.h>
//
#include "../../template/template.hpp"
#include "../../misc/fastio.hpp"
#include "../../modint/montgomery-modint.hpp"
#include "../../ntt/ntt-avx2.hpp"

NTT<LazyMontgomeryModInt<998244353>> ntt;
using namespace Nyaan;
void Nyaan::solve() {
  using namespace ntt_inner;
  int N, M;
  rd(N, M);
  for (int i = 0; i < N; i++) {
    int n;
    rd(n);
    _buf1[i] = n;
  }
  for (int i = 0; i < M; i++) {
    int n;
    rd(n);
    _buf2[i] = n;
  }
  ntt.inplace_multiply(N, M, false);
  int len = N + M - 1;
  for (int i = 0; i < len; i++) {
    if (i) wt(' ');
    wt(_buf1[i]);
  }
  wt('\n');
}
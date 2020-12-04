#pragma once



namespace PrimeCounting {
using i64 = long long;
static inline i64 my_div(i64 n, i64 p) { return double(n) / p; };

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) i64
prime_counting(i64 N) {
  i64 N2 = sqrt(N);
  i64 NdN2 = my_div(N, N2);

  vector<i64> hl(NdN2);
  for (int i = 1; i < NdN2; i++) hl[i] = my_div(N, i) - 1;

  vector<int> hs(N2 + 1);
  iota(begin(hs), end(hs), -1);

  for (int x = 2, pi = 0; x <= N2; ++x) {
    if (hs[x] == hs[x - 1]) continue;
    i64 x2 = i64(x) * x;
    i64 imax = min<i64>(NdN2, my_div(N, x2) + 1);
    i64 ix = x;
    for (i64 i = 1; i < imax; ++i) {
      hl[i] -= (ix < NdN2 ? hl[ix] : hs[my_div(N, ix)]) - pi;
      ix += x;
    }
    for (int n = N2; n >= x2; n--) {
      hs[n] -= hs[my_div(n, x)] - pi;
    }
    ++pi;
  }
  return hl[1];
}

}  // namespace PrimeCounting

/**
 * @brief 素数カウント( $\mathrm{O}(\frac{N^{\frac{3}{4}}}{\log N})$・高速化版)
 * @docs docs/multiplicative-function/prime-counting.md
 */

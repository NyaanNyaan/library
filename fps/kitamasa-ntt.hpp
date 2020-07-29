#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../ntt/ntt-avx2.hpp"
#include "formal-power-series.hpp"

template <typename mint>
mint LinearRecursionFormula(long long k, FormalPowerSeries<mint> Q,
                            FormalPowerSeries<mint> P) {
  mint ret = 0;

  P.shrink();
  Q.shrink();
  if (P.size() >= Q.size()) {
    auto R = P / Q;
    P -= R * Q;
    if (k < (int)R.size()) ret += R[k];
  }
  P.shrink();
  if ((int)P.size() == 0) return ret;

  int N = 1;
  while (N < (int)Q.size()) N <<= 1;

  P.resize(2 * N);
  Q.resize(2 * N);
  P.ntt();
  Q.ntt();
  vector<mint> S(2 * N), T(2 * N);

  vector<int> btr(N);
  for (int i = 0, logn = __builtin_ctz(N); i < (1 << logn); i++) {
    btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (logn - 1));
  }
  mint dw = mint(FormalPowerSeries<mint>::ntt_pr())
                .inverse()
                .pow((mint::get_mod() - 1) / (2 * N));

  while (k) {
    mint inv2 = mint(2).inverse();

    // even degree of Q(x)Q(-x)
    T.resize(N);
    for (int i = 0; i < N; i++) T[i] = Q[(i << 1) | 0] * Q[(i << 1) | 1];

    S.resize(N);
    if (k & 1) {
      // odd degree of P(x)Q(-x)
      for (auto &i : btr) {
        S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] -
                P[(i << 1) | 1] * Q[(i << 1) | 0]) *
               inv2;
        inv2 *= dw;
      }
    } else {
      // even degree of P(x)Q(-x)
      for (int i = 0; i < N; i++) {
        S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] +
                P[(i << 1) | 1] * Q[(i << 1) | 0]) *
               inv2;
      }
    }

    swap(P, S);
    swap(Q, T);
    k >>= 1;
    if (k < N) break;
    P.ntt_doubling();
    Q.ntt_doubling();
  }
  P.intt();
  Q.intt();
  return ret + (P * (Q.inv()))[k];
}

template <typename mint>
mint kitamasa(long long N, FormalPowerSeries<mint> Q,
              FormalPowerSeries<mint> a) {
  int k = Q.size() - 1;
  assert((int)a.size() == k);
  FormalPowerSeries<mint> P = a * Q;
  P.resize(Q.size() - 1);
  return LinearRecursionFormula<mint>(N, Q, P);
}

/**
 * @brief 線形漸化式の高速計算
 * @docs docs/linear-recursive.md
 */

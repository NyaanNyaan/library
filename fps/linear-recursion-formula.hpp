#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "formal-power-series.hpp"

template <typename mint>
mint LinearRecursionFormula(long long N, FormalPowerSeries<mint> Q,
                            FormalPowerSeries<mint> P) {
  int k = Q.size() - 1;
  P.resize(k);
  while (N) {
    auto Q2 = Q;
    for (int i = 1; i < (int)Q2.size(); i += 2) Q2[i] = -Q2[i];
    auto S = P * Q2;
    auto T = Q * Q2;
    if (N & 1) {
      for (int i = 1; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
      for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
    } else {
      for (int i = 0; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
      for (int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
    }
    N >>= 1;
  }
  return P[0];
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
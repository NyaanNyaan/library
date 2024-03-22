#pragma once

#include <cassert>
#include <vector>
using namespace std;

#include "formal-power-series.hpp"

// g(f(x)) を計算
template <typename mint>
FormalPowerSeries<mint> composition(FormalPowerSeries<mint> f,
                                    FormalPowerSeries<mint> g, int deg = -1) {
  using fps = FormalPowerSeries<mint>;

  auto dfs = [&](auto rc, fps Q, int n, int h, int k) -> fps {
    if (n == 0) {
      fps T{begin(Q), begin(Q) + k};
      T.push_back(1);
      fps u = g * T.rev().inv().rev();
      fps P(h * k);
      for (int i = 0; i < (int)g.size(); i++) P[k - 1 - i] = u[i + k];
      return P;
    }
    fps nQ(4 * h * k), nR(2 * h * k);
    for (int i = 0; i < k; i++) {
      copy(begin(Q) + i * h, begin(Q) + i * h + n + 1, begin(nQ) + i * 2 * h);
    }
    nQ[k * 2 * h] += 1;
    nQ.ntt();
    for (int i = 0; i < 4 * h * k; i += 2) swap(nQ[i], nQ[i + 1]);
    for (int i = 0; i < 2 * h * k; i++) nR[i] = nQ[i * 2] * nQ[i * 2 + 1];
    nR.intt();
    nR[0] -= 1;
    Q.assign(h * k, 0);
    for (int i = 0; i < 2 * k; i++) {
      for (int j = 0; j <= n / 2; j++) {
        Q[i * h / 2 + j] = nR[i * h + j];
      }
    }
    auto P = rc(rc, Q, n / 2, h / 2, k * 2);
    fps nP(4 * h * k);
    for (int i = 0; i < 2 * k; i++) {
      for (int j = 0; j <= n / 2; j++) {
        nP[i * 2 * h + j * 2 + n % 2] = P[i * h / 2 + j];
      }
    }
    nP.ntt();
    for (int i = 1; i < 4 * h * k; i *= 2) {
      reverse(begin(nQ) + i, begin(nQ) + i * 2);
    }
    for (int i = 0; i < 4 * h * k; i++) nP[i] *= nQ[i];
    nP.intt();
    P.assign(h * k, 0);
    for (int i = 0; i < k; i++) {
      copy(begin(nP) + i * 2 * h, begin(nP) + i * 2 * h + n + 1,
           begin(P) + i * h);
    }
    return P;
  };

  if (deg == -1) deg = max(f.size(), g.size());
  f.resize(deg), g.resize(deg);
  int n = f.size() - 1, k = 1;
  int h = 1;
  while (h < n + 1) h *= 2;
  fps Q(h * k);
  for (int i = 0; i <= n; i++) Q[i] = -f[i];
  fps P = dfs(dfs, Q, n, h, k);
  return P.pre(n + 1).rev();
}

/**
 * @brief 関数の合成( $\mathrm{O}(N \log^2 N)$ )
 */

#pragma once

#include <cassert>
#include <vector>
using namespace std;

#include "../fps/formal-power-series.hpp"
#include "../fps/taylor-shift.hpp"
#include "subset-convolution.hpp"

template <typename mint, int MAX = 21>
vector<mint> polynomial_composite_set_power_series(int n, FormalPowerSeries<mint> f,
                                            vector<mint> g) {
  assert(0 <= n && n <= MAX);
  static SubsetConvolution<mint, MAX> ss;

  Binomial<mint> binom(f.size());
  if (g[0] != 0) {
    f = TaylorShift(f, g[0], binom);
    g[0] = 0;
  }
  f.resize(n + 1), g.resize(1 << n);

  for (int i = 0; i <= n; i++) f[i] *= binom.fac(i);
  vector h(n + 1, vector(n + 1, vector<mint>{}));
  for (int i = 0; i <= n; i++) h[0][i] = {f[i]};
  for (int k = 1; k <= n; k++) {
    auto A = ss.lift({begin(g) + (1 << (k - 1)), begin(g) + (1 << k)});
    ss.zeta(A);
    for (int j = 0; j <= n - k; j++) {
      h[k][j] = h[k - 1][j];
      auto B = ss.lift(h[k - 1][j + 1]);
      ss.zeta(B);
      ss.prod(B, A);
      ss.mobius(B);
      auto c = ss.unlift(B);
      copy(begin(c), end(c), back_inserter(h[k][j]));
    }
  }
  return h[n][0];
}

/**
 * @brief 集合冪級数の合成
 */

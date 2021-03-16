#pragma once

#include "../fps/formal-power-series.hpp"
#include "../fps/sample-point-shift.hpp"

template <typename mint>
mint factorial(int n) {
  if (n <= 1) return 1;
  using fps = FormalPowerSeries<mint>;
  long long v = 1;
  while(v * v < n) v *= 2;
  mint iv = mint(v).inverse();
  fps G{1, v + 1};
  for (long long d = 1; d != v; d <<= 1) {
    fps G1 = SamplePointShift(G, mint(d) * iv);
    fps G2 = SamplePointShift(G, mint(d * v + v) * iv);
    fps G3 = SamplePointShift(G, mint(d * v + d + v) * iv);
    for (int i = 0; i <= d; i++) G[i] *= G1[i], G2[i] *= G3[i];
    copy(begin(G2), end(G2) - 1, back_inserter(G));
  }
  mint res = 1;
  long long i = 0;
  while (i + v <= n) res *= G[i / v], i += v;
  while (i < n) res *= ++i;
  return res;
}

/**
 * @brief 階乗 $\mod p$
 * @docs docs/modulo/factorial.md
 */

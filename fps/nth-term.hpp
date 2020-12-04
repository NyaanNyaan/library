#pragma once

#include "berlekamp-massey.hpp"
#include "kitamasa.hpp"

template <typename mint>
mint nth_term(long long n, const vector<mint> &s) {
  using fps = FormalPowerSeries<mint>;
  auto bm = BerlekampMassey<mint>(s);
  return kitamasa(n, fps{begin(bm), end(bm)}, fps{begin(s), end(s)});
}

/**
 * @brief 線形回帰数列の高速計算(Berlekamp-Massey/Bostan-Mori)
 * @docs docs/fps/nth-term.md
 */

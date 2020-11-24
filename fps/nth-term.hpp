#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "berlekamp-massey.hpp"
#include "kitamasa.hpp"

template <typename mint>
mint nth_term(int n, const vector<mint> &s) {
  using fps = FormalPowerSeries<mint>;
  auto bm = BerlekampMassey<mint>(s);
  return kitamasa(n, fps{begin(bm), end(bm)}, fps{begin(s), end(s)});
}

/**
 * @brief 与えられた数列の第$n$項を計算(Berlekamp-Massey/Bostan-Mori)
 * @docs docs/fps/kitamasa.md
 */

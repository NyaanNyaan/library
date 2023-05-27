#pragma once

#include <cassert>
#include <vector>
using namespace std;

#include "subset-convolution.hpp"

template <typename mint, int MAX = 21>
vector<mint> exp_of_set_power_series(int n, vector<mint> g) {
  assert(0 <= n && n <= MAX);
  static SubsetConvolution<mint, MAX> ss;
  g.resize(1 << n);
  assert(g[0] == 0);

  vector<mint> h{1};
  for (int k = 1; k <= n; k++) {
    auto a = ss.multiply(h, {begin(g) + (1 << (k - 1)), begin(g) + (1 << k)});
    copy(begin(a), end(a), back_inserter(h));
  }
  return h;
}

/**
 * @brief 集合冪級数の exp
 */

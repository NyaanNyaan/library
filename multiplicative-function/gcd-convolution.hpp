#pragma once



#include "divisor-multiple-transform.hpp"

template <typename mint>
vector<mint> gcd_convolution(const vector<mint>& a, const vector<mint>& b) {
  assert(a.size() == b.size());
  auto s = a, t = b;
  multiple_transform::zeta_transform(s);
  multiple_transform::zeta_transform(t);
  for (int i = 0; i < (int)a.size(); i++) s[i] *= t[i];
  multiple_transform::mobius_transform(s);
  return s;
}

/**
 * @brief GCD畳み込み
 */

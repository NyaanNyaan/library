#pragma once

#include "mod-sqrt.hpp"

template <typename mint>
vector<mint> QuadraticEquation(mint a, mint b, mint c) {
  assert(mint::get_mod() % 2 != 0);
  if (a == mint()) {
    if(b == mint()) {
      assert(c != mint());
      return {};
    }
    return vector<mint>{-c * b.inverse()};
  }
  mint ia = a.inverse(), inv2 = mint(2).inverse();
  b *= ia, c *= ia;
  auto D = mod_sqrt(((b * inv2).pow(2) - c).get(), mint::get_mod());
  if(D == -1) return {};
  if(D <= 1) return vector<mint>{-b * inv2 + D};
  return vector<mint>{-b * inv2 + D, -b * inv2 - D};
}

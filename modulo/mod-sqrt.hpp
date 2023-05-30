#pragma once
#include "../modint/arbitrary-montgomery-modint.hpp"

int64_t mod_sqrt(const int64_t &a, const int64_t &p) {
  assert(0 <= a && a < p);
  if (a < 2) return a;
  using Mint = ArbitraryLazyMontgomeryModInt<409075245>;
  Mint::set_mod(p);
  if (Mint(a).pow((p - 1) >> 1) != 1) return -1;
  Mint b = 1, one = 1;
  while (b.pow((p - 1) >> 1) == 1) b += one;
  int64_t m = p - 1, e = 0;
  while (m % 2 == 0) m >>= 1, e += 1;
  Mint x = Mint(a).pow((m - 1) >> 1);
  Mint y = Mint(a) * x * x;
  x *= a;
  Mint z = Mint(b).pow(m);
  while (y != 1) {
    int64_t j = 0;
    Mint t = y;
    while (t != one) {
      j += 1;
      t *= t;
    }
    z = z.pow(int64_t(1) << (e - j - 1));
    x *= z;
    z *= z;
    y *= z;
    e = j;
  }
  return x.get();
}

/**
 * @brief mod sqrt(Tonelli-Shanks algorithm)
 * @docs docs/modulo/mod-sqrt.md
 */

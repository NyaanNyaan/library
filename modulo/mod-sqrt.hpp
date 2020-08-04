#pragma once
#include "../modint/arbitrary-prime-modint.hpp"

int64_t mod_sqrt(const int64_t &a, const int64_t &p) {
  if (a == 0) return 0;
  if (p == 2) return a;
  using mint = ArbitraryLazyMontgomeryModInt;
  mint::set_mod(p);
  if (mint(a).pow((p - 1) >> 1) != 1) return -1;
  mint b = 1, one = 1;
  while (b.pow((p - 1) >> 1) == 1) b += one;
  int64_t m = p - 1, e = 0;
  while (m % 2 == 0) m >>= 1, e += 1;
  mint x = mint(a).pow((m - 1) >> 1);
  mint y = mint(a) * x * x;
  x *= a;
  mint z = mint(b).pow(m);
  while (y != 1) {
    int64_t j = 0;
    mint t = y;
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

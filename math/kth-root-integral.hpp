#pragma once



uint64_t kth_root_integral(uint64_t a, uint64_t k) {
  if (a <= 1 || k == 1) return a;
  if (64 <= k) return 1;
  auto check = [&](__uint128_t n) {
    __uint128_t x = 1, m = n;
    for (int p = k; p; p >>= 1, m *= m)
      if (p & 1) x *= m;
    return x <= a;
  };
  uint64_t n = powl(a, (long double)(1.0) / k);
  while (!check(n)) --n;
  while (check(n + 1)) ++n;
  return n;
}

/**
 * @brief $\mathrm{floor}(a^{\frac{1}{k}})$
 * @docs docs/math/kth-root-integral.md
 */

#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace nimber {
using u64 = uint64_t;

u64 calc(u64, u64, int p, int pre);

struct Precalc {
  u64 dp[256][256];
  Precalc() {
    for (int i = 0; i < 256; i++)
      for (int j = 0; j <= i; j++) {
        dp[i][j] = dp[j][i] = calc(i, j, 8, true);
      }
  }

} precalc;

u64 calc(u64 a, u64 b, int p = 64, int pre = false) {
  if (min(a, b) <= 1) return a * b;
  while (max(a, b) < 1ull << (p >> 1)) p >>= 1;
  if (!pre && p <= 8) return precalc.dp[a][b];
  p >>= 1;
  u64 a1 = a >> p, a2 = a & ((1ull << p) - 1);
  u64 b1 = b >> p, b2 = b & ((1ull << p) - 1);
  u64 c = calc(a1, b1, p, pre);
  u64 d = calc(a2, b2, p, pre);
  u64 e = calc(a1 ^ a2, b1 ^ b2, p, pre);
  return calc(c, 1ull << (p - 1), p, pre) ^ d ^ ((d ^ e) << p);
}

u64 nim_product(u64 a, u64 b) { return calc(a, b); }

}  // namespace nimber
using nimber::nim_product;

/**
 * @brief Nim Product
 * @docs docs/math/nim-product.md
 */

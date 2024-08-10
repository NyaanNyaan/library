#pragma once

#include "../hashmap/hashmap.hpp"
#include "../internal/internal-math.hpp"

// a^x = b (mod p) である最小の非負整数 x を返す
int64_t mod_log(int64_t a, int64_t b, int64_t p) {
  if ((a %= p) < 0) a += p;
  if ((b %= p) < 0) b += p;
  int64_t f, g, r = 1 % p;
  for (f = 0; (g = gcd(a, p)) > 1; ++f) {
    if (b % g) return (r == b) ? f : -1;
    b /= g;
    p /= g;
    (r *= (a / g)) %= p;
  }
  if (p == 1) return f;
  int64_t ir = internal::inv(r, p);
  (b *= ir) %= p;
  int64_t k = 0, ak = 1;
  HashMap<int64_t, int64_t> baby;
  for (; k * k < p; ++k) {
    if(baby.find(ak) == baby.end()) baby[ak] = k;
    (ak *= a) %= p;
  }
  int64_t iak = internal::inv(ak, p);
  for (int64_t i = 0; i < k; ++i) {
    if (baby.find(b) != baby.end()) return f + i * k + baby[b];
    (b *= iak) %= p;
  }
  return -1;
}
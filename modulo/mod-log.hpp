#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../math/elementary-function.hpp"

int64_t mod_log(int64_t a, int64_t b, int64_t p) {
  if ((a %= p) < 0) a += p;
  if ((b %= p) < 0) b += p;
  int64_t f, g, r = 1 % p;
  for (f = 0; (g = __gcd(a, p)) > 1; ++f) {
    if (b % g) return (r == b) ? f : -1;
    b /= g;
    p /= g;
    (r *= (a / g)) %= p;
  }
  if (p == 1) return f;
  auto ir = extgcd(r, p);
  (b *= (ir.first + p)) %= p;
  int64_t k = 0, ak = 1;
  unordered_map<int64_t, int64_t> baby;
  for (; k * k < p; ++k) {
    if (!baby.count(ak)) baby[ak] = k;
    (ak *= a) %= p;
  }
  auto iak = extgcd(ak, p);
  if(iak.first < 0) iak.first += p;
  for (int64_t i = 0; i < k; ++i) {
    if (baby.count(b)) return f + i * k + baby[b];
    (b *= iak.first) %= p;
  }
  return -1;
}
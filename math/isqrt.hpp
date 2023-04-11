#pragma once

#include <cmath>
using namespace std;

// floor(sqrt(n)) を返す (ただし n が負の場合は 0 を返す)
long long isqrt(long long n) {
  if (n <= 0) return 0;
  long long x = sqrt(n);
  while ((x + 1) * (x + 1) <= n) x++;
  while (x * x > n) x--;
  return x;
}

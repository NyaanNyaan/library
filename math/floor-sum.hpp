#pragma once

// sum_{0 <= i < N} (ai + b) // m
template <typename T>
T sum_of_floor(T n, T m, T a, T b) {
  T ret = 0;
  if (a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;
  if (b >= m) ret += n * (b / m), b %= m;
  T y = (a * n + b) / m;
  if (y == 0) return ret;
  T x = y * m - b;
  ret += (n - (x + a - 1) / a) * y;
  ret += sum_of_floor(y, a, m, (a - x % a) % a);
  return ret;
}

// verify www.codechef.com/viewsolution/36222026
// count x : ax + b mod m < yr, 0 <= x < xr
template <typename T>
T mod_affine_range_counting(T a, T b, T m, T xr, T yr) {
  assert(0 <= yr && yr <= m);
  return sum_of_floor(xr, m, a, b + m) - sum_of_floor(xr, m, a, b + m - yr);
}

#pragma once

#include <cassert>
#include <type_traits>
using namespace std;

// gcd(a, m) != 1 のとき 0 除算で RE する
template <typename T>
T inv_mod(T a, T m) {
  if (m == 1) return 0;
  if (a >= m) a %= m;
  if (a < 0) a += m;
  T b = m, s = 1, t = 0;
  while (true) {
    if (a == 1) return s;
    t -= b / a * s;
    b %= a;
    if (b == 1) return t + m;
    s -= a / b * t;
    a %= b;
  }
}

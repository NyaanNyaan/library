#pragma once

namespace internal {

#include <cassert>
using namespace std;

template <typename T>
T inv(T a, T p) {
  T b = p, x = 1, y = 0;
  while (a) {
    T q = b / a;
    swap(a, b %= a);
    swap(x, y -= q * x);
  }
  assert(b == 1);
  return y < 0 ? y + p : y;
}

template <typename T, typename U>
T modpow(T a, U n, T p) {
  T ret = 1 % p;
  while (n) {
    if (n & 1) ret = U(ret) * a % p;
    a = U(a) * a % p;
    n >>= 1;
  }
  return ret;
}

}  // namespace internal

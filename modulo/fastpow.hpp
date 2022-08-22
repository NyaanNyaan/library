#pragma once


template <typename T, int LOG = 21>
struct FastPow {
  static constexpr long long B0 = 1LL << LOG;
  static constexpr long long B1 = 1LL << (LOG * 2);
  static constexpr long long mask = B0 - 1;
  vector<T> p0, p1, p2;
  FastPow(T base, T I = 1) : p0(B0), p1(B0), p2(B0) {
    T x = I;
    for (int i = 0; i < B0; i++) p0[i] = x, x *= base;
    base = x, x = I;
    for (int i = 0; i < B0; i++) p1[i] = x, x *= base;
    base = x, x = I;
    for (int i = 0; i < B0; i++) p2[i] = x, x *= base;
  }
  T operator()(long long e) {
    assert(0 <= e);
    if (e < B0) return p0[e];
    if (e < B1) return p0[e & mask] * p1[(e >> LOG) & mask];
    return p0[e & mask] * p1[(e >> LOG) & mask] * p2[(e >> (LOG * 2)) & mask];
  }
};

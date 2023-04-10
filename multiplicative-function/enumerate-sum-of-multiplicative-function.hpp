#pragma once

#include <functional>
#include <unordered_map>
using namespace std;

#include "../math/enumerate-quotient.hpp"
#include "../math/isqrt.hpp"
/**
 * S(f, n) = f(1) + f(2) + ... + f(n) とする
 * f と g のディリクレ積を h とする
 * S(h, n) と S(g, n) が高速に計算できる, かつ g(1) = 1 のとき
 * S(f, N/i) を O(N^{3/4}) で列挙できる
 *
 * うまくやると O~(N^{2/3}) に落ちたり g(1) != 1 に対応できる
 * https://codeforces.com/blog/entry/54150
 */
template <typename T, typename SG, typename SH>
struct enumerate_mf_prefix_sum {
  long long N, sq;
  const SG sg;
  const SH sh;
  vector<T> small, large;
  T& ref(long long x) {
    if (x <= sq) {
      return small[x];
    } else if (N <= 1000000000000LL) {
      return large[1.0 * N / x];
    } else {
      return large[N / x];
    }
  }
  enumerate_mf_prefix_sum(long long _n, SG _sg, SH _sh)
      : N(_n), sq(isqrt(N)), sg(_sg), sh(_sh) {
    small.resize(sq + 1);
    large.resize(sq + 1);
    enumerate_quotient(N, [&](long long n, long long, long long) {
      T& cur = (ref(n) = sh(n));
      enumerate_quotient(n, [&](long long q, long long l, long long r) {
        if (q != n) cur -= ref(q) * (sg(r) - sg(l));
      });
    });
  }
  T get(long long n) { return ref(n); }
  T operator()(long long n) { return get(n); }
};

/**
 * @brief 乗法的関数のprefix sum の列挙
 */

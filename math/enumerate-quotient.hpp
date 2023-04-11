#pragma once

#include "isqrt.hpp"

namespace EnumerateQuotientImpl {
long long fast_div(long long a, long long b) { return 1.0 * a / b; };
long long slow_div(long long a, long long b) { return a / b; };
}  // namespace EnumerateQuotientImpl

// { (q, l, r) : forall x in (l,r], floor(N/x) = q }
// を引数に取る関数f(q, l, r)を渡す。範囲が左に半開なのに注意
// 商は小さい方から走査する
template <typename T, typename F>
void enumerate_quotient(T N, const F& f) {
  T sq = isqrt(N);

#define FUNC(d)                       \
  T upper = N, quo = 0;               \
  while (upper > sq) {                \
    T thres = d(N, (++quo + 1));      \
    f(quo, thres, upper);             \
    upper = thres;                    \
  }                                   \
  while (upper > 0) {                 \
    f(d(N, upper), upper - 1, upper); \
    upper--;                          \
  }

  if (N <= 1e12) {
    FUNC(EnumerateQuotientImpl::fast_div);
  } else {
    FUNC(EnumerateQuotientImpl::slow_div);
  }
#undef FUNC
}

/**
 *  @brief 商の列挙
 */

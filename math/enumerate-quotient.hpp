#pragma once

// { (q, l, r) : forall x in (l,r], floor(N/x) = q }
// を引数に取る関数f(q, l, r)を渡す。範囲が左に半開なのに注意
template <typename T, typename F>
void enumerate_quotient(T N, const F& f) {
  T sq = sqrt(N), upper = N, quo = 0;
  while (upper > sq) {
    T thres = N / (++quo + 1);
    f(quo, thres, upper);
    upper = thres;
  }
  while (upper > 0) {
    f(N / upper, upper - 1, upper);
    upper--;
  }
}

/**
 *  @brief 商の列挙
 */

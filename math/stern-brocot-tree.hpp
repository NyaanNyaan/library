#pragma once

#include "rational.hpp"

// f(x) が true, かつ分子と分母が INF 以下である最小の既約分数 x を求める
// f(0) = true の場合は 0 を, true になる分数が存在しない場合は 1/0 を返す
using T = Rational;
using I = typename T::Key;
template <typename F>
T binary_search_on_stern_brocot_tree(const F& f, const I& INF) {
  // INF >= 1
  assert(1 <= INF);
  auto gen_frac = [&](const T& a, const I& b, const T& c) -> T {
    return T{a.x * b + c.x, a.y * b + c.y};
  };

  T L{0, 1}, M{1, 1}, R = T::raw(1, 0);
  if (f(L)) return L;
  int go_left = f(M);
  while (true) {
    if (go_left) {
      // (L, M] に答えがある
      // (f(L * b + M) = false) or (INF 超え) になる b の最小は？
      I a = 0, b = 1;
      while (true) {
        T x = gen_frac(L, b, M);
        if (max(x.x, x.y) > INF or !f(x)) break;
        a = b, b += b;
      }
      while (a + 1 < b) {
        I c = (a + b) / 2;
        T x = gen_frac(L, c, M);
        (max(x.x, x.y) > INF or !f(x) ? b : a) = c;
      }
      R = gen_frac(L, a, M);
      M = gen_frac(L, b, M);
      if (max(M.x, M.y) > INF) return R;
    } else {
      // f(M) = false -> (M, R] に答えがある
      // (f(M + R * b) = true) or (INF 超え) になる b の最小は？
      I a = 0, b = 1;
      while (true) {
        T x = gen_frac(R, b, M);
        if (max(x.x, x.y) > INF or f(x)) break;
        a = b, b += b;
      }
      while (a + 1 < b) {
        I c = (a + b) / 2;
        T x = gen_frac(R, c, M);
        (max(x.x, x.y) > INF or f(x) ? b : a) = c;
      }
      L = gen_frac(R, a, M);
      M = gen_frac(R, b, M);
      if (max(M.x, M.y) > INF) return R;
    }
    go_left ^= 1;
  }
}

/**
 * Stern-Brocot Tree 上の二分探索
 */
